#include <iostream>
using namespace std;

// Hilfsfunktion zur Ausgabe des Arrays
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[4] = {5, 2, 8, 1};
    int n = 4;

    cout << "Ausgangsarray: ";
    printArray(arr, n);
    cout << "-----------------------" << endl;

    // Äußere Schleife: Wandert von links nach rechts durch das Array
    for (int i = 0; i < n - 1; i++) {
        // Wir nehmen an, das erste Element des unsortierten Teils ist das kleinste
        int min_idx = i;

        // Innere Schleife: Sucht im restlichen Array nach einem noch kleineren Element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Neuen Index des kleinsten Elements merken
            }
        }

        // Wenn ein kleineres Element gefunden wurde, tauschen wir es an die richtige Stelle (i)
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }

        // Zeigt den Zustand des Arrays nach jedem Durchlauf
        cout << "Durchlauf " << i + 1 << ": ";
        printArray(arr, n);
    }

    cout << "-----------------------" << endl;
    cout << "Endgueltig sortiert: ";
    printArray(arr, n);

    return 0;
}