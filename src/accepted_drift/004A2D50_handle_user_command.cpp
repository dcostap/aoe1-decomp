// VA: 004A2D50 TribeMPSetupScreen::handle_user_command
// scr_mps.cpp lines 1628-1924 (157 line records)
//
// Canonical reconstruction: large virtual switch over MP-setup user commands.
// Class surface follows the exact donor 004A37D0 (fillPlayers); TPanel vtable
// follows the exact 004A16E0 action surface (set_redraw at +0x20,
// handle_user_command at +0x64). Case order follows the physical body layout
// of the original (17BB, 17A4, 17D5, 17A6, 17A7, 17A8, 17A9, 17B2, 17AA,
// 17B3, 17B7, 17B6, 17B9, 17AE, default).
//
// Attempt log:
// - Baseline (full surface, do-while loops, walking checksum pointer): frame
//   0x128 vs 0x12C; message base E-0x104 confirmed from GetClientReadiness
//   out0 lea + sprintf/popup message+4 leas.
// - message[260] (not 256): exact 0x12C frame; Ghidra's [256] rounds the real
//   260-byte buffer that spans E-0x104..E-1.
// - Case 17BB: nested if(IsHost){int i=0; if(n>0){do..while}} + SINGLE return
//   after the if. All three exits (not-host, n<=0, loop-done) share one return
//   statement; VC5 tail-duplicates it into the case return + the shared 36D1
//   (ebx) return. This + the 17B9 if/else form unlocked the ebx basin that
//   hoists `mov ebx,1` before the first branch (2DC2/33D0/36AA).
// - Case 17A6: updateSummary + if(!IsHost){ if(!(sent_cd && checksums &&
//   ready)) { sync; } } + single return after the if. The INVERTED ready
//   condition (fall-through to the shared return on ready-match, sync in the
//   else) fixed the ready-match je target (3410 -> 36D1). Positive IsHost
//   early-return / explicit sync return forms regressed to 73B.
// - Case 17B9: `if (IsLobbyLaunched) { cancelScreen(1); } else {
//   handleKickedPlayer(0); } return 1;` — if/else with a single shared return
//   duplicates the ebx return into both branches (36B9/36D1) and hoists
//   `mov ebx,1` before the je (36AA). This was the basin-breaking fix.
// - 17A4: declare int i=0 before int* checksum to schedule xor esi before
//   add edi (004A2F12).
// - TPanel gap_04[0xF0] (TPanel = 0xF4) added so TribeMPSetupScreen fields
//   land at the canonical +0x72C..+0x88C offsets (was 0xF0 low).
// - resend_game_options needs a 4-byte pad at +0x888 (after scenarioCheckSum[8])
//   to land at +0x88C.
// - user locals: homes are VC5-internal and declaration-invariant (6 orders
//   tested); ready cast as (unsigned long*)&ready per Ghidra.
//
// LEFT IN SCRATCH: 6 bytes (0.2352%) of stack-home displacement drift in the
// GetClientReadiness argument block. Original homes user2@+2C, user6@+30,
// ready@+34; rebuilt keeps ready@+2C, user2@+30, user6@+34. 3 lea + 3 load
// displacement bytes only; size/frame/calls/CFG all exact (2551/2551, 769/769,
// 104/104). Declaration order, local types, scope, and check shapes were swept
// without moving the homes; the internal ordering that assigns these three
// stack homes is not reachable from the natural source forms tried.
// ACCEPTED_DRIFT: manual instruction review confirms that all six differing
// bytes are only the displacements of three independent address-taken locals
// passed to GetClientReadiness and reloaded under their corresponding semantic
// names. Calls, argument order, branches, memory effects outside this frame,
// and every later instruction are identical; only the private stack-home
// permutation differs.

#include <string.h>

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);

class TDebuggingLog {
public:
    void Log(const char* format, ...);   // 00436610 (this on stack, cdecl varargs)
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup();
    virtual void set_rect(void*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long,
                                 long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);        // +0x20
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(void*);
    virtual void draw_offset(long, long, void*);
    virtual void draw_rect2(void*);
    virtual void draw_offset2(long, long, void*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);      // +0x60
    virtual long handle_user_command(unsigned int, long); // +0x64
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(void*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    char gap_04[0xF0];       // TPanel size 0xF4
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];

    void popupOKDialog(char* title, char* panel_name, int a, int b);  // 00469F30
};

class TScreenPanel : public TEasy_Panel {
public:
    char* get_string(int id);   // 00466870
};

class TChat {
public:
    void setWindowHandle(void* hwnd);  // 00423E60
};

class TCommunications_Handler {
public:
    int IsHost();                     // 0042CB00
    int WhoAmI();                     // 0042CAF0
    int GetPlayerHumanity(unsigned int player);  // 0042CC00
    int GetClientReadiness(unsigned int index, int* out0, unsigned long* out1,
                           unsigned long* out2, unsigned long* out3, unsigned long* out4,
                           unsigned long* out5, unsigned long* out6, unsigned long* out7);  // 0042E500
    int IsPlayerReady(unsigned int player);  // 0042E580
    int SetMyReadiness(int ready, unsigned long u1, unsigned long u2, unsigned long u3,
                       unsigned long u4, unsigned long u5, unsigned long u6, unsigned long u7);  // 0042E380
    char* GetPlayerName(unsigned int player);  // 0042D0E0
    void SetWindowHandle(void* hwnd);   // 0042D490
    int IsLobbyLaunched();              // 0042D170
};

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
    virtual void send_game_options();    // +0x48
    virtual void receive_game_options(); // +0x4C

    int singlePlayerGame() const;        // 004223F0
    int numberPlayers() const;           // 00422650
    int playerTeam(int player);          // 00422660
    int playerHasCD(int player);         // 004224A0
    unsigned char playerVersion(int player);  // 004224C0
    void setPlayerVersion(int player, unsigned char version);  // 00422820
    void setPlayerTeam(int player, int team);  // 00422880
    void setPlayerHasCD(int player, int has_cd);  // 00422800
    int check_for_cd(int param);         // 0041FC90
    char* scenarioName();                // 004223E0
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int playerColor(int player);         // 005293A0
    void setPlayerColor(int player, int color);  // 005293B0
    int civilization(int player);        // 00529340
    void setCivilization(int player, int civilization);  // 00529350
    int scenarioPlayer(int player);      // 00529370
    void setScenarioPlayer(int player, int scenario_player);  // 00529380
    int start_game(int param);           // 00525D20
};

class TribeMPSetupScreen : public TScreenPanel {
public:
    char gap_478[0x2B4];          // +478 .. +72C
    int myCivilization;           // +72C
    int myScenarioPlayer;         // +730
    int myPlayerColor;            // +734
    int myPlayerTeam;             // +738
    long myScenarioChecksum;      // +73C
    char saveScenarioName[256];   // +740
    char gap_840[4];              // +840
    long saveScenarioChecksum;    // +844
    char gap_848[0x0C];           // +848 .. +854
    int sent_cd_status;           // +854
    char gap_858[4];              // +858
    int i_am_ready;               // +85C
    unsigned char defaultColor[8];  // +860
    int scenarioCheckSum[8];      // +868
    char gap_888[4];              // +888
    int resend_game_options;      // +88C

    virtual ~TribeMPSetupScreen();
    long handle_user_command(unsigned int command, long param);
    void fillPlayers();           // 004A37D0
    void fillChat(int n);         // 004A4100
    void updateSummary();         // 004A4190
    void handleKickedPlayer(int player_index);  // 004A5020
    void cancelScreen(int timed_out);          // 004A2BA0
};

extern TDebuggingLog* L;                    // 62C4FC
extern TCommunications_Handler* comm;       // 62C4C0
extern TRIBE_Game* rge_base_game;           // 62C574
extern TChat* chat;                         // 62C4B8
extern void* AppWnd;                        // 5B236C

extern int __cdecl debug_rand(char* file, int line);  // 004230A0

long TribeMPSetupScreen::handle_user_command(unsigned int command, long param)
{
    char message[260];
    int ready;
    unsigned long user6, user2, user7, user3, user1, user4;

    if (rge_base_game->singlePlayerGame()) {
        return 1;
    }

    switch (command) {
    case 0x17BB:  // COMM_SHARED_DATA_SENT
        L->Log("$$$ USER_COMMAND: COMM_SHARED_DATA_SENT (%d,%d)", command, param);
        if (comm->IsHost()) {
            int i = 0;
            if (rge_base_game->numberPlayers() > 0) {
                do {
                    if (((TRIBE_Game*)rge_base_game)->civilization(i) >= 0x32) {
                        L->Log("$$$ HOST RESET CIV+50");
                        ((TRIBE_Game*)rge_base_game)->setCivilization(i,
                            ((TRIBE_Game*)rge_base_game)->civilization(i) - 0x32);
                        this->resend_game_options = 1;
                    }
                    if (rge_base_game->playerTeam(i) >= 0x32) {
                        L->Log("$$$ HOST RESET TEAM+50");
                        rge_base_game->setPlayerTeam(i, rge_base_game->playerTeam(i) - 0x32);
                        this->resend_game_options = 1;
                    }
                    ++i;
                } while (i < rge_base_game->numberPlayers());
            }
        }
        return 1;

    case 0x17A4:  // COMM_UPDATE_PLAYERS
        L->Log("$$$ USER_COMMAND: COMM_UPDATE_PLAYERS (%d,%d)", command, param);
        {
            int changed = 0;
            if (comm->IsHost() && this->sent_cd_status == 0) {
                this->sent_cd_status = 1;
                if (rge_base_game->check_for_cd(0)) {
                    changed = 1;
                    rge_base_game->setPlayerHasCD(comm->WhoAmI() - 1, 1);
                }
            }
            if (comm->IsHost()) {
                int i = 0;
                int* checksum = this->scenarioCheckSum;
                int player;
                do {
                    player = i + 1;
                    int humanity = comm->GetPlayerHumanity(player);
                    if (comm->WhoAmI() != player && humanity == 2) {
                        comm->GetClientReadiness(player, (int*)message,
                                                 &user3, &user6, &user7,
                                                 &user1, &user4, (unsigned long*)&ready, &user2);
                        if (user3 != 0 && user3 != ((TRIBE_Game*)rge_base_game)->civilization(i)) {
                            ((TRIBE_Game*)rge_base_game)->setCivilization(i, user3);
                            changed = 1;
                        }
                        if (user6 != 0) {
                            int sp = user6 - 1;
                            if (sp != ((TRIBE_Game*)rge_base_game)->scenarioPlayer(i)) {
                                ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(i, sp);
                                changed = 1;
                            }
                        }
                        if (user7 != 0) {
                            if (user7 == 1) {
                                if (rge_base_game->playerHasCD(i) == 1) {
                                    rge_base_game->setPlayerHasCD(i, 0);
                                    changed = 1;
                                }
                            } else if (user7 == 2) {
                                if (rge_base_game->playerHasCD(i) == 0) {
                                    rge_base_game->setPlayerHasCD(i, 1);
                                    changed = 1;
                                }
                            }
                        }
                        if (user1 != 0 && user1 != ((TRIBE_Game*)rge_base_game)->playerColor(i)) {
                            ((TRIBE_Game*)rge_base_game)->setPlayerColor(i, user1);
                            changed = 1;
                        }
                        if (user4 != 0 && user4 != rge_base_game->playerTeam(i)) {
                            rge_base_game->setPlayerTeam(i, user4);
                            changed = 1;
                        }
                        if (ready != 0) {
                            *checksum = ready;
                        }
                        if (user2 != 0) {
                            rge_base_game->setPlayerVersion(i, (unsigned char)user2);
                            changed = 1;
                        }
                    } else if (humanity != 2 && humanity != 4) {
                        int r = debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x6D6) % 16 + 1;
                        if (((TRIBE_Game*)rge_base_game)->civilization(i) != r) {
                            ((TRIBE_Game*)rge_base_game)->setCivilization(i, r);
                            changed = 1;
                        }
                        if (((TRIBE_Game*)rge_base_game)->scenarioPlayer(i) != i) {
                            ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(i, i);
                            changed = 1;
                        }
                        if (rge_base_game->playerHasCD(i)) {
                            rge_base_game->setPlayerHasCD(i, 0);
                            changed = 1;
                        }
                        if (((TRIBE_Game*)rge_base_game)->playerColor(i) != this->defaultColor[i]) {
                            ((TRIBE_Game*)rge_base_game)->setPlayerColor(i, this->defaultColor[i]);
                            changed = 1;
                        }
                        if (rge_base_game->playerTeam(i) != 1) {
                            rge_base_game->setPlayerTeam(i, 1);
                            changed = 1;
                        }
                        if (rge_base_game->playerVersion(i) != 0) {
                            rge_base_game->setPlayerVersion(i, 0);
                            changed = 1;
                        }
                        *checksum = 0;
                    }
                    checksum++;
                    i = player;
                } while (player < 8);
                if (changed) {
                    rge_base_game->send_game_options();
                    this->resend_game_options = 0;
                }
            }
            this->fillPlayers();
            this->set_redraw(1);
            return 1;
        }

    case 0x17D5:  // CHAT_RECEIVED
        L->Log("$$$ USER_COMMAND: CHAT_RECEIVED (%d,%d)", command, param);
        this->fillChat(param);
        return 1;

    case 0x17A6:  // COMM_UPDATE_PARAMS
        L->Log("$$$ USER_COMMAND: COMM_UPDATE_PARAMS (%d,%d)", command, param);
        rge_base_game->receive_game_options();
        {
            int i = 0;
            if (rge_base_game->numberPlayers() > 0) {
                do {
                    if (((TRIBE_Game*)rge_base_game)->civilization(i) >= 0x32) {
                        L->Log("$$$ CIV2>50");
                        ((TRIBE_Game*)rge_base_game)->setCivilization(i,
                            ((TRIBE_Game*)rge_base_game)->civilization(i) - 0x32);
                        if (i + 1 == comm->WhoAmI()) {
                            this->myCivilization = 0;
                            L->Log("$$$ RESETTING MYCIV2");
                        }
                    }
                    if (rge_base_game->playerTeam(i) >= 0x32) {
                        L->Log("$$$ TEAM2>50");
                        rge_base_game->setPlayerTeam(i, rge_base_game->playerTeam(i) - 0x32);
                        if (i + 1 == comm->WhoAmI()) {
                            this->myPlayerTeam = 0;
                            L->Log("$$$ RESETTING MYTEAM2");
                        }
                    }
                    ++i;
                } while (i < rge_base_game->numberPlayers());
            }
        }
        if (this->myScenarioPlayer != 0) {
            if (strcmp(this->saveScenarioName, rge_base_game->scenarioName()) != 0) {
                this->myScenarioPlayer = -1;
            }
        }
        this->updateSummary();
        if (!comm->IsHost()) {
            if (!(this->sent_cd_status != 0 &&
                  this->myScenarioChecksum == this->saveScenarioChecksum &&
                  comm->IsPlayerReady(comm->WhoAmI()) == this->i_am_ready)) {
                int checksum = this->myScenarioChecksum;
                this->sent_cd_status = 1;
                this->saveScenarioChecksum = checksum;
                comm->SetMyReadiness(this->i_am_ready, 0, 0,
                                     rge_base_game->check_for_cd(0) + 1, 0, 0, checksum, 1);
            }
        }
        return 1;

    case 0x17A7:  // COMM_LAUNCH_GAME
        L->Log("$$$ USER_COMMAND: COMM_LAUNCH_GAME (%d,%d)", command, param);
        chat->setWindowHandle(AppWnd);
        comm->SetWindowHandle(AppWnd);
        ((TRIBE_Game*)rge_base_game)->start_game(0);
        return 1;

    case 0x17A8:  // COMM_CANCEL_GAME
        L->Log("$$$ USER_COMMAND: COMM_CANCEL_GAME (%d,%d)", command, param);
        this->handleKickedPlayer(0);
        return 1;

    case 0x17A9:  // COMM_HOST_EXITED
        L->Log("$$$ USER_COMMAND: COMM_HOST_EXITED (%d,%d)", command, param);
        this->handleKickedPlayer(0);
        return 1;

    case 0x17B2:  // COMM_PLAYER_DROPPED
        L->Log("$$$ USER_COMMAND: COMM_PLAYER_DROPPED (%d,%d)", command, param);
        this->handleKickedPlayer(1);
        return 1;

    case 0x17AA:  // COMM_PLAYER_KICKED
        L->Log("$$$ USER_COMMAND: COMM_PLAYER_KICKED (%d,%d)", command, param);
        this->handleKickedPlayer(1);
        return 1;

    case 0x17B3:  // COMM_OTHER_PLAYER_DROPPED
        L->Log("$$$ USER_COMMAND: COMM_OTHER_PLAYER_DROPPED (%d,%d)", command, param);
        this->fillPlayers();
        return 1;

    case 0x17B7:  // COMM_PLAYER_SERVICE_ERROR
        L->Log("$$$ USER_COMMAND: COMM_PLAYER_SERVICE_ERROR (%d,%d)", command, param);
        sprintf(message + 4, this->get_string(0x25DE), comm->GetPlayerName(param));
        this->popupOKDialog(message + 4, 0, 0x1C2, 100);
        return 1;

    case 0x17B6:  // COMM_BAD_VERSION
        L->Log("$$$ USER_COMMAND: COMM_BAD_VERSION (%d,%d)", command, param);
        sprintf(message + 4, this->get_string(0x25DD), comm->GetPlayerName(param));
        this->popupOKDialog(message + 4, 0, 0x1C2, 100);
        return 1;

    case 0x17B9:  // COMM_HOST_BUSY
        L->Log("$$$ USER_COMMAND: COMM_HOST_BUSY (%d,%d)", command, param);
        if (comm->IsLobbyLaunched()) {
            this->cancelScreen(1);
        } else {
            this->handleKickedPlayer(0);
        }
        return 1;

    case 0x17AE:  // COMM_NO_LINK
        L->Log("$$$ USER_COMMAND: COMM_NO_LINK (%d,%d)", command, param);
        this->cancelScreen(0);
        return 1;

    default:
        L->Log("$$$ USER_COMMAND: UNKNOWN (%d, %d)", command, param);
        return 1;
    }
}
