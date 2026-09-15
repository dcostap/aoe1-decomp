
#include "../include/tm_co_ob.h"
#include "../include/t_c_obj.h"
#include "../include/ttsk_lst.h"
#include <new.h>

#include "../include/rge_fio.h"

extern float save_game_version;
extern float DAT_0057677c;

TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(
    TRIBE_Master_Combat_Object* other_object, int do_setup)
    : RGE_Master_Combat_Object(other_object, 0) {
    if (do_setup != 0) {
        setup(other_object);
    }
}

TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(
    int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup)
    : RGE_Master_Combat_Object(infile, sprites, sounds, 0) {
    if (do_setup != 0) {
        setup(infile, sprites, sounds);
    }
}

TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(
    FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id,
    int do_setup)
    : RGE_Master_Combat_Object(infile, sprites, sounds, in_id, 0) {
    if (do_setup != 0) {
        setup(infile, sprites, sounds, in_id);
    }
}

int TRIBE_Master_Combat_Object::setup(TRIBE_Master_Combat_Object* other_object) {
    RGE_Master_Combat_Object::setup(other_object);
    master_type = 0x46;

    int i;
    for (i = 0; i < 3; i++) {
        build_inventory[i] = other_object->build_inventory[i];
    }

    build_pts_required = other_object->build_pts_required;
    id_of_building_obj = other_object->id_of_building_obj;
    button_location = other_object->button_location;
    orig_pierce_armor = other_object->orig_pierce_armor;

    return 1;
}

int TRIBE_Master_Combat_Object::setup(int infile, RGE_Sprite** sprites,
                                      RGE_Sound** sounds) {
    int armor_count;
    int left;

    RGE_Master_Combat_Object::setup(infile, sprites, sounds);
    master_type = 0x46;

    Attribute_Cost* cost = build_inventory;
    int remaining = 3;
    do {
        rge_read(infile, cost, 6);
        cost++;
        remaining--;
    } while (remaining != 0);

    rge_read(infile, &build_pts_required, 2);
    rge_read(infile, &id_of_building_obj, 2);
    rge_read(infile, &button_location, 1);

    if (save_game_version >= DAT_0057677c) {
        rge_read(infile, &orig_pierce_armor, 2);
        return 1;
    }

    armor_count = (int)armor_num;
    orig_pierce_armor = 0;
    if (armor_count > 0) {
        RGE_Armor_Weapon_Info* entry = armor;
        left = armor_count;
        do {
            if (entry->type == 3 && entry->value > orig_pierce_armor) {
                orig_pierce_armor = entry->value;
            }
            entry++;
            left--;
        } while (left != 0);
    }

    orig_armor = (unsigned char)base_armor;
    if (armor_count > 0) {
        RGE_Armor_Weapon_Info* entry = armor;
        while (armor_count != 0) {
            if (entry->type != 3 && entry->value > orig_armor) {
                orig_armor = entry->value;
            }
            entry++;
            armor_count--;
        }
    }

    return 1;
}

int TRIBE_Master_Combat_Object::setup(FILE* infile, RGE_Sprite** sprites,
                                      RGE_Sound** sounds, short in_id) {
    int armor_count;
    int left;

    RGE_Master_Combat_Object::setup(infile, sprites, sounds, in_id);
    master_type = 0x46;

    Attribute_Cost* cost = build_inventory;
    int remaining = 3;
    do {
        fscanf(infile, "%hd %hd %hd", &cost->type, &cost->amount, &in_id);
        cost->flag = (unsigned char)in_id;
        cost++;
        remaining--;
    } while (remaining != 0);

    // The original uses the unused sounds parameter home for the final scan
    // destination. Keep this store order and width.
    fscanf(infile, "%hd %hd %hd", &build_pts_required, &id_of_building_obj,
           &sounds);

    armor_count = (int)armor_num;
    button_location = (unsigned char)sounds;
    orig_pierce_armor = 0;
    if (armor_count > 0) {
        RGE_Armor_Weapon_Info* entry = armor;
        left = armor_count;
        do {
            if (entry->type == 3 && entry->value > orig_pierce_armor) {
                orig_pierce_armor = entry->value;
            }
            entry++;
            left--;
        } while (left != 0);
    }

    orig_armor = (unsigned char)base_armor;
    if (armor_count > 0) {
        RGE_Armor_Weapon_Info* entry = armor;
        while (armor_count != 0) {
            if (entry->type != 3 && entry->value > orig_armor) {
                orig_armor = entry->value;
            }
            entry++;
            armor_count--;
        }
    }

    return 1;
}

TRIBE_Master_Combat_Object::~TRIBE_Master_Combat_Object() {
}

RGE_Task_List* TRIBE_Master_Combat_Object::create_task_list() {
    return new TRIBE_Task_List();
}

void TRIBE_Master_Combat_Object::copy_obj(RGE_Master_Static_Object* source) {
    RGE_Master_Combat_Object::copy_obj(source);

    TRIBE_Master_Combat_Object* tribe_source =
        (TRIBE_Master_Combat_Object*)source;
    int i;
    for (i = 0; i < 3; i++) {
        build_inventory[i] = tribe_source->build_inventory[i];
    }

    build_pts_required = tribe_source->build_pts_required;
    id_of_building_obj = tribe_source->id_of_building_obj;
    button_location = tribe_source->button_location;
    orig_pierce_armor = tribe_source->orig_pierce_armor;
}

void TRIBE_Master_Combat_Object::modify(float amount,
                                        unsigned char flag) {
    short* type;
    short* types;
    float* current_value;
    float* values;
    int remaining;
    int i;

    switch (flag) {
    case 'd':
        for (i = 0; i < 3; i++) {
            if (build_inventory[i].flag) {
                build_inventory[i].amount = (short)(int)amount;
            }
        }
        break;

    case 'e':
        for (i = 0; i < 3; i++) {
            if (!build_inventory[i].flag) {
                build_inventory[i].amount = (short)(int)(-amount);
            }
        }

        values = attribute_amount_held;
        types = attribute_type_held;
        remaining = 3;
        current_value = values;
        type = types;
        do {
            if (*type == 4) {
                *current_value = amount;
            }
            type++;
            current_value++;
            remaining--;
        } while (remaining != 0);

        remaining = 3;
        current_value = values;
        type = types;
        do {
            if (*type == 0x0B) {
                *current_value = -amount;
            }
            type++;
            current_value++;
            remaining--;
        } while (remaining != 0);

        remaining = 3;
        current_value = values;
        type = types;
        do {
            if (*type == 0x13) {
                *current_value = -amount;
            }
            type++;
            current_value++;
            remaining--;
        } while (remaining != 0);
        break;

    default:
        RGE_Master_Combat_Object::modify(amount, flag);
        break;
    }
}

void TRIBE_Master_Combat_Object::modify_delta(float amount,
                                              unsigned char flag) {
    if (flag != 0x64) {
        RGE_Master_Combat_Object::modify_delta(amount, flag);
        return;
    }

    Attribute_Cost* entry = build_inventory;
    int remaining = 3;
    do {
        if (entry->flag != 0) {
            entry->amount = entry->amount + (short)amount;
        }
        ++entry;
    } while (--remaining != 0);
}

void TRIBE_Master_Combat_Object::modify_percent(float amount,
                                                unsigned char flag) {
    if (flag != 0x64) {
        RGE_Master_Combat_Object::modify_percent(amount, flag);
        return;
    }

    Attribute_Cost* entry = build_inventory;
    int remaining = 3;
    do {
        if (entry->flag != 0) {
            entry->amount = (short)((float)entry->amount * amount);
        }
        entry++;
        remaining--;
    } while (remaining != 0);
}

void TRIBE_Master_Combat_Object::save(int outfile) {
    RGE_Master_Combat_Object::save(outfile);

    int i;
    for (i = 0; i < 3; i++) {
        rge_write(outfile, &build_inventory[i], 6);
    }

    rge_write(outfile, &build_pts_required, 2);
    rge_write(outfile, &id_of_building_obj, 2);
    rge_write(outfile, &button_location, 1);
    rge_write(outfile, &orig_pierce_armor, 2);
}

RGE_Static_Object* TRIBE_Master_Combat_Object::make_new_obj(
    RGE_Player* owner, float x, float y, float z) {
    return new TRIBE_Combat_Object(this, owner, x, y, z, 1);
}

RGE_Master_Static_Object* TRIBE_Master_Combat_Object::make_new_master() {
    return new TRIBE_Master_Combat_Object(this, 1);
}
