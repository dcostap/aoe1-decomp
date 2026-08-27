// VA: 004595E0 RGE_Map::set_elev
// Owner: RGE_Map::set_elev, map.cpp:2466-2557.
// Natural fields: RGE_Tile::terrain_type and RGE_Tile::height.
// Current canonical-TU result: 789 / 792 bytes, 178 positional differences,
// zero relocation-target mismatches, and zero boundary escapes.
// Classification: accepted drift. Standalone source remains MATCH.

#include <windows.h>

#ifndef MAP_CONTEXT_H
class RGE_Tile;
class RGE_Static_Object;

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    unsigned char centered;
    unsigned char gap_0D[3];
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
    short number_of_objects;
    unsigned char gap_0A[2];
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game();
    virtual void recycle_out_of_game();
    virtual void draw();
    virtual void shadow_draw();
    virtual void normal_draw();
    virtual void draw_front_frame();
    virtual void draw_back_frame();
    virtual void draw_frame();
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save();
    virtual float teleport(float x, float y, float z);

    char gap_04[0x34];
    float world_x;
    float world_y;
};

class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type : 5;
    unsigned char height : 3;
    unsigned char border_type : 4;
    unsigned char border_shape : 4;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    RGE_Object_List objects;
};

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    void* list;

    void add_node(int col, int row);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x68];
    RGE_Tile_List diam_tile_list;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x19];
    unsigned char game_state;
    char gap_1E[0x22];
    RGE_Player** players;
    char gap_44[0x38];
    short curr_player;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Tile* map;
    long map_width;
    long map_height;
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;
    char gap_8D90[0x30];
    RGE_Game_World* game_world;

    unsigned char get_tile_type(short col, short row);
    void set_map_screen_pos(int col0, int row0, int col1, int row1);
    void request_redraw(int col0, int row0, int col1, int row1,
                        unsigned char attr);
    void set_elev(short col0, short row0, short col1, short row1,
                  unsigned char elevation, short delta,
                  unsigned char relative);
};

#endif

void RGE_Map::set_elev(short col0, short row0, short col1, short row1,
                       unsigned char elevation, short delta,
                       unsigned char relative)
{
    short row_i;
    short col_i;
    RGE_Tile* tile;
    RGE_Player* cur_player =
        this->game_world->players[this->game_world->curr_player];

    if (row0 > row1) {
        short temp = row1;
        row1 = row0;
        row0 = temp;
    }
    if (col0 > col1) {
        short temp = col1;
        col1 = col0;
        col0 = temp;
    }

    if (row0 < 0)
        row0 = 0;
    if (row1 >= this->map_height)
        row1 = (short)this->map_height - 1;
    if (col0 < 0)
        col0 = 0;
    if (col1 >= this->map_width)
        col1 = (short)this->map_width - 1;

    if (relative != 0) {
        if (delta != 0) {
            for (row_i = row0; row_i <= row1; ++row_i) {
                for (col_i = col0; col_i <= col1; ++col_i) {
                    tile = &this->map_row_offset[row_i][col_i];
                    short new_elevation = tile->height + delta;

                    if (new_elevation < 0)
                        new_elevation = 0;
                    else if (new_elevation > 0xFF)
                        new_elevation = 0xFF;

                    tile->height = (unsigned char)new_elevation;
                    if (tile->height > 8)
                        tile->height = 0;
                }
            }
        } else {
            if (elevation > 8)
                elevation = 8;

            for (row_i = row0; row_i <= row1; ++row_i) {
                for (col_i = col0; col_i <= col1; ++col_i) {
                    tile = &this->map_row_offset[row_i][col_i];
                    tile->height = elevation;
                }
            }
        }
    }

    if (row0 > 0)
        --row0;
    if (row1 < this->map_height - 1)
        ++row1;
    if (col0 > 0)
        --col0;
    if (col1 < this->map_width - 1)
        ++col1;

    for (row_i = row0; row_i <= row1; ++row_i) {
        for (col_i = col0; col_i <= col1; ++col_i) {
            tile = &this->map_row_offset[row_i][col_i];
            tile->tile_type = this->get_tile_type(col_i, row_i);

            RGE_Object_Node* object_node = tile->objects.list;
            while (object_node != 0) {
                object_node->node->teleport(object_node->node->world_x,
                                             object_node->node->world_y, 0.0f);
                object_node = object_node->next;
            }

            if (this->game_world->game_state != 3)
                cur_player->diam_tile_list.add_node(col_i, row_i);
        }
    }

    this->set_map_screen_pos((int)col0, (int)row0,
                             (int)col1, (int)row1);
    this->request_redraw((int)col0, (int)row0,
                         (int)col1, (int)row1, 0);
}
