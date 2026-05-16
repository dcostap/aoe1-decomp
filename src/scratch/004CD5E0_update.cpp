// VA: 004CD5E0 TRIBE_Action_Build::update
// Attempt log:
// try 1: natural behavioral reconstruction from packet/Ghidra: missing-target checks, build-site validation, switch on state/action-list status, command/state transitions.
// try 2: fixed local class surfaces for player command/vtable and build target fields so source compiles.
// try 3: exact-size O2 build, but broad mismatch through early guard/control-flow and switch lowering.
// try 4: /GX probe unchanged; removed.
// try 5: /Od probe exact-size but wrong debug-basin codegen; removed.
// try 6: modeled missing targetID1/object lookup -> clear target -> optional state 3 early return.
// try 7: modeled missing targetID2/object lookup -> clear secondary target.
// try 8: modeled active target/work gate and command call with observed many-argument scheduling.
// try 9: modeled action-list status sub-switches for states 1 and 2 and state-transition returns.
// try 10: modeled build placement/can-build/work calculation/farm-progress cases and final command/state return 3 case.
// left in scratch: current source is exact-size 724B but mismatch is broad switch/control/vtable/call-surface drift, not accepted_drift-safe.

class RGE_Game_World { public: void* object(int); };
class RGE_Player { public: virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void command(int,int,int,int,int,int,int,int,int,int,int,int); char gap[0x38]; RGE_Game_World* world; short id; };
class RGE_Static_Object {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14();
    virtual void vf18(); virtual void vf1C(); virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void command(int,int,int,int,int,int); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vt4C(void*,float,float,int);
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C(); virtual void vf60(); virtual void vf64();
    virtual void vf68(); virtual void vf6C(); virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C(); virtual void vf90(); virtual void buildAt(void*,int,int);
    virtual void vf9C(); virtual void vfA0(); virtual void vfA4(); virtual void vfA8(); virtual void vfAC(); virtual void vfB0();
    virtual void vfB4(); virtual void vfB8(); virtual void vfBC(); virtual void vfC0(); virtual void vfC4(); virtual void vfC8();
    virtual void vfCC(); virtual void vfD0(); virtual void vfD4(); virtual void vfD8(); virtual void vfDC(); virtual void vfE0();
    virtual void vfE4(); virtual void vfE8(); virtual void vfEC(); virtual void vfF0(); virtual void vfF4(); virtual void vfF8();
    virtual void vfFC(); virtual void vf100(); virtual void vf104(); virtual void vf108(); virtual void vf10C(); virtual void vf110();
    virtual void vf114(); virtual void vf118(); virtual void vf11C(); virtual void vf120(); virtual void vf124(); virtual void vt12C(int);
    virtual void vf130(); virtual void vf134(); virtual void vf138(); virtual void vf13C(); virtual void vf140(); virtual void vf144();
    virtual void vf148(); virtual void vf14C(); virtual void vf150(); virtual void vf154(); virtual void vf158(); virtual void vf15C();
    virtual void vf160(); virtual void vf164(); virtual void vf168(); virtual void vf16C(); virtual void vf170(); virtual void vf174();
    virtual void vf178(); virtual void vf17C(); virtual void vf180(); virtual void vf184(); virtual void vf188(); virtual void vf18C();
    virtual void vf190(); virtual void vf194(); virtual void vf198(); virtual void vf19C(); virtual void vf1A0(); virtual void vf1A4();
    virtual void vf1A8(); virtual void vf1AC(); virtual void vf1B0(); virtual void vf1B4(); virtual void vf1B8(); virtual void vf1BC();
    virtual void vf1C0(); virtual void vf1C4(); virtual void vf1C8(); virtual void vf1CC(); virtual void vf1D0(); virtual void vf1D4();
    virtual void vf1D8(); virtual void vf1DC(); virtual void vf1E0(); virtual void vf1E4(); virtual void vf1E8(); virtual unsigned char canBuild(void*,int,int);
    int id; void* master; RGE_Player* player; char gap_10[0x20]; void* dbObj;
};
class ActionList { public: virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual unsigned char status(); };
class BuildTarget { public: char gap_00[4]; int id; char gap_08[4]; RGE_Player* owner; char gap_10[0x14]; int f24; char gap_28[8]; float work; int x; int y; int z; float progress; unsigned char active; void* dbObj; };
class BaseGame { public: char gap[0x9A8]; int cheat; };
extern BaseGame* rge_base_game;
extern unsigned char __cdecl canBuildTarget(BuildTarget*, float);

class TRIBE_Action_Build {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14();
    virtual void vf18(); virtual void vf1C(); virtual void vf20(); virtual void vf24(); virtual unsigned char update();
    virtual void vf2C(); virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C(); virtual void vf50(); virtual void clearTarget(int); virtual void clearOther(int); virtual void set_state(int);
    RGE_Static_Object* obj; unsigned char state; char gap0D[3]; BuildTarget* target; char gap14[4]; int targetID1; int targetID2; int x; int y; int z; float work; BuildTarget* info; ActionList* actions;
};

unsigned char TRIBE_Action_Build::update()
{
    if (this->targetID1 != -1) {
        if (this->obj->player->world->object(this->targetID1) == 0) {
            this->clearTarget(0);
            if (this->state != 2) { this->set_state(3); return 0; }
        }
    }
    if (this->targetID2 != -1) {
        if (this->obj->player->world->object(this->targetID2) == 0) this->clearOther(0);
    }
    if (this->target && this->target->active && this->work == 1.0f) {
        if ((float)((short*)this->target->dbObj)[0x13] >= this->target->work) {
            this->obj->vfF4();
            RGE_Player* p = this->obj->player;
            p->vf00();
            this->obj->player->command(this->obj->player->id, this->obj->id, 0x2CE, this->target->owner->id, this->target->x, this->target->y, this->target->z, this->target->f24, 0x3f800000, 1, 0, 100);
            return 0;
        } else {
            this->clearTarget(0);
            if (this->state != 2) { this->set_state(3); return 0; }
        }
    }
    switch (this->state) {
    case 1:
        switch (this->actions->status()) { case 1: this->set_state(3); return 0; default: break; }
        break;
    case 2:
        switch (this->actions->status()) { case 1: this->clearTarget(0); this->set_state(11); return 0; default: break; }
        break;
    case 3: this->set_state(6); return 0;
    case 6:
        if (this->obj->canBuild(this->target,0,0)) { this->set_state(7); return 0; }
        break;
    case 7:
        if (this->work < 0.0 && this->target && this->target->progress >= 1.0f) {
            this->obj->vfF4(); this->obj->vt12C(1); this->obj->buildAt(this->target,this->target->x,this->target->y); return 0;
        }
        {
            float work;
            if (rge_base_game->cheat) work = 1000.0f;
            else work = *(float*)((char*)this->info + 0x1c) * *(float*)((char*)this->obj->dbObj + 0xe4) * *(float*)((char*)this->obj->player->world + 0x84);
            if (this->target && !canBuildTarget(this->target, work)) break;
            if (this->target && ((short*)this->target->dbObj)[8] == 0x32) { this->work = -1.0f; return 0; }
            this->set_state(3); return 0;
        }
    case 11: return 1;
    case 12:
        this->obj->command(this->obj->id,this->obj->id,0x1F9,0x25A,0,0); this->set_state(2); return 3;
    }
    return 0;
}
