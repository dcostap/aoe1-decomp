// VA: 004521E0 setup (755B)
// m_s_obj.cpp
// RGE_Master_Static_Object::setup

class RGE_Sprite;
class RGE_Sound;

class RGE_Damage_Sprite_Info {
public:
    RGE_Sprite* sprite;
    unsigned char damage_percent;
    unsigned char flag;
};

void __cdecl free(void* block);
void* __cdecl calloc(unsigned int count, unsigned int size);
void __cdecl getstring(char** dest, char* src);

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;  // +0x4
    char pad_05[0x3];
    char* name;                 // +0x8
    short string_id;            // +0xC
    short string_id2;           // +0xE
    short id;                   // +0x10
    short copy_id;              // +0x12
    short object_group;         // +0x14
    char pad_16[0x2];
    RGE_Sprite* sprite;         // +0x18
    RGE_Sprite* death_sprite;   // +0x1C
    RGE_Sprite* undead_sprite;  // +0x20
    unsigned char undead_flag;  // +0x24
    char pad_25[0x1];
    short hp;                   // +0x26
    float los;                  // +0x28
    unsigned char obj_max;      // +0x2C
    char pad_2D[0x3];
    float radius_x;             // +0x30
    float radius_y;             // +0x34
    float radius_z;             // +0x38
    RGE_Sound* selected_sound;  // +0x3C
    RGE_Sound* created_sound;   // +0x40
    RGE_Sound* death_sound;     // +0x44
    short death_spawn_obj_id;   // +0x48
    unsigned char sort_number;  // +0x4A
    unsigned char can_be_built_on; // +0x4B
    short button_pict;          // +0x4C
    unsigned char hide_in_scenario_editor; // +0x4E
    char pad_4F[0x1];
    short portrait_pict;        // +0x50
    unsigned char available;    // +0x52
    char pad_53[0x1];
    short tile_req1;            // +0x54
    short tile_req2;            // +0x56
    short center_tile_req1;     // +0x58
    short center_tile_req2;     // +0x5A
    float construction_radius_x; // +0x5C
    float construction_radius_y; // +0x60
    unsigned char elevation_flag; // +0x64
    unsigned char fog_flag;     // +0x65
    short terrain;              // +0x66
    unsigned char movement_type; // +0x68
    char pad_69[0x1];
    short attribute_type_held[3]; // +0x6A
    float attribute_amount_held[3]; // +0x70
    short attribute_max_amount; // +0x7C
    char pad_7E[0x2];
    float attribute_rot;       // +0x80
    float multiple_attribute_mod; // +0x84
    unsigned char attribute_flag[3]; // +0x88
    unsigned char area_effect_object_level; // +0x8B
    unsigned char combat_level; // +0x8C
    unsigned char select_level; // +0x8D
    unsigned char map_draw_level; // +0x8E
    unsigned char unit_level;   // +0x8F
    unsigned char map_color;    // +0x90
    unsigned char attack_reaction; // +0x91
    unsigned char convert_terrain_flag; // +0x92
    unsigned char damage_sprite_num; // +0x93
    RGE_Damage_Sprite_Info* damage_sprites; // +0x94
    long help_string_id;       // +0x98
    long help_page_id;         // +0x9C
    long hotkey_id;            // +0xA0
    unsigned char recyclable;  // +0xA4
    unsigned char track_as_resource; // +0xA5
    unsigned char create_doppleganger_on_death; // +0xA6
    unsigned char resource_group; // +0xA7
    unsigned char draw_flag;   // +0xA8
    unsigned char draw_color;  // +0xA9
    char pad_AA[0x2];
    float outline_radius_x;   // +0xAC
    float outline_radius_y;   // +0xB0
    float outline_radius_z;   // +0xB4

    int setup(RGE_Master_Static_Object* src);
};

int RGE_Master_Static_Object::setup(RGE_Master_Static_Object* src) {
    master_type = 0x0A;
    recyclable = src->recyclable;
    string_id = src->string_id;
    string_id2 = src->string_id2;
    id = src->id;
    copy_id = id;
    object_group = src->object_group;
    sprite = src->sprite;
    death_sprite = src->death_sprite;
    undead_sprite = src->undead_sprite;
    undead_flag = src->undead_flag;
    hp = src->hp;
    los = src->los;
    obj_max = src->obj_max;
    radius_x = src->radius_x;
    radius_y = src->radius_y;
    radius_z = src->radius_z;
    created_sound = src->created_sound;
    death_spawn_obj_id = src->death_spawn_obj_id;
    sort_number = src->sort_number;
    can_be_built_on = src->can_be_built_on;
    button_pict = src->button_pict;
    hide_in_scenario_editor = src->hide_in_scenario_editor;
    portrait_pict = src->portrait_pict;
    available = src->available;
    tile_req1 = src->tile_req1;
    tile_req2 = src->tile_req2;
    center_tile_req1 = src->center_tile_req1;
    center_tile_req2 = src->center_tile_req2;
    construction_radius_x = src->construction_radius_x;
    construction_radius_y = src->construction_radius_y;
    elevation_flag = src->elevation_flag;
    fog_flag = src->fog_flag;
    terrain = src->terrain;
    movement_type = src->movement_type;
    attribute_max_amount = src->attribute_max_amount;
    attribute_rot = src->attribute_rot;
    area_effect_object_level = src->area_effect_object_level;
    combat_level = src->combat_level;
    select_level = src->select_level;
    map_draw_level = src->map_draw_level;
    unit_level = src->unit_level;
    multiple_attribute_mod = src->multiple_attribute_mod;
    selected_sound = src->selected_sound;
    death_sound = src->death_sound;
    attack_reaction = src->attack_reaction;
    convert_terrain_flag = src->convert_terrain_flag;
    map_color = src->map_color;
    help_string_id = src->help_string_id;
    help_page_id = src->help_page_id;
    hotkey_id = src->hotkey_id;
    track_as_resource = src->track_as_resource;
    create_doppleganger_on_death = src->create_doppleganger_on_death;
    resource_group = src->resource_group;
    draw_flag = src->draw_flag;
    draw_color = src->draw_color;
    outline_radius_x = src->outline_radius_x;
    outline_radius_y = src->outline_radius_y;
    outline_radius_z = src->outline_radius_z;

    {
        unsigned char* fp = attribute_flag;
        float* ap = attribute_amount_held;
        short* tp = attribute_type_held;
        int diff = (int)src - (int)(RGE_Master_Static_Object*)this;
        int cnt = 3;
        do {
            *tp = *(short*)((int)tp + diff);
            *ap = *(float*)((int)ap + diff);
            *fp = *(unsigned char*)((int)fp + diff);
            tp++;
            ap++;
            fp++;
            cnt--;
        } while (cnt != 0);
    }

    {
        damage_sprite_num = src->damage_sprite_num;
        if (damage_sprite_num > 0) {
            damage_sprites = (RGE_Damage_Sprite_Info*)calloc(damage_sprite_num, 8);
            short i = 0;
            if (damage_sprite_num > 0) {
                do {
                    damage_sprites[i].sprite = src->damage_sprites[i].sprite;
                    damage_sprites[i].damage_percent = src->damage_sprites[i].damage_percent;
                    damage_sprites[i].flag = src->damage_sprites[i].flag;
                    i++;
                } while (i < (short)damage_sprite_num);
            }
        } else {
            damage_sprites = 0;
        }
    }

    name = 0;
    getstring(&name, src->name);
    return 1;
}
