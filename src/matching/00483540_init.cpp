// 00483540 init
// tried the obvious derived-only surface first; because the base lacked a vptr, VC5 treated the
// random-map-module subobject as starting at +4 and emitted `lea edi,[esi+4]` before helper calls.
// use the real polymorphic base so helper calls stay on `ecx = esi`, and keep the full virtual slot
// order so the four module calls land at vt[1..4] rather than vt[0..3].

class RGE_Tile;
class RGE_Map;
class RGE_Game_World;

class RGE_Random_Map_Module {
public:
    virtual unsigned char generate();

    RGE_Random_Map_Module* parent;
    void* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    void* stack_array;
    void* stack_offsets;

    void update_map_info(RGE_Map* param_1);
    void create_shared_resources();
};

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    RGE_Game_World* world;
    long map_type;
    long number_of_players;

    virtual void add_land_module(unsigned char param_1);
    virtual void add_terrain_module();
    virtual void add_object_module();
    virtual void add_elevation_module();
    virtual unsigned char init(RGE_Map* param_1, RGE_Game_World* param_2, unsigned char param_3, long param_4, unsigned char param_5);
    virtual unsigned char de_init();
};

unsigned char RGE_RMM_Database_Controller::init(RGE_Map* param_1, RGE_Game_World* param_2, unsigned char param_3, long param_4, unsigned char param_5) {
    this->world = param_2;
    this->map_type = param_3;
    this->number_of_players = param_4;
    this->update_map_info(param_1);
    this->create_shared_resources();
    this->add_land_module(param_5);
    this->add_terrain_module();
    this->add_object_module();
    this->add_elevation_module();
    return 1;
}
