// TPicturePanel::setup
// VA: 0047A2A0
// PDB: Pnl_pic.cpp:50-87
//
// Attempt log:
// - draft 1: strcpy+strlen+memcpy → function 12 bytes too short (library calls, not inlined)
// - draft 2: while-loop → same issue
// - draft 3: strlen+memcpy with restructured control flow → right size but 83% diff (register allocation)
// Root cause: VC5 assigns param_7 to ESI (my code) vs EDI (original), cascading through entire function.
// Register allocation is deeply coupled to control-flow structure.
// Left in scratch until a different source model can be explored.

#include "..\..\include\game_globals.h"
#include <string.h>

class TDrawArea {
public:
    char gap_00[0x4];
};

class TPanel {
public:
    char gap_00[0xF4];
    long setup(TDrawArea* p1, TPanel* p2, long p3, long p4, long p5, long p6, int p7);
};

class TPicture {
public:
    char gap_00[0x14];
    int Width;
    int Height;
};

class TShape {
public:
    int is_loaded();
    void shape_bounds(int zero, short* outW, short* outH);
};

class TPicturePanel : public TPanel {
public:
    char pic_name[12];
    int res_id;
    int size_from_pic;
    int keep_loaded;
    int own_pic;
    int pic_type;
    TPicture* pic;
    TShape* shape;

    long setup(TDrawArea* p1, TPanel* p2, long p3, long p4, long p5, long p6, char* p7, long p8, int p9, int p10);
    int load_pic();
    void free_pic();
    void draw();
};

long TPicturePanel::setup(TDrawArea* p1, TPanel* p2, long p3, long p4, long p5, long p6, char* p7, long p8, int p9, int p10)
{
    long width;
    long height;

    if (p7) {
        int len = strlen(p7) + 1;
        memcpy(this->pic_name, p7, len);
    } else {
        this->pic_name[0] = 0;
    }

    this->res_id = p8;
    this->size_from_pic = p9;
    this->keep_loaded = p10;

    if ((p9 || p10) && this->load_pic()) {
        if (this->size_from_pic) {
            if (this->pic_type) {
                short sw, sh;
                this->shape->shape_bounds(0, &sw, &sh);
                width = sw;
                height = sh;
            } else {
                width = this->pic->Width;
                height = this->pic->Height;
            }
        } else {
            width = p5;
            height = p6;
        }
        if (!this->keep_loaded)
            this->free_pic();
    } else {
        width = p5;
        height = p6;
    }

    ((TPanel*)this)->setup(p1, p2, p3, p4, width, height, 0);
    return 1;
}
