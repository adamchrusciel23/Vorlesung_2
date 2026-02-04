#include <stdio.h>
int addition(int zahl1, int zahl2){
    return zahl1 + zahl2;
}
int subtraktion(int zahl1, int zahl2){
    return zahl1 - zahl2;
}
int multiplikation(int zahl1, int zahl2){
    return zahl1 * zahl2;
}
int division(int zahl1, int zahl2){
    return zahl1 / zahl2;
}
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
        case('+'):  
            ergebnis = addition(ersteZahl, zweiteZahl);   
            printf("Ergebnis: %d", ergebnis);   
            break;
        
        case('-'):  
            ergebnis = subtraktion(ersteZahl, zweiteZahl);   
            printf("Ergebnis: %d", ergebnis);   
            break;
        
        case('*'):  
            ergebnis = multiplikation(ersteZahl, zweiteZahl);   
            printf("Ergebnis: %d", ergebnis);   
            break;
        
        case('/'): 
            if(zweiteZahl){
                ergebnis = division(ersteZahl, zweiteZahl);
                printf("Ergebnis: %d", ergebnis);  
            } 
            else{
                printf("Division durch 0");  
            }  
            break;
    }
    return 0;
}