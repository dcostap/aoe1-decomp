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
// - v15: separated the local arrays as a control; it preserved the frame but
//   changed the prologue and was restored.
// - v16: rewrote the final copy as an indexed four-entry loop. VC5 reduced the
//   size to 478 bytes and kept the natural member ownership; this is the
//   current clean reconstruction.
// - v17: tested an early best-resource sentinel; VC5 emitted the same code.
// - v18: changed the final indexed loop to a counted for form; VC5 emitted the
//   same code.
// Revisit v19: restored three direct four-entry arrays and a separate scalar;
// VC5 reduced the frame to 0x30 and worsened the result to diff 425.
// Revisit v20: moved the difference-pointer declaration after scalar locals;
// VC5 emitted duplicate code at diff 403.
// Revisit v21: removed the invented aggregate and used direct typed arrays;
// VC5 kept the frame but worsened the result to diff 414.
// Revisit v22: used typed parallel pointers for the final copy; VC5 emitted
// 482 bytes and worsened the result to diff 419.
// Revisit v23: restored the PDB-proven four-entry assignedResource array and
// kept the byte offset as its own scalar, rather than folding the offset into
// a fifth array slot. This tests the original local ownership and indexing.
// Revisit v24: replaced the fallback pointer walk with direct indexed array
// reads. VC5 now emits the original independent pointer setup and loop bytes;
// the remaining mismatch is the earlier initialization register basin.
// Revisit v25: a four-entry local aggregate plus a separate offset retained
// the 403-byte metric but changed the final copy to a countdown basin. It was
// rejected because the PDB names three separate arrays.
// Revisit v26: register hints for the difference cursor and first result were
// codegen duplicates. The natural unqualified declarations remain authoritative.
// BLOCKER: the current typed reconstruction has the exact frame and 478-byte
// size, eight ordered calls, and correct field offsets. It remains non-exact:
// the first mismatch is local initialization at +0x2B. The original keeps -1
// in EDX and EAX and zero in ECX. VC5 keeps only -1 in EAX and zero in ESI.
// The first difference scan also swaps the original EBP result and EBX cursor.
// The indexed fallback and final copy preserve the original pointer topology,
// but no period-plausible source change has recovered the early colors. Leave
// this source in scratch.

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
    int assignedResource[4];
    int tempNeededResource[4];
    int tempResourceDifference[4];
    int i;
    int* diffPtr;
    int bestResource;
    int bestDifference;
    int offset;

    this->md->buildAI.mostNeededResource(&this->neededResources, this->sn[0x93]);

    i = 0;
    tempResourceDifference[0] = -1;
    tempNeededResource[0] = -1;
    assignedResource[0] = 0;
    tempResourceDifference[1] = -1;
    tempNeededResource[1] = -1;
    assignedResource[1] = 0;
    tempResourceDifference[2] = -1;
    tempNeededResource[2] = -1;
    assignedResource[2] = 0;
    diffPtr = this->resourceDifferenceValue;
    tempResourceDifference[3] = -1;
    tempNeededResource[3] = -1;
    assignedResource[3] = 0;

    do {
        int resource = this->md->resourceAI.resource(i);
        int needed = this->neededResources.value(i);
        i++;
        *diffPtr = resource - needed;
        diffPtr++;
    } while (i < 4);

    offset = 0;
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
                if ((bestResource == -1 || this->resourceDifferenceValue[i] < bestDifference) && assignedResource[i] == 0) {
                    bestDifference = this->resourceDifferenceValue[i];
                    bestResource = i;
                }
            }
next_resource:
            i++;
        } while (i < 4);

        if (bestResource == -1) {
            i = 0;
            do {
                if ((bestResource == -1 || this->resourceDifferenceValue[i] < bestDifference) && assignedResource[i] == 0) {
                    bestDifference = this->resourceDifferenceValue[i];
                    bestResource = i;
                }
                i++;
            } while (i < 4);
        }

        assignedResource[bestResource] = 1;
        *(int*)((char*)tempNeededResource + offset) = bestResource;
        *(int*)((char*)tempResourceDifference + offset) = bestDifference;
        offset += 4;
    } while (offset < 0x10);

    i = 0;
    for (; i < 4; i++) {
        int resource = tempNeededResource[i];
        int difference = tempResourceDifference[i];
        this->neededResourceValue[i] = resource;
        this->resourceDifferenceValue[resource] = difference;
    }
}
