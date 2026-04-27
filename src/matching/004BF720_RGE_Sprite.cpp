// 004BF720 RGE_Sprite::RGE_Sprite
// Source: sprite.cpp lines 42-72
// public: __thiscall RGE_Sprite::RGE_Sprite(short)
//
// Attempt log:
// Probe 1: natural member-init constructor, default flags,
//   field stores in the asm-observed order

#include "..\..\include\game_globals.h"

// RGE_Sprite size 0x78 (from inventory types dump)
class RGE_Sprite {
public:
    char pict_name[13];              // +0x0 (0xD)
    // gap 3 bytes
    long resource_id;                // +0x10 (4)
    unsigned char loaded;            // +0x14 (1)
    // gap 3 bytes
    RGE_Color_Table** color_tables;  // +0x18 (4)
    TShape* shape;                   // +0x1C (4)
    long last_time;                  // +0x20 (4)
    long delta_time;                 // +0x24 (4)
    unsigned char color_flag;        // +0x28 (1)
    unsigned char draw_level;        // +0x29 (1)
    short color_table;               // +0x2A (2)
    unsigned char transparent_picking_flag; // +0x2C (1)
    // pad 1 byte
    short box_x1;                    // +0x2E (2)
    short box_y1;                    // +0x30 (2)
    short box_x2;                    // +0x32 (2)
    short box_y2;                    // +0x34 (2)
    short draw_list_num;             // +0x36 (2)
    RGE_Picture_List* draw_list;     // +0x38 (4)
    RGE_Sound* main_sound;           // +0x3C (4)
    unsigned char micro_man_sound;   // +0x40 (1)
    // gap 3 bytes
    RGE_Sound_List* sound_list;      // +0x44 (4)
    char name[21];                   // +0x48 (0x15)
    // gap 1 byte
    short frame_num;                 // +0x5E (2)
    short facet_num;                 // +0x60 (2)
    // gap 2 bytes
    float base_speed;                // +0x64 (4)
    float duration;                  // +0x68 (4)
    float pause_between_loops;       // +0x6C (4)
    unsigned char flag;              // +0x70 (1)
    // gap 1 byte
    short id;                        // +0x72 (2)
    unsigned char mirror_flag;       // +0x74 (1)
    // pad 3 bytes

    RGE_Sprite(short id);
};

RGE_Sprite::RGE_Sprite(short id)
{
    this->color_tables = 0;
    this->id = id;
    this->last_time = 0;
    this->delta_time = 0;
    this->name[0] = 0;
    this->pict_name[0] = 0;
    this->resource_id = 0;
    this->frame_num = 0;
    this->facet_num = 0;
    this->color_table = 0;
    this->box_x1 = 0;
    this->box_y1 = 0;
    this->box_x2 = 0;
    this->box_y2 = 0;
    this->base_speed = 0.0f;
    this->duration = 0.0f;
    this->pause_between_loops = 0.0f;
    this->draw_list_num = 0;
    this->loaded = 0;
    this->shape = 0;
    this->main_sound = 0;
    this->mirror_flag = 0;
    this->color_flag = 0;
    this->draw_level = 0;
    this->transparent_picking_flag = 0;
    this->micro_man_sound = 0;
    this->flag = 0;
    this->draw_list = 0;
    this->sound_list = 0;
}
