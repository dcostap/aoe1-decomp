#ifndef AOE1_TDLG_LST_CONTEXT_H
#define AOE1_TDLG_LST_CONTEXT_H

// Authentic shared declaration surface for the PDB-ordered tdlg_lst.cpp TU.
// Keep the class hierarchy and member offsets common to every owner body.

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

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x12C];
    RGE_Static_Object* selected_obj;

    int is_group_selected(short group);
    int own_selected();
};

class TRIBE_Player : public RGE_Player {
public:
    void interface_item_avail(Item_Avail** item_list, short* item_num, short size);
    void interface_tech_avail(Item_Avail** item_list, short* item_num, short size);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    RGE_Player* get_player();
};

extern RGE_Base_Game* rge_base_game;

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
    RGE_Dialog_List(char* name);
    virtual ~RGE_Dialog_List();
    virtual int create_list();
    virtual short get_cur_id();

    int list_type;
    short list_size;
    short list_line;
    rdlg_list_info* list_info;
    char** list_text;
};

class TRIBE_Dialog_List : public RGE_Dialog_List {
public:
    virtual ~TRIBE_Dialog_List();
    TRIBE_Dialog_List(char* name);

protected:
    virtual int create_list();
    int create_build_list();
    int create_train_list();
    int create_research_list();
    virtual short get_cur_id();
};

#endif
