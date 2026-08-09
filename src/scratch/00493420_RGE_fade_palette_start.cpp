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
// - left in scratch: ordered destination-cursor setup remains non-exact; calls,
//   loop CFG, and final timestamp/FPU/flag logic align.

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

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

extern tagPALETTEENTRY DAT_0086b2a8;
extern float DAT_0086b290;
extern int DAT_0086b2a0;
extern unsigned char DAT_0086b2a4;
extern int DAT_0086b298;
extern int DAT_0086b29c;
extern unsigned int DAT_0086b294;
extern float DAT_0086b2ac;
extern tagPALETTEENTRY DAT_0086b2b0[256];
extern tagPALETTEENTRY DAT_0086b6b0[256];
extern TDrawArea* DAT_0086bab0;

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
