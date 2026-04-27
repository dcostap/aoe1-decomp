// BLOCKED: 004F8570 TribeTacticalAIModule::civilian
// BLOCKED: ~600B function with expandable soldiers array, workingArea dedup,
//   world->object lookup, unitAI calls, currentOrder comparisons (3 params),
//   distance-to-position float comparison, and best-unit selection logic.
// Cannot reach non-stub quality within 1 probe — needs full struct layout,
//   virtual method stubs, float comparison model, and expandable-array helpers.
// Packet: taitacmd.cpp lines 7272-7331
