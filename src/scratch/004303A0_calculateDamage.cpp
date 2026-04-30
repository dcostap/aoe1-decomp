// 004303A0 RGE_Combat_Object::calculateDamage
// Source: com_obj.cpp lines 433-466, size 213 bytes
//
// Attempt log:
// 1: Struct with explicit field offsets → 7 byte edit diff (offsets off by 4)
// 2: Added field_04 → field offsets correct, but register allocation shifted
// 3: Moved armor_array to function scope → still delayed load
// 4: char* pointer arithmetic → same register scheduling issue
// 5: unsigned char cls → no change in register allocation
// All 9 probes: VC5 register scheduling drift on armor_array load
// (uses ebx before push ebp instead of ebp between push ebp and push esi)
// Drift: [eax+104h] loaded into ebx at prologue vs ebp after push ebp
// Parked: VC5 codegen drift only

extern float FLOAT_1_0;
extern float FLOAT_0_0;
extern double DOUBLE_0_0;

struct RGE_Armor_Weapon_Info {
    short type;
    short value;
};

struct RGE_Combat_Object {
    virtual float calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2,
                                  float param_3, void* param_4, void* param_5);
};

float RGE_Combat_Object::calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2,
                                         float param_3, void* param_4, void* param_5)
{
    char* obj = *(char**)((char*)this + 8);
    float mult = FLOAT_1_0;
    short weaponKind = *(short*)(obj + 0x110);
    short* armorTbl = (short*)(*(long*)(obj + 0x104));
    int nArmor = *(short*)(obj + 0x102);
    void* tgt = *(void**)((char*)this + 0x1C);

    if (weaponKind >= 0 && tgt != 0) {
        unsigned char cls = *(unsigned char*)((char*)tgt + 5) & 0x1F;
        char* wld = *(char**)((char*)this + 0x0C);
        void* wtp = *(void**)(wld + 0x3C);
        float* const* tbl = *(float* const**)((char*)wtp + 0x54);
        mult = tbl[weaponKind][cls];
    }

    float total = FLOAT_0_0;

    if (param_1 > 0) {
        RGE_Armor_Weapon_Info* weapon = param_2;
        int cnt = param_1;

        do {
            int attack = *(unsigned char*)(obj + 0x100);

            if (nArmor > 0) {
                short* srch = armorTbl;
                int n = nArmor;
                do {
                    if (*srch == weapon->type) {
                        attack = *(short*)(srch + 1);
                    }
                    srch += 2;
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
