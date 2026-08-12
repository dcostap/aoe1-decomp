// VA: 0052A510 TRIBE_Game::disconnect_multiplayer_game (279 B)
// PDB source: tribegam.cpp (lines 5611-5649)
// Attempt log:
// baseline (sa83_disconnect): the prior scaffold used free functions and raw
// offsets; it was retained only as the starting build checkpoint.
// behavior (typed reconstruction): comm_handler, prog_mode, and world are the
// proven named fields at +0x18C, +0x1B0, and +0x3F4.  The wait is represented
// as the nested 500-ms / 15-second loops shown by the original CFG.
// control-flow: a positive multiplayer arm with an explicit else GameOver
// reproduces the original shared-tail branches, size, ordered calls, and CFG.
// liveness/context probes (rolled back): function-scope time locals, qualified
// base call, reordered declarations, a scoped world local, a base-pointer alias,
// flat-vs-inherited TRIBE_Game layout, and a top-level mode local all emitted
// the same 279-byte code.  The remaining 16-byte drift is only register color:
// rebuilt this/elapsed are ESI/EDI while the original uses EDI/ESI.
// follow-up probes (rolled back): full RGE_Base_Game virtual surface, declared
// TRIBE_Game destructor, complete derived-size gap, TRIBE_Game pointer/reference
// aliases, and a single natural for-loop wait form.  The typed class/layout
// context and aliases were codegen duplicates; the for-loop changed CFG/size
// (289 B) and was discarded.  No natural source probe flipped the ESI/EDI pair.
// Main-agent audit restored canonical world polymorphic ownership; the
// validated 16-byte coloring gap is unchanged.
// new context pass: added the recovered named game/screen/video derived field
// surface from the now-exact neighboring TU functions; it was a codegen
// duplicate, so the EDI-this / ESI-elapsed coloring gap remains unexplained.
// abi probe: corrected debug_timeGetTime's parameter to the PDB's char* form;
// emitted code and the 16-byte register-color gap were unchanged.
// session probes: declaration/assignment order, split world guards, enum and
// signedness spellings, inlined timestamp result, and negative/switch/positive
// control-flow forms all either duplicated the 279-byte output or broke CFG.
// A 36-case variant lab covering those axes plus derived virtual-surface sizes
// found no alternate register basin; clean source remains authoritative.

enum COMMSTATUS {
    COMMSTATUS_UNINITIALIZED = 0,
    INITIALIZED = 1,
    SERVICE_AVAILABLE = 5
};

class TCommunications_Handler {
public:
    void SendIResignMsg();
    void ShutdownGameMessages();
    int CountWaitingMessages();
    void GameOver();
    COMMSTATUS UnlinkToLevel(COMMSTATUS level);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x19];
    unsigned char game_status;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    int multiplayerGame() const;
    void disable_input();

    char gap_04[0x18C - 0x04];
    TCommunications_Handler* comm_handler;
    char gap_190[0x1B0 - 0x190];
    int prog_mode;
    char gap_1B4[0x3F4 - 0x1B4];
    RGE_Game_World* world;
    char gap_3F8[0xA24 - 0x3F8];
};

extern unsigned long debug_timeGetTime(char* file, int line);

class TRIBE_Game : public RGE_Base_Game {
public:
    // Canonical tribegam.cpp derived surface recovered from the game/screen/
    // video donors.  These named members preserve the real TU ownership while
    // leaving the disconnect body unchanged.
    void* MouseRightClickTable; // +0xA24
    int MouseRightClickTableSize; // +0xA28
    void* MouseLeftClickTable; // +0xA2C
    int MouseLeftClickTableSize; // +0xA30
    long queue_is_waiting_on_pop_counter[9]; // +0xA34
    int random_civ[9]; // +0xA58
    unsigned char tribe_game_options[0x6C]; // +0xA7C
    char testing_scenario[260]; // +0xAE8
    void* video_window; // +0xBEC
    int cur_video; // +0xBF0
    int (__stdcall *old_video_wnd_proc)(); // +0xBF4
    int video_paused; // +0xBF8
    unsigned long last_video_time; // +0xBFC
    int video_setup; // +0xC00
    int video_double_size; // +0xC04
    int video_changed_res; // +0xC08
    int video_hi_color; // +0xC0C
    long video_save_res_wid; // +0xC10
    long video_save_res_hgt; // +0xC14
    void* video_save_palette; // +0xC18
    int started_menu_music; // +0xC1C
    int show_object_id; // +0xC20
    void* game_screen; // +0xC24
    long notification_loc_x[5]; // +0xC28
    long notification_loc_y[5]; // +0xC3C
    long current_notification_loc; // +0xC50
    long current_notification_recalled; // +0xC54
    char startup_scenario[260]; // +0xC58
    char startup_game[260]; // +0xD5C
    unsigned long auto_exit_time; // +0xE60
    char save_game_name[260]; // +0xE64
    char load_game_name[260]; // +0xF68
    char timing_text2[256]; // +0x106C
    int save_humanity[9]; // +0x116C
    unsigned char quick_start_game; // +0x1190
    unsigned char gap_1191[3];
    int random_start_value; // +0x1194
    char computerNameUsed[18][10]; // +0x1198
    void* handleIdleLock; // +0x124C
    int inHandleIdle; // +0x1250

    void show_status_message(int message, char* parameter, long value);
    void disconnect_multiplayer_game();
};

void TRIBE_Game::disconnect_multiplayer_game()
{
    if (this->multiplayerGame()) {
        if (this->prog_mode == 4 || this->prog_mode == 6 ||
            this->prog_mode == 7 || this->prog_mode == 5) {
            this->comm_handler->SendIResignMsg();
            this->comm_handler->ShutdownGameMessages();

            if (this->comm_handler->CountWaitingMessages() > 0) {
                this->disable_input();
                this->show_status_message(0x4C0, 0, -1);

                unsigned long start_time = debug_timeGetTime(
                    "C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x15F8);
                unsigned long elapsed_start = start_time;

                do {
                    unsigned long now;
                    do {
                        if (this->world == 0 || this->world->game_status == 1)
                            goto disconnect_done;

                        this->comm_handler->ShutdownGameMessages();
                        now = debug_timeGetTime(
                            "C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x1601);
                    } while (now - elapsed_start < 500);

                    if (this->comm_handler->CountWaitingMessages() == 0)
                        break;
                    elapsed_start = debug_timeGetTime(
                        "C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x1605);
                } while (elapsed_start - start_time < 15000);
            }

        disconnect_done:
            this->comm_handler->GameOver();
            this->comm_handler->UnlinkToLevel(SERVICE_AVAILABLE);
        }
    } else {
        this->comm_handler->GameOver();
    }
}
