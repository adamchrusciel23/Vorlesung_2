#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "string_utils.h"

int main() {
    // Wir nutzen fprintf mit stderr für sofortige Sichtbarkeit
    fprintf(stderr, "Test gestartet\n"); 

    assert(custom_len("Hallo") == 5);
    assert(custom_len("") == 0);
    assert(custom_len("Hallo Welt") == 10);
    
    fprintf(stderr, "Dieser Text soll erscheinen\n");

    // Jetzt der absichtliche Crash
    assert(custom_len("Hallo Welt") == 11); 

    fprintf(stderr, "Dieser Text darf nicht erscheinen\n");
    return 0;
}