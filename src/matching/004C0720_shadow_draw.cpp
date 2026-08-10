// VA: 004C0720 RGE_Sprite::shadow_draw
// PDB source: sprite.cpp, lines 656-684
// Baseline: canonical RGE_Sprite/RGE_Picture_List ownership with the natural
// draw-list scan and the observed facet-selection/fallback behavior.
// Attempts:
// - baseline reconstruction from the matching normal_draw sibling: 279 bytes,
//   with the wrong entry cursor and only 64.42% instruction-shape similarity.
// - parameter-left facet guard, <=0 list guard, function-scope count home, and
//   a typed 16-byte byte cursor: 272 bytes and 95.10% shape similarity.
// - raw decompiler-style top-level pointer locals and a named list base made
//   the function 259 bytes; both were rolled back.
// - a small source-shape lab over typed entry/cursor and update spellings found
//   no size-valid or exact variant (8 variants, 272/282-byte groups).
// - loading the child sprite before forming the entry address reproduces the
//   observed child-load-before-LEA topology and reaches 274 bytes / 32 differing
//   bytes. This raw view remains diagnostic only; it proves the 16-byte stride
//   and ordering, while the living source uses a typed pointer walk.
// Corrected the draw-list arm to call sprite->do_draw: original ECX is the
// child sprite, not the parent. The binary-proven int cursor and child-load
// before entry-LEA are retained as a plausible period source shape; reversing
// the natural update statements (count first, then cursor) makes VC5 reload
// draw_list_num after both parameter-home stores and reaches exact bytes.
// Main-agent audit should review the raw 0x10-byte cursor against the original
// source idiom; ownership, stride, call targets, and stack homes are proven.

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
    unsigned char shadow_draw(long param_1, long param_2, long param_3,
                              long param_4, RGE_Color_Table* param_5,
                              TDrawArea* param_6, unsigned char param_7);
};

unsigned char RGE_Sprite::shadow_draw(long param_1, long param_2, long param_3,
                                      long param_4, RGE_Color_Table* param_5,
                                      TDrawArea* param_6, unsigned char param_7)
{
    RGE_Sprite* sprite;
    long facet = param_1;
    int entry_offset;
    if (param_1 >= this->facet_num) {
        facet = 0;
    }

    if ((this->draw_list_num <= 0) || (this->draw_list == 0)) {
        if ((this->draw_level != param_7) && (this->draw_level < 0x14)) {
            this->do_draw(facet, param_2, param_3, param_4, param_5, param_6, 0);
        }
        param_1 = 1;
    }
    else {
        param_1 = 0;
        if (0 < this->draw_list_num) {
            entry_offset = 0;
            do {
                // Preserve the original 16-byte cursor order: VC5 loads the
                // child before materializing the typed entry address.
                sprite = *(RGE_Sprite**)((char*)this->draw_list + entry_offset + 4);
                RGE_Picture_List* entry =
                    (RGE_Picture_List*)((char*)this->draw_list + entry_offset);
                if ((sprite->draw_level != param_7) &&
                    (sprite->draw_level < 0x14) &&
                    ((entry->facet < 0) || (entry->facet == facet))) {
                    sprite->do_draw((sprite->facet_num * facet) /
                                      (int)this->facet_num,
                                  param_2,
                                  (long)entry->offset_x + param_3,
                                  (long)entry->offset_y + param_4,
                                  param_5, param_6, 0);
                }
                param_1++;
                entry_offset = entry_offset + 0x10;
            } while (param_1 < this->draw_list_num);
            return (unsigned char)param_1;
        }
    }
    return (unsigned char)param_1;
}
