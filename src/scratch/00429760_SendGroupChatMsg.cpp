// target: VA 00429760 TCommunications_Handler::SendGroupChatMsg(char*)
// first pass: mirror the 10-byte DestMap fill, per-player chat-group scan, and final send helper call
// probe 1: the loop/count shape is right, but VC5 is still choosing a different prolog basin with ebp/edi instead of the packet's edi/esi pattern
// probe 2: reordering the initial fill/check locals shifted the basin again but still missed the packet's exact prolog and call setup

class TChat {
public:
    char gap_00[0x04];
    int chatGroupPlayers[10];

    int inChatGroup(int index);
};

class TCommunications_Handler {
public:
    char gap_00[0x18];
    TChat* Chat; // +0x18
    char gap_1C[0x10E0 - 0x1C];
    unsigned int Me; // +0x10E0
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
    if (uVar2 > this->MaxGamePlayers) {
        return;
    }

    *(unsigned long*)&DestMap[4] = fill;
    *(unsigned short*)&DestMap[8] = 0x4E4E;
    do {
        iVar1 = this->Chat->inChatGroup(uVar2);
        if (iVar1 != 0) {
            DestMap[uVar2 + 4] = 0x59;
        }
        uVar2 = uVar2 + 1;
    } while (uVar2 <= this->MaxGamePlayers);

    this->TXChat(this->Me, (char*)&DestMap[0], param_1);
}
