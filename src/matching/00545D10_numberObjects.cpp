// 00545D10 RGE_Game_World::numberObjects()
// PDB: World.cpp lines 3575-3577; owning range 00545D10-00545D16.
// Exact anchor: maxNumberNegativeObjects() owns 00545D00-00545D06.
// Bytes 00545D07-00545D0F are alignment data before this body.
// BINARY NOTE: This nonvirtual __thiscall getter reads numberObjectsValue at +0x8C.
class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_0[0x88];
    int numberObjectsValue;
    int numberObjects();
};

int RGE_Game_World::numberObjects() { return this->numberObjectsValue; }
