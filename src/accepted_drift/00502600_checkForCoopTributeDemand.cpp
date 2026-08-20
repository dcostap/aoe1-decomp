// 00502600 TribeTacticalAIModule::checkForCoopTributeDemand
// Attempt log:
// - Baseline was a natural md->holder->world scaffold: 814 bytes, 0x14 frame,
//   and a direct tribute call instead of the observed player vslot +0x54.
// - Restored the period md->player->world ownership, RGE/TRIBE layouts, and
//   the full RGE_Player virtual surface; this fixed the call set and frame.
// - Split the random-player pick from the later tribute amount so VC5 could
//   reuse the original stack home for the resource cursor.
// - The original inner scan uses a positive tempRand guard around the do-loop;
//   a break/body-skip variant added a bottom tempRand test and was rolled back.
// - Best validated reconstruction: 792 bytes versus 788, 0x18 frame, all 12
//   ordered calls/relocations aligned, 96.79% shape, 70-byte edit diff. The
//   remaining structural hunk is the initial amount spill (VC5 keeps it in
//   EBX before testing instead of storing/reloading the original stack home),
//   plus the resulting four-byte tail/branch shift. Paused after the 10-probe
//   budget; no inline asm or custom flags.
// - New claim: restored the binary-shaped inner break form, but VC5 duplicated
//   an earlier 800-byte basin; restored the positive tempRand gate.
// - New claim: declaration order and a scoped tempRand initializer emitted the
//   same 792-byte code; `< 1` threshold spelling worsened shape to 476 diff.
// - New claim: the natural resource-gate conjunction worsened positional diff
//   to 472; restored the four binary-shaped gate jumps.
// - New claim: first-use initializers, reordered loop initialization, the
//   period sn[] surface, and the polymorphic tactical base were codegen
//   duplicates; restored the named clean reconstruction.
// - Remaining lead: recover the natural VC5 spill that stores coopTributeAmount
//   to [esp+10] before its first test; calls, frame, and loop body are aligned.
// Accepted-drift review: the rebuild keeps coopTributeAmount in EBX and tests
// it before initializing private loop homes. The executable stores and reloads
// the same value first. After tribute calls, the executable reloads the resource
// cursor; the rebuild relies on its callee-saved register. Loop exits use an
// inverted branch form. All 12 calls, amounts, players, and effects match.

typedef unsigned char uchar;

struct RGE_Player;

struct RGE_Game_World {
    virtual ~RGE_Game_World();
    int time;
    char gap08[0x34];
    short player_count;
    char gap3e[2];
    RGE_Player** players;
    char gap44[0xC0];
};

struct TRIBE_World : RGE_Game_World {
    char gap104[0x19];
    uchar coop_tribute_player;
};

struct RGE_Player {
    virtual ~RGE_Player();
    virtual void set_game_status(uchar);
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
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual void* make_scenario_obj(float, float, float, short, uchar, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short, float, uchar);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual void* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual uchar command_make_move(void*, float, float);
    virtual uchar command_make_work(void*, float, float);
    virtual uchar command_make_do(void*, float, float);
    virtual uchar command_stop();
    virtual uchar command_place_object(short, float, float, float);
    virtual uchar command_add_attribute(int, float);
    virtual uchar command_give_attribute(int, int, float);
    virtual uchar command_formation(int);
    virtual uchar command_stand_ground();
    virtual uchar command_create_group(int, int*, int, float);
    virtual uchar command_add_to_group(int, int, float);
    virtual uchar command_remove_from_group(int, int);
    virtual uchar command_destroy_group(int);
    virtual uchar command_resign(int, int);
    virtual uchar command_add_waypoint(float, float, float);
    virtual void* addObject(void*, int, int);
    virtual void removeObject(void*, int, int, void*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(void*, int);
    virtual void load_victory(int, long*, uchar);
    virtual void new_victory();

    int computerPlayerValue;
    char gap08_player[0x20];
    void* objects;
    char gap2c[0x10];
    TRIBE_World* world;
    char gap40[0x0A];
    short id;
    char gap4c[4];
    float* resources;

    int computerPlayer();
};

struct ResourceAI { int resource(int); };
struct MainDecision { char gap0[0xf0]; RGE_Player* player; char gapf4[0x10c88]; ResourceAI resourceAI; }; 
struct TribeTacticalAIModule {
    char gap000[0xf0];
    MainDecision* md;
    char gap0f4[0x388];
    int coopTributeInterval; // 47c
    int coopTributeAmount; // 480
    char gap484[8];
    int foodMin; int woodMin; int stoneMin; int goldMin; // 48c..
    char gap49c[0x8ec];
    int neededResourceValue[4]; // d88
    char gapd98[0x200];
    int lastCoopTributeDemandTime; // f98
    void checkForCoopTributeDemand();
};

extern "C" int __cdecl debug_rand(char*, int);

void TribeTacticalAIModule::checkForCoopTributeDemand()
{
    int tempRand;
    int pick;
    TRIBE_World* world;
    int i;
    int j;
    int amountDemandable;
    RGE_Player* player;
    int cur;
    int count;
    int* need;

    if (this->coopTributeInterval == -1) return;
    world = this->md->player->world;
    cur = world->time;
    if ((cur - this->lastCoopTributeDemandTime) / 1000 < this->coopTributeInterval) return;
    this->lastCoopTributeDemandTime = cur;

    world = this->md->player->world;
    if (world->coop_tribute_player == 0xff) {
        i = 1;
        count = 0;
        if (world->player_count > 1) {
            do {
                if (world->players[i]->computerPlayer() == 1) count++;
                i++;
            } while (i < world->player_count);
        }
        if (count == 1) {
            world->coop_tribute_player = (uchar)this->md->player->id;
        } else {
            pick = debug_rand("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0x31f0) % count + 1;
            j = 1;
            if (world->player_count > 1) {
                do {
                    player = world->players[j];
                    if (player->computerPlayer() == 1) {
                        pick--;
                        if (pick == 0) world->coop_tribute_player = (uchar)player->id;
                    }
                    j++;
                } while (j < world->player_count);
            }
        }
    }

    if (world->coop_tribute_player != (uchar)this->md->player->id) return;

    tempRand = this->coopTributeAmount;
    i = 0;
    need = this->neededResourceValue;
    do {
        if (tempRand <= 0) return;
        if (*need == 0 && this->md->resourceAI.resource(0) >= this->foodMin) goto next;
        if (*need == 1 && this->md->resourceAI.resource(1) >= this->woodMin) goto next;
        if (*need == 3 && this->md->resourceAI.resource(3) >= this->goldMin) goto next;
        if (*need == 2 && this->md->resourceAI.resource(2) >= this->stoneMin) goto next;
        if (need[4] < 0) {
            j = 1;
            if (world->player_count > 1) {
                if (tempRand > 0) {
                    do {
                    player = world->players[j];
                    if (player->id != this->md->player->id && player->computerPlayer() != 0) {
                        if (this->md->player->isAlly(j) != 0) {
                            if (player->isAlly((int)this->md->player->id) != 0) {
                                short myid = this->md->player->id;
                                if ((myid < player->id && player->id != (short)world->coop_tribute_player) || myid == (short)world->coop_tribute_player) {
                                    int res = *need;
                                    amountDemandable = (int)player->resources[res];
                                    if (amountDemandable > 50) {
                                        if (amountDemandable > tempRand) amountDemandable = tempRand;
                                        tempRand -= amountDemandable;
                                        player->sendAICommand(myid, 1, res, amountDemandable, 0);
                                    }
                                }
                            }
                        }
                    }
                        j++;
                    } while (j < world->player_count);
                }
            }
        }
next:
        need++;
        i++;
    } while (i < 4);
}
