#include "../include/TRIBE_Tree_Object.h"

#include "../include/TRIBE_Master_Tree_Object.h"

#include <cstdarg>
#include <cstdio>

TRIBE_Tree_Object::TRIBE_Tree_Object(TRIBE_Master_Tree_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6)
    : RGE_Static_Object((RGE_Master_Static_Object*)param_1, param_2, param_3, param_4, param_5, 0) {
    // Fully verified. Source of truth: t_tre_ob.cpp.decomp @ 0x004CCA60
    if (param_6 != 0) {
        this->RGE_Static_Object::setup((RGE_Master_Static_Object*)param_1, param_2, param_3, param_4, param_5);
    }
}

TRIBE_Tree_Object::TRIBE_Tree_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : RGE_Static_Object(param_1, param_2, 0) {
    // Fully verified. Source of truth: t_tre_ob.cpp.decomp @ 0x004CCB20
    if (param_3 != 0) {
        this->RGE_Static_Object::setup(param_1, param_2);
    }
}

TRIBE_Tree_Object::~TRIBE_Tree_Object() {}

void TRIBE_Tree_Object::recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) { RGE_Static_Object::recycle_in_to_game(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
void TRIBE_Tree_Object::recycle_out_of_game() { RGE_Static_Object::recycle_out_of_game(); } // TODO: STUB
void TRIBE_Tree_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4) { RGE_Static_Object::draw(param_1, param_2, param_3, param_4); } // TODO: STUB
void TRIBE_Tree_Object::shadow_draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4) { RGE_Static_Object::shadow_draw(param_1, param_2, param_3, param_4); } // TODO: STUB
void TRIBE_Tree_Object::normal_draw(TDrawArea* param_1, short param_2, short param_3) { RGE_Static_Object::normal_draw(param_1, param_2, param_3); } // TODO: STUB
void TRIBE_Tree_Object::draw_front_frame(TDrawArea* param_1, short param_2, short param_3) { RGE_Static_Object::draw_front_frame(param_1, param_2, param_3); } // TODO: STUB
void TRIBE_Tree_Object::draw_back_frame(TDrawArea* param_1, short param_2, short param_3) { RGE_Static_Object::draw_back_frame(param_1, param_2, param_3); } // TODO: STUB
void TRIBE_Tree_Object::draw_frame(TDrawArea* param_1, short param_2, short param_3) { RGE_Static_Object::draw_frame(param_1, param_2, param_3); } // TODO: STUB
uchar TRIBE_Tree_Object::update() { return RGE_Static_Object::update(); } // TODO: STUB
void TRIBE_Tree_Object::check_damage_sprites() { RGE_Static_Object::check_damage_sprites(); } // TODO: STUB
void TRIBE_Tree_Object::rehook() { RGE_Static_Object::rehook(); } // TODO: STUB
void TRIBE_Tree_Object::save(int param_1) { RGE_Static_Object::save(param_1); } // TODO: STUB
float TRIBE_Tree_Object::teleport(float param_1, float param_2, float param_3) { return RGE_Static_Object::teleport(param_1, param_2, param_3); } // TODO: STUB
void TRIBE_Tree_Object::new_sprite(RGE_Sprite* param_1) { RGE_Static_Object::new_sprite(param_1); } // TODO: STUB
void TRIBE_Tree_Object::add_overlay_sprite(RGE_Sprite* param_1, uchar param_2) { RGE_Static_Object::add_overlay_sprite(param_1, param_2); } // TODO: STUB
void TRIBE_Tree_Object::remove_overlay_sprite(RGE_Sprite* param_1) { RGE_Static_Object::remove_overlay_sprite(param_1); } // TODO: STUB
void TRIBE_Tree_Object::change_ownership(RGE_Player* param_1) { RGE_Static_Object::change_ownership(param_1); } // TODO: STUB
void TRIBE_Tree_Object::modify(float param_1, uchar param_2) { RGE_Static_Object::modify(param_1, param_2); } // TODO: STUB
void TRIBE_Tree_Object::modify_delta(float param_1, uchar param_2) { RGE_Static_Object::modify_delta(param_1, param_2); } // TODO: STUB
void TRIBE_Tree_Object::modify_percent(float param_1, uchar param_2) { RGE_Static_Object::modify_percent(param_1, param_2); } // TODO: STUB
void TRIBE_Tree_Object::transform(RGE_Master_Static_Object* param_1) { RGE_Static_Object::transform(param_1); } // TODO: STUB
void TRIBE_Tree_Object::copy_obj(RGE_Master_Static_Object* param_1) { RGE_Static_Object::copy_obj(param_1); } // TODO: STUB
void TRIBE_Tree_Object::remove_visible_resource() { RGE_Static_Object::remove_visible_resource(); } // TODO: STUB
void TRIBE_Tree_Object::create_doppleganger_when_dying() { RGE_Static_Object::create_doppleganger_when_dying(); } // TODO: STUB
void TRIBE_Tree_Object::destroy_obj() { RGE_Static_Object::destroy_obj(); } // TODO: STUB
void TRIBE_Tree_Object::die_die_die() { RGE_Static_Object::die_die_die(); } // TODO: STUB
void TRIBE_Tree_Object::damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) { RGE_Static_Object::damage(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
float TRIBE_Tree_Object::calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) { return RGE_Static_Object::calculateDamage(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
void TRIBE_Tree_Object::rotate(long param_1) { RGE_Static_Object::rotate(param_1); } // TODO: STUB
uchar TRIBE_Tree_Object::can_attack() { return RGE_Static_Object::can_attack(); } // TODO: STUB
void TRIBE_Tree_Object::set_attribute(short param_1, float param_2) { RGE_Static_Object::set_attribute(param_1, param_2); } // TODO: STUB
void TRIBE_Tree_Object::set_attribute_amount(float param_1, uchar param_2, uchar param_3) { RGE_Static_Object::set_attribute_amount(param_1, param_2, param_3); } // TODO: STUB
int TRIBE_Tree_Object::heal(int param_1, int param_2) { return RGE_Static_Object::heal(param_1, param_2); } // TODO: STUB
uchar TRIBE_Tree_Object::heal(float param_1) { return RGE_Static_Object::heal(param_1); } // TODO: STUB
int TRIBE_Tree_Object::canRepair() { return RGE_Static_Object::canRepair(); } // TODO: STUB
void TRIBE_Tree_Object::notify_of_relation(long param_1, uchar param_2) { RGE_Static_Object::notify_of_relation(param_1, param_2); } // TODO: STUB
void TRIBE_Tree_Object::do_command(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { RGE_Static_Object::do_command(param_1, param_2, param_3, param_4); } // TODO: STUB
void TRIBE_Tree_Object::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { RGE_Static_Object::move_to(param_1, param_2, param_3, param_4); } // TODO: STUB
void TRIBE_Tree_Object::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { RGE_Static_Object::work(param_1, param_2, param_3, param_4); } // TODO: STUB
void TRIBE_Tree_Object::stop() { RGE_Static_Object::stop(); } // TODO: STUB
void TRIBE_Tree_Object::set_attack(RGE_Static_Object* param_1) { RGE_Static_Object::set_attack(param_1); } // TODO: STUB
void TRIBE_Tree_Object::play_command_sound() { RGE_Static_Object::play_command_sound(); } // TODO: STUB
void TRIBE_Tree_Object::play_move_sound() { RGE_Static_Object::play_move_sound(); } // TODO: STUB
void TRIBE_Tree_Object::new_angle(float param_1) { RGE_Static_Object::new_angle(param_1); } // TODO: STUB
RGE_Static_Object* TRIBE_Tree_Object::spawn_death_obj() { return RGE_Static_Object::spawn_death_obj(); } // TODO: STUB
RGE_Master_Static_Object* TRIBE_Tree_Object::get_command_master(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Static_Object::get_command_master(param_1, param_2, param_3, param_4); } // TODO: STUB
void TRIBE_Tree_Object::set_being_worked_on(RGE_Action_Object* param_1, short param_2, uchar param_3) { RGE_Static_Object::set_being_worked_on(param_1, param_2, param_3); } // TODO: STUB
void TRIBE_Tree_Object::release_being_worked_on(RGE_Static_Object* param_1) { RGE_Static_Object::release_being_worked_on(param_1); } // TODO: STUB
uchar TRIBE_Tree_Object::is_moving() { return RGE_Static_Object::is_moving(); } // TODO: STUB
RGE_Static_Object* TRIBE_Tree_Object::get_target_obj() { return RGE_Static_Object::get_target_obj(); } // TODO: STUB
void TRIBE_Tree_Object::enter_obj(RGE_Static_Object* param_1) { RGE_Static_Object::enter_obj(param_1); } // TODO: STUB
void TRIBE_Tree_Object::exit_obj() { RGE_Static_Object::exit_obj(); } // TODO: STUB
int TRIBE_Tree_Object::explore_terrain(RGE_Player* param_1, uchar param_2, int param_3) { return RGE_Static_Object::explore_terrain(param_1, param_2, param_3); } // TODO: STUB
void TRIBE_Tree_Object::unexplore_terrain(RGE_Player* param_1, uchar param_2, int param_3) { RGE_Static_Object::unexplore_terrain(param_1, param_2, param_3); } // TODO: STUB
LOSTBL* TRIBE_Tree_Object::get_los_table() { return RGE_Static_Object::get_los_table(); } // TODO: STUB
int TRIBE_Tree_Object::inAttackRange(RGE_Static_Object* param_1) { return RGE_Static_Object::inAttackRange(param_1); } // TODO: STUB
uchar TRIBE_Tree_Object::underAttack() { return RGE_Static_Object::underAttack(); } // TODO: STUB
void TRIBE_Tree_Object::setUnderAttack(uchar param_1) { RGE_Static_Object::setUnderAttack(param_1); } // TODO: STUB
float TRIBE_Tree_Object::calc_attack_modifier(RGE_Static_Object* param_1) { return RGE_Static_Object::calc_attack_modifier(param_1); } // TODO: STUB
float TRIBE_Tree_Object::getSpeed() { return RGE_Static_Object::getSpeed(); } // TODO: STUB
float TRIBE_Tree_Object::getAngle() { return RGE_Static_Object::getAngle(); } // TODO: STUB
float TRIBE_Tree_Object::maximumSpeed() { return RGE_Static_Object::maximumSpeed(); } // TODO: STUB
float TRIBE_Tree_Object::rateOfFire() { return RGE_Static_Object::rateOfFire(); } // TODO: STUB
float TRIBE_Tree_Object::damageCapability(RGE_Static_Object* param_1) { return RGE_Static_Object::damageCapability(param_1); } // TODO: STUB
float TRIBE_Tree_Object::damageCapability() { return RGE_Static_Object::damageCapability(); } // TODO: STUB
float TRIBE_Tree_Object::weaponRange() { return RGE_Static_Object::weaponRange(); } // TODO: STUB
float TRIBE_Tree_Object::minimumWeaponRange() { return RGE_Static_Object::minimumWeaponRange(); } // TODO: STUB
int TRIBE_Tree_Object::passableTile(float param_1, float param_2, int param_3) { return RGE_Static_Object::passableTile(param_1, param_2, param_3); } // TODO: STUB
uchar TRIBE_Tree_Object::facetToNextWaypoint() { return RGE_Static_Object::facetToNextWaypoint(); } // TODO: STUB
int TRIBE_Tree_Object::currentTargetID() { return RGE_Static_Object::currentTargetID(); } // TODO: STUB
float TRIBE_Tree_Object::currentTargetX() { return RGE_Static_Object::currentTargetX(); } // TODO: STUB
float TRIBE_Tree_Object::currentTargetY() { return RGE_Static_Object::currentTargetY(); } // TODO: STUB
float TRIBE_Tree_Object::currentTargetZ() { return RGE_Static_Object::currentTargetZ(); } // TODO: STUB
void TRIBE_Tree_Object::setWaitingToMove(uchar param_1) { RGE_Static_Object::setWaitingToMove(param_1); } // TODO: STUB
uchar TRIBE_Tree_Object::waitingToMove() { return RGE_Static_Object::waitingToMove(); } // TODO: STUB
uchar TRIBE_Tree_Object::actionState() { return RGE_Static_Object::actionState(); } // TODO: STUB
uchar TRIBE_Tree_Object::keepGatheringWhenObjectIsOut(int param_1) { return RGE_Static_Object::keepGatheringWhenObjectIsOut(param_1); } // TODO: STUB
uchar TRIBE_Tree_Object::produceWhenKilledBy(int param_1) { return RGE_Static_Object::produceWhenKilledBy(param_1); } // TODO: STUB
uchar TRIBE_Tree_Object::useSameZoneDropsite() { return RGE_Static_Object::useSameZoneDropsite(); } // TODO: STUB
void TRIBE_Tree_Object::logDebug(const char* param_1, ...) {
    va_list args;
    va_start(args, param_1);
    char formatted_message[1024];
    formatted_message[0] = '\0';
    if (param_1 != nullptr) {
        vsnprintf(formatted_message, sizeof(formatted_message), param_1, args);
        formatted_message[sizeof(formatted_message) - 1] = '\0';
    }
    this->RGE_Static_Object::logDebug("%s", formatted_message);
    va_end(args);
} // TODO: STUB
void TRIBE_Tree_Object::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) { RGE_Static_Object::notify(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
int TRIBE_Tree_Object::attack(float param_1, float param_2, float param_3, int param_4) { return RGE_Static_Object::attack(param_1, param_2, param_3, param_4); } // TODO: STUB
int TRIBE_Tree_Object::attack(int param_1, int param_2) { return RGE_Static_Object::attack(param_1, param_2); } // TODO: STUB
int TRIBE_Tree_Object::moveTo(float param_1, float param_2, float param_3, float param_4, int param_5) { return RGE_Static_Object::moveTo(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
int TRIBE_Tree_Object::moveTo(int param_1, float param_2, int param_3) { return RGE_Static_Object::moveTo(param_1, param_2, param_3); } // TODO: STUB
int TRIBE_Tree_Object::moveTo(int param_1, int param_2) { return RGE_Static_Object::moveTo(param_1, param_2); } // TODO: STUB
int TRIBE_Tree_Object::moveAwayFrom(int param_1, int param_2) { return RGE_Static_Object::moveAwayFrom(param_1, param_2); } // TODO: STUB
int TRIBE_Tree_Object::hunt(int param_1, int param_2) { return RGE_Static_Object::hunt(param_1, param_2); } // TODO: STUB
int TRIBE_Tree_Object::gather(int param_1, int param_2) { return RGE_Static_Object::gather(param_1, param_2); } // TODO: STUB
int TRIBE_Tree_Object::convert(int param_1, int param_2) { return RGE_Static_Object::convert(param_1, param_2); } // TODO: STUB
int TRIBE_Tree_Object::repair(int param_1, int param_2) { return RGE_Static_Object::repair(param_1, param_2); } // TODO: STUB
int TRIBE_Tree_Object::build(int param_1, int param_2) { return RGE_Static_Object::build(param_1, param_2); } // TODO: STUB
int TRIBE_Tree_Object::trade(int param_1, int param_2) { return RGE_Static_Object::trade(param_1, param_2); } // TODO: STUB
int TRIBE_Tree_Object::explore(int param_1, int param_2, int param_3) { return RGE_Static_Object::explore(param_1, param_2, param_3); } // TODO: STUB
int TRIBE_Tree_Object::enter(int param_1, int param_2) { return RGE_Static_Object::enter(param_1, param_2); } // TODO: STUB
int TRIBE_Tree_Object::unload(int param_1, float param_2, float param_3, float param_4) { return RGE_Static_Object::unload(param_1, param_2, param_3, param_4); } // TODO: STUB
int TRIBE_Tree_Object::transport(float param_1, float param_2, float param_3, int param_4) { return RGE_Static_Object::transport(param_1, param_2, param_3, param_4); } // TODO: STUB
int TRIBE_Tree_Object::stopAction() { return RGE_Static_Object::stopAction(); } // TODO: STUB
int TRIBE_Tree_Object::pause() { return RGE_Static_Object::pause(); } // TODO: STUB
int TRIBE_Tree_Object::canPath(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6) { return RGE_Static_Object::canPath(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
int TRIBE_Tree_Object::canPath(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7) { return RGE_Static_Object::canPath(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
int TRIBE_Tree_Object::canBidirectionPath(int param_1, int param_2, float param_3, float* param_4, int param_5, int param_6, int param_7) { return RGE_Static_Object::canBidirectionPath(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
int TRIBE_Tree_Object::canPathWithObstructions(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6, ManagedArray<int>* param_7) { return RGE_Static_Object::canPathWithObstructions(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
int TRIBE_Tree_Object::canPathWithAdditionalPassability(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7, int param_8, int param_9) { return RGE_Static_Object::canPathWithAdditionalPassability(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); } // TODO: STUB
int TRIBE_Tree_Object::findFirstTerrainAlongExceptionPath(int param_1, float* param_2, float* param_3) { return RGE_Static_Object::findFirstTerrainAlongExceptionPath(param_1, param_2, param_3); } // TODO: STUB
int TRIBE_Tree_Object::canLinePath(int param_1, int param_2, int param_3, int param_4, float param_5, int param_6) { return RGE_Static_Object::canLinePath(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
int TRIBE_Tree_Object::canLinePath(XYPoint* param_1, XYPoint* param_2, float param_3, XYPoint* param_4, int param_5) { return RGE_Static_Object::canLinePath(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
int TRIBE_Tree_Object::firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6) { return RGE_Static_Object::firstTileAlongLine(param_1, param_2, param_3, param_4, param_5, param_6); } // TODO: STUB
XYZBYTEPoint* TRIBE_Tree_Object::userDefinedWaypoint(int param_1) { return RGE_Static_Object::userDefinedWaypoint(param_1); } // TODO: STUB
int TRIBE_Tree_Object::addUserDefinedWaypoint(XYZBYTEPoint* param_1, int param_2) { return RGE_Static_Object::addUserDefinedWaypoint(param_1, param_2); } // TODO: STUB
void TRIBE_Tree_Object::removeAllUserDefinedWaypoints(int param_1) { RGE_Static_Object::removeAllUserDefinedWaypoints(param_1); } // TODO: STUB
void TRIBE_Tree_Object::removeUserDefinedWaypoint(int param_1) { RGE_Static_Object::removeUserDefinedWaypoint(param_1); } // TODO: STUB
int TRIBE_Tree_Object::numberUserDefinedWaypoints() { return RGE_Static_Object::numberUserDefinedWaypoints(); } // TODO: STUB
Path* TRIBE_Tree_Object::findAvoidancePath(XYZPoint* param_1, float param_2, int param_3) { return RGE_Static_Object::findAvoidancePath(param_1, param_2, param_3); } // TODO: STUB
long TRIBE_Tree_Object::get_action_checksum() { return RGE_Static_Object::get_action_checksum(); } // TODO: STUB
long TRIBE_Tree_Object::get_waypoint_checksum() { return RGE_Static_Object::get_waypoint_checksum(); } // TODO: STUB
int TRIBE_Tree_Object::setup(int param_1, RGE_Game_World* param_2) { return RGE_Static_Object::setup(param_1, param_2); } // TODO: STUB
int TRIBE_Tree_Object::setup(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) { return RGE_Static_Object::setup(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
RGE_Object_List* TRIBE_Tree_Object::create_object_list() { return RGE_Static_Object::create_object_list(); } // TODO: STUB
RGE_Active_Sprite_List* TRIBE_Tree_Object::create_sprite_list() { return RGE_Static_Object::create_sprite_list(); } // TODO: STUB

void TRIBE_Tree_Object::set_object_state(uchar param_1) {
    // Fully verified. Source of truth: t_tre_ob.cpp.decomp @ 0x004CCB90
    RGE_Static_Object::set_object_state(param_1);
}
