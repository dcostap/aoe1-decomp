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
// Main-agent audit restored canonical world polymorphic ownership; the
// validated 16-byte coloring gap is unchanged.

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

extern unsigned long debug_timeGetTime(const char* file, int line);

class TRIBE_Game : public RGE_Base_Game {
public:
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
