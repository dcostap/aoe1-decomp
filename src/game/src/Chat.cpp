#include "../include/TChat.h"
#include "../include/TTaunt.h"
#include "../include/RGE_Base_Game.h"
#include "../include/globals.h"
#include <stdlib.h>
#include <string.h>
#include <new>

TChat::TChat(void* p1) {
    // Fully verified. Source of truth: chat.cpp.decomp @ 0x00423C30
    this->taunt = new (std::nothrow)
        TTaunt((rge_base_game != nullptr) ? rge_base_game->sound_system : nullptr);

    this->HostWnd = p1;

    for (int i = 0; i < 0x33; ++i) {
        this->Chat[i] = nullptr;
    }

    this->CurrentMsgNo = 0;
    for (int i = 0; i < 10; ++i) {
        this->setInChatGroup(i, 0);
    }
    this->chatGroupPlayers[0] = 0;
}

TChat::~TChat() {
    // Fully verified. Source of truth: chat.cpp.decomp @ 0x00423CD0
    this->ClearChat();
    if (this->taunt != nullptr) {
        delete this->taunt;
        this->taunt = nullptr;
    }
}

int TChat::AddChatMsg(char* param_1, char* param_2, uchar param_3) {
    // Fully verified. Source of truth: chat.cpp.decomp @ 0x00423D00
    if (param_1 == nullptr) {
        return 0;
    }
    if (param_2 == nullptr) {
        return 0;
    }

    int msgNo = this->CurrentMsgNo + 1;
    this->CurrentMsgNo = msgNo;
    if (msgNo > 0x32) {
        this->CurrentMsgNo = 0;
    }

    if (this->Chat[this->CurrentMsgNo] != nullptr) {
        free(this->Chat[this->CurrentMsgNo]);
    }

    const size_t name_len = strlen(param_1);
    const size_t msg_len = strlen(param_2);
    char* buf = (char*)calloc(name_len + msg_len + 3, 1); // "%s: %s" + '\0'
    this->Chat[this->CurrentMsgNo] = buf;
    if (buf == nullptr) {
        return 0;
    }

    sprintf(buf, "%s: %s", param_1, param_2);
    PostMessageA((HWND)this->HostWnd, 0x400, (WPARAM)0x17d5, (LPARAM)this->CurrentMsgNo);

    if (this->taunt != nullptr) {
        (void)this->taunt->PlayTauntStr(param_2, param_3);
    }

    return 1;
}

char* TChat::GetChatMsg(int param_1) {
    // Fully verified. Source of truth: chat.cpp.decomp @ 0x00423DF0
    if (param_1 >= 0 && param_1 < 0x33) {
        return this->Chat[param_1];
    }
    return nullptr;
}

void TChat::ClearChat() {
    // Fully verified. Source of truth: chat.cpp.decomp @ 0x00423E10
    for (int i = 0; i < 0x33; ++i) {
        if (this->Chat[i] != nullptr) {
            free(this->Chat[i]);
        }
        this->Chat[i] = nullptr;
    }
    this->CurrentMsgNo = 0;
}

int TChat::MaxArraySize() {
    // Fully verified. Source of truth: chat.cpp.decomp @ 0x00423E50
    return 0x32;
}

void TChat::setWindowHandle(void* p1) {
    // Fully verified. Source of truth: chat.cpp.decomp @ 0x00423E60
    this->HostWnd = p1;
}

void TChat::setInChatGroup(int param_1, int param_2) {
    // Fully verified. Source of truth: chat.cpp.decomp @ 0x00423E70
    if (param_1 > 0 && param_1 < 10) {
        this->chatGroupPlayers[param_1] = param_2;
    }
}

int TChat::inChatGroup(int param_1) {
    // Fully verified. Source of truth: chat.cpp.decomp @ 0x00423E90
    if (param_1 >= 0 && param_1 < 10) {
        return this->chatGroupPlayers[param_1];
    }
    return 0;
}

void TChat::StopSoundSystem() {
    // Fully verified. Source of truth: chat.cpp.decomp @ 0x00423EB0
    if (this->taunt != nullptr) {
        this->taunt->StopSoundSystem();
    }
}

int TChat::RestartSoundSystem(TSound_Driver* param_1) {
    // Fully verified. Source of truth: chat.cpp.decomp @ 0x00423EC0
    if (this->taunt != nullptr) {
        return this->taunt->RestartSoundSystem(param_1);
    }
    return 1;
}
