// VA: 0052E990 TRIBE_World::setup_players (304 B)
// PDB source: tworld.cpp:355-380
// Attempt log:
// baseline: raw shim/free-function reconstruction; it missed the EH frame and
// called the player constructor through a cdecl helper.
// probe 2: natural TRIBE_World member plus typed RGE_Player_Info arrays and the
// real TRIBE_Player constructor surface; /GX is required by the original EH
// registration.  This is the canonical source reconstruction baseline.
// probes 3-6: inverted the type/useComputerPlayers dispatch, routed unknown
// types directly to the loop tail, and used a switch with case 0 before case 4;
// this recovered the original 304-byte CFG and all five ordered calls.
// probes 7-10: equivalent pointer-addition, local-byte, unsigned-byte, and
// pointer-parameter forms did not change the emitted code.  The best natural
// source remains one byte short of exactness: the dispatch load's SIB byte is
// [ebx+esi+248] instead of the original [esi+ebx+248].
// probe 15: a scoped type-table pointer was codegen-neutral.
// probe 16: a focused /GX variant lab over six natural type-table spellings
//   kept size/frame/call-set invariants but produced only the same three SIB
//   groups; no living source steering was retained.
// left in scratch: exact boundary/size/CFG/call set and all other bytes match;
// remaining drift is a single VC5 address-term encoding with no productive
// source axis found in this bounded assignment.
// Main-agent audit confirmed canonical world/player/info ownership and natural
// switch construction; no address-term steering survives in the source.
// sequential pass: direct branch-local slot stores, player-result declaration
// scope/order, short/register loop-index forms, inherited RGE_Player result
// typing, an input-pointer alias, subscript-term order, an equivalent for-loop,
// and a const dispatch local were all codegen-neutral or regressed.  The clean
// natural source remains 304B with one documented dispatch SIB byte differing.
// sequential TU pass: typed ABI and same-TU donor review found no new source
// or layout fact for the lone commutative SIB encoding; keep the natural source.
// probe 40: restored the same-TU world's proven virtual surface and declared
// setup_players at slot 24; this natural context fixes the lone SIB byte.

struct RGE_Master_Player;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x44];
};

class TRIBE_World;

class TRIBE_Player : public RGE_Player {
public:
    char gap_48[0x800];
    TRIBE_Player(TRIBE_World* world, RGE_Master_Player* master,
                 unsigned char player_id, char* name, unsigned char tribe,
                 unsigned char make_ai, unsigned char make_lists,
                 char* ai_1, char* ai_2, char* ai_3);
};

struct RGE_Player_Info {
    char name[9][65];
    char type[9];
    char tribe[9];
    char gap_25B;
    short color[9];
    char gap_26E[2];
    long player_id_hash[9];
    short player_num;
    char gap_296[2];
    char* scenario;
    void* map_info;
    short map_type;
    short map_width;
    short map_height;
    short ai_info;
    unsigned char campaign;
    char gap_2A9[3];
};

class RGE_Sound;
class TCommunications_Handler;

class RGE_Game_World {
public:
    // The same-TU world donor places setup_players at virtual slot 24 (+0x60).
    virtual unsigned char data_load_world(void*);
    virtual unsigned char data_load_terrain_tables(char*);
    virtual unsigned char data_load_players(char*);
    virtual unsigned char data_load_objects(char*);
    virtual unsigned char data_load_sounds(char*);
    virtual unsigned char data_load_color_tables(char*);
    virtual unsigned char data_load_sprites(char*);
    virtual void data_load_players_type(short, short, void*);
    virtual void data_load_effects(char*);
    virtual unsigned char data_load_map(char*, char*, char*, char*, short,
                                        short, short, RGE_Sound**, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
    virtual unsigned char init_player_type(int, short, unsigned char);
    virtual unsigned char init_player(int);
    virtual void load_player(int, unsigned char, short);
    virtual void color_table_init(int);
    virtual void terrain_tables_init(int);
    virtual void init_sounds(int, void*);
    virtual void init_sprites(int);
    virtual void map_init(int, void*);
    virtual void effects_init(int);
    virtual void master_player_init(int);
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, void*, TCommunications_Handler*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info& info);
    char gap_04[0x38];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
    char gap_44[4];
    RGE_Master_Player** master_players;
};

class TRIBE_World : public RGE_Game_World {
public:
    virtual void setup_players(RGE_Player_Info& info);
};

extern "C" int useComputerPlayers;

void TRIBE_World::setup_players(RGE_Player_Info& info)
{
    int index = 1;

    if (this->player_num > 1) {
        do {
            TRIBE_Player* player;

            char type = info.type[index - 1];
            switch (type) {
            case 0:
                player = new TRIBE_Player(this,
                    this->master_players[info.tribe[index - 1]],
                    (unsigned char)index, info.name[index - 1],
                    info.tribe[index - 1], 0, 1, 0, 0, 0);
                break;
            case 4:
                if (useComputerPlayers == 0) {
                    player = new TRIBE_Player(this,
                        this->master_players[info.tribe[index - 1]],
                        (unsigned char)index, info.name[index - 1],
                        info.tribe[index - 1], 0, 1, 0, 0, 0);
                } else {
                    player = new TRIBE_Player(this,
                        this->master_players[info.tribe[index - 1]],
                        (unsigned char)index, info.name[index - 1],
                        info.tribe[index - 1], 1, 1, 0, 0, 0);
                }
                break;
            default:
                goto next_player;
            }

            this->players[index] = player;
        next_player:
            ++index;
        } while (index < this->player_num);
    }
}
