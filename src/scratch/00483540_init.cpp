// 00483540 init: kept the obvious field stores and call sequence first.
// tried a plain direct member-call version; helper-call basin drifted into an extra EDI temp and local thunks
// tried adding local helper bodies/context; mismatch stayed at the update/create helper-call region
// paused in scratch because the remaining difference is call-shape/codegen drift after the field stores

class RGE_Tile;
class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Tile** give_up_map_offsets();
    int get_map_width();
    int get_map_height();
};
class RGE_Game_World;
class RGE_Random_Map_Module {
public:
    RGE_Random_Map_Module* parent;
    void* list;
    RGE_Map* map;
    void* map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    void* stack_array;
    void* stack_offsets;

    void update_child_map_info();
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

    unsigned char init(RGE_Map* param_1, RGE_Game_World* param_2, unsigned char param_3, long param_4, unsigned char param_5);
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

void RGE_Random_Map_Module::update_map_info(RGE_Map* param_1) {
    this->map = param_1;
    if (param_1 != 0) {
        this->map_row_offset = param_1->give_up_map_offsets();
        this->map_width = param_1->get_map_width();
        this->map_height = param_1->get_map_height();
    } else {
        this->map_row_offset = 0;
        this->map_width = 0;
        this->map_height = 0;
    }
    this->update_child_map_info();
}

void RGE_Random_Map_Module::create_shared_resources() {
    // Intentionally left as a local context stub for codegen matching.
}
