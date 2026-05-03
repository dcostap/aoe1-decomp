// 004FAEB0 TribeTacticalAIModule::taskWaterExplorer (taitacmd.cpp:8951-8969, 266B)
// Records a unit ID as tasked this update, then dispatches to player.
// FLAGS: /nologo /c /O2 /Oy

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

// ManagedArray<int> layout
struct ManagedArrayInt {
    int* value;          // +0x00
    int numberValue;     // +0x04
    int desiredValue;    // +0x08
    int maximumSize;     // +0x0C
};

struct RGE_Player {
    virtual void d0() {}
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
    virtual int taskUnitRelative(int short_field, int unit_id, int cmd,
                                  int a4, int a5, float x1, float y1,
                                  float z1, float w1, int a10, int a11,
                                  int a12) = 0;  // slot 12
    // vtable slot 12 (0x30) for the virtual call
};

struct TribeMainDecisionAIModule;

struct TribeTacticalAIModule {
    char gap_00[0xF0];
    /* +0xF0 */ TribeMainDecisionAIModule* md;
    char gap_F4[0xD58 - 0xF4];
    /* +0xD58 */ ManagedArrayInt unitsTaskedThisUpdate;

    int taskWaterExplorer(int param_1);
};

struct MainDecisionAIModule {
    char gap_00[0xF0];
    /* +0xF0 */ RGE_Player* player;
};

struct TribeMainDecisionAIModule : MainDecisionAIModule {
    // player at +0xF0 from MainDecisionAIModule base
};

int TribeTacticalAIModule::taskWaterExplorer(int param_1) {
    if (param_1 == -1) {
        return 0;
    }

    ManagedArrayInt& arr = unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSize) break;
        if (arr.value[i] == param_1) goto done;
    }

    if (arr.numberValue > arr.maximumSize - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = (int*)operator_new(newSize * 4);
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSize && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            operator_delete(arr.value);
            arr.value = newArray;
            arr.maximumSize = newSize;
        }
    }

    arr.value[arr.numberValue] = param_1;
    arr.numberValue++;

done:
    {
        RGE_Player* player = md->player;
        int short_field = *(short*)((char*)player + 0x4A);
        player->taskUnitRelative(short_field, param_1, 0x2C1, -1, -1,
                                 -1.0f, -1.0f,
                                 -1.0f, 1.0f,
                                 1, 0, 1);
    }
    return 1;
}
