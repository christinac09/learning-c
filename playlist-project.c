#include <stdio.h>
#include <stdlib.h> //for malloc
#include <string.h> //for strcpy

/* Using the abstract data type “Linked List”, create a playlist that only needs to move 1 direction. The program must allow for the following
● Add songs to the linked list
● Remove songs from the playlist
● Songs contain an artist, name and year released
In main function, simply call the add to playlist 3 times. Print the playlist.
Then call delete on one of the songs and reprint the playlist showing it no longer contains the delete song. */
/* most notes are from the textbook ch 17 */

struct song
{
    char title[30];
    char artist[30];
    int year;
    struct song *next_song; // pointer to the next song (node) in the playlist (linked list)
};

/* inserts node to beginning of list - how would it look if inserting at the end?? */
int add(struct song **playlist, const char *new_title, const char *new_artist, int new_year)
{                                           // playlist points to first song of list; ** is pointer to a pointer, so the pointer in main can be changed
    struct song *new_song;                  // points to the node temporarily until it's inserted into the list
    new_song = malloc(sizeof(struct song)); // allocate memory for new node, saving return value in new_song
    if (new_song == NULL)
    {
        printf("Error: malloc failed in add to list\n");
        return -1;
    };
    strcpy(new_song->title, new_title); // for arrays: use strcpy to copy string into array, can't just use do new_song->title = new_title;
    strcpy(new_song->artist, new_artist);
    new_song->year = new_year; // same as (*new_song).year = new_year

    new_song->next_song = *playlist; // makes the new node point to the previous first node
    *playlist = new_song;            // makes the new node the new head of the list

    return 0;
}

int delete(struct song **playlist, char *title)
{
    struct song *current, *previous;
    current = *playlist;
    previous = NULL;
    while (current != NULL && strcmp(current->title, title) != 0) // can't use != to compare strings
    {
        previous = current;
        current = current->next_song;
    }
    // while current title doesn't match title to delete, keep going thru list; previous keeps track of node before current so we can update its next pointer when we delete current

    if (current == NULL) // song not found
    {
        printf("Song not found in playlist\n");
        return -1;
    };
    if (previous == NULL) // song to delete is first node
    {
        *playlist = current->next_song; // update head song to point to next node
    }
    else
    {
        previous->next_song = current->next_song; // update previous node to point to node after current node
    };
    free(current);

    return 0;
};

void printList(struct song *head)
{
    struct song *current = head; // start at the head node
    if (current == NULL)
    {
        printf("Playlist is empty\n");
        return;
    };
    while (current != NULL) // while list not empty
    {
        printf("Title: %s, Artist: %s, Year: %d\n", current->title, current->artist, current->year);
        current = current->next_song; // update current, move to the next node
    }
}

/* frees dynamically allocated memory so it can be used for other things */
void freeList(struct song *head)
{
    struct song *current = head;

    while (current != NULL)
    {
        struct song *next = current->next_song;
        free(current);
        current = next;
    }
};

int main()
{
    struct song *first_song = NULL; // points to first node; NULL indicates that list is empty

    add(&first_song, "So Sick", "Ne-Yo", 2005);
    add(&first_song, "Housewife", "Tate McRae", 2026);
    add(&first_song, "Ain't in LA", "Adela", 2026);

    printf("Playlist:\n");
    printList(first_song);

    printf("\n");

    delete(&first_song, "Housewife");

    printf("Playlist after deleting 'Housewife':\n");
    printList(first_song);

    return 0;
};