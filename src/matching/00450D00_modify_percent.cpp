// VA: 00450D00 modify_percent (234B)
// m_co_obj.cpp
// RGE_Master_Combat_Object::modify_percent(float value, unsigned char attribute)
// virtual slot 0x10; overrides RGE_Master_Action_Object::modify_percent.
// Jump-table switch over attributes 6..18; unmatched attributes forward to the
// base implementation RGE_Master_Action_Object::modify_percent (0044F850).

class RGE_Master_Moving_Object {
public:
    char gap_00[0xC4];
    float turn_speed; // +0xC4
    char gap_C8[0x10]; // to 0xD8
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_D8[0x24]; // to 0xFC
    void modify_percent(float value, unsigned char attribute);
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    char gap_FC[4];                  // fight_sprite
    unsigned char base_armor;        // +0x100
    char gap_101[0xF];               // to 0x110
    short defense_terrain_bonus;     // +0x110
    char gap_112[2];
    float weapon_range;              // +0x114
    float area_effect_range;         // +0x118
    unsigned char area_effect_level; // +0x11C
    char gap_11D[3];
    float speed_of_attack;           // +0x120
    short missile_id;                // +0x124
    short base_hit_chance;           // +0x126

    void modify_percent(float value, unsigned char attribute);
};

void RGE_Master_Combat_Object::modify_percent(float value, unsigned char attribute) {
    switch (attribute) {
    case 6:
        turn_speed = (float)((double)value * (double)turn_speed);
        break;
    case 10:
        speed_of_attack = (float)((double)value * (double)speed_of_attack);
        break;
    case 11:
        base_hit_chance = (short)((float)base_hit_chance * value);
        break;
    case 12:
        weapon_range = (float)((double)value * (double)weapon_range);
        break;
    case 15:
        base_armor = (unsigned char)((float)missile_id * value);
        break;
    case 16:
        missile_id = (short)((float)missile_id * value);
        break;
    case 18:
        defense_terrain_bonus = (short)value;
        break;
    default:
        RGE_Master_Action_Object::modify_percent(value, attribute);
        break;
    }
}
