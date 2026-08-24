// VA: 0049BF50 command_chat (192B)
// scr_game.cpp, /GX
// Baseline reconstruction: single-player quick-chat fallback, the resigned/
// defeated multiplayer warning, and the normal message dialog construction.
// Attempt log:
// - Baseline natural command flow matched 192/192 bytes.
// - Restored the proven TScreenPanel/TEasy_Panel/TPanel hierarchy and explicit
//   base size; emitted code stayed an exact match.
// FLAGS: config/flags/0049BF50_command_chat.rsp retains /GX for the observed
// exception-registration frame.

#if !defined(SCR_GAME_TU_CONTEXT)
class TMessagePanel {
public:
    void show_message(int kind, const char* msg);
};

class TPanel {
public:
    char bytes[0xF4];
    const char* get_string(int id, int a, int b, int c, int d, int e);
};

class TEasy_Panel : public TPanel {
public:
    char bytes[0x478 - 0xF4];
};

class TScreenPanel : public TEasy_Panel {};

class TribeSendMessageDialog {
public:
    char bytes[0x54C];
    TribeSendMessageDialog(TScreenPanel* screen);
};

class RGE_Base_Game {
public:
    char gap[0x1B0];
    int prog_mode;
    int singlePlayerGame();
};

extern RGE_Base_Game* rge_base_game;
void* __cdecl operator new(unsigned int);

class TRIBE_Screen_Game : public TScreenPanel {
public:
    char gap1[0x544 - 0x478];
    TMessagePanel* message_panel;
    char gap2[0x7B4 - 0x548];
    int field_7B4;

    void command_quick_chat();
    void command_chat();
};
#endif

void TRIBE_Screen_Game::command_chat() {
    if (rge_base_game->singlePlayerGame()) {
        command_quick_chat();
        return;
    }
    if (field_7B4 == 0 && rge_base_game->prog_mode == 5) {
        const char* msg = get_string(0xBFE, 0x32, 0, 0, 0, 0);
        message_panel->show_message(1, msg);
        return;
    }
    new TribeSendMessageDialog(this);
}
