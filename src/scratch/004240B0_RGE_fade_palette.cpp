// VA: 004240B0 RGE_fade_palette
// Attempt log:
// try 1: direct decompiler/asm reconstruction with local palette arrays, GetPalette/SetPalette, debug_timeGetTime, translate palette, fade-in/fade-out branches.
// try 2: 256-entry palette arrays and direct entries compile cleanly but are 640B vs original 661B.
// try 3: model original stack as palette1/palette2 with unused element 0 and calls using +1 entries; exact 661B but stack frame becomes 0x818 vs original 0x810 and broad drift.
// try 4: reverted to 256-entry arrays to avoid false stack-frame match by extra storage; remains 640B.
// try 5: kept member calls for GetPalette/SetPalette rather than fake helpers; call convention/scheduling is correct family.
// try 6: copied source palette with explicit per-channel loop to model original byte-copy loop.
// try 7: tested fade-in and fade-out as separate do/while branches matching original branch order.
// try 8: modeled debug_timeGetTime calls with source path constant and line ids 0x69/0x70/0x88.
// try 9: modeled quadratic percent calculation with float temporaries; FPU compare/order still differs.
// try 10: leaving in scratch: clean source is too small and the only exact-size probe used an incorrect oversized frame, so not accepted_drift-safe.
// try 11: reordered copied palette channels to red/blue/green/flags, following the original byte-store order; checking loop register roles and frame.
// try 12: changed the binary's byte-sized completion flag to source-level bool, checking whether VC5 restores the post-copy done/draw-area reload order.
// try 13: used the source-proven double zero guard and delta_time > fade_time operand order in both fade branches; checking x87 compare polarity.
// try 14: introduced a narrowly scoped draw-area alias after palette acquisition to probe natural receiver lifetime/reload ordering; diagnostic only unless it preserves the exact body.
// try 15: split the completion-flag declaration from its first-statement false assignment, matching the original line-72 initialization site.
// try 16: replaced the indexed copy with a typed source/destination cursor loop, following the decompiler's pointer topology; checking whether the tail reload order is source-loop dependent.
// try 17: restored the period Windows palette type/header surface, checking whether donor TU context selects the original final reload order.
// try 18: restored the proven TDrawArea DrawSystem member surface from exact GetPalette/SetPalette donors; final context probe for the two reload order.
// Best reconstruction: typed 256-entry local palettes, red/blue/green/flags copy order, typed cursor ownership, and the source-proven double-zero/x87 guard forms.
// Final validated gap: 10 positional bytes at the palette-copy tail only; calls, frame/size, CFG, and all later fade code are exact. The remaining order is mov [draw_area] before/after mov [done].
// Follow-up TU pass: swapping old_time and done declarations emitted identical code.
// No new evidence supports an unnatural volatile or aliasing form for this reload order.

#include <windows.h>

class TDrawSystem;

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    void GetPalette(tagPALETTEENTRY* entries);
    void SetPalette(tagPALETTEENTRY* entries);
};

extern "C" int __cdecl debug_timeGetTime(char*, int);
extern "C" void __cdecl RGE_translate_palette(tagPALETTEENTRY*, tagPALETTEENTRY*, tagPALETTEENTRY, long, int, int);
extern "C" long __cdecl _ftol();

void __cdecl RGE_fade_palette(TDrawArea* draw_area, tagPALETTEENTRY fade_color, float fade_time,
                              unsigned char fade_type, tagPALETTEENTRY* palette, int first, int last)
{
    float delta_time;
    bool done;
    long old_time;
    float fade_time2;
    tagPALETTEENTRY palette1[256];
    tagPALETTEENTRY palette2[256];

    done = false;

    for (int i = 0; i < 256; i++) {
        palette1[i].peRed = 0;
        palette2[i].peRed = 0;
        palette1[i].peBlue = 0;
        palette2[i].peBlue = 0;
        palette1[i].peGreen = 0;
        palette2[i].peGreen = 0;
        palette1[i].peFlags = 0;
        palette2[i].peFlags = 0;
    }

    if (palette == 0) {
        draw_area->GetPalette(palette1);
    } else {
        tagPALETTEENTRY* target = palette1;
        tagPALETTEENTRY* source = palette;
        for (int j = 0; j < 256; j++) {
            target->peRed = source->peRed;
            target->peBlue = source->peBlue;
            target->peGreen = source->peGreen;
            target->peFlags = source->peFlags;
            ++target;
            ++source;
        }
    }

    old_time = debug_timeGetTime((char*)0x5804C8, 0x69);
    fade_time2 = fade_time * fade_time;

    if (fade_type == 1) {
        do {
            long pct;
            long cur_time = debug_timeGetTime((char*)0x5804C8, 0x70);
            delta_time = (float)(cur_time - old_time) * 0.001f;
            if (fade_time <= 0.0 || delta_time > fade_time || delta_time < 0.0f) {
                pct = 100;
            } else {
                pct = (long)((delta_time * delta_time / fade_time2) * 100.0f);
            }
            if (pct >= 100) {
                pct = 100;
                done = 1;
            }
            RGE_translate_palette(palette1, palette2, fade_color, pct, first, last);
            draw_area->SetPalette(palette2);
        } while (!done);
    } else {
        do {
            long pct;
            long cur_time = debug_timeGetTime((char*)0x5804C8, 0x88);
            delta_time = fade_time - ((float)(cur_time - old_time) * 0.001f);
            if (fade_time <= 0.0 || delta_time > fade_time || delta_time < 0.0f) {
                pct = 0;
            } else {
                pct = (long)((delta_time * delta_time / fade_time2) * 100.0f);
            }
            if (pct <= 0) {
                pct = 0;
                done = 1;
            }
            RGE_translate_palette(palette1, palette2, fade_color, pct, first, last);
            draw_area->SetPalette(palette2);
        } while (!done);
    }
}
