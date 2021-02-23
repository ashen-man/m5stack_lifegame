#define WIDTH 320
#define HEIGHT 240

using rectangle = bool(&)[HEIGHT][WIDTH];

void display(rectangle field);
void initialize(rectangle field);
void evolve(rectangle field);
bool is_alive(rectangle field, size_t row, size_t column);
