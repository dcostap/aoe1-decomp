// 00430230 RGE_Combat_Object::do_attack
// PDB: com_obj.cpp:361-390, 234 bytes
// virtual uchar __thiscall do_attack(RGE_Static_Object*, RGE_Combat_Object*, float, float, float)
// ret 14h (5 params), FLAGS: default
//
// === Attempt log ===
// probes 1-5: all produce 234-byte version matching size.
// Differences: __fastcall vtable calls add xor edx,edx overhead; register
// allocation for param loads differs from original.
// Best variant retained below.

extern "C" int debug_rand(const char* file, int line);

typedef unsigned long DWORD;

class RGE_Static_Object {
public:
    void* vtable;
    int obj_id;
};

class RGE_Combat_Object {
public:
    void* vtable;
    int field_4;
    void* object_info;
    int field_0C;

    unsigned char do_attack(RGE_Static_Object* target, RGE_Combat_Object* attacker,
        float param_3, float param_4, float param_5);
};

unsigned char RGE_Combat_Object::do_attack(RGE_Static_Object* target, RGE_Combat_Object* attacker,
    float param_3, float param_4, float param_5)
{
    if (target == 0) return 0;

    float attack_range = *(float*)((char*)this->object_info + 0x118);
    if (attack_range > 0.0f) {
        // area_attack(float, float, float, RGE_Combat_Object*, RGE_Static_Object*)
        typedef unsigned char (__fastcall* AreaAttackFunc)(RGE_Combat_Object*, int,
            float, float, float, RGE_Combat_Object*, RGE_Static_Object*);
        (*((AreaAttackFunc*)((DWORD*)this->vtable + 0x21C / 4)))(this, 0,
            param_3, param_4, param_5, attacker, 0);
        return 1;
    }

    // notify(int, int, int, long, long, long)
    typedef void (__fastcall* NotifyFunc)(RGE_Combat_Object*, int,
        int, int, int, long, long, long);
    (*((NotifyFunc*)((DWORD*)this->vtable + 0x148 / 4)))(this, 0,
        this->field_4, this->field_4, 0x200, 0x258, target->obj_id, 0);

    int r = debug_rand("C:\\msdev\\work\\age1_x1\\com_obj.cpp", 0x17B);
    int chance = r * 100 / 0x7FFF;

    short threshold = *(short*)((char*)this->object_info + 0x126);
    if (chance > (int)threshold) return 1;

    // calc_attack_modifier(RGE_Static_Object*)
    typedef float (__fastcall* CalcModFunc)(RGE_Combat_Object*, int, RGE_Static_Object*);
    float mod = (*((CalcModFunc*)((DWORD*)this->vtable + 0xF0 / 4)))(this, 0, target);

    // damage(int, int, float, int, void*)
    short weapon_type = *(short*)((char*)this->object_info + 0x108);
    int weapon_info = *(int*)((char*)this->object_info + 0x10C);
    typedef void (__fastcall* DamageFunc)(RGE_Static_Object*, int,
        int, int, float, int, void*);
    (*((DamageFunc*)((DWORD*)target->vtable + 0x70 / 4)))(target, 0,
        weapon_type, weapon_info, mod, this->field_0C, attacker);

    return 1;
}
