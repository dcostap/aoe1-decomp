// BLOCKED: 004F7E80 TribeTacticalAIModule::idleCivilian
// BLOCKED: ~794B function with expandable array, world object lookup,
//   unitAI calls, currentAction == -1 check, workingArea dedup,
//   master_obj->type == 0x103 check.
// Cannot reach non-stub quality within 1 probe — needs full TribeTacticalAIModule
//   struct, virtual method chain, and managed array helpers.
// Packet: taitacmd.cpp
