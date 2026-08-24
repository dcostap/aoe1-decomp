// VA: 00511BD0 TRIBE_Player::TRIBE_Player
// Attempt log:
// initial natural constructor from packet with /GX and explicit allocated stub sizes.
// tried non-polymorphic base: lost derived vptr store and broad prologue/register diff.
// added polymorphic RGE_Player base with size 0x48/0x44 pad; restored exact field offsets and vptr context.
// tried TRIBE_Player virtual dtor: introduced extra vptr/base offset (+4), rolled back.
// used member-initializer `playerAI(0)`: fixed early order (playerAI zero before derived vptr store), moving first mismatch from 0x41 to 0x1A3.
// inverted ruin/artifact version test to `>= read else -1`: fixed mid-function branch layout.
// tried delayed create_ai initialization inside both version arms; worsened control-flow/tail, rolled back.
// ACCEPTED_DRIFT proposal: current build is same size with 545 equal bytes; only remaining drift is localized at the player-type-3 version check where rebuilt initializes/stores create_ai=1 just before the FCOMP, while original does the same MOV/STOR immediately after FCOMP and before FNSTSW. No call/control-flow/predicate/memory-effect difference (same stack local value before possible rge_read/IsHost use).

extern "C" void __cdecl rge_read(int, void*, int);
extern "C" void* __cdecl operator_new(unsigned int);
#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class TRIBE_World;
class RGE_Game_World;
class RGE_Player;
class TCommunications_Handler { public: int IsHost(); };

class TRIBE_Player_Tech { public: char pad[0x10]; TRIBE_Player_Tech(int, void*, RGE_Player*, int); };
class TRIBE_History_Info { public: char pad[0x14]; TRIBE_History_Info(int); };
class TribeMainDecisionAIModule { public: char pad[0x125c8]; TribeMainDecisionAIModule(int, char*, void*, int); };

class TRIBE_World { public: char gap[0x104]; void* tech; };

class RGE_Player {
public:
    virtual ~RGE_Player();
    char base_pad[0x44];
    RGE_Player(int, RGE_Game_World*, unsigned char);
};

class TRIBE_Player : public RGE_Player {
public:
    char player_type;      // +48
    short civ;             // +4a
    char gap_04c[0x220 - 0x4c];
    TRIBE_Player_Tech* tech_tree; // +220
    int fog_update;        // +224
    int update_count;      // +228
    int update_history_count; // +22c
    int updateCountNeedHelp; // +230
    int update_time;       // +234
    TribeMainDecisionAIModule* playerAI; // +238
    char gap_23c[0x83c - 0x23c];
    TRIBE_History_Info* history; // +83c
    float ruin_held_time;  // +840
    float artifact_held_time; // +844

    TRIBE_Player(int fd, TRIBE_World* world, unsigned char mode);
};
#endif

extern TCommunications_Handler* comm;
extern float save_game_version;

TRIBE_Player::TRIBE_Player(int fd, TRIBE_World* world, unsigned char mode)
    : RGE_Player(fd, (RGE_Game_World*)world, mode), playerAI(0)
{
    rge_read(fd, &this->player_type, 1);
    rge_read(fd, &this->update_count, 4);
    rge_read(fd, &this->updateCountNeedHelp, 4);
    rge_read(fd, &this->fog_update, 4);
    rge_read(fd, &this->update_time, 4);

    this->tech_tree = new TRIBE_Player_Tech(fd, world->tech, (RGE_Player*)this, 0);

    if (save_game_version > *(float*)0x00576818) {
        rge_read(fd, &this->update_history_count, 4);
        this->history = new TRIBE_History_Info(fd);
    } else {
        this->update_history_count = 0;
        this->history = new TRIBE_History_Info(-1);
    }

    if (save_game_version >= *(float*)0x0057681c) {
        rge_read(fd, &this->ruin_held_time, 4);
        rge_read(fd, &this->artifact_held_time, 4);
    } else {
        this->ruin_held_time = -1.0f;
        this->artifact_held_time = -1.0f;
    }

    if (this->player_type == 3) {
        int create_ai = 1;
        if (save_game_version >= *(float*)0x00576820) {
            rge_read(fd, &create_ai, 4);
        }
        if (comm->IsHost() == 1 && create_ai == 1) {
            this->playerAI = new TribeMainDecisionAIModule((int)this->civ, *(char**)((char*)this + 0x44), this, fd);
        }
        *(int*)((char*)this + 4) = 1;
    }
}
