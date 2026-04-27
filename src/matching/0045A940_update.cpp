// VA: 0045A940 RGE_Missile_Object::update
// PDB source: misl_obj.cpp
// Tail jump to base::update

struct RGE_Combat_Object {
    unsigned char update();
};

struct RGE_Missile_Object : public RGE_Combat_Object {
    unsigned char update();
};

unsigned char RGE_Missile_Object::update()
{
    return RGE_Combat_Object::update();
}
