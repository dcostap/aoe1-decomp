// VA: 00502920 TribeTacticalAIModule::checkForCoopTributeGift
// Attempt log:
// - Initial rough reconstruction was structurally short and used incomplete
//   player/object virtual surfaces.
// - Baseline recorded before replacing that scaffold with the period-shaped
//   md/player/world/resource ownership and the exact RGE/TRIBE virtual slots.
// - Canonical typed reconstruction restored exact size/frame, all 11 ordered
//   calls, and the first 169 instructions; the remaining drift is localized to
//   the final four-argument command_give_attribute x87 argument schedule.
// - Tried direct final argument evaluation, split/named resource-delta locals,
//   receiver/attribute pointer locals, and a focused 12-variant lab.  The
//   closest natural form uses an int delta plus a float current-attribute local
//   (71 positional bytes; 30-byte edit drift); no variant was exact.
// - Corrected the current attribute from element 0xb8 to element 0x2e because
//   the oracle loads byte offset +0xb8; positional diff stayed 71 and edit drift
//   improved to 28 bytes.
// - Direct receiver/raw-pointer/direct-delta and assignment/reference probes
//   did not reproduce the oracle's fild-before-fld order; restored the clean
//   typed local form.
// - New claim probes: a float amount temporary and implicit conversion were
//   codegen duplicates; a void virtual return and base-typed receiver/cast were
//   also duplicates. A volatile amount made a 717-byte structural mismatch.
//   Restored the clean source after each diagnostic.
// - Replaced temporary offset aliases with the canonical sn[0xba]/sn[0xbe]
//   ownership and full managed-array prefix; emitted code stayed unchanged.
// - Exact natural form: materialize the resource delta as a float local before
//   the current-attribute float local. This restores the original fild/fld
//   order without compiler steering or opaque helpers.
// Exact candidate: size/frame/call/CFG parity and the final call's FPU order
// are exact.

extern int debug_rand(const char* file, int line);
static const char str_taitacmd_path[] =
    "C:\\msdev\\work\\age1_x1\\taitacmd.cpp";

class RGE_Master_Static_Object;
class RGE_Object_List;
class RGE_Game_World;
class TRIBE_World;
class TRIBE_Player;
class RGE_Player;
class XYZBYTEPoint;

class RGE_Object_List {
public:
    RGE_Master_Static_Object* find_by_master_id(
        long master_id, float x, float y, unsigned char use_state,
        unsigned char state, RGE_Master_Static_Object* object);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    int world_time;
    char gap_08[0x34];
    short player_count;
    char gap_3e[2];
    RGE_Player** players;
    char gap_44[0xC0];
};

class TRIBE_World : public RGE_Game_World {
public:
    char gap_104[0x19];
    unsigned char controllingComputerPlayer;
};

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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float,
                                 float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float,
                                float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(void*, void*, float, float);
    virtual void sendAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual void* make_scenario_obj(float, float, float, short, unsigned char,
                                    float);
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
    virtual unsigned char command_remove_from_group(int, int);
    virtual unsigned char command_destroy_group(int);
    virtual unsigned char command_resign(int, int);
    virtual unsigned char command_add_waypoint(float, float, float);
    virtual void* addObject(void*, int, int);
    virtual void removeObject(void*, int, int, void*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(void*, int);
    virtual void load_victory(int, long*, unsigned char);
    virtual void new_victory();

    int computerPlayerValue;
    char gap_08[0x20];
    RGE_Object_List* objects;
    char gap_2c[0x10];
    TRIBE_World* world;
    char gap_40[0x0A];
    short id;
    char gap_4c[4];
    float* attributes;

    int computerPlayer();
};

class TRIBE_Player : public RGE_Player {
public:
    virtual unsigned char command_give_attribute(int, int, float, float);
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class ManagedArrayInt {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    ManagedArrayInt objects;
};

class TribeMainDecisionAIModule;

class TribeResourceAIModule : public AIModule {
public:
    TribeMainDecisionAIModule* md;
    int numberResourcesValue;
    int resource(int type);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0x10D7C - 0x104];
    TribeResourceAIModule resourceAI;
    char gap_10E74[0x1256C - 0x10E74];
    TRIBE_Player* aiPlayer;
};

class TacticalAIModule {
public:
    virtual ~TacticalAIModule();
    char gap_04[0xEC];
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;
    ManagedArrayInt civilians;
    ManagedArrayInt civilianExplorers;
    ManagedArrayInt soldiers;
    ManagedArrayInt ungroupedSoldiers;
    ManagedArrayInt boats;
    ManagedArrayInt warBoats;
    ManagedArrayInt fishingBoats;
    ManagedArrayInt tradeBoats;
    ManagedArrayInt transportBoats;
    ManagedArrayInt artifacts;
    int sn[0xE2];
    char gap_51C[0xF9C - 0x51C];
    int lastCoopTributeGiftTime;

    void checkForCoopTributeGift();
};

void TribeTacticalAIModule::checkForCoopTributeGift()
{
    if (this->sn[0xBA] == -1) return;
    if (this->md->aiPlayer->objects->find_by_master_id(
            0x54, -1.0f, -1.0f, 0, 2, 0) == 0) return;

    int now = this->md->player->world->world_time;
    if ((now - this->lastCoopTributeGiftTime) / 1000 < this->sn[0xBA])
        return;
    this->lastCoopTributeGiftTime = now;

    TRIBE_World* world = this->md->player->world;
    if (world->controllingComputerPlayer == 0xff) {
        int i = 1;
        int num_computer = 0;
        if (world->player_count > 1) {
            do {
                if (world->players[i]->computerPlayer() == 1)
                    ++num_computer;
                ++i;
            } while (i < world->player_count);
        }
        if (num_computer == 1) {
            world->controllingComputerPlayer = this->md->player->id;
        } else {
            int pick = debug_rand(str_taitacmd_path, 0x3275) %
                            num_computer + 1;
            i = 1;
            if (world->player_count > 1) {
                do {
                    RGE_Player* other = world->players[i];
                    if (other->computerPlayer() == 1) {
                        --pick;
                        if (pick == 0)
                            world->controllingComputerPlayer = other->id;
                    }
                    ++i;
                } while (i < world->player_count);
            }
        }
    }

    int i = 0;
    int* minimum = &this->sn[0xBE];
    do {
        if (this->md->resourceAI.resource(i) > *minimum) {
            int bestCP = -1;
            float tributeAmount = 0.0f;
            int j = 1;
            if (world->player_count > 1) {
                do {
                    RGE_Player* other = world->players[j];
                    if (other->id != this->md->player->id &&
                        other->computerPlayer() != 0 &&
                        this->md->player->isAlly(j) != 0 &&
                        other->isAlly(this->md->player->id) != 0) {
                        float* attribute = other->attributes + i;
                        int minimumValue =
                            other->strategicNumber(i + 0xbe);
                        if (*attribute < (float)minimumValue &&
                            (bestCP == -1 || *attribute < tributeAmount)) {
                            bestCP = other->id;
                            tributeAmount = *attribute;
                        }
                    }
                    ++j;
                } while (j < world->player_count);
            }
            if (bestCP != -1) {
                float amount =
                    (float)(this->md->resourceAI.resource(i) - *minimum);
                TRIBE_Player* aiPlayer = this->md->aiPlayer;
                float current = aiPlayer->attributes[0x2e];
                aiPlayer->command_give_attribute(
                    bestCP, i,
                    amount,
                    current);
            }
        }
        ++i;
        ++minimum;
    } while (i < 4);
}
