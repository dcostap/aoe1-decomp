// tried the direct status/resigned guard shape first
// tried the combined decompiler guard and explicit locals; mismatch stayed at the first-instruction/prolog basin
// remaining drift is the opening register load plus the base-game dispatch register order

class RGE_Base_Game;
extern RGE_Base_Game* rge_base_game;

typedef void (__stdcall *RGE_Base_Game_SetGameStatus)(RGE_Base_Game*, int, int, int, int, int);

struct RGE_Base_Game_Vtbl {
    void* slots[0x10];
    RGE_Base_Game_SetGameStatus set_game_status;
};

struct RGE_Base_Game {
    RGE_Base_Game_Vtbl* vftable;
};

class RGE_Player {
public:
    char gap_00[0x4A];
    short id;
    char gap_4C[0x34];
    unsigned char game_status;
    unsigned char resigned;
    char gap_82[0x19E];

    void set_game_status(unsigned char status);
};

void RGE_Player::set_game_status(unsigned char status) {
    RGE_Player* player = this;
    RGE_Base_Game* game = rge_base_game;

    if ((status != player->game_status) && (((player->resigned == 0 || status == 2) && (player->game_status = status, status == 2)))) {
        game->vftable->set_game_status(game, 6, player->id, 0, 0, 0);
    }
}
