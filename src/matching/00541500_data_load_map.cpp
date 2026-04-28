// 00541500 RGE_Game_World::data_load_map
// Size: 141 bytes
// FLAGS: /GX (EH frame)

void* operator new(unsigned int size);

class RGE_Sound;

class RGE_Map {
public:
    RGE_Map(char* p2, char* p3, char* p4, short p5, short p6, short p7, RGE_Sound** p8);
    void load_terrain_obj_types(char* a);
    char gap_00[0x8DD0 - 4]; // sizeof = 0x8DD0
    int dummy;
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;              // +0x28

    void data_load_map(char* p1, char* p2, char* p3, char* p4, short p5, short p6, short p7, RGE_Sound** p8, char* p9);
};

void RGE_Game_World::data_load_map(char* p1, char* p2, char* p3, char* p4, short p5, short p6, short p7, RGE_Sound** p8, char* p9) {
    RGE_Map* m;

    m = new RGE_Map(p1, p3, p4, p5, p6, p7, p8);
    this->map = m;
    m->load_terrain_obj_types(p9);
}
