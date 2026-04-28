// 00463100 shadow_draw (123 bytes) — MATCHED
// PDB: obj_list.cpp (RGE_Object_List::shadow_draw)
//
// Key to match:
// - RGE_Static_Object: 4 dummy virtuals before shadow_draw to get vtable slot 4 (0x10)
// - RGE_Master_Static_Object: vtable_ptr at +0, fog_flag at +0x65
// - Fog logic: if(fog) check master_obj->fog_flag before calling node->shadow_draw

class TDrawArea;

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
    virtual void _virt0();
    virtual void _virt1();
    virtual void _virt2();
    virtual void _virt3();
    virtual void shadow_draw(TDrawArea* draw_area, short x, short y, unsigned char param_4);

    int id;
    RGE_Master_Static_Object* master_obj;
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

    void shadow_draw(TDrawArea* draw_area, short x, short y, unsigned char param_4, unsigned char fog);
};

void RGE_Object_List::shadow_draw(TDrawArea* draw_area, short x, short y, unsigned char param_4, unsigned char fog)
{
    RGE_Object_Node* p = this->list;

    if (fog) {
        while (p) {
            RGE_Static_Object* obj = p->node;
            if (obj) {
                if (obj->master_obj->fog_flag) {
                    obj->shadow_draw(draw_area, x, y, param_4);
                }
            }
            p = p->next;
        }
    } else {
        while (p) {
            RGE_Static_Object* obj = p->node;
            if (obj) {
                obj->shadow_draw(draw_area, x, y, param_4);
            }
            p = p->next;
        }
    }
}
