#include "TMousePointer.h"
#include <string.h>

// Address: 0x00444300
TMousePointer::TMousePointer(int custom_type) {
    memset(this, 0, sizeof(TMousePointer));
    this->Type = custom_type;
}

// Address: 0x00444340
TMousePointer::~TMousePointer() {
}

// Address: 0x00444380
int TMousePointer::setup(int custom_mouse, TDrawArea *draw_area, char *cursor_file, int resource_id, int count) {
    this->DrawArea = draw_area;
    this->Visible = 0;
    return 1;
}
