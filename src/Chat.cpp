
#include "../include/chat.h"
#include "../include/basegame.h"
#include "../include/game_globals.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

TChat::TChat(void* HostWndIn) {
    int i;

    taunt = new TTaunt(rge_base_game->sound_system);
    HostWnd = HostWndIn;

    for (i = 0; i < 51; ++i) {
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

int TChat::AddChatMsg(char* PlayerName, char* Text, unsigned char Local) {
    if (PlayerName == 0) {
        return 0;
    }
    if (Text == 0) {
        return 0;
    }

    ++CurrentMsgNo;
    if (CurrentMsgNo > 50) {
        CurrentMsgNo = 0;
    }

    if (Chat[CurrentMsgNo] != 0) {
        free(Chat[CurrentMsgNo]);
    }

    Chat[CurrentMsgNo] = (char*)calloc(strlen(PlayerName) + strlen(Text) + 3, 1);
    if (Chat[CurrentMsgNo] == 0) {
        return 0;
    }

    sprintf(Chat[CurrentMsgNo], "%s: %s", PlayerName, Text);
    PostMessageA(HostWnd, WM_USER, CHAT_RECEIVED, CurrentMsgNo);
    if (taunt != 0) {
        taunt->PlayTauntStr(Text, Local);
    }

    return 1;
}

char* TChat::GetChatMsg(int lineno) {
    if (lineno >= 0 && lineno <= 50) {
        return Chat[lineno];
    }
    return 0;
}

void TChat::ClearChat() {
    for (int i = 0; i < 51; ++i) {
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

void TChat::setWindowHandle(void* newHandle) {
    HostWnd = newHandle;
}

void TChat::setInChatGroup(int playerNum, int status) {
    if (playerNum > 0) {
        if (playerNum <= 9) {
            chatGroupPlayers[playerNum] = status;
        }
    }
}

int TChat::inChatGroup(int playerNum) {
    if (playerNum >= 0) {
        if (playerNum <= 9) {
            return chatGroupPlayers[playerNum];
        }
    }
    return 0;
}

void TChat::StopSoundSystem() {
    if (taunt != 0) {
        taunt->StopSoundSystem();
    }
}

int TChat::RestartSoundSystem(TSound_Driver* driver) {
    if (taunt != 0) {
        return taunt->RestartSoundSystem(driver);
    }
    return 1;
}
