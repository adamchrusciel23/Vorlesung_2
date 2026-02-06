#include <stdio.h>

int main(){
    int myNumbers[5] = {10,20,30,40,50};

    int* p2, pletzte;
    p2 = myNumbers + 1;
    int groeßeArray = sizeof(myNumbers)/4;
    pletzte = myNumbers + groeßeArray -1;
    printf("%p  %p", p2, pletzte);
    return 0;
}