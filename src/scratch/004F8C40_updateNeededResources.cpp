// 004F8C40 TribeTacticalAIModule::updateNeededResources
// PDB: taitacmd.cpp:7453-7527, 478 bytes
// Attempt log:
// - v1: direct reconstruction from packet/decompiler with local arrays and real member-call surfaces.
// - v2: corrected sn from pointer to embedded array at +0x194 (sn[0x93] observed at +0x3e0).
// - v3: added/reused output pointer local to probe original 0x34 frame and register allocation; optimized out.
// - v4: modeled assignedResource as 5 ints: counter at [0], flags at [1..4], matching original 0x34 frame.
// - v5: made loop index register to try to force ESI index / EDI this allocation.
// - v6: introduced self local and used it for member accesses to probe this-pointer register allocation.
// - v7: reordered local array declarations so assignedResource occupies low stack offsets like original.
// - v8: grouped arrays in a local struct to force assigned/tempNeeded/tempDiff contiguous stack layout.
// - v9: reordered one-time array initialization to match original flag/temp output stack stores.
// - v10: tried a fixed four-entry initialization loop; VC5 kept the loop and
//   lost the original unrolled stores, so it was restored.
// - v11: replaced raw md subobject casts with canonical buildAI/resourceAI
//   members and restored the proven AIModule, ResourceItem, and tactical sizes;
//   emitted code stayed unchanged while source ownership became typed.
// - v12: reordered initialization to the decompiler/PDB order; block shape
//   worsened, so the original interleaved source order was restored.
// - v13: removed the self alias; emitted code stayed unchanged.
// - v14: initialized the fallback assigned-resource pointer at slot 1; this
//   changed prologue register coloring and was restored.
// BLOCKER: the natural typed reconstruction has the exact frame, eight ordered
// calls, correct field offsets, and 484 rebuilt bytes versus 478 original.
// The first mismatch is local initialization at +0x2B: original keeps -1 in
// EDX and EAX and zero in ECX, while VC5 keeps only -1 in EAX and zero in ESI.
// The source shape still has a 6-byte suffix shift. No evidence remains for a
// period-plausible register-only change; leave this source in scratch.

class ResourceItem {
public:
    virtual ~ResourceItem();
    char gap_04[0x70 - 0x04];
    int value(int index);
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xf0 - 0x04];
};

class BuildAIModule : public AIModule {
public:
    char gap_f0[0x5bc - 0xf0];
};

class TribeMainDecisionAIModule;

class TribeBuildAIModule : public BuildAIModule {
public:
    TribeMainDecisionAIModule* md;
    int mostNeededResource(ResourceItem* needed, int sn93);
};

class ResourceAIModule : public AIModule {
public:
    char gap_f0[0x10c - 0xf0];
};

class TribeResourceAIModule : public ResourceAIModule {
public:
    TribeMainDecisionAIModule* md;
    int numberResourcesValue;
    int resource(int index);
};

class MainDecisionAIModule : public AIModule {
public:
    void* player;
    char gap_f4[0x104 - 0xf4];
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule buildAI;
    char gap_6c4[0x10d7c - 0x6c4];
    TribeResourceAIModule resourceAI;
};

class TacticalAIModule {
public:
    virtual ~TacticalAIModule();
    char gap_04[0xf0 - 0x04];
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;       // +0x0f0
    char gap_0f4[0x194 - 0x0f4];
    int sn[0xe2];                         // +0x194, sn[0x93] at +0x3e0
    char gap_after_sn[0xd88 - (0x194 + 0xe2 * 4)];
    int neededResourceValue[4];          // +0xd88
    int resourceDifferenceValue[4];      // +0xd98
    ResourceItem neededResources;        // +0xda8

    void updateNeededResources();
};

void TribeTacticalAIModule::updateNeededResources()
{
    struct LocalArrays { int assignedResource[5]; int tempNeededResource[4]; int tempResourceDifference[4]; } locals;
#define assignedResource (locals.assignedResource)
#define tempNeededResource (locals.tempNeededResource)
#define tempResourceDifference (locals.tempResourceDifference)
    register int i;
    int bestResource;
    int bestDifference;
    int offset;

    this->md->buildAI.mostNeededResource(&this->neededResources, this->sn[0x93]);

    i = 0;
    tempResourceDifference[0] = -1;
    tempNeededResource[0] = -1;
    assignedResource[1] = 0;
    tempResourceDifference[1] = -1;
    tempNeededResource[1] = -1;
    assignedResource[2] = 0;
    tempResourceDifference[2] = -1;
    tempNeededResource[2] = -1;
    assignedResource[3] = 0;
    tempResourceDifference[3] = -1;
    tempNeededResource[3] = -1;
    assignedResource[4] = 0;

    int* diffPtr = this->resourceDifferenceValue;
    do {
        int resource = this->md->resourceAI.resource(i);
        int needed = this->neededResources.value(i);
        i++;
        *diffPtr = resource - needed;
        diffPtr++;
    } while (i < 4);

    assignedResource[0] = 0;
    do {
        bestResource = -1;
        bestDifference = 0x7fffffff;
        i = 0;
        do {
            if (i == 0) {
                if (this->md->resourceAI.resource(i) >= this->sn[0xbe]) {
                    goto next_resource;
                }
            }
            if (i == 1) {
                if (this->md->resourceAI.resource(i) >= this->sn[0xbf]) {
                    goto next_resource;
                }
            }
            if (i == 3) {
                if (this->md->resourceAI.resource(i) >= this->sn[0xc1]) {
                    goto next_resource;
                }
            }
            if (i == 2) {
                if (this->md->resourceAI.resource(i) >= this->sn[0xc0]) {
                    goto next_resource;
                }
            }
            if (this->neededResources.value(i) > 0) {
                if ((bestResource == -1 || this->resourceDifferenceValue[i] < bestDifference) && assignedResource[i + 1] == 0) {
                    bestDifference = this->resourceDifferenceValue[i];
                    bestResource = i;
                }
            }
next_resource:
            i++;
        } while (i < 4);

        if (bestResource == -1) {
            i = 0;
            int* assignedPtr = assignedResource;
            diffPtr = this->resourceDifferenceValue;
            do {
                assignedPtr++;
                if ((bestResource == -1 || *diffPtr < bestDifference) && *assignedPtr == 0) {
                    bestDifference = *diffPtr;
                    bestResource = i;
                }
                i++;
                diffPtr++;
            } while (i < 4);
        }

        assignedResource[bestResource + 1] = 1;
        offset = assignedResource[0];
        *(int*)((char*)tempNeededResource + offset + 4) = bestResource;
        *(int*)((char*)tempResourceDifference + offset + 4) = bestDifference;
        offset += 4;
        assignedResource[0] = offset;
    } while (offset < 0x10);

    int* neededOut = this->neededResourceValue;
    offset = 0;
    do {
        int resource = *(int*)((char*)tempNeededResource + offset + 4);
        int difference = *(int*)((char*)tempResourceDifference + offset + 4);
        *neededOut = resource;
        offset += 4;
        neededOut++;
        this->resourceDifferenceValue[resource] = difference;
    } while (offset < 0x10);
#undef tempResourceDifference
#undef tempNeededResource
#undef assignedResource
}
