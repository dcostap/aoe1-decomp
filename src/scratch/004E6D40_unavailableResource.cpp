// 004E6D40 TribeResourceAIModule::unavailableResource
// Source: tairesmd.cpp lines 115-128
// Size: 134 bytes, no EH
//
// Attempt log:
// Probe 1: natural do-while loop matching resourcesAvailable pattern, default flags
//   → Same codegen basin as resourcesAvailable: ebp for this vs ebx, test ah,1 vs test ah,41h
//   Left in scratch — codegen basin, not a source model issue.
