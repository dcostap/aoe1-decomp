// VA: 005068B0, processNotify, 444 bytes
// Source: taiuaimd.cpp lines 2051-2117
// Attempt log:
// - v1: natural decompiler-shaped implementation with local structs/vtable pads.
// - v2: fixed notify caller offset to +0, p2 to +0x10 and base call signature with ulong.
// - v3/v4: changed mType dispatch to subtract chain; v4 uses `t != 0 && t != 0x1b`.
// - v5: cached helpMax in scan loops to avoid extra max>0 pretest/pointer-walk family.
// - v6: modeled RGE_Static_Object::action_list as pointer at +0x184, fixing final have_action/get_action surface.
// - v7: switch for mType dispatch emits original sub/sub chain exactly.
// - v8: introduced count locals for scan loops to try to get count in ecx and max in edx like original.
// - v9: swapped count/i declaration order; no register change.
// - v10: left in scratch. Best check: 444/444 bytes, positional diff 55.8559%, edit diff 31.3063%, first mismatch at +0xA0.
//   Blocker: scan-loop register/topology mismatch. Original uses indexed loop with ecx=count, edx=max,
//   ebx=list, ebp/edi=caller; rebuilt uses edx=count, ebp=max and pointer-walk/add forms, cascading into
//   allocation-copy registers (newMax/newList/caller) despite matching call set, stack cleanup, and final action-list surface.

typedef unsigned long ulong;

typedef unsigned char uchar;

void* operator new(unsigned int size);
void operator delete(void* ptr);

struct NotifyEvent {
    int caller;          // +0x00
    char gap_04[4];      // +0x04
    int mType;           // +0x08
    char gap_0c[4];      // +0x0c
    int p2;              // +0x10
};

class RGE_Player {
public:
    int computerPlayer();
};

class RGE_Action {
public:
    char gap_00[0x0c];
    uchar state;
};

class RGE_Action_List {
public:
    uchar have_action();
    RGE_Action* get_action();
};

class __declspec(novtable) RGE_Static_Object {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void va0(); virtual void va4(); virtual void va8(); virtual void vac();
    virtual void vb0(); virtual void vb4(); virtual void vb8(); virtual void vbc();
    virtual void vc0(); virtual void vc4(); virtual void vc8(); virtual void vcc();
    virtual void vd0(); virtual void vd4(); virtual void vd8(); virtual void vdc();
    virtual void ve0(); virtual void ve4();
    virtual void send_notify(int a, int b, int type, int caller, int zero1, int zero2); // +0xe8
    virtual void set_something(int one); // +0xec

    int id;             // +0x04
    void* master_obj;    // +0x08
    RGE_Player* owner;   // +0x0c
    char gap_10[0x174];
    RGE_Action_List* action_list; // +0x184
};

class UnitAIModule {
public:
    void* vtable;                 // +0x00
    RGE_Static_Object* obj;       // +0x04
    char gap_08[0x20];            // +0x08
    int currentOrder;             // +0x28
    char gap_2c[0x08];            // +0x2c
    int currentTarget;            // +0x34
    char gap_38[0x28];            // +0x38
    int* helpList;                // +0x60
    int helpCount;                // +0x64
    char gap_68[4];               // +0x68
    int helpMax;                  // +0x6c

    int processNotify(NotifyEvent* event, ulong param_2);
    void purgeNotifyQueue(ulong param_2);
    void askForHelp(int caller);
};

class TribeTransportShipUnitAIModule : public UnitAIModule {
public:
    int processNotify(NotifyEvent* event, ulong param_2);
};

class __declspec(novtable) ThisVTable {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void va0();
    virtual void func_a4(int one); // +0xa4
};

int TribeTransportShipUnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    switch (event->mType) {
    case 0x1f4:
    case 0x20f:
        break;
    default:
        return UnitAIModule::processNotify(event, param_2);
    }

    if (event->p2 <= 0) {
        RGE_Static_Object* o = this->obj;
        ((RGE_Static_Object*)o->owner)->send_notify(o->id, o->id, 0x209, event->caller, 0, 0);
        this->purgeNotifyQueue(param_2);
        return 4;
    }

    if (this->helpCount == 0 || ((RGE_Player*)this->obj->owner)->computerPlayer() == 1) {
        RGE_Static_Object* o = this->obj;
        ((RGE_Static_Object*)o->owner)->send_notify(o->id, o->id, 0x201, event->caller, 0, 0);
    }

    int count = this->helpCount;
    int i = 0;
    if (count > 0) {
        int max = this->helpMax;
        do {
            if (i >= max) break;
            if (this->helpList[i] == event->caller) goto found_for_help;
            i++;
        } while (i < count);
    }
    if (((RGE_Player*)this->obj->owner)->computerPlayer() == 0 && this->currentTarget != event->caller) {
        this->askForHelp(event->caller);
    }

found_for_help:
    i = 0;
    int caller = event->caller;
    count = this->helpCount;
    if (count > 0) {
        int max = this->helpMax;
        do {
            if (i >= max) break;
            if (this->helpList[i] == caller) goto already_in_list;
            i++;
        } while (i < count);
    }

    if (this->helpCount > this->helpMax - 1) {
        int newMax = this->helpCount + 1;
        int* newList = (int*)operator new(newMax * 4);
        if (newList != 0) {
            i = 0;
            if (this->helpMax > 0) {
                do {
                    if (i >= newMax) break;
                    i++;
                    newList[i - 1] = this->helpList[i - 1];
                } while (i < this->helpMax);
            }
            operator delete(this->helpList);
            this->helpList = newList;
            this->helpMax = newMax;
        }
    }
    this->helpList[this->helpCount] = caller;
    this->helpCount++;

already_in_list:
    this->obj->set_something(1);
    if (this->currentOrder != -1) {
        return 2;
    }

    RGE_Static_Object* obj2 = this->obj;
    if (!obj2->action_list->have_action() || obj2->action_list->get_action()->state == 2) {
        ((ThisVTable*)this)->func_a4(1);
    }
    return 3;
}
