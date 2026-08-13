// 004DE330 TribeInformationAIModule::higherPriorityObjectToDefend
// Source: taiinfmd.cpp lines 4527-4574
// Attempt log:
// 1: initial natural source: 18-byte frame, this in EDI, broad drift.
// 2: parameter-slot reuse attempt: mutate objId to unitZone, type to loop index, group to bestPriority; keep offset local for EBP. Frame 14, edit 51%.
// 3: remove count local: no change.
// 4: delay best initialization until after null check/currentZone: slightly better edit 50.5%, still frame 14.
// 5: store currentZone into low byte of objId parameter: removed and, edit 41.8%, but EBP became entry pointer.
// 6: raw importantObjectMemory+offset expressions made this register flip to EDI and regressed (edit 50.3%); rolled back to entry local despite EBP-as-pointer issue.
// 7: canonical indexed importantObjectMemory[i] outer scan improved positional diff
//    from 323 to 271 bytes, but retained a 0x14 frame and the wrong base/index
//    register split; the best source-shaped basin uses a local outer index and
//    the original numberValue/max-size inner-loop order.
// 8: moving the outer-index declaration before the initial lookup, explicit
//    max-size/count inner-loop variants, and a register-qualified offset either
//    regressed or produced duplicate codegen; restored the indexed form.
// 9: replaced the manual vtable/cast speed surface with the typed +0x10C virtual
//    declaration; emitted bytes were unchanged and the source is more canonical.
// Final pause: ordered calls and size match, but the remaining structural gap is
//    the 4-byte local frame plus EBP/base versus EDI/entry coloring (271 differing
//    bytes, 65.55% shape). No inline asm or custom flags retained.
// 10: direct typed indexed fields improved shape but added 8 bytes; rolled back.
// 11: retain a typed entry only through id/attack checks and recompute late fields
//     from the array; frame and size became exact, diff 252, shape 89.57%.
// 12: declaration reorder, hoisted entry, cached count, and typed reference were
//     duplicate or regressed; restored the pointer-based hybrid above.
// probes 22, 24, 28, 30: direct id-before-entry order, a persistent array base,
// hoisted entry lifetime, and entry scoping after the sentinel all increased
// the frame or worsened block shape; restored the best pointer hybrid.
// probe 26: canonical ManagedIntArray ownership preserved the emitted code.
// probe 27: pointer-addition spelling was a codegen duplicate.
// probe 32: canonical ObjectMemory and ManagedIntArray surfaces preserved the
// emitted code and are retained for source ownership.
// Current pause: calls, CFG counts, frame, size, and late blocks are aligned.
// Remaining first hunk is base/entry/id register allocation at +0x5D; no new
// evidence-backed source lead remains in this claim.
// probe 34: scoped the canonical array base inside each outer iteration to
// test the original reload feeding both id and entry address; duplicate codegen.

#include <math.h>

typedef unsigned char uchar;

struct ObjectMemory {
    int id;
    short type;
    short group;
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char owner;
    short hitPoints;
    unsigned char pad_0E[2];
    int attackAttempts;
    unsigned char kills;
    unsigned char pad_15[3];
    float damageCapability;
    float rateOfFire;
    float range;
};

struct XYPoint { int x; int y; };

struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class RGE_Static_Object {
public:
    virtual void d000(); virtual void d004(); virtual void d008(); virtual void d00C();
    virtual void d010(); virtual void d014(); virtual void d018(); virtual void d01C();
    virtual void d020(); virtual void d024(); virtual void d028(); virtual void d02C();
    virtual void d030(); virtual void d034(); virtual void d038(); virtual void d03C();
    virtual void d040(); virtual void d044(); virtual void d048(); virtual void d04C();
    virtual void d050(); virtual void d054(); virtual void d058(); virtual void d05C();
    virtual void d060(); virtual void d064(); virtual void d068(); virtual void d06C();
    virtual void d070(); virtual void d074(); virtual void d078(); virtual void d07C();
    virtual void d080(); virtual void d084(); virtual void d088(); virtual void d08C();
    virtual void d090(); virtual void d094(); virtual void d098(); virtual void d09C();
    virtual void d0A0(); virtual void d0A4(); virtual void d0A8(); virtual void d0AC();
    virtual void d0B0(); virtual void d0B4(); virtual void d0B8(); virtual void d0BC();
    virtual void d0C0(); virtual void d0C4(); virtual void d0C8(); virtual void d0CC();
    virtual void d0D0(); virtual void d0D4(); virtual void d0D8(); virtual void d0DC();
    virtual void d0E0(); virtual void d0E4(); virtual void d0E8(); virtual void d0EC();
    virtual void d0F0(); virtual void d0F4(); virtual void d0F8(); virtual void d0FC();
    virtual void d100(); virtual void d104(); virtual void d108();
    virtual float speed();
    int id;
    char gap_08[0x30];
    float world_x;
    float world_y;
    unsigned char currentZone();
    int withinRangeOfZoneAtPoint(unsigned char zone, float range, void* pt);
};

class MainDecisionAIModule {
public:
    char gap_00[0x04];
    RGE_Static_Object* object(int id);
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];
    MainDecisionAIModule* md;
    char gap_104[0x0C];
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;
    char gap_118[0x30];
    ManagedIntArray itemsToDefend;

    ObjectMemory* higherPriorityObjectToDefend(int objId, int type, int group);
    int defendPriority(int type, int group);
};

ObjectMemory* TribeInformationAIModule::higherPriorityObjectToDefend(int objId, int type, int group)
{
    RGE_Static_Object* mainObj = this->md->object(objId);
    ObjectMemory* best;
    if (mainObj == 0)
        return 0;

    *(unsigned char*)&objId = mainObj->currentZone();
    best = 0;
    group = this->defendPriority(type, group);
    int i = 0;
    if (this->maxImportantObjectMemory > 0) {
        do {
            ObjectMemory* entry = &this->importantObjectMemory[i];
            int id = entry->id;
            if (id != -1) {
                int j = 0;
                if (this->itemsToDefend.numberValue > 0) {
                    while (j < this->itemsToDefend.numberValue) {
                        if (j >= this->itemsToDefend.maximumSizeValue)
                            break;
                        if (this->itemsToDefend.value[j] == id) {
                            if (entry->attackAttempts <= 0) {
                                RGE_Static_Object* target = this->md->object(id);
                                if (target != 0) {
                                    if (target->currentZone() != *(unsigned char*)&objId) {
                                        XYPoint pt;
                                        pt.x = (int)target->world_x;
                                        pt.y = (int)target->world_y;
                                        if (mainObj->withinRangeOfZoneAtPoint(*(unsigned char*)&objId, mainObj->speed(), &pt) != 1)
                                            break;
                                    }
                                    int pri = this->defendPriority(
                                        this->importantObjectMemory[i].type,
                                        this->importantObjectMemory[i].group);
                                    if (pri < group) {
                                        group = pri;
                                        best = &this->importantObjectMemory[i];
                                    }
                                }
                            }
                            break;
                        }
                        j++;
                    }
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }
    return best;
}
