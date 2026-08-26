#include "../../include/music_context.h"

void TMusic_System::set_fade_out(int a, unsigned long b) {
    this->fade_out = a;
    this->fade_time = b;
}
