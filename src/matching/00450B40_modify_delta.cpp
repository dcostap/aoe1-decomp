// VA: 00450B40 modify_delta (391B)
// m_co_obj.cpp
//
// The combat-master fields below retain the period class hierarchy and the
// proven 4-byte armor/weapon record surface.  In particular, the two arrays
// are arrays of { short type; short value; }, not byte-offset cursors.
//
// Attempt log:
// - Restored the same-TU case order from the PDB bands (8, 9, 6, 10, 11,
//   12, 15, 16, 18); this fixed the jump-table handler order and function
//   size.
// - The best natural scan is one bounded for over an unsigned-short index,
//   with an int count and promoted record-type comparison.  It preserves the
//   391-byte boundary, all seven calls, and the original loop CFG.
// - Tried guarded while/do-while forms, a duplicated outer count guard,
//   widened/narrow target locals, and explicit target truncation.  They either
//   duplicate the count test, fold the first indexed load differently, or
//   compile identically.  Remaining drift is the early target/pointer
//   scheduling and the local handler-body liveness around the two scans.
// - Exact breakthrough: declare each packed target as an unsigned short before
//   the table pointer and initialize it from (encoded >> 8) & 0xff.  This is a
//   natural packed-attribute source shape and recovers the original VC5 AH,
//   redundant ffff-mask, scan, and handler scheduling exactly.

class RGE_Sprite;

class RGE_Armor_Weapon_Info {
public:
    short type;
    short value;
};

class RGE_Master_Moving_Object {
public:
    virtual ~RGE_Master_Moving_Object();
    char gap_04[0xC0];
    float turn_speed;
    char gap_C8[0x10];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_D8[0x24];

    void modify_delta(float value, unsigned char attribute);
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

    void modify_delta(float value, unsigned char attribute);
};

void RGE_Master_Combat_Object::modify_delta(float value,
                                             unsigned char attribute) {
    switch (attribute) {
    case 8: {
        int encoded = (int)value;
        unsigned short type = (unsigned short)((encoded >> 8) & 0xff);
        RGE_Armor_Weapon_Info* entries = armor;
        if (entries != 0) {
            int count = armor_num;
            unsigned short index = 0;
            for (; index < count; ++index) {
                if ((int)entries[index].type == type) {
                    entries[index].value += (short)(encoded & 0xff);
                    return;
                }
            }
        }
        break;
    }
    case 9: {
        int encoded = (int)value;
        unsigned short type = (unsigned short)((encoded >> 8) & 0xff);
        RGE_Armor_Weapon_Info* entries = weapon;
        if (entries != 0) {
            int count = weapon_num;
            unsigned short index = 0;
            for (; index < count; ++index) {
                if ((int)entries[index].type == type) {
                    entries[index].value += (short)(encoded & 0xff);
                    return;
                }
            }
        }
        break;
    }
    case 6:
        turn_speed = (float)((double)value + (double)turn_speed);
        break;
    case 10:
        speed_of_attack = (float)((double)value + (double)speed_of_attack);
        break;
    case 11:
        base_hit_chance += (short)(long)value;
        break;
    case 12:
        weapon_range = (float)((double)value + (double)weapon_range);
        break;
    case 15:
        base_armor += (unsigned char)(long)value;
        break;
    case 16:
        missile_id += (short)(long)value;
        break;
    case 18:
        defense_terrain_bonus = (short)(long)value;
        break;
    default:
        RGE_Master_Action_Object::modify_delta(value, attribute);
        break;
    }
}
