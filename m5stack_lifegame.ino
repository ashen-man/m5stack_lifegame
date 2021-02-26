#include <M5Stack.h>
#include "lifegame.h"


void setup() {
    M5.begin();
    initialize();
}

void loop(){
    display();
    evolve();
    delay(100);
}

