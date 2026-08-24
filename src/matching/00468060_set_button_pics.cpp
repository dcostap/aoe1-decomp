// attempt 1: natural TEasy_Panel::set_button_pics with TShape new/delete and CRT string helpers

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
    char gap_000[0x448];
    TShape* button_pics;

    void set_button_pics(char* filename, long id);
};
#endif

void TEasy_Panel::set_button_pics(char* filename, long id) {
    char file_name2[260];

    TShape* old = this->button_pics;
    if (old != 0) {
        delete old;
        this->button_pics = 0;
    }

    if (filename != 0 && *filename != 0 && stricmp(filename, "none") != 0) {
        if (strchr(filename, '.') == 0) {
            sprintf(file_name2, "%s.shp", filename);
        } else {
            sprintf(file_name2, "%s", filename);
        }
        this->button_pics = new TShape(file_name2, id);
    } else if (id != -1) {
        this->button_pics = new TShape("", id);
    }

    if (this->button_pics != 0 && this->button_pics->is_loaded() == 0) {
        TShape* shape = this->button_pics;
        if (shape != 0) {
            delete shape;
        }
        this->button_pics = 0;
    }
}
