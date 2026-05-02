#include <new.h>

struct TShape {
    unsigned char* shape;
    int load_type;
    int load_size;
    void* shape_header;
    char gap_10[0x04];
    void* offsets;
    unsigned char* FShape;
    void* shape_info;

    TShape(char* name, int param_2);
    ~TShape();
    unsigned char shape_minmax(long* out_minx, long* out_miny,
                               long* out_maxx, long* out_maxy,
                               long facet);
};

struct TPanel {
    virtual ~TPanel();
};

struct TEasy_Panel : public TPanel {
    char gap_04[0x474];
    virtual ~TEasy_Panel();
};

struct Time_Line_Panel : public TEasy_Panel {
    char gap_478[0x34];
    TShape* background_pic;          // +0x4AC
    short background_pic_wid;        // +0x4B0
    short background_pic_hgt;        // +0x4B2

    int set_background(char* name);
};

int Time_Line_Panel::set_background(char* name) {
    long x_max;
    long x_min;
    long y_max;
    long y_min;

    if (this->background_pic != 0) {
        delete this->background_pic;
        this->background_pic = 0;
        this->background_pic_wid = 0;
        this->background_pic_hgt = 0;
    }

    if (name == 0 || *name == '\0') {
        return 0;
    }

    this->background_pic = new TShape(name, -1);
    this->background_pic->shape_minmax(&x_max, &x_min, &y_max, &y_min, 0);
    this->background_pic_wid = (short)(y_max - x_max + 1);
    this->background_pic_hgt = (short)(y_min - x_min + 1);
    return 1;
}
