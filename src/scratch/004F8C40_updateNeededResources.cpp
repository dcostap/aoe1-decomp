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
// BLOCKER: behavior/call set/field offsets and frame now match closely at the top; first 43 bytes equal and size is exact 478. Remaining mismatch starts in the local array initialization/codegen basin: original uses EDX=-1, EAX=-1, ECX=0 and interleaves stores to stack slots [34]/[24]/[14] etc, while rebuilt uses only EAX=-1 and ESI=0 stores. Later control flow is mostly same shape but shifted/shorter because of this init/register allocation and local-struct layout differences.

class ResourceItem {
public:
    int value(int index);
};

class TribeBuildAIModule {
public:
    int mostNeededResource(ResourceItem* needed, int sn93);
};

class TribeResourceAIModule {
public:
    int resource(int index);
};

class TribeMainDecisionAIModule;

class TribeTacticalAIModule {
public:
    char gap_000[0x0f0];
    TribeMainDecisionAIModule* md;       // +0x0f0
    char gap_0f4[0x194 - 0x0f4];
    int sn[256];                         // +0x194, sn[0x93] at +0x3e0
    char gap_after_sn[0xd88 - (0x194 + 256 * 4)];
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
    TribeTacticalAIModule* self;

    self = this;
    ((TribeBuildAIModule*)((char*)self->md + 0x104))->mostNeededResource(&self->neededResources, self->sn[0x93]);

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
        int resource = ((TribeResourceAIModule*)((char*)self->md + 0x10d7c))->resource(i);
        int needed = self->neededResources.value(i);
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
                if (((TribeResourceAIModule*)((char*)self->md + 0x10d7c))->resource(i) >= self->sn[0xbe]) {
                    goto next_resource;
                }
            }
            if (i == 1) {
                if (((TribeResourceAIModule*)((char*)self->md + 0x10d7c))->resource(i) >= self->sn[0xbf]) {
                    goto next_resource;
                }
            }
            if (i == 3) {
                if (((TribeResourceAIModule*)((char*)self->md + 0x10d7c))->resource(i) >= self->sn[0xc1]) {
                    goto next_resource;
                }
            }
            if (i == 2) {
                if (((TribeResourceAIModule*)((char*)self->md + 0x10d7c))->resource(i) >= self->sn[0xc0]) {
                    goto next_resource;
                }
            }
            if (self->neededResources.value(i) > 0) {
                if ((bestResource == -1 || self->resourceDifferenceValue[i] < bestDifference) && assignedResource[i + 1] == 0) {
                    bestDifference = self->resourceDifferenceValue[i];
                    bestResource = i;
                }
            }
next_resource:
            i++;
        } while (i < 4);

        if (bestResource == -1) {
            i = 0;
            int* assignedPtr = assignedResource;
            diffPtr = self->resourceDifferenceValue;
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

    int* neededOut = self->neededResourceValue;
    offset = 0;
    do {
        int resource = *(int*)((char*)tempNeededResource + offset + 4);
        int difference = *(int*)((char*)tempResourceDifference + offset + 4);
        *neededOut = resource;
        offset += 4;
        neededOut++;
        self->resourceDifferenceValue[resource] = difference;
    } while (offset < 0x10);
#undef tempResourceDifference
#undef tempNeededResource
#undef assignedResource
}
