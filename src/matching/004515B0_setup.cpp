// attempt 1: direct base setup call followed by the byte and tail-field copies
// result: exact match landed after modeling the base field at +4 and the missile tail fields at +0x148..+0x150
// moved to src\matching\004515B0_setup.cpp after local validation

class RGE_Master_Missile_Object;
class RGE_Master_Combat_Object {
public:
    unsigned char pad_0[4];
    unsigned char field_4;
    unsigned char pad_5[0x148 - 0x5];

    int setup(RGE_Master_Combat_Object* other);
};

class RGE_Master_Missile_Object : public RGE_Master_Combat_Object {
public:
    unsigned char missile_type; // +0x148
    unsigned char targetting_type; // +0x149
    unsigned char missile_hit_info; // +0x14A
    unsigned char missile_die_info; // +0x14B
    unsigned char area_effect_specials; // +0x14C
    unsigned char pad_14D[3];
    float ballistics_ratio; // +0x150

    int setup(RGE_Master_Missile_Object* other);
};

int RGE_Master_Missile_Object::setup(RGE_Master_Missile_Object* other) {
    RGE_Master_Combat_Object::setup(other);
    this->field_4 = 0x3C;
    this->missile_type = other->missile_type;
    this->targetting_type = other->targetting_type;
    this->missile_hit_info = other->missile_hit_info;
    this->missile_die_info = other->missile_die_info;
    this->area_effect_specials = other->area_effect_specials;
    this->ballistics_ratio = other->ballistics_ratio;
    return 1;
}
