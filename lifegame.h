#define BLOCKSIZE 8

const int WIDTH = 320 / BLOCKSIZE;
const int HEIGHT = 240 / BLOCKSIZE;
const size_t LEN = WIDTH * HEIGHT;


void display();
void initialize();
void evolve();
bool is_alive(size_t index);

