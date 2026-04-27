// tried the direct new-expression first; /GX gave the right EH frame but the null-path branch still lands too late
// tried a temp plus explicit if/else, and then an operator_new + placement-new spelling; both kept the same branch basin
// remaining mismatch is localized to the null-path branch target / epilog shape, not the ctor call or the store target
class RGE_Sound;
class TRIBE_Map;

extern void* __cdecl operator_new(unsigned int size);
inline void* __cdecl operator new(unsigned int, void* place) {
    return place;
}

class TRIBE_World {
public:
    char pad_00[0x28];
    TRIBE_Map* map;
    char pad_2C[0x4];
    RGE_Sound** sounds;

    void map_init(int param_1, void* param_2);
};

class TRIBE_Map {
public:
    char pad_00[0xB5F8];
    TRIBE_Map(int param_1, RGE_Sound** param_2, char param_3);
};

void TRIBE_World::map_init(int param_1, void* param_2) {
    TRIBE_Map* map = (TRIBE_Map*)operator_new(0xB5F8);
    if (map != 0) {
        map = new (map) TRIBE_Map(param_1, this->sounds, 1);
    } else {
        map = 0;
    }
    this->map = map;
}
