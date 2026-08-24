#ifndef AOE1_CHAT_CONTEXT_H
class TTaunt {
public:
    ~TTaunt();
};

class TChat {
public:
    void* HostWnd;
    int chatGroupPlayers[10];
    char* Chat[51];
    int CurrentMsgNo;
    TTaunt* taunt;

    ~TChat();
    void ClearChat();
};
#endif

TChat::~TChat() {
    ClearChat();
    if (taunt != 0) {
        delete taunt;
    }
}
