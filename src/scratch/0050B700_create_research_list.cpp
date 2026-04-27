// VA: 0050B700 TRIBE_Dialog_List::create_research_list
// tdlg_lst.cpp lines 140-177

// attempt 1: natural C++, matching create_train_list structure
// Size: 272/277 (5 bytes short, sub esp 8 vs 0Ch)

#include <stdlib.h>
#include <string.h>

class RGE_Player {
public:
    int own_selected();
    void interface_research_avail(short* item_num, void** avail_list, short size);
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

    int create_research_list();
};

int TRIBE_Dialog_List::create_research_list() {
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
    player->interface_research_avail(&item_num, &avail_list, 
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
        for (int i = 0; i < itemCount; i++) {
            listItems[i].id = ((AvailItem*)avail_list)[i].id;
            strcpy(listItems[i].name, ((AvailItem*)avail_list)[i].name);
        }
    }
    return 1;
}
