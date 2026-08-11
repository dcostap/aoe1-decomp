// 00502D50 TribeTacticalAIModule::checkForCoopAttack
// Attempt log:
// 1: Natural reconstruction from asm: timing gate, random coop-player choice, per-player attack-order checks; broad mismatch due extra locals and /100 divisor.
// 2: Modeled current object as RGE_Player with player_list at +3c and /1000 timing; optimized too small (416-byte .text), wrong prolog/register allocation.
// 3: Tried explicit self/ai locals: still optimized too small.
// 4: Tried /Ob0: still optimized too small; removed flag.
// 5: Tried /Od: 89.58% broad mismatch from first byte; removed flag.
// BLOCKER: behavior is mostly reconstructed, but VC5 source shape/local topology is wrong. Natural high-level version collapses to 416 bytes; extra-local version has correct size but wrong prolog/register allocation and broad cascade. Need recover original one-local topology: `push ecx`, save `this` in EBP, EDI as PlayerList, EBX as loop index/local slot, with `/1000` timing magic 0x10624DD3.
// Probe 2: replaced the decompiler-shaped UnitAIModule/UnitObject chain with
// canonical md->player->world ownership and direct member expressions, avoiding
// a saved md/object temporary across the virtual calls.
// Probe 3: restored the complete 0x104-byte RGE_Game_World base; the derived
// controllingComputerPlayer byte then landed at its proven +0x11D offset and
// the canonical source matched all 480 bytes.
// Probe 5: made the debug source-file path a period-style local string literal;
// emitted code remained exact and the source no longer depends on a fabricated
// external path symbol.

extern int debug_rand(const char* file, int line);
static const char str_taitacmd_path[] =
    "C:\\msdev\\work\\age1_x1\\taitacmd.cpp";

class RGE_Player;

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
    virtual void set_game_status(unsigned char value);
    virtual void do_resign(int value);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int value);
    virtual int isEnemy(int playerId);
    virtual int isAlly(int playerId);
    virtual int isNeutral(int playerId);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int playerId, int stance);
    virtual void loadAIInformation(char* p1, char* p2, char* p3, int p4, int p5);
    virtual void sendUnitAIOrder(int p1, int p2, int p3, int p4, int p5,
                                 float p6, float p7, float p8, float p9,
                                 int p10, int p11, int p12);
    virtual void processAIOrder(int p1, int p2, int p3, int p4, int p5,
                                float p6, float p7, float p8, float p9,
                                int p10, int p11, int p12);
    virtual void kickAI(int value);
    virtual int strategicNumber(int value);
    virtual void sendGameOrder(void* p1, void* p2, float p3, float p4);
    virtual void sendAddWaypointCommand(int p1, void* p2, int p3);
    virtual void processAddWaypointCommand(int p1, void* p2, int p3);
    virtual void sendPlayCommand(int p1, int* p2, int p3, int p4, int p5);
    virtual void sendPlayCommand(int p1, int p2, int p3);
    virtual int sendAICommand(int playerId, int action, int p1, int p2, int p3);
    int computerPlayerValue;
    char gap_08[0x34];
    TRIBE_World* world;
    char gap_40[0x0a];
    short id;
    int computerPlayer();
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xec];
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
};

class TacticalAIModule {
public:
    virtual ~TacticalAIModule();
    char gap_04[0xec];
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;
    char gap_0f4[0x4A4 - 0x0F4];
    int coopAttackEnabled;
    int coopAttackInterval;
    char gap_4ac[0x0FA0 - 0x4AC];
    int lastCoopAttackTime;
    void checkForCoopAttack(int p1, int p2, int p3);
};

void TribeTacticalAIModule::checkForCoopAttack(int p1, int p2, int p3)
{
    if (this->coopAttackEnabled != 1) return;

    int now = this->md->player->world->world_time;
    if ((now - this->lastCoopAttackTime) / 1000 < this->coopAttackInterval) return;
    this->lastCoopAttackTime = now;

    TRIBE_World* world = this->md->player->world;
    if (world->controllingComputerPlayer == 0xff) {
        int num_computer = 0;
        int i = 1;
        if (world->player_count > 1) {
            do {
                if (world->players[i]->computerPlayer() == 1) ++num_computer;
                ++i;
            } while (i < world->player_count);
        }
        if (num_computer == 1) {
            world->controllingComputerPlayer = this->md->player->id;
        } else {
            int pick = debug_rand(str_taitacmd_path, 0x32f1) % num_computer + 1;
            i = 1;
            if (world->player_count > 1) {
                do {
                    RGE_Player* other = world->players[i];
                    if (other->computerPlayer() == 1) {
                        --pick;
                        if (pick == 0) world->controllingComputerPlayer = other->id;
                    }
                    ++i;
                } while (i < world->player_count);
            }
        }
    }

    int idx = 1;
    if (world->player_count <= 1) return;
    do {
        RGE_Player* other = world->players[idx];
        if (other->id != this->md->player->id &&
            other->computerPlayer() != 0 &&
            this->md->player->isAlly(idx) != 0 &&
            other->isAlly(this->md->player->id) != 0) {
            if ((this->md->player->id < other->id &&
                 other->id != world->controllingComputerPlayer) ||
                this->md->player->id == world->controllingComputerPlayer) {
                other->sendAICommand(this->md->player->id, 2, p1, p2, p3);
            }
        }
        ++idx;
    } while (idx < world->player_count);
}
