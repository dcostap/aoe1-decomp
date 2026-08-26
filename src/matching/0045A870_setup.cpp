// VA: 0045A870 RGE_Missile_Object::setup (5-param variant)
// PDB source: misl_obj.cpp

int RGE_Missile_Object::setup(RGE_Master_Combat_Object* param1, RGE_Player* param2,
                              float param3, float param4, float param5)
{
    RGE_Combat_Object::setup(param1, param2, param3, param4, param5);
    *(unsigned char*)((char*)this + 0x4E) = 0x3C;
    return 1;
}
