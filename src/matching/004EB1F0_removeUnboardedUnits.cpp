// 004EB1F0 TacticalAIGroup::removeUnboardedUnits(TribeTacticalAIModule*,TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 396-418
// Attempt log:
// - Replaced stub with full scan/removal logic, commander updates, player vtable
//   +0xCC notification, and TribeTacticalAIModule::stopUnit call through the
//   canonical RGE_Player surface.
// - Exact match with countdown local (`remaining = 40`) and pointer do-while;
//   reloading `*p` before commander/stopUnit preserves the original memory reads.

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
class RGE_Static_Object {
public:
    char gap_00[0x20];
    RGE_Static_Object* inside_obj;
};
#endif

#ifndef TAITACMD_SHARED_CONTEXT
class TribeMainDecisionAIModule {
public:
    char gap_000[0xF0];
    RGE_Player* player;

    RGE_Static_Object* object(int id);
};
#endif

#ifndef TAITACMD_SHARED_CONTEXT
class TribeTacticalAIModule {
public:
    int stopUnit(int id, int priority);
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
    int removeUnboardedUnits(TribeTacticalAIModule* tactical, TribeMainDecisionAIModule* md);
};
#endif

int TacticalAIGroup::removeUnboardedUnits(TribeTacticalAIModule* tactical, TribeMainDecisionAIModule* md)
{
    int remaining;
    int* p;
    int unit;
    int commander;
    RGE_Static_Object* obj;

    remaining = 40;
    p = this->unitsValue;
    do {
        unit = *p;
        if (unit != -1) {
            obj = md->object(unit);
            if (obj == 0 || obj->inside_obj == 0) {
                unit = *p;
                commander = this->commanderValue;
                if (unit == commander) {
                    this->setSpecificCommander(-1, md);
                }
                else if (commander != -1) {
                    md->player->command_remove_from_group(commander, unit);
                }
                tactical->stopUnit(*p, 100);
                *p = -1;
                p[40] = -1;
                this->numberUnitsValue = this->numberUnitsValue - 1;
            }
        }
        p = p + 1;
        remaining = remaining - 1;
    } while (remaining != 0);
    return 1;
}
