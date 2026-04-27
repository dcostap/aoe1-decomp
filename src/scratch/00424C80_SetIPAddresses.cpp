// 00424C80 RGE_Communications_Addresses::SetIPAddresses
// Source: com_addr.cpp lines 157-198
// Size: 260 bytes, no EH
//
// Attempt log:
// Probe 1: sprintf + strcpy pattern → 240 bytes (20 short), same register basin as SetIPAliases
// - sprintf call, IP byte extraction, and both strcpy patterns match the original
// - Only issue: lazy callee-save register allocation (3 vs 4 at entry, wrong pop order)
// Left in scratch: same codegen basin as SetIPAliases — register allocation for 4 callee-saves
