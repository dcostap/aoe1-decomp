// 00545CF0 RGE_Game_World::maxNumberObjects()
// PDB: World.cpp lines 3559-3561; owning range 00545CF0-00545CF6.
// The preceding World.cpp sibling, get_scenario_info(), owns 00545CE0-00545CE4.
// Bytes 00545CE5-00545CEB are alignment data between the two siblings;
// bytes 00545CEC-00545CEF continue that padding before this body. It is not
// part of this function.
// BINARY NOTE: This nonvirtual __thiscall getter reads the +0x90 field directly.
#ifndef WORLD_TU
class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_0[0x8C];
    int maxNumberObjectsValue;
    int maxNumberObjects();
};
#endif

int RGE_Game_World::maxNumberObjects() { return this->maxNumberObjectsValue; }
