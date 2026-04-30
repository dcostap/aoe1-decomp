// 004DC490 TribeInformationAIModule::objectToAttackWithPlay
// Source: taiinfmd.cpp lines 3277-3451, size 703 bytes
//
// This is a 703-byte function with extreme complexity:
// - sub esp, 0x1E0 (480 bytes local stack frame)
// - 7+ explicit stack params + this
// - AIPlayBook::play, AIPlay::humanPlay, AIPlayStatus ctor,
//   AIPlay::fillGroups, AIPlay::phase, AIPlayPhase::command,
//   inRangeOfUnits, calculatePlayVariation, debug_rand,
//   TribeTacticalAIModule::strategicNumber, AIPlayStatus::copyUnits
// - Nested loops: target loop → world loop → phase loop
// - Switch on AIPlay type (1/2/3 → 0xBD/0xC6/0xC7)
// - Deep field chains: this->md->+0xF0->+0x3C->+0xA0->playbook
//
// Parked: extreme complexity — 703 bytes, ~10 subcalls, deep hierarchies.
// Would require ~50+ probes minimum.
// 
// NOTE: Boss initially stated 276B, actual is 703B (per CSV + packet).
