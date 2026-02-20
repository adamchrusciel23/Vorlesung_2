#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song{
    char *p_title;
    char *p_artist;
    struct Song *p_next_song;
}Song;

typedef struct {
    Song *p_first_song;
}Playlist;

void init_playlist(Playlist *playlist) {
    playlist->p_first_song = NULL;
}

void add_song(Playlist *p_playlist, char *title, char *artist) {
    Song *p_new_song = (Song*)malloc(sizeof(Song));
    if(p_new_song == NULL){
        printf("Fehler beim erstellen eines neuen Songs\n");
        return;
    }

    p_new_song->p_title = (char*)malloc(sizeof(strlen(title))+1);
    if(p_new_song->p_title == NULL){
        printf("Fehler beim Titel des neuen Songs\n");
        free(p_new_song);
        return;
    }
    strcpy(p_new_song->p_title, title);

    p_new_song->p_artist = (char*)malloc(sizeof(strlen(artist))+1);
    if(p_new_song->p_artist == NULL){
        printf("Fehler beim Artist vom neuen Song\n");
        free(p_new_song->p_title);
        free(p_new_song);
        return;
    }
    strcpy(p_new_song->p_artist, artist);

    p_new_song->p_next_song = NULL;
    if(p_playlist->p_first_song == NULL){
        p_playlist ->p_first_song = p_new_song;
    }
    else{
        Song *p_current_song = p_playlist->p_first_song;
        while(p_current_song->p_next_song != NULL){
            p_current_song = p_current_song->p_next_song;
        }
        p_current_song->p_next_song = (Song*)malloc(sizeof(Song));
        if(p_current_song->p_next_song == NULL){
            printf("Fehler beim Hinzufügen des Songs\n");
        }
    }   
}

void print_playlist(Playlist *p_playlist){
    if(p_playlist->p_first_song == NULL){
        printf("Die Playlist ist leer\n");
        return;
    }
    Song *p_current_song = (Song*)malloc(sizeof(Song));
    if(p_current_song == NULL){
        printf("Speicherreservierung fehlgeschlagen in print_playlist\n");
        return;
    }
    while(p_current_song != NULL){
        printf("Title: __%s__, Artist: __%s__\n", p_current_song->p_title, p_current_song->p_artist);
        if(p_current_song->p_next_song != NULL){
            p_current_song = p_current_song->p_next_song;
        }
        else{
            p_current_song = NULL;
        }
    }

}


int main() {
    Playlist myPlaylist;
    init_playlist(&myPlaylist);

    add_song(&myPlaylist, "Crawling", "LinkingPark");
    print_playlist(&myPlaylist);

    add_song(&myPlaylist, "Layla", "Eric Clapton");
    add_song(&myPlaylist, "Esperanto", "Max Herre");
    print_playlist(&myPlaylist);

}