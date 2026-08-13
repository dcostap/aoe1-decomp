// VA: 005420F0 RGE_Game_World::load_world
// PDB source: World.cpp lines 1021-1107
//
// Attempt log:
// - The prior raw-offset candidate had the correct 31-call surface and was
//   615 bytes, but cross-member cursors made player_num/player_time_delta
//   ownership opaque and left the first structural drift after load_map.
// - This reconstruction names the serialized world fields and map/player
//   ownership while retaining the
//   original narrow read widths and +0x34/+0xF4 dispatch surfaces.
// - Typed virtual declarations moved the candidate from 247 differing bytes
//   to 45 and then the short player-count temporary plus positive version gate
//   reached an 8-byte, 99.07% shape candidate with all 31 calls aligned.
// - Remaining bytes are localized to VC5 scheduling: `test ax, ax` versus the
//   original `cmp ax, bp`, and the players-field store occurring three bytes
//   before the original flag-preserving store position. A short-index predicate
//   regressed the whole tail and was rolled back.
// - Paused after the bounded 10-hypothesis budget; no inline asm or raw
//   absolute-address macros are retained.
// - Main-agent audit removed the player-count pointer and file-parameter byte
//   reuse. Named count/save-state locals are the plausible serialization source;
//   prior stack-home proximity remains diagnostic only.
// - This pass recovered the later 614-byte/31-call basin, with a natural
//   direct player_num gate leaving only the two-byte `test ax,ax` versus
//   original `cmp ax,bp` hunk.  Player-index comparisons, narrow-index and
//   zero aliases, declaration/initialization movement, and explicit signed or
//   unsigned 16-bit predicates either duplicated that basin or worsened the
//   tail.  A seven-case focused gate lab found no exact emitted variant.
// - Final source keeps named member ownership rather than the diagnostic
//   short-count alias; remaining drift is a compiler comparison/register
//   scheduling basin with all calls, size, frame, CFG, and memory effects
//   aligned.
// - Tested the natural same-TU guard `i < player_num` with the live zero
//   player-loop index at the first allocation gate; VC5 widened the compare,
//   shifted the hunk earlier, and regressed to 244 differing bytes. Rolled back.
// - A separate short initial-index local, a union alias for the 16/32-bit loop
//   index, and a cached short count all reproduced the 2-byte test basin.
// - Reusing the cleared old_time field as the zero RHS widened the first load
//   and regressed to 247 bytes. Restored the natural direct player_num guard.

extern "C" void __cdecl rge_read(int, void*, int);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);

struct RGE_Unified_Visible_Map {
    void suppress_updates(int);
};

struct RGE_Map {
    virtual ~RGE_Map();
    void load_map(int);
    char gap_04[0x8DC4];
    RGE_Unified_Visible_Map* unified_vis_map; // +0x8DC8
};

struct RGE_Player {
    void load_info(int);
};

struct RGE_Base_Game {
    virtual ~RGE_Base_Game();
    int singlePlayerGame();
    float get_game_speed();
};

extern RGE_Base_Game* rge_base_game;
extern float save_game_version;
extern float DAT_00577a10;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void create_player(int file, int type, int index); // +0x34
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDC();
    virtual void vE0();
    virtual void vE4();
    virtual void vE8();
    virtual void vEC();
    virtual void vF0();
    virtual void load_player_data(int file, RGE_Game_World* world); // +0xF4
    unsigned long world_time;       // +0x04
    unsigned long old_world_time;   // +0x08
    unsigned long world_time_delta; // +0x0C
    float timer;                    // +0x10
    unsigned long old_time;         // +0x14
    float game_speed;               // +0x18
    unsigned char temp_pause;       // +0x1C
    unsigned char game_state;       // +0x1D
    unsigned char game_end_condition; // +0x1E
    char gap_1F[0x9];
    RGE_Map* map;                   // +0x28
    char gap_2C[0x10];
    short player_num;               // +0x3C
    char gap_3E[2];
    RGE_Player** players;           // +0x40
    char gap_44[0x24];
    int next_object_id;             // +0x68
    int next_reusable_object_id;    // +0x6C
    char gap_70[8];
    int random_seed;                // +0x78
    short current_player;           // +0x7C
    char gap_7E[6];
    int field_84;                   // +0x84
    char gap_88[0x1C];
    int campaign;                   // +0xA4
    int campaign_player;            // +0xA8
    int campaign_scenario;          // +0xAC
    int player_turn;                // +0xB0
    unsigned long player_time_delta[9]; // +0xB4
    char gap_D8[0x24];
    int currentUpdateComputerPlayer; // +0xFC
    int difficultyLevelValue;       // +0x100

    unsigned char load_world(int file);
    void initializePathingSystem();
    void update_mutual_allies();
};

unsigned char RGE_Game_World::load_world(int file) {
    int i;
    unsigned long* p;
    int count;
    int player_type;
    int f = file;
    unsigned char saved_game_state;

    this->game_state = 2;
    this->game_end_condition = 0;
    rge_read(f, &this->world_time, 4);
    rge_read(f, &this->old_world_time, 4);
    rge_read(f, &this->world_time_delta, 4);
    rge_read(f, &this->field_84, 4);
    rge_read(f, &this->timer, 4);
    rge_read(f, &this->game_speed, 4);
    rge_read(f, &this->temp_pause, 1);
    rge_read(f, &this->next_object_id, 4);
    rge_read(f, &this->next_reusable_object_id, 4);
    rge_read(f, &this->random_seed, 4);
    rge_read(f, &this->current_player, 2);

    rge_read(f, &this->player_num, 2);
    rge_read(f, &saved_game_state, 1);
    rge_read(f, &this->campaign, 4);
    rge_read(f, &this->campaign_player, 4);
    rge_read(f, &this->campaign_scenario, 4);
    rge_read(f, &this->player_turn, 4);

    p = this->player_time_delta;
    count = 9;
    do {
        rge_read(f, p, 4);
        p++;
        count--;
    } while (count != 0);

    i = 0;
    this->old_time = 0;
    this->map->load_map(f);
    this->initializePathingSystem();
    this->currentUpdateComputerPlayer = -1;

    if (0 < this->player_num) {
        this->players = (RGE_Player**)calloc(4, this->player_num);
        if (0 < this->player_num) {
            do {
                rge_read(f, &player_type, 1);
                this->create_player(f, player_type, i);
                i++;
            } while (i < this->player_num);
        }
    }

    this->update_mutual_allies();
    this->map->unified_vis_map->suppress_updates(1);
    i = 0;
    if (0 < this->player_num) {
        do {
            this->players[i]->load_info(f);
            i++;
        } while (i < this->player_num);
    }
    this->map->unified_vis_map->suppress_updates(0);
    this->load_player_data(f, this);

    if (save_game_version >= DAT_00577a10) {
        rge_read(f, &this->difficultyLevelValue, 4);
    } else {
        this->difficultyLevelValue = -1;
    }
    if (rge_base_game->singlePlayerGame()) {
        this->game_speed = rge_base_game->get_game_speed();
    }
    this->game_state = saved_game_state;
    return 1;
}
