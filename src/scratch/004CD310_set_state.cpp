// VA: 004CD310 TRIBE_Action_Build::set_state
// Attempt log:
// try 1: natural reconstruction from asm/Ghidra: delete action list, set state byte, switch over states, issue command/action calls and create move/build actions.
// FLAGS: config/flags/004CD310_set_state.rsp uses /GX because original has EH registration/unwind-state stores around new/action construction.
// try 2: no-/GX probe compiled to 544B, missing original EH prologue; kept /GX.
// try 3: added virtual padding for set_substate/vf54/vf58; exact vtable slots still differ in some calls.
// try 4: corrected RGE_Static_Object id/master/player offsets to +4/+8/+0C, improving command/frame source layout.
// try 5: defined action classes as 0x44 bytes so operator new size matches original push 44h.
// try 6: corrected build-info offsets +0x24/+0x34/+0x38/+0x44 used by move/build/frame/sound cases.
// try 7: modeled computer-player branch with command ids 0x1FA/0x202 and substate 1.
// try 8: modeled reset-state case with frame reset, two virtual clears, and x/y/z=-1.0f stores.
// try 9: modeled allocation-failure paths setting substate 13 and successful add/set_flag ordering for move/build actions.
// try 10: modeled final frame/sound cases; exact-size output remains broad drift from switch table, virtual slot surface, and EH constructor cleanup shape.
// left in scratch: current /GX source is exact-size 661B but mismatch is broad (first at switch lowering), not accepted_drift-safe.

class RGE_Action_List { public: void delete_list(); void add(void*); };
class RGE_Player { public: int computerPlayer(); };
class RGE_Static_Object {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14();
    virtual void vf18(); virtual void vf1C(); virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void set_frame(int);
    virtual void vf3C(); virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C(); virtual void vf60(); virtual void vf64();
    virtual void vf68(); virtual void vf6C(); virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C(); virtual void vf90(); virtual void vf94();
    virtual void vf98(); virtual void vf9C(); virtual void vfA0(); virtual void vfA4(); virtual void vfA8(); virtual void vfAC();
    virtual void vfB0(); virtual void vfB4(); virtual void vfB8(); virtual void vfBC(); virtual void vfC0(); virtual void vfC4();
    virtual void vfC8(); virtual void vfCC(); virtual void vfD0(); virtual void vfD4(); virtual void vfD8(); virtual void vfDC();
    virtual void vfE0(); virtual void vfE4(); virtual void vfE8(); virtual void vfEC(); virtual void vfF0(); virtual void vfF4();
    virtual void vfF8(); virtual void vfFC(); virtual void vf100(); virtual void vf104(); virtual void vf108(); virtual void vf10C();
    virtual void vf110(); virtual void vf114(); virtual void vf118(); virtual void vf11C(); virtual void vf120(); virtual void vf124();
    virtual void vf128(); virtual void vf12C(); virtual void vf130(); virtual void vf134(); virtual void vf138(); virtual void vf13C();
    virtual void vf140(); virtual void vf144(); virtual void command(int,int,int,int,int,int);
    int id; void* master; RGE_Player* player;
};
class BuildTarget { public: char gap00[0x24]; int f24; char gap28[0x0C]; int f34; int x; int y; int z; void* sound; };
class ActionMoveTo { public: char storage[0x44]; ActionMoveTo(RGE_Static_Object*, int, int, int, int, int); void set_flag(int); };
class ActionBuild { public: char storage[0x44]; ActionBuild(RGE_Static_Object*, BuildTarget*, int, int); void set_flag(int); };
class TDigital { public: void play(int); };
extern void* __cdecl operator new(unsigned int);

class TRIBE_Action_Build {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14();
    virtual void vf18(); virtual void vf1C(); virtual void vf20(); virtual void vf24(); virtual void set_state(unsigned char);
    virtual void vf2C(); virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C(); virtual void vf50(); virtual void vf54(int); virtual void vf58(int); virtual void set_substate(int);
    char gap_04[4];
    RGE_Static_Object* obj;
    unsigned char state;
    char gap_0D[3];
    BuildTarget* target;
    char gap_14[0x0C];
    int x; int y; int z;
    char gap_2C[4];
    BuildTarget* build_info;
    RGE_Action_List* actions;
};

void TRIBE_Action_Build::set_state(unsigned char s)
{
    this->actions->delete_list();
    this->state = s;
    switch (s) {
    case 3:
        if (this->obj->player->computerPlayer() == 1) {
            this->obj->command(this->obj->id, this->obj->id, 0x1FA, 0x25A, 0, 0);
            this->set_substate(1);
        } else {
            this->obj->command(this->obj->id, this->obj->id, 0x202, 0x25A, 0, 0);
        }
        this->obj->set_frame(*(int*)((char*)this->obj->master + 0x18));
        break;
    case 2:
        this->obj->set_frame(*(int*)((char*)this->obj->master + 0x18));
        this->vf54(0);
        this->vf58(0);
        this->x = -1082130432; this->y = -1082130432; this->z = -1082130432;
        break;
    case 11: {
        ActionMoveTo* a = new ActionMoveTo(this->obj, this->x, this->y, this->z, 0, this->build_info->f34);
        if (!a) { this->set_substate(13); break; }
        a->set_flag(1);
        this->actions->add(a);
        break;
    }
    case 12:
        if (this->target) { this->x = this->target->x; this->y = this->target->y; this->z = this->target->z; }
        {
            ActionBuild* b = new ActionBuild(this->obj, this->target, this->build_info->f24, this->build_info->f34);
            if (!b) { this->set_substate(13); break; }
            this->actions->add(b);
            b->set_flag(1);
        }
        break;
    case 13:
        this->obj->set_frame(this->build_info->f34);
        break;
    case 14:
        this->obj->set_frame(*(int*)((char*)this->build_info + 0x38));
        if (*(TDigital**)((char*)this->build_info + 0x44)) (*(TDigital**)((char*)this->build_info + 0x44))->play(1);
        break;
    case 15:
        this->obj->set_frame(*(int*)((char*)this->obj->master + 0x18));
        break;
    default:
        break;
    }
}
