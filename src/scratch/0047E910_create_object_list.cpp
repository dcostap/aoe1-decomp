// RGE_Dialog_List::create_object_list
// VA: 0047E910
// PDB: rdlg_lst.cpp:151-207
//
// Attempt log:
// - Initial natural draft had the wrong RGE_Base_Game virtual slot, a 0x0C frame,
//   and an incorrect constant zero object id; it emitted an indexed record loop.
// - Restored the period RGE_Base_Game virtual surface (get_string at +0x1C),
//   canonical master-object/list-info fields, and the binary-proven object id
//   (short j, incremented for every master-object entry).
// - Short list index plus typed int unit cursors recovered the original 0x10
//   frame, 396-byte size, all three ordered calls, and the add-by-four master
//   object cursor shape. Separate first/second scan cursors are retained as the
//   cleanest source reconstruction; VC5 still colors the late cursor/id pair
//   opposite the executable and keeps the player/count homes swapped.
// - Tried local declaration reordering, a register cursor, induction update
//   order, and assignment-bound null-guard forms; no further emitted-code gain.
// - Final bounded result: structural parity is good (size/frame/calls exact),
//   but byte matching remains unresolved in the initial local schedule and
//   late cursor/id register/stack-home allocation. Left in scratch.
// - Fresh pass: packet, same-TU donors, ABI evidence, dossier, and focused
//   assembly donors confirm the typed player/master-object/list-info model.
// - Fresh probes tried pointer/count declaration order, direct initialization,
//   short counter reuse, shared cursor scope, and ordinary while/for scans.
//   The while form improved block coverage but worsened positional bytes.
// - Restored this clean natural candidate. Remaining lead is the original
//   VC5 local-home and late cursor/id allocation basin, not behavior or ABI.

#include "..\..\include\game_globals.h"

class TListDialog {
public:
    virtual ~TListDialog();
};

class rdlg_list_info {
public:
    char text[0x64];
    short id;
};

class RGE_Game_Object {
public:
    char gap_00[8];
    char* name;               // +0x08
    short icon_id;            // +0x0C
    char gap_0E[0x4E - 0x0E];
    unsigned char field_4E;   // +0x4E
};

class RGE_Player {
public:
    char gap_00[0x22];
    short master_object_num;           // +0x22
    RGE_Game_Object** master_objects;  // +0x24
};

class RGE_Base_Game {
public:
    char gap_00[4];
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void* hwnd, unsigned int msg, unsigned int wparam, long lparam);
    virtual void set_prog_mode(int mode);
    virtual void set_game_mode(int mode, int sub_mode);
    virtual void set_player(short player);
    virtual int get_error_code();
    virtual char* get_string(int a, long b, char* c, int d);
    RGE_Player* get_player();
};

extern RGE_Base_Game* rge_base_game;

class RGE_Dialog_List : public TListDialog {
public:
    char gap_04[0x4AC];
    short list_size;              // +0x4B0
    short list_line;              // +0x4B2
    rdlg_list_info* list_info;    // +0x4B4
    char** list_text;             // +0x4B8

    int create_object_list();
};

int RGE_Dialog_List::create_object_list()
{
    short i;
    short j;
    RGE_Player* player;
    short num_objects;
    int cnt;

    player = rge_base_game->get_player();
    if (!player)
        return 0;

    this->list_size = 1;
    num_objects = player->master_object_num;

    if (num_objects > 0) {
        int obj_idx = 0;
        cnt = num_objects;
        do {
            if (player->master_objects[obj_idx] &&
                player->master_objects[obj_idx]->field_4E == 0)
                this->list_size++;
            obj_idx++;
            cnt--;
        } while (cnt != 0);
    }

    if (this->list_size == 0)
        return 0;

    this->list_info = (rdlg_list_info*)calloc(this->list_size, 0x66);
    if (!this->list_info)
        return 0;

    this->list_info[0].id = -1;
    strcpy(this->list_info[0].text, " <None> ");

    i = 1;
    j = 0;
    if (num_objects > 0) {
        int obj_idx = 0;
        do {
            RGE_Game_Object* obj = player->master_objects[obj_idx];
            if (obj && obj->field_4E == 0) {
                this->list_info[i].id = j;
                if (obj->icon_id > 0) {
                    rge_base_game->get_string(2, obj->icon_id, (char*)&this->list_info[i], 100);
                } else {
                    strcpy(this->list_info[i].text, obj->name);
                }
                i++;
            }
            j++;
            obj_idx++;
        } while (j < num_objects);
    }

    return 1;
}
