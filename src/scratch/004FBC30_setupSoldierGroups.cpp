// 004FBC30 TribeTacticalAIModule::setupSoldierGroups
// Source: taitacmd.cpp lines 9347-9674
//
// Baseline: period-plausible typed reconstruction.  ManagedArray growth/removal
// uses the established inline operator[]/remove surfaces; the local list uses
// the out-of-line resize member, as shown by the original call at 004147A0.
// FLAGS: config/flags/004FBC30_setupSoldierGroups.rsp (/GX for the observed EH frame).
//
// Attempt log:
// - default flags, no ManagedArray destructor: 2156 bytes, no EH frame; rolled
//   back after confirming the target's FS registration requires a nontrivial
//   local lifetime.
// - /GX alone was codegen-identical; adding the natural ManagedArray destructor
//   produced the target EH family and a 2200-byte reconstruction.
// - complete destructor field clearing was codegen-identical to the delete-only
//   body after dead-store elimination.
// - function-scope numPotentialAGroups models the FPU remainder home; the
//   constructor form preserves the original zero-store scheduling and is kept.
// - worker astra (2026-08): structural audit found the original does NOT reset
//   numAGroups/i before the workingArea loop; the leftover numAGroups is used as
//   the workingArea index (general operator[] growth, no const-fold to element 0).
//   Removed the pre-loop reset; moved `i = 0; numAGroups = 0;` to after the loop.
// - time-check: original computes BOTH /1000 divisions into named locals before
//   the test (rebalance statement first, attack second; test attack-first).
//   The inline && short-circuits in VC5; named locals reproduce the dual mul/shr.
// - compare operand orders per original asm: while(numDGroups>newArtifact),
//   while(numEGroups>i), while(local_24>numAGroups), else-arm
//   numPotentialAGroups >= sn[0x24] with a named maxArtifact temp (original loads
//   sn[0x24] on its own source line 9494 first).
// - else-arm i as min(...) (ternary/if-else) stores i after the subtraction;
//   this flipped the frame to 0x2C and the balance register basin (zero=ebp,
//   newArtifact=ebx, product=edi CSE across the ceil call via the artifactUnits
//   local).  Current best: 2245/2241 bytes (+4), frame 0x2C/0x2C, 69/69 calls,
//   exact CFG, 760 positional diff bytes (was 1998), edit diff 230.
// BINARY NOTE: the original balance block keeps numAGroups at [esp+18h],
// newArtifact at [esp+10h], and the zero value in EBP across all three ceil
// paths.  The clean source below reaches the same frame and call surface, but
// VC5 selects the opposite two homes and rematerializes zero after __ftol.
// BINARY NOTE: the original carries numAGroups into the workingArea index;
// there is no reset before that loop.  Keep this shipped behavior.
// LIKELY INTENT: the balance block is a direct group-count calculation with
// short-lived remainder values.  Named product and max-bound locals preserve
// the closest clean VC5 basin, even though direct expressions are simpler.
// Probe summary: 20 evidence-led local, predicate, loop, declaration, and
// expression variants were equal or worse.  The home swap remains unresolved.
// Remaining leads (allocator coloring, not structure):
// 1. numAGroups/newArtifact stack-home swap: rebuilt homes numAGroups at
//    [esp+10h] and newArtifact at [esp+18h]; original has them swapped.
//    Declaration order (tried 5 orders) does not affect it.  It is tied to the
//    zero-register liveness below; the first strict mismatch is this slot in the
//    removeGroup loop (+0184).
// 2. zero-register liveness: original keeps the balance-entry zero in ebp live
//    across the ceil calls (`cmp eax,ebp` at the <=0 remainder checks); rebuilt
//    rematerializes `test eax,eax`, which frees ebp for i (mov ebp,eax after
//    __ftol) instead of ecx, and flips the product imuls to loaded-first forms
//    (+4 bytes total).  The imul folding (`imul edi,[esi+1D4h]` vs
//    `mov edi,[esi+1D4h]; imul edi,ebx`) is a scheduling symptom of the same.
// 3. first-path i clamp stores early (default-then-override) in BOTH versions;
//    else path stores i after the sub (min form) - already matched.
// No fake volatility, manual vtables, opaque scaffolding or inline asm retained.
// ManagedArray recovery pass, 2026-08-19:
// - Replacing the complete local surface with include/utmarray.h made resize
//   inline twice. It added two allocator pairs and 214 bytes. The original
//   calls resize at both add sites, so the shared-header form is not valid in
//   this isolated translation unit.
// - The exact add body with declaration-only resize emits the same 2245-byte
//   frontier as the former manual scans. It matches the PDB line ownership and
//   removes unsupported caller-side field access. Keep this source model.

void* operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

extern "C" int __cdecl debug_rand(char* file, int line);
extern "C" double __cdecl ceil(double value);

class RGE_Static_Object;
class RGE_Game_World;
class RGE_Player;
class MainDecisionAIModule;
class TribeMainDecisionAIModule;
class TribeInformationAIModule;
class TacticalAIGroup;

class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ManagedArray_int()
        : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}

    ~ManagedArray_int() {
        if (this->value != 0) {
            operator_delete(this->value);
            this->value = 0;
        }
        this->numberValue = 0;
        this->desiredNumberValue = 0;
        this->maximumSizeValue = 0;
    }

    int resize(int new_size);

    int& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            int* new_data = (int*)operator_new(new_size * 4);
            if (new_data != 0) {
                for (int i = 0; i < this->maximumSizeValue && i < new_size; ++i) {
                    new_data[i] = this->value[i];
                }
                operator_delete(this->value);
                this->value = new_data;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }

    int add(int item) {
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

    int remove(int value_to_remove) {
        int i = 0;
        int max = this->maximumSizeValue;
        for (; i < max; ++i) {
            if (this->value[i] == value_to_remove) {
                break;
            }
        }
        if (i >= max) {
            return 0;
        }
        --max;
        if (i < max) {
            do {
                this->value[i] = this->value[i + 1];
                ++i;
            } while (i < this->maximumSizeValue - 1);
        }
        int count = this->numberValue - 1;
        this->numberValue = count;
        if (count < 0) {
            this->numberValue = 0;
        }
        return 1;
    }
};

class RGE_Game_World {
public:
    void* vtable_ptr;
    unsigned long world_time;
    char gap_08[0x34];

    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    int id;
    char gap_08[0x30];
    float world_x;
    float world_y;
    float world_z;
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;

    RGE_Static_Object* object(int id);
    RGE_Static_Object* object(int object_id, int type, int class_id, int action,
                              int has_order_filter, int resource_class,
                              int resource_subclass, int state, int min_hit_points,
                              int civilization);
};

class TribeInformationAIModule {
public:
    int fullyExploredZone(int object_id);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_F4[0xCEC - 0xF4];
    TribeInformationAIModule informationAI;
};

class TacticalAIGroup {
public:
    void* vtable_ptr;
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    char gap_0C[0x330 - 0x0C];

    int numberUnits() const;
    int id() const;
    int type() const;
    void setType(int value);
    void setDesiredNumberUnits(int value);
    int addUnit(int object_id, TribeMainDecisionAIModule* md);
    void setSpecificCommander(int object_id, TribeMainDecisionAIModule* md);
    void setLocation(float x, float y, float z);
    void setGatherLocation(float x, float y, float z);
    void setRetreatLocation(float x, float y, float z);
    void setTarget(int value);
    void setTargetType(int value);
    void setAction(int value);
    void setInUse(int value);
};

class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    TribeMainDecisionAIModule* md;
    ManagedArray_int civilians;
    ManagedArray_int civilianExplorers;
    ManagedArray_int soldiers;
    ManagedArray_int ungroupedSoldiers;
    ManagedArray_int boats;
    ManagedArray_int warBoats;
    ManagedArray_int fishingBoats;
    ManagedArray_int tradeBoats;
    ManagedArray_int transportBoats;
    ManagedArray_int artifacts;
    int sn[0xE2];
    char gap_51C[0x9D4 - 0x51C];
    TacticalAIGroup groups;
    int groupIDValue;
    int numberGroupsValue;
    unsigned long lastGroupAttackTime;
    unsigned long lastGroupRebalanceTime;
    char gap_D14[0xD48 - 0xD14];
    ManagedArray_int workingArea;

    TacticalAIGroup* createGroup(int assign_id);
    int removeGroup(int id);
    int removeAllGroups(int type);
    void setStrategicNumber(int index, int value);
    int numberGroups(int type, int action);
    int numberUngroupedArtifacts();
    TacticalAIGroup* group(int id, int type, int action, int target);

    void setupSoldierGroups();
};

void TribeTacticalAIModule::setupSoldierGroups()
{
    ManagedArray_int groupsToRemove;
    int newArtifact;
    int i;
    int numAGroups;
    int numDGroups;
    int numEGroups;
    int local_24;
    int numPotentialAGroups;
    TacticalAIGroup* sentinel;
    TacticalAIGroup* group;

    group = this->groups.next;
    sentinel = &this->groups;
    while (group != sentinel && group != 0) {
        if (group->numberUnits() == 0) {
            groupsToRemove.add(group->id());
        }
        group = group->next;
    }

    unsigned long timeSinceRebalance =
        (this->md->player->world->world_time - this->lastGroupRebalanceTime) / 1000;
    unsigned long timeSinceAttack =
        (this->md->player->world->world_time - this->lastGroupAttackTime) / 1000;
    if (timeSinceAttack > 600 && timeSinceRebalance > 600) {
        this->lastGroupRebalanceTime = this->md->player->world->world_time;
        group = this->groups.next;
        while (group != sentinel && group != 0) {
            if (group->type() == 100) {
                groupsToRemove.add(group->id());
            }
            group = group->next;
        }
    }

    numAGroups = 0;
    while (numAGroups < groupsToRemove.numberValue) {
        this->removeGroup(groupsToRemove[numAGroups]);
        ++numAGroups;
    }

    if (this->md->informationAI.fullyExploredZone(this->soldiers[0]) == 0) {
        this->removeAllGroups(0x66);
        this->setStrategicNumber(0x2A, 0);
    }

    numDGroups = this->numberGroups(100, -1);
    numEGroups = this->numberGroups(101, -1);
    local_24 = this->numberGroups(102, -1);
    this->numberGroups(109, -1);
    this->numberUngroupedArtifacts();

    while (this->workingArea.numberValue > 0) {
        int object_id = this->workingArea[numAGroups];
        RGE_Static_Object* object = this->md->object(object_id);
        if (object == 0) {
            this->workingArea.remove(object_id);
        }
        else {
            RGE_Static_Object* retreat = this->md->object(
                -1, -1, 0x6D, -1, -1, -1, -1, -1, -1, -1);
            if (retreat == 0) {
                this->workingArea.remove(object_id);
            }
            else {
                TacticalAIGroup* new_group = this->createGroup(1);
                if (new_group == 0) {
                    break;
                }
                new_group->setType(0x6D);
                new_group->setDesiredNumberUnits(1);
                new_group->addUnit(object_id, this->md);
                new_group->setSpecificCommander(object_id, this->md);
                new_group->setLocation(object->world_x, object->world_y, object->world_z);
                new_group->setGatherLocation(object->world_x, object->world_y, object->world_z);
                new_group->setRetreatLocation(retreat->world_x, retreat->world_y, retreat->world_z);
                this->workingArea.remove(object_id);
            }
        }
    }

    i = 0;
    numAGroups = 0;
    if (this->sn[0x28] == 0) {
        newArtifact = (int)ceil((double)this->soldiers.numberValue /
                                (double)this->sn[0x10]);
        if (newArtifact > this->sn[0x24]) {
            newArtifact = this->sn[0x24];
        }
        int artifactUnits = newArtifact * this->sn[0x10];
        numPotentialAGroups = this->soldiers.numberValue - artifactUnits;
        if (numPotentialAGroups <= 0) {
            goto balance_groups;
        }
        i = (int)ceil((double)numPotentialAGroups / (double)this->sn[0x19]);
        if (i > this->sn[0x26]) {
            i = this->sn[0x26];
        }
        numPotentialAGroups = this->soldiers.numberValue - i * this->sn[0x19] -
                              artifactUnits;
        if (numPotentialAGroups <= 0) {
            goto balance_groups;
        }
        numAGroups = (int)ceil((double)numPotentialAGroups / (double)this->sn[0x2B]);
        if (numAGroups <= this->sn[0x2A]) {
            goto balance_groups;
        }
    }
    else {
        int maxArtifact = this->sn[0x24];
        numPotentialAGroups = this->soldiers.numberValue;
        newArtifact = numPotentialAGroups;
        if (numPotentialAGroups >= maxArtifact) {
            newArtifact = maxArtifact;
        }
        numPotentialAGroups -= newArtifact;
        if (numPotentialAGroups <= 0) {
            goto balance_groups;
        }
        if (numPotentialAGroups < this->sn[0x26]) {
            i = numPotentialAGroups;
        }
        else {
            i = this->sn[0x26];
        }
        numPotentialAGroups -= i;
        if (numPotentialAGroups <= 0 ||
            (numAGroups = numPotentialAGroups,
             numPotentialAGroups < this->sn[0x2A])) {
            goto balance_groups;
        }
    }
    numAGroups = this->sn[0x2A];

balance_groups:
    if (this->sn[0xA2] == 1) {
        newArtifact = 0;
    }

    for (; numDGroups < newArtifact; ++numDGroups) {
        TacticalAIGroup* new_group = 0;
        if (numEGroups > 0) {
            new_group = this->group(-1, 0x65, -1, -1);
            if (new_group != 0) {
                --numEGroups;
            }
            else {
                new_group = this->group(-1, 0x66, -1, -1);
                if (new_group != 0) {
                    --local_24;
                }
            }
        }
        if (new_group == 0) {
            new_group = this->createGroup(1);
            if (new_group == 0) {
                break;
            }
        }
        new_group->setType(100);
        new_group->setTarget(-1);
        new_group->setTargetType(-1);
        new_group->setAction(1);
        new_group->setInUse(0);
        int desired = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0x2560) %
                      (this->sn[0x62] + 1) + this->sn[0x10];
        if (desired > this->sn[0x1A]) {
            desired = this->sn[0x1A];
        }
        new_group->setDesiredNumberUnits(desired);
    }

    while (numDGroups > newArtifact) {
        TacticalAIGroup* old_group = this->group(-1, 100, 0, -1);
        if (old_group == 0) {
            old_group = this->group(-1, 100, 1, -1);
        }
        if (old_group == 0) {
            break;
        }
        this->removeGroup(old_group->id());
        --numDGroups;
    }

    for (; numEGroups < i; ++numEGroups) {
        TacticalAIGroup* new_group = 0;
        if (local_24 > 0) {
            new_group = this->group(-1, 0x66, -1, -1);
            if (new_group != 0) {
                --local_24;
            }
        }
        if (new_group == 0) {
            new_group = this->createGroup(1);
            if (new_group == 0) {
                break;
            }
        }
        new_group->setType(0x65);
        new_group->setTarget(-1);
        new_group->setTargetType(-1);
        new_group->setAction(1);
        new_group->setInUse(0);
        new_group->setDesiredNumberUnits(this->sn[0x19]);
    }

    while (numEGroups > i) {
        TacticalAIGroup* old_group = this->group(-1, 0x65, -1, -1);
        if (old_group == 0) {
            break;
        }
        this->removeGroup(old_group->id());
        --numEGroups;
    }

    for (; local_24 < numAGroups; ++local_24) {
        TacticalAIGroup* new_group = this->createGroup(1);
        if (new_group == 0) {
            break;
        }
        new_group->setType(0x66);
        new_group->setDesiredNumberUnits(this->sn[0x2B]);
    }

    while (local_24 > numAGroups) {
        TacticalAIGroup* old_group = this->group(-1, 0x66, -1, -1);
        if (old_group == 0) {
            break;
        }
        this->removeGroup(old_group->id());
        --local_24;
    }

}
