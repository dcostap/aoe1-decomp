#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Armor_Weapon_Info {
public:
    short type;
    short value;
};

class RGE_Master_Combat_Object {
public:
    unsigned char gap_00[0x108];
    short weapon_num;
    unsigned char gap_10A[0x2];
    RGE_Armor_Weapon_Info* weapon;
    unsigned char gap_110_to_13E[0x2E];
    short orig_weapon;
};

class RGE_Combat_Object {
public:
    int id;
    RGE_Master_Combat_Object* master_obj;

    virtual void get_weapon(short* weapon, short* original_weapon);
};
#endif

void RGE_Combat_Object::get_weapon(short* weapon, short* original_weapon) {
    int i;

    *weapon = 0;
    for (i = 0; i < master_obj->weapon_num; ++i) {
        if (master_obj->weapon[i].value > *weapon) {
            *weapon = master_obj->weapon[i].value;
        }
    }
    *original_weapon = master_obj->orig_weapon;
}
