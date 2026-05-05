// VA: 00429760 | TCommunications_Handler::SendGroupChatMsg(char*) | Com_hand.cpp:2774-2787 | 106 bytes
// No custom flags needed.
//
// Attempt log:
// [1] Original scratch: uses explicit fills, do-while loop, 89% diff.
// [2] With `int fill` local: no `mov eax, fill` — compiler inlines fills.
// [3] Interleaved fill & uVar2 init: same basin.
// [4] unsigned short uVar2: compiler uses ebp frame + sign-extension.
// [5] Using `int iVar1; unsigned short uVar2; unsigned long fill;` locals: same.
//
// Blocked: VC5 uses completely different codegen basin. Original saves esi,edi and uses
// edi=this, esi=uVar2, eax=fill, ebx='Y'. Our VC5 uses different register allocation
// and doesn't emit `mov eax, fill` (inlines fills), produces different stack offsets
// for DestMap, and uses different register conventions for the loop.

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
    int iVar1;
    unsigned short uVar2;
    unsigned long fill;
    unsigned char DestMap[10];

    fill = 0x4E4E4E4E;
    *(unsigned long*)&DestMap[0] = fill;
    uVar2 = 1;
    if (uVar2 <= this->MaxGamePlayers) {
        do {
            iVar1 = this->Chat->inChatGroup(uVar2);
            if (iVar1 != 0) {
                DestMap[uVar2 + 4] = 0x59;
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 <= this->MaxGamePlayers);
    }

    this->TXChat(this->Me, (char*)&DestMap[0], param_1);
}
