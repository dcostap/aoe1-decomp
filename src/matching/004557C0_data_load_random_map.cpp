// first pass: keep the allocation/ctor as a natural direct new-expression and preserve the single assignment
// with /GX this should be the right EH/new basin if the constructor shape is the same as the packet
#ifndef MAP_CONTEXT_H
class RGE_Map;
class RGE_Game_World;
class RGE_Random_Map_Module {
public:
    void* vtable_ptr;
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
};

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    RGE_Game_World* world;
    long map_type;
    long number_of_players;
    char pad_3C[0x1438];
    char pad_1474[0x1298];
    char pad_270C[0x18C8];
    char pad_3FD4[0xF80];
    char pad_4F54[0x8];

    RGE_RMM_Database_Controller(int param_1);
};

class RGE_Map {
public:
    char pad_00[0x8DBC];
    RGE_RMM_Database_Controller* random_map_controller;

    void data_load_random_map(int param_1);
};

#endif

void RGE_Map::data_load_random_map(int param_1) {
    this->random_map_controller = new RGE_RMM_Database_Controller(param_1);
}
