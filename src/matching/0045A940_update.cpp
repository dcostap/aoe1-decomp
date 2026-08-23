// VA: 0045A940 RGE_Missile_Object::update
// PDB source: misl_obj.cpp
// Tail jump to base::update

#ifndef RGE_MISL_OBJ_SHARED_CONTEXT
struct RGE_Combat_Object {
    unsigned char update();
};

struct RGE_Missile_Object : public RGE_Combat_Object {
    unsigned char update();
};
#endif

unsigned char RGE_Missile_Object::update()
{
    return RGE_Combat_Object::update();
}
