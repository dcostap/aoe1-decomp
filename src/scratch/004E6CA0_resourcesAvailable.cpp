// 004E6CA0 TribeResourceAIModule::resourcesAvailable
// Source: tairesmd.cpp lines 82-110
// Size: 147 bytes, no EH
//
// Attempt log:
// Probe 1: standalone class + for-loop with count local → 144 bytes, wrong offset, ebp for this
// Probe 2: direct-pointer chain + for-loop → extra number() at loop entry (85% diff)
// Probe 3: infinite loop with bottom break + inline chain → completely different (122% diff)
// Probe 4: do-while + limits temp → 60% diff, ebp for this, test ah,1 vs test ah,41h
// Probe 5: for(;;) with top i>=number() break → wrong structure
// Summary: The remaining mismatch is a register allocation basin (ebp vs ebx for this, 
//   ebx vs ebp for limits) and fcomp flag test encoding (test ah,1 vs test ah,41h).
//   Left in scratch — codegen basin, not a source model issue.
