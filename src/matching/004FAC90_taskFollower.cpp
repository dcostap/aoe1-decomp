// VA: 004FAC90, TribeTacticalAIModule::taskFollower, 260 bytes
// Source: taitacmd.cpp lines 8919-8929
// FLAGS: default
//
// Attempt log:
// - Prior attempts used a hand-shaped count/capacity scan and an all-integer
//   vtable proxy.  They preserved calls but emitted a 256-byte function with
//   register, loop-shape, float-argument, and call-scheduling drift.
// - Current baseline: the canonical ownership was retained, but the hand-shaped
//   scan still produced a 246-byte function and diverged at the first capacity
//   check.
// - Probe 1: mirrored the exact taskWaterExplorer donor's natural
//   ManagedArray reference, bounded for scan, grow/copy/append sequence, and
//   typed float virtual-call signature.  Result: MATCH, 260/260 bytes.
// - Probe 2: replaced the proven player +0x4A raw load with the named
//   RGE_Player::id field from the generated layout.  Emitted code stayed exact;
//   retained as the canonical ownership model.
// - Probe 3: used the generated high-confidence slot-0x30 sendUnitAIOrder
//   name/void signature instead of a placeholder method name/return type;
//   emitted code stayed exact.
// - Final: exact natural ManagedArray source and typed RGE_Player slot-0x30
//   surface; default flags; no inline asm or compiler-steering hacks.
// - Main-agent audit restored canonical destructor ownership and natural
//   new[]/delete[] growth; emitted code remains exact.

#include <stddef.h>

struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSize;
};

struct RGE_Player {
    virtual ~RGE_Player();
    virtual void d1() {}
    virtual void d2() {}
    virtual void d3() {}
    virtual void d4() {}
    virtual void d5() {}
    virtual void d6() {}
    virtual void d7() {}
    virtual void d8() {}
    virtual void d9() {}
    virtual void d10() {}
    virtual void d11() {}
    virtual void sendUnitAIOrder(int short_field, int unit_id, int cmd,
                                 int a4, int a5, float x1, float y1,
                                 float z1, float w1, int a10, int a11,
                                 int a12) = 0;
    char gap_04[0x46];
    short id;
};

struct MainDecisionAIModule {
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;
};

struct TribeMainDecisionAIModule : MainDecisionAIModule {
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xEC];
    TribeMainDecisionAIModule* md;
    char gap_F4[0xD58 - 0xF4];
    ManagedIntArray unitsTaskedThisUpdate;

    int taskFollower(int param_1, int param_2, float param_3, int param_4);
};

int TribeTacticalAIModule::taskFollower(int param_1, int param_2, float param_3, int param_4) {
    ManagedIntArray& arr = unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSize) break;
        if (arr.value[i] == param_1) goto done;
    }

    if (arr.numberValue > arr.maximumSize - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSize && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSize = newSize;
        }
    }

    arr.value[arr.numberValue] = param_1;
    arr.numberValue++;

done:
    {
        RGE_Player* player = md->player;
        player->sendUnitAIOrder(player->id, param_1, 0x2C8, param_2, -1,
                                -1.0f, -1.0f, -1.0f, param_3, 1, 0, param_4);
    }
    return 1;
}
