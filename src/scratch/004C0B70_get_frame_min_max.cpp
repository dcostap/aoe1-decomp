// VA: 004C0B70 RGE_Sprite::get_frame_min_max
// PDB source: sprite.cpp, lines 763-803
// Attempt log:
// - Natural baseline matched size/frame/calls but used the opposite compare
//   operand order and kept the facet result byte-sized (167 differing bytes).
// - Reversed the equivalent frame bound and kept the facet result in an int;
//   this recovered the original compare, mask, call setup, and all four
//   return/update block shapes (110 differing bytes, exact size/frame/calls).
// - Reused formal frame/facet values, full donor-proven RGE_Sprite layout,
//   declaration-order, explicit adjusted-bound, and compound-assignment
//   variants; all emitted the same 110-byte basin or were worse. A six-case
//   variant lab likewise found one emitted group and no exact result.
// Fresh pass orch-luna-4c0b70-w3: decompiler local declaration/type ordering,
// canonical helper parameter ownership, separate swap temp, long accumulators,
// implicit short stores, unqualified member idioms, and an explicit swap goto
// were checked; all either duplicated the 110-byte basin or worsened it.
// A 64-case source-shape lab found no exact result (best diagnostic arm-only
// spelling was 108 bytes); VC5 /GX/alias/inline/debug flag-context probes were
// unchanged. Calls, frame, size, and prefix remain exact; first mismatch is
// the facet-swap block at +005F, with residual register/liveness drift after
// the second call.
// This pass also tested widened/reused coordinate temporaries and commutative
// x-bound spellings; the emitted basin stayed at 110 bytes. The natural result
// temporary remains the clean source; the remaining gap is the post-call
// frame/facet register assignment and branch span.
// Final clean source: retain the natural formal-parameter/temporary form;
// remaining drift is VC5 register/liveness coloring after the second call.
// Main-agent audit confirmed the canonical non-polymorphic 0x78-byte sprite
// surface and retained named frame-bound ownership.
// Worker pass sprite-sa-0aea9221: arm-local x bounds plus value-first upper
// bound predicates reached 108 differing bytes and 78.05% exact-block coverage;
// long x locals and reversed temporary assignment were neutral/worse. Restored
// the canonical formal-output source; remaining gap is the swap register basin.
// Fresh orch-sprite-01 probe 1: mutate the formal frame/facet and output values
// directly through the final bounds, removing the diagnostic x/y result locals;
// this tests the natural original source ownership rather than their scheduling.
// It reached 39 differing bytes, 95.12% shape, and 75.61% exact-block coverage
// with exact size/frame/calls; the first mismatch moved to +006D (swap register).
// Plain swap-first, reversed negative-swap, copy-then-negate, and temp-width or
// scope changes were neutral/worse (45 to 111 differing bytes); do not repeat.
// A focused 24-case direct-arm/update-order lab found no exact or invariant-valid
// variant. Register-qualified facet, unqualified same-class idioms, and reordered
// facet declaration all duplicated the 39-byte emitted basin.
// Final clean source for orch-sprite-01: retain direct formal frame/facet and
// get_size-output accumulation; remaining drift is the ESI/EBX post-call coloring
// and the resulting four bound-update encodings, not behavior/calls/layout.

class RGE_Color_Table;
class TShape;
class RGE_Picture_List;
class RGE_Sound;
class RGE_Sound_List;

class RGE_Sprite {
public:
    char pict_name[13];
    char gap_0D[3];
    long resource_id;
    unsigned char loaded;
    char gap_15[3];
    RGE_Color_Table** color_tables;
    TShape* shape;
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
    RGE_Sound* main_sound;
    unsigned char micro_man_sound;
    char gap_41[3];
    RGE_Sound_List* sound_list;
    char name[21];
    char gap_5D[1];
    short frame_num;
    short facet_num;
    char gap_62[2];
    float base_speed;
    float duration;
    float pause_between_loops;
    unsigned char flag;
    char gap_71[1];
    short id;
    unsigned char mirror_flag;
    char gap_75[3];

    unsigned char get_facetindex(long frame, long facet, long& frame_out);
    int get_size(long& min_x, long& max_y, long& max_x, long& max_y2,
                 long facet);
    int get_frame_min_max(short& min_x, short& min_y, short& max_x,
                          short& max_y, long frame, long facet,
                          short offset_x, short offset_y);
};

int RGE_Sprite::get_frame_min_max(short& min_x, short& min_y, short& max_x,
                                  short& max_y, long frame, long facet,
                                  short offset_x, short offset_y) {
    int facet_index;
    long frame_index = facet;
    long calc_min_y;
    long calc_max_y;
    long local_4;

    if (facet >= frame_num) {
        frame_index = 0;
    }

    facet_index = get_facetindex(frame, frame_index, calc_min_y);
    if (get_size(frame, calc_max_y, facet, local_4, calc_min_y) == 0) {
        return 0;
    }

    if (facet_index != 0) {
        int swap_temp;
        swap_temp = -frame;
        frame = -facet;
        facet = swap_temp;
    }

    frame += offset_x;
    facet += offset_x;
    calc_max_y += offset_y;
    local_4 += offset_y;

    if (frame < min_x) {
        min_x = (short)frame;
    }
    if (calc_max_y < min_y) {
        min_y = (short)calc_max_y;
    }
    if (max_x < facet) {
        max_x = (short)facet;
    }
    if (max_y < local_4) {
        max_y = (short)local_4;
    }
    return 1;
}
