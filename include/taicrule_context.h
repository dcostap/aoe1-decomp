#ifndef AOE1_TAICRULE_CONTEXT_H
#define AOE1_TAICRULE_CONTEXT_H

// Canonical local declaration surface for the original taicrule.cpp module.
//
// PDB ownership is C:\\msdev\\work\\age1_x1\\taicrule.cpp, with owners in
// constructor, destructor, loadRules, attack, and defense order.  The class
// inventory proves one virtual slot and a 2504-byte object: the vptr is at
// +0x00 and ratingValue is the 2500-byte table at +0x04.

class CombatRuleSystem {
public:
    virtual ~CombatRuleSystem();
    unsigned char ratingValue[2500];

    CombatRuleSystem();
    int loadRules(char* filename);
    int bestUnitTypeToAttack(int unitType);
    int bestUnitTypeToDefendAgainst(int unitType);
};

typedef char taicrule_combat_rule_system_size[
    (sizeof(CombatRuleSystem) == 0x9C8) ? 1 : -1];

typedef char taicrule_combat_rule_system_vptr[
    (sizeof(void*) == 4) ? 1 : -1];

#endif
