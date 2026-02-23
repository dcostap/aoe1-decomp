#include "../include/TRIBE_Tech.h"
#include "../include/TRIBE_World.h"
#include "../include/RGE_Effects.h"
#include "../include/mystring.h"
#include "../include/custom_debug.h"
#include "../include/globals.h"
#include <string.h>

// Source of truth: bucket_050B.cpp.decomp
// Constructor (int, TRIBE_World*): reads tech tree from binary data via rge_read.
// Constructor (char*): reads tech tree from text file via fscanf.
// Both are data-loading constructors that require the game database.

TRIBE_Tech::TRIBE_Tech(int param_1, TRIBE_World* param_2) {
    // Source of truth: bucket_050B.cpp.decomp @ 0x0050B840
    this->world = param_2;
    rge_read(param_1, &this->tech_tree_num, 2);
    if (this->tech_tree_num < 1 || this->tech_tree_num > 4096) {
        CUSTOM_DEBUG_LOG_FMT(
            "TRIBE_Tech::TRIBE_Tech(binary): rejecting tech_tree_num=%d (fd=%d)",
            (int)this->tech_tree_num,
            param_1);
        this->tech_tree_num = 0;
        this->tech_tree = nullptr;
    } else {
        this->tech_tree = (Tech_Tree*)calloc(0x3c, (int)this->tech_tree_num);
        for (short i = 0; i < this->tech_tree_num; i++) {
            // Read pre-requisites
            for (short j = 0; j < 4; j++) {
                rge_read(param_1, &this->tech_tree[i].pre_reqs[j], 2);
            }
            // Read cost attributes (3 sets)
            for (short j = 0; j < 3; j++) {
                rge_read(param_1, &this->tech_tree[i].attribute[j], 2);
                rge_read(param_1, &this->tech_tree[i].attribute_cost[j], 2);
                rge_read(param_1, &this->tech_tree[i].attribute_used[j], 1);
            }
            rge_read(param_1, &this->tech_tree[i].pre_reqs_required, 2);
            rge_read(param_1, &this->tech_tree[i].build_obj_id, 2);
            rge_read(param_1, &this->tech_tree[i].string_id, 2);
            rge_read(param_1, &this->tech_tree[i].string_id2, 2);
            rge_read(param_1, &this->tech_tree[i].research, 2);
            rge_read(param_1, &this->tech_tree[i].effect, 2);
            rge_read(param_1, &this->tech_tree[i].track, 2);
            rge_read(param_1, &this->tech_tree[i].icon, 2);
            rge_read(param_1, &this->tech_tree[i].button_location, 1);
            rge_read(param_1, &this->tech_tree[i].help_string_id, 4);
            rge_read(param_1, &this->tech_tree[i].help_page_id, 4);
            rge_read(param_1, &this->tech_tree[i].hotkey_id, 4);
            // Read name
            short name_len = 0;
            rge_read(param_1, &name_len, 2);
            if (name_len < 1 || name_len > 4096) {
                this->tech_tree[i].name = nullptr;
            } else {
                this->tech_tree[i].name = (char*)calloc(1, (int)name_len);
                rge_read(param_1, this->tech_tree[i].name, (int)name_len);
            }
        }
    }
}

TRIBE_Tech::TRIBE_Tech(char* param_1) {
    // Fully verified. Source of truth: bucket_050B.decomp @ 0x0050BB84
    this->tech_tree = (Tech_Tree*)0x0;

    FILE* local_1c = fopen(param_1, "r");
    if (local_1c != nullptr) {
        int tech_tree_num_tmp = 0;
        int entry_count_tmp = 0;
        int iVar1 = fscanf(local_1c, "%d %d", &tech_tree_num_tmp, &entry_count_tmp);
        this->tech_tree_num = (short)tech_tree_num_tmp;
        short local_c0 = (short)entry_count_tmp;

        if ((iVar1 != -1) && (0 < this->tech_tree_num)) {
            this->tech_tree = (Tech_Tree*)calloc(0x3c, (int)this->tech_tree_num);
            for (short local_20 = 0; local_20 < local_c0; local_20 = (short)(local_20 + 1)) {
                short local_8c0 = 0;
                fscanf(local_1c, "%hd", &local_8c0);

                char local_84[100];
                short button_location_tmp = 0;
                fscanf(local_1c,
                       "%s %hd %hd %hd %hd %hd %hd %hd",
                       local_84,
                       &this->tech_tree[local_8c0].pre_reqs_required,
                       &this->tech_tree[local_8c0].research,
                       &this->tech_tree[local_8c0].effect,
                       &this->tech_tree[local_8c0].track,
                       &this->tech_tree[local_8c0].icon,
                       &button_location_tmp,
                       &this->tech_tree[local_8c0].build_obj_id);
                this->tech_tree[local_8c0].button_location = (uchar)button_location_tmp;

                int local_8 = (int)strlen(local_84);
                for (int local_14 = 0; local_14 < local_8; local_14 = local_14 + 1) {
                    if (local_84[local_14] == '_') {
                        local_84[local_14] = ' ';
                    }
                }

                this->tech_tree[local_8c0].name = (char*)0x0;
                getstring(&this->tech_tree[local_8c0].name, local_84);

                for (short local_88 = 0; local_88 < 4; local_88 = (short)(local_88 + 1)) {
                    fscanf(local_1c, "%hd", this->tech_tree[local_8c0].pre_reqs + local_88);
                }
                for (short local_88 = 0; local_88 < 3; local_88 = (short)(local_88 + 1)) {
                    short attribute_used_tmp = 0;
                    fscanf(local_1c,
                           "%hd %hd %hd",
                           this->tech_tree[local_8c0].attribute + local_88,
                           this->tech_tree[local_8c0].attribute_cost + local_88,
                           &attribute_used_tmp);
                    this->tech_tree[local_8c0].attribute_used[local_88] = (uchar)attribute_used_tmp;
                }
                fscanf(local_1c,
                       "%hd %hd %d %d %d",
                       &this->tech_tree[local_8c0].string_id,
                       &this->tech_tree[local_8c0].string_id2,
                       &this->tech_tree[local_8c0].help_string_id,
                       &this->tech_tree[local_8c0].help_page_id,
                       &this->tech_tree[local_8c0].hotkey_id);
            }
        }
        fclose(local_1c);
    }
}

TRIBE_Tech::~TRIBE_Tech() {
    // Decomp @ 0x0050BF28: frees tech_tree entries (name strings) then the array.
    if (this->tech_tree) {
        for (short i = 0; i < this->tech_tree_num; i++) {
            if (this->tech_tree[i].name) {
                free(this->tech_tree[i].name);
            }
        }
        free(this->tech_tree);
        this->tech_tree = nullptr;
    }
}

long TRIBE_Tech::get_help_message(short param_1) {
    // Source of truth: bucket_050C.cpp.decomp @ 0x0050C2FA
    if (param_1 < 0 || this->tech_tree_num < param_1) {
        return -1;
    }
    return this->tech_tree[param_1].help_string_id;
}

long TRIBE_Tech::get_help_page(short param_1) {
    // Source of truth: bucket_050C.cpp.decomp @ 0x0050C333
    if (param_1 < 0 || this->tech_tree_num < param_1) {
        return -1;
    }
    return this->tech_tree[param_1].help_page_id;
}

long TRIBE_Tech::get_hotkey(short param_1) {
    // Source of truth: bucket_050C.cpp.decomp @ 0x0050C36C
    if (param_1 < 0 || this->tech_tree_num < param_1) {
        return -1;
    }
    return this->tech_tree[param_1].hotkey_id;
}

void TRIBE_Tech::do_tech(short param_1, RGE_Player* param_2) {
    // Source of truth: bucket_050B.cpp.decomp @ 0x0050BF9C
    if (this->tech_tree[param_1].effect >= 0) {
        this->world->effects->do_effect(this->tech_tree[param_1].effect, param_2);
    }
}

void TRIBE_Tech::save(int param_1) {
    // Source of truth: bucket_050B.cpp.decomp @ TRIBE_Tech::save
    rge_write(param_1, &this->tech_tree_num, 2);
    for (short i = 0; i < this->tech_tree_num; i++) {
        // Write pre-requisites
        for (short j = 0; j < 4; j++) {
            rge_write(param_1, &this->tech_tree[i].pre_reqs[j], 2);
        }
        // Write cost attributes (3 sets)
        for (short j = 0; j < 3; j++) {
            rge_write(param_1, &this->tech_tree[i].attribute[j], 2);
            rge_write(param_1, &this->tech_tree[i].attribute_cost[j], 2);
            rge_write(param_1, &this->tech_tree[i].attribute_used[j], 1);
        }
        rge_write(param_1, &this->tech_tree[i].pre_reqs_required, 2);
        rge_write(param_1, &this->tech_tree[i].build_obj_id, 2);
        rge_write(param_1, &this->tech_tree[i].string_id, 2);
        rge_write(param_1, &this->tech_tree[i].string_id2, 2);
        rge_write(param_1, &this->tech_tree[i].research, 2);
        rge_write(param_1, &this->tech_tree[i].effect, 2);
        rge_write(param_1, &this->tech_tree[i].track, 2);
        rge_write(param_1, &this->tech_tree[i].icon, 2);
        rge_write(param_1, &this->tech_tree[i].button_location, 1);
        rge_write(param_1, &this->tech_tree[i].help_string_id, 4);
        rge_write(param_1, &this->tech_tree[i].help_page_id, 4);
        rge_write(param_1, &this->tech_tree[i].hotkey_id, 4);
        // Write name
        short name_len = 0;
        if (this->tech_tree[i].name) {
            name_len = (short)(strlen(this->tech_tree[i].name) + 1);
        }
        rge_write(param_1, &name_len, 2);
        if (name_len > 0) {
            rge_write(param_1, this->tech_tree[i].name, (int)name_len);
        }
    }
}
