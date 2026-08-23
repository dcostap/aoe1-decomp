// VA: 004C0840 RGE_Sprite::get_size (279B)
// PDB source: sprite.cpp, lines 688-707
// FLAGS: config/flags/004C0840_get_size.rsp (/GX required by the TShape new-expression EH frame)
// Attempt log:
// probe 1 baseline: natural lazy TShape construction, timing calls, and typed
// shape_minmax references were exact-size/frame/call-set, but initialized fname at
// the function declaration and emitted the opposite EH-prologue order (247 diff).
// probe 2: baseline was exact-size/frame/call-set but initialized fname at the
// function declaration; original delays the fname zero store into line 696's
// call setup. Delaying the assignment recovered the mov-fs-first EH prologue and
// stack schedule (223 diff), leaving only the loaded-gate polarity/block placement.
// probe 3: positive nested loaded success with an explicit failure else matched
// the original je-to-0942 topology exactly (MATCH).
// main-agent audit restored canonical base-game polymorphic ownership; emitted
// code remains exact.

extern void __cdecl addstring(char** dst, char* base, char* ext);
extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);
extern "C" void __cdecl free(void* block);

#include "../../include/sprite_context.h"

int RGE_Sprite::get_size(long& min_x, long& min_y, long& max_x,
                         long& max_y, long facet)
{
    char* fname;

    if (this->shape == 0) {
        if (this->loaded != 0) {
            fname = 0;
            addstring(&fname, this->pict_name, ".shp");
            unsigned long start =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 0x2b9);
            TShape* shape = new TShape(fname, this->resource_id);
            this->shape = shape;
            unsigned long stop =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 0x2bb);
            rge_base_game->add_to_timing(0x0b, stop - start);
            free(fname);
        } else {
            return 0;
        }
    }

    return this->shape->shape_minmax(&min_x, &min_y, &max_x, &max_y, facet);
}
