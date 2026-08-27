#ifndef AOE1_TVICTORY_H
#define AOE1_TVICTORY_H

// The six owners below are one source module. Their address order is also the
// PDB order: 0052C8F0, 0052C920, 0052C940, 0052C950, 0052C970, and 0052C9B0.

#include "victory.h"

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

typedef char tribe_victory_conditions_size_check[
    (sizeof(TRIBE_Victory_Conditions) == 0x20) ? 1 : -1];

#endif
