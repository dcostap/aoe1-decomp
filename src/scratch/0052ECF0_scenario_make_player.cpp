// VA: 0052ECF0 TRIBE_World::scenario_make_player
// PDB source: tworld.cpp lines 458-470
// Baseline reconstruction: allocate a TRIBE_Player for each scenario slot,
// selecting the computer-player constructor flag only for type 4.
// Attempt log:
// - /GX is required by the original FS:[0] EH registration; it improves the
//   clean default candidate from 152 to 219 bytes and restores the CFG/body
//   basin.  /Ob0 is codegen-neutral and was not retained.
// - Nested type dispatch, switch dispatch, type-4 outer dispatch, and a
//   branch-local type-4 result were tested.  The nested type-0-first form is
//   the best natural source and matches all original calls except one merged
//   TRIBE_Player constructor site.
// - Proven ABI/layout facts retained: TRIBE_World* constructor argument,
//   RGE_Player base size 0x220, TRIBE_Player size 0x848, world arrays at
//   +0x40/+0x48.  Remaining structural gap is VC5 call factoring: rebuilt
//   code is 219 vs 255 bytes with 4/5 calls and 83.13% shape similarity.

class RGE_Master_Player;
class TRIBE_World;
class TRIBE_Player;

class RGE_Game_World {
public:
    virtual void v0();
    char gap_04[0x3C];
    TRIBE_Player** players;        // +0x40
    char gap_44[4];
    RGE_Master_Player** master_players; // +0x48
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x21C];
};

class TRIBE_Player : public RGE_Player {
public:
    char gap_220[0x628];
    virtual ~TRIBE_Player();
    TRIBE_Player(TRIBE_World* world, RGE_Master_Player* master,
        unsigned char player_id, char* name, unsigned char civ,
        unsigned char is_computer, unsigned char is_active,
        char* ai1, char* ai2, char* ai3);
};

class TRIBE_World : public RGE_Game_World {
public:
    virtual void scenario_make_player(short player_id, unsigned char master_id,
        unsigned char type, unsigned char civ, char* player_info);
};

void TRIBE_World::scenario_make_player(short player_id, unsigned char master_id,
    unsigned char type, unsigned char civ, char* player_info)
{
    TRIBE_Player* player;

    if (type == 0) {
        player = new TRIBE_Player(this, this->master_players[master_id],
            (unsigned char)player_id, player_info, master_id, 0, 1, 0, 0, 0);
    } else {
        if (type == 4) {
            player = new TRIBE_Player(this, this->master_players[master_id],
                (unsigned char)player_id, player_info, master_id, 1, 1, 0, 0, 0);
        } else {
            player = new TRIBE_Player(this, this->master_players[master_id],
                (unsigned char)player_id, player_info, master_id, 0, 1, 0, 0, 0);
        }
    }

    this->players[player_id] = player;
}
