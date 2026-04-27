// RGE_Dialog_List::create_object_list
// VA: 0047E910
// PDB: rdlg_lst.cpp:151-207
//
// Attempt log:
// - draft 1: natural for loops, struct offsets → 87% diff, divide instruction in loop
// - draft 2: j/4 with j+=4 → still divide instructions
// - draft 3: pointer arithmetic p_obj = master_objects; *p_obj++ → still generates divide
// - draft 4: unsigned int for index → no change
// - Remaining: VC5 optimizes array index + increment-by-1 into byte-offset loop with 
//   divide-by-4. The original uses direct byte offset (add edx,4; [ecx+edx]).
//   This is a persistent codegen difference in loop shape.
// Left in scratch.

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
    RGE_Player* get_player();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void get_name(int a, int b, void* c, int d);
};

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
    int cnt;
    unsigned int i;

    RGE_Player* player = rge_base_game->get_player();
    if (!player)
        return 0;

    this->list_size = 1;
    short num_objects = player->master_object_num;

    if (num_objects > 0) {
        i = 0;
        cnt = num_objects;
        do {
            if (player->master_objects[i] &&
                player->master_objects[i]->field_4E == 0)
                this->list_size++;
            i++;
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
    {
        int obj_idx = 0;
        if (num_objects > 0) {
            do {
                RGE_Game_Object* obj = player->master_objects[obj_idx];
                if (obj && obj->field_4E == 0) {
                    this->list_info[i].id = 0;
                    if (obj->icon_id > 0) {
                        rge_base_game->get_name(2, obj->icon_id, &this->list_info[i], 100);
                    } else {
                        strcpy(this->list_info[i].text, obj->name);
                    }
                    i++;
                }
                obj_idx++;
            } while (obj_idx < num_objects);
        }
    }

    return 1;
}
