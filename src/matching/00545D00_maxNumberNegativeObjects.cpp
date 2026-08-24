// 00545D00 RGE_Game_World::maxNumberNegativeObjects()
// PDB: World.cpp lines 3567-3569; owning range 00545D00-00545D06.
// Exact anchors: get_scenario_info() is 00545CE0-00545CE4;
// maxNumberObjects() is 00545CF0-00545CF6.
// Alignment data fills 00545CE5-00545CEF and 00545D07-00545D0F.
// BINARY NOTE: This nonvirtual __thiscall getter reads the +0x9C field directly.
#ifndef WORLD_TU
class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_0[0x98];
    int maxNumberNegativeObjectsValue;
    int maxNumberNegativeObjects();
};
#endif

int RGE_Game_World::maxNumberNegativeObjects() {
    return this->maxNumberNegativeObjectsValue;
}
