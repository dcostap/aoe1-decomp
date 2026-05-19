// 0052E2B0 TRIBE_World::data_load_map
// PDB source: tworld.cpp lines 201-206

class RGE_Sound;

class TRIBE_Map {
public:
    char gap_00[0xB5F8];
    TRIBE_Map(char* p1, char* p2, char* p3, char* p4, short p5, short p6, short p7, RGE_Sound** p8);
    void load_terrain_obj_types(char* filename);
};

class TRIBE_World {
public:
    char gap_00[0x28];
    TRIBE_Map* map; // +0x28

    void data_load_map(char* p1, char* p2, char* p3, char* p4, short p5, short p6, short p7, RGE_Sound** p8, char* p9);
};

void TRIBE_World::data_load_map(char* p1, char* p2, char* p3, char* p4, short p5, short p6, short p7, RGE_Sound** p8, char* p9)
{
    TRIBE_Map* m = new TRIBE_Map(p1, p2, p3, p4, p5, p6, p7, p8);
    this->map = m;
    m->load_terrain_obj_types(p9);
}
