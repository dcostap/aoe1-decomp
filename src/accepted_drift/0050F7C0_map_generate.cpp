// ACCEPTED_DRIFT: argument-load/store order drift only; param1 still goes to +8DD4, param2 to +8DD8, param4 to +8DE0, and the same param3 is pushed to the generator call.
// tried player/world parameter order and the reversed order; VC5 kept the same early arg-load basin
// tried both semantic field names and anonymous field_8DD4/field_8DD8 surfaces; no startup-order change
// fixed the virtual-class 4-byte layout issue and identified player/world/zones at +8DD4/+8DD8/+8DE0 with one dword gap at +8DDC
// leaving this in scratch because the remaining mismatch is localized to the first two arg loads and paired store order before the helper call
class RGE_Player;
class RGE_Game_World;
struct RGE_Player_Info;

class TRIBE_Map {
public:
    char gap_00[0x8DD0];
    void* field_8DD4;
    void* field_8DD8;
    int field_8DDC;
    unsigned char* zones;

    virtual void map_generate(RGE_Game_World* world, RGE_Player* player, RGE_Player_Info* info, unsigned char* zones);
    void map_generate(RGE_Player_Info* info);
};

void TRIBE_Map::map_generate(RGE_Game_World* world, RGE_Player* player, RGE_Player_Info* info, unsigned char* zones) {
    this->field_8DD8 = player;
    this->field_8DD4 = world;
    this->zones = zones;
    this->map_generate(info);
}
