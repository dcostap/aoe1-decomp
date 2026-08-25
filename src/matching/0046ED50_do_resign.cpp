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
    virtual void set_game_status(unsigned char);

    char gap_04[0x46];
    short id;
    short attribute_num_;
    char gap_4E[0x33];
    unsigned char resigned;

    void do_resign(int value);
};
#endif

void RGE_Player::do_resign(int value) {
    unsigned char resigned = this->resigned;
    this->resigned = 1;
    this->set_game_status(2);
    if (!resigned) {
        rge_base_game->notification(5, this->id, value, 0, 0);
    }
}
