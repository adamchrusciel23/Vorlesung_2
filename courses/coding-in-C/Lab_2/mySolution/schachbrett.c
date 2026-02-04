#include <stdio.h>

int main(){
    int zahlen[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    char buchstaben[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    for(int i = 7; i>=0; i--){
        for(int x = 0; x<=7; x++){
            printf("%c%d ", buchstaben[x], zahlen[i]);
        }
        printf("\n");
    }
    return 0;
}