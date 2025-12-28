#pragma once
#include "../types.h"

class TMousePointer {
public:
    TMousePointer();

    int setup(class TDrawArea *render_area, const char *cursor_file, int cursor_file_id, int drawn);

    char data[596];
};

static_assert(sizeof(TMousePointer) == 596, "TMousePointer size mismatch");
