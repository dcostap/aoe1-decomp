extern "C" void free(void*);
extern "C" void* calloc(unsigned int count, unsigned int size);
extern "C" unsigned int strlen(const char* text);
extern "C" int sprintf(char* buffer, const char* format, ...);
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void* hwnd, unsigned int msg, unsigned int wparam, long lparam);

#ifndef AOE1_CHAT_CONTEXT_H
class TTaunt {
public:
    int PlayTauntStr(char* text, unsigned char taunt_id);
};

class TChat {
public:
    void* HostWnd;
    int chatGroupPlayers[10];
    char* Chat[51];
    int CurrentMsgNo;
    TTaunt* taunt;

    int AddChatMsg(char* speaker, char* text, unsigned char taunt_id);
};
#endif

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
