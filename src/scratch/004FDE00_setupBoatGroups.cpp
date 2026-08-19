// 004FDE00 TribeTacticalAIModule::setupBoatGroups
// Source: taitacmd.cpp lines 10322-10681
//
// Baseline reconstruction: the local groupsToRemove is the real inline
// ManagedArray<int> surface. The three boat lists and workingArea are named
// ManagedArray<int> members, while the group list is the TacticalAIGroup
// sentinel owned by TribeTacticalAIModule. The repeated boat phases are kept
// as ordinary source-level loops; their shared remove/copy topology is visible
// in the original CFG.
// FLAGS: config/flags/004FDE00_setupBoatGroups.rsp (/GX for the observed EH frame).
//
// Attempt log:
// - baseline: canonical TacticalAIGroup sentinel, inline ManagedArray ownership,
//   and three ordinary boat-group phases; 2887-byte target rebuilt as 2894
//   bytes with a 0x28/0x2C frame gap and an early type-filter CFG mismatch.
// - negative type guard with explicit continue: matched the original late
//   type-match body and reduced the positional diff from 2602 to 730 bytes.
// - declaration/local-role reorderings (including the retained type-68 count)
//   emitted the same VC5 code; no further declaration archaeology retained.
// - positive nested remainder guards and commutative product-order probes were
//   also codegen duplicates; they remain diagnostic evidence only.
// - /GX balance-shape lab: a named product temporary plus compact positive
//   clamps produced the exact 2887-byte size and exact balance focus range.
// - explicit remainder guards with a separate retained type-68 local restored
//   the 730-byte diagnostic basin but added 16 bytes after the target boundary;
//   rolled back because structural size is authoritative.
// - compact arithmetic with a separate retained local, hoisted product and
//   remainder locals, and the exact setupSoldierGroups scalar declaration order
//   all emitted the clean 745-byte codegen group; no new structural lead.
// - corrected the third balance denominator/cap from sn[0x3d]/sn[0x3c] to
//   sn[0x3e]/sn[0x3d], matching original offsets 0x28C/0x288; shape improved
//   from 94.07% to 94.39% and exact blocks from 70.87% to 71.29%, with the
//   same 745-byte positional diff.
// - fresh pass: 20 evidence-led declaration, lifetime, arithmetic, and loop
//   probes kept the same 745-byte codegen basin. A volatile
//   numPotentialEGroups restored the 0x2C frame and 81.57% exact blocks, but
//   added 16 bytes after the boundary; it is diagnostic evidence only.
// - fresh pass: explicit shared-balance gotos, address-taking, split count
//   lifetimes, register hints, function-scope group pointers, and loop-form
//   rewrites were codegen duplicates or worse. Restored this clean source.
// - current best is still non-exact: 745 positional diff bytes, 94.39% shape,
//   71.29% exact blocks, 93/93 ordered calls, and frame 0x28 versus 0x2C.
//   Remaining lead is the real local-lifetime/register basin around the target
//   stack homes (especially the saved numPotentialEGroups/numAGroups values).
// - ManagedArray recovery pass, 2026-08-19: the exact add body replaces the
//   manual caller-side scan and emits the same 2887-byte frontier. The complete
//   shared header inlines resize at this site, adds one allocator pair and 82
//   bytes, and changes the call surface. Keep resize declaration-only here.

void* operator new(unsigned int size);
void __cdecl operator_delete(void* ptr);
extern "C" double __cdecl ceil(double value);

class RGE_Static_Object;
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
            int* new_data = (int*)operator new(new_size * 4);
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

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int idValue;
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
    virtual ~TacticalAIGroup();
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    char gap_0C[0x330 - 0x0C];

    int type() const;
    int numberUnits() const;
    int id();
    void setType(int value);
    void setTarget(int value);
    void setTargetType(int value);
    void setAction(int value);
    void setInUse(int value);
    void setDesiredNumberUnits(int value);
    int addUnit(int object_id, TribeMainDecisionAIModule* md);
    void setSpecificCommander(int object_id, TribeMainDecisionAIModule* md);
    void setLocation(float x, float y, float z);
    void setGatherLocation(float x, float y, float z);
    void setRetreatLocation(float x, float y, float z);
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
    int numberUngroupedFishingBoats();
    int numberUngroupedTradeBoats();
    int numberUngroupedTransportBoats();
    TacticalAIGroup* group(int id, int type, int action, int target);

    void setupBoatGroups();
};

void TribeTacticalAIModule::setupBoatGroups()
{
    ManagedArray_int groupsToRemove;
    int i;
    int numEGroups;
    int numPotentialEGroups;
    int numPotentialAGroups;
    int numDGroups;
    int numAGroups;
    TacticalAIGroup* sentinel;
    TacticalAIGroup* group;

    group = this->groups.next;
    sentinel = &this->groups;
    while (group != sentinel && group != 0) {
        if (group->type() != 0x67 &&
            group->type() != 0x68 &&
            group->type() != 0x69) {
            group = group->next;
            continue;
        }
        if (group->numberUnits() == 0) {
            groupsToRemove.add(group->id());
        }
        group = group->next;
    }

    numEGroups = 0;
    while (numEGroups < groupsToRemove.numberValue) {
        this->removeGroup(groupsToRemove[numEGroups]);
        ++numEGroups;
    }

    i = this->numberGroups(0x67, -1);
    numAGroups = this->numberGroups(0x68, -1);
    numPotentialAGroups = this->numberGroups(0x69, -1);
    this->numberGroups(0x6b, -1);
    this->numberGroups(0x6c, -1);
    this->numberGroups(0x6a, -1);

    this->numberUngroupedFishingBoats();
    while (this->workingArea.numberValue > 0) {
        int object_id = this->workingArea[numEGroups];
        RGE_Static_Object* object = this->md->object(object_id);
        if (object == 0) {
            this->workingArea.remove(object_id);
        }
        else {
            TacticalAIGroup* new_group = this->createGroup(1);
            if (new_group == 0) {
                break;
            }
            new_group->setType(0x6b);
            new_group->setDesiredNumberUnits(this->sn[0x41] + 1);
            new_group->addUnit(object_id, this->md);
            new_group->setSpecificCommander(object_id, this->md);
            new_group->setLocation(object->world_x, object->world_y, object->world_z);
            new_group->setGatherLocation(object->world_x, object->world_y, object->world_z);
            new_group->setRetreatLocation(object->world_x, object->world_y, object->world_z);
            this->workingArea.remove(object_id);
        }
    }

    this->numberUngroupedTradeBoats();
    while (this->workingArea.numberValue > 0) {
        int object_id = this->workingArea[numEGroups];
        RGE_Static_Object* object = this->md->object(object_id);
        if (object == 0) {
            this->workingArea.remove(object_id);
        }
        else {
            TacticalAIGroup* new_group = this->createGroup(1);
            if (new_group == 0) {
                break;
            }
            new_group->setType(0x6c);
            new_group->setDesiredNumberUnits(this->sn[0x40] + 1);
            new_group->addUnit(object_id, this->md);
            new_group->setSpecificCommander(object_id, this->md);
            new_group->setLocation(object->world_x, object->world_y, object->world_z);
            new_group->setGatherLocation(object->world_x, object->world_y, object->world_z);
            new_group->setRetreatLocation(object->world_x, object->world_y, object->world_z);
            this->workingArea.remove(object_id);
        }
    }

    this->numberUngroupedTransportBoats();
    while (this->workingArea.numberValue > 0) {
        int object_id = this->workingArea[numEGroups];
        RGE_Static_Object* object = this->md->object(object_id);
        if (object == 0) {
            this->workingArea.remove(object_id);
        }
        else {
            TacticalAIGroup* new_group = this->createGroup(1);
            if (new_group == 0) {
                break;
            }
            new_group->setType(0x6a);
            new_group->setDesiredNumberUnits(this->sn[0x42] + 1);
            new_group->addUnit(object_id, this->md);
            new_group->setSpecificCommander(object_id, this->md);
            new_group->setLocation(object->world_x, object->world_y, object->world_z);
            new_group->setGatherLocation(object->world_x, object->world_y, object->world_z);
            new_group->setRetreatLocation(object->world_x, object->world_y, object->world_z);
            this->workingArea.remove(object_id);
        }
    }

    int boat_id = this->boats[0];
    if (this->md->informationAI.fullyExploredZone(boat_id) == 0) {
        this->removeAllGroups(0x69);
        this->setStrategicNumber(0x3d, 0);
    }

    numEGroups = 0;
    numDGroups = 0;
    if (this->sn[0x28] == 0) {
        numPotentialEGroups = (int)ceil(
            (double)this->warBoats.numberValue / (double)this->sn[0x3b]);
        if (numPotentialEGroups > this->sn[0x3a]) numPotentialEGroups = this->sn[0x3a];
        int product = numPotentialEGroups * this->sn[0x3b];
        int remaining = this->warBoats.numberValue - product;
        if (remaining > 0) {
            numEGroups = (int)ceil((double)remaining / (double)this->sn[0x44]);
            if (numEGroups > this->sn[0x43]) numEGroups = this->sn[0x43];
            remaining = this->warBoats.numberValue -
                        product - numEGroups * this->sn[0x44];
            if (remaining > 0) {
                numDGroups = (int)ceil((double)remaining / (double)this->sn[0x3e]);
                if (numDGroups > this->sn[0x3d]) numDGroups = this->sn[0x3d];
            }
        }
    }
    else {
        numPotentialEGroups = this->warBoats.numberValue;
        if (numPotentialEGroups >= this->sn[0x3a]) {
            numPotentialEGroups = this->sn[0x3a];
        }
        int remaining = this->warBoats.numberValue - numPotentialEGroups;
        if (remaining > 0) {
            numEGroups = remaining < this->sn[0x43] ? remaining : this->sn[0x43];
            remaining -= numEGroups;
            if (remaining > 0) {
                numDGroups = remaining;
                if (numDGroups >= this->sn[0x3d]) numDGroups = this->sn[0x3d];
            }
        }
    }
balance_boat_groups:
    for (; i < numPotentialEGroups; ++i) {
        TacticalAIGroup* new_group = 0;
        if (numAGroups > 0) {
            new_group = this->group(-1, 0x68, -1, -1);
            if (new_group != 0) {
                --numAGroups;
            }
            else {
                new_group = this->group(-1, 0x69, -1, -1);
                if (new_group != 0) {
                    --numPotentialAGroups;
                }
            }
        }
        if (new_group == 0) {
            new_group = this->createGroup(1);
            if (new_group == 0) {
                break;
            }
        }
        new_group->setType(0x67);
        new_group->setTarget(-1);
        new_group->setTargetType(-1);
        new_group->setAction(1);
        new_group->setInUse(0);
        new_group->setDesiredNumberUnits(this->sn[0x3b]);
    }

    while (i > numPotentialEGroups) {
        TacticalAIGroup* old_group = this->group(-1, 0x67, 0, -1);
        if (old_group == 0) {
            old_group = this->group(-1, 0x67, 1, -1);
        }
        if (old_group == 0) {
            break;
        }
        this->removeGroup(old_group->id());
        --i;
    }

    for (; numAGroups < numEGroups; ++numAGroups) {
        TacticalAIGroup* new_group = 0;
        if (numPotentialAGroups > 0) {
            new_group = this->group(-1, 0x69, -1, -1);
            if (new_group != 0) {
                --numPotentialAGroups;
            }
        }
        if (new_group == 0) {
            new_group = this->createGroup(1);
            if (new_group == 0) {
                break;
            }
        }
        new_group->setType(0x68);
        new_group->setTarget(-1);
        new_group->setTargetType(-1);
        new_group->setAction(1);
        new_group->setInUse(0);
        new_group->setDesiredNumberUnits(this->sn[0x44]);
    }

    while (numAGroups > numEGroups) {
        TacticalAIGroup* old_group = this->group(-1, 0x68, -1, -1);
        if (old_group == 0) {
            break;
        }
        this->removeGroup(old_group->id());
        --numAGroups;
    }

    for (; numPotentialAGroups < numDGroups; ++numPotentialAGroups) {
        TacticalAIGroup* new_group = this->createGroup(1);
        if (new_group == 0) {
            break;
        }
        new_group->setType(0x69);
        new_group->setDesiredNumberUnits(this->sn[0x3d]);
    }

    while (numPotentialAGroups > numDGroups) {
        TacticalAIGroup* old_group = this->group(-1, 0x69, -1, -1);
        if (old_group == 0) {
            break;
        }
        this->removeGroup(old_group->id());
        --numPotentialAGroups;
    }
}
