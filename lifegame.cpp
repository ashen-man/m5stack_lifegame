#include <random>
#include <string.h>
#include <M5Stack.h>
#include "lifegame.h"


bool field[LEN];

void initialize() {
    for (size_t i = 0; i < LEN; i++) {
        field[i] = rand() % 2;
    }
}

void evolve() {
    bool tmp[LEN];
    for (size_t i = 0; i < LEN; i++) {
        tmp[i] = is_alive(i);
    }
    memcpy(field, tmp, sizeof(field));
}

bool is_alive(size_t index) {

    uint8_t count = 0;

    size_t x = index % WIDTH;
    size_t y = index / WIDTH;

    size_t lower = y == HEIGHT - 1 ? x : index + WIDTH;
    size_t upper = y == 0 ? WIDTH * (HEIGHT - 1) + x : index - WIDTH;
    size_t right = x == WIDTH - 1 ? index - WIDTH + 1 : index + 1;
    size_t left = x == 0 ? index + WIDTH - 1 : index - 1;

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
    for (size_t i = 0; i < LEN; i++) {
        if (field[i]) {
            M5.Lcd.fillRect(i % WIDTH * BLOCKSIZE, i / WIDTH * BLOCKSIZE, BLOCKSIZE, BLOCKSIZE, TFT_WHITE);
        }
        else {
            M5.Lcd.fillRect(i % WIDTH * BLOCKSIZE, i / WIDTH * BLOCKSIZE, BLOCKSIZE, BLOCKSIZE, TFT_BLACK);
        }
    }
}

