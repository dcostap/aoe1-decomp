#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Static_Object;

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual void owner();
    virtual void order();
    virtual int notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status();
    virtual void do_resign();
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual void aiStatus();
    virtual void isEnemy();
    virtual void isAlly();
    virtual void isNeutral();
    virtual void isAllNeutral();
    virtual void setDiplomaticStance();
    virtual void loadAIInformation();
    virtual void sendUnitAIOrder();
    virtual void processAIOrder();
    virtual void kickAI();
    virtual void strategicNumber();
    virtual void sendGameOrder();
    virtual void sendAddWaypointCommand();
    virtual void processAddWaypointCommand();
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual void sendAICommand();
    virtual void objectCostByType();
    virtual void trackUnitGather();
    virtual void make_scenario_obj();
    virtual void scenario_save();
    virtual void scenario_load();
    virtual void scenario_postsave();
    virtual void scenario_postload();
    virtual void load();
    virtual void add_attribute_num();
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save();
    virtual void save2();
    virtual void save_info();
    virtual void random_start();
    virtual void make_new_object();
    virtual void analyize_selected_objects();
    virtual void get_mouse_pointer_action_vars();
    virtual void command_make_move();
    virtual void command_make_work();
    virtual void command_make_do();
    virtual void command_stop();
    virtual void command_place_object();
    virtual void command_add_attribute();
    virtual void command_give_attribute();
    virtual void command_formation();
    virtual void command_stand_ground();
    virtual void command_create_group();
    virtual void command_add_to_group();
    virtual void command_remove_from_group();
    virtual void command_destroy_group();
    virtual void command_resign();
    virtual void command_add_waypoint();
    virtual void addObject();
    virtual void removeObject();
    virtual void logMessage();
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
};

class RGE_Combat_Object {
public:
    int id;
    void* master_obj;
    RGE_Player* owner;
    unsigned char gap_10[0x38];
    unsigned char object_state;
    unsigned char gap_49[0x2B];
    UnitAIModule* unitAIValue;

    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
};
#endif

void RGE_Combat_Object::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {
    if (object_state == 2) {
        if (unitAIValue != 0) {
            if (unitAIValue->notify(param_1, param_2, param_3, param_4, param_5, param_6) != 0) {
                return;
            }
        }
        if (param_3 != 0x2BB) {
            owner->notify(param_1, param_2, param_3, param_4, param_5, param_6);
        }
    }
}
