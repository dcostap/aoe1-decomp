// VA: 0041EBC0 RGE_Base_Game::setup_palette (41 B)
// PDB source: basegame.cpp, lines 2383-2398

#ifndef BASEGAME_GROUPED_TU
class RGE_Prog_Info {
public:
    char gap_000[0x66E];
    char pal_file[261];
};

class TPanelSystem {
public:
    void* get_palette(char* name, long id);
};
extern TPanelSystem panel_system;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    virtual void* get_view_panel();
    virtual void* get_map_panel();
    virtual void* new_scenario_header(void*);
    virtual void* new_scenario_header(int);
    virtual void* new_scenario_info(int);
    virtual void notification(int, long, long, long, long);
    virtual int reset_comm();
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual char* gameSummary();
    virtual int processCheatCode(int, char*);
    virtual int setup_music_system();
    virtual void shutdown_music_system();
    virtual int setup();
    virtual int setup_cmd_options();
    virtual int setup_class();
    virtual int setup_main_window();
    virtual int setup_graphics_system();
protected:
    virtual int setup_palette();
public:
    char gap_004[0x08];
    RGE_Prog_Info* prog_info;
    void* prog_window;
    int prog_ready;
    int prog_active;
    void* prog_palette;
};
#endif

int RGE_Base_Game::setup_palette()
{
    void* result = panel_system.get_palette(this->prog_info->pal_file, 0xC544);
    this->prog_palette = result;
    return result != 0;
}
