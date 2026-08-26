// TribeInformationAIModule::gameIDsOwnedBy (004D9970)
// taiinfmd.cpp:1559-1635, 279 bytes
// __thiscall: ecx=this, 3 stack params, ret 0Ch
// No SEH
//
// Status: grouped MATCH under the player-layout wrapper; not registered.
//
// Attempt log:
// Baseline: canonical ObjectMemory stride/fields, typed world lookup, and a
// natural dynamic output-array scan; 108 differing bytes.
// Probes 2-4: output aliases and killing the incoming output parameter did not
// change emitted code; the direct parameter surface was retained.
// Probe 5: moved delete outside the copy guard with a combined condition; it
// changed block shape and grew the emitted body, so it was rolled back.
// Probe 6: nested old-buffer/capacity copy guards plus an independent delete
// recovered the original size and reduced drift to 12 bytes.
// Probes 7-8: local declaration/assignment reorder was neutral at 12 bytes.
// Probe 9: declaration-time byte-offset initialization improved the localized
// stack-home schedule to 17 bytes; the guarded reset was retained as the next
// source-shape lead.
// Probe 10: keeping that guarded reset alongside the declaration initializer
// reduced drift to 6 bytes by restoring the original pre-guard local stores.
// Probe 11: a natural for-loop inside the old-buffer branch restored loop-init
// scheduling; exact MATCH (279/279 bytes).
// Probe 12: replaced the reduced ObjectMemory overlay and byte-offset scan
// with the complete typed record and indexed access. Standalone and grouped
// checks stayed exact, without raw field offsets or cursor arithmetic.
//
// Key findings:
// - This->md at +0x100 = TribeMainDecisionAIModule* (size 0x125C8)
// - md->aiPlayer at +0x1256C = TRIBE_Player*
// - aiPlayer->world at +0x3C = RGE_Game_World*
// - importantObjectMemory at +0x114, maxImportantObjectMemory at +0x110
// - ObjectMemory: id(+0x00), owner(+0x0B), stride 0x24
// - Capacity starts at 10, grows by *2, allocation is capacity*8
// - Output array stores int IDs at 4-byte indices
// - Uses platform-appropriate new/delete (not C++ new[])
// - The old output buffer is copied only in the positive-capacity branch, but
//   freed in a separate branch; this preserves the original conditional CFG.
// - The complete ObjectMemory layout and indexed access preserve the proven
//   0x24-byte stride while keeping the source as ordinary typed C++.
// - Main-agent audit restored canonical player/world/object/AI ownership while
//   preserving the exact binary-backed ObjectMemory stride schedule.

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class RGE_Game_World;
class RGE_Player;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[4];
    void* master_obj;
    RGE_Player* owner;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x84];
    void** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    void** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;

    RGE_Static_Object* object(int index);
};

class ObjectMemory {
public:
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

class TribeMainDecisionAIModule {
public:
    virtual ~TribeMainDecisionAIModule();
    char gap_04[0x12568];
    RGE_Player* aiPlayer;
};

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_04[0xFC];
    TribeMainDecisionAIModule* md;
    char gap_104[0xC];
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;

    int gameIDsOwnedBy(int owner_filter, int** out, int owner_id);
};
#endif

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);

#endif
int TribeInformationAIModule::gameIDsOwnedBy(int owner_filter, int** out, int owner_id)
{
    int count = 0;
    int capacity = 10;
    int i;
    *out = 0;
    i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            if (this->importantObjectMemory[i].id != -1) {
                RGE_Game_World* world = this->md->aiPlayer->world;
                RGE_Static_Object* obj = world->object(
                    this->importantObjectMemory[i].id
                );
                if (obj != 0) {
                    int ownerId = obj->owner->id;
                    if (ownerId == owner_id) {
                        if (owner_filter == -1 || owner_filter == this->importantObjectMemory[i].owner) {
                            if (count == capacity || *out == 0) {
                                int* new_arr = (int*)operator_new(capacity * 8);
                                if (*out != 0) {
                                    for (int j = 0; j < capacity; j++) {
                                        new_arr[j] = (*out)[j];
                                    }
                                }
                                capacity *= 2;
                                if (*out != 0) {
                                    operator_delete(*out);
                                }
                                *out = new_arr;
                            }
                            (*out)[count] = this->importantObjectMemory[i].id;
                            count++;
                        }
                    }
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return count;
}
