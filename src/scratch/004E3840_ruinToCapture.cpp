// VA: 004E3840 TribeInformationAIModule::ruinToCapture (393 B)
// PDB source: taiinfmd.cpp
// Attempt log:
// - Baseline used the canonical 0x24-byte ObjectMemory and a positive
//   indexed scan, but retained a record pointer and a cdecl vtable proxy
//   (360 bytes, 349 differing bytes).
// - Replaced the persistent record pointer with direct
//   importantObjectMemory[i] expressions and modeled md->player as the typed
//   vslot+0x18 owner-check virtual surface.  This restored ESI=this, EBP=the
//   byte offset, the 0x10 frame, all six ordered calls, and a 383-byte body
//   (171 differing bytes).
// - Declaration-only result locals, swapped result-local order, explicit
//   register declaration, direct integer result storage, explicit coordinate
//   locals, and base-plus-0x24 result addressing all emitted the same 383-byte
//   code; these were not retained as compiler-steering requirements.
// - A volatile result-local probe reached the expected 393-byte size but
//   changed the saved-register basin and broadened positional drift; rolled
//   back.  The living source remains typed and nonvolatile.
// - Fresh pass: declaration and initialization order, selected-result store
//   order, nested candidate branches, and proven polymorphic object surfaces
//   either duplicated the 383-byte basin or broadened drift; rolled back.
// - A 12-case lab covering natural local declaration orders and direct versus
//   indexed result-address forms emitted one identical 383-byte group.  No
//   new source-shape lead remains in this basin.
// - Paused after the ten-hypothesis budget.  Remaining localized gap is the
//   original townCenter/result callee-save allocation and the associated x87
//   argument scratch-slot order; no call target, CFG, frame, or field-layout
//   uncertainty remains.

#include <stdlib.h>

struct ObjectMemory {
    int id;                             // +0x00
    short type;                         // +0x04
    short group;                        // +0x06
    unsigned char x;                    // +0x08
    unsigned char y;                    // +0x09
    unsigned char z;                    // +0x0A
    unsigned char owner;                // +0x0B
    short hitPoints;                    // +0x0C
    unsigned char pad_0E[2];            // +0x0E
    int attackAttempts;                 // +0x10
    unsigned char kills;                // +0x14
    unsigned char pad_15[3];            // +0x15
    float damageCapability;             // +0x18
    float rateOfFire;                   // +0x1C
    float range;                        // +0x20
};

class RGE_Player {
public:
    virtual void vt00();
    virtual void vt04();
    virtual void vt08();
    virtual void vt0C();
    virtual void vt10();
    virtual void vt14();
    virtual int isEnemy(int playerNum); // vslot +0x18
};

class RGE_Static_Object {
public:
    char gap_00[0x48];
    unsigned char object_state;         // +0x48

    float distance_to_position(float x, float y, float z);
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;                 // +0xF0

    RGE_Static_Object* object(int p1, int p2, int p3, int p4, int p5,
                              int p6, int p7, int p8, int p9, int p10);
    RGE_Static_Object* object(int id);
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];
    MainDecisionAIModule* md;           // +0x100
    char gap_104[0x0C];
    int maxImportantObjectMemory;       // +0x110
    ObjectMemory* importantObjectMemory; // +0x114

    int numberUnitsWithinXTiles(int playerFilter, int x, int y, int range);
    ObjectMemory* ruinToCapture(int playerFilter);
};

ObjectMemory* TribeInformationAIModule::ruinToCapture(int playerFilter)
{
    RGE_Static_Object* townCenter;
    ObjectMemory* bestMemory;
    int bestResult;
    int i;

    townCenter = this->md->object(
        -1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
    bestMemory = 0;
    bestResult = -1;
    i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            if (this->importantObjectMemory[i].type == 0x9E ||
                this->importantObjectMemory[i].type == 0xA3) {
                if (playerFilter == -1 ||
                    (unsigned int)this->importantObjectMemory[i].owner ==
                        (unsigned int)playerFilter) {
                    if (playerFilter != -1 ||
                        this->md->player->isEnemy(
                            this->importantObjectMemory[i].owner) != 0) {
                        RGE_Static_Object* object = this->md->object(
                            this->importantObjectMemory[i].id);

                        if (object != 0 && object->object_state <= 2) {
                            int result = this->numberUnitsWithinXTiles(
                                playerFilter,
                                this->importantObjectMemory[i].x,
                                this->importantObjectMemory[i].y, 5);

                            if (townCenter != 0) {
                                result = (int)townCenter->distance_to_position(
                                    (float)this->importantObjectMemory[i].x,
                                    (float)this->importantObjectMemory[i].y,
                                    (float)this->importantObjectMemory[i].z) * result;
                            }

                            if (bestMemory == 0 || result < bestResult) {
                                bestResult = result;
                                bestMemory = &this->importantObjectMemory[i];
                            }
                        }
                    }
                }
            }

            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return bestMemory;
}
