// VA: 004CDBB0 TRIBE_Action_Convert::first_in_stack
// Attempt log:
// 1: natural reconstruction from packet/decompiler: text 560 B, wrong field offsets because virtual declarations shifted data members; notify helper emitted out-of-line.
// 2: rewrote with explicit vtable pointer field, manual vtable set_state calls, and inline notification bodies to restore real object offsets/call surface: exact size 595 but broad 87% positional; top differs by extra saved EBP/word BX.
// 3: tried int class-id local to force movsx ebx; worsened to 592 B and still used BX, rolled back.
// 4: tried /GX; unchanged.
// 5: tried /O2 without /Oy; unchanged.
// 6: current best same-size 595 B after inlining notify and manual vtable calls, but still broad mismatch from register topology: original carries target in EDX and actor in EDI with no EBP save; rebuilt saves EBP and carries target in EDI/actor in EDX.
// 7: object offsets/call surface are now correct (+8 actor, +10 target, +40 was_same_owner, +44 requiredRange), unlike v1.
// 8: remaining mismatch includes word-BX class id, branch distances, and all notification/set_state blocks shifted by the early register allocation.
// 9: left in scratch: behavior is modeled but mismatch is much too broad for accepted_drift.

typedef unsigned char uchar;

class RGE_Base_Game { public: void* vtable; };
extern RGE_Base_Game* rge_base_game;

class ActionV {
public:
    virtual void f00(); virtual void f04(); virtual void f08(); virtual void f0c();
    virtual void f10(); virtual void f14(); virtual void f18(); virtual void f1c();
    virtual void f20(); virtual void f24(); virtual void f28(); virtual void f2c();
    virtual void f30(); virtual void f34(); virtual void f38(); virtual void f3c();
    virtual void f40(); virtual void f44(); virtual void f48(); virtual void f4c();
    virtual void f50(); virtual void f54(); virtual void f58();
    virtual void set_state(int);
};
class GameV {
public:
    virtual void g00(); virtual void g04(); virtual void g08(); virtual void g0c();
    virtual void g10(); virtual void g14(); virtual void g18(); virtual void g1c();
    virtual void g20(); virtual void g24(); virtual void g28(); virtual void g2c();
    virtual void g30(); virtual void g34(); virtual void g38(); virtual void g3c();
    virtual void notify(int,int,int,int,int);
};

class RGE_Player {
public:
    char gap_00[0x4A];
    short id;
    char gap_4C[4];
    float* attributes;
    int computerPlayer();
};

class MasterObj { public: char gap_00[0x10]; short object_id; char gap_12[2]; short class_id; char gap_16[0x114-0x16]; float range; };
class UnitObj { public: char gap_00[8]; MasterObj* master; RGE_Player* owner; };
class ActionObj { public: char gap_00[8]; MasterObj* master; RGE_Player* owner; char gap_10[0x44-0x10]; float field_44; };

class TRIBE_Action_Convert {
public:
    void* vtable;
    char gap_04[4];
    ActionObj* actor;
    char gap_0C[4];
    UnitObj* target;
    char gap_14[0x40-0x14];
    uchar was_same_owner;
    char gap_41[3];
    float requiredRange;

    void first_in_stack(uchar param_1);
};

void TRIBE_Action_Convert::first_in_stack(uchar param_1)
{
    UnitObj* target = this->target;
    if (target != 0) {
        MasterObj* tm = target->master;
        ActionObj* actor = this->actor;
        short cls = tm->class_id;
        if (target->owner == actor->owner) {
            this->was_same_owner = 1;
        } else {
            this->was_same_owner = 0;
        }
        short oid = tm->object_id;
        if (oid == 0x6d || cls == 0x1b || oid == 0x9f || oid == 0x9e || oid == 0xa3 || oid == 0x114) {
            if (actor->owner->computerPlayer() == 1) {
                ((ActionV*)this)->set_state(0x0b);
            } else {
                ((ActionV*)this)->set_state(0x0d);
            }
            oid = this->target->master->object_id;
            if (oid == 0x6d) {
                RGE_Base_Game* game = rge_base_game;
                ((GameV*)game)->notify(0x79, (int)this->actor->owner->id, 0, 0, 0);
                return;
            }
            if (oid == 0x114) {
                RGE_Base_Game* game = rge_base_game;
                ((GameV*)game)->notify(0x7a, (int)this->actor->owner->id, 0, 0, 0);
                return;
            }
            return;
        }
        if (actor->field_44 < 100.0) {
            ((ActionV*)this)->set_state(0x0d);
            RGE_Base_Game* game = rge_base_game;
            ((GameV*)game)->notify(0x76, (int)this->actor->owner->id, 0, 0, 0);
            return;
        }
        if (cls == 3) {
            this->requiredRange = 1.0f;
        } else {
            this->requiredRange = actor->master->range;
        }
        if (cls == 0x1e) {
            ((ActionV*)this)->set_state(0x0d);
            return;
        }
        if (cls == 0x12 && actor->owner->attributes[0x1b] <= 0.0f) {
            if (actor->owner->computerPlayer() == 1) {
                ((ActionV*)this)->set_state(0x0b);
            } else {
                ((ActionV*)this)->set_state(0x0d);
            }
            RGE_Base_Game* game = rge_base_game;
            ((GameV*)game)->notify(0x77, (int)this->actor->owner->id, 0, 0, 0);
            return;
        }
        if (cls == 3 && actor->owner->attributes[0x1c] <= 0.0f) {
            if (actor->owner->computerPlayer() == 1) {
                ((ActionV*)this)->set_state(0x0b);
            } else {
                ((ActionV*)this)->set_state(0x0d);
            }
            RGE_Base_Game* game = rge_base_game;
            ((GameV*)game)->notify(0x78, (int)this->actor->owner->id, 0, 0, 0);
            return;
        }
    }
    if (param_1 != 0) {
        if (target != 0) {
            ((ActionV*)this)->set_state(4);
            return;
        }
    }
    ((ActionV*)this)->set_state(3);
}
