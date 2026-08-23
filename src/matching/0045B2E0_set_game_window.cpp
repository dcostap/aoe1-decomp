#include "../../include/mouseptr_context.h"

void TMousePointer::set_game_window(int a, int b, int c, int d) {
    this->game_window.left = a;
    this->game_window.top = b;
    this->game_window.right = c;
    this->game_window.bottom = d;
}
