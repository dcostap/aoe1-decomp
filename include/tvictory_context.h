#ifndef AOE1_TVICTORY_CONTEXT_H
#define AOE1_TVICTORY_CONTEXT_H

// Canonical declarations for the tvictory.cpp PDB module.
//
// The six owners below are one source module. Their address order is also the
// PDB order: 0052C8F0, 0052C920, 0052C940, 0052C950, 0052C970, and 0052C9B0.
// The base and derived declarations retain the published call surfaces.

#include "victory_context.h"

class TRIBE_Player_Tech {
public:
    short get_tech_state(short tech);
};

// The victory code receives RGE_Player*, but this module reads the canonical
// TRIBE_Player tech-tree member at +0x220.
class TRIBE_Player : public RGE_Player {
public:
    char gap_108[0x118];
    TRIBE_Player_Tech* tech_tree; // +0x220
};

class TRIBE_Victory_Conditions : public RGE_Victory_Conditions {
public:
    TRIBE_Victory_Conditions(RGE_Player* player, int handle, long* version_map,
                             unsigned char version_flag);
    TRIBE_Victory_Conditions(RGE_Player* player);
    // BINARY NOTE: the PDB owner is the nonvirtual QAE destructor.
    ~TRIBE_Victory_Conditions();
    virtual void handle_condition(RGE_Victory_Entry* entry);

protected:
    void handle_tech(RGE_Victory_Entry* entry);

public:
    unsigned char add_tech(unsigned char id, long count);
};

#endif
