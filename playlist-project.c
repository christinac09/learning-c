#include <stdio.h>
#include <stdlib.h> //for malloc
#include <string.h> //for strcpy

/* Using the abstract data type “Linked List”, create a playlist that only needs to move 1 direction. The program must allow for the following
● Add songs to the linked list
● Remove songs from the playlist
● Songs contain an artist, name and year released
In main function, simply call the add to playlist 3 times. Print the playlist.
Then call delete on one of the songs and reprint the playlist showing it no longer contains the delete song. */

struct song
{
    char title[30];
    char artist[30];
    int year;
    struct song *next_song; // pointer to the next song (node) in the playlist (linked list)
};

/* inserts node to beginning of list */
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

int delete(struct song song) {

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

int main()
{
    struct song *first_song = NULL; // points to first node; NULL indicates that list is empty

    add(&first_song, "So Sick", "Ne-Yo", 2005);
    add(&first_song, "Housewife", "Tate McRae", 2026);
    add(&first_song, "Ain't in LA", "Adela", 2026);

    printf("Playlist:\n");
    printList(first_song);

    return 0;
};