// TribeInformationAIModule::numberGranaries (004E3140)
// PDB source: taiinfmd.cpp:7576-7586
// Size: 193 bytes
// Calling convention: __thiscall
//
// PARKED: Remaining drift is register allocation (ebp vs ebx for loop counter)
// and condition reordering in the copy loop — TU-context issue.
//
// Attempt log:
// Probe 1 (flat class, for/while copy): 90.1% diff — reg alloc picks ebp not ebx
// Probe 2 (pre-declared i, for with no-init): 79.8% diff — same reg choice
// Probe 3 (i then count, count=i): 78.2% diff — got xor/mov init pattern right but still ebp
// Probe 4 (cached locals for value/maxSize/numVal): 90.7% diff — worse, extra locals shifted layout
// Variant lab (8 variants, outer=a/b/c/d x inner=x/y): best group G0002 edit_diff=124
//   All 8 variants: first mismatch is push ebp vs push ebx at byte 1
//   Copy loop: original checks j<newCapacity first (reg), rebuilt checks j<maxSize first (mem)
//   Rebuilt adds extra `test edi,edi; jle` guard for newCapacity not in original
//
// Assessment: Register allocation (ebx vs ebp for loop counter) and loop condition
// ordering are TU-context dependent. The function is logically correct.
// No custom flags tested; unlikely to help as the core issue is register assignment
// and comparison ordering within the same source shape.

extern "C" void* operator_new(unsigned int size);
extern "C" void operator_delete(void* p);

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;                           // +0x10
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj; // +0x08
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    void* member_F0;                     // +0xF0

    RGE_Static_Object* object(int id);
};

struct ManagedIntArray {
    int* value;                          // +0x00
    int numberValue;                     // +0x04
    int desiredNumberValue;              // +0x08
    int maximumSizeValue;                // +0x0C
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];                  // base classes + other fields to +0xFF
    MainDecisionAIModule* md;            // +0x100
    char gap_104[0x8C];                  // +0x104 to +0x18F
    ManagedIntArray playerBuildings;     // +0x190

    int numberGranaries();
};

int TribeInformationAIModule::numberGranaries() {
    int count = 0;
    int i = 0;
    if (playerBuildings.numberValue > 0) {
        for (; i < playerBuildings.numberValue; i++) {
            if (i >= playerBuildings.maximumSizeValue) {
                int* newValue = (int*)operator_new(i * 4 + 4);
                if (newValue) {
                    int newCapacity = i + 1;
                    int j = 0;
                    if (playerBuildings.maximumSizeValue > 0) {
                        while (j < newCapacity && j < playerBuildings.maximumSizeValue) {
                            newValue[j] = playerBuildings.value[j];
                            j++;
                        }
                    }
                    operator_delete(playerBuildings.value);
                    playerBuildings.value = newValue;
                    playerBuildings.maximumSizeValue = newCapacity;
                }
            }

            RGE_Static_Object* obj = md->object(playerBuildings.value[i]);
            if (obj && obj->master_obj->id == 0x44) {
                count++;
            }
        }
    }
    return count;
}
