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
    int result;
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
        result = 1;
    }
    else {
        result = 0;
        count = 0;
        if (0 < this->draw_list_num) {
            index = 0;
            do {
                RGE_Picture_List* entry = &this->draw_list[index];
                RGE_Sprite* sprite = entry->sprite;
                if ((sprite->draw_level == 0x14) &&
                    ((entry->facet < 0) || (entry->facet == facet))) {
                    sprite->do_draw((sprite->facet_num * facet) / (int)this->facet_num,
                                  param_2,
                                  (long)entry->offset_x + param_3,
                                  (long)entry->offset_y + param_4,
                                  param_5, param_6, 0);
                }
                count = count + 1;
                index = index + 1;
            } while (count < this->draw_list_num);
            return (unsigned char)count;
        }
    }
    return result;
}
