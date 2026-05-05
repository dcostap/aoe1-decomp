// attempt 1: same natural TShape replacement pattern as set_button_pics, returning whether background_pic survived loading

#include <stdio.h>
#include <string.h>

extern "C" int __cdecl stricmp(const char* a, const char* b);

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

int TEasy_Panel::set_background(char* filename, long id) {
    char file_name2[260];

    TShape* old = this->background_pic;
    if (old != 0) {
        delete old;
        this->background_pic = 0;
    }

    if (filename != 0 && *filename != 0 && stricmp(filename, "none") != 0) {
        if (strchr(filename, '.') == 0) {
            sprintf(file_name2, "%s.shp", filename);
        } else {
            sprintf(file_name2, "%s", filename);
        }
        this->background_pic = new TShape(file_name2, id);
    } else if (id != -1) {
        this->background_pic = new TShape("", id);
    }

    if (this->background_pic != 0 && this->background_pic->is_loaded() == 0) {
        TShape* shape = this->background_pic;
        if (shape != 0) {
            delete shape;
        }
        this->background_pic = 0;
    }
    return this->background_pic != 0;
}
