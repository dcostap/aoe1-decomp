// RGE_Master_Combat_Object::calc_base_damage_ability
// VA: 00451000
// m_co_obj.cpp
// Attempts: rebuilt natural damage/armor loops with typed 4-byte entries and double zero comparisons.
// Tried local ordering (target fields before/after base float), explicit Frame locals to force 8-byte stack frame, target alias, direct locals, explicit armor/weapon pointer locals, and expression forms for `(weapon.amount - armor)` accumulation.
// Best behavior/call set understood, but VC5 prologue/local-frame basin remains wrong: either `push ecx`/4-byte local or `sub esp,8` before loading stack param; original does `mov edx,[esp+4]; sub esp,8` then keeps count/value in exact stack slots. Current frame version also remains 12B short due scheduling/local-slot differences. No accepted_drift proposed.

struct DamageEntry { short type; short amount; };

class RGE_Master_Combat_Object {
public:
    char gap_00[0x100];
    unsigned char base_armor; // +0x100
    char gap_101;
    short armor_num;          // +0x102
    DamageEntry* armor;       // +0x104
    short weapon_num;         // +0x108
    DamageEntry* weapon;      // +0x10C

    long calc_base_damage_ability(RGE_Master_Combat_Object* target);
};

long RGE_Master_Combat_Object::calc_base_damage_ability(RGE_Master_Combat_Object* target)
{
    RGE_Master_Combat_Object* t = target;
    struct Frame { int count; int value; } f;
    float total = *(float*)0x570504;
    f.count = t->weapon_num;
    DamageEntry* weapon = t->weapon;

    if (f.count > 0) {
        do {
            f.value = this->base_armor;
            int armor_count = this->armor_num;
            if (armor_count > 0) {
                DamageEntry* armor = this->armor;
                do {
                    if (armor->type == weapon->type) {
                        f.value = armor->amount;
                    }
                    ++armor;
                    --armor_count;
                } while (armor_count != 0);
            }

            int attack = weapon->amount;
            float diff = (float)(attack - f.value);
            if ((double)diff > 0.0) {
                total += diff;
            }
            ++weapon;
            --f.count;
        } while (f.count != 0);
    }

    if ((double)total < 0.0) {
        total = *(float*)0x570518;
    }
    return (long)total;
}
