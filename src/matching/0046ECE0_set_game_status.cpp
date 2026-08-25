// tried the direct status/resigned guard shape first
// tried the combined decompiler guard and explicit locals; mismatch stayed at the first-instruction/prolog basin
// remaining drift is the opening register load plus the base-game dispatch register order
// attempt 3: natural early-return style, inline rge_base_game, explicit local for this

#ifndef PLAYER_GROUPED_TU
class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void run(int);
    virtual void wnd_proc(int);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int);
    virtual void set_player(int);
    virtual void get_error_code(int);
    virtual void get_string(int);
    virtual void get_string2(int);
    virtual void new_scenario_header(int);
    virtual void new_scenario_info(int);
    virtual void reset_comm(int);
    virtual void send_game_options(int);
    virtual void receive_game_options(int);
    virtual void gameSummary(int);
    virtual void processCheatCode(int, int);
    virtual void notification(int, int, int, int, int);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void changeToHumanPlayer(int);
    virtual void set_game_status(unsigned char status);

    char gap_04[0x46];
    short id;
    char gap_4C[0x34];
    unsigned char game_status;
    unsigned char resigned;
    char gap_82[0x19E];

    void do_resign(int value);
};
#endif

void RGE_Player::set_game_status(unsigned char status) {
    RGE_Player* p = this;
    if (status == p->game_status) return;
    if (p->resigned && status != 2) return;
    p->game_status = status;
    if (status == 2 && !p->resigned) {
    rge_base_game->notification(6, p->id, 0, 0, 0);
    }
}
