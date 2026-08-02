// 004E3070 numberStoragePits (taiinfmd.cpp:7561-7571)
// PDB source: taiinfmd.cpp (TribeInformationAIModule::numberStoragePits)
//
// Attempt log:
// attempts 1-10: for/while/do-while/if-guard variants, decl-order swaps,
//   Ghidra-literal copy loops. All produced ~65-91% diff, with push ebp vs
//   original push ebx at offset 1.
// variant lab (288 variants): 7 axes (decl_order, guard_form, growth_check,
//   alloc_expr, copy_loop, store_newsize, object_call). 12 unique asm groups;
//   0 exact matches. The best prior group was the while+j+++cap-break copy
//   loop (edit diff 62, positional diff 121), but it still chose i in EBP.
// probe 2: model the proven ManagedArray<int>::operator[] surface and use
//   playerBuildings[i], matching the period-plausible inline header idiom;
//   this replaces the parent-level hand-expanded growth scaffolding. MATCH:
//   193/193 bytes, all 3 calls and all blocks aligned; no custom flags or asm.

#include <stddef.h>

void* operator new(size_t size);
void operator delete(void* ptr);

struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

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

struct RGE_Master_Static_Object {
    char _gap_00[0x10];
    short id;
};

struct RGE_Static_Object {
    char _gap_00[0x08];
    RGE_Master_Static_Object* master_obj;
};

struct MainDecisionAIModule {
    char _gap_00[0x04];
    RGE_Static_Object* object(int objId);
};

struct TribeInformationAIModule {
    char _gap_00[0xF0];
    ManagedIntArray farmsTaskedThisUpdate;
    MainDecisionAIModule* md;
    char _gap_104[0x8C];
    ManagedIntArray playerBuildings;

    int numberStoragePits();
};

int TribeInformationAIModule::numberStoragePits() {
    int i = 0;
    int result = 0;

    if (playerBuildings.numberValue > 0) {
        do {
            RGE_Static_Object* obj = md->object(playerBuildings[i]);
            if (obj != 0 && obj->master_obj->id == 0x67) {
                result++;
            }

            i++;
        } while (i < playerBuildings.numberValue);
    }

    return result;
}
