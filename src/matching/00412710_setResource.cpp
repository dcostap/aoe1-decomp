// attempt 1: initial draft, mismatch at offset 21, bad call signature
// attempt 2: define strings, fix logCommonHistory call order

class ResourceItem {
public:
    int number();
    int value(int index);
};

extern const char s_setResource_n_v[];
extern const char s_setResource_r_v[];
extern void __cdecl logCommonHistory(void* thisPtr, const char* format, ...);

class ResourceAIModule {
public:
    char gap_00[0xF4];
    int numberResourcesValue;
    int* resourceValue;

    void setResource(int index, int value);
};

void ResourceAIModule::setResource(int index, int value) {
    logCommonHistory(this, s_setResource_n_v, index, value);
    if (index >= 0 && index < numberResourcesValue) {
        resourceValue[index] = value;
        logCommonHistory(this, s_setResource_r_v, index, resourceValue[index]);
    }
}
