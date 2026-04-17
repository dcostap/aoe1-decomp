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
};

class RGE_Combat_Object {
public:
    int id;
    RGE_Master_Combat_Object* master_obj;

    virtual float damageCapability();
};

float RGE_Combat_Object::damageCapability() {
    float total;
    short* value;
    int count;

    total = 0.0f;
    count = master_obj->weapon_num;
    if (count > 0) {
        value = &master_obj->weapon[0].value;
        do {
            if ((float)(int)*value > 0.0f) {
                total = total + (float)(int)*value;
            }
            value = value + 2;
            count = count - 1;
        } while (count != 0);
    }
    return total;
}
