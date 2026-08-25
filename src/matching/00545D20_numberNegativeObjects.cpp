// 00545D20 RGE_Game_World::numberNegativeObjects()
#include "../world_phase2_context.h"
// PDB: World.cpp lines 3583-3585; owning range 00545D20-00545D26.
// Exact anchor: numberObjects() owns 00545D10-00545D16.
// Bytes 00545D17-00545D1F are alignment data before this body.
// Bytes 00545D27-00545D2F are alignment data before object().
// BINARY NOTE: This nonvirtual __thiscall getter reads the +0x98 field directly.
int RGE_Game_World::numberNegativeObjects() {
    return this->numberNegativeObjectsValue;
}
