// Attempt log for 004D3B20 TribeBuildAIModule::loadBuildList
// Historical pass: an inline repeated add body reached 565 bytes, but the
// decompiler-shaped do/copy loops selected a pointer-walk basin; the earlier
// /O1, /Oy-, /GX, volatile, and local-pointer probes were rolled back.
// Fresh pass: restored BuildAIModule/ManagedArray<int> ownership and the
// inline ManagedArray<int>::add source family from utmarray.h.  The exact
// donor's natural for scan/copy spelling produced the indexed [value+eax*4]
// loops and exact size.  The donor's `numberValue > maximumSizeValue - 1`
// capacity spelling (rather than its reversed equivalent) selected the
// original cmp operand order in all three expansions.
// Exact validation: 565/565 bytes, 100% shape/CFG/call parity, 0 differing
// bytes.  The source remains ordinary typed period-plausible C++ with no asm.

#ifndef TAIBLDMD_SHARED_CONTEXT
typedef unsigned int uint;
void* operator new(uint size);
void operator delete(void* ptr);
class RGE_Player;
template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int add(int val) {
        int i;
        int* newValue;
        int newSize;

        for (i = 0; i < numberValue; i++) {
            if (i >= maximumSizeValue) break;
            if (value[i] == val) return 0;
        }
        if (numberValue > maximumSizeValue - 1) {
            newSize = numberValue + 1;
            newValue = (T*)operator new(newSize * sizeof(T));
            if (newValue != 0) {
                for (i = 0; i < maximumSizeValue; i++) {
                    if (i >= newSize) break;
                    newValue[i] = value[i];
                }
                operator delete(value);
                value = newValue;
                maximumSizeValue = newSize;
            }
        }
        value[numberValue] = val;
        numberValue = numberValue + 1;
        return 1;
    }
};
class AIModule { public: virtual ~AIModule(); char gap_04[0xEC]; };
class BuildAIModule : public AIModule {
public:
    char gap_F0[0x5AC - 0xF0];
    ManagedArray<int> typesToIgnore;
    virtual int loadBuildList(char*, RGE_Player*);
};
class TribeBuildAIModule : public BuildAIModule {
public:
    virtual int loadBuildList(char* filename, RGE_Player* player);
};
#endif

int TribeBuildAIModule::loadBuildList(char* filename, RGE_Player* player)
{
    this->typesToIgnore.add(0x46);
    this->typesToIgnore.add(0x67);
    this->typesToIgnore.add(0x44);
    return BuildAIModule::loadBuildList(filename, player);
}
