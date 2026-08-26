// 00434FB0 RGE_Command::do_command_group_waypoint
//
// BLOCKER: packet loop behavior, object lookup, object layout, and owner vcall
// are understood, but two local scheduling decisions remain stable. Original
// keeps count in EAX through the initial `test eax,eax; jle`, then pushes EBX and
// stores count to [esp+10h]. VC5 source variants store count to [esp+0Ch] before
// the branch, shortening the branch and shifting the loop by four bytes. Original
// also schedules waypoint[1] and waypoint[2]=0 around the vcall argument pushes;
// behavior-correct source stores both bytes before loading owner/id/vtable.
//
// Attempt log:
// 1. Existing packet loop understood but used unsigned count test and wrong object id offset.
// 2. Fixed object id at +4 and kept no extra owner/id locals; prefix now matches through count test setup.
// 3. Delaying count assignment or direct packet conditions worsened to AL/test/mask basin or early EDI push.
// 4. Extra owner/id locals caused an 8-byte stack frame/sub esp basin.
// 5. register count did not prevent pre-branch count spill.
// 6. variant_lab over int/uint count, assign-before/check-then-assign/direct-check, zero-before/zero-after/split/comma-arg payload shapes, and vc5-small flags: no exact. Best behavior-correct family remained first mismatch 20, pos 31.6832%, edit 24.7525%.
// 7. 2026-05-09: kept nested positive count guard with inner `int count = c`; this fixes the count spill timing (`test/jle; push ebx; mov [esp+10h],eax`) and moves first mismatch to the waypoint payload schedule (pos 24.7525%, edit 17.8218%). Local owner/id/wp temporaries and comma-arg zeroing either add an 8-byte frame or collapse back to early y/zero stores.
// 8. 2026-05-10 pass on this VA only: tried 15+ payload-call variants: comma side effects in second/third/first args, zero-after-call source, owner-only local, id-only local, owner+id locals with/without block scope, fake C vcall forms, ordered direct `(void)` sequencing, uninitialized locals, volatile byte/struct-cast/wp-pointer indexing, plus-zero first arg, and owner-call zero-firstarg. No exact. Owner+id locals can produce the original late `y` and post-push zero schedule but force an 8-byte frame/register-family change; frame-free variants keep broad prefix exact but schedule `y`/zero before owner/id/vtable/pushes.
// ACCEPTED_DRIFT: reviewed by Boss. Remaining diff is limited to stack-local waypoint payload scheduling before the same owner vcall: rebuilt stores y and zero before loading owner/id/vtable and pushing args; original stores y after LEA and zero after pushes at the equivalent shifted stack address. The waypoint bytes at call time, pushed arguments, vtable slot, loop state, stack cleanup, return paths, size, and epilogue are identical.

typedef unsigned char uchar;

#ifndef COMMAND_TU_CONTEXT
struct RGE_Obj_Info {
    int id;
};

class RGE_Command_Group_Waypoint {
public:
    uchar command;
    uchar unit_num;
    uchar x;
    uchar y;
};

struct XYZBYTEPoint {
    uchar x;
    uchar y;
    uchar z;
};

class RGE_Command;
class RGE_Static_Object;

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float,
                                float, unsigned int, unsigned int, unsigned int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
};

class RGE_Static_Object {
public:
    char gap_00[4];
    int id;
    char gap_08[4];
    RGE_Player* owner;
};

class RGE_Game_World;
class RGE_Command {
public:
    char gap_00[0x4];
    RGE_Game_World* world;
protected:
    RGE_Static_Object* get_obj(RGE_Obj_Info info);
    void do_command_group_waypoint(RGE_Command_Group_Waypoint* packet);
};
#endif

void RGE_Command::do_command_group_waypoint(RGE_Command_Group_Waypoint* packet) {
    int c;
    RGE_Obj_Info* ids;
    XYZBYTEPoint waypoint;

    c = packet->unit_num;
    ids = (RGE_Obj_Info*)((char*)packet + 4);
    if (c > 0) {
        int count = c;
        do {
            RGE_Static_Object* obj = this->get_obj(*ids);
            if (obj != 0) {
                waypoint.x = packet->x;
                waypoint.y = packet->y;
                waypoint.z = 0;
                obj->owner->processAddWaypointCommand(obj->id, &waypoint, 1);
            }
            ++ids;
            --count;
        } while (count != 0);
    }
}
