// 004DEA80 TribeInformationAIModule::objectToTradeWith
// taiinfmd.cpp:4736-4787, 277 bytes
//
// Attempt log:
// - Recovered typed ObjectMemory, player, object, and module surfaces from
//   exact same-TU donors 004E1BD0 and 004D7070.
// - ObjectMemory has id +0x00, type +0x04, x +0x08, y +0x09,
//   owner +0x0B, and a 0x24-byte stride. Player id is at +0x4A.
// - The natural scan keeps the sentinel, owner, type, dock-attribute, and
//   nearest squared-distance tests in the original order.
// - Direct indexed records added 15 bytes and a larger frame. A typed pointer
//   walk reduced the frame and moved farther from the original scan.
// - The current indexed typed candidate has the original size, frame, and four
//   ordered calls. Its 117 differing bytes start at the coordinate conversion.
// - Split coordinate statements and candidate assignment forms emit the same
//   117-byte result. No raw cursor or compiler-steering form is retained.
// Exact-finish pass:
// - Fresh validation keeps the original 277-byte boundary, 0x0C frame, owner
//   symbol, four ordered direct calls, and all pre-distance blocks exact.
// - Tested direct record reads, delayed and scoped candidate declarations,
//   reference and pointer forms, result declaration/store order, coordinate
//   temporary order, and period-style register qualifiers. These forms stayed
//   in the same arithmetic basin or changed earlier structure.
// - The remaining supported mismatch starts at the coordinate block: VC5 emits
//   `add esi,ebp` and candidate ESI before the first fld; the executable emits
//   `lea edi,[ecx+ebp]` after loading unit x, then rereads unit and publishes
//   candidate EDI. No tested natural source form recovered that schedule.
// Accepted-drift review: both versions capture importantObjectMemory before
// the first _ftol call, then convert unit x and y in the same order. The rebuild
// computes the candidate address earlier with ADD and reads candidate x before
// reloading the unit pointer from its private stack home. The executable does
// the stack reload first. This changes no object access, call, x87 operand,
// selected candidate, distance, or return value. All four calls match.

extern float DAT_00575580;

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x46];
    short id;                         // +0x4A
    char gap_4C[4];
    float* attributes;                // +0x50
};

#endif
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;                            // +0x04
    void* master_obj;                 // +0x08
    RGE_Player* owner;                // +0x0C
    char gap_10[0x28];
    float x;                           // +0x38
    float y;                           // +0x3C
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;               // +0xF0

    RGE_Static_Object* object(int object_id);
};

struct ObjectMemory {
    int id;                           // +0x00
    short type;                       // +0x04
    short group;                      // +0x06
    unsigned char x;                  // +0x08
    unsigned char y;                  // +0x09
    unsigned char z;                  // +0x0A
    unsigned char owner;              // +0x0B
    short hitPoints;                  // +0x0C
    unsigned char pad_0E[2];
    int attackAttempts;               // +0x10
    unsigned char kills;              // +0x14
    unsigned char pad_15[3];
    float damageCapability;           // +0x18
    float rateOfFire;                 // +0x1C
    float range;                      // +0x20
};

#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_04[0xFC];
    MainDecisionAIModule* md;         // +0x100
    char gap_104[0x0C];
    int maxImportantObjectMemory;     // +0x110
    ObjectMemory* importantObjectMemory; // +0x114

    ObjectMemory* objectToTradeWith(int param_1);
};
#endif
#endif

#endif
ObjectMemory* TribeInformationAIModule::objectToTradeWith(int param_1)
{
    RGE_Static_Object* unit = this->md->object(param_1);
    if (unit == 0)
        return 0;

    ObjectMemory* bestDock = 0;
    int bestDockDistance = 0;
    int i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            if (this->importantObjectMemory[i].id != -1 &&
                this->importantObjectMemory[i].owner != this->md->player->id &&
                this->importantObjectMemory[i].type == 0x2D) {
                RGE_Static_Object* dock = this->md->object(
                    this->importantObjectMemory[i].id);
                if (dock != 0 && dock->owner->attributes[9] > DAT_00575580) {
                    ObjectMemory* candidate = &this->importantObjectMemory[i];
                    int dx = (int)candidate->x - (int)unit->x;
                    int dy = (int)candidate->y - (int)unit->y;
                    int dist = dx * dx + dy * dy;
                    if (bestDock == 0 || dist < bestDockDistance) {
                        bestDock = candidate;
                        bestDockDistance = dist;
                    }
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return bestDock;
}
