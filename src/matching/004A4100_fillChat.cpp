// VA: 004A4100 TribeMPSetupScreen::fillChat
// scr_mps.cpp lines 2209-2232
//
// Attempt log:
// - Initial scratch used free-function wrappers and chatBox at +0; behavior was close but call/register surface was wrong.
// - SpruceGlow MATCH: use natural member calls and place `chatBox` at +0x618. Keep `need_scroll` as an int computed
//   from `lines > 0 && bot_line == lines - 1`; VC5 uses EDI and preserves the expected reloads of `chatBox`.
// Result: MATCH locally with `python tools/check_function.py --va 004A4100`.

#ifndef SCR_MPS_TU_CONTEXT

class RGE_Base_Game {
public:
    int singlePlayerGame();
};

class TChat {
public:
    char* GetChatMsg(int n);
};

class TTextPanel {
public:
    char gap_00[0xFE];
    short bot_line;

    int numberLines();
    int delete_line(long index);
    int word_wrap_append(char* msg);
    void scroll(unsigned char a, int b, int c);
};

extern RGE_Base_Game* rge_base_game;
extern TChat* chat;

class TribeMPSetupScreen {
public:
    char gap_00[0x618];
    TTextPanel* chatBox;

    void fillChat(int n);
};

#endif

void TribeMPSetupScreen::fillChat(int n) {
    if (!rge_base_game->singlePlayerGame()) {
        int lines = this->chatBox->numberLines();
        int need_scroll = (lines > 0 && this->chatBox->bot_line == lines - 1);
        if (lines >= 100) {
            this->chatBox->delete_line(0);
        }
        this->chatBox->word_wrap_append(chat->GetChatMsg(n));
        if (need_scroll) {
            this->chatBox->scroll(7, 0, 1);
        }
    }
}
