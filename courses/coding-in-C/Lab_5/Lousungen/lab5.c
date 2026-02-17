#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>



int main(int argc, char **argv) {
/*    int x = 10;
    int *p = &x;
    int **pp = &p;

    // TODO: complete the output statements
    printf("x = %d\n", x);
    printf("x via p = %d\n", *p);
    printf("x via pp = %d\n", **pp);

    **pp = 42;

    printf("x = %d\n", x);
    printf("x via p = %d\n", *p);
    printf("x via pp = %d\n", **pp);
    
    if (argc < 2) {
        printf("Bitte mindestens ein Argument angeben!\n");
    return 1;
    }
    for (int i = 0; i < argc; i++) {
        printf("Index: %d, Adresse: %p, Inhalt: %s, Länge: %zu\n", 
           i, (void*)&argv[i], argv[i], strlen(argv[i]));
    }*/

    int particles[10] = {0};
    particles[0] = 1;
    particles[2] = 1;
    particles[4] = 1;
    particles[6] = 1;
    particles[8] = 1;
    int* p_particles = particles;
    int particles_nextstate[10] = {0};
    int* p_particles_nextstate = particles_nextstate;
    int r = 0;

    for(int i = 0; i < sizeof(particles)/4; i++){
        particles_nextstate[i] = particles[i];
    }

    srand(time(NULL));
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < sizeof(particles)/4; j++){
            printf("%d ", particles[j]);
        }
        printf("\n");
        for (int j = 0; j < sizeof(particles)/4; j++){
            if(particles[j]){
                r = rand() % 2;
                if(r && j!=9){ // Nicht am rechten rand und Bewegung nach rechts
                    if(particles_nextstate[j+1]){ //Überprüfung ob rechts schon Teilchen vorhanden
                        particles_nextstate[j+1] = 0; //Wenn Rechts schon Teilchen dann Kollision -> beide Teilchen verschwinden
                        particles_nextstate[j] = 0;
                        printf("Kollision\n");
                    }
                    else{
                        particles_nextstate[j+1] = 1;
                        particles_nextstate[j] = 0;
                    }
                }
                else if(j){
                    if(particles_nextstate[j-1]){ //Überprüfung ob links schon Teilchen vorhanden
                        particles_nextstate[j-1] = 0; //Wenn Links schon Teilchen dann Kollision -> beide Teilchen verschwinden
                        particles_nextstate[j] = 0;
                        printf("Kollision\n");
                    }
                    else{
                        particles_nextstate[j-1] = 1;
                        particles_nextstate[j] = 0;
                    }
                } 
           } 
        }
        for(int j = 0; j < sizeof(particles_nextstate)/4; j++){
            particles[j] = particles_nextstate[j];
        }
        sleep(1);
    }
    
    
    



    return 0;
}
