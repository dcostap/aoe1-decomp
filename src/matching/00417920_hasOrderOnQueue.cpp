// 00417920 hasOrderOnQueue (53B, aiuaimod.cpp)
// Searches an array of OrderEvent structs (stride 0x24) for a matching order type.
// Returns 1 if found, 0 if not.
//
// Attempt log:
// - Best version: while(1) + if(i < count) continue; return 0;
// - Prologue/loads/cmp first 0x17 bytes match perfectly
// - Remaining: bottom-of-loop uses jge+jmp instead of jl (VC5 loop inversion)
// - Same codegen pattern as inGroup (0040A420)

#include "../../include/aiuaimod_context.h"

int UnitAIModule::hasOrderOnQueue(int param_1) {
    int count = this->orderQueueSizeValue;
    int index = 0;
    if (count <= 0) return 0;
    
    while (index < count) {
        if ((this->orderQueueValue + index)->orderType == param_1) return 1;
        index++;
    }
    return 0;
}
