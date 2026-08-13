// VA: 0050A1D0 TRIBE_Command::do_command_game
// Source: tcommand.cpp lines 531-665
// Attempt log:
// 1: broad natural switch reconstruction from packet; models simple command cases and restart/new-game cleanup path approximately; compiles too small (640 vs 661).
// 2: tried /GX because original has SEH/EH prologue; no size/prologue change in this harness with the fake ctor surface, flag removed.
// 3-10: fake helper names, raw absolute globals, and an omitted status-message constructor left the call multiset and EH source model wrong; retained only as prior negative evidence.
// Current baseline: restored the binary-proven command mapping, named globals, real member/helper surfaces, and a natural TRIBE_Screen_Status_Message new-expression before codegen probes.
// 11: exact RGE/TRIBE/panel/communications names plus real virtual slots recovered all 30 ordered calls; /GX and the status-message constructor restored the 0x108 EH frame.
// 12: reordered switch cases to the original 5,0,1,8,2,4,6,7 source order and restored default; output is 661 B with 185 instructions, 30/30 calls, exact CFG, and 196 strict bytes.
// Current pause: remaining drift is dominated by standalone unresolved data/string relocations (extern globals and literals emit zero-address placeholders instead of original absolute data); raw absolute-address macros are disallowed by policy. A localized short-register difference remains in TRIBE_World::cheat.
// Main-agent audit removed the diagnostic +4 formatting-buffer window and restored
// compiler-owned polymorphic world ownership. The direct buffer is authoritative.
// 13: tested the repeated donor RGE_Base_Game* type for 0062C574 with explicit
// TRIBE_Game casts; the emitted code was a duplicate, so the direct TRIBE_Game*
// declaration was restored. Standalone compilation cannot bind this data symbol.
// 14: removed the unused status-pointer void-use; emitted code was unchanged, so the natural result lifetime is not the remaining drift.

#include <stdio.h>

struct TRIBE_Command_Game {
    unsigned char command;
    unsigned char game_command;
    short var1;
    short var2;
    unsigned char gap_06[2];
    float var3;
    short var4;
    unsigned char gap_0E[2];
};

class RGE_Player;
class RGE_Game_World;
class RGE_Effects;
class RGE_Base_Game;
class TRIBE_Game;
class TRIBE_World;
class TCommunications_Handler;
class TPanel;
class TEasy_Panel;
class TPanelSystem;
class TDrawSystem;

class RGE_Command {
public:
    virtual void vfunc0();
    virtual ~RGE_Command();
    virtual void vfunc8();
    virtual void vfuncC();

    RGE_Game_World* world;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
#define PLAYER_VPAD(n) virtual void vfunc##n();
    PLAYER_VPAD(04) PLAYER_VPAD(08) PLAYER_VPAD(0C)
    PLAYER_VPAD(10) PLAYER_VPAD(14) PLAYER_VPAD(18) PLAYER_VPAD(1C)
    PLAYER_VPAD(20) PLAYER_VPAD(24) PLAYER_VPAD(28) PLAYER_VPAD(2C)
    PLAYER_VPAD(30) PLAYER_VPAD(34) PLAYER_VPAD(38) PLAYER_VPAD(3C)
    PLAYER_VPAD(40) PLAYER_VPAD(44) PLAYER_VPAD(48) PLAYER_VPAD(4C)
    PLAYER_VPAD(50) PLAYER_VPAD(54) PLAYER_VPAD(58) PLAYER_VPAD(5C)
    PLAYER_VPAD(60) PLAYER_VPAD(64) PLAYER_VPAD(68) PLAYER_VPAD(6C)
    PLAYER_VPAD(70) PLAYER_VPAD(74)
#undef PLAYER_VPAD
    virtual void add_attribute_num(short attribute, float amount,
                                    unsigned char flag);

    void set_allied_victory(unsigned char flag);
    void set_relation(long player, unsigned char relation);
    void loss_if_game_on();
};

class RGE_Effects {
public:
    virtual void vfunc0();
    virtual void vfunc4();
    virtual void show_effect(short effect, RGE_Player* player);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    float timer;
    unsigned long old_time;
    float game_speed;
    unsigned char gap_1C[0x24];
    RGE_Player** players;
    unsigned char gap_44[8];
    RGE_Effects* effects;
    unsigned char gap_50[0x2C];
    short curr_player;

    void set_game_speed(float speed);
    void update_mutual_allies();
};

class RGE_Base_Game {
public:
    virtual void vfunc0();
#define BASE_GAME_VPAD(n) virtual void vfunc##n();
    BASE_GAME_VPAD(04) BASE_GAME_VPAD(08) BASE_GAME_VPAD(0C)
    BASE_GAME_VPAD(10) BASE_GAME_VPAD(14) BASE_GAME_VPAD(18) BASE_GAME_VPAD(1C)
    BASE_GAME_VPAD(20) BASE_GAME_VPAD(24) BASE_GAME_VPAD(28) BASE_GAME_VPAD(2C)
    BASE_GAME_VPAD(30) BASE_GAME_VPAD(34) BASE_GAME_VPAD(38) BASE_GAME_VPAD(3C)
#undef BASE_GAME_VPAD
    unsigned char gap_04[0x44];
    TDrawSystem* draw_system;
    unsigned char gap_4C[0x3A8];
    RGE_Game_World* world;
    unsigned char gap_3F8[0x5B0];
    int quick_build;

    virtual void notification(int type, long player, long relation,
                              long value, long reserved);
    void save_game(char* filename);
    void do_game_over();
    void set_render_all();
    void draw_window();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void close_game_screens(int destroy_game_screen);
    int save_game(char* filename);
    void do_game_over();
};

class TRIBE_World : public RGE_Game_World {
public:
    void cheat(short value, short flag);
};

class TPanel {
public:
    virtual void vfunc0();
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    TPanel* currentPanel();
    int destroyPanel(char* name);
};

class TDrawSystem {
public:
    void SetPalette(void* palette);
};

class TEasy_Panel : public TPanel {
public:
    void* get_palette();
    void popupOKDialog(long text_id, char* panel_name,
                       long body_id, long button_count);
};

class TScreenPanel : public TPanel {
public:
    virtual ~TScreenPanel();
    virtual void draw();
};

class TRIBE_Screen_Status_Message : public TScreenPanel {
public:
    unsigned char gap_04[0x474];
    void* message;
    virtual ~TRIBE_Screen_Status_Message();
    TRIBE_Screen_Status_Message(char* panel_name, char* text,
                                char* info_file, long info_id);
};

class TCommunications_Handler {
public:
    int WhoAmI();
};

extern TRIBE_Game* rge_base_game;
extern TCommunications_Handler* comm;
extern TPanelSystem panel_system;
extern FILE* actionFile;
extern FILE* DVlogf;
extern FILE* DDlogf;
extern int do_debug_random;
extern int out_of_sync2;
extern void __cdecl debug_random_write();
extern void __cdecl dump_vismap_log();

class TRIBE_Command : public RGE_Command {
public:
    void do_command_game(TRIBE_Command_Game* cmd);
};

void TRIBE_Command::do_command_game(TRIBE_Command_Game* cmd)
{
    char file_name[260];

    switch (cmd->game_command) {
    case 5:
        this->world->players[cmd->var1]->set_allied_victory(
            (unsigned char)cmd->var2);
        break;

    case 0:
        this->world->players[cmd->var1]->set_relation(
            cmd->var2, (unsigned char)cmd->var3);
        rge_base_game->notification(8, cmd->var1, cmd->var2, cmd->var4, 0);
        this->world->update_mutual_allies();
        break;

    case 1:
        this->world->set_game_speed(cmd->var3);
        break;

    case 8:
        {
        out_of_sync2 = 1;
        TRIBE_Screen_Status_Message* status =
            new TRIBE_Screen_Status_Message("Temp Screen", "", 0, -1);
        (void)status;

        panel_system.setCurrentPanel("Temp Screen", 0);
        rge_base_game->close_game_screens(1);
        if (do_debug_random != 0) {
            debug_random_write();
            dump_vismap_log();
            if (actionFile != 0) {
                fclose(actionFile);
                actionFile = 0;
            }
            if (DVlogf != 0) {
                fclose(DVlogf);
                DVlogf = 0;
            }
            if (DDlogf != 0) {
                fclose(DDlogf);
                DDlogf = 0;
            }
        }

        sprintf(file_name, "syncerr%d.gam", comm->WhoAmI());
        rge_base_game->save_game(file_name);
        this->world->players[this->world->curr_player]->loss_if_game_on();
        rge_base_game->do_game_over();

        TEasy_Panel* panel = (TEasy_Panel*)panel_system.currentPanel();
        if (panel != 0) {
            rge_base_game->draw_system->SetPalette(panel->get_palette());
            rge_base_game->set_render_all();
            rge_base_game->draw_window();
            panel->popupOKDialog(0x966, 0, 0x1C2, 100);
        }
        panel_system.destroyPanel("Temp Screen");
        break;
        }

    case 2:
        this->world->players[cmd->var1]->add_attribute_num(
            cmd->var2, cmd->var3, 0);
        break;

    case 4:
        rge_base_game->quick_build = cmd->var1;
        break;

    case 6:
        ((TRIBE_World*)this->world)->cheat(
            cmd->var1, (short)(unsigned char)cmd->var2);
        break;

    case 7:
        this->world->effects->show_effect(
            0x71, this->world->players[cmd->var1]);
        break;

    default:
        break;
    }
}
