// Narrow VC5 include probe for the tact_lst owner surface.
//
// Build and redirect the object into build/. The probe intentionally omits
// tact_mob.h because that exact owner header is not present.

#include "../include/tact_lst.h"
#include "../include/act_entr.h"
#include "../include/act_tran.h"
#include "../include/tact_bld.h"
#include "../include/tact_dar.h"
#include "../include/tact_hea.h"
#include "../include/tact_art.h"
#include "../include/tact_hnt.h"
#include "../include/tact_rep.h"
#include "../include/tact_trd.h"
#include "../include/tact_wnd.h"

typedef char tact_lst_probe_action_size[
    (sizeof(RGE_Action) == 0x40) ? 1 : -1];
typedef char tact_lst_probe_list_size[
    (sizeof(RGE_Action_List) == 0x0C) ? 1 : -1];
typedef char tact_lst_probe_build_size[
    (sizeof(TRIBE_Action_Build) == 0x40) ? 1 : -1];
typedef char tact_lst_probe_discovery_size[
    (sizeof(TRIBE_Action_Discovery_Artifact) == 0x44) ? 1 : -1];
typedef char tact_lst_probe_heal_size[
    (sizeof(TRIBE_Action_Heal) == 0x40) ? 1 : -1];

int tact_lst_owner_probe()
{
    return sizeof(TRIBE_Action_List) + sizeof(TRIBE_Action_Build) +
           sizeof(TRIBE_Action_Discovery_Artifact) + sizeof(TRIBE_Action_Heal);
}
