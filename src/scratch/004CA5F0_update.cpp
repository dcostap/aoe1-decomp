// compact combat-update shape first
// tried direct add/clamp, then temp-based clamp, then typed sub-objects for the +0x84/+0x8C reads
// remaining mismatch stayed in the FPU compare basin: VC5 keeps materializing the clamp compare differently than the original fcom/fnstsw sequence

class RGE_Stat_Object_Sub_3C {
public:
    char pad_00[0x84];
    float field_84;
};

class RGE_Stat_Object_Sub_50 {
public:
    char pad_00[0x8C];
    float field_8C;
};

class RGE_Stat_Object_Sub {
public:
    char pad_00[0x14];
    short field_14;
    char pad_16[0x26];
    RGE_Stat_Object_Sub_3C* field_3C;
    char pad_40[0x10];
    RGE_Stat_Object_Sub_50* field_50;
};

class RGE_Combat_Object {
public:
    unsigned char update();
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    char pad_00[0x8];
    RGE_Stat_Object_Sub* unit;
    char pad_0C[0x38];
    float field_44;
    unsigned char field_48;
    char pad_49[0x3];
    unsigned short field_4C;

    unsigned char update();
};

unsigned char TRIBE_Combat_Object::update(void) {
    if (this->unit->field_14 == 0x12 && this->field_48 == 2) {
        float fVar1 = this->unit->field_50->field_8C * this->unit->field_3C->field_84 + this->field_44;
        this->field_44 = fVar1;
        if (100.0f <= fVar1) {
            this->field_44 = 100.0f;
        }
        this->field_4C = 0x22;
    }
    return RGE_Combat_Object::update();
}
