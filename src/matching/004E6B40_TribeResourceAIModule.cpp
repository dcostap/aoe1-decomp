#include "../../include/tairesmd_context.h"

extern const char s_Resource_AI[];

// Source: tairesmd.cpp lines 30-31.
// BINARY NOTE: Both members are initialized in the initializer list. VC5 then
// emits the derived vtable store after the member stores, matching the binary.
TribeResourceAIModule::TribeResourceAIModule(void* param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
    : AIModule((void*)s_Resource_AI, 0x3EF, param_2, param_1),
      md(0),
      numberResourcesValue(param_3) {
}
