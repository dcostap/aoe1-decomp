// VA: 0041F2D0 RGE_Base_Game::setup_shapes (289 B) EH-framed
// PDB source: basegame.cpp, lines 2630-2647
//
// Attempt log:
// - Baseline: replaced the free-function/decompiler shims with the canonical
//   RGE_Base_Game fields, a 0x20-byte TShape class, and the real
//   TShape(char*, long) new-expression ABI.  Calls aligned and the EH frame
//   appeared; the initialization loop still used a pointer induction.
// - Direct-member loop: spelling the zeroing as this->shapes[i] reproduced the
//   original per-iteration member reload and indexed store.  Exact match.
// - Main-agent audit restored setup_shapes at its donor-backed +0x98 virtual
//   slot behind the canonical base-game destructor; bytes remain exact.
// FLAGS: config/flags/0041F2D0_setup_shapes.rsp (/GX is required by the
//        binary's EH-framed constructor new-expressions).

#include <new.h>

extern "C" void* calloc(int num, int size);

class TShape {
public:
    char gap_00[0x20];

    TShape(char* filename, long file_id);
};

class RGE_Base_Game {
public:
#define BASE_PAD(n) virtual void base_pad##n();
    virtual ~RGE_Base_Game();
    BASE_PAD(1) BASE_PAD(2) BASE_PAD(3) BASE_PAD(4) BASE_PAD(5) BASE_PAD(6)
    BASE_PAD(7) BASE_PAD(8) BASE_PAD(9) BASE_PAD(10) BASE_PAD(11) BASE_PAD(12)
    BASE_PAD(13) BASE_PAD(14) BASE_PAD(15) BASE_PAD(16) BASE_PAD(17) BASE_PAD(18)
    BASE_PAD(19) BASE_PAD(20) BASE_PAD(21) BASE_PAD(22) BASE_PAD(23) BASE_PAD(24)
    BASE_PAD(25) BASE_PAD(26) BASE_PAD(27) BASE_PAD(28) BASE_PAD(29) BASE_PAD(30)
    BASE_PAD(31) BASE_PAD(32) BASE_PAD(33) BASE_PAD(34) BASE_PAD(35) BASE_PAD(36)
    BASE_PAD(37)
    virtual int setup_shapes();
#undef BASE_PAD

    char gap_04[0x54];
    short shape_num;
    char gap_5A[2];
    TShape** shapes;
};

int RGE_Base_Game::setup_shapes()
{
    TShape* shape;
    TShape** shape_array;
    int i;

    this->shape_num = 3;
    shape_array = (TShape**)calloc(3, 4);
    this->shapes = shape_array;
    if (shape_array == 0)
        return 0;

    for (i = 0; i < this->shape_num; ++i)
        this->shapes[i] = 0;

    shape = new TShape("groupnum.shp", 0xC4E3);
    this->shapes[0] = shape;

    shape = new TShape("waypoint.shp", 0xC4E4);
    this->shapes[1] = shape;

    shape = new TShape("moveto.shp", 0xC4E5);
    this->shapes[2] = shape;

    return 1;
}
