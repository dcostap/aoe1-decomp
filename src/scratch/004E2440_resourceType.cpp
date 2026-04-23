// first pass: pick the resource-type bucket, return 1 if its list contains the requested resource id, else 0
// tried direct array indexing, a shifted-offset local, and a nested pointer layout; the mismatch stayed in the first-load/prolog basin around the resource-type index

class TribeInformationAIModule {
public:
    char gap_00[0x4C8];
    int** resourceTypesValue;
    int* numberResourceTypesValue;

    int resourceType(int resourceTypeIndex, int resourceId);
};

int TribeInformationAIModule::resourceType(int resourceTypeIndex, int resourceId) {
    int count = this->numberResourceTypesValue[resourceTypeIndex];
    int* list;
    int i = 0;

    if (count < 1) {
        return 0;
    }

    list = this->resourceTypesValue[resourceTypeIndex];
    do {
        if (*list == resourceId) {
            return 1;
        }
        i++;
        list++;
    } while (i < count);
    return 0;
}
