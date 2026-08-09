// VA: 0050B700 TRIBE_Dialog_List::create_research_list
// tdlg_lst.cpp lines 140-177

// attempt 1: raw local layout and early-return reconstruction (wrong call set,
//             frame, and CFG)
// attempt 2: corrected interface_tech_avail call and nested positive guards;
//             CFG/size became close, but the ad-hoc list surface kept this in
//             the wrong register/local basin
// attempt 3: mirrored the exact same-TU list-builder surface: selected_obj,
//             Item_Avail ABI, rdlg_list_info ownership, and direct list fields
// attempt 4: canonical surface reached exact size/frame/CFG and 14 differing
//             bytes; only the output-zero versus selected-master load order
//             remains (calls, relocations, loop, and epilogues align)
// attempts 5-9: declaration/assignment order, materialized scheduling forms,
//               narrow volatility, comma scheduling, and nested guards were
//               unchanged or duplicated codegen; none moved the 14-byte hunk
// attempt 10: aggregate output record worsened size/CFG; rolled back
// left in scratch: clean period-plausible source; remaining drift is the
// VC5 scheduling order at tdlg_lst.cpp:155-157, with no productive hypothesis
// remaining in this assignment
// main-agent audit restored canonical master/object/player/base-game destructor
// ownership; the validated 14-byte scheduling gap is unchanged.
// - function-scope output declarations, matching the old TU's top-level local
//   style, reproduce the original zero-store/load order exactly.

#include <stdlib.h>
#include <string.h>

class RGE_Player;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short interface_group;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[4];
    RGE_Master_Static_Object* master_obj;
};

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
    char gap_04[0x12C];
    RGE_Static_Object* selected_obj;

    int own_selected();
};

class TRIBE_Player : public RGE_Player {
public:
    void interface_tech_avail(Item_Avail** item_list, short* item_num, short size);
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
    char name[0x64];
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
    int create_research_list();
};

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
