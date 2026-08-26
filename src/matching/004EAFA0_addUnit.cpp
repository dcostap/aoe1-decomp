// 004EAFA0 TacticalAIGroup::addUnit(int,TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 303-319
// Attempt log:
// - Replaced old one-slot stub with full Ghidra logic and the canonical
//   RGE_Player command surface.
// - Using `while (i < 40)` for the scan (not do-while) prevents
//   VC5 from peeling/preloading the first array element and matches the original
//   push-edi, xor-index, memory-cmp loop top.
// - The old `md->player->list->next` spelling was a reduced-context type view.
//   PDB fields name RGE_Player +0x3C as `world`, and RGE_Game_World +0x04 as
//   `world_time`. The original load is [player+3C], then [world+4]. Use that
//   real field meaning as `md->player->world->world_time`.

#ifndef TAITACMD_SHARED_CONTEXT
class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
};
#endif

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
    virtual void scenario_postload(int, long*, float);
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

    char gap_04[0x38];
    RGE_Game_World* world;
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
    char gap_168[0x32C - 0x168];
    unsigned long lastAddedUnitTimeValue;

    int addUnit(int unit, TribeMainDecisionAIModule* md);
};
#endif

int TacticalAIGroup::addUnit(int unit, TribeMainDecisionAIModule* md)
{
    int i;
    volatile int* p;

    i = 0;
    p = this->unitsValue;
    while (i < 40) {
        if (*p == -1) {
            this->unitsValue[i] = unit;
            this->unitsOriginalHitPointsValue[i] = -1;
            this->numberUnitsValue = this->numberUnitsValue + 1;
            if (this->commanderValue != -1) {
                md->player->command_add_to_group(this->commanderValue, unit, 4.0f);
            }
            this->lastAddedUnitTimeValue = md->player->world->world_time;
            return 1;
        }
        i = i + 1;
        p = p + 1;
    }
    return 0;
}
