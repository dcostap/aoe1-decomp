// 0051EC10 Time_Line_Panel::set_background
// Source: tpnl_tml.cpp lines 275-314
// attempt 1: natural source combining 0051EB00 and TEasy_Panel set_background patterns.

#include <stdio.h>
#include <string.h>
#include <new.h>

extern "C" int __cdecl stricmp(const char* a, const char* b);

#define STR_NONE ((char*)0x00584D54)
#define STR_S_SHP ((char*)0x00584EAC)
#define STR_S ((char*)0x0057F324)
#define STR_EMPTY ((char*)0x00592A40)

class TShape {
public:
    char data[0x20];
    TShape(char* name, long id);
    ~TShape();
    int is_loaded();
    unsigned char shape_minmax(long* out_minx, long* out_miny,
                               long* out_maxx, long* out_maxy,
                               long facet);
};

class TPanel { public: virtual ~TPanel(); };
class TEasy_Panel : public TPanel { public: char gap_04[0x474]; virtual ~TEasy_Panel(); };

class Time_Line_Panel : public TEasy_Panel {
public:
    char gap_478[0x34];
    TShape* background_pic;   // +4AC
    short background_pic_wid; // +4B0
    short background_pic_hgt; // +4B2

    int set_background(char* name, long id);
};

int Time_Line_Panel::set_background(char* name, long id)
{
    long y_max;
    long y_min;
    long x_min;
    long x_max;
    char file_name2[260];

    if (this->background_pic != 0) {
        delete this->background_pic;
        this->background_pic = 0;
        this->background_pic_wid = 0;
        this->background_pic_hgt = 0;
    }

    if (name != 0 && *name != 0 && stricmp(name, STR_NONE) != 0) {
        if (strchr(name, '.') == 0) {
            sprintf(file_name2, STR_S_SHP, name);
        } else {
            sprintf(file_name2, STR_S, name);
        }
        this->background_pic = new TShape(file_name2, id);
    } else if (id != -1) {
        this->background_pic = new TShape(STR_EMPTY, id);
    }

    if (this->background_pic != 0 && this->background_pic->is_loaded() == 0) {
        delete this->background_pic;
        this->background_pic = 0;
    }

    if (this->background_pic != 0) {
        this->background_pic->shape_minmax(&x_max, &x_min, &y_max, &y_min, 0);
        this->background_pic_wid = (short)(y_max - x_max + 1);
        this->background_pic_hgt = (short)(y_min - x_min + 1);
        return 1;
    }
    return 0;
}
