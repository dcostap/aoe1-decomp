// VA: 00450A00 modify (265B)
// m_co_obj.cpp
// Attempt log:
// - baseline reconstruction: the combat-object attribute switch and packed
//   armor/weapon table update use named fields and typed four-byte records.
// - same-TU nonvirtual declaration surface was codegen-neutral.
// - hoisted/narrowed high-byte index variants expanded the body to 316-348B;
//   the named 16-bit index remains the clean source reconstruction.
// - unsigned-char case-16 conversion produced the observed movzx locally but
//   crossed the original boundary; it was rolled back.
// - shared packed/table locals and combined guards were diagnostic only: they
//   changed CFG/compare topology despite one modest raw-diff improvement.
// - left in scratch: 7 calls and size/frame match; remaining drift is packed
//   index extraction, case-16 zero-extension, and default-call scheduling.
// - Main-agent audit restored the canonical base destructor/copy/modify virtual
//   prefix; the validated codegen gap is unchanged.

class RGE_Sprite;

class RGE_Armor_Weapon_Info {
public:
    short type;
    short value;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, unsigned char attribute);
    char gap_04[0xB4];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char gap_BC[0x1C];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_D8[0x24];
    virtual void modify(float value, unsigned char attribute);
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    RGE_Sprite* fight_sprite;
    unsigned char base_armor;
    unsigned char gap_101[1];
    short armor_num;
    RGE_Armor_Weapon_Info* armor;
    short weapon_num;
    unsigned char gap_10A[2];
    RGE_Armor_Weapon_Info* weapon;
    short defense_terrain_bonus;
    unsigned char gap_112[2];
    float weapon_range;
    float area_effect_range;
    unsigned char area_effect_level;
    unsigned char gap_11D[3];
    float speed_of_attack;
    short missile_id;
    short base_hit_chance;

    virtual void modify(float value, unsigned char attribute);
};

void RGE_Master_Combat_Object::modify(float value, unsigned char attribute) {
    switch (attribute) {
    case 8: {
        long packed = (long)value;
        if (armor != 0) {
            unsigned short index = (unsigned short)(packed >> 8);
            if ((int)index < (int)armor_num) {
                armor[index].value = (short)(packed & 0xff);
            }
        }
        break;
    }
    case 9: {
        long packed = (long)value;
        if (weapon != 0) {
            unsigned short index = (unsigned short)(packed >> 8);
            if ((int)index < (int)weapon_num) {
                weapon[index].value = (short)(packed & 0xff);
            }
        }
        break;
    }
    case 10:
        speed_of_attack = value;
        break;
    case 11:
        base_hit_chance = (short)value;
        break;
    case 12:
        weapon_range = value;
        break;
    case 15:
        base_armor = (unsigned char)value;
        break;
    case 16:
        missile_id = (short)value;
        break;
    case 18:
        defense_terrain_bonus = (short)value;
        break;
    default:
        RGE_Master_Action_Object::modify(value, attribute);
        break;
    }
}
