// VA: 0050F090 TRIBE_Master_Combat_Object::make_new_obj
// PDB source: tm_co_ob.cpp

#ifndef TM_CO_OB_SHARED_CONTEXT
class RGE_Player;
class RGE_Static_Object {};

class TRIBE_Master_Combat_Object {
public:
    RGE_Static_Object* make_new_obj(RGE_Player* player, float x, float y, float z);
};

class TRIBE_Combat_Object : public RGE_Static_Object {
public:
    char gap[0x1C8];
    TRIBE_Combat_Object(TRIBE_Master_Combat_Object* master, RGE_Player* player, float x, float y, float z, int flag);
};
#endif

void* __cdecl operator new(unsigned int size);

RGE_Static_Object* TRIBE_Master_Combat_Object::make_new_obj(RGE_Player* player, float x, float y, float z) {
    return new TRIBE_Combat_Object(this, player, x, y, z, 1);
}
