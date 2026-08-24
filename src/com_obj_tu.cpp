// Authentic PDB-ordered owner wrapper for com_obj.cpp.
//
// The source module has 50 normal owners in PDB order.  One compiler-generated
// vector deleting destructor at 0042F9C0 is listed in the proposal only.
// Matching owners are included from src/matching.  Scratch owners remain
// observed.  Accepted-drift owners remain observed and are not promoted.
//
// The shared header is the canonical declaration surface for this module.
// Included owner files keep their isolated declarations behind
// RGE_COM_OBJ_SHARED_CONTEXT.  No grouped-only body fork, namespace alias,
// inline assembly, dummy owner, or metric-only wrapper is used.
// Final grouped result: 3 exact owners, 47 observed owners, 1 generated
// destructor, and no blocked normal owner.

#define RGE_COM_OBJ_SHARED_CONTEXT 1
#include "../include/com_obj_context.h"

#include "matching/0042F930_RGE_Combat_Object.cpp"
#include "matching/0042F9E0_RGE_Combat_Object.cpp"
#include "matching/0042FA50_RGE_Combat_Object.cpp"
#include "matching/0042FAF0_recycle_in_to_game.cpp"
#include "matching/0042FB40_setup.cpp"
#include "matching/0042FBA0_setup.cpp"
#include "matching/0042FC10_save.cpp"
#include "matching/0042FC50_stop.cpp"
#include "scratch/0042FC90_calc_attack_modifier.cpp"
#include "matching/0042FCA0_area_attack.cpp"
#include "scratch/0042FF50_attack.cpp"
#include "scratch/004300F0_attack.cpp"
#include "matching/00430230_do_attack.cpp"
#include "matching/00430320_damage.cpp"
#include "matching/004303A0_calculateDamage.cpp"
#include "matching/00430480_can_attack.cpp"
#include "matching/004304A0_reset_attack_timer.cpp"
#include "matching/004304B0_get_armor.cpp"
#include "matching/00430510_get_weapon.cpp"
#include "matching/00430570_get_weapon_range.cpp"
#include "matching/004305A0_get_speed_of_attack.cpp"
#include "matching/004305D0_release_being_worked_on.cpp"
#include "matching/00430610_enter_obj.cpp"
#include "matching/00430680_update.cpp"
#include "matching/00430810_copy_obj.cpp"
#include "matching/00430850_notify.cpp"
#include "matching/004308C0_attack.cpp"
#include "matching/00430A90_attack.cpp"
#include "matching/00430C10_moveTo.cpp"
#include "matching/00430C30_moveTo.cpp"
#include "accepted_drift/00430D50_moveTo.cpp"
#include "matching/00430EC0_moveAwayFrom.cpp"
#include "accepted_drift/00430ED0_gather.cpp"
#include "scratch/00431020_explore.cpp"
#include "matching/00431150_enter.cpp"
#include "accepted_drift/00431250_transport.cpp"
#include "matching/00431340_unload.cpp"
#include "matching/00431440_stopAction.cpp"
#include "matching/00431470_pause.cpp"
#include "scratch/00431490_rateOfFire.cpp"
#include "matching/004314A0_damageCapability.cpp"
#include "matching/004314F0_damageCapability.cpp"
#include "matching/00431530_inAttackRange.cpp"
#include "scratch/004315A0_weaponRange.cpp"
#include "scratch/004315B0_minimumWeaponRange.cpp"
#include "matching/004315C0_currentTargetID.cpp"
#include "matching/00431610_currentTargetX.cpp"
#include "matching/00431640_currentTargetY.cpp"
#include "matching/00431670_currentTargetZ.cpp"
#include "scratch/004316A0_teleport.cpp"

#undef RGE_COM_OBJ_SHARED_CONTEXT
