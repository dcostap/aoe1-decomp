// PDB source module: C:/msdev/work/age1_x1/rdlg_lst.cpp.
// Definitions follow the original source order.

#include <stdlib.h>
#include <string.h>

#include "../include/Pnl_scr.h"
#include "../include/rdlg_lst.h"
#include "../include/basegame.h"
#include "../include/m_s_obj.h"
#include "../include/player.h"
#include "../include/rge_base_game_global.h"

extern "C" __declspec(dllimport) int __stdcall CompareStringA(
    unsigned long locale, unsigned long flags, const char* string1,
    int length1, const char* string2, int length2);

RGE_Dialog_List::RGE_Dialog_List(char* name) : TListDialog(name) {
}

int RGE_Dialog_List::setup(TScreenPanel* screen, char* popup_file,
                           long popup_id, int list_type, char* title)
{
    this->list_type = list_type;
    this->list_info = 0;
    this->list_text = 0;

    if (this->error_code != 0)
        return 0;
    if (this->create_list() == 0)
        return 0;

    this->sort_list();
    this->calc_list_line();

    this->list_text = (char**)calloc((unsigned int)this->list_size, 4);
    if (this->list_text == 0)
        return 0;

    rdlg_list_info*& info = this->list_info;
    int i = 0;
    int offset = 0;
    while (i < this->list_size) {
        this->list_text[i] = (char*)calloc(strlen(info->text + offset) + 1, 1);
        if (this->list_text[i] == 0)
            return 0;
        strcpy(this->list_text[i], info->text + offset);
        ++i;
        offset += 0x66;
    }

    return this->TListDialog::setup(
        screen, popup_file, popup_id,
        0x136, 0x190, 0x0A, 0x0A, 0x122,
        0x19, title, 0x0A, 0x2D, 0x122,
        0x131, this->list_text, this->list_size, this->list_line,
        0x0A, 0xA0, 0x168, 0x8C, 0x1E) != 0;
}

RGE_Dialog_List::~RGE_Dialog_List()
{
    if (this->list_text) {
        for (int i = 0; i < this->list_size; i++) {
            if (this->list_text[i])
                free(this->list_text[i]);
        }
        free(this->list_text);
        this->list_text = 0;
    }

    if (this->list_info) {
        free(this->list_info);
        this->list_info = 0;
    }
}

short RGE_Dialog_List::get_list_id(void)
{
    short index = this->list_id;
    if (index == -1)
        return index;
    return this->list_info[index].id;
}

int RGE_Dialog_List::create_list()
{
    if (this->list_type - 1)
        return 0;
    return this->create_object_list();
}

int RGE_Dialog_List::create_object_list()
{
    short i;
    short j;
    RGE_Player* player;
    short num_objects;

    if ((player = rge_base_game->get_player()) == 0)
        return 0;

    this->list_size = 1;
    num_objects = player->master_object_num;
    if (num_objects > 0) {
        int count;
        int object_index = 0;
        count = num_objects;
        do {
            if (player->master_objects[object_index] &&
                player->master_objects[object_index]->hide_in_scenario_editor == 0)
                this->list_size++;
            object_index++;
            count--;
        } while (count != 0);
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
        int object_index = 0;
        do {
            if (player->master_objects[object_index] &&
                player->master_objects[object_index]->hide_in_scenario_editor == 0) {
                this->list_info[i].id = j;
                if (player->master_objects[object_index]->string_id > 0) {
                    rge_base_game->get_string(2,
                                              player->master_objects[object_index]->string_id,
                                              this->list_info[i].text, 100);
                } else {
                    strcpy(this->list_info[i].text,
                           player->master_objects[object_index]->name);
                }
                i++;
            }
            j++;
            object_index++;
        } while (j < num_objects);
    }

    return 1;
}

int __cdecl rdlg_list_compare(const void* a, const void* b)
{
    int result = CompareStringA(0x400, 1, (const char*)a, -1,
                                (const char*)b, -1);
    if (result == 1)
        return -1;
    return result == 3;
}

void RGE_Dialog_List::sort_list()
{
    qsort(this->list_info, (int)this->list_size, 0x66, rdlg_list_compare);
}

void RGE_Dialog_List::calc_list_line()
{
    this->list_line = -1;
    short selected_id = this->get_cur_id();
    if (selected_id != -1) {
        for (short i = 0; i < this->list_size; i++) {
            if (this->list_info[i].id == selected_id) {
                this->list_line = i;
                break;
            }
        }
    }
    if (this->list_line == -1)
        this->list_line = 0;
}

short RGE_Dialog_List::get_cur_id()
{
    int list_type;
    RGE_Base_Game* base_game;

    list_type = this->list_type;
    if (--list_type != 0)
        return -1;
    base_game = rge_base_game;
    return base_game->master_obj_id;
}
