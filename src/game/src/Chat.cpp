#include "../include/TChat.h"
#include <stdlib.h>
#include <string.h>

TChat::TChat(void* p1) {
    memset(this, 0, sizeof(TChat));
    this->HostWnd = p1;
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
