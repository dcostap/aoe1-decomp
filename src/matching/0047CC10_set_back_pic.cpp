// 0047CC10 set_back_pic (Pnl_txt.cpp:667-685)
// TTextPanel::set_back_pic(char* name) - void __thiscall
//
// Attempt log:
//   Reconstructed as the void sibling of Time_Line_Panel::set_background
//   (0051EB00, exact match): free old back_pic, then new TShape(name,-1),
//   shape_minmax bounds, store wid/hgt. /GX required for the EH frame
//   (state slot -1 -> 0 -> -1 around the new-expression), same as sibling.
//   back_pic +0x144, back_pic_wid +0x148, back_pic_hgt +0x14A per PDB.
// FLAGS: config/flags/0047CC10_set_back_pic.rsp (/nologo /c /O2 /Oy /GX)
//   /GX required: original has the new-expression EH frame (state slot -1->0->-1
//   around operator_new/TShape ctor); sibling exact matches in the same panel
//   family (0051EB00, 0051EC10) also require /GX.

#include <new.h>

#ifndef PNL_TXT_TU_CONTEXT
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
#endif

#ifndef PNL_TXT_TU_CONTEXT
struct TPanel {
    virtual ~TPanel();
    char gap_04[0xF0];          // TPanel size 0xF4
};

struct TTextPanel : public TPanel {
    char gap_F4[0x50];          // up to +0x144
    TShape* back_pic;           // +0x144
    short back_pic_wid;         // +0x148
    short back_pic_hgt;         // +0x14A

    void set_back_pic(char* name);
};
#endif

void TTextPanel::set_back_pic(char* name) {
    long x_max;
    long x_min;
    long y_max;
    long y_min;

    if (this->back_pic != 0) {
        delete this->back_pic;
        this->back_pic = 0;
        this->back_pic_wid = 0;
        this->back_pic_hgt = 0;
    }

    if (name == 0 || *name == '\0') {
        return;
    }

    this->back_pic = new TShape(name, -1);
    this->back_pic->shape_minmax(&x_max, &x_min, &y_max, &y_min, 0);
    this->back_pic_wid = (short)(y_max - x_max + 1);
    this->back_pic_hgt = (short)(y_min - x_min + 1);
}
