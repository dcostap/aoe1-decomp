// VA: 00483430 generate (264B)
// rmm_dbct.cpp, lines 378-389, /GX EH frame.
//
// Clean reconstruction: the four generator objects are created with the
// period source's standalone new-expressions, then the inherited random-map
// generator is called.  The controller fields and generator sizes below are
// named/layout-backed declarations; they are not decompiler cursor plumbing.
//
// Previous scratch stub only allocated one buffer and stored it as field_4F50;
// that was not the observed four-constructor behavior and has been replaced.
// Main-agent audit restored the donor-backed module destructor surface;
// emitted code remains exact.

#include <new.h>

class RGE_Map;
class RGE_Game_World;

class RGE_Terrain_Info {
public:
    char data[0x1298];
};

class RGE_Land_Info {
public:
    char data[0x1438];
};

class RGE_Object_Info {
public:
    char data[0x18C8];
};

class RGE_Elevation_Info {
public:
    char data[0xF80];
};

class RGE_Random_Map_Module {
public:
    virtual unsigned char generate();
    virtual ~RGE_Random_Map_Module();

    RGE_Random_Map_Module* parent;
    void* list;
    RGE_Map* map;
    void* map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    void* search_map;
    void* search_map_rows;
    void* stack_array;
    void* stack_offsets;
};

class RGE_RMM_Terrain_Generator : public RGE_Random_Map_Module {
public:
    char data[0x1298];
    void* map_zone;

    RGE_RMM_Terrain_Generator(RGE_Map* map, RGE_Random_Map_Module* parent,
                              RGE_Terrain_Info* info);
};

class RGE_RMM_Land_Generator : public RGE_Random_Map_Module {
public:
    char data[0x1438];

    RGE_RMM_Land_Generator(RGE_Map* map, RGE_Random_Map_Module* parent,
                           RGE_Land_Info* info);
};

class RGE_RMM_Object_Generator : public RGE_Random_Map_Module {
public:
    char data[0x18F0];

    RGE_RMM_Object_Generator(RGE_Map* map, RGE_Random_Map_Module* parent,
                             RGE_Game_World* world, RGE_Object_Info* info,
                             unsigned char add_terrain);
};

class RGE_RMM_Elevation_Generator : public RGE_Random_Map_Module {
public:
    char data[0xF80];

    RGE_RMM_Elevation_Generator(RGE_Map* map, RGE_Random_Map_Module* parent,
                                RGE_Elevation_Info* info);
};

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    RGE_Game_World* world;
    long map_type;
    long number_of_players;
    RGE_Land_Info land_info;
    RGE_Terrain_Info terrain_info;
    RGE_Object_Info object_info;
    RGE_Elevation_Info elevation_info;

    virtual unsigned char generate();
};

unsigned char RGE_RMM_Database_Controller::generate() {
    new RGE_RMM_Terrain_Generator(this->map, this, &this->terrain_info);
    new RGE_RMM_Land_Generator(this->map, this, &this->land_info);
    new RGE_RMM_Object_Generator(this->map, this, this->world,
                                 &this->object_info, 1);
    new RGE_RMM_Elevation_Generator(this->map, this, &this->elevation_info);

    return RGE_Random_Map_Module::generate();
}
