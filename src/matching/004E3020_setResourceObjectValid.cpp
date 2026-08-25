#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
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
    ResourceMemory* resourcePtrs[4];
    int numResources[4];

    int setResourceObjectValid(int resourceType, int resourceId, int valid);
};
#endif

#endif
int TribeInformationAIModule::setResourceObjectValid(int resourceType, int resourceId, int valid) {
    for (int i = 0; i < this->numResources[resourceType]; i++) {
        if (this->resourcePtrs[resourceType][i].id == resourceId) {
            this->resourcePtrs[resourceType][i].valid = (unsigned char)valid;
            return 1;
        }
    }
    return 0;
}
