// VA: 0050B5E0 TRIBE_Dialog_List::create_train_list
// tdlg_lst.cpp lines 97-134

// attempt 1: natural C++ matching original control flow, direct 0x62C574 access

#include <stdlib.h>
#include <string.h>

class RGE_Player {
public:
    int is_group_selected(short group);
    int own_selected();
    void interface_item_avail(short* item_num, void** avail_list, short size);
};

class RGE_Base_Game {
public:
    int get_player();
};

void* calloc(size_t num, size_t size);

struct AvailItem {
    char* name;
    short id;
};

struct ListItem {
    char name[0x64];
    short id;
};

class TRIBE_Dialog_List {
public:
    char gap_000[0x4B0];
    short itemCount;
    void* items;

    int create_train_list();
};

int TRIBE_Dialog_List::create_train_list() {
    RGE_Base_Game* game = *(RGE_Base_Game**)0x62C574;
    RGE_Player* player = (RGE_Player*)game->get_player();
    if (player == 0) {
        return 0;
    }
    if (*(int*)((int)player + 0x130) == 0) {
        return 0;
    }
    if (!player->own_selected()) {
        return 0;
    }
    void* avail_list = 0;
    short item_num = 0;
    char* temp_str;
    player->interface_item_avail(&item_num, &avail_list, 
        *(short*)(*(int*)(*(int*)((int)player + 0x130) + 8) + 0x10));
    if (item_num == 0) {
        return 0;
    }
    itemCount = item_num;
    ListItem* listItems = (ListItem*)calloc(item_num, 0x66);
    items = listItems;
    if (listItems == 0) {
        return 0;
    }
    if (itemCount > 0) {
        int i;
        for (i = 0; i < itemCount; i++) {
            listItems[i].id = ((AvailItem*)avail_list)[i].id;
            temp_str = listItems[i].name;
            strcpy(temp_str, ((AvailItem*)avail_list)[i].name);
        }
    }
    return 1;
}
