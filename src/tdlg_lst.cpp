
#include "../include/tdlg_lst.h"
#include "../include/basegame.h"
#include "../include/m_s_obj.h"
#include "../include/rge_base_game_global.h"
#include "../include/stat_obj.h"
#include "../include/tplayer.h"

#include <stdlib.h>
#include <string.h>

TRIBE_Dialog_List::TRIBE_Dialog_List(char* name)
    : RGE_Dialog_List(name) {
}

int TRIBE_Dialog_List::create_list() {
    switch (this->list_type) {
    case 100:
        return this->create_build_list();
    case 101:
        return this->create_train_list();
    case 102:
        return this->create_research_list();
    default:
        return RGE_Dialog_List::create_list();
    }
}

int TRIBE_Dialog_List::create_build_list() {
    TRIBE_Player* player = (TRIBE_Player*)rge_base_game->get_player();
    short i = 0;
    if (player == 0) {
        return 0;
    }
    if (!player->is_group_selected(4)) {
        return 0;
    }

    Item_Avail* avail_list = 0;
    short item_num = 0;
    player->interface_item_avail(&avail_list, &item_num, 0x76);
    if (item_num == 0) {
        return 0;
    }

    list_size = item_num;
    list_info = (rdlg_list_info*)calloc(item_num, sizeof(rdlg_list_info));
    if (list_info == 0) {
        return 0;
    }

    if (list_size > 0) {
        do {
            list_info[i].id = avail_list[i].id;
            strcpy(list_info[i].text, avail_list[i].name);
            i++;
        } while (i < list_size);
    }
    return 1;
}

int TRIBE_Dialog_List::create_train_list() {
    Item_Avail* avail_list;
    short item_num;
    TRIBE_Player* player = (TRIBE_Player*)rge_base_game->get_player();
    short i = 0;

    if (player != 0 && player->selected_obj != 0) {
        if (player->own_selected()) {
            avail_list = 0;
            item_num = 0;
            player->interface_item_avail(
                &avail_list, &item_num,
                player->selected_obj->master_obj->id);
            if (item_num != 0) {
                list_size = item_num;
                list_info = (rdlg_list_info*)calloc(item_num, sizeof(rdlg_list_info));
                if (list_info != 0) {
                    if (list_size > 0) {
                        do {
                            list_info[i].id = avail_list[i].id;
                            strcpy(list_info[i].text, avail_list[i].name);
                            i++;
                        } while (i < list_size);
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}

int TRIBE_Dialog_List::create_research_list() {
    Item_Avail* avail_list;
    short item_num;
    TRIBE_Player* player = (TRIBE_Player*)rge_base_game->get_player();
    short i = 0;

    if (player != 0 && player->selected_obj != 0) {
        if (player->own_selected()) {
            avail_list = 0;
            item_num = 0;
            player->interface_tech_avail(
                &avail_list, &item_num,
                player->selected_obj->master_obj->id);
            if (item_num != 0) {
                list_size = item_num;
                list_info = (rdlg_list_info*)calloc(item_num, sizeof(rdlg_list_info));
                if (list_info != 0) {
                    if (list_size > 0) {
                        do {
                            list_info[i].id = avail_list[i].id;
                            strcpy(list_info[i].text, avail_list[i].name);
                            i++;
                        } while (i < list_size);
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}

short TRIBE_Dialog_List::get_cur_id() {
    int value = this->list_type - 100;
    if (value == 0)
        goto return_minus_one;
    if (--value == 0)
        goto return_minus_one;
    if (--value == 0)
        goto return_minus_one;
    return RGE_Dialog_List::get_cur_id();

return_minus_one:
    return -1;
}
