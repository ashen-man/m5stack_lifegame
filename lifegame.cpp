#include <random>
#include <string.h>
#include <M5Stack.h>
#include "lifegame.h"

bool field[len];

void initialize() {
    for (size_t i = 0; i < len; i++) {
        field[len] = rand() % 2;
    }
}

void evolve() {
    bool tmp[len];
    for (size_t i = 0; i < len; i++) {
        tmp[i] = is_alive(i);
    }
    memcpy(field, tmp, sizeof(field));
}

bool is_alive(size_t index) {

    uint8_t count = 0;

    size_t x = index / WIDTH - 1;
    size_t y = index % WIDTH;

    size_t lower = x == HEIGHT-1 ? y : index+WIDTH;
    size_t upper = x == 0 ? x*(HEIGHT-1)+y : index-WIDTH;
    size_t right = y == WIDTH-1 ? index-WIDTH+1 : index+1;
    size_t left = y == 0 ? index+WIDTH-1 : index-1;

    size_t neighbors[8] = {
        upper - 1,
        upper,
        upper + 1,
        index - 1,
        index + 1,
        lower - 1,
        lower,
        lower + 1,
    };
    for (size_t i = 0; i < 8; i++) {
        if (field[neighbors[i]]) {
            count++;
        }
    }
    switch (count) {
        case 2: return field[index];
        case 3: return true;
        default: return false;
    }
}

void display() {
    uint8_t data[len];
    for (size_t i = 0; i < len; i++) {
        if (field[i]) {
            data[i] = 0xF800;
        }
    }
    M5.Lcd.drawBitmap(0, 0, WIDTH, HEIGHT, data);
}

