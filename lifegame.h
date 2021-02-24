#define WIDTH 320
#define HEIGHT 240

const size_t len = WIDTH * HEIGHT;
using bitmap = bool(&)[len];

void display();
void initialize();
void evolve();
bool is_alive(size_t index);

