// RGE_Master_Combat_Object::calc_base_damage_ability
// VA: 00451000
// m_co_obj.cpp
// Matching attempt log:
// - Hoisted armor_num/base_armor outside the weapon loop; this recovered 188-byte size and the original nested-loop topology.
// - Separate `(float)attack - (float)value` operands recovered the original two-fild/fxch/fsubp x87 sequence.
// - Leaving the inner counter uninitialized until after the armor pointer load recovered the exact +0039..+00BC block island.
// - DAT_00570504/08/10/18 are the proven global surfaces; the full inherited polymorphic class surface and register-qualified target were neutral.
// - Best: 42 strict differing bytes, 95.08% instruction-shape similarity, 188/188 bytes, exact call set; remaining drift is the entry prologue/register basin and value reload (`edx` vs original `eax`) at +0039.
// - Paused after 10 meaningful probes; no accepted_drift proposed.
// - Main-agent ABI audit restored the binary-backed inherited virtual surface through slot +0x28;
//   emitted code and the remaining prologue/register mismatch were unchanged.

#include "..\..\include\game_globals.h"

struct DamageEntry { short type; short amount; };

class RGE_Sprite;
class RGE_Master_Combat_Object;

class RGE_Master_Action_Object {
public:
    virtual ~RGE_Master_Action_Object();
    virtual void copy_obj(void*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual void* make_new_obj(void*, float, float, float);
    virtual void* make_new_master();
    virtual unsigned char check_placement(void*, float, float, int*, unsigned char,
        unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
    virtual unsigned char alignment(float*, float*, void*, unsigned char);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* target);
    char gap_04[0xF8];
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    RGE_Sprite* fight_sprite; // +0xFC
    unsigned char base_armor; // +0x100
    char gap_101;
    short armor_num;          // +0x102
    DamageEntry* armor;       // +0x104
    short weapon_num;         // +0x108
    DamageEntry* weapon;      // +0x10C

    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* target);
};

long RGE_Master_Combat_Object::calc_base_damage_ability(RGE_Master_Combat_Object* target)
{
    float total = DAT_00570504;
    int count = target->weapon_num;
    DamageEntry* weapon = target->weapon;

    if (count > 0) {
        int armor_count = this->armor_num;
        int base_armor = this->base_armor;
        do {
            int n;
            int value = base_armor;
            if (armor_count > 0) {
                short weapon_type = weapon->type;
                DamageEntry* armor = this->armor;
                n = armor_count;
                do {
                    if (armor->type == weapon_type) {
                        value = armor->amount;
                    }
                    ++armor;
                    --n;
                } while (n != 0);
            }

            int attack = weapon->amount;
            float diff = (float)attack - (float)value;
            if ((double)diff > DAT_00570508) {
                total += diff;
            }
            ++weapon;
            --count;
        } while (count != 0);
    }

    if ((double)total < DAT_00570510) {
        total = DAT_00570518;
    }
    return (long)total;
}
