class RGE_Armor_Weapon_Info {
public:
    short type;
    short value;
};

class RGE_Master_Combat_Object {
public:
    unsigned char gap_00[0x100];
    unsigned char base_armor;
    unsigned char gap_101[0x1];
    short armor_num;
    RGE_Armor_Weapon_Info* armor;
    unsigned char gap_108_to_13C[0x34];
    short orig_armor;
};

class RGE_Combat_Object {
public:
    int id;
    RGE_Master_Combat_Object* master_obj;

    virtual void get_armor(short* armor, short* original_armor);
};

void RGE_Combat_Object::get_armor(short* armor, short* original_armor) {
    int i;

    *armor = master_obj->base_armor;
    for (i = 0; i < master_obj->armor_num; ++i) {
        if (master_obj->armor[i].value > *armor) {
            *armor = master_obj->armor[i].value;
        }
    }
    *original_armor = master_obj->orig_armor;
}
