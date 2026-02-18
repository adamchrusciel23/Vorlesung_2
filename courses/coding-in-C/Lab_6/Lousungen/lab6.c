#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE_ARRAY 3000

typedef struct{
    float time;
    double probability;
}SensorData;

typedef struct{
    int id;
    double threshold;
    SensorData data[SIZE_ARRAY];
    int object_detection[SIZE_ARRAY];
}Sensor;

int main(){
    float startzeit_messung = 0;
    float endzeit_messung = 0;
    bool messen = false;
    Sensor sensor1;
    Sensor sensor2;
    sensor1.id = 1;
    sensor2.id = 2;
    sensor1.threshold = 0.8;
    sensor2.threshold = 0.7;
    FILE *f1 = fopen("../sensor1.txt", "r");
    FILE *f2 = fopen("../sensor2.txt", "r");
    if(f1 == NULL){//Fehlerbehandlung
        printf("Fehler beim öffnen von sensor1.txt\n");
    }
    else{
        printf("sensor1.txt erfolgreich geöffnet\n");
    }
    if(f2 == NULL){//Fehlerbehandlung
        printf("Fehler beim öffnen von sensor2.txt\n");
    }
    else{
        printf("sensor2.txt erfolgreich geöffnet\n");
    }
    for(int i = 0; i < SIZE_ARRAY; i++){//Einlesen der Daten
        fscanf(f1, "%f %lf", &sensor1.data[i].time, &sensor1.data[i].probability);
    }
    for(int i = 0; i < SIZE_ARRAY; i++){//Einlesen der Daten
        fscanf(f2, "%f %lf", &sensor2.data[i].time, &sensor2.data[i].probability);
    }
    fclose(f1);
    fclose(f2);
    f1 = NULL;
    f2 = NULL; //da Pointer nichtmehr verwendet werden sollen.
    for(int i = 0; i < SIZE_ARRAY; i++){//Objekterkennung
        if(sensor1.data[i].probability > sensor1.threshold){
            sensor1.object_detection[i] = 1;
        }
        else{
            sensor1.object_detection[i] = 0;
        }
        if(sensor2.data[i].probability > sensor2.threshold){
            sensor2.object_detection[i] = 1;
        }
        else{
            sensor2.object_detection[i] = 0;
        }
    }
    for(int i = 0; i < SIZE_ARRAY; i++){//Ausgabe der Ergebnisse sensor 1
        if(sensor1.object_detection[i] && messen == false){ //Messung starten
            startzeit_messung = sensor1.data[i].time;
            messen = true;
        }
        if(!sensor1.object_detection[i] && messen == true || messen == true && i==SIZE_ARRAY-1){ //Messung stoppen
            if(i == SIZE_ARRAY-1){
                endzeit_messung = sensor2.data[i].time;
            }
            else{
                endzeit_messung = sensor2.data[i-1].time;
            }
            messen = false;
            printf("Zeitintervall für sensor1 = %.2f - %.2f\n", startzeit_messung, endzeit_messung);
        }
    }
    startzeit_messung = 0;
    endzeit_messung = 0;
    messen = false; //Hilfswerte neu Initialisieren vor naechster Messung
    for(int i = 0; i < SIZE_ARRAY; i++){//Ausgabe der Ergebnisse sensor 2
        if(sensor2.object_detection[i] && messen == false){ //Messung starten
            startzeit_messung = sensor2.data[i].time;
            messen = true;
        }
        if(!sensor2.object_detection[i] && messen == true || messen == true && i==SIZE_ARRAY-1){ //Messung stoppen
            if(i == SIZE_ARRAY-1){
                endzeit_messung = sensor2.data[i].time;
            }
            else{
                endzeit_messung = sensor2.data[i-1].time;
            }
            messen = false;
            printf("Zeitintervall für sensor2 = %.2f - %.2f\n", startzeit_messung, endzeit_messung);
        }
    }
    startzeit_messung = 0;
    endzeit_messung = 0;
    messen = false; //Hilfswerte neu Initialisieren vor naechster Messung
    printf("Zeitintervall für beide Sensoren:\n");
    for(int i = 0; i < SIZE_ARRAY; i++){
        if(sensor1.object_detection[i] && sensor2.object_detection[i] && messen == false){
            startzeit_messung = sensor1.data[i].time;
            messen = true;
        }
        if((!sensor1.object_detection[i] || !sensor2.object_detection[i]) && messen == true){
            if(i == SIZE_ARRAY-1){
                endzeit_messung = sensor2.data[i].time;
            }
            else{
                endzeit_messung = sensor2.data[i-1].time;
            }
            messen = false;
            printf("%.2f - %.2f\n", startzeit_messung, endzeit_messung);
        }
    }
}
