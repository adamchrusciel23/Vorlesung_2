#include <stdio.h>

int main(){
    int ersteZahl;
    int zweiteZahl;
    char rechenoperation;
    int ergebnis;
    
    printf("Geben Sie die erste Zahl ein: ");
    scanf("%d", &ersteZahl);
    printf("\nGeben Sie die zweite Zahl ein: ");
    scanf("%d", &zweiteZahl);
    
    printf("%d, %d,", ersteZahl, zweiteZahl);
    
    printf("\nGeben sie die Rechenoperation ein: ");
    scanf(" %c", &rechenoperation);

    /*if(rechenoperation == '+'){
        ergebnis = ersteZahl + zweiteZahl;
        printf("Ergebnis: %d", ergebnis);
    }
    if(rechenoperation == '-'){
        ergebnis = ersteZahl - zweiteZahl;
        printf("Ergebnis: %d", ergebnis);
    }
    if(rechenoperation == '*'){
        ergebnis = ersteZahl * zweiteZahl;
        printf("Ergebnis: %d", ergebnis);
    }
    if(rechenoperation == '/'){
        if(zweiteZahl){
            ergebnis = ersteZahl / zweiteZahl;
            printf("Ergebnis: %d", ergebnis);
        }
        else{
            printf("\nDivision durch 0");
        }
    }*/
    switch(rechenoperation){
        case('+'):  ergebnis = ersteZahl + zweiteZahl;   printf("Ergebnis: %d", ergebnis);   break;
        case('-'):  ergebnis = ersteZahl - zweiteZahl;   printf("Ergebnis: %d", ergebnis);   break;
        case('*'):  ergebnis = ersteZahl * zweiteZahl;   printf("Ergebnis: %d", ergebnis);   break;
        case('/'):  if(zweiteZahl){   ergebnis = ersteZahl / zweiteZahl;   printf("Ergebnis: %d", ergebnis);   break;}
                    else{printf("\nDivision durch 0");}

    }
    

    return 0;
}