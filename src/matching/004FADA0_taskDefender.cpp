// 004FADA0 TribeTacticalAIModule::taskDefender
// taitacmd.cpp:8935-8946, 260 bytes
//
// int __thiscall TribeTacticalAIModule::taskDefender(int param_1, int param_2, float param_3, int param_4)
// ret 10h cleanup (4 stack params + this in ecx)
//
// === Attempt log ===
// 1: Initial version - class layout structs, new[]/delete[], do-while search loop
//    Prologue OK through offset 13, but register cascade: count→edx vs ecx
//    Search loop uses pointer arithmetic (add ecx,4) instead of indexed [edi+eax*4]
//    Edit diff: 97/260 (37.3%), positional diff: 213/260 (81.9%)
//    Text size: 272 vs 260 (12 bytes too big)
// 2: Variant lab confirms both do-while and while-break search styles produce identical code
//    Register allocation (count→edx vs ecx) is the cascade root
// 3: Restored clean source before testing a reference-local ManagedArray surface.
// 4: Reference-local indexed scan/copy plus direct operator new/delete recovered the
//    original 260-byte CFG and array ownership; exact bytes now match.
// 5: The mission slot takes an int, with the proven short field promoted before the
//    call; the typed virtual surface and argument order also match exactly.
// Main-agent audit restored canonical AI/player destructor ownership, named
// sendUnitAIOrder, and natural new[]/delete[] growth; output remains exact.

struct IntArray {
    int* value;      // +0x00: this+0xD58
    int count;       // +0x04: this+0xD5C
    int gap_08;      // +0x08
    int maxSize;     // +0x0C: this+0xD64
};

class MissionSubObject {
public:
    virtual ~MissionSubObject();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual int sendUnitAIOrder(int a, int b, int c, int d, int e, float f, float g, float h, float i, int j, int k, int l);
    char _gap_04[70];
    short field_4A;
};

class TribeMainDecisionAIModule {
public:
    virtual ~TribeMainDecisionAIModule();
    char _gap_04[0x0EC];
    MissionSubObject* missionObj;
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char _gap_04[0x0EC];
    TribeMainDecisionAIModule* md;
    char _gap_0F4[0x0D58 - 0x0F4];
    IntArray unitsTasked;

    int taskDefender(int param_1, int param_2, float param_3, int param_4);
};

int TribeTacticalAIModule::taskDefender(int param_1, int param_2, float param_3, int param_4)
{
    IntArray& arr = this->unitsTasked;
    int i;

    for (i = 0; i < arr.count; i++) {
        if (i >= arr.maxSize)
            break;
        if (arr.value[i] == param_1)
            goto dispatch;
    }

    if (arr.count > arr.maxSize - 1) {
        int newSize = arr.count + 1;
        int* newVals = new int[newSize];
        if (newVals != 0) {
            int j;
            for (j = 0; j < arr.maxSize && j < newSize; j++) {
                newVals[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newVals;
            arr.maxSize = newSize;
        }
    }

    arr.value[arr.count] = param_1;
    arr.count++;

dispatch:
    // Mission dispatch through the typed player order surface.
    {
        MissionSubObject* obj = this->md->missionObj;
        obj->sendUnitAIOrder(
            (int)obj->field_4A,
            param_1,
            0x2BD,
            param_2,
            -1,
            -1.0f,
            -1.0f,
            -1.0f,
            param_3,
            1,
            0,
            param_4
        );
    }

    return 1;
}
