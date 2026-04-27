// RGE_Dialog_List::~RGE_Dialog_List
// VA: 0047E830
// PDB: rdlg_lst.cpp:97-116

#include "..\..\include\game_globals.h"

class TListDialog {
public:
    virtual ~TListDialog();
};

class rdlg_list_info {
};

class RGE_Dialog_List : public TListDialog {
public:
    char gap_04[0x4AC];
    short list_size;              // +0x4B0
    short list_line;              // +0x4B2
    rdlg_list_info* list_info;    // +0x4B4
    char** list_text;             // +0x4B8

    virtual ~RGE_Dialog_List();
};

RGE_Dialog_List::~RGE_Dialog_List()
{
    int i;

    if (this->list_text) {
        for (i = 0; i < this->list_size; i++) {
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
