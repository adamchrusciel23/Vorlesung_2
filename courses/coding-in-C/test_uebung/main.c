#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"

int main(){
    printf("Geben Sie einen Satz ein:");
    char *input = read_line_dynamic();
    if (input != NULL) {
        printf("Die Länge des eingegebenen Satzes beträgt: %d\n", custom_len(input));
    }
    for(int i = 0; input[i] != '\0'; i++) {
        printf("%c", input[i]);
    }
    free(input);
}