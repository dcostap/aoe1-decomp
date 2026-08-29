#include "../include/tech.h"
#include "../include/effects.h"
#include "../include/t_histry.h"
#include "../include/tplayer.h"
#include "../include/tworld.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4035 4805)

extern float save_game_version;
extern double DAT_005766d8;

void __cdecl getstring(char** destination, char* source);
void __cdecl rge_read(int file, void* data, int size);
void __cdecl rge_write(int file, void* data, int size);

// Contribution: 0050B840-0050D456.

TRIBE_Tech::TRIBE_Tech(int file, TRIBE_World* world_arg)
{
    short i;

    this->world = world_arg;
    rge_read(file, &this->tech_tree_num, 2);
    if (this->tech_tree_num > 0) {
        this->tech_tree = (Tech_Tree*)calloc(0x3c, this->tech_tree_num);
        for (i = 0; i < this->tech_tree_num; i++) {
            short j;
            for (j = 0; j < 4; j++) {
                rge_read(file, &this->tech_tree[i].pre_reqs[j], 2);
            }
            for (j = 0; j < 3; j++) {
                rge_read(file, &this->tech_tree[i].attribute[j], 2);
                rge_read(file, &this->tech_tree[i].attribute_cost[j], 2);
                rge_read(file, &this->tech_tree[i].attribute_used[j], 1);
            }
            rge_read(file, &this->tech_tree[i].pre_reqs_required, 2);
            rge_read(file, &this->tech_tree[i].build_obj_id, 2);
            rge_read(file, &this->tech_tree[i].string_id, 2);
            rge_read(file, &this->tech_tree[i].string_id2, 2);
            rge_read(file, &this->tech_tree[i].research, 2);
            rge_read(file, &this->tech_tree[i].effect, 2);
            rge_read(file, &this->tech_tree[i].track, 2);
            rge_read(file, &this->tech_tree[i].icon, 2);
            rge_read(file, &this->tech_tree[i].button_location, 1);
            rge_read(file, &this->tech_tree[i].help_string_id, 4);
            rge_read(file, &this->tech_tree[i].help_page_id, 4);
            rge_read(file, &this->tech_tree[i].hotkey_id, 4);

            short name_len;
            rge_read(file, &name_len, 2);
            if (name_len > 0) {
                this->tech_tree[i].name = (char*)calloc(1, name_len);
                rge_read(file, this->tech_tree[i].name, name_len);
            } else {
                this->tech_tree[i].name = 0;
            }
        }
    } else {
        this->tech_tree = 0;
    }
}

TRIBE_Tech::TRIBE_Tech(char* filename)
{
    FILE* file;
    unsigned char button_temp;
    int k;
    int used_read;
    short file_count;
    int len;

    this->tech_tree = 0;
    file = fopen(filename, "r");
    if (file != 0) {
        if (fscanf(file, "%d %d", &this->tech_tree_num, &file_count) != -1) {
            if (this->tech_tree_num > 0) {
                char name_buf[0x64];
                short i;
                this->tech_tree = (Tech_Tree*)calloc(0x3c, this->tech_tree_num);
                for (i = 0; i < file_count; i++) {
                    short j;
                    short tech_id;

                    fscanf(file, "%hd", &j);
                    fscanf(file, "%s %hd %hd %hd %hd %hd %hd %hd",
                           name_buf,
                           &this->tech_tree[j].pre_reqs_required,
                           &this->tech_tree[j].research,
                           &this->tech_tree[j].effect,
                           &this->tech_tree[j].track,
                           &this->tech_tree[j].icon,
                           &button_temp,
                           &this->tech_tree[j].build_obj_id);
                    this->tech_tree[j].button_location = button_temp;
                    used_read = strlen(name_buf);
                    for (k = 0; k < used_read; k++) {
                        if (name_buf[k] == '_') {
                            name_buf[k] = ' ';
                        }
                    }
                    this->tech_tree[j].name = 0;
                    getstring(&this->tech_tree[j].name, name_buf);
                    for (tech_id = 0; tech_id < 4; tech_id++) {
                        fscanf(file, "%hd", &this->tech_tree[j].pre_reqs[tech_id]);
                    }
                    for (tech_id = 0; tech_id < 3; tech_id++) {
                        fscanf(file, "%hd %hd %hd",
                               &this->tech_tree[j].attribute[tech_id],
                               &this->tech_tree[j].attribute_cost[tech_id],
                               &len);
                        this->tech_tree[j].attribute_used[tech_id] =
                            (unsigned char)len;
                    }
                    fscanf(file, "%hd %hd %ld %ld %ld",
                           &this->tech_tree[j].string_id,
                           &this->tech_tree[j].string_id2,
                           &this->tech_tree[j].help_string_id,
                           &this->tech_tree[j].help_page_id,
                           &this->tech_tree[j].hotkey_id);
                }
            }
        }
        fclose(file);
    }
}

TRIBE_Tech::~TRIBE_Tech()
{
    int i;

    if (this->tech_tree) {
        for (i = 0; i < this->tech_tree_num; i++) {
            if (this->tech_tree[i].name) {
                free(this->tech_tree[i].name);
            }
        }
        free(this->tech_tree);
        this->tech_tree = 0;
    }
}

unsigned char TRIBE_Tech::do_tech(short tech_id, RGE_Player* player)
{
    if (this->tech_tree[tech_id].effect >= 0) {
        this->world->effects->do_effect(this->tech_tree[tech_id].effect, player);
    }
    return 1;
}

void TRIBE_Tech::save(int file)
{
    short i;

    rge_write(file, &this->tech_tree_num, 2);
    for (i = 0; i < this->tech_tree_num; i++) {
        short name_len;
        if (this->tech_tree[i].name != 0) {
            name_len = (short)(strlen(this->tech_tree[i].name) + 1);
        } else {
            name_len = 0;
        }
        {
            short j;
            for (j = 0; j < 4; j++) {
                rge_write(file, &this->tech_tree[i].pre_reqs[j], 2);
            }
            for (j = 0; j < 3; j++) {
                rge_write(file, &this->tech_tree[i].attribute[j], 2);
                rge_write(file, &this->tech_tree[i].attribute_cost[j], 2);
                rge_write(file, &this->tech_tree[i].attribute_used[j], 1);
            }
        }
        rge_write(file, &this->tech_tree[i].pre_reqs_required, 2);
        rge_write(file, &this->tech_tree[i].build_obj_id, 2);
        rge_write(file, &this->tech_tree[i].string_id, 2);
        rge_write(file, &this->tech_tree[i].string_id2, 2);
        rge_write(file, &this->tech_tree[i].research, 2);
        rge_write(file, &this->tech_tree[i].effect, 2);
        rge_write(file, &this->tech_tree[i].track, 2);
        rge_write(file, &this->tech_tree[i].icon, 2);
        rge_write(file, &this->tech_tree[i].button_location, 1);
        rge_write(file, &this->tech_tree[i].help_string_id, 4);
        rge_write(file, &this->tech_tree[i].help_page_id, 4);
        rge_write(file, &this->tech_tree[i].hotkey_id, 4);
        rge_write(file, &name_len, 2);
        if (name_len > 0) {
            rge_write(file, this->tech_tree[i].name, name_len);
        }
    }
}

long TRIBE_Tech::get_help_message(short tech_id)
{
    // The executable accepts tech_tree_num as an index.
    if (tech_id < 0 || tech_id > this->tech_tree_num) {
        return -1;
    }
    return this->tech_tree[tech_id].help_string_id;
}

long TRIBE_Tech::get_help_page(short tech_id)
{
    // The executable accepts tech_tree_num as an index.
    if (tech_id < 0 || tech_id > this->tech_tree_num) {
        return -1;
    }
    return this->tech_tree[tech_id].help_page_id;
}

long TRIBE_Tech::get_hotkey(short tech_id)
{
    // The executable accepts tech_tree_num as an index.
    if (tech_id < 0 || tech_id > this->tech_tree_num) {
        return -1;
    }
    return this->tech_tree[tech_id].hotkey_id;
}

TRIBE_Player_Tech::TRIBE_Player_Tech(int file, TRIBE_Tech* tech,
                                     RGE_Player* player, unsigned char load)
{
    short i;

    rge_read(file, &this->tech_player_tree_num, 2);
    this->base_tech = tech;
    this->owner = player;
    if (0 < this->tech_player_tree_num) {
        this->tech_player_tree =
            (Tech_Player_Tree*)calloc(8, this->tech_player_tree_num);

        for (i = 0; i < this->tech_player_tree_num; i++) {
            if (save_game_version <= 7.03f) {
                rge_read(file, &this->tech_player_tree[i], 2);
            } else {
                rge_read(file, &this->tech_player_tree[i], 4);
            }
            rge_read(file, &this->tech_player_tree[i].state, 2);
        }
        if (load) {
            for (i = 0; i < this->tech_player_tree_num; i++) {
                if (this->tech_player_tree[i].state == 3) {
                    this->tech_player_tree[i].state = 1;
                    do_tech(i);
                }
            }
            check_for_new_tech();
        }
    }
}

TRIBE_Player_Tech::TRIBE_Player_Tech(TRIBE_Tech* tech, RGE_Player* player,
                                     unsigned char load)
{
    this->base_tech = tech;
    this->owner = player;
    this->tech_player_tree_num = tech->tech_tree_num;
    if (0 < this->tech_player_tree_num) {
        this->tech_player_tree =
            (Tech_Player_Tree*)calloc(8, this->tech_player_tree_num);
    }
    if (load) {
        check_for_new_tech();
    }
}

TRIBE_Player_Tech::~TRIBE_Player_Tech()
{
    if (this->tech_player_tree) {
        free(this->tech_player_tree);
        this->tech_player_tree = 0;
    }
}

short TRIBE_Player_Tech::get_tech_state(short tech_id)
{
    return this->tech_player_tree[tech_id].state;
}

unsigned char TRIBE_Player_Tech::undo_tech(short tech_id)
{
    if (this->tech_player_tree[tech_id].state >= 1) {
        this->tech_player_tree[tech_id].state = 0;
        check_for_new_tech();
        return 1;
    }
    return 0;
}

unsigned char TRIBE_Player_Tech::do_tech(short tech_id)
{
    if (this->tech_player_tree[tech_id].state < 3 &&
        this->tech_player_tree[tech_id].state > -1) {
        this->tech_player_tree[tech_id].state = 3;
        this->base_tech->do_tech(tech_id, this->owner);
        check_for_new_tech();
        if (tech_id == 0x65) {
            ((TRIBE_Player*)this->owner)->history->add_history_event(0);
        } else if (tech_id == 0x66) {
            ((TRIBE_Player*)this->owner)->history->add_history_event(1);
        } else if (tech_id == 0x67) {
            ((TRIBE_Player*)this->owner)->history->add_history_event(2);
        }
        return 1;
    }
    return 0;
}

unsigned char TRIBE_Player_Tech::research(short tech_id, float amount)
{
    if (this->tech_player_tree[tech_id].state == 2) {
        this->tech_player_tree[tech_id].research_done += amount;
        if (!(this->tech_player_tree[tech_id].research_done <
              (float)(int)this->base_tech->tech_tree[tech_id].research)) {
            do_tech(tech_id);
            return 0;
        }
        return 1;
    }
    return 0;
}

void TRIBE_Player_Tech::tech_cost(short tech_id, short* attr1, short* cost1,
                                  short* attr2, short* cost2, short* attr3,
                                  short* cost3)
{
    Tech_Tree* tech;
    short total;
    unsigned char can_use_carry;

    tech = this->base_tech->tech_tree + tech_id;
    total = 0;
    *attr1 = -1;
    *cost1 = 0;
    *attr2 = -1;
    *cost2 = 0;
    *attr3 = -1;
    *cost3 = 0;

    can_use_carry = this->check_tech_cost(tech_id, 0);
    if (this->owner->attributes[0x1d] < 1.0f) {
        can_use_carry = 0;
    }

    if (tech->attribute_used[0] != 0) {
        *attr1 = tech->attribute[0];
        if (*attr1 >= 0) {
            *cost1 = tech->attribute_cost[0];
            if (this->owner->attributes[*attr1] < (float)(int)*cost1 &&
                can_use_carry) {
                total += (short)(*cost1 -
                    (short)this->owner->attributes[*attr1]);
                *cost1 = (short)this->owner->attributes[*attr1];
            }
        }
    }

    if (tech->attribute_used[1] != 0) {
        *attr2 = tech->attribute[1];
        if (*attr2 >= 0) {
            *cost2 = tech->attribute_cost[1];
            if (this->owner->attributes[*attr2] < (float)(int)*cost2 &&
                can_use_carry) {
                total += (short)(*cost2 -
                    (short)this->owner->attributes[*attr2]);
                *cost2 = (short)this->owner->attributes[*attr2];
            }
        }
    }

    if (tech->attribute_used[2] != 0) {
        *attr3 = tech->attribute[2];
        if (*attr3 >= 0) {
            *cost3 = tech->attribute_cost[2];
            if (this->owner->attributes[*attr3] < (float)(int)*cost3 &&
                can_use_carry) {
                total += (short)(*cost3 -
                    (short)this->owner->attributes[*attr3]);
                *cost3 = (short)this->owner->attributes[*attr3];
            }
        }
    }

    if (total > 0) {
        if (*attr1 == 3 || *attr1 == -1) {
            *attr1 = 3;
            *cost1 += total;
        } else if (*attr2 == 3 || *attr2 == -1) {
            *attr2 = 3;
            *cost2 += total;
        } else if (*attr3 == 3 || *attr3 == -1) {
            *attr3 = 3;
            *cost3 = total;
        }
    }

    if (*cost1 <= 0) {
        *attr1 = -1;
    }
    if (*cost2 <= 0) {
        *attr2 = -1;
    }
    if (*cost3 <= 0) {
        *attr3 = -1;
    }
}

unsigned char TRIBE_Player_Tech::check_tech_cost(short tech_id,
                                                  short* missing_attribute)
{
    int i;
    int attribute;
    Tech_Tree* tech;
    float carry;
    float cost;
    unsigned char has_carry;

    tech = this->base_tech->tech_tree + tech_id;
    carry = this->owner->attributes[3];

    if (this->owner->attributes[0x1d] < 1.0f) {
        carry = 0.0f;
        has_carry = 0;
    } else {
        has_carry = 1;
    }
    if (this->tech_player_tree[tech_id].state == 1) {
        for (i = 0; i < 3; i++) {
            attribute = tech->attribute[i];
            if (attribute >= 0 && tech->attribute_used[i] != 0) {
                cost = (float)(int)tech->attribute_cost[i];
                if (has_carry && attribute == 3) {
                    carry = carry - cost;
                    if (carry < 0.0f) {
                        if (missing_attribute) {
                            *missing_attribute = (short)attribute;
                        }
                        return 0;
                    }
                }
                if (this->owner->attributes[attribute] < cost) {
                    if (carry + this->owner->attributes[attribute] < cost) {
                        if (missing_attribute) {
                            *missing_attribute = (short)attribute;
                        }
                        return 0;
                    }
                    carry = carry -
                        (cost - this->owner->attributes[attribute]);
                }
            }
        }
        return 1;
    }
    if (missing_attribute) {
        *missing_attribute = -1;
    }
    return 0;
}

unsigned char TRIBE_Player_Tech::start_research(short tech_id,
                                                unsigned char charge,
                                                short* missing_attribute)
{
    Tech_Tree* tech;
    int i;
    float cost;
    int attribute;

    tech = this->base_tech->tech_tree + tech_id;
    if (this->check_tech_cost(tech_id, missing_attribute)) {
        if (charge) {
            for (i = 0; i < 3; i++) {
                attribute = tech->attribute[i];
                if (attribute >= 0 && tech->attribute_used[i] != 0) {
                    cost = (float)(int)tech->attribute_cost[i];
                    if (this->owner->attributes[attribute] < cost) {
                        this->owner->attributes[3] =
                            this->owner->attributes[3] -
                            (cost - this->owner->attributes[attribute]);
                        this->owner->attributes[attribute] = 0.0f;
                    } else {
                        this->owner->attributes[attribute] =
                            this->owner->attributes[attribute] - cost;
                    }
                }
            }
            this->tech_player_tree[tech_id].state = 2;
        }
        return 1;
    }
    if (missing_attribute) {
        *missing_attribute = -1;
    }
    return 0;
}

unsigned char TRIBE_Player_Tech::cancel_research(short tech_id,
                                                 unsigned char refund)
{
    Tech_Tree* tech;
    short i;

    tech = this->base_tech->tech_tree + tech_id;
    if (this->tech_player_tree[tech_id].state == 2) {
        if (refund) {
            for (i = 0; i < 3; i++) {
                if (tech->attribute[i] >= 0 && tech->attribute_used[i] != 0) {
                    this->owner->attributes[tech->attribute[i]] =
                        this->owner->attributes[tech->attribute[i]] +
                        (float)(int)tech->attribute_cost[i];
                }
            }
        }
        this->tech_player_tree[tech_id].state = 1;
        this->tech_player_tree[tech_id].research_done = 0.0f;
        return 1;
    }
    return 0;
}

unsigned char TRIBE_Player_Tech::check_for_new_tech()
{
    Tech_Tree* tech;
    short i;
    short j;
    unsigned char prereq_done;
    short prereq_count;
    short active_count;
    unsigned char changed;

    active_count = 0;
    tech = this->base_tech->tech_tree;
    do {
        // The executable clears changed and never sets it.
        changed = 0;
        for (i = 0; i < this->tech_player_tree_num; i++) {
            if (this->tech_player_tree[i].state < 2 &&
                this->tech_player_tree[i].state > -1) {
                active_count++;
                prereq_done = 0;
                prereq_count = 0;
                for (j = 0; j < 4; j++) {
                    if (tech[i].pre_reqs[j] >= 0) {
                        prereq_count++;
                        if (this->tech_player_tree[tech[i].pre_reqs[j]].state == 3) {
                            prereq_done++;
                        }
                    }
                }
                if (prereq_done >= tech[i].pre_reqs_required) {
                    if ((float)(int)tech[i].research <=
                        this->tech_player_tree[i].research_done) {
                        do_tech(i);
                        active_count--;
                    } else if (this->tech_player_tree[i].state < 1) {
                        this->tech_player_tree[i].state = 1;
                    }
                } else if (this->tech_player_tree[i].state > 0) {
                    this->tech_player_tree[i].state = 0;
                }
            } else if (this->tech_player_tree[i].state == 2) {
                active_count++;
            }
        }
    } while (changed);
    if (active_count == 0 && this->owner->attributes[0x27] == DAT_005766d8) {
        this->owner->attributes[0x27] = 1.0f;
    }
    return 1;
}

void TRIBE_Player_Tech::save(int file)
{
    rge_write(file, &this->tech_player_tree_num, 2);
    for (short i = 0; i < this->tech_player_tree_num; i++) {
        rge_write(file, &this->tech_player_tree[i], 4);
        rge_write(file, &this->tech_player_tree[i].state, 2);
    }
}

short TRIBE_Player_Tech::get_progress(short tech_id)
{
    short progress;

    if (this->tech_player_tree[tech_id].state == 2) {
        progress = (short)(long)(this->tech_player_tree[tech_id].research_done *
            100.0f / (float)(int)this->base_tech->tech_tree[tech_id].research);
    } else if (this->tech_player_tree[tech_id].state == 3) {
        progress = 100;
    } else {
        progress = 0;
    }
    return progress;
}

char* TRIBE_Player_Tech::get_name(short tech_id)
{
    return this->base_tech->tech_tree[tech_id].name;
}

short TRIBE_Player_Tech::get_string_id(short tech_id)
{
    return this->base_tech->tech_tree[tech_id].string_id;
}

short TRIBE_Player_Tech::get_string_id2(short tech_id)
{
    return this->base_tech->tech_tree[tech_id].string_id2;
}

unsigned char TRIBE_Player_Tech::get_button_location(short tech_id)
{
    return this->base_tech->tech_tree[tech_id].button_location;
}

void TRIBE_Player_Tech::do_rev_tech(short tech_id)
{
    int i;
    int tech;

    for (i = 0; i < 4; i++) {
        tech = this->base_tech->tech_tree[tech_id].pre_reqs[i];
        if (tech >= 0 && this->tech_player_tree[tech].state < 3) {
            if (this->tech_player_tree[tech].state >= 0) {
                this->do_rev_tech((short)tech);
            }
        }
    }
    this->do_tech(tech_id);
}

unsigned char TRIBE_Player_Tech::rev_tech(short tech_id)
{
    int i;
    int j;

    this->do_tech(tech_id);
    for (i = 0; i < this->tech_player_tree_num; i++) {
        for (j = 0; j < 4; j++) {
            if (this->base_tech->tech_tree[i].pre_reqs[j] == tech_id) {
                this->do_rev_tech((short)i);
            }
        }
    }
    return 1;
}

void TRIBE_Player_Tech::disable(short tech_id)
{
    int i;

    if (tech_id < 0) {
        for (i = 0; i < this->tech_player_tree_num; i++) {
            if (this->tech_player_tree[i].state != 3) {
                this->tech_player_tree[i].state = -1;
            }
        }
    } else if (this->tech_player_tree[tech_id].state != 3) {
        this->tech_player_tree[tech_id].state = -1;
    }
}

void TRIBE_Player_Tech::enable(short tech_id)
{
    int i;

    if (tech_id < 0) {
        for (i = 0; i < this->tech_player_tree_num; i++) {
            if (this->tech_player_tree[i].state == -1) {
                this->tech_player_tree[i].state = 0;
            }
        }
    } else if (this->tech_player_tree[tech_id].state == -1) {
        this->tech_player_tree[tech_id].state = 0;
    }
}

long TRIBE_Player_Tech::get_help_message(short tech_id)
{
    return this->base_tech->get_help_message(tech_id);
}

long TRIBE_Player_Tech::get_help_page(short tech_id)
{
    return this->base_tech->get_help_page(tech_id);
}

long TRIBE_Player_Tech::get_hotkey(short tech_id)
{
    return this->base_tech->get_hotkey(tech_id);
}
