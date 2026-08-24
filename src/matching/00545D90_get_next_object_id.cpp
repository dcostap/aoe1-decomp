// VA: 00545D90 RGE_Game_World::get_next_object_id (62B)
// PDB owner: public: long __thiscall RGE_Game_World::get_next_object_id(void)
// Decorated owner: ?get_next_object_id@RGE_Game_World@@QAEJXZ.
// PDB source: C:\msdev\work\age1_x1\World.cpp lines 3636-3651.
// Owning range: 00545D90-00545DCD. The next World.cpp sibling begins at
// 00545DD0. Bytes 00545D74-00545D7F are padding after object() and before the
// exact object_ptr() wrapper at 00545D80; do not assign them to this function.
// BINARY NOTE: The loop reads the canonical objectsValue field at +0x88 and
// tests maxNumberObjectsValue - 1 directly against next_object_id. That direct
// expression preserves the original VC5 register and save order.
// Exact-finish: the direct member bound expression is required; a named bound
// local emits the same behavior but not the original bytes.

#ifndef WORLD_TU
class RGE_Static_Object;

class RGE_Game_World {
public:
    char gap_00[0x68];
    int next_object_id;                     // +0x68
    char gap_6C[0x04];                      // +0x6C
    int scenario_object_id;                 // +0x70
    unsigned char scenario_object_flag;     // +0x74
    char gap_75[0x13];                      // +0x75-0x87
    RGE_Static_Object** objectsValue;       // +0x88
    char gap_8C[0x04];                      // +0x8C-0x8F
    int maxNumberObjectsValue;              // +0x90

    long get_next_object_id();
};
#endif

long RGE_Game_World::get_next_object_id() {
    if (!this->scenario_object_flag) {
        for (; this->maxNumberObjectsValue - 1 >= this->next_object_id &&
               this->objectsValue[this->next_object_id] != 0;
             this->next_object_id++) {}

        int result = this->next_object_id;
        this->next_object_id = result + 1;
        return result;
    }
    return this->scenario_object_id;
}
