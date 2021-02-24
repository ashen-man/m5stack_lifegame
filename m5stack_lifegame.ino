#include <M5Stack.h>
#include "lifegame.h"

void setup() {
    M5.begin();
    M5.Power.begin();
    initialize();
}

void loop(){
    while (true) {
        // evolve();
        display();
    }
}
