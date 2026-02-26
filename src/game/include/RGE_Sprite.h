#pragma once
#include "common.h"

class RGE_Sound;
class RGE_Color_Table;
class TShape;
class RGE_Active_Sprite;

struct RGE_Picture_List {
    short picture_num; // 0x0
    short _pad0;      // 0x2
    class RGE_Sprite* sprite; // 0x4
    short offset_x;    // 0x8
    short offset_y;    // 0xA
    short facet;       // 0xC
    short _pad1;      // 0xE
};

struct RGE_Sound_List {
    RGE_Sound* sound[3]; // 0x0 - 0xB
    short frame[3];      // 0xC - 0x11
    short _pad;          // 0x12 - 0x13
};

class RGE_Sprite {
public:
    RGE_Sprite(short id);
    RGE_Sprite(FILE* infile, short id, RGE_Sound** sounds);
    RGE_Sprite(int fd, RGE_Sound** sounds, RGE_Color_Table** color_tables);
    ~RGE_Sprite();

    // Field order and padding checked against ASM offsets
    char pict_name[13];       // 0x0
    unsigned char _pad0[3];   // 0xD
    int resource_id;         // 0x10
    char loaded;             // 0x14
    unsigned char _pad1[3];   // 0x15
    RGE_Color_Table** color_tables; // 0x18
    TShape* shape;           // 0x1C
    long last_time;          // 0x20
    long delta_time;         // 0x24
    char color_flag;         // 0x28
    char draw_level;         // 0x29
    short color_table;       // 0x2A
    char transparent_picking_flag; // 0x2C
    char _pad2;              // 0x2D
    short box_x1, box_y1, box_x2, box_y2; // 0x2E, 0x30, 0x32, 0x34
    short draw_list_num;     // 0x36
    RGE_Picture_List* draw_list; // 0x38
    RGE_Sound* main_sound;   // 0x3C
    char micro_man_sound;    // 0x40
    unsigned char _pad3[3];   // 0x41
    RGE_Sound_List* sound_list; // 0x44
    char name[21];           // 0x48
    char _pad4;              // 0x5D
    short frame_num;         // 0x5E
    short facet_num;         // 0x60
    unsigned char _pad5[2];   // 0x62
    float base_speed;        // 0x64
    float duration;          // 0x68
    float pause_between_loops; // 0x6C
    char flag;               // 0x70
    char _pad6;              // 0x71
    short id;                // 0x72
    char mirror_flag;        // 0x74
    unsigned char _pad7[3];   // 0x75 (align to 0x78)

    // Methods
    void rehook(RGE_Sprite** sprites);
    void load_facets(RGE_Sprite** sprites);
    void update(ulong param_1);
    void save(int param_1);
    void play_sound(short param_1, short param_2, short param_3);
    unsigned char get_facetindex(long param_1, long param_2, long* param_3);
    void do_draw(long param_1, long param_2, long param_3, long param_4, RGE_Color_Table* param_5, TDrawArea* param_6, unsigned char param_7);
    unsigned char draw(long param_1, long param_2, long param_3, long param_4, long param_5, long param_6, RGE_Color_Table* param_7, TDrawArea* param_8, unsigned char param_9);
    unsigned char normal_draw(long param_1, long param_2, long param_3, long param_4, RGE_Color_Table* param_5, TDrawArea* param_6);
    unsigned char shadow_draw(long param_1, long param_2, long param_3, long param_4, RGE_Color_Table* param_5, TDrawArea* param_6, unsigned char param_7);
    int get_size(long* param_1, long* param_2, long* param_3, long* param_4, long param_5);
    int get_frame(short* param_1, short* param_2, short* param_3, short* param_4, long param_5, long param_6);
    int get_frame_min_max(short* param_1, short* param_2, short* param_3, short* param_4, long param_5, long param_6, short param_7, short param_8);
    unsigned char get_lowest_draw_level();
    RGE_Active_Sprite* make_active_sprite();
    int check_for_shadows();
};
static_assert(sizeof(RGE_Sprite) == 0x78, "Size mismatch: RGE_Sprite");
