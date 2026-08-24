// VA: 0050B4D0 TRIBE_Dialog_List::create_build_list
// tdlg_lst.cpp lines 54-91
//
// The shared declaration surface models the proven Item_Avail stride, the
// TRIBE_Player interface ABI, and RGE_Dialog_List list ownership.

#include <stdlib.h>
#include <string.h>

#include "../../include/tdlg_lst_context.h"

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
            strcpy(list_info[i].name, avail_list[i].name);
            i++;
        } while (i < list_size);
    }
    return 1;
}
