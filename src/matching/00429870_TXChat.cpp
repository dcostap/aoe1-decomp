// 00429870 TCommunications_Handler::TXChat (Com_hand.cpp:2815-2869)
// Attempt log:
// 1: Natural struct/source, member calls, strlen+strncpy: 42.70% diff; this kept in EDI, Log emitted extra this arg.
// 2: Make Log a cdecl free function: improves to 36.40%, but this still EDI and destMap EBP.
// 3: Add explicit self/dest locals: no register improvement; still EDI/EBP split.
// 4: Replace hand-coded length loop with strlen(): improves to 24.49%; remaining starts at len kept in EDI vs original ECX/stack.
// 5: Use cht.len for post-copy size expressions: improves to 17.30%; remaining zero terminator scheduled after Log pushes and xor before setcc.
// 6: Move terminator before ProgramState compare: no codegen change.
// 7: bool joinNow: no codegen change.
// 8: char ternary: no codegen change.
// 9: Separate join local worsened to 18.65%; rolled back.
// 10: Volatile terminator store worsened to 19.10%; rolled back.
// 11: Moving terminator after Log slightly improved edit diff but incorrectly scheduled it before CommOut; rolled back.
// 12: Removing self/dest locals made no difference from best 17.30%.
// 13: Spell joinNow assignment as explicit if/else.

extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
extern void* L;

class TChat {
public:
    int AddChatMsg(char* name, char* text, int flag);
};

class RGE_Comm_Error {
public:
    void ShowReturn(long code, const char* where);
};

extern "C" void __cdecl Log(void* obj, const char* fmt, ...);

struct MSGFORMAT_CHAT_LOCAL {
    unsigned char from;       // +0
    char dest[11];            // +1, player-indexed
    unsigned int len;         // +0x0c
    unsigned char joinNow;    // +0x10
    char msg[256];            // +0x11
};

class TCommunications_Handler {
public:
    char pad_0000[0x18];
    TChat* Chat;                  // +0x18
    char pad_001c[0x10E0 - 0x1c];
    int Me;                       // +0x10E0
    int Multiplayer;              // +0x10E4
    char pad_10e8[0x12C8 - 0x10e8];
    char (*FriendlyName)[128];     // +0x12C8
    char pad_12cc[0x12D8 - 0x12cc];
    unsigned short MaxGamePlayers; // +0x12D8
    char pad_12da[0x14E0 - 0x12da];
    RGE_Comm_Error* Err;           // +0x14E0
    char pad_14e4[0x1558 - 0x14e4];
    int ProgramState;              // +0x1558

    long TXChat(unsigned int player, unsigned char* destMap, char* text);
    int IsPlayerHuman(unsigned int player);
    long CommOut(int a, int type, void* data, int len, int flag);
};

long TCommunications_Handler::TXChat(unsigned int player, unsigned char* destMap, char* text)
{
    MSGFORMAT_CHAT_LOCAL cht;
    if (this->Multiplayer == 0) {
        this->Chat->AddChatMsg(this->FriendlyName[player], text, 1);
        Log(L, "Local chat single player add: %s", text);
        return 0;
    }

    if (player > (unsigned int)this->MaxGamePlayers) {
        return 0x80004005;
    }

    unsigned int i = 1;
    if ((unsigned int)this->MaxGamePlayers >= i) {
        do {
            if (this->IsPlayerHuman(i) && destMap[i] == 'Y') {
                cht.dest[i] = 'Y';
            } else {
                cht.dest[i] = 'N';
            }
            i++;
        } while (i <= (unsigned int)this->MaxGamePlayers);
    }

    if (cht.dest[this->Me] == 'Y') {
        this->Chat->AddChatMsg(this->FriendlyName[player], text, 1);
        Log(L, "Local chat add: %s", text);
    }

    unsigned int len = strlen(text);
    if (len > 0xff) {
        len = 0xff;
    } else {
        len = strlen(text);
    }

    cht.from = (unsigned char)player;
    cht.len = len;
    strncpy(cht.msg, text, len + 1);
    cht.msg[255] = 0;
    if (this->ProgramState == 3) {
        cht.joinNow = 1;
    } else {
        cht.joinNow = 0;
    }
    Log(L, "  >TX CHAT '%s' (%d)", text, cht.len + 0x16);
    long ret = this->CommOut(0, 0x43, &cht, cht.len + 0x16, 0);
    this->Err->ShowReturn(ret, "TXChat()");
    return ret;
}
