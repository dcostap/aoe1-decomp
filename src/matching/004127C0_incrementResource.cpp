// incrementResource (004127C0, 92 bytes, airesmod.cpp)
// Attempt 2: logCommonHistory is __cdecl

class AIModule {
public:
    void __cdecl logCommonHistory(const char* fmt, int p1, int p2);
};

class ResourceAIModule : public AIModule {
public:
    char gap_00[0xF4];
    int numberResourcesValue;
    int* resourceValue;

    void incrementResource(int resourceID, int value);
};

void ResourceAIModule::incrementResource(int resourceID, int value) {
    this->logCommonHistory("incrementResource: n=%d, v=%d.", resourceID, value);

    if (resourceID < 0 || resourceID >= numberResourcesValue) {
        return;
    }

    resourceValue[resourceID] += value;

    if (value == 0) {
        return;
    }

    this->logCommonHistory("  incrementResource: r[%d]=%d.", resourceID, resourceValue[resourceID]);
}
