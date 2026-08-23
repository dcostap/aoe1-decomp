// VA: 00417730 UnitAIModule::visibleStatus (60B)
// PDB source: aiuaimod.cpp lines 3900-3910
// __thiscall with 3 params: RGE_Visible_Map* param_1, int param_2 (x), int param_3 (y)
// ret 0Ch = 3 params cleaned.
// Similar to get_visible but accessed via this->objectValue->owner instead of direct player.
// Use #define for absolute address, load-order matching, branch-free explored path.

#define unified_map_offsets ((unsigned long**)0x886808)

#include "../../include/aiuaimod_context.h"

unsigned char UnitAIModule::visibleStatus(class RGE_Visible_Map* param_1, int param_2, int param_3) {
    unsigned long cell = unified_map_offsets[param_3][param_2];
    RGE_Player* owner = this->objectValue->owner;
    if ((owner->mutualVisibleMask & cell) != 0) return 0x0F;
    if ((cell & owner->mutualExploredMask) != 0) return 0x80;
    return 0;
}
