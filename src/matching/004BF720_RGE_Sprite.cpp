// 004BF720 RGE_Sprite::RGE_Sprite
// Source: sprite.cpp lines 42-72
// public: __thiscall RGE_Sprite::RGE_Sprite(short)
//
// Attempt log:
// Probe 1: natural member-init constructor, default flags,
//   field stores in the asm-observed order

#include "..\..\include\sprite_context.h"

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
    this->flags = 0;
    this->draw_list = 0;
    this->sound_list = 0;
}
