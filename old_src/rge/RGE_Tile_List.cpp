#include "RGE_Tile_List.h"
#include <stdlib.h>

RGE_Tile_List::RGE_Tile_List(int initial_size) {
    this->list = (RGE_Tile_List_Node *)calloc(initial_size, 8);
    this->list_size = initial_size;
    this->num_active = 0;
    this->new_count = 0;
    this->collapse_list = 0;
}

RGE_Tile_List::~RGE_Tile_List() {
    if (this->list) free(this->list);
}

void RGE_Tile_List::add_node(int col, int row) {}
void RGE_Tile_List::del_list() {}
void RGE_Tile_List::get_list_info(RGE_Tile_List_Node *&out_list, int &out_num) {}
int RGE_Tile_List::get_new_count() { return 0; }
