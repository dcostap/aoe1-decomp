#ifndef AOE1_CHAT_CONTEXT_H
class TTaunt;

class TChat {
public:
    void* HostWnd;
    int chatGroupPlayers[10];
    char* Chat[51];
    int CurrentMsgNo;
    TTaunt* taunt;

    char* GetChatMsg(int index);
};
#endif

char* TChat::GetChatMsg(int index) {
    if (index >= 0 && index <= 0x32) {
        return Chat[index];
    }
    return 0;
}
