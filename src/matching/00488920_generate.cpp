// 00488920 RGE_RMM_Terrain_Generator::generate
// Source: rmm_terr.cpp lines 32-54
// Attempt log:
// Probe 1: packet-derived natural source with terrain table and by-value 0x20 struct call.

struct RGE_Terrain_Info_Line {
    int a0; int a4; int a8; int aC; int a10; int a14; int a18; int a1C;
};

class RGE_Zone_Map_List {
public:
    long create_zone_map(float* table, long count);
    void* get_zone_map(long id);
};

class RGE_RMM_Terrain_Generator {
public:
    virtual unsigned char generate();
    char gap_04[0x08];
    void* world; // +0C, zonemap list at +8DC4
    char gap_10[0x20];
    RGE_Terrain_Info_Line info[99]; // +30
    char gap_after[0x24];
    int terrain_num; // +C90 approximate via padding below not used by layout? 
    void generate_modifiers();
    unsigned char base_terrain_generate(RGE_Terrain_Info_Line line);
    void check_borders();
};

unsigned char RGE_RMM_Terrain_Generator::generate()
{
    long index;
    float terrain_table[99];

    this->generate_modifiers();
    index = 0;
    do {
        terrain_table[index] = (float)index;
        index++;
    } while (index < 99);

    RGE_Zone_Map_List* zml = *(RGE_Zone_Map_List**)((char*)this->world + 0x8DC4);
    long zid = zml->create_zone_map(terrain_table, 99);
    *(void**)((char*)this + 0x12C8) = (*(RGE_Zone_Map_List**)((char*)this->world + 0x8DC4))->get_zone_map(zid);

    index = 0;
    if (*(int*)((char*)this + 0xC90) > 0) {
        RGE_Terrain_Info_Line* p = (RGE_Terrain_Info_Line*)((char*)this + 0x30);
        do {
            this->base_terrain_generate(*p);
            index++;
            p++;
        } while (index < *(int*)((char*)this + 0xC90));
    }
    this->check_borders();
    return 1;
}
