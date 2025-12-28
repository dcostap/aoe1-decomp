#pragma once

struct RGE_Tile_List_Node {
    int col;
    int row;
};

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    RGE_Tile_List_Node *list;

    RGE_Tile_List(int initial_size);
    ~RGE_Tile_List();

    void add_node(int col, int row);
    void del_list();
    void get_list_info(RGE_Tile_List_Node *&out_list, int &out_num);
    int get_new_count();
};

static_assert(sizeof(RGE_Tile_List) == 20, "RGE_Tile_List size mismatch");
