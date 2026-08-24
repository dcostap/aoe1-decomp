// VA: 00412BA0 ~TacticalAIModule (11B)
// Translation unit: aitacmod.cpp, source line 31.
//
// BINARY NOTE: the target writes the TacticalAIModule vptr, then tail-jumps to
// AIModule::~AIModule.  The base owner and direct target are therefore part of
// this wrapper's ABI.  Do not use a synthetic base class or a local destructor.
//
// Context categories: source ownership, class ABI, TU order, compiler flags.
// Policy review: no inline assembly, dummy function, fake vtable, volatility,
// metric-only alias, or config change.
#include "../../include/aitacmod_context.h"

TacticalAIModule::~TacticalAIModule() {
}
