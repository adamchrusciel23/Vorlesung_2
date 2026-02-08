#include <stdio.h>
#include <stdlib.h>

char* read_string() {
    char* satz = malloc(100 * sizeof(char));
    printf("Geben Sie Ihren Satz ein: ");
    fgets(satz, 100, stdin);
    return satz;
}

void change_second_letter(char* satz){
    char* second_letter = satz + 1;
    *second_letter = 'c';
}


int palindrom(char satz[]){
    int laenge = strlen(satz-1);
    for (int i = 0; i<laenge; i++){
        if(satz[i] <65 || satz[i]>90){
            satz[i] = satz[i] + 32;
        }
        if(satz[i] != satz[laenge-1-i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    /*char satz[] = "Curly bird catches the worm";
    char* pSatz = &satz;

    for(int i = 0; i<sizeof(satz); i++){
        printf("%c",satz[i]);
    }
    printf("\n");
    printf("%p", pSatz);

    char* pErstesZeichen = pSatz;
    char* pZweitesZeichen = pSatz + 1;

    *pErstesZeichen = 'E';
    *pZweitesZeichen = 'a';
    printf("\n");
    for(int i = 0; i<sizeof(satz); i++){
        printf("%c",satz[i]);
    }
    return 0;*/
    
    
    /*char satz[] = "AAtions speak louder than words";
    change_second_letter(satz);
    printf("%s", satz);
    return 0;*/

    char* satz = read_string();
    int palindrom_bool = palindrom(satz);
    if(palindrom_bool == 1){
        printf("ist eins");
    }
    else{
        printf("ist keins");
    }
    return 0;



}