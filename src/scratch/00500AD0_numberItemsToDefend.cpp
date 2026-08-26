#ifndef TAITACMD_SHARED_CONTEXT
// 00500AD0 TribeTacticalAIModule::numberItemsToDefend
// Observed body remains unresolved. This source keeps the owner callable.

int TribeTacticalAIModule::numberItemsToDefend()
{
    return 0;
}
#else
// BLOCKER: The shared context omits TribeInformationAIModule::numberItemsToDefend.
// A natural member call needs that shared declaration to preserve the direct tail target.
int TribeTacticalAIModule::numberItemsToDefend() {
    return 0;
}
#endif
