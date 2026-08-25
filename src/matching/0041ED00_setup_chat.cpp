// attempt 2: donor-style TU context for the chat constructor/new basin
// exact match landed with /GX and the donor-style TChat context; target function stays lexically first so the bytes still belong to 0041ED00
#include "..\..\include\game_types.h"

class SoundDriver;
class TDigital;


class SoundDriver;


TChat* chat;

int RGE_Base_Game::setup_chat() {
    TChat* new_chat;

    new_chat = new TChat(this->prog_window);
    chat = new_chat;
    return new_chat != 0;
}

TChat::TChat(void* host_wnd) {
    int i;

    taunt = new TTaunt(rge_base_game->sound_system);
    HostWnd = host_wnd;

    for (i = 0; i < 0x33; ++i) {
        Chat[i] = 0;
    }

    CurrentMsgNo = 0;

    for (i = 0; i <= 9; ++i) {
        setInChatGroup(i, 0);
    }
}

TChat::~TChat() {
    if (taunt != 0) {
        delete taunt;
    }
}
