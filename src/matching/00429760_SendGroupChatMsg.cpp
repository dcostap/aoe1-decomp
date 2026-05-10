// VA: 00429760 | TCommunications_Handler::SendGroupChatMsg(char*) | Com_hand.cpp:2774-2787
// No custom flags needed.
//
// Attempt log:
// - Prior scratch used explicit dword/dword/word fill and matched loop store/address broadly, but VC5 scheduled
//   this/index setup before the fill and used the wrong reload register at the loop bottom.
// - SpruceGlow tries 1-12: fill order variants, fill local, literal char stores, for/while/do loops, max locals,
//   call-arg locals, chat/self locals, and yes-char local did not exact; most stayed in the same scheduling basin.
// - SpruceGlow try 13 MATCH: spell the ten-byte DestMap initialization as a simple `for (int j=0; j<10; j++)`
//   byte fill with 'N'. VC5 recognizes/collapses the loop into the original `mov eax,4E4E4E4E` dword/dword/word
//   stores while preserving the original prologue/fill scheduling and ECX loop-bottom reload.
// Result: MATCH locally with `python tools/check_function.py --va 00429760`.

class TChat {
public:
    char gap_00[0x04];
    int chatGroupPlayers[10];

    int inChatGroup(int index);
};

class TCommunications_Handler {
public:
    char gap_00[0x18];
    TChat* Chat;                 // +0x18
    char gap_1C[0x10E0 - 0x1C];
    unsigned int Me;             // +0x10E0
    char gap_10E4[0x12D8 - 0x10E4];
    unsigned short MaxGamePlayers; // +0x12D8

    long TXChat(unsigned int me, char* destMap, char* msg);
    void SendGroupChatMsg(char* param_1);
};

void TCommunications_Handler::SendGroupChatMsg(char* param_1) {
    unsigned char DestMap[10];

    for (int j = 0; j < 10; j++) {
        DestMap[j] = 'N';
    }

    unsigned int i = 1;
    if (i <= this->MaxGamePlayers) {
        do {
            if (this->Chat->inChatGroup(i)) {
                DestMap[i] = 'Y';
            }
            i++;
        } while (i <= this->MaxGamePlayers);
    }

    this->TXChat(this->Me, (char*)DestMap, param_1);
}
