// VA: 00412B50 TacticalAIModule::TacticalAIModule (42B)
// Translation unit: aitacmod.cpp, source lines 24-26.
//
// BINARY NOTE: the constructor passes the arguments to AIModule in the order
// shown by the five pushes, then installs the derived vptr before returning.
//
// Context categories: source ownership, class ABI, TU order, compiler flags.
// Policy review: no inline assembly, dummy function, fake vtable, volatility,
// metric-only alias, or config change.
#include "../../include/aitacmod_context.h"

TacticalAIModule::TacticalAIModule(void* param1, int param2)
    : AIModule("TacAI", 0x3F1, param2, param1)
{
}
