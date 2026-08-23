// 004F0D70 TribeTacticalAIModule::addObject
// PDB: taitacmd.cpp lines 3098-3167
//
// Attempt log:
// - Earlier source used an add_unique_scan helper and wrong list offsets.
//   It collapsed the four inline scan blocks and produced a 500-byte body.
// - The binary uses one shared resize/append tail for civilians and soldiers.
//   Boat and subtype lists use separate inline bodies.
// - Fresh typed reconstruction: model the ten ManagedArray fields at their
//   proven offsets and use the declaration-only period array methods.
// - Baseline direct scans with do/while loops rebuilt 879 bytes and aligned
//   all 11 calls.  Matching the same-TU for-loop donor reduced this to 839.
// - Loading each subtype list before contains reduced the body to 825 bytes.
//   The player/world correction then reduced it to 822 bytes and aligned the
//   difficulty chain at md->player->world (+0x3c).
// - A split scan-ID/contains-ID local reduced size to 801 but worsened byte
//   alignment.  It was restored.  Current source is the 822-byte candidate:
//   all calls and list offsets align, but register ownership and several
//   subtype blocks still differ.
// - Session shardA4: direct `this`/parameter use, declaration reordering, and
//   the donor-backed TacticalAIModule virtual base were natural ABI probes;
//   each was a codegen duplicate.
// - The original has a dedicated boat-chain return before the shared
//   civilian/soldier append.  Added that return and the fishing early-return
//   form; returns became 3/3 and exact-block coverage improved to 60.66%, but
//   the 822-byte body and first prologue mismatch remained.
// - A preincrement resize capacity form was also a codegen duplicate and was
//   restored to the clearer `number + 1` spelling.
// - Same-TU AIModule base spelling and a full base gap were codegen duplicates
//   at 822 bytes; the structural prologue and four ID spill gaps were unchanged.
// - Restoring the binary-supported persistent object alias in the current
//   virtual-base context was also a duplicate.  A register-ID diagnostic was
//   unchanged, so the clean typed candidate remains authoritative.
// - Revisit session: the clean 822-byte source rebuilt with 11/11 ordered
//   calls, no frame, 570 strict diff bytes, and 60.66% exact-block coverage.
// - Tested persistent object aliases, parameter-home mutation, the Ghidra
//   local topology, a typed parameter-home reference, delayed initialization,
//   register-qualified parameter/ID locals, a flat class prefix, local-order
//   changes, and combined scan predicates.  These were duplicates or worse.
// - Tested non-register object and receiver aliases, direct member scans,
//   stdlib/string/windows headers, their combination, and a receiver reference.
//   Each emitted the same 822-byte candidate.
// - Branch-local subtype IDs changed the basin to 777 bytes and 747 strict
//   diff bytes, but lost structural alignment and was restored.
// - The remaining mismatch is register ownership: the original keeps the
//   parameter in EBX, this in EBP, and the repeated ID in EDI.  The clean
//   source keeps the same behavior and calls but assigns another register
//   basin, spilling the ID after three resize calls.
// - ManagedArray recovery replaced the four caller-side scan/append copies
//   with direct calls to the exact add body. This recovered the original
//   parameter, receiver, and ID registers and all inline blocks.
// - The artifact add at line 3165 remains out of line in the executable, while
//   all four later add sites inline. A narrow inline-depth limit preserves this
//   proved same-TU split. Without it, VC5 inlines the artifact add and emits an
//   extra resize call. Restoring the depth immediately gives an exact match.
// - Exact-finish reduction removed four redundant returns and flattened the
//   soldier else-if. Both reductions remained exact.
// - The shared template surface initially inlined three contains calls and
//   moved the function into an 816-byte register basin. The executable keeps
//   all three calls out of line. One narrow inline-depth region restores the
//   exact isolated and grouped output without changing nearby exact owners.

#ifndef TAITACMD_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0c];
    short id;
    char gap_12[2];
    short object_group;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
};

class RGE_Game_World {
public:
    char gap_00[0x3c];
    int difficultyLevel();
};

class RGE_Player {
public:
    char gap_00[0x3c];
    RGE_Game_World* world;
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0xf0];
    RGE_Player* player;
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int resize(int new_size);
    int contains(const T& wanted) const;
    int add(T item) {
        int i;
        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                break;
            if (this->value[i] == item)
                return 0;
        }
        if (this->numberValue > this->maximumSizeValue - 1)
            this->resize(this->numberValue + 1);
        this->value[this->numberValue] = item;
        this->numberValue++;
        return 1;
    }
};

class TacticalAIModule {
public:
    virtual ~TacticalAIModule();
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    char gap_04[0xec];
    TribeMainDecisionAIModule* md;
    ManagedArray<int> civilians;
    ManagedArray<int> civilianExplorers;
    ManagedArray<int> soldiers;
    ManagedArray<int> ungroupedSoldiers;
    ManagedArray<int> boats;
    ManagedArray<int> warBoats;
    ManagedArray<int> fishingBoats;
    ManagedArray<int> tradeBoats;
    ManagedArray<int> transportBoats;
    ManagedArray<int> artifacts;

    void addObject(RGE_Static_Object* obj);
};
#endif

void TribeTacticalAIModule::addObject(RGE_Static_Object* obj)
{
    short group = obj->master_obj->object_group;
    int id;
    int number;
    int i;
    ManagedArray<int>* list;

    if (group == 4) {
        this->civilians.add(obj->id);
    } else if (group == 0 || group == 0x18 || group == 6 || group == 0x19 ||
               group == 0x1a || group == 0x0c || group == 0x23 ||
               group == 0x17 || group == 0x24 || group == 0x1c ||
               group == 0x12 || group == 0x0d || group == 0x27) {
        this->soldiers.add(obj->id);
    } else {
        if (group != 2 && group != 0x14 && group != 0x16 && group != 0x15) {
            if (obj->master_obj->id != 0x9f)
                return;
            if (this->md->player->world->difficultyLevel() >= 4)
                return;
            // BINARY NOTE: This call stays out of line. Later add calls inline.
#pragma inline_depth(0)
            this->artifacts.add(obj->id);
#pragma inline_depth(255)
            return;
        }

        this->boats.add(obj->id);
        if (obj->master_obj->object_group == 2) {
            this->tradeBoats.add(obj->id);
        }

        if (obj->master_obj->object_group == 0x14) {
            id = obj->id;
            list = &this->transportBoats;
            // BINARY NOTE: These contains and resize sites stay out of line.
#pragma inline_depth(0)
            if (list->contains(id) != 1) {
                number = list->numberValue;
                if (number > list->maximumSizeValue - 1)
                    list->resize(number + 1);
                list->value[list->numberValue] = id;
                list->numberValue++;
            }
        }

        if (obj->master_obj->object_group == 0x16) {
            id = obj->id;
            list = &this->warBoats;
            if (list->contains(id) != 1) {
                number = list->numberValue;
                if (number > list->maximumSizeValue - 1)
                    list->resize(number + 1);
                list->value[list->numberValue] = id;
                list->numberValue++;
            }
        }

        if (obj->master_obj->object_group == 0x15) {
            id = obj->id;
            list = &this->fishingBoats;
            if (list->contains(id) == 1)
                return;
            number = list->numberValue;
            if (number > list->maximumSizeValue - 1)
                list->resize(number + 1);
#pragma inline_depth(255)
            list->value[list->numberValue] = id;
            list->numberValue++;
        }
    }
}
