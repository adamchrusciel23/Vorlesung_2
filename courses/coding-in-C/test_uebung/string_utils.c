#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"
int custom_len(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
char* read_line_dynamic(){
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);
    if(buffer[0] == '\0'){
        return NULL;
    }
    int laenge = custom_len(buffer);
    char *string = malloc(laenge+1);
    if(string == NULL){
        return NULL;
    }
    if (buffer[laenge - 1] == '\n') {
    buffer[laenge - 1] = '\0';
    laenge--;
    }
    for(int i = 0; i < laenge; i++){
        string[i] = buffer[i];
    }
    string[laenge] = '\0';
    return string;
}