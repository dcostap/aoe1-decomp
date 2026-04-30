// first pass: EH-framed factory that allocates a TRIBE_Building_Object with operator new(0x204)
// and calls TRIBE_Building_Object::TRIBE_Building_Object(master, player, x, y, z, param_5, 1)
// /GX required for exact EH frame
#include "..\..\include\game_globals.h"

// Local surface for the master object class chain (sizeof = 0x17C)
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char pad_04[0xB8 - 0x4];
};

class RGE_Master_Combat_Object : public RGE_Master_Static_Object {
public:
    char pad_B8[0x148 - 0xB8];
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    char pad_148[0x17C - 0x148];
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4, int param_5);
};

// sizeof = 0x204 to match operator new(0x204)
class RGE_Static_Object {
public:
    char pad[0x204];
};

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    TRIBE_Building_Object(TRIBE_Master_Building_Object* master, RGE_Player* player, float x, float y, float z, int param_6, int param_7);
};

RGE_Static_Object* TRIBE_Master_Building_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4, int param_5) {
    return new TRIBE_Building_Object(this, param_1, param_2, param_3, param_4, param_5, 1);
}
