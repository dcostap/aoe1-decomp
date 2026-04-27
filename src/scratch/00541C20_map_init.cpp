// tried the natural new+ctor assignment shape against the EH prolog
// tried the decompiler-style temp/if-else shape; the first mismatch moved to the fail/merge block
// tried a placement-new helper; it regressed into a smaller size basin and then compilation friction
// leaving this in scratch because the remaining issue is still prolog/codegen basin drift, not behavior
#include "..\..\include\game_types.h"

class RGE_Map {
public:
    char pad_00[0x8DD0];
    RGE_Map(int param_1, RGE_Sound** sounds, char param_3);
};

class RGE_Game_World {
public:
    char pad_00[0x28];
    RGE_Map* map;
    char pad_2C[0x4];
    RGE_Sound** sounds;

    void map_init(int param_1, TSound_Driver* param_2);
};

void RGE_Game_World::map_init(int param_1, TSound_Driver* param_2) {
    this->map = new RGE_Map(param_1, this->sounds, 1);
}
