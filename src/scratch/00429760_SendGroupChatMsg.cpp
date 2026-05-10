// VA: 00429760 | TCommunications_Handler::SendGroupChatMsg(char*) | Com_hand.cpp:2774-2787 | 106 bytes
// No custom flags needed.
//
// Attempt log:
// [1] Original scratch: uses explicit fills, do-while loop, 89% diff.
// [2] With `int fill` local: no `mov eax, fill` — compiler inlines fills.
// [3] Interleaved fill & uVar2 init: same basin.
// [4] unsigned short uVar2: compiler uses ebp frame + sign-extension.
// [5] Using `int iVar1; unsigned short uVar2; unsigned long fill;` locals: same.
// [6] Natural 10-byte DestMap with dword/dword/word fill and `DestMap[i]` improved
//     stack-indexing to match loop store, but scheduler still moves `push edi/this/i`
//     before `mov eax,4E4E4E4E`, emits word immediate store before dword stores, and
//     uses eax instead of ecx for the bottom MaxGamePlayers zero-extension.
// [7] 14-byte buffer + pass `DestMap+4` confirmed decompiler's +4 view is misleading:
//     local size becomes 0x10 and offsets drift. Reverted to 10-byte buffer.
// [8] `unsigned int` loop counter fixed loop branch to unsigned `jbe`, but not register
//     choice (`eax` vs original `ecx`) or prologue/fill scheduling.
// [9] explicit `maxPlayers` local optimized to same code; /O1 probe wrong .text size.
//
// Blocked: behavior/calls/stack cleanup are understood, and current source gets the
// loop store/address family right, but isolated VC5 chooses a different scheduling basin
// for initialization and loop-bottom reloads. Original saves esi,edi and uses edi=this,
// esi=index, eax=fill, ebx='Y', then ecx for MaxGamePlayers reload. Rebuilt keeps edi/esi
// but initializes this/index before fill, stores the trailing word as an immediate first,
// and uses eax for the reload/TXChat argument setup. Broad drift, not accepted_drift.

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
    unsigned int i;
    unsigned int maxPlayers;

    *(unsigned int*)&DestMap[0] = 0x4E4E4E4E;
    i = 1;
    *(unsigned int*)&DestMap[4] = 0x4E4E4E4E;
    *(unsigned short*)&DestMap[8] = 0x4E4E;

    if (i <= this->MaxGamePlayers) {
        do {
            if (this->Chat->inChatGroup(i)) {
                DestMap[i] = 'Y';
            }
            i++;
            maxPlayers = this->MaxGamePlayers;
        } while (i <= maxPlayers);
    }

    this->TXChat(this->Me, (char*)DestMap, param_1);
}
