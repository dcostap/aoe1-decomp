// 00463260 sort (125 bytes)
// PDB: obj_list.cpp (RGE_Object_List::sort)
// STATUS: STUCK — register allocation (EBX↔EBP) swap.
//
// Original uses EBX for source iterator (pRVar3), rebuilt uses EBP.
// This swaps push ebx/push ebp in the prologue and affects every register
// encoding throughout. Isolated TU cannot reproduce original's register
// allocation. 72% positional diff, 35.2% edit diff. Not accepted_drift.

#include <stdlib.h>

class RGE_Master_Static_Object {
public:
    void* vtable_ptr;
    unsigned char master_type;
    unsigned char _pad_0[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char _pad_1[2];
    void* sprite;
    void* death_sprite;
    void* undead_sprite;
    unsigned char undead_flag;
    unsigned char _pad_2;
    short hp;
    float los;
    unsigned char obj_max;
    unsigned char _pad_3[3];
    float radius_x;
    float radius_y;
    float radius_z;
    void* selected_sound;
    void* created_sound;
    void* death_sound;
    short death_spawn_obj_id;
    unsigned char sort_number;
    unsigned char can_be_built_on;
    short button_pict;
    unsigned char hide_in_scenario_editor;
    unsigned char _pad_4;
    short portrait_pict;
    unsigned char available;
    unsigned char _pad_5;
    short tile_req1;
    short tile_req2;
    short center_tile_req1;
    short center_tile_req2;
    float construction_radius_x;
    float construction_radius_y;
    unsigned char elevation_flag;
    unsigned char fog_flag;
    short terrain;
    unsigned char movement_type;
    unsigned char _pad_6;
    short attribute_type_held[3];
    float attribute_amount_held[3];
    short attribute_max_amount;
    unsigned char _pad_7[2];
    float attribute_rot;
    float multiple_attribute_mod;
    unsigned char attribute_flag[3];
    unsigned char area_effect_object_level;
    unsigned char combat_level;
    unsigned char select_level;
    unsigned char map_draw_level;
    unsigned char unit_level;
    unsigned char map_color;
    unsigned char attack_reaction;
    unsigned char convert_terrain_flag;
    unsigned char damage_sprite_num;
    void* damage_sprites;
    long help_string_id;
    long help_page_id;
    long hotkey_id;
    unsigned char recyclable;
    unsigned char track_as_resource;
    unsigned char create_doppleganger_on_death;
    unsigned char resource_group;
    unsigned char draw_flag;
    unsigned char draw_color;
    unsigned char _pad_8[2];
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    int id;
    RGE_Master_Static_Object* master_obj;
    void* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    void* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
};

struct RGE_Object_Node {
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    unsigned char centered;
    unsigned char _pad_end[3];
};

class RGE_Object_List {
public:
    void* vtable;
    RGE_Object_Node* list;
    short number_of_objects;
    unsigned char _pad_end[2];

    RGE_Object_Node* sort();
};

RGE_Object_Node* RGE_Object_List::sort()
{
    RGE_Object_Node* pRVar3;
    RGE_Object_Node* sorted;
    RGE_Object_Node** ppRVar4;
    RGE_Object_Node* pRVar5;

    sorted = 0;
    pRVar3 = this->list;
    if (pRVar3 == 0) {
        return 0;
    }

    do {
        ppRVar4 = &sorted;
        unsigned char bVar1 = pRVar3->node->master_obj->sort_number;
        for (pRVar5 = sorted; pRVar5 != 0; pRVar5 = pRVar5->next) {
            unsigned char bVar2 = pRVar5->node->master_obj->sort_number;
            if ((bVar2 < bVar1) ||
                (bVar2 == bVar1 && pRVar3->node->screen_y_offset < pRVar5->node->screen_y_offset)) {
                break;
            }
            ppRVar4 = &pRVar5->next;
        }

        pRVar5 = (RGE_Object_Node*)calloc(1, 0x10);
        pRVar5->next = *ppRVar4;
        if (*ppRVar4 != 0) {
            pRVar5->prev = (*ppRVar4)->prev;
            (*ppRVar4)->prev = pRVar5;
        }
        pRVar5->node = pRVar3->node;
        *ppRVar4 = pRVar5;

        pRVar3 = pRVar3->next;
    } while (pRVar3 != 0);

    return sorted;
}
