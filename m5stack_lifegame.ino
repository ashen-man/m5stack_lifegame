#include <M5Stack.h>
#include "lifegame.h"

bool field[HEIGHT][WIDTH];

void display(rectangle field) {
  for (size_t row = 0; row < HEIGHT; row++) {
      for (size_t column = 0; column < WIDTH; column++) {
          if (field[row][column]) {
            M5.Lcd.drawPixel(column, row, RED);
          }
      }
  }
}

void setup() {
  M5.begin();
  M5.Power.begin();
  initialize(field);
  display(field);
}

// the loop routine runs over and over again forever
void loop(){
    evolve(field);
    display(field);
    delay(2000);
}

