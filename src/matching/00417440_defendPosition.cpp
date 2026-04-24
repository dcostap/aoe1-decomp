// defendPosition: aiuaimod.cpp lines 3733-3747
// __thiscall, virtual (but we don't rely on virtual here)
// Direct transcription of original asm.
// Attempt 1: straightforward implementation with minimal stubs.

class RGE_Static_Object {
public:
    char gap_00[0x40];   // padding to offset 0x40
    float world_z;       // +0x40
};

class UnitAIModule {
public:
    void* vtable_ptr;                      // +0x0
    RGE_Static_Object* objectValue;         // +0x4
    char gap_08[0x28];      // to +0x30
    int currentActionValue;                 // +0x30
    char gap_34[0x14];      // to +0x48
    float desiredTargetDistanceValue;      // +0x48
    int defendTargetValue;                  // +0x4C

    // Methods called by this function
    void setCurrentAction(int action);
    void setCurrentTarget(int target, float x, float y, float z);

    // The function we implement
    int defendPosition(float x, float y, float distance, int flag);
};

int UnitAIModule::defendPosition(float x, float y, float distance, int flag) {
    // Guard: if (flag == 0 && currentActionValue != -1) return 0;
    if (flag == 0 && this->currentActionValue != -1) {
        return 0;
    }

    // setCurrentAction(0x259)
    this->setCurrentAction(0x259);

    // setCurrentTarget(-1, x, y, this->objectValue->world_z)
    this->setCurrentTarget(-1, x, y, this->objectValue->world_z);

    // this->defendTargetValue = -1;
    this->defendTargetValue = -1;

    // this->desiredTargetDistanceValue = distance;
    this->desiredTargetDistanceValue = distance;

    return 1;
}
