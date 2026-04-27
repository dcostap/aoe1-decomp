// decrementResource (00412870, 92 bytes, airesmod.cpp)
// Attempt 1

class AIModule {
public:
    void __cdecl logCommonHistory(const char* fmt, int p1, int p2);
};

class ResourceAIModule : public AIModule {
public:
    char gap_00[0xF4];
    int numberResourcesValue;
    int* resourceValue;

    void decrementResource(int resourceID, int value);
};

void ResourceAIModule::decrementResource(int resourceID, int value) {
    this->logCommonHistory("decrementResource: n=%d, v=%d.", resourceID, value);

    if (resourceID < 0 || resourceID >= numberResourcesValue) {
        return;
    }

    resourceValue[resourceID] -= value;

    if (value == 0) {
        return;
    }

    this->logCommonHistory("  decrementResource: r[%d]=%d.", resourceID, resourceValue[resourceID]);
}
