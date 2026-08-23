// 00485DC0 RGE_RMM_Object_Generator::generate
// Source: rmm_obj.cpp lines 66-86. 136 bytes. __thiscall, returns uchar in AL.
//
// MATCHED. Exact 136-byte match confirmed via local check_function.py.
// Key: do-while zeroing loop forces LEA before MOV ECX/XOR EAX for rep stosd.

#include "..\..\include\rmm_obj_context.h"

unsigned char RGE_RMM_Object_Generator::generate() {
    if (this->add_terrain != 0) {
        RGE_Game_World* wld = this->world;
        short w = this->map_width;
        short h = this->map_height;
        h--;
        w--;
        this->map->set_terrain(
            *wld->players,
            wld,
            0, 0,
            w, h,
            1, 0, 0
        );
    }

    this->clear_stack();

    long* zero_ptr = (long*)this->terrain_table;
    int zero_cnt = 8;
    do {
        *zero_ptr++ = 0;
        zero_cnt--;
    } while (zero_cnt != 0);

    for (int i = 0; i < this->info.object_num; i++) {
        this->generate_objects(this->info.objects[i]);
    }

    this->map->zone_map_list->delete_zone_maps();

    return 1;
}
