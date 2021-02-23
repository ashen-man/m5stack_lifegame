#include <random>
#include <string.h>
#include "lifegame.h"


void initialize(rectangle field) {
    for (size_t row = 0; row < HEIGHT; row++) {
        for (size_t column = 0; column < WIDTH; column++) {
            field[row][column] = rand() % 2;
        }
    }
}

void evolve(rectangle field) {
    bool tmp[HEIGHT][WIDTH];
    for (size_t row = 0; row < HEIGHT; row++) {
        for (size_t column = 0; column < WIDTH; column++) {
            tmp[row][column] = is_alive(field, row, column);
        }
    }
    for (int row = 0; row < HEIGHT; row++) {
        memcpy(field[row], tmp[row], sizeof(field[row]));
    }
}

bool is_alive(rectangle field, size_t row, size_t column) {

    uint8_t count = 0;

    size_t lower = row == HEIGHT-1 ? 0 : row+1;
    size_t upper = row == 0 ? HEIGHT-1 : row-1;
    size_t right = column == WIDTH-1 ? 0 : column+1;
    size_t left = column == 0 ? WIDTH-1 : column-1;

    size_t neighbors[8][2] = {
        {upper, left},
        {upper, column},
        {upper, right},
        {row, left},
        {row, right},
        {lower, left},
        {lower, column},
        {lower, right}
    };
    for (size_t i = 0; i < 8; i++) {
        if (field[neighbors[i][0]][neighbors[i][1]]) {
            count++;
        }
    }
    switch (count) {
        case 2: return field[row][column];
        case 3: return true;
        default: return false;
    }
}
