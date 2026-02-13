#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL)); //Initialiesierung
    int zufall = rand() % 2; //gibt 0 oder 1 zurück (links/rechts) 
    int particles[] = {0,0,0,1,0,1,0,1,0,0};
    int* p_particles = particles;
    int next_state_particles[10];
    int* p_next_state_particles = next_state_particles;

    while(1)
    
}
