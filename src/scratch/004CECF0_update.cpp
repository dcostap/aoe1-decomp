// 004CECF0 TRIBE_Action_Heal::update
// Source: tact_hea.cpp lines 175-365
// Size: 739 bytes, no EH
//
// Attempt log:
// Probe 1: 82.27% diff (608 bytes). Full implementation with proper switch structure
// and virtual method stubs for RGE_Action_Object (125 vtable slots) and RGE_Static_Object.
// Main issues: nested switch dispatch (two-level lookup tables for state→case mapping),
// floating point healing math (fmul chain), virtual dispatch through deep class hierarchy.
// Left in scratch: needs proper class hierarchy (RGE_Static_Object→RGE_Moving_Object→RGE_Game_Object)
// with correct vtable slots for all method calls.
