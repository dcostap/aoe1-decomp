// 004EB030 TacticalAIGroup::removeUnit(int,TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 324-341
// Attempt log:
// - Replaced old one-field stub with full Ghidra logic and the canonical
//   RGE_Player command surface.
// - Exact match: use an explicit pointer plus `while (i < 40)` scan. This keeps
//   the parameter load before saved-register pushes and emits the original
//   memory compare at the loop top instead of a peeled first-element load.

#ifndef TAITACMD_SHARED_CONTEXT
class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float,
                                float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(void*, void*, float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual void make_scenario_obj(float, float, float, short, unsigned char, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int);
    virtual void load(int);
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual void* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(void*, float, float);
    virtual unsigned char command_make_work(void*, float, float);
    virtual unsigned char command_make_do(void*, float, float);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short, float, float, float);
    virtual unsigned char command_add_attribute(int, float);
    virtual unsigned char command_give_attribute(int, int, float);
    virtual unsigned char command_formation(int);
    virtual unsigned char command_stand_ground();
    virtual unsigned char command_create_group(int, int*, int, float);
    virtual unsigned char command_add_to_group(int, int, float);
    virtual unsigned char command_remove_from_group(int, int);
};
#endif

#ifndef TAITACMD_SHARED_CONTEXT
class TribeMainDecisionAIModule {
public:
    char gap_000[0xF0];
    RGE_Player* player;
};
#endif

#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    char gap_00[0x1C];
    int unitsValue[40];
    int unitsOriginalHitPointsValue[40];
    int numberUnitsValue;
    int desiredNumberUnitsValue;
    int commanderValue;

    void setSpecificCommander(int commander, TribeMainDecisionAIModule* md);
    int removeUnit(int unit, TribeMainDecisionAIModule* md);
};
#endif

int TacticalAIGroup::removeUnit(int unit, TribeMainDecisionAIModule* md)
{
    int commander;
    int i;
    int* p;

    i = 0;
    p = this->unitsValue;
    while (i < 40) {
        if (*p == unit) {
            commander = this->commanderValue;
            if (unit == commander) {
                this->setSpecificCommander(-1, md);
            }
            else if (commander != -1) {
                md->player->command_remove_from_group(commander, unit);
            }
            this->unitsValue[i] = -1;
            this->unitsOriginalHitPointsValue[i] = -1;
            this->numberUnitsValue = this->numberUnitsValue - 1;
            return 1;
        }
        i = i + 1;
        p = p + 1;
    }
    return 0;
}
