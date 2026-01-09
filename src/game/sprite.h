#pragma once
#include "common.h"

class RGE_Sprite {
public:
    char pict_name[13];                      // 0x0
    long resource_id;                        // 0x10
    uchar loaded;                            // 0x14
    RGE_Color_Table** color_tables;          // 0x18
    TShape* shape;                           // 0x1C
    long last_time;                          // 0x20
    long delta_time;                         // 0x24
    uchar color_flag;                        // 0x28
    uchar draw_level;                        // 0x29
    short color_table;                       // 0x2A
    uchar transparent_picking_flag;          // 0x2C
    short box_x1;                            // 0x2E
    short box_y1;                            // 0x30
    short box_x2;                            // 0x32
    short box_y2;                            // 0x34
    short draw_list_num;                     // 0x36
    RGE_Picture_List* draw_list;             // 0x38
    RGE_Sound* main_sound;                   // 0x3C
    uchar micro_man_sound;                   // 0x40
    RGE_Sound_List* sound_list;              // 0x44
    char name[21];                           // 0x48
    short frame_num;                         // 0x5E
    short facet_num;                         // 0x60
    float base_speed;                        // 0x64
    float duration;                          // 0x68
    float pause_between_loops;               // 0x6C
    uchar flag;                              // 0x70
    short id;                                // 0x72
    uchar mirror_flag;                       // 0x74

    RGE_Sprite(short param_1);
    RGE_Sprite(int param_1, RGE_Sound** param_2, RGE_Color_Table** param_3);
    RGE_Sprite(_iobuf* param_1, short param_2, RGE_Sound** param_3);
    ~RGE_Sprite();
    void rehook(RGE_Sprite** param_1);
    void save(int param_1);
    void load_facets(RGE_Sprite** param_1);
    void play_sound(short param_1, short param_2, short param_3);
    uchar get_facetindex(long param_1, long param_2, long* param_3);
    void do_draw(long param_1, long param_2, long param_3, long param_4, RGE_Color_Table* param_5, TDrawArea* param_6, uchar param_7);
    uchar draw(long param_1, long param_2, long param_3, long param_4, long param_5, long param_6, RGE_Color_Table* param_7, TDrawArea* param_8, uchar param_9);
    uchar normal_draw(long param_1, long param_2, long param_3, long param_4, RGE_Color_Table* param_5, TDrawArea* param_6);
    uchar shadow_draw(long param_1, long param_2, long param_3, long param_4, RGE_Color_Table* param_5, TDrawArea* param_6, uchar param_7);
    int get_size(long* param_1, long* param_2, long* param_3, long* param_4, long param_5);
    int get_frame(short* param_1, short* param_2, short* param_3, short* param_4, long param_5, long param_6);
    int get_frame_min_max(short* param_1, short* param_2, short* param_3, short* param_4, long param_5, long param_6, short param_7, short param_8);
    uchar get_lowest_draw_level();
    uchar hit_test(short param_1, short param_2, long param_3, long param_4);
    uchar shape_hit_test(short param_1, short param_2, long param_3, long param_4);
    RGE_Active_Sprite* make_active_sprite();
    int check_for_shadows();
    void update(ulong param_1);
};

static_assert(sizeof(RGE_Sprite) == 0x78, "RGE_Sprite Size Mismatch");

