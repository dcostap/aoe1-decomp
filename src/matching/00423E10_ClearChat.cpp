extern "C" void free(void*);

#ifndef AOE1_CHAT_CONTEXT_H
class TTaunt;

class TChat {
public:
    void* HostWnd;
    int chatGroupPlayers[10];
    char* Chat[51];
    int CurrentMsgNo;
    TTaunt* taunt;

    void ClearChat();
};
#endif

void TChat::ClearChat() {
    for (int i = 0; i < 0x33; ++i) {
        if (Chat[i] != 0) {
            free(Chat[i]);
        }
        Chat[i] = 0;
    }
    CurrentMsgNo = 0;
}
