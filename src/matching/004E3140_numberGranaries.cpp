// TribeInformationAIModule::numberGranaries (004E3140)
// PDB source: taiinfmd.cpp:7576-7586
// Size: 193 bytes
// Calling convention: __thiscall
//
// Attempt log:
// Probes 1-5: hand-expanded growth logic stayed in the wrong EBP/condition basin.
// Probe 6: inline ManagedArray operator[] and natural do-while scan improved to
// 56.3% positional diff; remaining mismatch was the operator copy-loop shape.
// Probe 7: use the exact matched same-TU ManagedArray/source surface from
// numberStoragePits; exact 193/193 match.

#include <stddef.h>

void* operator new(size_t size);
void operator delete(void* ptr);

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
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
    char gap_00[0x04];
    RGE_Static_Object* object(int id);
};

struct ManagedIntArray {
    int* value;                          // +0x00
    int numberValue;                     // +0x04
    int desiredNumberValue;              // +0x08
    int maximumSizeValue;                // +0x0C

    int& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            int* new_data = (int*)::operator new(new_size * 4);
            if (new_data != 0) {
                int i;
                for (i = 0; i < this->maximumSizeValue && i < new_size; i++) {
                    new_data[i] = this->value[i];
                }
                ::operator delete(this->value);
                this->value = new_data;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
};

class TribeInformationAIModule {
public:
    char gap_00[0xF0];
    ManagedIntArray farmsTaskedThisUpdate;
    MainDecisionAIModule* md;            // +0x100
    char gap_104[0x8C];                  // +0x104 to +0x18F
    ManagedIntArray playerBuildings;     // +0x190

    int numberGranaries();
};
#endif

#endif
int TribeInformationAIModule::numberGranaries() {
    int i = 0;
    int result = 0;

    if (playerBuildings.numberValue > 0) {
        do {
            RGE_Static_Object* obj = md->object(playerBuildings[i]);
            if (obj != 0 && obj->master_obj->id == 0x44) {
                result++;
            }

            i++;
        } while (i < playerBuildings.numberValue);
    }

    return result;
}
