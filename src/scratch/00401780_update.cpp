// 00401780 RGE_Action_Attack::update
// Attempt log:
// 1: natural switch reconstruction from packet/decompiler, using virtual padding and direct member calls.
// 2: modeled action virtual slots +0x54/+0x58/+0x5c as real virtuals to avoid __thiscall casts.
// 3: modeled RGE_Game_World::object as direct member call, but guessed object/world surface is still wrong early.
// 4: modeled weapon sub-switch with switch-on-return to produce nested switch family, but current register pressure differs.
// 5: tried raw vtable cdecl helpers for external object tests; compiles but forces extra saved ebx/ebp versus original push ecx/esi/edi.
// 6: modeled notify virtual +0x148 call with raw helper; behavior path present but call surface likely needs real typed virtual.
// 7: modeled ready_to_attack stack local initialized to -1; local slot exists but broader prologue mismatch remains.
// 8: modeled ftol/fire_missile path with float expression, but not exact and later path not reliable.
// 9: no inline asm or custom flags tried.
// 10: left in scratch: first mismatch is prologue/register pressure and object layout, broad diff, not accepted_drift.

typedef unsigned char uchar;
extern "C" long __cdecl _ftol(void);
class RGE_Static_Object;
class RGE_Game_World { public: RGE_Static_Object* object(int id); };
class RGE_Combat_Object {
public:
    void reset_attack_timer();
};
#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
class RGE_Action_Attack {
public:
    VPAD16(0) VPAD4(16) VPAD1(20)
    virtual void set_target(int v); // +54
    virtual void clear_target(int v); // +58
    virtual void set_state(int v); // +5c
    char state;
    char gap_0d[3];
    RGE_Combat_Object* object;
    char gap_14[4];
    int target_id;
    int target2_id;
    char gap_20[0x0c];
    float timer;
    char gap_30[4];
    void* weapon;
    char gap_38[4];
    uchar flag3c;
    char gap_3d[0x19];
    short fire_missile_at_frame;
    uchar need_to_attack;
    char gap_59;
    uchar indirect_fire_flag;
    int ready_to_attack(int* rangeStatus);
    void do_attack();
    uchar update();
};
#define VTBL(o) (*(void***)(o))
#define IS_VISIBLE(o,arg) ((int (__cdecl*)(void*,int))VTBL(o)[7])((o),(arg))
#define WEAP_STATE(o) ((uchar (__cdecl*)(void*))VTBL(o)[3])((o))
#define CAN_FIRE(o) ((uchar (__cdecl*)(void*))VTBL(o)[31])((o))
#define CAN_ATTACK(a,b) ((uchar (__cdecl*)(void*,void*))VTBL(a)[9])((a),(b))
#define CHECK_FRAME(a,b) ((uchar (__cdecl*)(void*,void*))VTBL(a)[8])((a),(b))
#define NOTIFY(o,a,b,c,d,e,f) ((void (__cdecl*)(void*,int,int,int,int,int,int))VTBL(o)[0x52])((o),(a),(b),(c),(d),(e),(f))

uchar RGE_Action_Attack::update()
{
    int rangeStatus;
    RGE_Combat_Object* obj = this->object;
    RGE_Game_World* world = *(RGE_Game_World**)((char*)obj + 0x3c); // approximate surface
    this->timer += *(float*)((char*)world + 0x84);
    if (this->target_id != -1 && world->object(this->target_id) == 0) {
        this->set_target(0);
        this->set_state(2);
        return 5;
    }
    if (this->target2_id != -1 && world->object(this->target2_id) == 0) {
        this->clear_target(0);
    }
    RGE_Static_Object* target = *(RGE_Static_Object**)((char*)this + 0x10);
    if (target != 0) {
        if (*(uchar*)((char*)target + 0x48) >= 3) {
            this->set_target(0);
            this->set_state(2);
            return 5;
        }
        if (*(short*)((char*)obj + 0x4a) != 0 && IS_VISIBLE(obj, *(short*)((char*)target + 0x4a))) {
            this->set_state(1);
            if (this->flag3c != 0) return 4;
            NOTIFY(this->object, *(int*)((char*)this->object + 4), *(int*)((char*)this->object + 4), 0x1fb, 0x258, this->target_id, 0);
            return 4;
        }
    }
    if (target != 0 && *(int*)((char*)target + 0x20) != 0) {
        this->set_state(1);
        if (this->flag3c == 0) NOTIFY(this->object, *(int*)((char*)this->object + 4), *(int*)((char*)this->object + 4), 0x1fb, 0x258, this->target_id, 0);
        return 4;
    }
    switch (this->state) {
    case 1: return 1;
    case 2:
        if (CHECK_FRAME(*(void**)((char*)obj+0x18), *(void**)((char*)obj+0x10)) == 1) {
            this->set_target(0);
            if (this->flag3c == 0) NOTIFY(this->object, *(int*)((char*)this->object + 4), *(int*)((char*)this->object + 4), 0x1fa, 0x258, 0, 0);
            this->set_state(1);
            return this->flag3c == 1 ? 5 : 3;
        }
        return 0;
    case 4:
        switch (WEAP_STATE(this->weapon)) {
        case 1: case 2: this->set_state(6); return 0;
        case 3: this->set_state(13); if (this->flag3c) return 3; NOTIFY(this->object, *(int*)((char*)this->object + 4), *(int*)((char*)this->object + 4), 0x1f9, 0x258, 0, 0); return 3;
        case 4: this->set_state(14); if (this->flag3c == 0) NOTIFY(this->object, *(int*)((char*)this->object + 4), *(int*)((char*)this->object + 4), 0x1fb, 0x258, this->target_id, 0); return 4;
        default: return 0;
        }
    case 6:
        rangeStatus = -1;
        if (this->ready_to_attack(&rangeStatus)) { this->object->reset_attack_timer(); this->set_state(7); }
        return 0;
    case 7:
        if (!this->need_to_attack) {
            if (CAN_FIRE(obj) == 1) {
                if (target == 0 && !this->indirect_fire_flag) { this->set_state(2); return 0; }
                this->object->reset_attack_timer();
                this->set_state(6);
                if (this->state != 13 && this->state != 4) this->set_state(7);
            }
            if (!this->need_to_attack) {
                if (CHECK_FRAME(*(void**)((char*)obj+0x18), *(void**)((char*)obj+0x10)) != 1 && (*(uchar*)(*(int*)((char*)obj+0x10)+0x70) & 1)) return 0;
                if (target == 0 && !this->indirect_fire_flag) { this->set_state(2); return 0; }
                this->set_state(6); return 0;
            }
        }
        if (this->fire_missile_at_frame == 0) {
            int frame = (int)((float)*(short*)(*(int*)((char*)obj+0x10)+0x5e) * 0.5f);
            return frame, (uchar)0;
        }
        if (!CAN_ATTACK(*(void**)((char*)obj+0x18), *(void**)((char*)obj+0x10))) return 0;
        this->do_attack(); return 0;
    default: return 0;
    }
}
