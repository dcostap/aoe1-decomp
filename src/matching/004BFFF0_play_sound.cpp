// VA: 004BFFF0 RGE_Sprite::play_sound
// PDB source: sprite.cpp, lines 396-437
// Baseline: natural typed sound-list traversal reconstructed from the
// executable's three-entry, 0x14-byte facet records.
// Attempt log:
// - Corrected facet_num to +0x60 and reversed the bound spelling for the
//   original parameter-first cmp/JL guard.
// - A +0x0c byte-cursor experiment improved scheduling, but main-agent audit
//   restored ordinary typed facet/frame ownership rather than retain a
//   decompiler-shaped cursor solely for byte metrics.
// - Reversed frame-bound operands to recover the original compare polarity;
//   the cursor experiment's codegen-best remains diagnostic history only.
// - Do-while, facet-local, and declaration-order variants were worse or
//   duplicated. Final normalized typed source is exact-size with 158 differing
//   bytes; recover control-flow/source context without restoring raw cursors.
// This pass retested direct sound_list indexing and a named base pointer; the
// direct form grew to 259 bytes and the base was codegen-neutral. Keep the
// period-plausible typed facet-record traversal; residual drift is structural
// register/liveness coloring in the two three-entry loops.
// Main-agent audit confirmed the 0x14-byte sound-facet record and retained the
// natural bounded array traversal.
// Follow-up baseline: binary frame-offset evidence supports a natural `int`
// byte cursor anchored at the sound-list record base, with both scans written
// as bounded `while (i < 3)` loops. This reconstruction is exact in size,
// CFG, calls, and all but two bytes. Reversing address terms, anchoring through
// the sound array, a loop-local list base, and a four-variant address-shape
// lab all emitted the same two-byte SIB base/index drift; the typed ownership
// and proven cursor remain the living source.
// Fresh replacement pass: the baseline revalidated the two-byte drift. A
// pointer-cast address probe and direct sound-array anchor were codegen-neutral.
// Restoring the complete exact-sibling RGE_Sprite field surface changed the
// second loop's SIB byte to the oracle and left one first-loop byte; completing
// RGE_Sound and changing its trailing padding were neutral. Original-loop and
// function-scope-local experiments broadened drift and were rolled back.
// Best current reconstruction retains the full canonical sprite/sound layout,
// natural bounded scans, and one localized first-loop SIB mismatch.

class RGE_Sound {
public:
    char gap_00[0x0C];
    short id;

    void play(int add_to_list);
};

class RGE_Sound_List {
public:
    RGE_Sound* sound[3];
    short frame[3];
    char gap_12[2];
};

class RGE_Color_Table;
class TShape;
class RGE_Picture_List;

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

    void play_sound(short param_1, short param_2, short param_3);
};

void RGE_Sprite::play_sound(short param_1, short param_2, short param_3) {
    if (param_3 >= this->facet_num) {
        param_3 = 0;
    }

    if (param_1 != param_2) {
        if (this->main_sound != 0 &&
            (param_1 == 0 || (param_2 < param_1 && param_2 != 0))) {
            this->main_sound->play(1);
        }

        if (this->micro_man_sound != 0) {
            if (param_1 < param_2) {
                int i = 0;
                int offset = param_3 * 0x14 + 0x0c;
                while (i < 3) {
                    int frame = *(short *)((char *)this->sound_list->sound + offset);
                    if (frame <= -1) {
                        return;
                    }
                    if (frame >= param_1 && frame < param_2) {
                        this->sound_list[param_3].sound[i]->play(1);
                    }
                    i++;
                    offset += 2;
                }
            } else {
                int i = 0;
                int offset = param_3 * 0x14 + 0x0c;
                while (i < 3) {
                    int frame = *(short *)((char *)this->sound_list->sound + offset);
                    if (frame <= -1) {
                        return;
                    }
                    if (frame >= param_1 || frame < param_2) {
                        this->sound_list[param_3].sound[i]->play(1);
                    }
                    i++;
                    offset += 2;
                }
            }
        }
    }
}
