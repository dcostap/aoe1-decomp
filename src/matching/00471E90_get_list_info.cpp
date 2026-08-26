#ifndef PLAYER_GROUPED_TU
struct RGE_Tile_List_Node;
class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    RGE_Tile_List_Node* list;

    void get_list_info(RGE_Tile_List_Node*& out1, int& out2);
};
#endif

void RGE_Tile_List::get_list_info(RGE_Tile_List_Node*& out1, int& out2) {
    out1 = this->list;
    out2 = this->num_active;
}
