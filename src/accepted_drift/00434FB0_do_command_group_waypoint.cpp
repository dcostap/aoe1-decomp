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
class RGE_Command_Group_Waypoint {
public:
    uchar command;
    uchar unit_num;
    uchar x;
    uchar y;
};

class RGE_Command;
class RGE_Static_Object;

class RGE_Object_Owner {
public:
    virtual void vf00(void); virtual void vf04(void); virtual void vf08(void); virtual void vf0C(void);
    virtual void vf10(void); virtual void vf14(void); virtual void vf18(void); virtual void vf1C(void);
    virtual void vf20(void); virtual void vf24(void); virtual void vf28(void); virtual void vf2C(void);
    virtual void vf30(void); virtual void vf34(void); virtual void vf38(void); virtual void vf3C(void);
    virtual void vf40(void); virtual void vf44(void); virtual void send_waypoint(int id, unsigned char* waypoint, int push_order);
};

class RGE_Static_Object {
public:
    char gap_00[4];
    int id;
    char gap_08[4];
    RGE_Object_Owner* owner;
};

class RGE_Game_World;
class RGE_Command {
public:
    char gap_00[0x4];
    RGE_Game_World* world;
    RGE_Static_Object* get_obj(int id);
    void do_command_group_waypoint(RGE_Command_Group_Waypoint* packet);
};
#endif

void RGE_Command::do_command_group_waypoint(RGE_Command_Group_Waypoint* packet) {
    int c;
    int* ids;
    unsigned char waypoint[3];

    c = packet->unit_num;
    ids = (int*)((char*)packet + 4);
    if (c > 0) {
        int count = c;
        do {
            RGE_Static_Object* obj = this->get_obj(*ids);
            if (obj != 0) {
                waypoint[0] = packet->x;
                waypoint[1] = packet->y;
                waypoint[2] = 0;
                obj->owner->send_waypoint(obj->id, waypoint, 1);
            }
            ++ids;
            --count;
        } while (count != 0);
    }
}
