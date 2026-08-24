// VA: 0050EE80 TRIBE_Master_Combat_Object::modify
// PDB source: tm_co_ob.cpp
// Attempt log:
// - pre-claim state: if-form, 224/233 (9 short), 22.7% shape, wrong base-modify symbol
// - h1 baseline (CURRENT, clean pin): switch-form dispatch (sub eax,64h/je/dec/je chain,
//   matching the base RGE_Master_Combat_Object::modify style), real virtual class surface
//   so default call has true ?modify@RGE_Master_Combat_Object@@UAEXME@Z symbol, loop counter
//   hoisted out of the switch (VC5 C2360/C2374). Result: 233/233 size, calls 100% aligned,
//   shape 95.51%, exact-block 88.64%, edit diff 16.31%. First strict mismatch +0015
//   (je displacement: rebuilt 'e' body 2 bytes short).
// Remaining drift (EXACT CODEGEN stage, all in 'e' pts loops 2-4):
//   - original keeps bases in callee-saved esi(int@0x70)/edi(short@0x6A, this mutated via
//     add edi,6Ah), reloads BOTH working ptrs (ecx/eax) + counter edx at each loop start;
//     param_1 bits loaded at use inside loop2 (mov ebx,[esp+10h] after cmp/jne).
//   - rebuilt hoists bases to ebx/eax, hoists param_1 into edi before loop2, and loop4
//     reuses eax as short ptr (2 bytes shorter setup) -> shifts 'd' handler up 2 bytes.
// - h2 do/while pointer scans plus the canonical inherited attribute arrays: 103/233.
//   Resetting the cursor locals for the third scan restored the original block
//   topology (6 bytes left: cursor-reset move order only).
// - h3 swapped each reset to assign the value cursor before the type cursor: exact 233/233.
//   The module wrapper uses the natural member assignment. The remaining reload
//   difference is observed codegen drift, not a source-level volatility contract.

#ifndef TM_CO_OB_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual void _virt0();
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

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    void* move_sprite;
    void* run_sprite;
    float turn_speed;
    unsigned char size_class;
    unsigned char _pad_9;
    short obj_trail_id;
    unsigned char obj_trail_options;
    unsigned char _pad_10[3];
    float obj_trail_spacing;
    unsigned char move_algorithem;
    unsigned char _pad_11[3];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    void* tasks;
    short default_task;
    unsigned char _pad_12[2];
    float search_radius;
    float work_rate;
    short drop_site;
    short backup_drop_site;
    unsigned char task_by_group;
    unsigned char _pad_13[3];
    void* command_sound;
    void* move_sound;
    unsigned char run_pattern;
    unsigned char _pad_14[3];
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    void* fight_sprite;
    unsigned char base_armor;
    unsigned char _pad_15;
    short armor_num;
    void* armor;
    short weapon_num;
    unsigned char _pad_16[2];
    void* weapon;
    short defense_terrain_bonus;
    unsigned char _pad_17[2];
    float weapon_range;
    float area_effect_range;
    unsigned char area_effect_level;
    unsigned char _pad_18[3];
    float speed_of_attack;
    short missile_id;
    short base_hit_chance;
    unsigned char break_off_combat;
    unsigned char _pad_19;
    short fire_missile_at_frame;
    float weapon_offset_x;
    float weapon_offset_y;
    float weapon_offset_z;
    float minimum_weapon_range;
    short orig_armor;
    short orig_weapon;
    float orig_weapon_range;
    float orig_speed_of_attack;

    virtual void modify(float param_1, unsigned char param_2);
};

class Attribute_Cost {
public:
    short type;
    short amount;
    unsigned char flag;
    unsigned char _pad_end;
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    Attribute_Cost build_inventory[3];
    short build_pts_required;
    short id_of_building_obj;
    unsigned char button_location;
    unsigned char _pad_20;
    short orig_pierce_armor;
    unsigned char _pad_end[2];

    void modify(float param_1, unsigned char param_2);
};
#endif

void TRIBE_Master_Combat_Object::modify(float param_1, unsigned char param_2)
{
    short* type;
    short* types;
    float* value;
    float* values;
    int remaining;
    int i;
    switch (param_2) {
    case 'd':
        for (i = 0; i < 3; i++) {
            if (build_inventory[i].flag)
                build_inventory[i].amount = (short)(int)param_1;
        }
        break;
    case 'e':
        for (i = 0; i < 3; i++) {
            if (!build_inventory[i].flag)
                build_inventory[i].amount = (short)(int)(-param_1);
        }
        values = attribute_amount_held;
        types = attribute_type_held;
        remaining = 3;
        value = values;
        type = types;
        do {
            if (*type == 4)
                *(float*)value = param_1;
            type++;
            value++;
            remaining--;
        } while (remaining != 0);
        remaining = 3;
        value = values;
        type = types;
        do {
            if (*type == 0x0B)
                *(float*)value = -param_1;
            type++;
            value++;
            remaining--;
        } while (remaining != 0);
        remaining = 3;
        value = values;
        type = types;
        do {
            if (*type == 0x13)
                *(float*)value = -param_1;
            type++;
            value++;
            remaining--;
        } while (remaining != 0);
        break;
    default:
        RGE_Master_Combat_Object::modify(param_1, param_2);
        break;
    }
}
