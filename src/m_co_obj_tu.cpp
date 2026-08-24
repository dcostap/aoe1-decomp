// Authentic PDB-ordered owner wrapper for m_co_obj.cpp.
//
// Module: C:\\msdev\\work\\age1_x1\\m_co_obj.cpp
// Owner order follows the line bands in build/tu_plans/m_co_obj_cpp.
// The vector deleting destructor at 0044FEA0 is compiler generated and is
// listed in the candidate proposal, not as a source include.
//
// Constructors, factories, and the destructor use the module's observed /GX
// context. The candidate flag response is the existing constructor response
// config/flags/0044FE40_RGE_Master_Combat_Object.rsp.

#define RGE_MCO_OBJ_SHARED_CONTEXT 1
#include "../include/m_co_obj_context.h"

#include "matching/0044FE40_RGE_Master_Combat_Object.cpp"
#include "matching/0044FEC0_RGE_Master_Combat_Object.cpp"
#include "matching/0044FF30_RGE_Master_Combat_Object.cpp"
#include "matching/0044FFB0_setup.cpp"
#include "matching/00450170_setup.cpp"
#include "accepted_drift/00450450_setup.cpp"
#include "matching/00450680_RGE_Master_Combat_Object.cpp"
#include "matching/004506D0_make_new_obj.cpp"
#include "matching/004507A0_make_new_master.cpp"
#include "matching/00450810_copy_obj.cpp"
#include "matching/00450A00_modify.cpp"
#include "matching/00450B40_modify_delta.cpp"
#include "matching/00450D00_modify_percent.cpp"
#include "matching/00450E20_save.cpp"
#include "accepted_drift/00451000_calc_base_damage_ability.cpp"

#undef RGE_MCO_OBJ_SHARED_CONTEXT
