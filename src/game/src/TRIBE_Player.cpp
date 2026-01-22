#include "../include/TRIBE_Player.h"
#include "../include/RGE_Static_Object.h"

// TRIBE_Player stubs - mostly delegating to RGE_Player
TRIBE_Player::~TRIBE_Player() {}
void TRIBE_Player::set_game_status(uchar param_1) { RGE_Player::set_game_status(param_1); }
void TRIBE_Player::do_resign(int param_1) { RGE_Player::do_resign(param_1); }
void TRIBE_Player::changeToHumanPlayer() { RGE_Player::changeToHumanPlayer(); }
void TRIBE_Player::changeToComputerPlayer() { RGE_Player::changeToComputerPlayer(); }
char* TRIBE_Player::aiStatus(int param_1) { return RGE_Player::aiStatus(param_1); }
int TRIBE_Player::isEnemy(int param_1) { return RGE_Player::isEnemy(param_1); }
int TRIBE_Player::isAlly(int param_1) { return RGE_Player::isAlly(param_1); }
int TRIBE_Player::isNeutral(int param_1) { return RGE_Player::isNeutral(param_1); }
int TRIBE_Player::isAllNeutral() { return RGE_Player::isAllNeutral(); }
void TRIBE_Player::setDiplomaticStance(int param_1, int param_2) { RGE_Player::setDiplomaticStance(param_1, param_2); }
void TRIBE_Player::loadAIInformation(char* param_1, char* param_2, char* param_3, int param_4, int param_5) { RGE_Player::loadAIInformation(param_1, param_2, param_3, param_4, param_5); }
void TRIBE_Player::sendUnitAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12) { RGE_Player::sendUnitAIOrder(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
void TRIBE_Player::processAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12) { RGE_Player::processAIOrder(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
void TRIBE_Player::kickAI(int param_1) { RGE_Player::kickAI(param_1); }
int TRIBE_Player::strategicNumber(int param_1) { return RGE_Player::strategicNumber(param_1); }
void TRIBE_Player::sendGameOrder(RGE_Static_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4) { RGE_Player::sendGameOrder(param_1, param_2, param_3, param_4); }
void TRIBE_Player::sendAddWaypointCommand(int param_1, XYZBYTEPoint* param_2, int param_3) { RGE_Player::sendAddWaypointCommand(param_1, param_2, param_3); }
void TRIBE_Player::processAddWaypointCommand(int param_1, XYZBYTEPoint* param_2, int param_3) { RGE_Player::processAddWaypointCommand(param_1, param_2, param_3); }
void TRIBE_Player::sendPlayCommand(int param_1, int* param_2, int param_3, int param_4, int param_5) { RGE_Player::sendPlayCommand(param_1, param_2, param_3, param_4, param_5); }
void TRIBE_Player::sendPlayCommand(int param_1, int param_2, int param_3) { RGE_Player::sendPlayCommand(param_1, param_2, param_3); }
int TRIBE_Player::sendAICommand(int param_1, int param_2, int param_3, int param_4, int param_5) { return RGE_Player::sendAICommand(param_1, param_2, param_3, param_4, param_5); }
int TRIBE_Player::objectCostByType(int param_1) { return RGE_Player::objectCostByType(param_1); }
void TRIBE_Player::trackUnitGather(int param_1, int param_2, int param_3) { RGE_Player::trackUnitGather(param_1, param_2, param_3); }
RGE_Static_Object* TRIBE_Player::make_scenario_obj(float param_1, float param_2, float param_3, short param_4, uchar param_5, float param_6) { return RGE_Player::make_scenario_obj(param_1, param_2, param_3, param_4, param_5, param_6); }
void TRIBE_Player::scenario_save(int param_1) { RGE_Player::scenario_save(param_1); }
void TRIBE_Player::scenario_load(int param_1, long* param_2, float param_3) { RGE_Player::scenario_load(param_1, param_2, param_3); }
void TRIBE_Player::scenario_postsave(int param_1) { RGE_Player::scenario_postsave(param_1); }
void TRIBE_Player::scenario_postload(int param_1, long* param_2, float param_3) { RGE_Player::scenario_postload(param_1, param_2, param_3); }
void TRIBE_Player::load(int param_1) { RGE_Player::load(param_1); }
void TRIBE_Player::add_attribute_num(short param_1, float param_2, uchar param_3) { RGE_Player::add_attribute_num(param_1, param_2, param_3); }
void TRIBE_Player::update() { RGE_Player::update(); }
void TRIBE_Player::update_dopplegangers() { RGE_Player::update_dopplegangers(); }
void TRIBE_Player::save(int param_1) { RGE_Player::save(param_1); }
void TRIBE_Player::save2(int param_1) { RGE_Player::save2(param_1); }
void TRIBE_Player::save_info(int param_1) { RGE_Player::save_info(param_1); }
void TRIBE_Player::random_start() { RGE_Player::random_start(); }
RGE_Static_Object* TRIBE_Player::make_new_object(long param_1, float param_2, float param_3, float param_4, int param_5) { return RGE_Player::make_new_object(param_1, param_2, param_3, param_4, param_5); }
void TRIBE_Player::analyize_selected_objects() { RGE_Player::analyize_selected_objects(); }
int TRIBE_Player::get_mouse_pointer_action_vars(int param_1, int* param_2, int* param_3) { return RGE_Player::get_mouse_pointer_action_vars(param_1, param_2, param_3); }
uchar TRIBE_Player::command_make_move(RGE_Static_Object* param_1, float param_2, float param_3) { return RGE_Player::command_make_move(param_1, param_2, param_3); }
uchar TRIBE_Player::command_make_work(RGE_Static_Object* param_1, float param_2, float param_3) { return RGE_Player::command_make_work(param_1, param_2, param_3); }
uchar TRIBE_Player::command_make_do(RGE_Static_Object* param_1, float param_2, float param_3) { return RGE_Player::command_make_do(param_1, param_2, param_3); }
uchar TRIBE_Player::command_stop() { return RGE_Player::command_stop(); }
uchar TRIBE_Player::command_place_object(short param_1, float param_2, float param_3, float param_4) { return RGE_Player::command_place_object(param_1, param_2, param_3, param_4); }
uchar TRIBE_Player::command_add_attribute(int param_1, float param_2) { return RGE_Player::command_add_attribute(param_1, param_2); }
uchar TRIBE_Player::command_give_attribute(int param_1, int param_2, float param_3) { return RGE_Player::command_give_attribute(param_1, param_2, param_3); }
uchar TRIBE_Player::command_formation(int param_1) { return RGE_Player::command_formation(param_1); }
uchar TRIBE_Player::command_stand_ground() { return RGE_Player::command_stand_ground(); }
uchar TRIBE_Player::command_create_group(int param_1, int* param_2, int param_3, float param_4) { return RGE_Player::command_create_group(param_1, param_2, param_3, param_4); }
uchar TRIBE_Player::command_add_to_group(int param_1, int param_2, float param_3) { return RGE_Player::command_add_to_group(param_1, param_2, param_3); }
uchar TRIBE_Player::command_remove_from_group(int param_1, int param_2) { return RGE_Player::command_remove_from_group(param_1, param_2); }
uchar TRIBE_Player::command_destroy_group(int param_1) { return RGE_Player::command_destroy_group(param_1); }
uchar TRIBE_Player::command_resign(int param_1, int param_2) { return RGE_Player::command_resign(param_1, param_2); }
uchar TRIBE_Player::command_add_waypoint(float param_1, float param_2, float param_3) { return RGE_Player::command_add_waypoint(param_1, param_2, param_3); }
RGE_Object_Node* TRIBE_Player::addObject(RGE_Static_Object* param_1, int param_2, int param_3) { return RGE_Player::addObject(param_1, param_2, param_3); }
void TRIBE_Player::removeObject(RGE_Static_Object* param_1, int param_2, int param_3, RGE_Object_Node* param_4) { RGE_Player::removeObject(param_1, param_2, param_3, param_4); }
void TRIBE_Player::logMessage(char* param_1) { RGE_Player::logMessage(param_1); }
void TRIBE_Player::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) { RGE_Player::notify(param_1, param_2, param_3, param_4, param_5, param_6); }
void TRIBE_Player::logStatus(FILE* param_1, int param_2) { RGE_Player::logStatus(param_1, param_2); }
void TRIBE_Player::load_victory(int param_1, long* param_2, uchar param_3) { RGE_Player::load_victory(param_1, param_2, param_3); }
void TRIBE_Player::new_victory() { RGE_Player::new_victory(); }
uchar TRIBE_Player::command_give_attribute(int param_1, int param_2, float param_3, float param_4) { return 0; }
void TRIBE_Player::buildObject(int param_1, int param_2, float param_3, float param_4, int param_5) {}
void TRIBE_Player::cancelBuild(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7) {}
void TRIBE_Player::registerBuild(RGE_Static_Object* param_1, int param_2) {}
void TRIBE_Player::trainUnit(int param_1, int param_2, int param_3) {}
void TRIBE_Player::cancelTrain(int param_1, int param_2, int param_3, int param_4) {}
void TRIBE_Player::registerTrain(int param_1, int param_2, int param_3, int param_4) {}
void TRIBE_Player::research(int param_1, int param_2, int param_3) {}
void TRIBE_Player::cancelResearch(int param_1, int param_2, int param_3, int param_4) {}
void TRIBE_Player::registerResearch(int param_1, int param_2, int param_3) {}
void TRIBE_Player::taskTrader(int param_1, int param_2, int param_3, float param_4, float param_5) {}
void TRIBE_Player::taskResourceGatherer(int param_1, int param_2, int param_3, float param_4, float param_5) {}
void TRIBE_Player::notifyAI(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {}
