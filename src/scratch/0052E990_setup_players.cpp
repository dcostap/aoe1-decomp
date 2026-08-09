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
// left in scratch: exact boundary/size/CFG/call set and all other bytes match;
// remaining drift is a single VC5 address-term encoding with no productive
// source axis found in this bounded assignment.
// Main-agent audit confirmed canonical world/player/info ownership and natural
// switch construction; no address-term steering survives in the source.

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

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x38];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
    char gap_44[4];
    RGE_Master_Player** master_players;
};

class TRIBE_World : public RGE_Game_World {
public:
    void setup_players(RGE_Player_Info& info);
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
