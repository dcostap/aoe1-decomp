// TPicturePanel::setup
// VA: 0047A2A0
// PDB: Pnl_pic.cpp:50-87
//
// Attempt log:
// - draft 1: strcpy+strlen+memcpy → function 12 bytes too short (library calls, not inlined)
// - draft 2: while-loop → same issue
// - draft 3: strlen+memcpy with restructured control flow → right size but 83% diff (register allocation)
// - current baseline hypothesis: use the natural strcpy intrinsic, mutate the width/height
//   parameters, and preserve the binary's Picture (zero) versus Shape branch.
// - exact probe: function-scope short bounds locals coalesce naturally into the dead p7/p8
//   parameter homes; explicit parameter casts were tested and rolled back as unnecessary.
// - exact ABI probe: shape_bounds is an unsigned-char thiscall with long/short-reference args.
// Root cause of the old draft's broad drift: VC5 assigned param_7 to ESI (my code) vs EDI
// (original), cascading through the function. Parameter-home reuse for shape bounds is
// expected compiler behavior and is now recovered from ordinary short locals.
// Main-agent audit restored canonical TPanel inheritance and a qualified base
// setup call; emitted code remains exact.

#include "..\..\include\game_globals.h"
#include <string.h>

class TDrawArea {
public:
    char gap_00[0x4];
};

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0xF0];
    long setup(TDrawArea* p1, TPanel* p2, long p3, long p4, long p5, long p6, int p7);
};

class TPicture {
public:
    char gap_00[0x14];
    long Width;
    long Height;
};

class TShape {
public:
    unsigned char shape_bounds(long zero, short& outW, short& outH);
};

class TPicturePanel : public TPanel {
public:
    enum PictureType {
        Picture = 0,
        Shape = 1
    };

    char pic_name[12];
    long res_id;
    int size_from_pic;
    int keep_loaded;
    int own_pic;
    PictureType pic_type;
    TPicture* pic;
    TShape* shape;

    long setup(TDrawArea* p1, TPanel* p2, long p3, long p4, long p5, long p6, char* p7, long p8, int p9, int p10);
    int load_pic();
    void free_pic();
    void draw();
};

long TPicturePanel::setup(TDrawArea* p1, TPanel* p2, long p3, long p4, long p5, long p6, char* p7, long p8, int p9, int p10)
{
    short sw, sh;

    if (p7) {
        strcpy(this->pic_name, p7);
    } else {
        this->pic_name[0] = 0;
    }

    this->res_id = p8;
    this->size_from_pic = p9;
    this->keep_loaded = p10;

    if ((p9 || p10) && this->load_pic()) {
        if (this->size_from_pic) {
            if (this->pic_type == Picture) {
                p5 = this->pic->Width;
                p6 = this->pic->Height;
            } else {
                this->shape->shape_bounds(0, sw, sh);
                p5 = sw;
                p6 = sh;
            }
        }
        if (!this->keep_loaded)
            this->free_pic();
    }

    TPanel::setup(p1, p2, p3, p4, p5, p6, 0);
    return 1;
}
