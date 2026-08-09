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

class RGE_Sound {
public:
    void play(int add_to_list);
};

class RGE_Sound_List {
public:
    RGE_Sound* sound[3];
    short frame[3];
    short gap_12;
};

class RGE_Sprite {
public:
    char gap_00[0x3C];
    RGE_Sound* main_sound;
    unsigned char micro_man_sound;
    char gap_41[3];
    RGE_Sound_List* sound_list;
    char gap_48[0x18];
    short facet_num;

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
                RGE_Sound_List* facet = &this->sound_list[param_3];
                int i = 0;
                while (1) {
                    int frame = facet->frame[i];
                    if (frame <= -1) {
                        break;
                    }
                    if (frame >= param_1 && frame < param_2) {
                        facet->sound[i]->play(1);
                    }
                    i++;
                    if (2 < i) {
                        return;
                    }
                }
            } else {
                RGE_Sound_List* facet = &this->sound_list[param_3];
                int i = 0;
                do {
                    int frame = facet->frame[i];
                    if (frame <= -1) {
                        return;
                    }
                    if (frame >= param_1 || frame < param_2) {
                        facet->sound[i]->play(1);
                    }
                    i++;
                } while (i < 3);
            }
        }
    }
}
