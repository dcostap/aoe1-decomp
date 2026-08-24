// VA: 00450680 RGE_Master_Combat_Object::~RGE_Master_Combat_Object (76B)
// m_co_obj.cpp lines 268-280.
// The prior scratch body named this operation destroy(), which did not define
// the PDB-owned destructor. This source now uses the authentic destructor
// owner and leaves its inherited base destruction implicit in the body shape.

#ifndef RGE_MCO_OBJ_SHARED_CONTEXT
#include <stdlib.h>

class RGE_Armor_Weapon_Info;
class RGE_Sprite;

class RGE_Master_Action_Object {
public:
    virtual ~RGE_Master_Action_Object();
    char pad_04[0xF8];
    void destroy(void);
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    virtual ~RGE_Master_Combat_Object();
    RGE_Sprite* fight_sprite;
    unsigned char base_armor;
    unsigned char pad_100[1];
    short armor_num;
    RGE_Armor_Weapon_Info* armor;
    short weapon_num;
    unsigned char pad_10A[2];
    RGE_Armor_Weapon_Info* weapon;
};
#endif

RGE_Master_Combat_Object::~RGE_Master_Combat_Object() {
    if (this->weapon != 0) {
        free(this->weapon);
        this->weapon = (RGE_Armor_Weapon_Info*)0;
    }
    if (this->armor != 0) {
        free(this->armor);
        this->armor = (RGE_Armor_Weapon_Info*)0;
    }
}
