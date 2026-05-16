// VA: 00506CC0 TribeFishingShipUnitAIModule::processNotify
// Source: taiuaimd.cpp lines 2197-2276
// Attempt log:
// 1: natural reconstruction from packet with direct fields, virtual calls, dynamic int-list growth: broad mismatch; compiler cached NotifyEvent in EBP not original EDI.
// 2: add register event alias and use it throughout to try EDI allocation; no register change.
// 3: tried notification type gate as switch; no prologue/register improvement and slightly worse diff, rolled back.
// 4: tried narrow /O1 as possible register/prologue probe; object shrank to 521 and failed configured size, flag removed.
// 5: tried /O2 /Oy /Ob0 flag probe; same as default, flag removed.
// 6: remove event alias and use parameter directly to test whether alias caused EBP cache; no change.
// 7: corrected RGE_Player virtual padding so sendCommand is at vtable +0xE8 instead of +0x20; behavior surface improved but diff worsened due existing early register barrier.
// 8: reviewed late stopObject/vf58/vfA4 surface: current manual vtbl field is behaviorally suspect for ECX=this scheduling, but changing to full virtual class would require reworking all field offsets.
// 9: compared default vs flag/no-alias/switch variants; best byte metrics remain the natural default family before vtable padding, but kept vtable padding because it matches binary-observed +0xE8 call target.
// 10: left in scratch: main blocker is first prologue/register allocation (original EDI=NotifyEvent, ESI=this; rebuilt EBP=NotifyEvent), cascading through all event/list logic plus unresolved true class/vtable surface for late stop calls.

extern void* operator new(unsigned int sz);
extern void operator delete(void* p);
extern "C" int __cdecl fprintf(void* file, const char* fmt, ...);
extern void* actionFile;

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

struct NotifyEvent {
    int caller;
    char gap_04[4];
    int type;
    char gap_0C[4];
    int p2;
};

class RGE_Player {
public:
    VPAD32(rp0) VPAD16(rp32) VPAD8(rp48) VPAD2(rp56)
    virtual void sendCommand(int a, int b, int cmd, int target, int c, int d); // +E8
    int computerPlayer();
};

class UnitObj {
public:
    virtual void vf00();
    char gap_04[0x10 - 0x04];
    virtual void stopObject(int playerId, int obj1, int obj2, int minus1, int a, int b, int c, int d, int zero1, int zero2, int last); // +10
    char gap_14[0x58 - 0x14];
    virtual void vf58(int v); // +58
    char gap_5C[0xA4 - 0x5C];
    virtual void vfA4(int v); // +A4
};

class UnitAIModule {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void stopObject(int playerId, int obj1, int obj2, int minus1, int a, int b, int c, int d, int zero1, int zero2, int last); // +10
    char gap_14[0x58 - 0x14];
    virtual void vf58(int v);
    char gap_5C[0xA4 - 0x5C];
    virtual void vfA4(int v);

    UnitObj* vptr_obj; // actually vptr at +0, but fields modeled by offsets below through class layout
};

class TribeFishingShipUnitAIModule {
public:
    UnitObj* vtbl;
    struct PlayerSlot* slot; // +4
    char gap_08[0x28 - 0x08];
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    char gap_38[0x3C - 0x38];
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    char gap_4C[0x60 - 0x4C];
    int* list;
    int count;
    char gap_68[4];
    int max;

    int processNotify(NotifyEvent* ev, unsigned long flags);
    int base_processNotify(NotifyEvent* ev, unsigned long flags);
    void purgeNotifyQueue(unsigned long flags);
    void askForHelp(int id);
};

struct PlayerSlot {
    virtual void ps00();
    int player_id;
    char gap_08[4];
    RGE_Player* player;
    virtual void pad04(); virtual void pad08(); virtual void pad0C(); virtual void pad10(); virtual void pad14(); virtual void pad18(); virtual void pad1C();
    virtual void pad20(); virtual void pad24(); virtual void pad28(); virtual void pad2C(); virtual void pad30(); virtual void pad34(); virtual void pad38(); virtual void pad3C();
    virtual void pad40(); virtual void pad44(); virtual void pad48(); virtual void pad4C(); virtual void pad50(); virtual void pad54(); virtual void pad58(); virtual void pad5C();
    virtual void pad60(); virtual void pad64(); virtual void pad68(); virtual void pad6C(); virtual void pad70(); virtual void pad74(); virtual void pad78(); virtual void pad7C();
    virtual void pad80(); virtual void pad84(); virtual void pad88(); virtual void pad8C(); virtual void pad90(); virtual void pad94(); virtual void pad98(); virtual void pad9C();
    virtual void padA0(); virtual void padA4(); virtual void padA8(); virtual void padAC(); virtual void padB0(); virtual void padB4(); virtual void padB8(); virtual void padBC();
    virtual void padC0(); virtual void padC4(); virtual void padC8(); virtual void padCC(); virtual void padD0(); virtual void padD4(); virtual void padD8(); virtual void padDC();
    virtual void padE0(); virtual void padE4(); virtual void vfE8(int a, int b, int cmd, int target, int c, int d); virtual void vfEC(int v);
};

int TribeFishingShipUnitAIModule::processNotify(NotifyEvent* ev, unsigned long flags)
{
    if (ev->type != 500 && ev->type != 0x20f) {
        return this->base_processNotify(ev, flags);
    }

    if (ev->p2 <= 0) {
        RGE_Player* p = this->slot->player;
        int pid = this->slot->player_id;
        p->sendCommand(pid, pid, 0x209, ev->caller, 0, 0);
        this->purgeNotifyQueue(flags);
        return 4;
    }

    if (this->count == 0 || this->slot->player->computerPlayer() == 1) {
        RGE_Player* p2 = this->slot->player;
        int pid2 = this->slot->player_id;
        p2->sendCommand(pid2, pid2, 0x201, ev->caller, 0, 0);
    }

    int i = 0;
    if (this->count > 0) {
        do {
            if (i >= this->max) break;
            if (this->list[i] == ev->caller) goto skip_help;
            i++;
        } while (i < this->count);
    }
    if (this->slot->player->computerPlayer() == 0 && this->field_34 != ev->caller) {
        this->askForHelp(ev->caller);
    }

skip_help:
    i = 0;
    if (this->count > 0) {
        do {
            if (i >= this->max) break;
            if (this->list[i] == ev->caller) goto after_add;
            i++;
        } while (i < this->count);
    }
    if (this->count > this->max - 1) {
        int newMax = this->count + 1;
        int* newList = (int*)operator new(newMax * 4);
        if (newList != 0) {
            i = 0;
            if (this->max > 0) {
                do {
                    if (i >= newMax) break;
                    newList[i] = this->list[i];
                    i++;
                } while (i < this->max);
            }
            operator delete(this->list);
            this->list = newList;
            this->max = newMax;
        }
    }
    this->list[this->count] = ev->caller;
    this->count = this->count + 1;

after_add:
    this->slot->vfEC(1);
    if (this->slot->player->computerPlayer() == 0 && this->field_28 != -1) {
        return 2;
    }
    if (this->field_30 != 0x262) {
        this->vtbl->stopObject(this->slot->player_id, this->field_28, this->field_34, -1, this->field_3C, this->field_40, this->field_44, this->field_48, 0, 0, this->field_2C);
        if (actionFile != 0) {
            int pid = this->slot != 0 ? this->slot->player_id : -1;
            fprintf(actionFile, "#%d call stopObject %s %d\n", pid, "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x8d4);
        }
        this->vtbl->vf58(1);
    }
    this->vtbl->vfA4(1);
    return 3;
}
