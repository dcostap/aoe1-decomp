// VA: 00483200 ~RGE_RMM_Database_Controller
//
// Attempt 1: compile error, wrong world type.
// Attempt 2: fixed world type, but the destructor body was still only a stub.
// Clean reconstruction: the owned map table is an array of 0x48-byte records;
// each record owns four optional arrays, followed by the table itself.  The
// class owns the map_info aggregate at +0x4F54 and derives from the real
// RGE_Random_Map_Module base so its destructor tail is emitted naturally.
// Probe 1: a named count and entry pointer created a stack home and preserved
// the entry across all four frees; the executable instead rereads map_info and
// the map base at each field group.
// Probe 2: direct member rereads plus separate positive guards restored the
// original ESI-held this pointer and repeated map-base loads (166 differing
// bytes, but still an 8-byte structural shortfall).
// Probe 3: moving the loop index into the inner guard did not change codegen.
// Probe 4: a natural counted for loop restored the preheader test, delayed EDI
// save, exact block layout, and all 213 bytes.
// Probe 5: canonical exact-sized aggregate names for the four owned info blocks
// and the known base field order preserved the exact output.

#include <stdlib.h>

class RGE_Map;
class RGE_Game_World;
class RGE_Tile;
class RGE_Random_Map_Module_List;
struct Map_Stack;

class RGE_Random_Map_Module {
public:
    virtual ~RGE_Random_Map_Module();
    RGE_Random_Map_Module* parent;
    RGE_Random_Map_Module_List* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    Map_Stack* stack_array;
    unsigned char** search_map_rows;
    Map_Stack** stack_offsets;

};

struct RGE_Land_Data {
    long map_edge_buffer[4];
    long map_edge_fade;
    long land_placement_edge;
    long base_terrain;
    long grown_land_percent;
    long id;
    long land_num;
    void* land;
};

struct RGE_Terrain_Data {
    long terrain_num;
    void* terrain;
};

struct RGE_Object_Data {
    long object_num;
    void* objects;
};

struct RGE_Elevation_Data {
    long elevation_num;
    void* elevation;
};

struct RGE_Map_Data_Entry {
    long map_id;
    RGE_Land_Data land_info;
    RGE_Terrain_Data terrain_info;
    RGE_Object_Data object_info;
    RGE_Elevation_Data elevation_info;
};

struct RGE_Map_Data {
    long map_num;
    RGE_Map_Data_Entry* maps;
};

struct RGE_Land_Info {
    char data[0x1438];
};

struct RGE_Terrain_Info {
    char data[0x1298];
};

struct RGE_Object_Info {
    char data[0x18C8];
};

struct RGE_Elevation_Info {
    char data[0xF80];
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
    RGE_Map_Data map_info;

    virtual ~RGE_RMM_Database_Controller();
};

RGE_RMM_Database_Controller::~RGE_RMM_Database_Controller() {
    if (this->map_info.map_num > 0) {
        if (this->map_info.maps != 0) {
            for (int i = 0; i < this->map_info.map_num; ++i) {
                if (this->map_info.maps[i].land_info.land_num > 0) {
                    free(this->map_info.maps[i].land_info.land);
                }
                if (this->map_info.maps[i].terrain_info.terrain_num > 0) {
                    free(this->map_info.maps[i].terrain_info.terrain);
                }
                if (this->map_info.maps[i].object_info.object_num > 0) {
                    free(this->map_info.maps[i].object_info.objects);
                }
                if (this->map_info.maps[i].elevation_info.elevation_num > 0) {
                    free(this->map_info.maps[i].elevation_info.elevation);
                }
            }

            free(this->map_info.maps);
            this->map_info.map_num = 0;
        }
    }
}
