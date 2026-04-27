// VA: 0050B4D0 TRIBE_Dialog_List::create_build_list
// tdlg_lst.cpp lines 54-91

// attempt 1-4: various approach attempts
// - member calls with extern pointers: 256/271 bytes
// - raw C function: 224/271 bytes  
// - direct 0x62C574 access: 240/271 bytes
// - added gap_000[0x4B0] for correct field offsets: 240/271
// BEST: 240/271 bytes, structure all correct but register allocation
// differs and local stack is 8 vs 12 bytes.
// Left in scratch: persistent codegen-basin gap.
// Behavior fully equivalent.

#include <stdlib.h>
#include <string.h>

class RGE_Player {
public:
    int is_group_selected(short group);
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

    int create_build_list();
};

int TRIBE_Dialog_List::create_build_list() {
    RGE_Base_Game* game = *(RGE_Base_Game**)0x62C574;
    RGE_Player* player = (RGE_Player*)game->get_player();
    if (player == 0) {
        return 0;
    }
    if (!player->is_group_selected(4)) {
        return 0;
    }
    void* avail_list = 0;
    short item_num = 0;
    player->interface_item_avail(&item_num, &avail_list, 0x76);
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
        for (int i = 0; i < itemCount; i++) {
            listItems[i].id = ((AvailItem*)avail_list)[i].id;
            strcpy(listItems[i].name, ((AvailItem*)avail_list)[i].name);
        }
    }
    return 1;
}
