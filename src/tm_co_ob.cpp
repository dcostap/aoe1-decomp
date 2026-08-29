
#include "../include/tm_co_ob.h"
#include "../include/t_c_obj.h"
#include "../include/ttsk_lst.h"
#include <new.h>

extern "C" {
    void __cdecl rge_read(int fd, void* data, int size);
    void __cdecl rge_write(int fd, void* data, int size);
}

extern float save_game_version;
extern float DAT_0057677c;

TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(
    TRIBE_Master_Combat_Object* source, int do_setup)
    : RGE_Master_Combat_Object(source, 0) {
    if (do_setup != 0) {
        setup(source);
    }
}

TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(
    int id, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup)
    : RGE_Master_Combat_Object(id, sprites, sounds, 0) {
    if (do_setup != 0) {
        setup(id, sprites, sounds);
    }
}

TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(
    FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short id,
    int do_setup)
    : RGE_Master_Combat_Object(file, sprites, sounds, id, 0) {
    if (do_setup != 0) {
        setup(file, sprites, sounds, id);
    }
}

int TRIBE_Master_Combat_Object::setup(TRIBE_Master_Combat_Object* source) {
    RGE_Master_Combat_Object::setup(source);
    master_type = 0x46;

    int i;
    for (i = 0; i < 3; i++) {
        build_inventory[i] = source->build_inventory[i];
    }

    build_pts_required = source->build_pts_required;
    id_of_building_obj = source->id_of_building_obj;
    button_location = source->button_location;
    orig_pierce_armor = source->orig_pierce_armor;

    return 1;
}

int TRIBE_Master_Combat_Object::setup(int fd, RGE_Sprite** sprites,
                                      RGE_Sound** sounds) {
    int armor_count;
    int left;

    RGE_Master_Combat_Object::setup(fd, sprites, sounds);
    master_type = 0x46;

    Attribute_Cost* cost = build_inventory;
    int remaining = 3;
    do {
        rge_read(fd, cost, 6);
        cost++;
        remaining--;
    } while (remaining != 0);

    rge_read(fd, &build_pts_required, 2);
    rge_read(fd, &id_of_building_obj, 2);
    rge_read(fd, &button_location, 1);

    if (save_game_version >= DAT_0057677c) {
        rge_read(fd, &orig_pierce_armor, 2);
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

int TRIBE_Master_Combat_Object::setup(FILE* file, RGE_Sprite** sprites,
                                      RGE_Sound** sounds, short id) {
    int armor_count;
    int left;

    RGE_Master_Combat_Object::setup(file, sprites, sounds, id);
    master_type = 0x46;

    Attribute_Cost* cost = build_inventory;
    int remaining = 3;
    do {
        fscanf(file, "%hd %hd %hd", &cost->type, &cost->amount, &id);
        cost->flag = (unsigned char)id;
        cost++;
        remaining--;
    } while (remaining != 0);

    // The original uses the unused sounds parameter home for the final scan
    // destination. Keep this store order and width.
    fscanf(file, "%hd %hd %hd", &build_pts_required, &id_of_building_obj,
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

void TRIBE_Master_Combat_Object::modify(float value,
                                        unsigned char attribute) {
    short* type;
    short* types;
    float* current_value;
    float* values;
    int remaining;
    int i;

    switch (attribute) {
    case 'd':
        for (i = 0; i < 3; i++) {
            if (build_inventory[i].flag) {
                build_inventory[i].amount = (short)(int)value;
            }
        }
        break;

    case 'e':
        for (i = 0; i < 3; i++) {
            if (!build_inventory[i].flag) {
                build_inventory[i].amount = (short)(int)(-value);
            }
        }

        values = attribute_amount_held;
        types = attribute_type_held;
        remaining = 3;
        current_value = values;
        type = types;
        do {
            if (*type == 4) {
                *current_value = value;
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
                *current_value = -value;
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
                *current_value = -value;
            }
            type++;
            current_value++;
            remaining--;
        } while (remaining != 0);
        break;

    default:
        RGE_Master_Combat_Object::modify(value, attribute);
        break;
    }
}

void TRIBE_Master_Combat_Object::modify_delta(float value,
                                              unsigned char attribute) {
    if (attribute != 0x64) {
        RGE_Master_Combat_Object::modify_delta(value, attribute);
        return;
    }

    Attribute_Cost* entry = build_inventory;
    int remaining = 3;
    do {
        if (entry->flag != 0) {
            entry->amount = entry->amount + (short)value;
        }
        ++entry;
    } while (--remaining != 0);
}

void TRIBE_Master_Combat_Object::modify_percent(float value,
                                                unsigned char attribute) {
    if (attribute != 0x64) {
        RGE_Master_Combat_Object::modify_percent(value, attribute);
        return;
    }

    Attribute_Cost* entry = build_inventory;
    int remaining = 3;
    do {
        if (entry->flag != 0) {
            entry->amount = (short)((float)entry->amount * value);
        }
        entry++;
        remaining--;
    } while (remaining != 0);
}

void TRIBE_Master_Combat_Object::save(int fd) {
    RGE_Master_Combat_Object::save(fd);

    int i;
    for (i = 0; i < 3; i++) {
        rge_write(fd, &build_inventory[i], 6);
    }

    rge_write(fd, &build_pts_required, 2);
    rge_write(fd, &id_of_building_obj, 2);
    rge_write(fd, &button_location, 1);
    rge_write(fd, &orig_pierce_armor, 2);
}

RGE_Static_Object* TRIBE_Master_Combat_Object::make_new_obj(
    RGE_Player* player, float x, float y, float z) {
    return new TRIBE_Combat_Object(this, player, x, y, z, 1);
}

RGE_Master_Static_Object* TRIBE_Master_Combat_Object::make_new_master() {
    return new TRIBE_Master_Combat_Object(this, 1);
}
