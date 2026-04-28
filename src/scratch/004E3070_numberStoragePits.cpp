// 004E3070 numberStoragePits (taiinfmd.cpp:7561-7571)
// PDB source: taiinfmd.cpp (TribeInformationAIModule::numberStoragePits)
//
// Attempt log:
// attempts 1-10: for/while/do-while/if-guard variants, decl-order swaps,
//   Ghidra-literal copy loops. All produce ~65-91% diff, same first mismatch
//   (push ebp vs push ebx at offset 1).
// variant lab (288 variants): 7 axes (decl_order, guard_form, growth_check,
//   alloc_expr, copy_loop, store_newsize, object_call). 12 unique asm groups.
//   0 exact matches. Every variant has push ebp(55) vs push ebx(53) at offset 1.
// Best group: G0001 (edit diff 62, pos diff 121) with while+j+++cap-break copy
//   loop + if_gt_do_while guard + i>cap-1 check.
// 
// LEFT IN SCRATCH: Remaining mismatch is pure VC5 register/scheduling drift.
// All 288 variants share push ebp (i in ebp) vs original push ebx (i in ebx).
// Copy loop uses shl+pointer-arithmetic instead of inc+[base+reg*4-4].
// Object call loads md before array[i] instead of array[i] first then md.
// These are ingrained VC5 codegen-family choices, not source-fixable with
// natural C++. No inline asm possible (forbidden). Parking.

#include <stddef.h>

void* operator new(size_t size);
void operator delete(void* ptr);

struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
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
    int result = 0;
    int i = 0;

    if (playerBuildings.numberValue > 0) {
        do {
            if (i > playerBuildings.maximumSizeValue - 1) {
                int* newArray = (int*)::operator new((i + 1) * sizeof(int));
                if (newArray != 0) {
                    int j = 0;
                    int cap = playerBuildings.maximumSizeValue;
                    if (cap > 0) {
                        while (j < i + 1) {
                            newArray[j] = playerBuildings.value[j];
                            j++;
                            if (j >= cap) break;
                        }
                    }
                    ::operator delete(playerBuildings.value);
                    playerBuildings.value = newArray;
                    playerBuildings.maximumSizeValue = i + 1;
                }
            }

            int id = playerBuildings.value[i];
            RGE_Static_Object* obj = md->object(id);
            if (obj != 0 && obj->master_obj->id == 0x67) {
                result++;
            }

            i++;
        } while (i < playerBuildings.numberValue);
    }

    return result;
}
