// VA: 00493420 RGE_fade_palette_start
// PDB donor: scr_cred.cpp lines 660-701
// Attempt log:
// - baseline candidate: period-plausible global palette buffers, typed palette
//   entries, natural initialization/copy loops, and the existing GetPalette and
//   debug_timeGetTime surfaces.
// - reloaded the stored duration/direction globals for their later uses; this
//   matches the observed global reloads and removes artificial parameter liveness.
// - the binary's copy loop is red, blue, green, flags and ends with a signed
//   destination-address comparison; the typed cursor form preserves that shape.
// - a reversed global-assignment experiment was the metric-best diagnostic
//   (277 bytes, 121 positional differences) but is not retained as source: the
//   natural color/time/type/first/last/draw order is the plausible reconstruction.
// - the 720-order sweep found a plausible color/draw/time/type/first/last order
//   that matches the prologue and initialization through the palette branch;
//   the remaining copy-cursor setup is still structurally non-exact.
// - windows.h context and global declaration-order probes were codegen-neutral;
//   a binary-backed byte-cursor copy improved resynchronization but was rolled
//   back as decompiler-shaped scaffolding.
// - this claim's declaration/initializer splits, source/destination cursor
//   order, named end pointer, red-channel alias, comma sequencing, and hoisted
//   destination lifetime were codegen duplicates or structural regressions;
//   the focused 12-form cursor lab likewise found no improved setup basin.
// - treating the two palette globals as inventory-backed byte objects expanded
//   the function to 294 bytes and broke the exact initialization block; the
//   raw cursor forms were not retained. Moving ++target into the loop condition
//   kept 277 bytes but lost an exact late block, so it was restored.
// - the same-TU donor's scalar-byte globals with one-time typed palette aliases
//   expanded the function to 294 bytes and moved the first mismatch to the
//   prologue; this declaration/context lead was rolled back.
// - corrected byte-cursor and parameter-alias variants both broke the exact
//   prologue; a byte-array overlay and combined cursor declaration were
//   codegen duplicates. The exact palette-step scalar surface was not retained.
// - the exact debug-time donor ABI (C linkage, cdecl, mutable char path) is
//   retained with the natural source literal; it is codegen-neutral.
// - a typed red-channel cursor alias was a diagnostic liveness probe; it
//   collapsed the saved-register setup and widened the mismatch to 227 bytes,
//   so the clean typed cursor reconstruction is restored.
// - this claim revalidated the clean source at 277 bytes and 117 positional
//   differences. Byte-pointer source/destination anchors widened the drift to
//   217 bytes; an explicit decompiler-shaped next-cursor form widened it to
//   227 bytes. Both forms were rolled back.
// - left in scratch: ordered destination-cursor setup remains non-exact; calls,
//   loop CFG, and final timestamp/FPU/flag logic align.
// - the prior byte-channel cursor basin reaches 274 bytes with two residual SIB
//   bytes, but raw cursor plumbing is not a valid source model for this target.
// - keep the typed palette-entry ownership and signed address-bound loop. A typed
//   destination loop is 277 bytes with 117 differences, but preserves the target
//   behavior and policy. Do not force the SIB order with opaque arithmetic.
// - the exact RGE_fade_palette donor in color.cpp shows the same SIB store family;
//   it does not justify changing this target's typed global ownership or timing.
// - repository-only follow-up: the 274-byte/2-difference candidate uses four
//   unsigned-char channel cursors. The original copy setup requires that
//   topology, but the assignment forbids byte cursors and opaque address tuning.
// - natural typed-entry ownership remains 277 bytes with 117 differences. Its
//   initialization, calls, loop behavior, and timestamp tail align; no policy-
//   valid typed rewrite recovered the original per-channel setup.
// - deeper scr_cred TU pass: the canonical TDrawArea/TDrawSystem palette
//   surface, SDK PALETTEENTRY typedef, stdio/stdlib/new/io/fcntl header state,
//   RGE_fade_palette_step declarations, and neighboring panel declarations
//   were each tested. They were codegen-neutral, alone and in combination.
// - a contiguous typed fade-state aggregate was farther (213 differences),
//   while inventory scalar PALETTEENTRY roots with address-of array decay were
//   the same 277-byte basin. The typed pointer bound without its signed cast
//   lost the original loop block; the signed address-bound cast is required.
// - the natural API array-parameter spelling was neutral. The only closer
//   basin remains the prior four-byte channel-cursor form at 274 bytes/2
//   differences, which is rejected as raw cursor plumbing. Keep this clean
//   typed-entry reconstruction as the policy-valid frontier.
// - ownership audit: the target writes two 0x400-byte regions rooted at
//   DAT_0086b2b0 and DAT_0086b6b0. Each region repeats a four-byte record:
//   red +0, green +1, blue +2, and flags +3. The zeroing loop proves the
//   +4 stride and 256-entry extent. GetPalette consumes the first base, and
//   the exact RGE_fade_palette_step consumer passes both bases as
//   tagPALETTEENTRY pointers. Exact TDrawArea palette donors and the reviewed
//   tagPALETTEENTRY layout prove this entry ownership.
// - the 274-byte diagnostic is only another representation of those fields:
//   its four cursors are base+0, base+1, base+2, and base+3, and its source
//   offsets are 0, 1, 2, and 3 with one four-byte advance. No evidence names
//   independent channel arrays, a shifted entry array, or a fade-state
//   aggregate. The inventory lists only scalar root bytes for both globals,
//   so the local typed array extent is behavior-proven, not shared ABI proof.
// - exact 00439750 ReadPalette ownership is separate. Its System_color_Table
//   is a reviewed PAL_TABLE array with size 0x8, index +0, colors +4..+6, and
//   a linked eight-byte advance. That evidence proves the PAL_TABLE model for
//   005841e0, not for the four-byte fade buffers. Do not transfer its anchor
//   or cursor form to this target.
// - this claim tested ten additional natural typed forms: indexed loops,
//   typed pointer bounds, explicit count bounds, aggregate entry assignment,
//   source-owned indexing, SDK PALETTEENTRY context, const source aliases,
//   and explicit entry-zero bases. None improved the 117-byte clean basin;
//   aggregate assignment and source-owned indexing were structural regressions.
//   The policy-clean typed source is restored.
// - independent per-entry audit: twenty natural typed probes tested entry
//   references, indexed entries, copy grouping, channel assignment orders,
//   signed channel casts, pointer update order, and loop induction. Typed
//   references, indexing, comma grouping, signed casts, declaration order, and
//   pointer update order were codegen duplicates or regressions. Aggregate
//   entry copies and alternate channel orders broke the prologue or loop body.
// - original line 701 stores red, blue, green, and flags in that order. Exact
//   GetPalette and palette-step donors support four-byte PALETTEENTRY entries.
//   The earlier 274-byte/2-difference form used four forbidden byte cursors.
// - TU recovery: declaring DAT_0086b2b0 as an unsized external
//   tagPALETTEENTRY array naturally derives the four channel cursors and
//   recovers the original 274 bytes. A fixed [256] declaration stays in the
//   277-byte basin. DAT_0086b6b0 is fixed at [256] here; fixed and unsized
//   declarations both produce the exact result.
// - exact-first checkpoint: unsized declarations for both palette globals,
//   validated by check_function as 274 bytes and 0 differing bytes.
// - exact reduction: restored the proven [256] extent for DAT_0086b6b0;
//   DAT_0086b2b0 remains unsized and the result stays an exact MATCH.
// - TU audit: global declaration order, same-TU step and credits declarations,
//   Windows/SDK palette type context, standard headers, and tested pragmas did
//   not change the fixed-array basin. The unsized declaration is the controlling
//   source feature, not a hidden header or function-order effect.
// - FLAGS: config/flags/default.rsp (/nologo /c /O2 /Oy). The small VC5 flag
//   classification sweep stayed exact after the unsized declaration change.

#include "../../include/scr_cred_context.h"

#if 0
struct tagPALETTEENTRY {
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

class TDrawArea {
public:
    void GetPalette(tagPALETTEENTRY* entries);
};

extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);

extern tagPALETTEENTRY DAT_0086b2a8;
extern float DAT_0086b290;
extern int DAT_0086b2a0;
extern unsigned char DAT_0086b2a4;
extern int DAT_0086b298;
extern int DAT_0086b29c;
extern unsigned int DAT_0086b294;
extern float DAT_0086b2ac;
extern tagPALETTEENTRY DAT_0086b2b0[];
extern tagPALETTEENTRY DAT_0086b6b0[256];
extern TDrawArea* DAT_0086bab0;
#endif

void RGE_fade_palette_start(TDrawArea* draw_area, tagPALETTEENTRY fade_color,
                            float fade_time, unsigned char fade_type,
                            tagPALETTEENTRY* palette, int first, int last)
{
    DAT_0086bab0 = draw_area;
    DAT_0086b2a8 = fade_color;
    DAT_0086b290 = fade_time;
    DAT_0086b2a4 = fade_type;
    DAT_0086b298 = first;
    DAT_0086b29c = last;

    for (int i = 0; i < 256; i++) {
        DAT_0086b2b0[i].peRed = 0;
        DAT_0086b6b0[i].peRed = 0;
        DAT_0086b2b0[i].peBlue = 0;
        DAT_0086b6b0[i].peBlue = 0;
        DAT_0086b2b0[i].peGreen = 0;
        DAT_0086b6b0[i].peGreen = 0;
        DAT_0086b2b0[i].peFlags = 0;
        DAT_0086b6b0[i].peFlags = 0;
    }

    if (palette == 0) {
        draw_area->GetPalette(DAT_0086b2b0);
    } else {
        tagPALETTEENTRY* target = DAT_0086b2b0;
        tagPALETTEENTRY* source = palette;
        do {
            target->peRed = source->peRed;
            target->peBlue = source->peBlue;
            target->peGreen = source->peGreen;
            target->peFlags = source->peFlags;
            ++target;
            ++source;
        } while ((int)target < (int)DAT_0086b6b0);
    }

    DAT_0086b294 = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x2B5);
    DAT_0086b2ac = DAT_0086b290 * DAT_0086b290;

    if (DAT_0086b2a4 == 1) {
        DAT_0086b2a0 = 0;
    } else {
        DAT_0086b2a0 = 100;
    }
}
