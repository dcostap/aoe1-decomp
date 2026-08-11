// VA: 004C04F0 RGE_Sprite::draw (304B)
// PDB source: sprite.cpp, lines 594-621
// Attempt log:
// baseline reconstruction: natural typed RGE_Sprite/RGE_Picture_List ownership,
// child-list scan, draw-level coordinate selection, and do_draw calls.
// parameter mutation/direct-return and nonpositive-list guards reached the right
// size but stayed in a different register/frame basin; top-level locals and a
// typed 16-byte cursor did not recover the original saved-this topology.
// best emitted probe: direct parameter mutation, 304B, 289 differing bytes;
// clean source retained because the remaining gap is structural register/local
// allocation (original 0xC frame, stack-saved this, cached color/draw pointers).
// Main-agent audit retained the natural non-polymorphic sprite/picture-list
// ownership; no codegen-only frame or parameter-mutation probe survives.
// Follow-up bounded pass: a natural saved-self/count/byte-cursor reconstruction
// moved to a 0xC frame only when the proven three-dword local window was modeled
// as a state aggregate; that state reached 287 differing bytes but still missed
// the original saved-self prologue and cached color/draw argument schedule.
// Loop-only color/draw caching and aggregate initialization were codegen
// duplicates. Restored the less opaque natural source; the remaining blocker is
// source/context recovery for the saved-this spill and callee-save argument
// caches, not child-list behavior or call set.
// Worker pass sprite-sa-0aea9221-04f0: retested saved-self/byte-cursor and
// top-level typed-local forms; they stayed structural (287-297 differing
// bytes) and did not reproduce the original self spill. Restored this natural
// canonical source for the documented pause.
// Worker pass sa2229d570_r1_004C04F0: materializing the child facet quotient
// before the draw-level branch moved the source from 298 to 294 differing
// bytes; removing an unsupported inner facet reset then reached exact size and
// 284 differing bytes, proving that the normalized facet remains live through
// the child quotient. A natural saved-self plus call-argument cache form
// reached 271 differing bytes with the same call set and 0x8 frame; a raw
// byte-cursor rewrite and function-scope entry locals were codegen duplicates.
// A diagnostic three-dword state aggregate reproduced the 0xC frame and 60%
// shape similarity at 270 differing bytes but still kept self in EBP; it was
// rejected as an opaque metric-only source. Adding sprite.cpp-era stdio context
// was a duplicate. The clean source below retains named ownership, the
// binary-proven facet lifetime, and ordinary call-argument caches; residual
// drift is the saved-self/callee-save scheduling basin.

#include <stdio.h>

class RGE_Color_Table;
class TDrawArea;
class RGE_Sprite;

class RGE_Picture_List {
public:
    short picture_num;
    char gap_02[2];
    RGE_Sprite* sprite;
    short offset_x;
    short offset_y;
    short facet;
    char gap_0E[2];
};

class RGE_Sprite {
public:
    char pict_name[13];
    char gap_0D[3];
    long resource_id;
    unsigned char loaded;
    char gap_15[3];
    RGE_Color_Table** color_tables;
    void* shape;
    long last_time;
    long delta_time;
    unsigned char color_flag;
    unsigned char draw_level;
    short color_table;
    unsigned char transparent_picking_flag;
    char gap_2D[1];
    short box_x1;
    short box_y1;
    short box_x2;
    short box_y2;
    short draw_list_num;
    RGE_Picture_List* draw_list;
    void* main_sound;
    unsigned char micro_man_sound;
    char gap_41[3];
    void* sound_list;
    char name[21];
    char gap_5D[1];
    short frame_num;
    short facet_num;
    float base_speed;
    float duration;
    float pause_between_loops;
    unsigned char flag;
    char gap_71[1];
    short id;
    unsigned char mirror_flag;
    char gap_75[3];

    void do_draw(long frame, long param_2, long x, long y,
                 RGE_Color_Table* color_table, TDrawArea* draw_area,
                 unsigned char color_index);
    unsigned char draw(long facet, long param_2, long param_3, long param_4,
                       long param_5, long param_6,
                       RGE_Color_Table* color_table, TDrawArea* draw_area,
                       unsigned char color_index);
};

unsigned char RGE_Sprite::draw(long facet, long param_2, long param_3,
                               long param_4, long param_5, long param_6,
                               RGE_Color_Table* color_table,
                               TDrawArea* draw_area,
                               unsigned char color_index)
{
    unsigned char result;
    RGE_Sprite* self = this;
    int count = 0;
    TDrawArea* loop_draw_area;
    RGE_Color_Table* loop_color_table;

    if (facet >= (signed short)self->facet_num) {
        facet = 0;
    }

    if ((self->draw_list_num < 1) || (self->draw_list == 0)) {
        if (self->draw_level < 0xb) {
            param_3 = param_5;
            param_4 = param_6;
        }
        self->do_draw(facet, param_2, param_3, param_4,
                      color_table, draw_area, color_index);
        result = 1;
    }
    else {
        result = 0;
        count = 0;
        if (0 < self->draw_list_num) {
            loop_draw_area = draw_area;
            loop_color_table = color_table;
            do {
                RGE_Picture_List* entry = &self->draw_list[count];
                short entry_facet = entry->facet;
                if ((entry_facet < 0) || (entry_facet == facet)) {
                    RGE_Sprite* sprite = entry->sprite;
                    int child_facet =
                        (sprite->facet_num * facet) /
                        (int)self->facet_num;
                    long offset_y = entry->offset_y;
                    long offset_x;
                    long base_x;
                    if (sprite->draw_level < 0xb) {
                        offset_y = offset_y + param_6;
                        offset_x = entry->offset_x;
                        base_x = param_5;
                    }
                    else {
                        offset_y = offset_y + param_4;
                        offset_x = entry->offset_x;
                        base_x = param_3;
                    }
                    sprite->do_draw(child_facet, param_2,
                                    offset_x + base_x, offset_y,
                                    loop_color_table, loop_draw_area,
                                    color_index);
                }
                count = count + 1;
            } while (count < self->draw_list_num);
            return (unsigned char)count;
        }
    }
    return result;
}
