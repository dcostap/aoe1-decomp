#include <stdlib.h>

class RGE_Armor_Weapon_Info;
class RGE_Sprite;
class RGE_Master_Action_Object;

class RGE_Master_Action_Object {
public:
    void* vtable_ptr;
    char pad_04[0xF8];

    void destroy(void);
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    RGE_Sprite* fight_sprite;
    unsigned char base_armor;
    unsigned char pad_100[1];
    short armor_num;
    RGE_Armor_Weapon_Info* armor;
    short weapon_num;
    unsigned char pad_10A[2];
    RGE_Armor_Weapon_Info* weapon;

    void destroy(void);
};

void RGE_Master_Combat_Object::destroy(void) {
    this->vtable_ptr = (void*)0x5704C0;
    if (this->weapon != 0) {
        free(this->weapon);
        this->weapon = (RGE_Armor_Weapon_Info*)0;
    }
    if (this->armor != 0) {
        free(this->armor);
        this->armor = (RGE_Armor_Weapon_Info*)0;
    }
    RGE_Master_Action_Object::destroy();
}
