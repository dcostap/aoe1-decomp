// TODO: STUB - virtual method forwarding stubs for linker satisfaction
// Auto-generated stubs for derived game object virtual methods.
// Each derived class re-declares all parent virtuals at the same vtable slots.
// These minimal forwarding implementations satisfy the linker when classes
// are instantiated but full transliterations are not yet done.

#include "../include/RGE_Animated_Object.h"
#include "../include/RGE_Moving_Object.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Combat_Object.h"
#include "../include/RGE_Missile_Object.h"
#include "../include/RGE_Doppleganger_Object.h"
#include "../include/RGE_Action_List.h"
#include <cstdarg>
#include <cstdio>

namespace {
void forward_log_debug_to_static(RGE_Static_Object* object, const char* format, va_list args) {
    char formatted_message[1024];
    formatted_message[0] = '\0';

    if (format != nullptr) {
        vsnprintf(formatted_message, sizeof(formatted_message), format, args);
        formatted_message[sizeof(formatted_message) - 1] = '\0';
    }

    object->RGE_Static_Object::logDebug("%s", formatted_message);
}
} // namespace

// =====================================================================
// RGE_Animated_Object  (parent: RGE_Static_Object)
// =====================================================================

// --- Forwarding stubs: same signature as RGE_Static_Object ---
void RGE_Animated_Object::recycle_out_of_game() { RGE_Static_Object::recycle_out_of_game(); } // TODO: STUB

float RGE_Animated_Object::teleport(float param_1, float param_2, float param_3) { return RGE_Static_Object::teleport(param_1, param_2, param_3); } // TODO: STUB
void RGE_Animated_Object::change_ownership(RGE_Player* param_1) { RGE_Static_Object::change_ownership(param_1); } // TODO: STUB
void RGE_Animated_Object::modify(float param_1, uchar param_2) { RGE_Static_Object::modify(param_1, param_2); } // TODO: STUB
void RGE_Animated_Object::modify_delta(float param_1, uchar param_2) { RGE_Static_Object::modify_delta(param_1, param_2); } // TODO: STUB
void RGE_Animated_Object::modify_percent(float param_1, uchar param_2) { RGE_Static_Object::modify_percent(param_1, param_2); } // TODO: STUB
void RGE_Animated_Object::copy_obj(RGE_Master_Static_Object* param_1) { RGE_Static_Object::copy_obj(param_1); } // TODO: STUB
void RGE_Animated_Object::set_object_state(uchar param_1) { RGE_Static_Object::set_object_state(param_1); } // TODO: STUB
void RGE_Animated_Object::remove_visible_resource() { RGE_Static_Object::remove_visible_resource(); } // TODO: STUB
void RGE_Animated_Object::create_doppleganger_when_dying() { RGE_Static_Object::create_doppleganger_when_dying(); } // TODO: STUB
void RGE_Animated_Object::destroy_obj() { RGE_Static_Object::destroy_obj(); } // TODO: STUB
void RGE_Animated_Object::die_die_die() { RGE_Static_Object::die_die_die(); } // TODO: STUB
void RGE_Animated_Object::rotate(long param_1) { RGE_Static_Object::rotate(param_1); } // TODO: STUB
uchar RGE_Animated_Object::can_attack() { return RGE_Static_Object::can_attack(); } // TODO: STUB
void RGE_Animated_Object::set_attribute(short param_1, float param_2) { RGE_Static_Object::set_attribute(param_1, param_2); } // TODO: STUB
void RGE_Animated_Object::set_attribute_amount(float param_1, uchar param_2, uchar param_3) { RGE_Static_Object::set_attribute_amount(param_1, param_2, param_3); } // TODO: STUB
int RGE_Animated_Object::heal(int param_1, int param_2) { return RGE_Static_Object::heal(param_1, param_2); } // TODO: STUB
uchar RGE_Animated_Object::heal(float param_1) { return RGE_Static_Object::heal(param_1); } // TODO: STUB
int RGE_Animated_Object::canRepair() { return RGE_Static_Object::canRepair(); } // TODO: STUB
void RGE_Animated_Object::notify_of_relation(long param_1, uchar param_2) { RGE_Static_Object::notify_of_relation(param_1, param_2); } // TODO: STUB
void RGE_Animated_Object::stop() { RGE_Static_Object::stop(); } // TODO: STUB
void RGE_Animated_Object::play_command_sound() { RGE_Static_Object::play_command_sound(); } // TODO: STUB
void RGE_Animated_Object::play_move_sound() { RGE_Static_Object::play_move_sound(); } // TODO: STUB
void RGE_Animated_Object::new_angle(float param_1) { RGE_Static_Object::new_angle(param_1); } // TODO: STUB
RGE_Static_Object* RGE_Animated_Object::spawn_death_obj() { return RGE_Static_Object::spawn_death_obj(); } // TODO: STUB
uchar RGE_Animated_Object::is_moving() { return RGE_Static_Object::is_moving(); } // TODO: STUB
RGE_Static_Object* RGE_Animated_Object::get_target_obj() { return RGE_Static_Object::get_target_obj(); } // TODO: STUB
void RGE_Animated_Object::enter_obj(RGE_Static_Object* param_1) { RGE_Static_Object::enter_obj(param_1); } // TODO: STUB
void RGE_Animated_Object::exit_obj() { RGE_Static_Object::exit_obj(); } // TODO: STUB
int RGE_Animated_Object::explore_terrain(RGE_Player* param_1, uchar param_2, int param_3) { return RGE_Static_Object::explore_terrain(param_1, param_2, param_3); } // TODO: STUB
void RGE_Animated_Object::unexplore_terrain(RGE_Player* param_1, uchar param_2, int param_3) { RGE_Static_Object::unexplore_terrain(param_1, param_2, param_3); } // TODO: STUB
LOSTBL* RGE_Animated_Object::get_los_table() { return RGE_Static_Object::get_los_table(); } // TODO: STUB
uchar RGE_Animated_Object::underAttack() { return RGE_Static_Object::underAttack(); } // TODO: STUB
void RGE_Animated_Object::setUnderAttack(uchar param_1) { RGE_Static_Object::setUnderAttack(param_1); } // TODO: STUB
float RGE_Animated_Object::getAngle() { return RGE_Static_Object::getAngle(); } // TODO: STUB
float RGE_Animated_Object::maximumSpeed() { return RGE_Static_Object::maximumSpeed(); } // TODO: STUB
float RGE_Animated_Object::rateOfFire() { return RGE_Static_Object::rateOfFire(); } // TODO: STUB
float RGE_Animated_Object::damageCapability(RGE_Static_Object* param_1) { return RGE_Static_Object::damageCapability(param_1); } // TODO: STUB
float RGE_Animated_Object::damageCapability() { return RGE_Static_Object::damageCapability(); } // TODO: STUB
float RGE_Animated_Object::weaponRange() { return RGE_Static_Object::weaponRange(); } // TODO: STUB
float RGE_Animated_Object::minimumWeaponRange() { return RGE_Static_Object::minimumWeaponRange(); } // TODO: STUB
int RGE_Animated_Object::passableTile(float param_1, float param_2, int param_3) { return RGE_Static_Object::passableTile(param_1, param_2, param_3); } // TODO: STUB
uchar RGE_Animated_Object::facetToNextWaypoint() { return RGE_Static_Object::facetToNextWaypoint(); } // TODO: STUB
int RGE_Animated_Object::currentTargetID() { return RGE_Static_Object::currentTargetID(); } // TODO: STUB
float RGE_Animated_Object::currentTargetX() { return RGE_Static_Object::currentTargetX(); } // TODO: STUB
float RGE_Animated_Object::currentTargetY() { return RGE_Static_Object::currentTargetY(); } // TODO: STUB
float RGE_Animated_Object::currentTargetZ() { return RGE_Static_Object::currentTargetZ(); } // TODO: STUB
void RGE_Animated_Object::setWaitingToMove(uchar param_1) { RGE_Static_Object::setWaitingToMove(param_1); } // TODO: STUB
uchar RGE_Animated_Object::waitingToMove() { return RGE_Static_Object::waitingToMove(); } // TODO: STUB
uchar RGE_Animated_Object::actionState() { return RGE_Static_Object::actionState(); } // TODO: STUB
uchar RGE_Animated_Object::keepGatheringWhenObjectIsOut(int param_1) { return RGE_Static_Object::keepGatheringWhenObjectIsOut(param_1); } // TODO: STUB
uchar RGE_Animated_Object::produceWhenKilledBy(int param_1) { return RGE_Static_Object::produceWhenKilledBy(param_1); } // TODO: STUB
uchar RGE_Animated_Object::useSameZoneDropsite() { return RGE_Static_Object::useSameZoneDropsite(); } // TODO: STUB
void RGE_Animated_Object::logDebug(const char* param_1, ...) {
    va_list args;
    va_start(args, param_1);
    forward_log_debug_to_static(this, param_1, args);
    va_end(args);
} // TODO: STUB
void RGE_Animated_Object::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) { RGE_Static_Object::notify(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
int RGE_Animated_Object::attack(float param_1, float param_2, float param_3, int param_4) { return RGE_Static_Object::attack(param_1, param_2, param_3, param_4); } // TODO: STUB
int RGE_Animated_Object::attack(int param_1, int param_2) { return RGE_Static_Object::attack(param_1, param_2); } // TODO: STUB
int RGE_Animated_Object::moveTo(float param_1, float param_2, float param_3, float param_4, int param_5) { return RGE_Static_Object::moveTo(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
int RGE_Animated_Object::moveTo(int param_1, float param_2, int param_3) { return RGE_Static_Object::moveTo(param_1, param_2, param_3); } // TODO: STUB
int RGE_Animated_Object::moveTo(int param_1, int param_2) { return RGE_Static_Object::moveTo(param_1, param_2); } // TODO: STUB
int RGE_Animated_Object::moveAwayFrom(int param_1, int param_2) { return RGE_Static_Object::moveAwayFrom(param_1, param_2); } // TODO: STUB
int RGE_Animated_Object::hunt(int param_1, int param_2) { return RGE_Static_Object::hunt(param_1, param_2); } // TODO: STUB
int RGE_Animated_Object::gather(int param_1, int param_2) { return RGE_Static_Object::gather(param_1, param_2); } // TODO: STUB
int RGE_Animated_Object::convert(int param_1, int param_2) { return RGE_Static_Object::convert(param_1, param_2); } // TODO: STUB
int RGE_Animated_Object::repair(int param_1, int param_2) { return RGE_Static_Object::repair(param_1, param_2); } // TODO: STUB
int RGE_Animated_Object::build(int param_1, int param_2) { return RGE_Static_Object::build(param_1, param_2); } // TODO: STUB
int RGE_Animated_Object::trade(int param_1, int param_2) { return RGE_Static_Object::trade(param_1, param_2); } // TODO: STUB
int RGE_Animated_Object::explore(int param_1, int param_2, int param_3) { return RGE_Static_Object::explore(param_1, param_2, param_3); } // TODO: STUB
int RGE_Animated_Object::enter(int param_1, int param_2) { return RGE_Static_Object::enter(param_1, param_2); } // TODO: STUB
int RGE_Animated_Object::unload(int param_1, float param_2, float param_3, float param_4) { return RGE_Static_Object::unload(param_1, param_2, param_3, param_4); } // TODO: STUB
int RGE_Animated_Object::transport(float param_1, float param_2, float param_3, int param_4) { return RGE_Static_Object::transport(param_1, param_2, param_3, param_4); } // TODO: STUB
int RGE_Animated_Object::stopAction() { return RGE_Static_Object::stopAction(); } // TODO: STUB
int RGE_Animated_Object::pause() { return RGE_Static_Object::pause(); } // TODO: STUB
int RGE_Animated_Object::canPath(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6) { return RGE_Static_Object::canPath(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
int RGE_Animated_Object::canPath(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7) { return RGE_Static_Object::canPath(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
int RGE_Animated_Object::canBidirectionPath(int param_1, int param_2, float param_3, float* param_4, int param_5, int param_6, int param_7) { return RGE_Static_Object::canBidirectionPath(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
int RGE_Animated_Object::canPathWithObstructions(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6, ManagedArray<int>* param_7) { return RGE_Static_Object::canPathWithObstructions(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
int RGE_Animated_Object::canPathWithAdditionalPassability(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7, int param_8, int param_9) { return RGE_Static_Object::canPathWithAdditionalPassability(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); } // TODO: STUB
int RGE_Animated_Object::findFirstTerrainAlongExceptionPath(int param_1, float* param_2, float* param_3) { return RGE_Static_Object::findFirstTerrainAlongExceptionPath(param_1, param_2, param_3); } // TODO: STUB
int RGE_Animated_Object::canLinePath(int param_1, int param_2, int param_3, int param_4, float param_5, int param_6) { return RGE_Static_Object::canLinePath(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
int RGE_Animated_Object::canLinePath(XYPoint* param_1, XYPoint* param_2, float param_3, XYPoint* param_4, int param_5) { return RGE_Static_Object::canLinePath(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
int RGE_Animated_Object::firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6) { return RGE_Static_Object::firstTileAlongLine(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
XYZBYTEPoint* RGE_Animated_Object::userDefinedWaypoint(int param_1) { return RGE_Static_Object::userDefinedWaypoint(param_1); } // TODO: STUB
int RGE_Animated_Object::addUserDefinedWaypoint(XYZBYTEPoint* param_1, int param_2) { return RGE_Static_Object::addUserDefinedWaypoint(param_1, param_2); } // TODO: STUB
void RGE_Animated_Object::removeAllUserDefinedWaypoints(int param_1) { RGE_Static_Object::removeAllUserDefinedWaypoints(param_1); } // TODO: STUB
void RGE_Animated_Object::removeUserDefinedWaypoint(int param_1) { RGE_Static_Object::removeUserDefinedWaypoint(param_1); } // TODO: STUB
int RGE_Animated_Object::numberUserDefinedWaypoints() { return RGE_Static_Object::numberUserDefinedWaypoints(); } // TODO: STUB
Path* RGE_Animated_Object::findAvoidancePath(XYZPoint* param_1, float param_2, int param_3) { return RGE_Static_Object::findAvoidancePath(param_1, param_2, param_3); } // TODO: STUB
long RGE_Animated_Object::get_action_checksum() { return RGE_Static_Object::get_action_checksum(); } // TODO: STUB
long RGE_Animated_Object::get_waypoint_checksum() { return RGE_Static_Object::get_waypoint_checksum(); } // TODO: STUB
// setup(int, RGE_Game_World*) -- ALREADY IMPLEMENTED in RGE_Animated_Object.cpp
int RGE_Animated_Object::setup(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) { return RGE_Static_Object::setup(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
RGE_Object_List* RGE_Animated_Object::create_object_list() { return RGE_Static_Object::create_object_list(); } // TODO: STUB
RGE_Active_Sprite_List* RGE_Animated_Object::create_sprite_list() { return RGE_Static_Object::create_sprite_list(); } // TODO: STUB

// --- Different signature from parent (return defaults) ---
void RGE_Animated_Object::damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) {} // TODO: STUB - extra param vs Static
float RGE_Animated_Object::calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) { return 0.0f; } // TODO: STUB - extra param vs Static
void RGE_Animated_Object::do_command(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { RGE_Static_Object::do_command(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Animated_Object::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { RGE_Static_Object::move_to(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Animated_Object::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { RGE_Static_Object::work(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Animated_Object::set_attack(RGE_Static_Object* param_1) { RGE_Static_Object::set_attack(param_1); } // TODO: STUB
RGE_Master_Static_Object* RGE_Animated_Object::get_command_master(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Static_Object::get_command_master(param_1, param_2, param_3, param_4); } // TODO: STUB
int RGE_Animated_Object::inAttackRange(RGE_Static_Object* param_1) { return RGE_Static_Object::inAttackRange(param_1); } // TODO: STUB
float RGE_Animated_Object::calc_attack_modifier(RGE_Static_Object* param_1) { return RGE_Static_Object::calc_attack_modifier(param_1); } // TODO: STUB

// --- New virtual in Animated (not in Static) ---


// =====================================================================
// RGE_Moving_Object  (parent: RGE_Animated_Object)
// =====================================================================


// --- Forwarding stubs: same signature as RGE_Animated_Object ---

void RGE_Moving_Object::recycle_out_of_game() { RGE_Animated_Object::recycle_out_of_game(); } // TODO: STUB
void RGE_Moving_Object::draw_front_frame(TDrawArea* param_1, short param_2, short param_3) { RGE_Animated_Object::draw_front_frame(param_1, param_2, param_3); } // TODO: STUB
void RGE_Moving_Object::draw_back_frame(TDrawArea* param_1, short param_2, short param_3) { RGE_Animated_Object::draw_back_frame(param_1, param_2, param_3); } // TODO: STUB
void RGE_Moving_Object::draw_frame(TDrawArea* param_1, short param_2, short param_3) { RGE_Animated_Object::draw_frame(param_1, param_2, param_3); } // TODO: STUB
void RGE_Moving_Object::check_damage_sprites() { RGE_Animated_Object::check_damage_sprites(); } // TODO: STUB
void RGE_Moving_Object::rehook() { RGE_Animated_Object::rehook(); } // TODO: STUB
void RGE_Moving_Object::add_overlay_sprite(RGE_Sprite* param_1, uchar param_2) { RGE_Animated_Object::add_overlay_sprite(param_1, param_2); } // TODO: STUB
void RGE_Moving_Object::remove_overlay_sprite(RGE_Sprite* param_1) { RGE_Animated_Object::remove_overlay_sprite(param_1); } // TODO: STUB
void RGE_Moving_Object::change_ownership(RGE_Player* param_1) { RGE_Animated_Object::change_ownership(param_1); } // TODO: STUB
void RGE_Moving_Object::modify(float param_1, uchar param_2) { RGE_Animated_Object::modify(param_1, param_2); } // TODO: STUB
void RGE_Moving_Object::modify_delta(float param_1, uchar param_2) { RGE_Animated_Object::modify_delta(param_1, param_2); } // TODO: STUB
void RGE_Moving_Object::modify_percent(float param_1, uchar param_2) { RGE_Animated_Object::modify_percent(param_1, param_2); } // TODO: STUB
void RGE_Moving_Object::set_object_state(uchar param_1) { RGE_Animated_Object::set_object_state(param_1); } // TODO: STUB
void RGE_Moving_Object::remove_visible_resource() { RGE_Animated_Object::remove_visible_resource(); } // TODO: STUB
void RGE_Moving_Object::create_doppleganger_when_dying() { RGE_Animated_Object::create_doppleganger_when_dying(); } // TODO: STUB
void RGE_Moving_Object::destroy_obj() { RGE_Animated_Object::destroy_obj(); } // TODO: STUB
void RGE_Moving_Object::die_die_die() { RGE_Animated_Object::die_die_die(); } // TODO: STUB
void RGE_Moving_Object::damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) { RGE_Animated_Object::damage(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
float RGE_Moving_Object::calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) { return RGE_Animated_Object::calculateDamage(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
uchar RGE_Moving_Object::can_attack() { return RGE_Animated_Object::can_attack(); } // TODO: STUB
void RGE_Moving_Object::set_attribute(short param_1, float param_2) { RGE_Animated_Object::set_attribute(param_1, param_2); } // TODO: STUB
void RGE_Moving_Object::set_attribute_amount(float param_1, uchar param_2, uchar param_3) { RGE_Animated_Object::set_attribute_amount(param_1, param_2, param_3); } // TODO: STUB
int RGE_Moving_Object::heal(int param_1, int param_2) { return RGE_Animated_Object::heal(param_1, param_2); } // TODO: STUB
uchar RGE_Moving_Object::heal(float param_1) { return RGE_Animated_Object::heal(param_1); } // TODO: STUB
int RGE_Moving_Object::canRepair() { return RGE_Animated_Object::canRepair(); } // TODO: STUB
void RGE_Moving_Object::notify_of_relation(long param_1, uchar param_2) { RGE_Animated_Object::notify_of_relation(param_1, param_2); } // TODO: STUB
void RGE_Moving_Object::do_command(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { RGE_Animated_Object::do_command(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Moving_Object::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { RGE_Animated_Object::move_to(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Moving_Object::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { RGE_Animated_Object::work(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Moving_Object::stop() { RGE_Animated_Object::stop(); } // TODO: STUB
void RGE_Moving_Object::set_attack(RGE_Static_Object* param_1) { RGE_Animated_Object::set_attack(param_1); } // TODO: STUB
void RGE_Moving_Object::play_command_sound() { RGE_Animated_Object::play_command_sound(); } // TODO: STUB
void RGE_Moving_Object::play_move_sound() { RGE_Animated_Object::play_move_sound(); } // TODO: STUB
RGE_Master_Static_Object* RGE_Moving_Object::get_command_master(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Animated_Object::get_command_master(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Moving_Object::set_being_worked_on(RGE_Action_Object* param_1, short param_2, uchar param_3) { RGE_Animated_Object::set_being_worked_on(param_1, param_2, param_3); } // TODO: STUB
void RGE_Moving_Object::release_being_worked_on(RGE_Static_Object* param_1) { RGE_Animated_Object::release_being_worked_on(param_1); } // TODO: STUB
RGE_Static_Object* RGE_Moving_Object::get_target_obj() { return RGE_Animated_Object::get_target_obj(); } // TODO: STUB
void RGE_Moving_Object::enter_obj(RGE_Static_Object* param_1) { RGE_Animated_Object::enter_obj(param_1); } // TODO: STUB
void RGE_Moving_Object::exit_obj() { RGE_Animated_Object::exit_obj(); } // TODO: STUB
int RGE_Moving_Object::explore_terrain(RGE_Player* param_1, uchar param_2, int param_3) { return RGE_Animated_Object::explore_terrain(param_1, param_2, param_3); } // TODO: STUB
void RGE_Moving_Object::unexplore_terrain(RGE_Player* param_1, uchar param_2, int param_3) { RGE_Animated_Object::unexplore_terrain(param_1, param_2, param_3); } // TODO: STUB
LOSTBL* RGE_Moving_Object::get_los_table() { return RGE_Animated_Object::get_los_table(); } // TODO: STUB
int RGE_Moving_Object::inAttackRange(RGE_Static_Object* param_1) { return RGE_Animated_Object::inAttackRange(param_1); } // TODO: STUB
uchar RGE_Moving_Object::underAttack() { return RGE_Animated_Object::underAttack(); } // TODO: STUB
void RGE_Moving_Object::setUnderAttack(uchar param_1) { RGE_Animated_Object::setUnderAttack(param_1); } // TODO: STUB
float RGE_Moving_Object::calc_attack_modifier(RGE_Static_Object* param_1) { return RGE_Animated_Object::calc_attack_modifier(param_1); } // TODO: STUB
float RGE_Moving_Object::getSpeed() { return RGE_Animated_Object::getSpeed(); } // TODO: STUB
float RGE_Moving_Object::rateOfFire() { return RGE_Animated_Object::rateOfFire(); } // TODO: STUB
float RGE_Moving_Object::damageCapability(RGE_Static_Object* param_1) { return RGE_Animated_Object::damageCapability(param_1); } // TODO: STUB
float RGE_Moving_Object::damageCapability() { return RGE_Animated_Object::damageCapability(); } // TODO: STUB
float RGE_Moving_Object::weaponRange() { return RGE_Animated_Object::weaponRange(); } // TODO: STUB
float RGE_Moving_Object::minimumWeaponRange() { return RGE_Animated_Object::minimumWeaponRange(); } // TODO: STUB
int RGE_Moving_Object::currentTargetID() { return RGE_Animated_Object::currentTargetID(); } // TODO: STUB
float RGE_Moving_Object::currentTargetX() { return RGE_Animated_Object::currentTargetX(); } // TODO: STUB
float RGE_Moving_Object::currentTargetY() { return RGE_Animated_Object::currentTargetY(); } // TODO: STUB
float RGE_Moving_Object::currentTargetZ() { return RGE_Animated_Object::currentTargetZ(); } // TODO: STUB
uchar RGE_Moving_Object::actionState() { return RGE_Animated_Object::actionState(); } // TODO: STUB
uchar RGE_Moving_Object::keepGatheringWhenObjectIsOut(int param_1) { return RGE_Animated_Object::keepGatheringWhenObjectIsOut(param_1); } // TODO: STUB
uchar RGE_Moving_Object::produceWhenKilledBy(int param_1) { return RGE_Animated_Object::produceWhenKilledBy(param_1); } // TODO: STUB
uchar RGE_Moving_Object::useSameZoneDropsite() { return RGE_Animated_Object::useSameZoneDropsite(); } // TODO: STUB
void RGE_Moving_Object::logDebug(const char* param_1, ...) {
    va_list args;
    va_start(args, param_1);
    forward_log_debug_to_static(this, param_1, args);
    va_end(args);
} // TODO: STUB
void RGE_Moving_Object::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) { RGE_Animated_Object::notify(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
int RGE_Moving_Object::attack(float param_1, float param_2, float param_3, int param_4) { return RGE_Animated_Object::attack(param_1, param_2, param_3, param_4); } // TODO: STUB
int RGE_Moving_Object::attack(int param_1, int param_2) { return RGE_Animated_Object::attack(param_1, param_2); } // TODO: STUB
int RGE_Moving_Object::moveTo(float param_1, float param_2, float param_3, float param_4, int param_5) { return RGE_Animated_Object::moveTo(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
int RGE_Moving_Object::moveTo(int param_1, float param_2, int param_3) { return RGE_Animated_Object::moveTo(param_1, param_2, param_3); } // TODO: STUB
int RGE_Moving_Object::moveTo(int param_1, int param_2) { return RGE_Animated_Object::moveTo(param_1, param_2); } // TODO: STUB
int RGE_Moving_Object::moveAwayFrom(int param_1, int param_2) { return RGE_Animated_Object::moveAwayFrom(param_1, param_2); } // TODO: STUB
int RGE_Moving_Object::hunt(int param_1, int param_2) { return RGE_Animated_Object::hunt(param_1, param_2); } // TODO: STUB
int RGE_Moving_Object::gather(int param_1, int param_2) { return RGE_Animated_Object::gather(param_1, param_2); } // TODO: STUB
int RGE_Moving_Object::convert(int param_1, int param_2) { return RGE_Animated_Object::convert(param_1, param_2); } // TODO: STUB
int RGE_Moving_Object::repair(int param_1, int param_2) { return RGE_Animated_Object::repair(param_1, param_2); } // TODO: STUB
int RGE_Moving_Object::build(int param_1, int param_2) { return RGE_Animated_Object::build(param_1, param_2); } // TODO: STUB
int RGE_Moving_Object::trade(int param_1, int param_2) { return RGE_Animated_Object::trade(param_1, param_2); } // TODO: STUB
int RGE_Moving_Object::explore(int param_1, int param_2, int param_3) { return RGE_Animated_Object::explore(param_1, param_2, param_3); } // TODO: STUB
int RGE_Moving_Object::enter(int param_1, int param_2) { return RGE_Animated_Object::enter(param_1, param_2); } // TODO: STUB
int RGE_Moving_Object::unload(int param_1, float param_2, float param_3, float param_4) { return RGE_Animated_Object::unload(param_1, param_2, param_3, param_4); } // TODO: STUB
int RGE_Moving_Object::transport(float param_1, float param_2, float param_3, int param_4) { return RGE_Animated_Object::transport(param_1, param_2, param_3, param_4); } // TODO: STUB
int RGE_Moving_Object::stopAction() { return RGE_Animated_Object::stopAction(); } // TODO: STUB
int RGE_Moving_Object::pause() { return RGE_Animated_Object::pause(); } // TODO: STUB
long RGE_Moving_Object::get_action_checksum() { return RGE_Animated_Object::get_action_checksum(); } // TODO: STUB
// setup(int, RGE_Game_World*) -- ALREADY IMPLEMENTED in RGE_Moving_Object.cpp
int RGE_Moving_Object::setup(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) { return RGE_Animated_Object::setup(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
RGE_Object_List* RGE_Moving_Object::create_object_list() { return RGE_Animated_Object::create_object_list(); } // TODO: STUB
RGE_Active_Sprite_List* RGE_Moving_Object::create_sprite_list() { return RGE_Animated_Object::create_sprite_list(); } // TODO: STUB
int RGE_Moving_Object::setup(RGE_Master_Animated_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) { return RGE_Animated_Object::setup(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB

// --- New virtuals in Moving (not in Animated) ---


// =====================================================================
// RGE_Action_Object  (parent: RGE_Moving_Object)
// =====================================================================


// --- Forwarding stubs: same signature as RGE_Moving_Object ---

void RGE_Action_Object::draw_front_frame(TDrawArea* param_1, short param_2, short param_3) { RGE_Moving_Object::draw_front_frame(param_1, param_2, param_3); } // TODO: STUB
void RGE_Action_Object::draw_back_frame(TDrawArea* param_1, short param_2, short param_3) { RGE_Moving_Object::draw_back_frame(param_1, param_2, param_3); } // TODO: STUB
void RGE_Action_Object::draw_frame(TDrawArea* param_1, short param_2, short param_3) { RGE_Moving_Object::draw_frame(param_1, param_2, param_3); } // TODO: STUB
void RGE_Action_Object::check_damage_sprites() { RGE_Moving_Object::check_damage_sprites(); } // TODO: STUB
float RGE_Action_Object::teleport(float param_1, float param_2, float param_3) { return RGE_Moving_Object::teleport(param_1, param_2, param_3); } // TODO: STUB
void RGE_Action_Object::new_sprite(RGE_Sprite* param_1) { RGE_Moving_Object::new_sprite(param_1); } // TODO: STUB
void RGE_Action_Object::add_overlay_sprite(RGE_Sprite* param_1, uchar param_2) { RGE_Moving_Object::add_overlay_sprite(param_1, param_2); } // TODO: STUB
void RGE_Action_Object::remove_overlay_sprite(RGE_Sprite* param_1) { RGE_Moving_Object::remove_overlay_sprite(param_1); } // TODO: STUB
void RGE_Action_Object::modify(float param_1, uchar param_2) { RGE_Moving_Object::modify(param_1, param_2); } // TODO: STUB
void RGE_Action_Object::modify_delta(float param_1, uchar param_2) { RGE_Moving_Object::modify_delta(param_1, param_2); } // TODO: STUB
void RGE_Action_Object::modify_percent(float param_1, uchar param_2) { RGE_Moving_Object::modify_percent(param_1, param_2); } // TODO: STUB
void RGE_Action_Object::set_object_state(uchar param_1) { RGE_Moving_Object::set_object_state(param_1); } // TODO: STUB
void RGE_Action_Object::remove_visible_resource() { RGE_Moving_Object::remove_visible_resource(); } // TODO: STUB
void RGE_Action_Object::create_doppleganger_when_dying() { RGE_Moving_Object::create_doppleganger_when_dying(); } // TODO: STUB
void RGE_Action_Object::die_die_die() { RGE_Moving_Object::die_die_die(); } // TODO: STUB
void RGE_Action_Object::damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) { RGE_Moving_Object::damage(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
float RGE_Action_Object::calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) { return RGE_Moving_Object::calculateDamage(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
void RGE_Action_Object::rotate(long param_1) { RGE_Moving_Object::rotate(param_1); } // TODO: STUB
uchar RGE_Action_Object::can_attack() { return RGE_Moving_Object::can_attack(); } // TODO: STUB
void RGE_Action_Object::set_attribute(short param_1, float param_2) { RGE_Moving_Object::set_attribute(param_1, param_2); } // TODO: STUB
void RGE_Action_Object::set_attribute_amount(float param_1, uchar param_2, uchar param_3) { RGE_Moving_Object::set_attribute_amount(param_1, param_2, param_3); } // TODO: STUB
int RGE_Action_Object::heal(int param_1, int param_2) { return RGE_Moving_Object::heal(param_1, param_2); } // TODO: STUB
uchar RGE_Action_Object::heal(float param_1) { return RGE_Moving_Object::heal(param_1); } // TODO: STUB
int RGE_Action_Object::canRepair() { return RGE_Moving_Object::canRepair(); } // TODO: STUB
void RGE_Action_Object::new_angle(float param_1) { RGE_Moving_Object::new_angle(param_1); } // TODO: STUB
RGE_Static_Object* RGE_Action_Object::spawn_death_obj() { return RGE_Moving_Object::spawn_death_obj(); } // TODO: STUB
void RGE_Action_Object::release_being_worked_on(RGE_Static_Object* param_1) { RGE_Moving_Object::release_being_worked_on(param_1); } // TODO: STUB
uchar RGE_Action_Object::is_moving() { return RGE_Moving_Object::is_moving(); } // TODO: STUB
void RGE_Action_Object::enter_obj(RGE_Static_Object* param_1) { RGE_Moving_Object::enter_obj(param_1); } // TODO: STUB
void RGE_Action_Object::exit_obj() { RGE_Moving_Object::exit_obj(); } // TODO: STUB
int RGE_Action_Object::explore_terrain(RGE_Player* param_1, uchar param_2, int param_3) { return RGE_Moving_Object::explore_terrain(param_1, param_2, param_3); } // TODO: STUB
void RGE_Action_Object::unexplore_terrain(RGE_Player* param_1, uchar param_2, int param_3) { RGE_Moving_Object::unexplore_terrain(param_1, param_2, param_3); } // TODO: STUB
LOSTBL* RGE_Action_Object::get_los_table() { return RGE_Moving_Object::get_los_table(); } // TODO: STUB
int RGE_Action_Object::inAttackRange(RGE_Static_Object* param_1) { return RGE_Moving_Object::inAttackRange(param_1); } // TODO: STUB
uchar RGE_Action_Object::underAttack() { return RGE_Moving_Object::underAttack(); } // TODO: STUB
void RGE_Action_Object::setUnderAttack(uchar param_1) { RGE_Moving_Object::setUnderAttack(param_1); } // TODO: STUB
float RGE_Action_Object::calc_attack_modifier(RGE_Static_Object* param_1) { return RGE_Moving_Object::calc_attack_modifier(param_1); } // TODO: STUB
float RGE_Action_Object::getSpeed() { return RGE_Moving_Object::getSpeed(); } // TODO: STUB
float RGE_Action_Object::getAngle() { return RGE_Moving_Object::getAngle(); } // TODO: STUB
float RGE_Action_Object::maximumSpeed() { return RGE_Moving_Object::maximumSpeed(); } // TODO: STUB
float RGE_Action_Object::rateOfFire() { return RGE_Moving_Object::rateOfFire(); } // TODO: STUB
float RGE_Action_Object::damageCapability(RGE_Static_Object* param_1) { return RGE_Moving_Object::damageCapability(param_1); } // TODO: STUB
float RGE_Action_Object::damageCapability() { return RGE_Moving_Object::damageCapability(); } // TODO: STUB
float RGE_Action_Object::weaponRange() { return RGE_Moving_Object::weaponRange(); } // TODO: STUB
float RGE_Action_Object::minimumWeaponRange() { return RGE_Moving_Object::minimumWeaponRange(); } // TODO: STUB
int RGE_Action_Object::passableTile(float param_1, float param_2, int param_3) { return RGE_Moving_Object::passableTile(param_1, param_2, param_3); } // TODO: STUB
uchar RGE_Action_Object::facetToNextWaypoint() { return RGE_Moving_Object::facetToNextWaypoint(); } // TODO: STUB
int RGE_Action_Object::currentTargetID() { return RGE_Moving_Object::currentTargetID(); } // TODO: STUB
float RGE_Action_Object::currentTargetX() { return RGE_Moving_Object::currentTargetX(); } // TODO: STUB
float RGE_Action_Object::currentTargetY() { return RGE_Moving_Object::currentTargetY(); } // TODO: STUB
float RGE_Action_Object::currentTargetZ() { return RGE_Moving_Object::currentTargetZ(); } // TODO: STUB
void RGE_Action_Object::setWaitingToMove(uchar param_1) { RGE_Moving_Object::setWaitingToMove(param_1); } // TODO: STUB
uchar RGE_Action_Object::waitingToMove() { return RGE_Moving_Object::waitingToMove(); } // TODO: STUB
uchar RGE_Action_Object::keepGatheringWhenObjectIsOut(int param_1) { return RGE_Moving_Object::keepGatheringWhenObjectIsOut(param_1); } // TODO: STUB
uchar RGE_Action_Object::produceWhenKilledBy(int param_1) { return RGE_Moving_Object::produceWhenKilledBy(param_1); } // TODO: STUB
uchar RGE_Action_Object::useSameZoneDropsite() { return RGE_Moving_Object::useSameZoneDropsite(); } // TODO: STUB
void RGE_Action_Object::logDebug(const char* param_1, ...) {
    va_list args;
    va_start(args, param_1);
    forward_log_debug_to_static(this, param_1, args);
    va_end(args);
} // TODO: STUB
void RGE_Action_Object::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) { RGE_Moving_Object::notify(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
int RGE_Action_Object::attack(float param_1, float param_2, float param_3, int param_4) { return RGE_Moving_Object::attack(param_1, param_2, param_3, param_4); } // TODO: STUB
int RGE_Action_Object::attack(int param_1, int param_2) { return RGE_Moving_Object::attack(param_1, param_2); } // TODO: STUB
int RGE_Action_Object::moveTo(float param_1, float param_2, float param_3, float param_4, int param_5) { return RGE_Moving_Object::moveTo(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
int RGE_Action_Object::moveTo(int param_1, float param_2, int param_3) { return RGE_Moving_Object::moveTo(param_1, param_2, param_3); } // TODO: STUB
int RGE_Action_Object::moveTo(int param_1, int param_2) { return RGE_Moving_Object::moveTo(param_1, param_2); } // TODO: STUB
int RGE_Action_Object::moveAwayFrom(int param_1, int param_2) { return RGE_Moving_Object::moveAwayFrom(param_1, param_2); } // TODO: STUB
int RGE_Action_Object::hunt(int param_1, int param_2) { return RGE_Moving_Object::hunt(param_1, param_2); } // TODO: STUB
int RGE_Action_Object::gather(int param_1, int param_2) { return RGE_Moving_Object::gather(param_1, param_2); } // TODO: STUB
int RGE_Action_Object::convert(int param_1, int param_2) { return RGE_Moving_Object::convert(param_1, param_2); } // TODO: STUB
int RGE_Action_Object::repair(int param_1, int param_2) { return RGE_Moving_Object::repair(param_1, param_2); } // TODO: STUB
int RGE_Action_Object::build(int param_1, int param_2) { return RGE_Moving_Object::build(param_1, param_2); } // TODO: STUB
int RGE_Action_Object::trade(int param_1, int param_2) { return RGE_Moving_Object::trade(param_1, param_2); } // TODO: STUB
int RGE_Action_Object::explore(int param_1, int param_2, int param_3) { return RGE_Moving_Object::explore(param_1, param_2, param_3); } // TODO: STUB
int RGE_Action_Object::enter(int param_1, int param_2) { return RGE_Moving_Object::enter(param_1, param_2); } // TODO: STUB
int RGE_Action_Object::unload(int param_1, float param_2, float param_3, float param_4) { return RGE_Moving_Object::unload(param_1, param_2, param_3, param_4); } // TODO: STUB
int RGE_Action_Object::transport(float param_1, float param_2, float param_3, int param_4) { return RGE_Moving_Object::transport(param_1, param_2, param_3, param_4); } // TODO: STUB
int RGE_Action_Object::stopAction() { return RGE_Moving_Object::stopAction(); } // TODO: STUB
int RGE_Action_Object::pause() { return RGE_Moving_Object::pause(); } // TODO: STUB
int RGE_Action_Object::canPath(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6) { return RGE_Moving_Object::canPath(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
int RGE_Action_Object::canPath(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7) { return RGE_Moving_Object::canPath(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
int RGE_Action_Object::canBidirectionPath(int param_1, int param_2, float param_3, float* param_4, int param_5, int param_6, int param_7) { return RGE_Moving_Object::canBidirectionPath(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
int RGE_Action_Object::canPathWithObstructions(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6, ManagedArray<int>* param_7) { return RGE_Moving_Object::canPathWithObstructions(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
int RGE_Action_Object::canPathWithAdditionalPassability(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7, int param_8, int param_9) { return RGE_Moving_Object::canPathWithAdditionalPassability(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); } // TODO: STUB
int RGE_Action_Object::findFirstTerrainAlongExceptionPath(int param_1, float* param_2, float* param_3) { return RGE_Moving_Object::findFirstTerrainAlongExceptionPath(param_1, param_2, param_3); } // TODO: STUB
int RGE_Action_Object::canLinePath(int param_1, int param_2, int param_3, int param_4, float param_5, int param_6) { return RGE_Moving_Object::canLinePath(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
int RGE_Action_Object::canLinePath(XYPoint* param_1, XYPoint* param_2, float param_3, XYPoint* param_4, int param_5) { return RGE_Moving_Object::canLinePath(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
int RGE_Action_Object::firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6) { return RGE_Moving_Object::firstTileAlongLine(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
XYZBYTEPoint* RGE_Action_Object::userDefinedWaypoint(int param_1) { return RGE_Moving_Object::userDefinedWaypoint(param_1); } // TODO: STUB
int RGE_Action_Object::addUserDefinedWaypoint(XYZBYTEPoint* param_1, int param_2) { return RGE_Moving_Object::addUserDefinedWaypoint(param_1, param_2); } // TODO: STUB
void RGE_Action_Object::removeAllUserDefinedWaypoints(int param_1) { RGE_Moving_Object::removeAllUserDefinedWaypoints(param_1); } // TODO: STUB
void RGE_Action_Object::removeUserDefinedWaypoint(int param_1) { RGE_Moving_Object::removeUserDefinedWaypoint(param_1); } // TODO: STUB
int RGE_Action_Object::numberUserDefinedWaypoints() { return RGE_Moving_Object::numberUserDefinedWaypoints(); } // TODO: STUB
Path* RGE_Action_Object::findAvoidancePath(XYZPoint* param_1, float param_2, int param_3) { return RGE_Moving_Object::findAvoidancePath(param_1, param_2, param_3); } // TODO: STUB
long RGE_Action_Object::get_waypoint_checksum() { return RGE_Moving_Object::get_waypoint_checksum(); } // TODO: STUB
// setup(int, RGE_Game_World*) -- ALREADY IMPLEMENTED in RGE_Action_Object.cpp
int RGE_Action_Object::setup(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) { return RGE_Moving_Object::setup(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
RGE_Object_List* RGE_Action_Object::create_object_list() { return RGE_Moving_Object::create_object_list(); } // TODO: STUB
RGE_Active_Sprite_List* RGE_Action_Object::create_sprite_list() { return RGE_Moving_Object::create_sprite_list(); } // TODO: STUB
int RGE_Action_Object::setup(RGE_Master_Animated_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) { return RGE_Moving_Object::setup(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
void RGE_Action_Object::stop_moving() { RGE_Moving_Object::stop_moving(); } // TODO: STUB
uchar RGE_Action_Object::turn_towards(RGE_Static_Object* param_1, float param_2, float param_3) { return RGE_Moving_Object::turn_towards(param_1, param_2, param_3); } // TODO: STUB
int RGE_Action_Object::setup(RGE_Master_Moving_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) { return RGE_Moving_Object::setup(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB

// --- Different signature from parent (vt[48] set_being_worked_on) ---
void RGE_Action_Object::set_being_worked_on(RGE_Action_Object* param_1, short param_2, uchar param_3) { RGE_Moving_Object::set_being_worked_on(param_1, param_2, param_3); } // TODO: STUB

// --- New virtuals in Action (not in Moving) ---
// create_action_list() -- ALREADY IMPLEMENTED in RGE_Action_Object.cpp


// =====================================================================
// RGE_Combat_Object  (parent: RGE_Action_Object)
// =====================================================================

// --- Forwarding stubs: same signature as RGE_Action_Object ---

void RGE_Combat_Object::recycle_out_of_game() { RGE_Action_Object::recycle_out_of_game(); } // TODO: STUB
void RGE_Combat_Object::draw_front_frame(TDrawArea* param_1, short param_2, short param_3) { RGE_Action_Object::draw_front_frame(param_1, param_2, param_3); } // TODO: STUB
void RGE_Combat_Object::draw_back_frame(TDrawArea* param_1, short param_2, short param_3) { RGE_Action_Object::draw_back_frame(param_1, param_2, param_3); } // TODO: STUB
void RGE_Combat_Object::draw_frame(TDrawArea* param_1, short param_2, short param_3) { RGE_Action_Object::draw_frame(param_1, param_2, param_3); } // TODO: STUB
// update() -- ALREADY IMPLEMENTED in RGE_Combat_Object.cpp
void RGE_Combat_Object::check_damage_sprites() { RGE_Action_Object::check_damage_sprites(); } // TODO: STUB
void RGE_Combat_Object::rehook() { RGE_Action_Object::rehook(); } // TODO: STUB
// save(int) -- ALREADY IMPLEMENTED in RGE_Combat_Object.cpp
void RGE_Combat_Object::new_sprite(RGE_Sprite* param_1) { RGE_Action_Object::new_sprite(param_1); } // TODO: STUB
void RGE_Combat_Object::add_overlay_sprite(RGE_Sprite* param_1, uchar param_2) { RGE_Action_Object::add_overlay_sprite(param_1, param_2); } // TODO: STUB
void RGE_Combat_Object::remove_overlay_sprite(RGE_Sprite* param_1) { RGE_Action_Object::remove_overlay_sprite(param_1); } // TODO: STUB
void RGE_Combat_Object::change_ownership(RGE_Player* param_1) { RGE_Action_Object::change_ownership(param_1); } // TODO: STUB
void RGE_Combat_Object::modify(float param_1, uchar param_2) { RGE_Action_Object::modify(param_1, param_2); } // TODO: STUB
void RGE_Combat_Object::modify_delta(float param_1, uchar param_2) { RGE_Action_Object::modify_delta(param_1, param_2); } // TODO: STUB
void RGE_Combat_Object::modify_percent(float param_1, uchar param_2) { RGE_Action_Object::modify_percent(param_1, param_2); } // TODO: STUB
void RGE_Combat_Object::transform(RGE_Master_Static_Object* param_1) { RGE_Action_Object::transform(param_1); } // TODO: STUB
void RGE_Combat_Object::set_object_state(uchar param_1) { RGE_Action_Object::set_object_state(param_1); } // TODO: STUB
void RGE_Combat_Object::remove_visible_resource() { RGE_Action_Object::remove_visible_resource(); } // TODO: STUB
void RGE_Combat_Object::create_doppleganger_when_dying() { RGE_Action_Object::create_doppleganger_when_dying(); } // TODO: STUB
void RGE_Combat_Object::destroy_obj() { RGE_Action_Object::destroy_obj(); } // TODO: STUB
void RGE_Combat_Object::die_die_die() { RGE_Action_Object::die_die_die(); } // TODO: STUB
// damage(...) -- ALREADY IMPLEMENTED in RGE_Combat_Object.cpp
// calculateDamage(...) -- ALREADY IMPLEMENTED in RGE_Combat_Object.cpp
void RGE_Combat_Object::rotate(long param_1) { RGE_Action_Object::rotate(param_1); } // TODO: STUB
// can_attack() -- ALREADY IMPLEMENTED in RGE_Combat_Object.cpp
void RGE_Combat_Object::set_attribute(short param_1, float param_2) { RGE_Action_Object::set_attribute(param_1, param_2); } // TODO: STUB
void RGE_Combat_Object::set_attribute_amount(float param_1, uchar param_2, uchar param_3) { RGE_Action_Object::set_attribute_amount(param_1, param_2, param_3); } // TODO: STUB
int RGE_Combat_Object::heal(int param_1, int param_2) { return RGE_Action_Object::heal(param_1, param_2); } // TODO: STUB
uchar RGE_Combat_Object::heal(float param_1) { return RGE_Action_Object::heal(param_1); } // TODO: STUB
int RGE_Combat_Object::canRepair() { return RGE_Action_Object::canRepair(); } // TODO: STUB
void RGE_Combat_Object::notify_of_relation(long param_1, uchar param_2) { RGE_Action_Object::notify_of_relation(param_1, param_2); } // TODO: STUB
void RGE_Combat_Object::do_command(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { RGE_Action_Object::do_command(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Combat_Object::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { RGE_Action_Object::move_to(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Combat_Object::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { RGE_Action_Object::work(param_1, param_2, param_3, param_4); } // TODO: STUB
// stop() -- ALREADY IMPLEMENTED in RGE_Combat_Object.cpp
void RGE_Combat_Object::set_attack(RGE_Static_Object* param_1) { RGE_Action_Object::set_attack(param_1); } // TODO: STUB
void RGE_Combat_Object::play_command_sound() { RGE_Action_Object::play_command_sound(); } // TODO: STUB
void RGE_Combat_Object::play_move_sound() { RGE_Action_Object::play_move_sound(); } // TODO: STUB
void RGE_Combat_Object::new_angle(float param_1) { RGE_Action_Object::new_angle(param_1); } // TODO: STUB
RGE_Static_Object* RGE_Combat_Object::spawn_death_obj() { return RGE_Action_Object::spawn_death_obj(); } // TODO: STUB
RGE_Master_Static_Object* RGE_Combat_Object::get_command_master(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action_Object::get_command_master(param_1, param_2, param_3, param_4); } // TODO: STUB
uchar RGE_Combat_Object::is_moving() { return RGE_Action_Object::is_moving(); } // TODO: STUB
RGE_Static_Object* RGE_Combat_Object::get_target_obj() { return RGE_Action_Object::get_target_obj(); } // TODO: STUB
void RGE_Combat_Object::exit_obj() { RGE_Action_Object::exit_obj(); } // TODO: STUB
int RGE_Combat_Object::explore_terrain(RGE_Player* param_1, uchar param_2, int param_3) { return RGE_Action_Object::explore_terrain(param_1, param_2, param_3); } // TODO: STUB
void RGE_Combat_Object::unexplore_terrain(RGE_Player* param_1, uchar param_2, int param_3) { RGE_Action_Object::unexplore_terrain(param_1, param_2, param_3); } // TODO: STUB
LOSTBL* RGE_Combat_Object::get_los_table() { return RGE_Action_Object::get_los_table(); } // TODO: STUB
// inAttackRange(...) -- ALREADY IMPLEMENTED in RGE_Combat_Object.cpp
uchar RGE_Combat_Object::underAttack() { return RGE_Action_Object::underAttack(); } // TODO: STUB
void RGE_Combat_Object::setUnderAttack(uchar param_1) { RGE_Action_Object::setUnderAttack(param_1); } // TODO: STUB
// calc_attack_modifier(...) -- ALREADY IMPLEMENTED in RGE_Combat_Object.cpp
float RGE_Combat_Object::getSpeed() { return RGE_Action_Object::getSpeed(); } // TODO: STUB
float RGE_Combat_Object::getAngle() { return RGE_Action_Object::getAngle(); } // TODO: STUB
float RGE_Combat_Object::maximumSpeed() { return RGE_Action_Object::maximumSpeed(); } // TODO: STUB
// rateOfFire() -- ALREADY IMPLEMENTED in RGE_Combat_Object.cpp
// damageCapability(...) -- ALREADY IMPLEMENTED in RGE_Combat_Object.cpp
// weaponRange() -- ALREADY IMPLEMENTED in RGE_Combat_Object.cpp
// minimumWeaponRange() -- ALREADY IMPLEMENTED in RGE_Combat_Object.cpp
int RGE_Combat_Object::passableTile(float param_1, float param_2, int param_3) { return RGE_Action_Object::passableTile(param_1, param_2, param_3); } // TODO: STUB
uchar RGE_Combat_Object::facetToNextWaypoint() { return RGE_Action_Object::facetToNextWaypoint(); } // TODO: STUB
// currentTarget*() -- ALREADY IMPLEMENTED in RGE_Combat_Object.cpp
void RGE_Combat_Object::setWaitingToMove(uchar param_1) { RGE_Action_Object::setWaitingToMove(param_1); } // TODO: STUB
uchar RGE_Combat_Object::waitingToMove() { return RGE_Action_Object::waitingToMove(); } // TODO: STUB
uchar RGE_Combat_Object::actionState() { return RGE_Action_Object::actionState(); } // TODO: STUB
uchar RGE_Combat_Object::keepGatheringWhenObjectIsOut(int param_1) { return RGE_Action_Object::keepGatheringWhenObjectIsOut(param_1); } // TODO: STUB
uchar RGE_Combat_Object::produceWhenKilledBy(int param_1) { return RGE_Action_Object::produceWhenKilledBy(param_1); } // TODO: STUB
uchar RGE_Combat_Object::useSameZoneDropsite() { return RGE_Action_Object::useSameZoneDropsite(); } // TODO: STUB
void RGE_Combat_Object::logDebug(const char* param_1, ...) {
    va_list args;
    va_start(args, param_1);
    forward_log_debug_to_static(this, param_1, args);
    va_end(args);
} // TODO: STUB
// attack(...) -- ALREADY IMPLEMENTED in RGE_Combat_Object.cpp
int RGE_Combat_Object::hunt(int param_1, int param_2) { return RGE_Action_Object::hunt(param_1, param_2); } // TODO: STUB
int RGE_Combat_Object::convert(int param_1, int param_2) { return RGE_Action_Object::convert(param_1, param_2); } // TODO: STUB
int RGE_Combat_Object::repair(int param_1, int param_2) { return RGE_Action_Object::repair(param_1, param_2); } // TODO: STUB
int RGE_Combat_Object::build(int param_1, int param_2) { return RGE_Action_Object::build(param_1, param_2); } // TODO: STUB
int RGE_Combat_Object::trade(int param_1, int param_2) { return RGE_Action_Object::trade(param_1, param_2); } // TODO: STUB
// stopAction() -- ALREADY IMPLEMENTED in RGE_Combat_Object.cpp
// pause() -- ALREADY IMPLEMENTED in RGE_Combat_Object.cpp
int RGE_Combat_Object::canPath(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6) { return RGE_Action_Object::canPath(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
int RGE_Combat_Object::canPath(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7) { return RGE_Action_Object::canPath(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
int RGE_Combat_Object::canBidirectionPath(int param_1, int param_2, float param_3, float* param_4, int param_5, int param_6, int param_7) { return RGE_Action_Object::canBidirectionPath(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
int RGE_Combat_Object::canPathWithObstructions(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6, ManagedArray<int>* param_7) { return RGE_Action_Object::canPathWithObstructions(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
int RGE_Combat_Object::canPathWithAdditionalPassability(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7, int param_8, int param_9) { return RGE_Action_Object::canPathWithAdditionalPassability(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); } // TODO: STUB
int RGE_Combat_Object::findFirstTerrainAlongExceptionPath(int param_1, float* param_2, float* param_3) { return RGE_Action_Object::findFirstTerrainAlongExceptionPath(param_1, param_2, param_3); } // TODO: STUB
int RGE_Combat_Object::canLinePath(int param_1, int param_2, int param_3, int param_4, float param_5, int param_6) { return RGE_Action_Object::canLinePath(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
int RGE_Combat_Object::canLinePath(XYPoint* param_1, XYPoint* param_2, float param_3, XYPoint* param_4, int param_5) { return RGE_Action_Object::canLinePath(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
int RGE_Combat_Object::firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6) { return RGE_Action_Object::firstTileAlongLine(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
XYZBYTEPoint* RGE_Combat_Object::userDefinedWaypoint(int param_1) { return RGE_Action_Object::userDefinedWaypoint(param_1); } // TODO: STUB
int RGE_Combat_Object::addUserDefinedWaypoint(XYZBYTEPoint* param_1, int param_2) { return RGE_Action_Object::addUserDefinedWaypoint(param_1, param_2); } // TODO: STUB
void RGE_Combat_Object::removeAllUserDefinedWaypoints(int param_1) { RGE_Action_Object::removeAllUserDefinedWaypoints(param_1); } // TODO: STUB
void RGE_Combat_Object::removeUserDefinedWaypoint(int param_1) { RGE_Action_Object::removeUserDefinedWaypoint(param_1); } // TODO: STUB
int RGE_Combat_Object::numberUserDefinedWaypoints() { return RGE_Action_Object::numberUserDefinedWaypoints(); } // TODO: STUB
Path* RGE_Combat_Object::findAvoidancePath(XYZPoint* param_1, float param_2, int param_3) { return RGE_Action_Object::findAvoidancePath(param_1, param_2, param_3); } // TODO: STUB
long RGE_Combat_Object::get_action_checksum() { return RGE_Action_Object::get_action_checksum(); } // TODO: STUB
long RGE_Combat_Object::get_waypoint_checksum() { return RGE_Action_Object::get_waypoint_checksum(); } // TODO: STUB
// setup(int, RGE_Game_World*) -- ALREADY IMPLEMENTED in RGE_Combat_Object.cpp
RGE_Object_List* RGE_Combat_Object::create_object_list() { return RGE_Action_Object::create_object_list(); } // TODO: STUB
RGE_Active_Sprite_List* RGE_Combat_Object::create_sprite_list() { return RGE_Action_Object::create_sprite_list(); } // TODO: STUB
int RGE_Combat_Object::setup(RGE_Master_Animated_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) { return RGE_Action_Object::setup(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
void RGE_Combat_Object::stop_moving() { RGE_Action_Object::stop_moving(); } // TODO: STUB
uchar RGE_Combat_Object::turn_towards(RGE_Static_Object* param_1, float param_2, float param_3) { return RGE_Action_Object::turn_towards(param_1, param_2, param_3); } // TODO: STUB
void RGE_Combat_Object::work2(RGE_Static_Object* param_1, float param_2, float param_3, float param_4, uchar param_5) { RGE_Action_Object::work2(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
void RGE_Combat_Object::set_task(short param_1) { RGE_Action_Object::set_task(param_1); } // TODO: STUB

// --- Different signature from parent (vt[48] set_being_worked_on) ---
// Combat has (RGE_Action_Object*, short, uchar) but Action parent has (short, uchar) - different sig
void RGE_Combat_Object::set_being_worked_on(RGE_Action_Object* param_1, short param_2, uchar param_3) { RGE_Action_Object::set_being_worked_on(param_1, param_2, param_3); } // TODO: STUB


// =====================================================================
// RGE_Missile_Object  (parent: RGE_Combat_Object)
// =====================================================================

// --- Forwarding stubs: same signature as RGE_Combat_Object ---

void RGE_Missile_Object::recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) { RGE_Combat_Object::recycle_in_to_game(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
void RGE_Missile_Object::recycle_out_of_game() { RGE_Combat_Object::recycle_out_of_game(); } // TODO: STUB
void RGE_Missile_Object::draw_front_frame(TDrawArea* param_1, short param_2, short param_3) { RGE_Combat_Object::draw_front_frame(param_1, param_2, param_3); } // TODO: STUB
void RGE_Missile_Object::draw_back_frame(TDrawArea* param_1, short param_2, short param_3) { RGE_Combat_Object::draw_back_frame(param_1, param_2, param_3); } // TODO: STUB
void RGE_Missile_Object::draw_frame(TDrawArea* param_1, short param_2, short param_3) { RGE_Combat_Object::draw_frame(param_1, param_2, param_3); } // TODO: STUB

void RGE_Missile_Object::check_damage_sprites() { RGE_Combat_Object::check_damage_sprites(); } // TODO: STUB
float RGE_Missile_Object::teleport(float param_1, float param_2, float param_3) { return RGE_Combat_Object::teleport(param_1, param_2, param_3); } // TODO: STUB
void RGE_Missile_Object::new_sprite(RGE_Sprite* param_1) { RGE_Combat_Object::new_sprite(param_1); } // TODO: STUB
void RGE_Missile_Object::add_overlay_sprite(RGE_Sprite* param_1, uchar param_2) { RGE_Combat_Object::add_overlay_sprite(param_1, param_2); } // TODO: STUB
void RGE_Missile_Object::remove_overlay_sprite(RGE_Sprite* param_1) { RGE_Combat_Object::remove_overlay_sprite(param_1); } // TODO: STUB
void RGE_Missile_Object::change_ownership(RGE_Player* param_1) { RGE_Combat_Object::change_ownership(param_1); } // TODO: STUB
void RGE_Missile_Object::modify(float param_1, uchar param_2) { RGE_Combat_Object::modify(param_1, param_2); } // TODO: STUB
void RGE_Missile_Object::modify_delta(float param_1, uchar param_2) { RGE_Combat_Object::modify_delta(param_1, param_2); } // TODO: STUB
void RGE_Missile_Object::modify_percent(float param_1, uchar param_2) { RGE_Combat_Object::modify_percent(param_1, param_2); } // TODO: STUB
void RGE_Missile_Object::transform(RGE_Master_Static_Object* param_1) { RGE_Combat_Object::transform(param_1); } // TODO: STUB
void RGE_Missile_Object::copy_obj(RGE_Master_Static_Object* param_1) { RGE_Combat_Object::copy_obj(param_1); } // TODO: STUB
void RGE_Missile_Object::set_object_state(uchar param_1) { RGE_Combat_Object::set_object_state(param_1); } // TODO: STUB
void RGE_Missile_Object::remove_visible_resource() { RGE_Combat_Object::remove_visible_resource(); } // TODO: STUB
void RGE_Missile_Object::create_doppleganger_when_dying() { RGE_Combat_Object::create_doppleganger_when_dying(); } // TODO: STUB
void RGE_Missile_Object::destroy_obj() { RGE_Combat_Object::destroy_obj(); } // TODO: STUB
void RGE_Missile_Object::die_die_die() { RGE_Combat_Object::die_die_die(); } // TODO: STUB
void RGE_Missile_Object::damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) { RGE_Combat_Object::damage(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
float RGE_Missile_Object::calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) { return RGE_Combat_Object::calculateDamage(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
void RGE_Missile_Object::rotate(long param_1) { RGE_Combat_Object::rotate(param_1); } // TODO: STUB
uchar RGE_Missile_Object::can_attack() { return RGE_Combat_Object::can_attack(); } // TODO: STUB
void RGE_Missile_Object::set_attribute(short param_1, float param_2) { RGE_Combat_Object::set_attribute(param_1, param_2); } // TODO: STUB
void RGE_Missile_Object::set_attribute_amount(float param_1, uchar param_2, uchar param_3) { RGE_Combat_Object::set_attribute_amount(param_1, param_2, param_3); } // TODO: STUB
int RGE_Missile_Object::heal(int param_1, int param_2) { return RGE_Combat_Object::heal(param_1, param_2); } // TODO: STUB
uchar RGE_Missile_Object::heal(float param_1) { return RGE_Combat_Object::heal(param_1); } // TODO: STUB
int RGE_Missile_Object::canRepair() { return RGE_Combat_Object::canRepair(); } // TODO: STUB
void RGE_Missile_Object::notify_of_relation(long param_1, uchar param_2) { RGE_Combat_Object::notify_of_relation(param_1, param_2); } // TODO: STUB
void RGE_Missile_Object::do_command(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { RGE_Combat_Object::do_command(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Missile_Object::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { RGE_Combat_Object::move_to(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Missile_Object::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { RGE_Combat_Object::work(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Missile_Object::stop() { RGE_Combat_Object::stop(); } // TODO: STUB
void RGE_Missile_Object::set_attack(RGE_Static_Object* param_1) { RGE_Combat_Object::set_attack(param_1); } // TODO: STUB
void RGE_Missile_Object::play_command_sound() { RGE_Combat_Object::play_command_sound(); } // TODO: STUB
void RGE_Missile_Object::play_move_sound() { RGE_Combat_Object::play_move_sound(); } // TODO: STUB
void RGE_Missile_Object::new_angle(float param_1) { RGE_Combat_Object::new_angle(param_1); } // TODO: STUB
RGE_Static_Object* RGE_Missile_Object::spawn_death_obj() { return RGE_Combat_Object::spawn_death_obj(); } // TODO: STUB
RGE_Master_Static_Object* RGE_Missile_Object::get_command_master(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Combat_Object::get_command_master(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Missile_Object::set_being_worked_on(RGE_Action_Object* param_1, short param_2, uchar param_3) { RGE_Combat_Object::set_being_worked_on(param_1, param_2, param_3); } // TODO: STUB
void RGE_Missile_Object::release_being_worked_on(RGE_Static_Object* param_1) { RGE_Combat_Object::release_being_worked_on(param_1); } // TODO: STUB
uchar RGE_Missile_Object::is_moving() { return RGE_Combat_Object::is_moving(); } // TODO: STUB
RGE_Static_Object* RGE_Missile_Object::get_target_obj() { return RGE_Combat_Object::get_target_obj(); } // TODO: STUB
void RGE_Missile_Object::enter_obj(RGE_Static_Object* param_1) { RGE_Combat_Object::enter_obj(param_1); } // TODO: STUB
void RGE_Missile_Object::exit_obj() { RGE_Combat_Object::exit_obj(); } // TODO: STUB
int RGE_Missile_Object::explore_terrain(RGE_Player* param_1, uchar param_2, int param_3) { return RGE_Combat_Object::explore_terrain(param_1, param_2, param_3); } // TODO: STUB
void RGE_Missile_Object::unexplore_terrain(RGE_Player* param_1, uchar param_2, int param_3) { RGE_Combat_Object::unexplore_terrain(param_1, param_2, param_3); } // TODO: STUB
LOSTBL* RGE_Missile_Object::get_los_table() { return RGE_Combat_Object::get_los_table(); } // TODO: STUB
int RGE_Missile_Object::inAttackRange(RGE_Static_Object* param_1) { return RGE_Combat_Object::inAttackRange(param_1); } // TODO: STUB
uchar RGE_Missile_Object::underAttack() { return RGE_Combat_Object::underAttack(); } // TODO: STUB
void RGE_Missile_Object::setUnderAttack(uchar param_1) { RGE_Combat_Object::setUnderAttack(param_1); } // TODO: STUB
float RGE_Missile_Object::calc_attack_modifier(RGE_Static_Object* param_1) { return RGE_Combat_Object::calc_attack_modifier(param_1); } // TODO: STUB
float RGE_Missile_Object::getSpeed() { return RGE_Combat_Object::getSpeed(); } // TODO: STUB
float RGE_Missile_Object::getAngle() { return RGE_Combat_Object::getAngle(); } // TODO: STUB
float RGE_Missile_Object::maximumSpeed() { return RGE_Combat_Object::maximumSpeed(); } // TODO: STUB
float RGE_Missile_Object::rateOfFire() { return RGE_Combat_Object::rateOfFire(); } // TODO: STUB
float RGE_Missile_Object::damageCapability(RGE_Static_Object* param_1) { return RGE_Combat_Object::damageCapability(param_1); } // TODO: STUB
float RGE_Missile_Object::damageCapability() { return RGE_Combat_Object::damageCapability(); } // TODO: STUB
float RGE_Missile_Object::weaponRange() { return RGE_Combat_Object::weaponRange(); } // TODO: STUB
float RGE_Missile_Object::minimumWeaponRange() { return RGE_Combat_Object::minimumWeaponRange(); } // TODO: STUB
int RGE_Missile_Object::passableTile(float param_1, float param_2, int param_3) { return RGE_Combat_Object::passableTile(param_1, param_2, param_3); } // TODO: STUB
uchar RGE_Missile_Object::facetToNextWaypoint() { return RGE_Combat_Object::facetToNextWaypoint(); } // TODO: STUB
int RGE_Missile_Object::currentTargetID() { return RGE_Combat_Object::currentTargetID(); } // TODO: STUB
float RGE_Missile_Object::currentTargetX() { return RGE_Combat_Object::currentTargetX(); } // TODO: STUB
float RGE_Missile_Object::currentTargetY() { return RGE_Combat_Object::currentTargetY(); } // TODO: STUB
float RGE_Missile_Object::currentTargetZ() { return RGE_Combat_Object::currentTargetZ(); } // TODO: STUB
void RGE_Missile_Object::setWaitingToMove(uchar param_1) { RGE_Combat_Object::setWaitingToMove(param_1); } // TODO: STUB
uchar RGE_Missile_Object::waitingToMove() { return RGE_Combat_Object::waitingToMove(); } // TODO: STUB
uchar RGE_Missile_Object::actionState() { return RGE_Combat_Object::actionState(); } // TODO: STUB
uchar RGE_Missile_Object::keepGatheringWhenObjectIsOut(int param_1) { return RGE_Combat_Object::keepGatheringWhenObjectIsOut(param_1); } // TODO: STUB
uchar RGE_Missile_Object::produceWhenKilledBy(int param_1) { return RGE_Combat_Object::produceWhenKilledBy(param_1); } // TODO: STUB
uchar RGE_Missile_Object::useSameZoneDropsite() { return RGE_Combat_Object::useSameZoneDropsite(); } // TODO: STUB
void RGE_Missile_Object::logDebug(const char* param_1, ...) {
    va_list args;
    va_start(args, param_1);
    forward_log_debug_to_static(this, param_1, args);
    va_end(args);
} // TODO: STUB
void RGE_Missile_Object::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) { RGE_Combat_Object::notify(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
int RGE_Missile_Object::attack(float param_1, float param_2, float param_3, int param_4) { return RGE_Combat_Object::attack(param_1, param_2, param_3, param_4); } // TODO: STUB
int RGE_Missile_Object::attack(int param_1, int param_2) { return RGE_Combat_Object::attack(param_1, param_2); } // TODO: STUB
int RGE_Missile_Object::moveTo(float param_1, float param_2, float param_3, float param_4, int param_5) { return RGE_Combat_Object::moveTo(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
int RGE_Missile_Object::moveTo(int param_1, float param_2, int param_3) { return RGE_Combat_Object::moveTo(param_1, param_2, param_3); } // TODO: STUB
int RGE_Missile_Object::moveTo(int param_1, int param_2) { return RGE_Combat_Object::moveTo(param_1, param_2); } // TODO: STUB
int RGE_Missile_Object::moveAwayFrom(int param_1, int param_2) { return RGE_Combat_Object::moveAwayFrom(param_1, param_2); } // TODO: STUB
int RGE_Missile_Object::hunt(int param_1, int param_2) { return RGE_Combat_Object::hunt(param_1, param_2); } // TODO: STUB
int RGE_Missile_Object::gather(int param_1, int param_2) { return RGE_Combat_Object::gather(param_1, param_2); } // TODO: STUB
int RGE_Missile_Object::convert(int param_1, int param_2) { return RGE_Combat_Object::convert(param_1, param_2); } // TODO: STUB
int RGE_Missile_Object::repair(int param_1, int param_2) { return RGE_Combat_Object::repair(param_1, param_2); } // TODO: STUB
int RGE_Missile_Object::build(int param_1, int param_2) { return RGE_Combat_Object::build(param_1, param_2); } // TODO: STUB
int RGE_Missile_Object::trade(int param_1, int param_2) { return RGE_Combat_Object::trade(param_1, param_2); } // TODO: STUB
int RGE_Missile_Object::explore(int param_1, int param_2, int param_3) { return RGE_Combat_Object::explore(param_1, param_2, param_3); } // TODO: STUB
int RGE_Missile_Object::enter(int param_1, int param_2) { return RGE_Combat_Object::enter(param_1, param_2); } // TODO: STUB
int RGE_Missile_Object::unload(int param_1, float param_2, float param_3, float param_4) { return RGE_Combat_Object::unload(param_1, param_2, param_3, param_4); } // TODO: STUB
int RGE_Missile_Object::transport(float param_1, float param_2, float param_3, int param_4) { return RGE_Combat_Object::transport(param_1, param_2, param_3, param_4); } // TODO: STUB
int RGE_Missile_Object::stopAction() { return RGE_Combat_Object::stopAction(); } // TODO: STUB
int RGE_Missile_Object::pause() { return RGE_Combat_Object::pause(); } // TODO: STUB
int RGE_Missile_Object::canPath(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6) { return RGE_Combat_Object::canPath(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
int RGE_Missile_Object::canPath(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7) { return RGE_Combat_Object::canPath(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
int RGE_Missile_Object::canBidirectionPath(int param_1, int param_2, float param_3, float* param_4, int param_5, int param_6, int param_7) { return RGE_Combat_Object::canBidirectionPath(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
int RGE_Missile_Object::canPathWithObstructions(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6, ManagedArray<int>* param_7) { return RGE_Combat_Object::canPathWithObstructions(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
int RGE_Missile_Object::canPathWithAdditionalPassability(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7, int param_8, int param_9) { return RGE_Combat_Object::canPathWithAdditionalPassability(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); } // TODO: STUB
int RGE_Missile_Object::findFirstTerrainAlongExceptionPath(int param_1, float* param_2, float* param_3) { return RGE_Combat_Object::findFirstTerrainAlongExceptionPath(param_1, param_2, param_3); } // TODO: STUB
int RGE_Missile_Object::canLinePath(int param_1, int param_2, int param_3, int param_4, float param_5, int param_6) { return RGE_Combat_Object::canLinePath(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
int RGE_Missile_Object::canLinePath(XYPoint* param_1, XYPoint* param_2, float param_3, XYPoint* param_4, int param_5) { return RGE_Combat_Object::canLinePath(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
int RGE_Missile_Object::firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6) { return RGE_Combat_Object::firstTileAlongLine(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
XYZBYTEPoint* RGE_Missile_Object::userDefinedWaypoint(int param_1) { return RGE_Combat_Object::userDefinedWaypoint(param_1); } // TODO: STUB
int RGE_Missile_Object::addUserDefinedWaypoint(XYZBYTEPoint* param_1, int param_2) { return RGE_Combat_Object::addUserDefinedWaypoint(param_1, param_2); } // TODO: STUB
void RGE_Missile_Object::removeAllUserDefinedWaypoints(int param_1) { RGE_Combat_Object::removeAllUserDefinedWaypoints(param_1); } // TODO: STUB
void RGE_Missile_Object::removeUserDefinedWaypoint(int param_1) { RGE_Combat_Object::removeUserDefinedWaypoint(param_1); } // TODO: STUB
int RGE_Missile_Object::numberUserDefinedWaypoints() { return RGE_Combat_Object::numberUserDefinedWaypoints(); } // TODO: STUB
Path* RGE_Missile_Object::findAvoidancePath(XYZPoint* param_1, float param_2, int param_3) { return RGE_Combat_Object::findAvoidancePath(param_1, param_2, param_3); } // TODO: STUB
long RGE_Missile_Object::get_action_checksum() { return RGE_Combat_Object::get_action_checksum(); } // TODO: STUB
long RGE_Missile_Object::get_waypoint_checksum() { return RGE_Combat_Object::get_waypoint_checksum(); } // TODO: STUB
// setup(int, RGE_Game_World*) -- ALREADY IMPLEMENTED in RGE_Missile_Object.cpp
RGE_Object_List* RGE_Missile_Object::create_object_list() { return RGE_Combat_Object::create_object_list(); } // TODO: STUB
RGE_Active_Sprite_List* RGE_Missile_Object::create_sprite_list() { return RGE_Combat_Object::create_sprite_list(); } // TODO: STUB
void RGE_Missile_Object::stop_moving() { RGE_Combat_Object::stop_moving(); } // TODO: STUB
uchar RGE_Missile_Object::turn_towards(RGE_Static_Object* param_1, float param_2, float param_3) { return RGE_Combat_Object::turn_towards(param_1, param_2, param_3); } // TODO: STUB
void RGE_Missile_Object::work2(RGE_Static_Object* param_1, float param_2, float param_3, float param_4, uchar param_5) { RGE_Combat_Object::work2(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
void RGE_Missile_Object::set_task(short param_1) { RGE_Combat_Object::set_task(param_1); } // TODO: STUB


// =====================================================================
// RGE_Doppleganger_Object  (parent: RGE_Animated_Object)
// =====================================================================

RGE_Doppleganger_Object::~RGE_Doppleganger_Object() {} // TODO: STUB

// --- Forwarding stubs: same signature as RGE_Animated_Object ---

void RGE_Doppleganger_Object::recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) { RGE_Animated_Object::recycle_in_to_game(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
void RGE_Doppleganger_Object::recycle_out_of_game() { RGE_Animated_Object::recycle_out_of_game(); } // TODO: STUB
void RGE_Doppleganger_Object::draw_front_frame(TDrawArea* param_1, short param_2, short param_3) { RGE_Animated_Object::draw_front_frame(param_1, param_2, param_3); } // TODO: STUB
void RGE_Doppleganger_Object::draw_back_frame(TDrawArea* param_1, short param_2, short param_3) { RGE_Animated_Object::draw_back_frame(param_1, param_2, param_3); } // TODO: STUB
void RGE_Doppleganger_Object::draw_frame(TDrawArea* param_1, short param_2, short param_3) { RGE_Animated_Object::draw_frame(param_1, param_2, param_3); } // TODO: STUB
void RGE_Doppleganger_Object::check_damage_sprites() { RGE_Animated_Object::check_damage_sprites(); } // TODO: STUB
float RGE_Doppleganger_Object::teleport(float param_1, float param_2, float param_3) { return RGE_Animated_Object::teleport(param_1, param_2, param_3); } // TODO: STUB
void RGE_Doppleganger_Object::new_sprite(RGE_Sprite* param_1) { RGE_Animated_Object::new_sprite(param_1); } // TODO: STUB
void RGE_Doppleganger_Object::add_overlay_sprite(RGE_Sprite* param_1, uchar param_2) { RGE_Animated_Object::add_overlay_sprite(param_1, param_2); } // TODO: STUB
void RGE_Doppleganger_Object::remove_overlay_sprite(RGE_Sprite* param_1) { RGE_Animated_Object::remove_overlay_sprite(param_1); } // TODO: STUB
void RGE_Doppleganger_Object::change_ownership(RGE_Player* param_1) { RGE_Animated_Object::change_ownership(param_1); } // TODO: STUB
void RGE_Doppleganger_Object::modify(float param_1, uchar param_2) { RGE_Animated_Object::modify(param_1, param_2); } // TODO: STUB
void RGE_Doppleganger_Object::modify_delta(float param_1, uchar param_2) { RGE_Animated_Object::modify_delta(param_1, param_2); } // TODO: STUB
void RGE_Doppleganger_Object::modify_percent(float param_1, uchar param_2) { RGE_Animated_Object::modify_percent(param_1, param_2); } // TODO: STUB
void RGE_Doppleganger_Object::transform(RGE_Master_Static_Object* param_1) { RGE_Animated_Object::transform(param_1); } // TODO: STUB
void RGE_Doppleganger_Object::copy_obj(RGE_Master_Static_Object* param_1) { RGE_Animated_Object::copy_obj(param_1); } // TODO: STUB
void RGE_Doppleganger_Object::set_object_state(uchar param_1) { RGE_Animated_Object::set_object_state(param_1); } // TODO: STUB
void RGE_Doppleganger_Object::remove_visible_resource() { RGE_Animated_Object::remove_visible_resource(); } // TODO: STUB
void RGE_Doppleganger_Object::create_doppleganger_when_dying() { RGE_Animated_Object::create_doppleganger_when_dying(); } // TODO: STUB
void RGE_Doppleganger_Object::destroy_obj() { RGE_Animated_Object::destroy_obj(); } // TODO: STUB
void RGE_Doppleganger_Object::die_die_die() { RGE_Animated_Object::die_die_die(); } // TODO: STUB
void RGE_Doppleganger_Object::damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) { RGE_Animated_Object::damage(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
float RGE_Doppleganger_Object::calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) { return RGE_Animated_Object::calculateDamage(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
void RGE_Doppleganger_Object::rotate(long param_1) { RGE_Animated_Object::rotate(param_1); } // TODO: STUB
uchar RGE_Doppleganger_Object::can_attack() { return RGE_Animated_Object::can_attack(); } // TODO: STUB
void RGE_Doppleganger_Object::set_attribute(short param_1, float param_2) { RGE_Animated_Object::set_attribute(param_1, param_2); } // TODO: STUB
void RGE_Doppleganger_Object::set_attribute_amount(float param_1, uchar param_2, uchar param_3) { RGE_Animated_Object::set_attribute_amount(param_1, param_2, param_3); } // TODO: STUB
int RGE_Doppleganger_Object::heal(int param_1, int param_2) { return RGE_Animated_Object::heal(param_1, param_2); } // TODO: STUB
uchar RGE_Doppleganger_Object::heal(float param_1) { return RGE_Animated_Object::heal(param_1); } // TODO: STUB
int RGE_Doppleganger_Object::canRepair() { return RGE_Animated_Object::canRepair(); } // TODO: STUB
void RGE_Doppleganger_Object::notify_of_relation(long param_1, uchar param_2) { RGE_Animated_Object::notify_of_relation(param_1, param_2); } // TODO: STUB
void RGE_Doppleganger_Object::do_command(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { RGE_Animated_Object::do_command(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Doppleganger_Object::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { RGE_Animated_Object::move_to(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Doppleganger_Object::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { RGE_Animated_Object::work(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Doppleganger_Object::stop() { RGE_Animated_Object::stop(); } // TODO: STUB
void RGE_Doppleganger_Object::set_attack(RGE_Static_Object* param_1) { RGE_Animated_Object::set_attack(param_1); } // TODO: STUB
void RGE_Doppleganger_Object::play_command_sound() { RGE_Animated_Object::play_command_sound(); } // TODO: STUB
void RGE_Doppleganger_Object::play_move_sound() { RGE_Animated_Object::play_move_sound(); } // TODO: STUB
void RGE_Doppleganger_Object::new_angle(float param_1) { RGE_Animated_Object::new_angle(param_1); } // TODO: STUB
RGE_Static_Object* RGE_Doppleganger_Object::spawn_death_obj() { return RGE_Animated_Object::spawn_death_obj(); } // TODO: STUB
RGE_Master_Static_Object* RGE_Doppleganger_Object::get_command_master(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Animated_Object::get_command_master(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Doppleganger_Object::set_being_worked_on(RGE_Action_Object* param_1, short param_2, uchar param_3) { RGE_Animated_Object::set_being_worked_on(param_1, param_2, param_3); } // TODO: STUB
void RGE_Doppleganger_Object::release_being_worked_on(RGE_Static_Object* param_1) { RGE_Animated_Object::release_being_worked_on(param_1); } // TODO: STUB
uchar RGE_Doppleganger_Object::is_moving() { return RGE_Animated_Object::is_moving(); } // TODO: STUB
RGE_Static_Object* RGE_Doppleganger_Object::get_target_obj() { return RGE_Animated_Object::get_target_obj(); } // TODO: STUB
void RGE_Doppleganger_Object::enter_obj(RGE_Static_Object* param_1) { RGE_Animated_Object::enter_obj(param_1); } // TODO: STUB
void RGE_Doppleganger_Object::exit_obj() { RGE_Animated_Object::exit_obj(); } // TODO: STUB
int RGE_Doppleganger_Object::explore_terrain(RGE_Player* param_1, uchar param_2, int param_3) { return RGE_Animated_Object::explore_terrain(param_1, param_2, param_3); } // TODO: STUB
void RGE_Doppleganger_Object::unexplore_terrain(RGE_Player* param_1, uchar param_2, int param_3) { RGE_Animated_Object::unexplore_terrain(param_1, param_2, param_3); } // TODO: STUB
LOSTBL* RGE_Doppleganger_Object::get_los_table() { return RGE_Animated_Object::get_los_table(); } // TODO: STUB
int RGE_Doppleganger_Object::inAttackRange(RGE_Static_Object* param_1) { return RGE_Animated_Object::inAttackRange(param_1); } // TODO: STUB
uchar RGE_Doppleganger_Object::underAttack() { return RGE_Animated_Object::underAttack(); } // TODO: STUB
void RGE_Doppleganger_Object::setUnderAttack(uchar param_1) { RGE_Animated_Object::setUnderAttack(param_1); } // TODO: STUB
float RGE_Doppleganger_Object::calc_attack_modifier(RGE_Static_Object* param_1) { return RGE_Animated_Object::calc_attack_modifier(param_1); } // TODO: STUB
float RGE_Doppleganger_Object::getSpeed() { return RGE_Animated_Object::getSpeed(); } // TODO: STUB
float RGE_Doppleganger_Object::getAngle() { return RGE_Animated_Object::getAngle(); } // TODO: STUB
float RGE_Doppleganger_Object::maximumSpeed() { return RGE_Animated_Object::maximumSpeed(); } // TODO: STUB
float RGE_Doppleganger_Object::rateOfFire() { return RGE_Animated_Object::rateOfFire(); } // TODO: STUB
float RGE_Doppleganger_Object::damageCapability(RGE_Static_Object* param_1) { return RGE_Animated_Object::damageCapability(param_1); } // TODO: STUB
float RGE_Doppleganger_Object::damageCapability() { return RGE_Animated_Object::damageCapability(); } // TODO: STUB
float RGE_Doppleganger_Object::weaponRange() { return RGE_Animated_Object::weaponRange(); } // TODO: STUB
float RGE_Doppleganger_Object::minimumWeaponRange() { return RGE_Animated_Object::minimumWeaponRange(); } // TODO: STUB
int RGE_Doppleganger_Object::passableTile(float param_1, float param_2, int param_3) { return RGE_Animated_Object::passableTile(param_1, param_2, param_3); } // TODO: STUB
uchar RGE_Doppleganger_Object::facetToNextWaypoint() { return RGE_Animated_Object::facetToNextWaypoint(); } // TODO: STUB
int RGE_Doppleganger_Object::currentTargetID() { return RGE_Animated_Object::currentTargetID(); } // TODO: STUB
float RGE_Doppleganger_Object::currentTargetX() { return RGE_Animated_Object::currentTargetX(); } // TODO: STUB
float RGE_Doppleganger_Object::currentTargetY() { return RGE_Animated_Object::currentTargetY(); } // TODO: STUB
float RGE_Doppleganger_Object::currentTargetZ() { return RGE_Animated_Object::currentTargetZ(); } // TODO: STUB
void RGE_Doppleganger_Object::setWaitingToMove(uchar param_1) { RGE_Animated_Object::setWaitingToMove(param_1); } // TODO: STUB
uchar RGE_Doppleganger_Object::waitingToMove() { return RGE_Animated_Object::waitingToMove(); } // TODO: STUB
uchar RGE_Doppleganger_Object::actionState() { return RGE_Animated_Object::actionState(); } // TODO: STUB
uchar RGE_Doppleganger_Object::keepGatheringWhenObjectIsOut(int param_1) { return RGE_Animated_Object::keepGatheringWhenObjectIsOut(param_1); } // TODO: STUB
uchar RGE_Doppleganger_Object::produceWhenKilledBy(int param_1) { return RGE_Animated_Object::produceWhenKilledBy(param_1); } // TODO: STUB
uchar RGE_Doppleganger_Object::useSameZoneDropsite() { return RGE_Animated_Object::useSameZoneDropsite(); } // TODO: STUB
void RGE_Doppleganger_Object::logDebug(const char* param_1, ...) {
    va_list args;
    va_start(args, param_1);
    forward_log_debug_to_static(this, param_1, args);
    va_end(args);
} // TODO: STUB
void RGE_Doppleganger_Object::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) { RGE_Animated_Object::notify(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
int RGE_Doppleganger_Object::attack(float param_1, float param_2, float param_3, int param_4) { return RGE_Animated_Object::attack(param_1, param_2, param_3, param_4); } // TODO: STUB
int RGE_Doppleganger_Object::attack(int param_1, int param_2) { return RGE_Animated_Object::attack(param_1, param_2); } // TODO: STUB
int RGE_Doppleganger_Object::moveTo(float param_1, float param_2, float param_3, float param_4, int param_5) { return RGE_Animated_Object::moveTo(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
int RGE_Doppleganger_Object::moveTo(int param_1, float param_2, int param_3) { return RGE_Animated_Object::moveTo(param_1, param_2, param_3); } // TODO: STUB
int RGE_Doppleganger_Object::moveTo(int param_1, int param_2) { return RGE_Animated_Object::moveTo(param_1, param_2); } // TODO: STUB
int RGE_Doppleganger_Object::moveAwayFrom(int param_1, int param_2) { return RGE_Animated_Object::moveAwayFrom(param_1, param_2); } // TODO: STUB
int RGE_Doppleganger_Object::hunt(int param_1, int param_2) { return RGE_Animated_Object::hunt(param_1, param_2); } // TODO: STUB
int RGE_Doppleganger_Object::gather(int param_1, int param_2) { return RGE_Animated_Object::gather(param_1, param_2); } // TODO: STUB
int RGE_Doppleganger_Object::convert(int param_1, int param_2) { return RGE_Animated_Object::convert(param_1, param_2); } // TODO: STUB
int RGE_Doppleganger_Object::repair(int param_1, int param_2) { return RGE_Animated_Object::repair(param_1, param_2); } // TODO: STUB
int RGE_Doppleganger_Object::build(int param_1, int param_2) { return RGE_Animated_Object::build(param_1, param_2); } // TODO: STUB
int RGE_Doppleganger_Object::trade(int param_1, int param_2) { return RGE_Animated_Object::trade(param_1, param_2); } // TODO: STUB
int RGE_Doppleganger_Object::explore(int param_1, int param_2, int param_3) { return RGE_Animated_Object::explore(param_1, param_2, param_3); } // TODO: STUB
int RGE_Doppleganger_Object::enter(int param_1, int param_2) { return RGE_Animated_Object::enter(param_1, param_2); } // TODO: STUB
int RGE_Doppleganger_Object::unload(int param_1, float param_2, float param_3, float param_4) { return RGE_Animated_Object::unload(param_1, param_2, param_3, param_4); } // TODO: STUB
int RGE_Doppleganger_Object::transport(float param_1, float param_2, float param_3, int param_4) { return RGE_Animated_Object::transport(param_1, param_2, param_3, param_4); } // TODO: STUB
int RGE_Doppleganger_Object::stopAction() { return RGE_Animated_Object::stopAction(); } // TODO: STUB
int RGE_Doppleganger_Object::pause() { return RGE_Animated_Object::pause(); } // TODO: STUB
int RGE_Doppleganger_Object::canPath(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6) { return RGE_Animated_Object::canPath(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
int RGE_Doppleganger_Object::canPath(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7) { return RGE_Animated_Object::canPath(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
int RGE_Doppleganger_Object::canBidirectionPath(int param_1, int param_2, float param_3, float* param_4, int param_5, int param_6, int param_7) { return RGE_Animated_Object::canBidirectionPath(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
int RGE_Doppleganger_Object::canPathWithObstructions(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6, ManagedArray<int>* param_7) { return RGE_Animated_Object::canPathWithObstructions(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
int RGE_Doppleganger_Object::canPathWithAdditionalPassability(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7, int param_8, int param_9) { return RGE_Animated_Object::canPathWithAdditionalPassability(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); } // TODO: STUB
int RGE_Doppleganger_Object::findFirstTerrainAlongExceptionPath(int param_1, float* param_2, float* param_3) { return RGE_Animated_Object::findFirstTerrainAlongExceptionPath(param_1, param_2, param_3); } // TODO: STUB
int RGE_Doppleganger_Object::canLinePath(int param_1, int param_2, int param_3, int param_4, float param_5, int param_6) { return RGE_Animated_Object::canLinePath(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
int RGE_Doppleganger_Object::canLinePath(XYPoint* param_1, XYPoint* param_2, float param_3, XYPoint* param_4, int param_5) { return RGE_Animated_Object::canLinePath(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
int RGE_Doppleganger_Object::firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6) { return RGE_Animated_Object::firstTileAlongLine(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
XYZBYTEPoint* RGE_Doppleganger_Object::userDefinedWaypoint(int param_1) { return RGE_Animated_Object::userDefinedWaypoint(param_1); } // TODO: STUB
int RGE_Doppleganger_Object::addUserDefinedWaypoint(XYZBYTEPoint* param_1, int param_2) { return RGE_Animated_Object::addUserDefinedWaypoint(param_1, param_2); } // TODO: STUB
void RGE_Doppleganger_Object::removeAllUserDefinedWaypoints(int param_1) { RGE_Animated_Object::removeAllUserDefinedWaypoints(param_1); } // TODO: STUB
void RGE_Doppleganger_Object::removeUserDefinedWaypoint(int param_1) { RGE_Animated_Object::removeUserDefinedWaypoint(param_1); } // TODO: STUB
int RGE_Doppleganger_Object::numberUserDefinedWaypoints() { return RGE_Animated_Object::numberUserDefinedWaypoints(); } // TODO: STUB
Path* RGE_Doppleganger_Object::findAvoidancePath(XYZPoint* param_1, float param_2, int param_3) { return RGE_Animated_Object::findAvoidancePath(param_1, param_2, param_3); } // TODO: STUB
long RGE_Doppleganger_Object::get_action_checksum() { return RGE_Animated_Object::get_action_checksum(); } // TODO: STUB
long RGE_Doppleganger_Object::get_waypoint_checksum() { return RGE_Animated_Object::get_waypoint_checksum(); } // TODO: STUB
// setup(int, RGE_Game_World*) -- ALREADY IMPLEMENTED in RGE_Doppleganger_Object.cpp
int RGE_Doppleganger_Object::setup(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) { return RGE_Animated_Object::setup(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
RGE_Object_List* RGE_Doppleganger_Object::create_object_list() { return RGE_Animated_Object::create_object_list(); } // TODO: STUB
RGE_Active_Sprite_List* RGE_Doppleganger_Object::create_sprite_list() { return RGE_Animated_Object::create_sprite_list(); } // TODO: STUB
int RGE_Doppleganger_Object::setup(RGE_Master_Animated_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) { return RGE_Animated_Object::setup(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB

// --- New virtuals in Doppleganger (slots 123-125, different from Moving's slots) ---
