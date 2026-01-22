#include "../include/RGE_Player.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Static_Object.h"

// RGE_Player stubs
RGE_Player::~RGE_Player() {}
void RGE_Player::set_game_status(uchar param_1) {}
void RGE_Player::do_resign(int param_1) {}
void RGE_Player::changeToHumanPlayer() {}
void RGE_Player::changeToComputerPlayer() {}
char* RGE_Player::aiStatus(int param_1) { return nullptr; }
int RGE_Player::isEnemy(int param_1) { return 0; }
int RGE_Player::isAlly(int param_1) { return 0; }
int RGE_Player::isNeutral(int param_1) { return 0; }
int RGE_Player::isAllNeutral() { return 0; }
void RGE_Player::setDiplomaticStance(int param_1, int param_2) {}
void RGE_Player::loadAIInformation(char* param_1, char* param_2, char* param_3, int param_4, int param_5) {}
void RGE_Player::sendUnitAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12) {}
void RGE_Player::processAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12) {}
void RGE_Player::kickAI(int param_1) {}
int RGE_Player::strategicNumber(int param_1) { return 0; }
void RGE_Player::sendGameOrder(RGE_Static_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4) {}
void RGE_Player::sendAddWaypointCommand(int param_1, XYZBYTEPoint* param_2, int param_3) {}
void RGE_Player::processAddWaypointCommand(int param_1, XYZBYTEPoint* param_2, int param_3) {}
void RGE_Player::sendPlayCommand(int param_1, int* param_2, int param_3, int param_4, int param_5) {}
void RGE_Player::sendPlayCommand(int param_1, int param_2, int param_3) {}
int RGE_Player::sendAICommand(int param_1, int param_2, int param_3, int param_4, int param_5) { return 0; }
int RGE_Player::objectCostByType(int param_1) { return 0; }
void RGE_Player::trackUnitGather(int param_1, int param_2, int param_3) {}
RGE_Static_Object* RGE_Player::make_scenario_obj(float param_1, float param_2, float param_3, short param_4, uchar param_5, float param_6) { return nullptr; }
void RGE_Player::scenario_save(int param_1) {}
void RGE_Player::scenario_load(int param_1, long* param_2, float param_3) {}
void RGE_Player::scenario_postsave(int param_1) {}
void RGE_Player::scenario_postload(int param_1, long* param_2, float param_3) {}
void RGE_Player::load(int param_1) {}
void RGE_Player::add_attribute_num(short param_1, float param_2, uchar param_3) {}
void RGE_Player::update() {}
void RGE_Player::update_dopplegangers() {}
void RGE_Player::save(int param_1) {}
void RGE_Player::save2(int param_1) {}
void RGE_Player::save_info(int param_1) {}
void RGE_Player::random_start() {}
RGE_Static_Object* RGE_Player::make_new_object(long param_1, float param_2, float param_3, float param_4, int param_5) { return nullptr; }
void RGE_Player::analyize_selected_objects() {}
int RGE_Player::get_mouse_pointer_action_vars(int param_1, int* param_2, int* param_3) { return 0; }
uchar RGE_Player::command_make_move(RGE_Static_Object* param_1, float param_2, float param_3) { return 1; }
uchar RGE_Player::command_make_work(RGE_Static_Object* param_1, float param_2, float param_3) { return 1; }
uchar RGE_Player::command_make_do(RGE_Static_Object* param_1, float param_2, float param_3) { return 1; }
uchar RGE_Player::command_stop() { return 1; }
uchar RGE_Player::command_place_object(short param_1, float param_2, float param_3, float param_4) { return 1; }
uchar RGE_Player::command_add_attribute(int param_1, float param_2) { return 1; }
uchar RGE_Player::command_give_attribute(int param_1, int param_2, float param_3) { return 1; }
uchar RGE_Player::command_formation(int param_1) { return 1; }
uchar RGE_Player::command_stand_ground() { return 1; }
uchar RGE_Player::command_create_group(int param_1, int* param_2, int param_3, float param_4) { return 1; }
uchar RGE_Player::command_add_to_group(int param_1, int param_2, float param_3) { return 1; }
uchar RGE_Player::command_remove_from_group(int param_1, int param_2) { return 1; }
uchar RGE_Player::command_destroy_group(int param_1) { return 1; }
uchar RGE_Player::command_resign(int param_1, int param_2) { return 1; }
uchar RGE_Player::command_add_waypoint(float param_1, float param_2, float param_3) { return 1; }
RGE_Object_Node* RGE_Player::addObject(RGE_Static_Object* param_1, int param_2, int param_3) { return nullptr; }
void RGE_Player::removeObject(RGE_Static_Object* param_1, int param_2, int param_3, RGE_Object_Node* param_4) {}
void RGE_Player::logMessage(char* param_1) {}
void RGE_Player::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {}
void RGE_Player::logStatus(FILE* param_1, int param_2) {}
void RGE_Player::load_victory(int param_1, long* param_2, uchar param_3) {}
void RGE_Player::new_victory() {}
