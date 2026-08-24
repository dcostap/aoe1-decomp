// VA: 004CA0F0 TRIBE_Combat_Object::TRIBE_Combat_Object (7-param ctor, EH-framed)
// PDB source: t_c_obj.cpp

#ifndef T_C_OBJ_CONTEXT_H
class RGE_Combat_Object {
public:
    virtual ~RGE_Combat_Object();
    RGE_Combat_Object(void* master, void* player, float x, float y, float z, int flag);
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    TRIBE_Combat_Object(void* master, void* player, float x, float y, float z, int flag);
    int setup(void* master, void* player, float x, float y, float z);
};
#endif

TRIBE_Combat_Object::TRIBE_Combat_Object(void* master, void* player, float x, float y, float z, int flag)
    : RGE_Combat_Object(master, player, x, y, z, 0)
{
    *(void**)this = (void*)0x574A20;
    if (flag != 0) {
        this->setup(master, player, x, y, z);
    }
}
