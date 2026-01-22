#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Sprite.h"
#include "../include/RGE_Action_Object.h"
#include "../include/TDrawArea.h"
#include "../include/RGE_Color_Table.h"

// RGE_Static_Object stubs
RGE_Static_Object::~RGE_Static_Object() {}
void RGE_Static_Object::recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {}
void RGE_Static_Object::recycle_out_of_game() {}
void RGE_Static_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4) {}
void RGE_Static_Object::shadow_draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4) {}
void RGE_Static_Object::normal_draw(TDrawArea* param_1, short param_2, short param_3) {}
void RGE_Static_Object::draw_front_frame(TDrawArea* param_1, short param_2, short param_3) {}
void RGE_Static_Object::draw_back_frame(TDrawArea* param_1, short param_2, short param_3) {}
void RGE_Static_Object::draw_frame(TDrawArea* param_1, short param_2, short param_3) {}
uchar RGE_Static_Object::update() { return 1; }
void RGE_Static_Object::check_damage_sprites() {}
void RGE_Static_Object::rehook() {}
void RGE_Static_Object::save(int param_1) {}
float RGE_Static_Object::teleport(float param_1, float param_2, float param_3) { return 0.0f; }
void RGE_Static_Object::new_sprite(RGE_Sprite* param_1) {}
void RGE_Static_Object::add_overlay_sprite(RGE_Sprite* param_1, uchar param_2) {}
void RGE_Static_Object::remove_overlay_sprite(RGE_Sprite* param_1) {}
void RGE_Static_Object::change_ownership(RGE_Player* param_1) {}
void RGE_Static_Object::modify(float param_1, uchar param_2) {}
void RGE_Static_Object::modify_delta(float param_1, uchar param_2) {}
void RGE_Static_Object::modify_percent(float param_1, uchar param_2) {}
void RGE_Static_Object::transform(RGE_Master_Static_Object* param_1) {}
void RGE_Static_Object::copy_obj(RGE_Master_Static_Object* param_1) {}
void RGE_Static_Object::set_object_state(uchar param_1) {}
void RGE_Static_Object::remove_visible_resource() {}
void RGE_Static_Object::create_doppleganger_when_dying() {}
void RGE_Static_Object::destroy_obj() {}
void RGE_Static_Object::die_die_die() {}
void RGE_Static_Object::damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4) {}
float RGE_Static_Object::calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4) { return 0.0f; }
void RGE_Static_Object::rotate(long param_1) {}
uchar RGE_Static_Object::can_attack() { return 0; }
void RGE_Static_Object::set_attribute(short param_1, float param_2) {}
void RGE_Static_Object::set_attribute_amount(float param_1, uchar param_2, uchar param_3) {}
int RGE_Static_Object::heal(int param_1, int param_2) { return 0; }
uchar RGE_Static_Object::heal(float param_1) { return 0; }
int RGE_Static_Object::canRepair() { return 0; }
void RGE_Static_Object::notify_of_relation(long param_1, uchar param_2) {}
void RGE_Static_Object::do_command(float param_1, float param_2, float param_3) {}
void RGE_Static_Object::move_to(float param_1, float param_2, float param_3) {}
void RGE_Static_Object::work(float param_1, float param_2, float param_3) {}
void RGE_Static_Object::stop() {}
void RGE_Static_Object::set_attack() {}
void RGE_Static_Object::play_command_sound() {}
void RGE_Static_Object::play_move_sound() {}
void RGE_Static_Object::new_angle(float param_1) {}
RGE_Static_Object* RGE_Static_Object::spawn_death_obj() { return nullptr; }
RGE_Master_Static_Object* RGE_Static_Object::get_command_master(float param_1, float param_2, float param_3) { return nullptr; }
void RGE_Static_Object::set_being_worked_on(RGE_Action_Object* param_1, short param_2, uchar param_3) {}
void RGE_Static_Object::release_being_worked_on() {}
uchar RGE_Static_Object::is_moving() { return 0; }
RGE_Static_Object* RGE_Static_Object::get_target_obj() { return nullptr; }
void RGE_Static_Object::enter_obj() {}
void RGE_Static_Object::exit_obj() {}
int RGE_Static_Object::explore_terrain(RGE_Player* param_1, uchar param_2, int param_3) { return 0; }
void RGE_Static_Object::unexplore_terrain(RGE_Player* param_1, uchar param_2, int param_3) {}
LOSTBL* RGE_Static_Object::get_los_table() { return nullptr; }
int RGE_Static_Object::inAttackRange() { return 0; }
uchar RGE_Static_Object::underAttack() { return 0; }
void RGE_Static_Object::setUnderAttack(uchar param_1) {}
float RGE_Static_Object::calc_attack_modifier() { return 1.0f; }
float RGE_Static_Object::getSpeed() { return 0.0f; }
float RGE_Static_Object::getAngle() { return 0.0f; }
float RGE_Static_Object::maximumSpeed() { return 0.0f; }
float RGE_Static_Object::rateOfFire() { return 1.0f; }
float RGE_Static_Object::damageCapability(RGE_Static_Object* param_1) { return 0.0f; }
float RGE_Static_Object::damageCapability() { return 0.0f; }
float RGE_Static_Object::weaponRange() { return 0.0f; }
float RGE_Static_Object::minimumWeaponRange() { return 0.0f; }
int RGE_Static_Object::passableTile(float param_1, float param_2, int param_3) { return 1; }
uchar RGE_Static_Object::facetToNextWaypoint() { return 0; }
int RGE_Static_Object::currentTargetID() { return -1; }
float RGE_Static_Object::currentTargetX() { return 0.0f; }
float RGE_Static_Object::currentTargetY() { return 0.0f; }
float RGE_Static_Object::currentTargetZ() { return 0.0f; }
void RGE_Static_Object::setWaitingToMove(uchar param_1) {}
uchar RGE_Static_Object::waitingToMove() { return 0; }
uchar RGE_Static_Object::actionState() { return 0; }
uchar RGE_Static_Object::keepGatheringWhenObjectIsOut(int param_1) { return 0; }
uchar RGE_Static_Object::produceWhenKilledBy(int param_1) { return 0; }
uchar RGE_Static_Object::useSameZoneDropsite() { return 0; }
void RGE_Static_Object::logDebug(char* param_1) {}
void RGE_Static_Object::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {}
int RGE_Static_Object::attack(float param_1, float param_2, float param_3, int param_4) { return 0; }
int RGE_Static_Object::attack(int param_1, int param_2) { return 0; }
int RGE_Static_Object::moveTo(float param_1, float param_2, float param_3, float param_4, int param_5) { return 0; }
int RGE_Static_Object::moveTo(int param_1, float param_2, int param_3) { return 0; }
int RGE_Static_Object::moveTo(int param_1, int param_2) { return 0; }
int RGE_Static_Object::moveAwayFrom(int param_1, int param_2) { return 0; }
int RGE_Static_Object::hunt(int param_1, int param_2) { return 0; }
int RGE_Static_Object::gather(int param_1, int param_2) { return 0; }
int RGE_Static_Object::convert(int param_1, int param_2) { return 0; }
int RGE_Static_Object::repair(int param_1, int param_2) { return 0; }
int RGE_Static_Object::build(int param_1, int param_2) { return 0; }
int RGE_Static_Object::trade(int param_1, int param_2) { return 0; }
int RGE_Static_Object::explore(int param_1, int param_2, int param_3) { return 0; }
int RGE_Static_Object::enter(int param_1, int param_2) { return 0; }
int RGE_Static_Object::unload(int param_1, float param_2, float param_3, float param_4) { return 0; }
int RGE_Static_Object::transport(float param_1, float param_2, float param_3, int param_4) { return 0; }
int RGE_Static_Object::stopAction() { return 0; }
int RGE_Static_Object::pause() { return 0; }
int RGE_Static_Object::canPath(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6) { return 0; }
int RGE_Static_Object::canPath(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7) { return 0; }
int RGE_Static_Object::canBidirectionPath(int param_1, int param_2, float param_3, float* param_4, int param_5, int param_6, int param_7) { return 0; }
int RGE_Static_Object::canPathWithObstructions(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6, ManagedArray<int>* param_7) { return 0; }
int RGE_Static_Object::canPathWithAdditionalPassability(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7, int param_8, int param_9) { return 0; }
int RGE_Static_Object::findFirstTerrainAlongExceptionPath(int param_1, float* param_2, float* param_3) { return 0; }
int RGE_Static_Object::canLinePath(int param_1, int param_2, int param_3, int param_4, float param_5, int param_6) { return 0; }
int RGE_Static_Object::canLinePath(XYPoint* param_1, XYPoint* param_2, float param_3, XYPoint* param_4, int param_5) { return 0; }
int RGE_Static_Object::firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6) { return 0; }
XYZBYTEPoint* RGE_Static_Object::userDefinedWaypoint(int param_1) { return nullptr; }
int RGE_Static_Object::addUserDefinedWaypoint(XYZBYTEPoint* param_1, int param_2) { return 0; }
void RGE_Static_Object::removeAllUserDefinedWaypoints(int param_1) {}
void RGE_Static_Object::removeUserDefinedWaypoint(int param_1) {}
int RGE_Static_Object::numberUserDefinedWaypoints() { return 0; }
Path* RGE_Static_Object::findAvoidancePath(XYZPoint* param_1, float param_2, int param_3) { return nullptr; }
long RGE_Static_Object::get_action_checksum() { return 0; }
long RGE_Static_Object::get_waypoint_checksum() { return 0; }
int RGE_Static_Object::setup(int param_1, RGE_Game_World* param_2) { return 1; }
int RGE_Static_Object::setup(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) { return 1; }
RGE_Object_List* RGE_Static_Object::create_object_list() { return nullptr; }
RGE_Active_Sprite_List* RGE_Static_Object::create_sprite_list() { return nullptr; }
