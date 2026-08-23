#ifndef AOE1_TMAP_CONTEXT_H
#define AOE1_TMAP_CONTEXT_H

// Canonical tmap.cpp declarations used by the forest and terrain owners.
// The field offsets come from the original tmap.cpp accesses and exact
// do_terrain_brush_check/find_cliff/delete_cliff donors.

class RGE_Game_World {
public:
    char gap_00[0x1D];
    unsigned char game_state;
    char gap_1E[0x1E];
    short player_num;
    char gap_3E[0x2];
    class RGE_Player** players;
    char gap_44[0x38];
    short curr_player;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short id;
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x3C];
    unsigned char field_48;
};

class RGE_Object_Node {
public:
    RGE_Static_Object* object;
    RGE_Object_Node* next;
};

class RGE_Tile {
public:
    char gap_00[0x05];
    unsigned char terrain;
    unsigned char border;
    char gap_07[0x09];
    RGE_Object_Node* object_list;
    char gap_14[0x04];
};

class RGE_Tile_List {
public:
    void add_node(int x, int y);
};

class RGE_Player {
public:
    char gap_00[0x6C];
    RGE_Tile_List diam_tile_list;
};

class RGE_Map {
public:
    char gap_00[0x08];
    long map_width;
    long map_height;
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;

    void get_border_type(short row, short col);

};

class TRIBE_Map : public RGE_Map {
public:
    void change_terrain(short x, short y, unsigned char terrain,
                        RGE_Game_World* world);
    void check_tile_for_forest_change(short x, short y,
                                      RGE_Game_World* world);
};

#endif
