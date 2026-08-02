// 004887A0 TRIBE_RMM_Database_Controller::add_shallows_module
// PDB source: rmm_tdbc.cpp, lines 593-608
// Attempt log:
// - Baseline candidate: model the proven land/shallows records and the direct
//   generator allocation/logging sequence from the original assembly.
// - Probe 1 (baseline): pointer-cursor reconstruction matched size/frame/call
//   count but chose an EBX/ESI/EDI save basin and differed from offset 0.
// - Probe 2: a declared generator destructor did not change emitted code.
// - Probe 3: replaced the intermediate base/payload gaps with the generated
//   RGE_RMM_Database_Controller and RGE_RMM_Shallows_Generator layouts; no
//   emitted change.
// - Probe 4: included <new.h> as a VC5 EH-context donor; no emitted change.
// - Probe 5: direct assignment of the allocation into shallow line 0 improved
//   local shape but added an unwanted null-path xor and was rolled back.
// - Probe 6: hoisted the generator pointer declaration; returned to the
//   baseline codegen basin.
// - Probe 7: natural indexed `land[i]` / `shallows[i + 1]` copy produced the
//   original loop's load/store/advance topology, but still uses EBX and has a
//   different aggregate stack home.
// - Probes 8-10: restored polymorphic/full controller context and removed the
//   named count; neither changed the indexed candidate.
// - Current best source reconstruction keeps the proven full layouts and the
//   period-plausible indexed record loop. Clean-source baseline remains the
//   metric-best pointer-cursor candidate (180 differing bytes); current source
//   is 183 differing bytes with 100% ordered call-set parity. Left in scratch:
//   structural prologue/register/stack-home mismatch remains unresolved.

#include <new.h>

class RGE_Map;

class RGE_Random_Map_Module {
public:
    virtual unsigned char generate();
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

class RGE_Land_Info_Line {
public:
    long land_size;
    long terrain_type;
    long x;
    long y;
    long base_size;
    long area;
    unsigned char zone;
    unsigned char pad_19[3];
    long clumpiness_factor;
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    unsigned char wall_fade;
    unsigned char pad_31[3];
};

class RGE_Land_Info {
public:
    RGE_Land_Info_Line land[99];
    long land_num;
    unsigned char base_terrain;
    unsigned char pad_1421[3];
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    unsigned char wall_fade;
    unsigned char pad_1435[3];
};

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    virtual unsigned char generate();
    virtual void add_land_module(unsigned char param);
    virtual void add_terrain_module();
    virtual void add_object_module();
    virtual void add_elevation_module();
    virtual unsigned char init(RGE_Map* map, void* world, unsigned char flag,
                               long value, unsigned char flag2);
    virtual unsigned char de_init();
    void* world;
    long map_type;
    long number_of_players;
    RGE_Land_Info land_info;
    char gap_1474_to_4f5c[0x4F5C - 0x1474];
};

class RGE_Shallows_Info_Line {
public:
    long x;
    long y;
};

class RGE_Shallows_Info {
public:
    RGE_Shallows_Info_Line shallows[99];
    long shallows_num;
};

class RGE_RMM_Shallows_Generator : public RGE_Random_Map_Module {
public:
    RGE_Shallows_Info info;
    virtual unsigned char generate();
    RGE_RMM_Shallows_Generator(RGE_Map* map, RGE_Random_Map_Module* parent,
                               RGE_Shallows_Info* info);
    ~RGE_RMM_Shallows_Generator();
};

class TDebuggingLog {
public:
    void Log(char* format, ...);
};

extern TDebuggingLog* L;
extern int __cdecl debug_rand(char* file, int line);

class TRIBE_RMM_Database_Controller : public RGE_RMM_Database_Controller {
public:
    void add_shallows_module();
};

void TRIBE_RMM_Database_Controller::add_shallows_module()
{
    RGE_RMM_Shallows_Generator* generator;
    RGE_Shallows_Info shallows_info;
    int i = 0;

    if (this->land_info.land_num > 0) {
        do {
            shallows_info.shallows[i].y = this->land_info.land[i].x;
            shallows_info.shallows[i + 1].x = this->land_info.land[i].y;
            ++i;
        } while (i < this->land_info.land_num);
    }

    generator = new RGE_RMM_Shallows_Generator(
        this->map, this, (RGE_Shallows_Info*)&shallows_info.shallows[0].y);

    L->Log("Random Map shallows initilization, rand: %d",
           debug_rand((char*)"C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x25F));
}
