// 00545D30 RGE_Game_World::object(int) -> RGE_Static_Object*
// PDB: C:\msdev\work\age1_x1\World.cpp lines 3591-3603.
// Decorated owner: ?object@RGE_Game_World@@QAEPAVRGE_Static_Object@@H@Z.
// BINARY NOTE: This function owns 00545D30-00545D73. Bytes 00545D74-00545D7F
// are alignment data before object_ptr() at 00545D80.
// Exact anchor: numberNegativeObjects() owns 00545D20-00545D26; bytes
// 00545D27-00545D2F are alignment data before this body.
// BINARY NOTE: Direct fields are objectsValue +0x88, numberObjectsValue +0x8C,
// maxNumberObjectsValue +0x90, negativeObjectsValue +0x94,
// numberNegativeObjectsValue +0x98, and maxNumberNegativeObjectsValue +0x9C.
#ifndef WORLD_TU
class RGE_Static_Object;

class RGE_Game_World {
public:
    char gap_00[0x88];
    RGE_Static_Object** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    RGE_Static_Object** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;

    RGE_Static_Object* object(int index);
};
#endif

RGE_Static_Object* RGE_Game_World::object(int index) {
    int neg_index;
    if (index < 0) {
        neg_index = -index;
        if (neg_index < this->maxNumberNegativeObjectsValue) {
            return this->negativeObjectsValue[neg_index];
        }
    }
    if (index > -1 && index < this->maxNumberObjectsValue) {
        return this->objectsValue[index];
    }
    return 0;
}
