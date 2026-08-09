// 004E3E90 TribeInformationAIModule::numberAvailableStoragePits (taiinfmd.cpp:8079-8129)
// Attempt log:
// - baseline decompiler-shaped reconstruction: 109 differing bytes; calls/CFG
//   were complete but the zone methods were incorrectly modeled as int.
// - exact same-TU granaries donor supplied unsigned-char currentZone/lookupZone
//   returns with byte masks: 15 differing bytes, 238/238 bytes and all calls,
//   blocks, and widths aligned.
// - flat-vs-inherited class surface, named md alias, combined object guard,
//   top-declared object locals, proven polymorphic base surface, and reused
//   decompiler int role all emitted the same 15-byte register-coloring basin
//   (or regressed structurally for the md alias/positive outer guard).
// - sibling 00501B90's exhaustive register/source-shape work was not repeated;
//   its remaining md/product callee-save basin is consistent with this target's
//   unresolved this/md and second-object register swap.
// - Best retained reconstruction: canonical typed ownership and donor-backed
//   byte-return zone ABI; remaining drift is 15 register/address encoding bytes
//   (original this=EDI/md=ESI/obj2=ESI, rebuilt this=ESI/md=EDI/obj2=EDI).
// - Main-agent audit replaced the raw +0x1146C cast with the exact-donor-backed
//   TribeMainDecisionAIModule::tacticalAI member; codegen is unchanged.
// - Session probes: caching md for the age/first-object phase either regressed
//   broadly when used throughout or emitted the same 15-byte basin when its
//   lifetime was narrowed; restored the direct canonical source.
// - Session probes: donor declaration order, top-declared zone/object locals,
//   a register-qualified md alias, inherited AIModule/MainDecision object
//   surfaces, a named self alias, combined age decrement, and stdlib TU context
//   all emitted the same 238-byte/15-byte-drift basin (the md/this and second
//   object register swap remains). Restored the canonical typed source.

class RGE_Static_Object;

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class InformationAIModule : public AIModule {
public:
    virtual ~InformationAIModule();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x4C];
    float* attributes;
};

class TribeTacticalAIModule {
public:
    int strategicNumber(int);
};

class TribeMainDecisionAIModule {
public:
    virtual ~TribeMainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;   // +0xF0
    char gap_F4[0x1146C - 0xF4];
    TribeTacticalAIModule tacticalAI;

    RGE_Static_Object* object(int);
    RGE_Static_Object* object(int, int, int, int, int, int, int, int, int, int);
};

class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

// Main-agent audit confirmed canonical AI/player/master ownership and retained
// the natural storage-pit count.
class TribeInformationAIModule : public InformationAIModule {
public:
    ManagedArray_int farmsTaskedThisUpdate;       // +0xF0
    TribeMainDecisionAIModule* md;                // +0x100
    char gap_104_to_500[0x500 - 0x104];
    int dropsitesByAge[4][4];                     // +0x500
    int closestDropsiteValue[4];                  // +0x540
    int closestDropsiteResourceID[4];             // +0x550

    int numberAvailableStoragePits(int param_1);
};

class RGE_Static_Object {
public:
    char gap_00[0x38];
    float field_0x38;
    float field_0x3C;

    unsigned char currentZone();
    unsigned char lookupZone(int, int);
};

int TribeInformationAIModule::numberAvailableStoragePits(int param_1)
{
    int age_idx = (int)(this->md->player->attributes[6]);
    age_idx--;

    if (age_idx < 0) {
        age_idx = 0;
    } else if (age_idx > 3) {
        age_idx = 3;
    }

    if (this->dropsitesByAge[param_1][age_idx] == 0) {
        return 0;
    }

    RGE_Static_Object* obj1 = this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);

    if (obj1 != 0) {
        RGE_Static_Object* obj2 = this->md->object(this->closestDropsiteResourceID[param_1]);

        if (obj2 != 0) {
            int zone = obj1->currentZone() & 0xff;
            int y = (int)(obj2->field_0x3C);
            int x = (int)(obj2->field_0x38);
            int lookup = obj1->lookupZone(x, y) & 0xff;

            if (zone != lookup) {
                return 0;
            }
        }
    }

    int strategicN = this->md->tacticalAI.strategicNumber(param_1 + 0xA3);
    return (this->closestDropsiteValue[param_1] > strategicN) ? 1 : 0;
}
