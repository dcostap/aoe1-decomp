// PDB order: constructor, canAttackUnit, canAttackUnitAtNeutrality, processNotify.
// The six NOPs at 0050763A-0050763F follow processNotify as data padding.
// A grouped /GX probe with 00507640 processIdle failed on its separate class
// declarations. Keep that later exact owner outside this group.
#include "matching/00506FE0_TribeSoldierUnitAIModule.cpp"
#include "matching/005071A0_canAttackUnit.cpp"
#include "matching/005071C0_canAttackUnitAtNeutrality.cpp"
#include "matching/005071F0_processNotify.cpp"
