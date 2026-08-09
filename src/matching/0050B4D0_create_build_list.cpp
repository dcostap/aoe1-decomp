// VA: 0050B4D0 TRIBE_Dialog_List::create_build_list
// tdlg_lst.cpp lines 54-91

// attempt 1-4: various approach attempts
// - member calls with extern pointers: 256/271 bytes
// - raw C function: 224/271 bytes
// - direct 0x62C574 access: 240/271 bytes
// - added gap_000[0x4B0] for correct field offsets: 240/271
// BEST before this session: 240/271 bytes, structure all correct but register
// allocation differs and local stack is 8 vs 12 bytes.
// probe 1 baseline: restored the period-shaped TRIBE_Player interface ABI, an
// early short loop index, direct member reloads, and the do/while copy (100
// differing bytes; frame/size/CFG still one byte off).
// probe 2 layout: the proven 0x28-byte Item_Avail record restored the input
// stride/address schedule and produced an exact match.
// probe 3 layout: canonical RGE_Dialog_List/list_size/list_info ownership and
// rdlg_list_info kept the same exact bytes.
// probe 4 context: typed rge_base_game extern kept the exact bytes and removed
// the raw global-address expression.
// main-agent audit restored canonical polymorphic RGE_Player/RGE_Base_Game
// ownership; emitted code remains exact.

#include <stdlib.h>
#include <string.h>

class Item_Avail {
public:
    char* name;
    short id;
    short pict;
    short inventory_item_1;
    unsigned char gap_0A[2];
    float inventory_cost_1;
    short inventory_item_2;
    unsigned char gap_12[2];
    float inventory_cost_2;
    short inventory_item_3;
    unsigned char gap_1A[2];
    float inventory_cost_3;
    long help_string_id;
    long help_page_id;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    int is_group_selected(short group);
};

class TRIBE_Player : public RGE_Player {
public:
    void interface_item_avail(Item_Avail** item_list, short* item_num, short size);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    RGE_Player* get_player();
};

extern RGE_Base_Game* rge_base_game;

void* calloc(size_t num, size_t size);

class rdlg_list_info {
public:
    char text[0x64];
    short id;
};

class TListDialog {
public:
    virtual ~TListDialog();
    char gap_04[0x4A8];
};

class RGE_Dialog_List : public TListDialog {
public:
    int list_type;
    short list_size;
    short list_line;
    rdlg_list_info* list_info;
    char** list_text;
};

class TRIBE_Dialog_List : public RGE_Dialog_List {
public:

    int create_build_list();
};

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
