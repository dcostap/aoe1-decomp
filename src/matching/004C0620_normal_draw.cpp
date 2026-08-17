// VA: 004C0620 RGE_Sprite::normal_draw
// PDB source: sprite.cpp, lines 625-652
// Baseline: canonical RGE_Sprite/RGE_Picture_List ownership with the natural
// draw-list scan and the observed facet-selection/fallback behavior.
// Attempts:
// - parameter-left facet bound plus a nonpositive draw-list guard moved the
//   first mismatch past the entry and preserved the original duplicate checks.
// - typed array access, declaration ordering, and register-hint variants did
//   not change the best emitted basin; raw field-offset cursors were worse.
// - the remaining drift is VC5 register/statement scheduling around the loop
//   setup, child argument evaluation, and fallback result register.
// Corrected the draw-list arm to call sprite->do_draw: original ECX is the
// child sprite, not the parent. This moved the natural typed source from 189
// to 45 differing bytes with matching size/calls; result/count and declaration
// probes did not improve it. Keep the corrected ownership; residual drift is
// the duplicated draw-list guard and VC5 local/register scheduling.
// Main-agent audit confirmed that drawing belongs to each child sprite and
// retained ordinary typed picture-entry indexing.
// Follow-up bounded pass: delayed count initialization, byte result typing,
// a short draw-count local, explicit base-plus-byte-offset entry expressions,
// shared result initialization, and a four-way declaration-order lab all
// preserved or worsened the existing 45-byte basin. The raw cursor version
// also lost the original prologue. Restored this natural typed source; the
// remaining lead is the draw-list-count register/local schedule before the
// otherwise exact child-draw loop.
// Fresh replacement pass: baseline remained 250-byte exact-size with two
// direct do_draw calls and a 45-byte residual beginning at the duplicate
// draw-list count compare. Typed shape/sound fields, complete sibling class
// surfaces, and stdio TU context were codegen-neutral. Dead/shared result
// locals, delayed result assignment, and a binary-supported byte-cursor entry
// probe all broadened structural drift; the canonical typed scan is restored.
// Remaining lead: original reloads draw_list_num into AX while this basin keeps
// it in CX and zeroes EAX for result=0 before the second guard.
// Bounded wave20-sprite-01 pass: moving result=0 before the outer guard produced
// the AX/CX hunk in the wrong direction (60 bytes); direct inner return 0 was
// structural (253 bytes / 181 diff), and an explicit loop-test/body goto was a
// codegen duplicate. Restored the clean typed source after each.
// Parameter-home cursor mutation was also a duplicate. Shared count/result
// probes did reach AX and EBX=1, but retained the wrong two-byte typed entry
// address basin (181 positional bytes); list/cursor and child-before-entry
// variants were structural or broader. An 18-case result/entry/update lab's
// best was the same shared-count basin (173 bytes, edit diff 21), no exact.
// Final validation retains the canonical full RGE_Sprite and typed child
// do_draw ABI; remaining evidence is the localized AX/CX count plus list-entry
// register/address schedule, with no productive source lead left in this pass.
// New bounded pass (sa-26f9ed6b-r1, 10 hypotheses): moving result zeroing
// inside/after the inner positive guard broadened to 189 bytes and 258 bytes;
// one shared count/result (including a diagnostic union) preserved AX and
// EBX=1 but changed the exact child-entry register/address basin to 181 bytes.
// Positive outer guard, narrow result types, reversed initialization order,
// and declaration reordering were duplicate or worse (45/51 bytes). Restored
// the pinned canonical typed source; the remaining gap is the incompatible
// result/count liveness versus ECX/EDX/LEA child-entry schedule.
// Follow-up donor pass (follow-C0620-r1): a byte result initialized before the
// outer guard moved the first mismatch into facet setup and reached 77 bytes;
// rolled back. Reusing the typed facet parameter as the fallback result made
// the function structural (256 bytes, 183 differing bytes); rolled back.
// A function-scope typed child-sprite pointer copied from shadow_draw was
// codegen-identical at 45 bytes; rolled back. The clean typed source remains
// the best reconstruction. The first paired hunk is still result/count
// liveness (AX versus CX), followed by list-base and parameter-home coloring.
// TU-group pass (tu-sprite-C0620): removing the draw-list result zero widened
// the function to 258 bytes and 189 differing bytes. Coalescing fallback and
// scan count reproduced the earlier 181-byte basin. Restored the 45-byte
// canonical typed source; no raw list cursor was retained.
// Shard E bounded pass: count-first/result-from-count, byte/int zero-result
// source order, and chained zero assignment were nonproductive (45-65-byte
// diffs or duplicates). Restored the canonical typed source; the AX/CX
// duplicate-guard register gap remains the only local codegen lead.
// Shard F reassessment: shared count/result with a typed list base duplicated
// the earlier 181-byte basin; child-first typed entry access reached 201 bytes.
// A period-plausible byte cursor with the proven 0x10 stride also reached 201;
// byte-result initialization after facet normalization reached 65. Restored
// the canonical typed source. No new source-backed lead beats the 45-byte
// clean checkpoint; calls, size, frame, and the later draw loop remain aligned.
// Subagent pass (sa-2ad40ec8-r1): 11 focused probes were run against the clean
// 45-byte checkpoint. Direct returns, uninitialized and narrow result locals,
// and register qualification were structural, 50-byte, 187-byte, or duplicate
// basins. Child-first cursor and typed list-base forms were 217-byte and
// 239-byte mismatches. Reversing the duplicate guard was 223 bytes. Sharing
// count with the fallback result reached 181 bytes but changed the entry
// address basin. All probes were restored. The remaining AX/CX count load and
// ECX/EDX/LEA schedule needs new source or compiler-context evidence.
// Revisit pass (sa-9357bf13-r1): one loop index as the return value made the
// function 258 bytes and 201 differing bytes. Delayed fallback zeroing made
// it 256 bytes and 183 differing bytes. Typed entry references, a local list
// alias, repeated typed member access, pointer-plus-index spelling, inner
// index scope, and implicit byte return conversion were duplicate or worse.
// The clean typed source remains the best policy-compliant reconstruction.
// Revisit pass (sa-d0f54e3b-r1): 17 focused probes confirmed the same result.
// A shared count local reaches the original AX/EBX guard basin but changes the
// typed entry address lowering and widens to 181 bytes. Function-scope typed
// pointers, declaration reordering, long indices, and donor-shaped cursor
// forms did not recover the original ECX/EDX/LEA schedule. Byte-result forms
// reached 50-77 bytes or changed control flow. All probes were restored.
// Final validation: 250-byte source, two aligned do_draw calls, 45 differing
// bytes. Keep this natural typed source until new compiler-context evidence.
// Exact policy audit (sa-9e1373e7-r2): one count local carries both the
// fallback result and scan return. Direct typed draw_list[index] access keeps
// the canonical RGE_Picture_List ownership and recovers all 250 bytes.

#include <stdio.h>

class RGE_Color_Table;
class TDrawArea;
class RGE_Sprite;

class TShape {
public:
    char data[0x20];
    TShape(char* filename, long resource_id);
    ~TShape();
};

class RGE_Sound {
public:
    char gap_00[0x0C];
    short id;
};

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

class RGE_Sound_List {
public:
    RGE_Sound* sound[3];
    short frame[3];
    char gap_12[2];
};

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
    float base_speed;
    float duration;
    float pause_between_loops;
    unsigned char flag;
    char gap_71[1];
    short id;
    unsigned char mirror_flag;
    char gap_75[3];

    void do_draw(long param_1, long param_2, long param_3, long param_4,
                 RGE_Color_Table* param_5, TDrawArea* param_6,
                 unsigned char param_7);
    unsigned char normal_draw(long param_1, long param_2, long param_3,
                              long param_4, RGE_Color_Table* param_5,
                              TDrawArea* param_6);
};

unsigned char RGE_Sprite::normal_draw(long param_1, long param_2, long param_3,
                                      long param_4, RGE_Color_Table* param_5,
                                      TDrawArea* param_6)
{
    long facet;
    int index;
    int count;
    facet = param_1;
    if (param_1 >= this->facet_num) {
        facet = 0;
    }

    if ((this->draw_list_num <= 0) || (this->draw_list == 0)) {
        if (this->draw_level == 0x14) {
            this->do_draw(facet, param_2, param_3, param_4, param_5, param_6, 0);
        }
        count = 1;
    }
    else {
        count = 0;
        if (0 < this->draw_list_num) {
            index = 0;
            do {
                RGE_Sprite* sprite = this->draw_list[index].sprite;
                if ((sprite->draw_level == 0x14) &&
                    ((this->draw_list[index].facet < 0) ||
                     (this->draw_list[index].facet == facet))) {
                    sprite->do_draw((sprite->facet_num * facet) / (int)this->facet_num,
                                  param_2,
                                  (long)this->draw_list[index].offset_x + param_3,
                                  (long)this->draw_list[index].offset_y + param_4,
                                  param_5, param_6, 0);
                }
                count = count + 1;
                index = index + 1;
            } while (count < this->draw_list_num);
            return (unsigned char)count;
        }
    }
    return (unsigned char)count;
}
