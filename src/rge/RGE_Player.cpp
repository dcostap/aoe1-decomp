#include "RGE_Player.h"
#include <stdio.h>

RGE_Player::~RGE_Player() {}
void RGE_Player::set_game_status(uchar status) {}
void RGE_Player::do_resign(int param_1) {}
void RGE_Player::changeToHumanPlayer() {}
void RGE_Player::changeToComputerPlayer() {}
char *RGE_Player::aiStatus(int param_1) { return nullptr; }
int RGE_Player::isEnemy(int player_id) { return 0; }
int RGE_Player::isAlly(int player_id) { return 0; }
int RGE_Player::isNeutral(int player_id) { return 0; }
int RGE_Player::isAllNeutral() { return 0; }
void RGE_Player::setDiplomaticStance(int player_id, int stance) {}
void RGE_Player::loadAIInformation(char *a, char *b, char *c, int d, int e) {}
void RGE_Player::sendUnitAIOrder(int a, int b, int c, int d, int e, float f, float g, float h, float i, int j, int k, int l) {}
void RGE_Player::processAIOrder(int a, int b, int c, int d, int e, float f, float g, float h, float i, int j, int k, int l) {}
void RGE_Player::kickAI(int param_1) {}
int RGE_Player::strategicNumber(int param_1) { return 0; }
void RGE_Player::sendGameOrder(RGE_Static_Object *obj1, RGE_Static_Object *obj2, float x, float y) {}
void RGE_Player::sendAddWaypointCommand(int a, XYZBYTEPoint *b, int c) {}
void RGE_Player::processAddWaypointCommand(int a, XYZBYTEPoint *b, int c) {}
void RGE_Player::sendPlayCommand(int a, int *b, int c, int d, int e) {}
void RGE_Player::sendPlayCommand(int a, int b, int c) {}
int RGE_Player::sendAICommand(int a, int b, int c, int d, int e) { return 0; }
int RGE_Player::objectCostByType(int param_1) { return 0; }
void RGE_Player::trackUnitGather(int a, int b, int c) {}
RGE_Static_Object *RGE_Player::make_scenario_obj(float a, float b, float c, short d, uchar e, float f) { return nullptr; }
void RGE_Player::scenario_save(int file_ptr) {}
void RGE_Player::scenario_load(int a, long *b, float c) {}
void RGE_Player::scenario_postsave(int file_ptr) {}
void RGE_Player::scenario_postload(int a, long *b, float c) {}
void RGE_Player::load(int file_ptr) {}
void RGE_Player::add_attribute_num(short id, float amount, uchar type) {}
void RGE_Player::update() {}
void RGE_Player::update_dopplegangers() {}
void RGE_Player::save(int file_ptr) {}
void RGE_Player::save2(int file_ptr) {}
void RGE_Player::save_info(int file_ptr) {}
void RGE_Player::random_start() {}
RGE_Static_Object *RGE_Player::make_new_object(long a, float b, float c, float d, int e) { return nullptr; }
void RGE_Player::analyize_selected_objects() {}
int RGE_Player::get_mouse_pointer_action_vars(int a, int *b, int *c) { return 0; }
uchar RGE_Player::command_make_move(RGE_Static_Object *obj, float x, float y) { return 0; }
uchar RGE_Player::command_make_work(RGE_Static_Object *obj, float x, float y) { return 0; }
uchar RGE_Player::command_make_do(RGE_Static_Object *obj, float x, float y) { return 0; }
uchar RGE_Player::command_stop() { return 0; }
uchar RGE_Player::command_place_object(short a, float b, float c, float d) { return 0; }
uchar RGE_Player::command_add_attribute(int id, float amount) { return 0; }
uchar RGE_Player::command_give_attribute(int player_id, int attr_id, float amount) { return 0; }
uchar RGE_Player::command_formation(int param_1) { return 0; }
uchar RGE_Player::command_stand_ground() { return 0; }
uchar RGE_Player::command_create_group(int a, int *b, int c, float d) { return 0; }
uchar RGE_Player::command_add_to_group(int a, int b, float c) { return 0; }
uchar RGE_Player::command_remove_from_group(int a, int b) { return 0; }
uchar RGE_Player::command_destroy_group(int param_1) { return 0; }
uchar RGE_Player::command_resign(int a, int b) { return 0; }
uchar RGE_Player::command_add_waypoint(float a, float b, float c) { return 0; }
RGE_Object_Node *RGE_Player::addObject(RGE_Static_Object *obj, int a, int b) { return nullptr; }
void RGE_Player::removeObject(RGE_Static_Object *obj, int a, int b, RGE_Object_Node *c) {}
void RGE_Player::logMessage(char *format, ...) {}
void RGE_Player::notify(int a, int b, int c, long d, long e, long f) {}
void RGE_Player::logStatus(_iobuf *file, int a) {}
void RGE_Player::load_victory(int a, long *b, uchar c) {}
void RGE_Player::new_victory() {}
