// VA: 0050B5E0 TRIBE_Dialog_List::create_train_list
// tdlg_lst.cpp lines 97-134

// Canonical ownership: TRIBE_Dialog_List stores the resulting count at +0x4B0
// and rdlg_list_info records at +0x4B4.  The selected object's master supplies
// the interface group passed to TRIBE_Player::interface_item_avail.
//
// Attempt log:
// - baseline: decompiler-shaped raw selected-object access and split failure
//   returns; 272/277 bytes, 0x8 frame, structural mismatch.
// - nested typed guards with the sibling list-builder surface: 277/277 bytes,
//   0xC frame, 14-byte localized drift at the two zero stores versus the
//   selected-master load.
// - explicit assignment, declaration-order, named-group, and polymorphic
//   RGE_Static_Object variants did not move that 14-byte hunk.
// - a comma-order and volatile selected-object diagnostic were unchanged and
//   are not retained as source.
// - localized eight-case initialization lab (#10) found no exact variant;
//   best emitted code remains the 14-byte drift, while this natural typed form
//   is the retained source reconstruction.
// - Main-agent audit restored canonical master/player/base-game destructor
//   ownership; the validated 14-byte scheduling gap is unchanged.

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
    long id;
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
    int create_train_list();
};

int TRIBE_Dialog_List::create_train_list() {
    TRIBE_Player* player = (TRIBE_Player*)rge_base_game->get_player();
    short i = 0;

    if (player != 0 && player->selected_obj != 0) {
        if (player->own_selected()) {
            Item_Avail* avail_list = 0;
            short item_num = 0;
            player->interface_item_avail(
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
