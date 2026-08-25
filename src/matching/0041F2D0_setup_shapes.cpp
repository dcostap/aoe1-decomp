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
