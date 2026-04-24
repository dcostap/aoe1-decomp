// tried a direct indexed-array spelling and then a raw-pointer spelling; mismatch stayed at the entry prolog / resourceType load basin
// also corrected the resource bucket layout to keep the 4D0/4E0 split in view, but VC5 still insists on a different first-load order
// leaving in scratch: behavior is locally understood, but the remaining drift is the prolog register basin

class ResourceMemory {
public:
    int id;
    char gap_04[0x08];
    unsigned char valid;
    char gap_0D[0x07];
};

class TribeInformationAIModule {
public:
    char gap_00[0x4D0];
    char* resourceBases[8];
    int numResources[8];

    int setResourceObjectValid(int resourceType, int resourceId, int valid);
};

int TribeInformationAIModule::setResourceObjectValid(int resourceType, int resourceId, int valid) {
    int index = resourceType;
    int count = this->numResources[index];
    if (count < 1) {
        return 0;
    }
    ResourceMemory* resource = (ResourceMemory*)this->resourceBases[index];
    int i = 0;
    do {
        if (resource->id == resourceId) {
            resource->valid = (unsigned char)valid;
            return 1;
        }
        i++;
        resource++;
    } while (i < count);
    return 0;
}
