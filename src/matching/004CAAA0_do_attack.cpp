// VA: 004CAAA0 TRIBE_Combat_Object::do_attack
// Source: t_c_obj.cpp lines 500-542
// Attempt log:
// 1: explicit thiscall vtable pointer typedefs rejected by VC5.
// 2: natural virtual declarations for vtable calls.

extern "C" int __cdecl debug_rand(const char* file, int line);

#ifndef T_C_OBJ_CONTEXT_H
class RGE_Static_Object;
class RGE_Combat_Object;

class RGE_Base_Game {
public:
    char gap_000[0x9A8];
    int quick_build;
};

#define rge_base_game (*(RGE_Base_Game**)0x0062C574)

class RGE_Static_Object {
public:
    virtual void vf000(void);
    virtual void vf004(void);
    virtual void vf008(void);
    virtual void vf00C(void);
    virtual void vf010(void);
    virtual void vf014(void);
    virtual void vf018(void);
    virtual void vf01C(void);
    virtual void vf020(void);
    virtual void vf024(void);
    virtual void vf028(void);
    virtual void vf02C(void);
    virtual void vf030(void);
    virtual void vf034(void);
    virtual void vf038(void);
    virtual void vf03C(void);
    virtual void vf040(void);
    virtual void vf044(void);
    virtual void vf048(void);
    virtual void vf04C(void);
    virtual void vf050(void);
    virtual void vf054(void);
    virtual void vf058(void);
    virtual void vf05C(void);
    virtual void vf060(void);
    virtual void vf064(void);
    virtual void vf068(void);
    virtual void vf06C(void);
    virtual void vf070(int weapon_type, int weapon_info, float mod, int source, RGE_Combat_Object* attacker);

    int id;
};

class RGE_Combat_Object {
public:
    virtual void vf000(void);
    virtual void vf004(void);
    virtual void vf008(void);
    virtual void vf00C(void);
    virtual void vf010(void);
    virtual void vf014(void);
    virtual void vf018(void);
    virtual void vf01C(void);
    virtual void vf020(void);
    virtual void vf024(void);
    virtual void vf028(void);
    virtual void vf02C(void);
    virtual void vf030(void);
    virtual void vf034(void);
    virtual void vf038(void);
    virtual void vf03C(void);
    virtual void vf040(void);
    virtual void vf044(void);
    virtual void vf048(void);
    virtual void vf04C(void);
    virtual void vf050(void);
    virtual void vf054(void);
    virtual void vf058(void);
    virtual void vf05C(void);
    virtual void vf060(void);
    virtual void vf064(void);
    virtual void vf068(void);
    virtual void vf06C(void);
    virtual void vf070(void);
    virtual void vf074(void);
    virtual void vf078(void);
    virtual void vf07C(void);
    virtual void vf080(void);
    virtual void vf084(void);
    virtual void vf088(void);
    virtual void vf08C(void);
    virtual void vf090(void);
    virtual void vf094(void);
    virtual void vf098(void);
    virtual void vf09C(void);
    virtual void vf0A0(void);
    virtual void vf0A4(void);
    virtual void vf0A8(void);
    virtual void vf0AC(void);
    virtual void vf0B0(void);
    virtual void vf0B4(void);
    virtual void vf0B8(void);
    virtual void vf0BC(void);
    virtual void vf0C0(void);
    virtual void vf0C4(void);
    virtual void vf0C8(void);
    virtual void vf0CC(void);
    virtual void vf0D0(void);
    virtual void vf0D4(void);
    virtual void vf0D8(void);
    virtual void vf0DC(void);
    virtual void vf0E0(void);
    virtual void vf0E4(void);
    virtual void vf0E8(void);
    virtual void vf0EC(void);
    virtual float vf0F0(RGE_Static_Object* target);
    virtual void vf0F4(void);
    virtual void vf0F8(void);
    virtual void vf0FC(void);
    virtual void vf100(void);
    virtual void vf104(void);
    virtual void vf108(void);
    virtual void vf10C(void);
    virtual void vf110(void);
    virtual void vf114(void);
    virtual void vf118(void);
    virtual void vf11C(void);
    virtual void vf120(void);
    virtual void vf124(void);
    virtual void vf128(void);
    virtual void vf12C(void);
    virtual void vf130(void);
    virtual void vf134(void);
    virtual void vf138(void);
    virtual void vf13C(void);
    virtual void vf140(void);
    virtual void vf144(void);
    virtual void vf148(int a, int b, int c, int d, int e, int f);
    virtual void vf14C(void);
    virtual void vf150(void);
    virtual void vf154(void);
    virtual void vf158(void);
    virtual void vf15C(void);
    virtual void vf160(void);
    virtual void vf164(void);
    virtual void vf168(void);
    virtual void vf16C(void);
    virtual void vf170(void);
    virtual void vf174(void);
    virtual void vf178(void);
    virtual void vf17C(void);
    virtual void vf180(void);
    virtual void vf184(void);
    virtual void vf188(void);
    virtual void vf18C(void);
    virtual void vf190(void);
    virtual void vf194(void);
    virtual void vf198(void);
    virtual void vf19C(void);
    virtual void vf1A0(void);
    virtual void vf1A4(void);
    virtual void vf1A8(void);
    virtual void vf1AC(void);
    virtual void vf1B0(void);
    virtual void vf1B4(void);
    virtual void vf1B8(void);
    virtual void vf1BC(void);
    virtual void vf1C0(void);
    virtual void vf1C4(void);
    virtual void vf1C8(void);
    virtual void vf1CC(void);
    virtual void vf1D0(void);
    virtual void vf1D4(void);
    virtual void vf1D8(void);
    virtual void vf1DC(void);
    virtual void vf1E0(void);
    virtual void vf1E4(void);
    virtual void vf1E8(void);
    virtual void vf1EC(void);
    virtual void vf1F0(void);
    virtual void vf1F4(void);
    virtual void vf1F8(void);
    virtual void vf1FC(void);
    virtual void vf200(void);
    virtual void vf204(void);
    virtual void vf208(void);
    virtual void vf20C(void);
    virtual void vf210(void);
    virtual void vf214(void);
    virtual void vf218(void);
    virtual unsigned char vf21C(float p3, float p4, float p5, RGE_Combat_Object* attacker, RGE_Static_Object* target);

    int field_04;
    void* object_info;
    int field_0C;

    unsigned char do_attack(RGE_Static_Object* target, RGE_Combat_Object* attacker, float p3, float p4, float p5);
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    unsigned char do_attack(RGE_Static_Object* target, RGE_Combat_Object* attacker, float p3, float p4, float p5);
};
#endif

#ifdef T_C_OBJ_CONTEXT_H
#define field_0C field_0C_value
#endif

unsigned char TRIBE_Combat_Object::do_attack(RGE_Static_Object* target, RGE_Combat_Object* attacker, float p3, float p4, float p5)
{
    if (target == 0) {
        return 0;
    }

    if (rge_base_game->quick_build != 0) {
        short type = *(short*)((char*)this->object_info + 0x10);
        if (type == 0x7a || type == 0x7b) {
            this->vf148(this->field_04, this->field_04, 0x200, 0x258, target->id, 0);
            target->vf06C();
            return 1;
        }
    }

    if (*(float*)((char*)this->object_info + 0x118) > 0.0f &&
        *(float*)((char*)this->object_info + 0x114) < 0.99f) {
        this->vf21C(p3, p4, p5, attacker, target);
        this->vf148(this->field_04, this->field_04, 0x200, 0x258, target->id, 0);
        int r = debug_rand("C:\\msdev\\work\\age1_x1\\t_c_obj.cpp", 0x211);
        int chance = (r * 100) / 0x7fff;
        if (chance <= (int)*(short*)((char*)this->object_info + 0x126)) {
            float mod = this->vf0F0(target);
            target->vf070((int)*(short*)((char*)this->object_info + 0x108),
                          *(int*)((char*)this->object_info + 0x10c),
                          mod,
                          this->field_0C,
                          attacker);
        }
        return 1;
    }

    return RGE_Combat_Object::do_attack(target, attacker, p3, p4, p5);
}

#ifdef T_C_OBJ_CONTEXT_H
#undef field_0C
#endif
