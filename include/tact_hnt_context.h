#ifndef AOE1_TACT_HNT_CONTEXT_H
#define AOE1_TACT_HNT_CONTEXT_H

void rge_read(int, void*, int);
void rge_write(int, void*, int);

// The reviewed tact_hnt declarations live with the exact set_state owner.
// Import that declaration surface without importing its function body.  This
// keeps one compiler-facing class owner while the wrapper restores PDB order.
#define TACT_HNT_CONTEXT_ONLY 1
#ifndef TACT_HNT_SHARED_CONTEXT
#include "../src/matching/004CF300_set_state.cpp"
#else
#define TACT_HNT_CONTEXT_RESTORE_SHARED 1
#undef TACT_HNT_SHARED_CONTEXT
#include "../src/matching/004CF300_set_state.cpp"
#define TACT_HNT_SHARED_CONTEXT 1
#undef TACT_HNT_CONTEXT_RESTORE_SHARED
#endif
#undef TACT_HNT_CONTEXT_ONLY

class RGE_Base_Game {
public:
    char gap_00[0x9A8];
    int quick_build;
};

typedef char tact_hnt_action_abi[(sizeof(RGE_Action) == 0x40) ? 1 : -1];
typedef char tact_hnt_hunt_abi[(sizeof(TRIBE_Action_Hunt) == 0x44) ? 1 : -1];

#endif
