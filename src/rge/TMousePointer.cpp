#include "TMousePointer.h"
#include <string.h>

TMousePointer::TMousePointer(int custom_type) {
    memset(this, 0, sizeof(TMousePointer));
    this->Type = custom_type;
}

TMousePointer::~TMousePointer() {
}

int TMousePointer::setup(int custom_mouse, TDrawArea *draw_area, char *cursor_file, int resource_id, int count) {
    this->DrawArea = draw_area;
    this->Visible = 0;
    return 1;
}
