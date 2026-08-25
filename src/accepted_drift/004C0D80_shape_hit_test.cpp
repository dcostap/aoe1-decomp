// VA: 004C0D80 RGE_Sprite::shape_hit_test (516B)
// PDB source: sprite.cpp, lines 855-915
// EH frame (/GX)
// Attempt log:
// - Replaced the field-only scaffold with the natural lazy TShape load,
//   facet-index lookup, transparent-picking switch, and typed shape bounds
//   checks recovered from the executable.  The first checker run is the
//   clean-source baseline.
// - Reversed the frame-bound compare and added explicit switch case 0;
//   the latter recovered the original sub/dec dispatch family.
// - Routed lazy/bounds failures through the proven shared fail epilogue;
//   this reached exact size/frame/instruction/call parity.
// - Recovered the mirrored-arm-first source order and canonical min/max
//   ownership.  Best clean result: 516-byte rebuild, 72 strict differing
//   bytes, 96.32% shape similarity; residual drift is the shape_minmax local
//   address/evaluation and one late mirrored-bound jump.
// - Fresh bounded pass kept the canonical typed source and changed the
//   shared y bounds to explicit fail checks.  This improved the clean output
//   to 70 differing bytes and 97.55% shape similarity; direct x and width
//   variants were worse.  Three focused variant families found no exact
//   source spelling.  The remaining drift is the mirrored max assignment's
//   register and branch placement.
// - Duplicated the typed upper x comparison inside both mirror arms to test
//   the original paired compare hunk; this widened the function to 522 bytes
//   and worsened the positional diff to 189 bytes.  Restored the clean arm.
// - A fresh pass reversed the transparent-picking facet arm.  This recovered
//   the original mirrored shape-check branch layout and reduced the diff to
//   33 bytes with exact size, frame, calls, and 96.32% exact-block coverage.
// - Confirmed ownership from sprite.cpp donors and binary calls: RGE_Sprite
//   owns shape at +0x1C, loaded at +0x14, resource_id at +0x10, frame_num at
//   +0x5E, and transparent_picking_flag at +0x2C.  TShape owns the lazy-load
//   constructor and shape_minmax/shape_check calls.  The /GX frame and the
//   ordered eleven-call set match the original.  shape_minmax uses the
//   canonical min-x, min-y, max-x, max-y output order.  The mirror arm checks
//   x against -max-x and -min-x; the normal arm checks min-x and max-x.
// - Fresh final probes tested compound per-arm ranges, duplicated upper-bound
//   checks after the facet-arm recovery, and a separate upper-bound local.
//   None improved the 33-byte result. The scoped canonical source remains.
// - Re-read orig/ghidra_decomp/sprite.cpp.decomp as source-recovery evidence.
//   Its stack-slot names confirm the same typed shape_minmax output slots,
//   mirrored lower/upper transforms, and common y-bound fault order.  A
//   decompiler-shaped output reorder reached 33 bytes only after the same
//   mirrored assignment form was restored; the simpler canonical source is
//   retained.  A 49-variant bound/header lab and a 294-variant declaration
//   lab found no exact basin.
// ACCEPTED DRIFT: The x-range hunk computes the same lower and upper bounds.
// The original duplicates the upper compare and shares its `jg`; the rebuild
// shares the compare and branch. The later differences only recolor registers
// while pushing identical shape_check arguments. Values, flags at each used
// branch, calls, memory effects, SEH state, cleanup, and fault order match.

extern void __cdecl addstring(char** dst, char* base, char* ext);
extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);
extern "C" void __cdecl free(void* block);
#include "..\..\include\sprite_context.h"

unsigned char RGE_Sprite::shape_hit_test(short x, short y, long facet,
                                         long frame)
{
    char* fname;
    long shape_frame;
    long min_x;
    long min_y;
    long max_x;
    long max_y;
    unsigned char facet_index;

    if (this->shape == 0) {
        if (this->loaded != 0) {
            fname = 0;
            addstring(&fname, this->pict_name, ".shp");
            unsigned long start =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 0x366);
            TShape* shape = new TShape(fname, this->resource_id);
            this->shape = shape;
            unsigned long stop =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 0x368);
            rge_base_game->add_to_timing(0x0b, stop - start);
            free(fname);
        } else {
            goto fail;
        }
    }

    if (frame > this->frame_num) {
        frame = 0;
    }

    facet_index = this->get_facetindex(facet, frame, shape_frame);

    switch (this->transparent_picking_flag) {
    case 0:
        break;

    case 1:
        if (this->shape != 0) {
            if (facet_index != 0) {
                return this->shape->shape_check(-x, y, shape_frame);
            }
            return this->shape->shape_check(x, y, shape_frame);
        }
        break;

    case 2:
        if (this->shape != 0) {
            this->shape->shape_minmax(&min_x, &min_y, &max_x,
                                      &max_y, shape_frame);
            int x_value = x;
            if (facet_index != 0) {
                if (x_value < -max_x) {
                    goto fail;
                }
                max_x = -min_x;
            } else {
                if (x_value < min_x) {
                    goto fail;
                }
            }

            if (x_value > max_x) {
                goto fail;
            }
            if (y < min_y) {
                goto fail;
            }
            if (y > max_y) {
                goto fail;
            }
            return 1;
        }
        break;
    }

fail:
    return 0;
}
