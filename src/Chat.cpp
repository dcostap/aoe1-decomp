// Authentic Chat.cpp source module.
// PDB owners below follow the shipped source-line order.

#include "../include/chat.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Chat.cpp only proves the sound_system member at offset 0x60.  Keep this
// incomplete view private until the complete RGE_Base_Game surface is shared.
class ChatBaseGameView {
public:
    unsigned char gap_00[0x60];
    TSound_Driver* sound_system;
};

TChat::TChat(void* host_wnd) {
    int i;

    taunt = new TTaunt(
        reinterpret_cast<ChatBaseGameView*>(rge_base_game)->sound_system);
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
    ClearChat();
    if (taunt != 0) {
        delete taunt;
    }
}

int TChat::AddChatMsg(char* speaker, char* text, unsigned char taunt_id) {
    if (speaker == 0) {
        return 0;
    }
    if (text == 0) {
        return 0;
    }

    ++CurrentMsgNo;
    if (CurrentMsgNo > 0x32) {
        CurrentMsgNo = 0;
    }

    if (Chat[CurrentMsgNo] != 0) {
        free(Chat[CurrentMsgNo]);
    }

    Chat[CurrentMsgNo] = (char*)calloc(strlen(speaker) + strlen(text) + 3, 1);
    if (Chat[CurrentMsgNo] == 0) {
        return 0;
    }

    sprintf(Chat[CurrentMsgNo], "%s: %s", speaker, text);
    PostMessageA(HostWnd, 0x400, 0x17D5, CurrentMsgNo);
    if (taunt != 0) {
        taunt->PlayTauntStr(text, taunt_id);
    }

    return 1;
}

char* TChat::GetChatMsg(int index) {
    if (index >= 0 && index <= 0x32) {
        return Chat[index];
    }
    return 0;
}

void TChat::ClearChat() {
    for (int i = 0; i < 0x33; ++i) {
        if (Chat[i] != 0) {
            free(Chat[i]);
        }
        Chat[i] = 0;
    }
    CurrentMsgNo = 0;
}

int TChat::MaxArraySize() {
    return 50;
}

void TChat::setWindowHandle(void* value) {
    HostWnd = value;
}

void TChat::setInChatGroup(int index, int value) {
    if (index > 0) {
        if (index <= 9) {
            chatGroupPlayers[index] = value;
        }
    }
}

int TChat::inChatGroup(int index) {
    if (index >= 0) {
        if (index <= 9) {
            return chatGroupPlayers[index];
        }
    }
    return 0;
}

void TChat::StopSoundSystem() {
    if (taunt != 0) {
        taunt->StopSoundSystem();
    }
}

int TChat::RestartSoundSystem(TSound_Driver* sound_driver) {
    if (taunt != 0) {
        return taunt->RestartSoundSystem(sound_driver);
    }
    return 1;
}
