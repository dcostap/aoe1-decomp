// first pass: pick the resource-type bucket, return 1 if its list contains the requested resource id, else 0
// tried direct array indexing, a shifted-offset local, and a nested pointer layout; the mismatch stayed in the first-load/prolog basin around the resource-type index
// tried the direct for-loop over the real backing arrays so VC5 can keep eax as the loop index and ecx as the walking list pointer

class TribeInformationAIModule {
public:
    char gap_00[0x4C8];
    int** resourceTypesValue;
    int* numberResourceTypesValue;

    int resourceType(int resourceTypeIndex, int resourceId);
};

int TribeInformationAIModule::resourceType(int resourceTypeIndex, int resourceId) {
    for (int i = 0; i < this->numberResourceTypesValue[resourceTypeIndex]; i++) {
        if (this->resourceTypesValue[resourceTypeIndex][i] == resourceId) {
            return 1;
        }
    }
    return 0;
}
