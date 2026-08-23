// attempt 1: same natural TShape replacement pattern as set_button_pics, returning whether background_pic survived loading

#include <stdio.h>
#include <string.h>

extern "C" int __cdecl stricmp(const char* a, const char* b);

#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TShape {
public:
    char data[0x20];
    TShape(char* filename, long id);
    ~TShape();
    int is_loaded();
};

class TEasy_Panel {
public:
    char gap_000[0x204];
    TShape* background_pic;

    int set_background(char* filename, long id);
};
#endif

int TEasy_Panel::set_background(char* filename, long id) {
    char file_name2[260];

    TShape*& background_pic = *(TShape**)((char*)this + 0x204);
    TShape* old = background_pic;
    if (old != 0) {
        delete old;
        background_pic = 0;
    }

    if (filename != 0 && *filename != 0 && stricmp(filename, "none") != 0) {
        if (strchr(filename, '.') == 0) {
            sprintf(file_name2, "%s.shp", filename);
        } else {
            sprintf(file_name2, "%s", filename);
        }
        background_pic = new TShape(file_name2, id);
    } else if (id != -1) {
        background_pic = new TShape("", id);
    }

    if (background_pic != 0 && background_pic->is_loaded() == 0) {
        TShape* shape = background_pic;
        if (shape != 0) {
            delete shape;
        }
        background_pic = 0;
    }
    return background_pic != 0;
}
