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
// - Fresh bounded pass: swapped top-level obj1/obj2 declarations; used a
//   canonical MainDecision base-typed md phase and base-typed md member; all
//   retained the same 238-byte/15-byte basin.
// - Reference and const md aliases worsened to a 184-byte diff with a frame;
//   both were restored. A 48-variant body/source-order lab and a 384-variant
//   class-surface lab (base/vtable/object/local declaration combinations)
//   found no exact result; every invariant-eligible group remained 238 bytes
//   with the same 15 register/address mismatches. The clean typed source is
//   retained; the remaining blocker is a stable VC5 this/md/second-object
//   allocator basin rather than behavior, layout, or call-set uncertainty.
// - wave20 bounded pass: target destructor, obj1/obj2 register hints, full
//   target size, full AIModule virtual slots, self alias, math.h context,
//   function-scope local declarations, and a scoped tacticalAI alias all
//   emitted the same 238-byte/15-byte basin. A four-variant canonical
//   AIModule/MainDecision virtual-surface lab produced two stable groups,
//   both with the same first mismatch at +3; no exact or structural lead.
// - Fresh bounded pass: a direct MainDecision-typed md widened the drift to
//   19 bytes; inherited MainDecision object surfaces gave 16 bytes. Explicit
//   MainDecision casts for both object calls stayed at 15 bytes with no code
//   movement. Restored the typed TribeMainDecision ownership.
// - Fresh context probes: stdlib/string and windows.h header pairs left the
//   same 238-byte/15-byte basin. VC5 rejects __restrict; no probe was kept.
// - Added the complete same-TU donor declaration tail from exact donor 004D9970
//   (the +0x1256C aiPlayer field) without changing the natural function body;
//   emitted code stayed at 238 bytes with the same 15-byte register basin.
// - Fresh nested-layout probe: the minimal typed MainDecision/build/
//   information/resource/tactical parent surface regressed to 18 bytes;
//   restore the exact 00501D70 nested shape before further comparison.
// - Full 00501D70 nested class surface, inherited MainDecision object calls,
//   and full informationAI size restored the 238-byte/15-byte basin. Adding
//   TacticalAIModule inheritance also stayed in that basin.
// - Inlining coordinate conversions and naming the final available count were
//   codegen duplicates. A phase-local decision alias widened the drift to 133
//   bytes and was restored. No localized liveness lead changed the stable
//   this=ESI/md=EDI/obj2=EDI allocator basin.
// - Current lease baseline reconfirmed the clean 238-byte basin.  The
//   remaining 15 bytes are the stable this/md/second-object register swap;
//   no new source or ABI lead is justified without repeating prior probes.

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

class TribeMainDecisionAIModule;

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    char gap_F4[0x10];

    RGE_Static_Object* object(int);
    RGE_Static_Object* object(int, int, int, int, int, int, int, int, int, int);
};

class BuildAIModule : public AIModule {
public:
};

class TribeBuildAIModule : public BuildAIModule {
public:
    char gap_F0[0x5C0 - 0xF0];

    virtual int loggingHistory();
    virtual void setLogHistory(int value);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char* filename);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int value);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char* filename);
    virtual int saveState(char* filename);
    virtual int gleanState(int value);
    virtual int processMessage(void* message);
    virtual int update(int value);
    virtual void setCallbackMessage(void* message);
    virtual int filterOutMessage(void* message);
    virtual int save(int value);
    virtual void displayBuildList();
    virtual int loadBuildList(char* filename, void* player);
    virtual int numberBuiltOrInProgressItemsOfType(int type, int mode);
};

class TribeResourceAIModule : public AIModule {
public:
    char gap_F0[0x08];
};

class TacticalAIModule : public AIModule {
public:
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    int strategicNumber(int);
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
    char gap_560_to_10090[0x10090 - 0x560];

    int numberAvailableStoragePits(int param_1);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule buildAI;
    char gap_6C4[0xCEC - 0x6C4];
    TribeInformationAIModule informationAI;
    TribeResourceAIModule resourceAI;
    char gap_10E74[0x1146C - 0x10E74];
    TribeTacticalAIModule tacticalAI;
    char gap_11560[0x1256C - 0x11560];
    RGE_Player* aiPlayer;
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
