// probe 4: separate +8 master-object surface from +0C stats surface; compare directly on the stored member

#ifndef T_C_OBJ_CONTEXT_H
class TRIBE_Combat_Object_Master {
public:
    char gap_00[0x14];
    short field_14;
};

class TRIBE_Combat_Object_Sub_3C {
public:
    char gap_00[0x84];
    float field_84;
};

class TRIBE_Combat_Object_Sub_50 {
public:
    char gap_00[0x8C];
    float field_8C;
};

class TRIBE_Combat_Object_Sub {
public:
    char gap_00[0x3C];
    TRIBE_Combat_Object_Sub_3C* field_3C;
    char gap_40[0x10];
    TRIBE_Combat_Object_Sub_50* field_50;
};

class RGE_Combat_Object {
public:
    virtual unsigned char update();
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    char gap_04[0x04];
    TRIBE_Combat_Object_Master* field_08;
    TRIBE_Combat_Object_Sub* field_0C;
    char gap_10[0x34];
    float field_44;
    unsigned char field_48;
    char gap_49[0x3];
    unsigned short field_4C;

    unsigned char update();
};
#endif

unsigned char TRIBE_Combat_Object::update(void) {
    if (this->field_08->field_14 == 0x12 && this->field_48 == 2) {
        this->field_44 = this->field_0C->field_50->field_8C * this->field_0C->field_3C->field_84 + this->field_44;
        if (this->field_44 >= 100.0f) {
            this->field_44 = 100.0f;
        }
        this->field_4C = 0x22;
    }
    return RGE_Combat_Object::update();
}
