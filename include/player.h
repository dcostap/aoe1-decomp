#ifndef AOE1_PLAYER_H
#define AOE1_PLAYER_H

class RGE_Player;
class RGE_Tile_List;
struct RGE_Tile_List_Node;

struct RGE_Tile_List_Node {
    int col;
    int row;
};

typedef char rge_tile_list_node_size_check[
    (sizeof(RGE_Tile_List_Node) == 0x08) ? 1 : -1];

class RGE_Tile_List {
public:
    RGE_Tile_List(int list_size);
    ~RGE_Tile_List();
    void get_list_info(RGE_Tile_List_Node*& list, int& number);

    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    RGE_Tile_List_Node* list;
};

typedef char rge_tile_list_size_check[
    (sizeof(RGE_Tile_List) == 0x14) ? 1 : -1];

#endif
