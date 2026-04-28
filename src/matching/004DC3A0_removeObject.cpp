// 004DC3A0 TribeInformationAIModule::removeObject(int param_1)
// Source: taiinfmd.cpp lines 3254-3270
// Size: 232 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Probe 4: remove outer if guard, use direct member access in loops

struct RGE_Static_Object;

struct ManagedArray_int {
    int* value;            // +0x00
    int numberValue;       // +0x04
    int desiredNumberValue; // +0x08
    int maximumSizeValue;  // +0x0C
};

struct ObjectMemory {
    unsigned char pad_00[0x0B];
    unsigned char owner;   // +0x0B
};

class MainDecisionAIModule {
public:
    RGE_Static_Object* object(int param_1);  // no body
};

class TribeInformationAIModule {
public:
    unsigned char pad_000[0xF0];                // +0x000
    ManagedArray_int farmsTaskedThisUpdate;     // +0x0F0
    MainDecisionAIModule* md;                   // +0x100
    unsigned char pad_104[0x7C];                // +0x104 to +0x180
    ManagedArray_int playerObjects;             // +0x180
    ManagedArray_int playerBuildings;           // +0x190

    void removeObject(int param_1);
    ObjectMemory* objectMemory(int id);  // no body
};

void TribeInformationAIModule::removeObject(int param_1)
{
    int idx;
    int* ptr;

    // --- playerBuildings search ---
    idx = 0;
    while (idx < playerBuildings.maximumSizeValue) {
        if (playerBuildings.value[idx] == param_1)
            break;
        idx++;
    }

    // --- playerBuildings removal ---
    if (idx < playerBuildings.maximumSizeValue) {
        if (idx < playerBuildings.maximumSizeValue - 1) {
            do {
                ptr = playerBuildings.value;
                idx++;
                ptr[idx - 1] = ptr[idx];
            } while (idx < playerBuildings.maximumSizeValue - 1);
        }
        playerBuildings.numberValue--;
        if (playerBuildings.numberValue < 0)
            playerBuildings.numberValue = 0;
    }

    // --- playerObjects search ---
    idx = 0;
    while (idx < playerObjects.maximumSizeValue) {
        if (playerObjects.value[idx] == param_1)
            break;
        idx++;
    }

    // --- playerObjects removal ---
    if (idx < playerObjects.maximumSizeValue) {
        if (idx < playerObjects.maximumSizeValue - 1) {
            do {
                ptr = playerObjects.value;
                idx++;
                ptr[idx - 1] = ptr[idx];
            } while (idx < playerObjects.maximumSizeValue - 1);
        }
        playerObjects.numberValue--;
        if (playerObjects.numberValue < 0)
            playerObjects.numberValue = 0;
    }

    // --- finalize ---
    RGE_Static_Object* obj = md->object(param_1);
    if (obj != 0) {
        ObjectMemory* mem = objectMemory(param_1);
        if (mem != 0) {
            unsigned char owner_id = *(unsigned char*)(*(int*)((char*)obj + 0x0C) + 0x4A);
            mem->owner = owner_id;
        }
    }
}
