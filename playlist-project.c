/* Using the abstract data type “Linked List”, create a playlist that only needs to move 1 direction. The program must allow for the following
● Add songs to the linked list
● Remove songs from the playlist
● Songs contain an artist, name and year released
In main function, simply call the add to playlist 3 times. Print the playlist.
Then call delete on one of the songs and reprint the playlist showing it no longer contains the delete song. */

#include <stdio.h>

struct song
{
    char title[100];
    char artist[100];
    int year;
};

void add(struct song song, playlst) {
};

void delete(struct song song) {

};

int main()
{
    struct song playlist[];
    struct song song;
    for (int i = 0; i < 3; i++)
    {
        printf("Enter a song title: ");
        scanf("%s", song.title);
        printf("Enter a song artist: ");
        scanf("%s", song.artist);
        printf("Enter a song year: ");
        scanf("%d", song.year);
        // add
    }
};