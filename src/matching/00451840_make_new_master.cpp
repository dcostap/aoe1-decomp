// first pass: direct new-expression for the EH-framed factory helper
// if this is sticky, the only real follow-up is whether /GX is required to keep the ctor/new basin
class RGE_Master_Static_Object {
public:
    char pad_00[0xB8];
};

class RGE_Master_Combat_Object : public RGE_Master_Static_Object {
public:
    char pad_B8[0x148 - 0xB8];
};

class RGE_Master_Missile_Object : public RGE_Master_Combat_Object {
public:
    unsigned char missile_type;
    unsigned char targetting_type;
    unsigned char missile_hit_info;
    unsigned char missile_die_info;
    unsigned char area_effect_specials;
    char pad_14D[0x3];
    float ballistics_ratio;

    RGE_Master_Missile_Object(RGE_Master_Missile_Object* source, int do_setup);
    RGE_Master_Static_Object* make_new_master(void);
};

RGE_Master_Static_Object* RGE_Master_Missile_Object::make_new_master(void) {
    return new RGE_Master_Missile_Object(this, 1);
}
