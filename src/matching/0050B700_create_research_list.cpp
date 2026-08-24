// VA: 0050B700 TRIBE_Dialog_List::create_research_list
// tdlg_lst.cpp lines 140-177
//
// The shared declaration surface preserves selected_obj at +0x130,
// master_obj at +0x8, interface_group at +0x10, and list ownership at
// +0x4B0/+0x4B4.

#include <stdlib.h>
#include <string.h>

#include "../../include/tdlg_lst_context.h"

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
                player->selected_obj->master_obj->interface_group);
            if (item_num != 0) {
                list_size = item_num;
                list_info = (rdlg_list_info*)calloc(item_num, sizeof(rdlg_list_info));
                if (list_info != 0) {
                    if (list_size > 0) {
                        do {
                            list_info[i].id = avail_list[i].id;
                            strcpy(list_info[i].name, avail_list[i].name);
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
