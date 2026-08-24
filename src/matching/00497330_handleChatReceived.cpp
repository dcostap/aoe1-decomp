// VA: 00497330 TRIBE_Screen_Game::handleChatReceived
// scr_game.cpp:2131-2145
// Retry 2026-05-24: replace stale stub with packet-derived chat receive handler.

#include <string.h>

#if !defined(SCR_GAME_TU_CONTEXT)
class TChat {
public:
    char* GetChatMsg(int index);
};

class TDebuggingLog {
public:
    void Log(const char* fmt, ...);
};

class TMessagePanel {
public:
    void show_message(int type, char* text, int color, int a4, int a5, int a6, int a7);
};

extern TChat* chat;
extern TDebuggingLog* L;

class TRIBE_Screen_Game {
public:
    char gap_000[0x55C];
    TMessagePanel* chat_panel_0;
    TMessagePanel* chat_panel_1;
    TMessagePanel* chat_panel_2;
    TMessagePanel* chat_panel_3;
    TMessagePanel* chat_panel_4;
    TMessagePanel* chat_panel_5;
    TMessagePanel* chat_panel_6;
    TMessagePanel* chat_panel_7;
    char gap_57C[0x38];
    void* comm_handler;      // +0x5B4, object whose +4 is sender/player id
    char gap_5B8[0x16C];
    int next_chat_panel;     // +0x724

    void handleChatReceived(int chatIndex);
};
#endif

void TRIBE_Screen_Game::handleChatReceived(int chatIndex)
{
    char chat_msg[256];

    strcpy(chat_msg, chat->GetChatMsg(chatIndex));
    L->Log("$$$ RECEIVED CHAT @%u: %s", *(int*)((char*)comm_handler + 4), chat_msg);
    ((TMessagePanel**)((char*)this + 0x55C))[next_chat_panel]->show_message(3, chat_msg, 0xff, 0, 0, 0, 0);

    next_chat_panel++;
    if (next_chat_panel >= 8) {
        next_chat_panel = 0;
    }
}
