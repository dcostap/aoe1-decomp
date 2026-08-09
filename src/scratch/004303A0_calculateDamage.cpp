// 004303A0 RGE_Combat_Object::calculateDamage
// Source: com_obj.cpp lines 433-466, size 213 bytes
//
// Attempt log:
// Prior worker: raw-offset variants reached a 7-byte edit diff but loaded the
// armor table into EBX before saving EBP; nine probes did not change that basin.
// 1 baseline: raw-offset source, 214-byte rebuild; armor pointer in EBX.
// 2 typed layout: named master/tile/player/world/table fields improved the
// diff by 15 bytes but kept the same prologue basin.
// 3 typed armor records: corrected the scan stride to sizeof(RGE_Armor_Weapon_Info)
// and recovered the exact inner-loop shape; codegen remained 214 bytes.
// 4 full same-TU virtual surface: duplicate codegen.
// 5 split terrain/world/table locals: duplicate codegen.
// 6 swapped armor/count declarations: duplicate codegen.
// 7 register-qualified armor pointer: duplicate codegen.
// 8/9 scoped armor pointer: worsened to a 203-byte diff and was rolled back.
// 10 inherited static-object field surface: duplicate of the best typed basin.
//
// Fresh exact pass (orch-luna-4303a0-w3): same-TU donors 00430320/004304B0/
// 00430510 and ABI evidence confirmed the virtual five-argument float signature,
// 4-byte armor records, signed short defense bonus, signed short armor count,
// and int promoted arithmetic. A widened terrain-class temporary was codegen
// neutral. Widening the defense bonus to int removed one byte but changed the
// proven short-load/test and was rolled back. A diagnostic top-level
// `int weaponIndex = weaponKind` reached 38 strict differing bytes (213 bytes,
// 71.62% exact-block coverage) but retained an extra promoted index and did not
// recover the original terrain schedule; declaration reordering and register
// hints were codegen duplicates. The diagnostic form was rolled back.
// Final natural reconstruction remains 169 strict differing bytes (214 emitted
// bytes vs 213), with exact calls/CFG and the localized armor-pointer register
// basin unresolved; no source-only register steering retained.
// Best reconstruction: canonical master armor fields at +100/+102/+104/+110,
// tile terrain bitfield at +1C/+5, owner world at +0C/+3C, and world terrain
// rows at +54, expressed with named types and ordinary loops. Remaining drift
// is compiler register scheduling: original saves EBP then loads armor into it,
// while VC5 loads armor into EBX before the EBP save; downstream terrain-index
// registers follow that choice. Left in scratch after the bounded session.
// Fresh worker: declaration-after-terrain reached a 76-byte diff by delaying
// armor loads to loop entry; direct member armor scan worsened to 210 bytes and
// was rolled back. The clean typed candidate remains authoritative.
// Main-agent audit restored canonical polymorphic master/world/player/static
// ownership while retaining the natural armor and terrain-table loops.

extern float FLOAT_1_0;
extern float FLOAT_0_0;
extern double DOUBLE_0_0;

struct RGE_Armor_Weapon_Info {
    short type;
    short value;
};

struct RGE_Master_Combat_Object {
    virtual ~RGE_Master_Combat_Object();
    unsigned char gap_04[0xFC];
    unsigned char base_armor;
    unsigned char gap_101[0x1];
    short armor_num;
    RGE_Armor_Weapon_Info* armor;
    short weapon_num;
    unsigned char gap_10A[0x2];
    RGE_Armor_Weapon_Info* weapon;
    short defense_terrain_bonus;
};

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type : 5;
};

struct RGE_Game_World {
    virtual ~RGE_Game_World();
    unsigned char gap_04[0x50];
    float** terrains;
};

struct RGE_Player {
    virtual ~RGE_Player();
    unsigned char gap_04[0x38];
    RGE_Game_World* world;
};

struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    virtual void slot_04();
    virtual void slot_08();
    virtual void slot_0C();
    virtual void slot_10();
    virtual void slot_14();
    virtual void slot_18();
    virtual void slot_1C();
    virtual void slot_20();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_2C();
    virtual void slot_30();
    virtual void slot_34();
    virtual void slot_38();
    virtual void slot_3C();
    virtual void slot_40();
    virtual void slot_44();
    virtual void slot_48();
    virtual void slot_4C();
    virtual void slot_50();
    virtual void slot_54();
    virtual void slot_58();
    virtual void slot_5C();
    virtual void slot_60();
    virtual void slot_64();
    virtual void slot_68();
    virtual void slot_6C();
    virtual void damage(int param_1, RGE_Armor_Weapon_Info* param_2,
                        float param_3, RGE_Player* param_4, RGE_Static_Object* param_5);
    virtual float calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2,
                                  float param_3, RGE_Player* param_4, RGE_Static_Object* param_5);
    virtual void slot_78();
    virtual void slot_7C();
    virtual void slot_80();
    virtual void slot_84();
    virtual void slot_88();
    virtual void slot_8C();
    virtual void slot_90();
    virtual void slot_94();
    virtual void slot_98();
    virtual void slot_9C();
    virtual void slot_A0();
    virtual void slot_A4();
    virtual void slot_A8();
    virtual void slot_AC();
    virtual void slot_B0();
    virtual void slot_B4();
    virtual void slot_B8();
    virtual void slot_BC();
    virtual void slot_C0();
    virtual void slot_C4();
    virtual void slot_C8();
    virtual void slot_CC();
    virtual void slot_D0();
    virtual void slot_D4();
    virtual void slot_D8();
    virtual void slot_DC();
    virtual void slot_E0();
    virtual void slot_E4();
    virtual void slot_E8();
    virtual void slot_EC();
    virtual void slot_F0();
    virtual void slot_F4();
    virtual void slot_F8();
    virtual void slot_FC();
    virtual void slot_100();
    virtual void slot_104();
    virtual void slot_108();
    virtual void slot_10C();
    virtual void slot_110();
    virtual void slot_114();
    virtual void slot_118();
    virtual void slot_11C();
    virtual void slot_120();
    virtual void slot_124();
    virtual void slot_128();
    virtual void slot_12C();
    virtual void slot_130();
    virtual void slot_134();
    virtual void slot_138();
    virtual void slot_13C();
    virtual void slot_140();
    virtual void slot_144();
    virtual void slot_148(int target_id, int self_id, int order,
                          int other_id, int hp_value, int master_hp);

    int id;
    RGE_Master_Combat_Object* master_obj;
    RGE_Player* owner;
    unsigned char gap_10[0x0C];
    RGE_Tile* tile;
    void* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
};

struct RGE_Combat_Object : RGE_Static_Object {
    virtual float calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2,
                                  float param_3, RGE_Player* param_4, RGE_Static_Object* param_5);
};

float RGE_Combat_Object::calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2,
                                         float param_3, RGE_Player* param_4, RGE_Static_Object* param_5)
{
    RGE_Master_Combat_Object* obj = this->master_obj;
    float mult = FLOAT_1_0;
    short weaponKind = obj->defense_terrain_bonus;
    RGE_Armor_Weapon_Info* armorTbl = obj->armor;
    int nArmor = obj->armor_num;

    if (weaponKind >= 0 && this->tile != 0) {
        unsigned char cls = this->tile->terrain_type;
        RGE_Game_World* wld = this->owner->world;
        float** tbl = wld->terrains;
        mult = tbl[weaponKind][cls];
    }

    float total = FLOAT_0_0;

    if (param_1 > 0) {
        RGE_Armor_Weapon_Info* weapon = param_2;
        int cnt = param_1;

        do {
            int attack = obj->base_armor;

            if (nArmor > 0) {
                RGE_Armor_Weapon_Info* srch = armorTbl;
                int n = nArmor;
                do {
                    if (srch->type == weapon->type) {
                        attack = srch->value;
                    }
                    ++srch;
                    n--;
                } while (n != 0);
            }

            float d = (float)weapon->value - (float)attack;
            float dmg = d * mult * param_3;

            if (dmg > DOUBLE_0_0) {
                total += dmg;
            }

            weapon++;
            cnt--;
        } while (cnt != 0);
    }

    return total;
}
