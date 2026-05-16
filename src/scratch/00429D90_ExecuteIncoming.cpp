// 00429D90 TCommunications_Handler::ExecuteIncoming
// PDB: Com_hand.cpp:3080-3142, 485 bytes
// Attempt log:
// - v1: reconstructed on-hold message scan from packet/decompiler with local structs and member calls.
// - v2: inlined clear-entry code and rewrote around byte offset to match original EBX offset topology.
// - v3: delayed offset initialization until after multiplayer check and marked offset register to probe EBX allocation; no size improvement.
// - v4: introduced self local and restored offset zero-before-check to probe original ESI-this/EBX-zero allocation.
// - v5: tried /GX as TU-context probe; no change to compiled main .text size, removed flag.
// BLOCKER: behavior and call set are reconstructed, but VC5 is in a different register/control-flow basin and compiles the main function to 464 bytes vs original 485, so check_function cannot compare. Original keeps this in ESI and byte offset in EBX with only pno/player/dco locals; rebuilt tends to keep this in EDI or EBP and uses a stack slot for offset/pointer, producing shorter clear-entry and loop-update sequences. Need source-shape/register-allocation breakthrough around offset-vs-entry iteration and inlined clear blocks.

typedef unsigned int uint;

class TDebuggingLog;
void __cdecl Log(TDebuggingLog* log, char* fmt, ...);
int __cdecl sprintf(char* buf, const char* fmt, ...);
void operator delete(void* p);
extern TDebuggingLog* L;

static char s_clear_past[] = "+++Clearing PAST OnHold Slot=%d  Serial#%d Len=%d  From=%d  To=%d  HumanSerial#%d";
static char s_cached[] = "Cached Execute #%d  Slot#%d ";
static char s_clearing[] = "Clearing OnHold Slot=%d  Len=%d  From=%d  To=%d";

struct OnHoldEntry { void* HoldMsg; uint Serial; uint Length; uint dcoFromID; uint dcoReceiveID; uint pad14; };

class TCommunications_Handler {
public:
    char gap_0000[0x0fc5]; char TBuff[1]; char gap_0fc6[0x10e0 - 0x0fc6];
    uint Me; uint Multiplayer; char gap_10e8[0x12d8 - 0x10e8]; unsigned short MaxGamePlayers;
    char gap_12da[0x1524 - 0x12da]; OnHoldEntry* OnHold; char gap_1528[0x152c - 0x1528];
    uint playerSerial[15]; uint dcoID[15];
    int IsPlayerHuman(uint player);
    int PreprocessMessages(uint len, void* msg, uint from, uint to, int cached);
    uint ExecuteIncoming();
};

uint TCommunications_Handler::ExecuteIncoming()
{
    TCommunications_Handler* self;
    uint pno;
    uint player;
    uint* dco;
    uint offset;

    self = this;
    offset = 0;
    if (self->Multiplayer == 0) {
        return 0;
    }
    pno = 0;
    do {
        if (*(uint*)((char*)&self->OnHold->Length + offset) != 0) {
            player = 1;
            if (self->MaxGamePlayers >= 1) {
                dco = self->dcoID;
                do {
                    if (self->IsPlayerHuman(player) && player != self->Me) {
                        uint humanSerial = *(dco - 15) + 1;
                        OnHoldEntry* entry = (OnHoldEntry*)((char*)self->OnHold + offset);
                        uint serial = *(uint*)((char*)&self->OnHold->Serial + offset);
                        if (serial < humanSerial && *(uint*)((char*)&self->OnHold->dcoFromID + offset) == *dco) {
                            Log(L, s_clear_past, pno, serial, *(uint*)((char*)&self->OnHold->Length + offset), *(uint*)((char*)&self->OnHold->dcoFromID + offset), *(uint*)((char*)&self->OnHold->dcoReceiveID + offset), humanSerial);
                            if (entry->HoldMsg != 0) operator delete(entry->HoldMsg);
                            entry->HoldMsg = 0; entry->Serial = 0; entry->Length = 0; entry->dcoFromID = 0; entry->dcoReceiveID = 0;
                        }
                        if (*(uint*)((char*)&self->OnHold->Serial + offset) == humanSerial && *(uint*)((char*)&self->OnHold->dcoFromID + offset) == *dco) {
                            sprintf(self->TBuff, s_cached, humanSerial, pno);
                            Log(L, self->TBuff);
                            entry = (OnHoldEntry*)((char*)self->OnHold + offset);
                            self->PreprocessMessages(entry->Length, entry->HoldMsg, entry->dcoFromID, entry->dcoReceiveID, 1);
                            Log(L, s_clearing, pno, entry->Length, entry->dcoFromID, entry->dcoReceiveID);
                            if (entry->HoldMsg != 0) operator delete(entry->HoldMsg);
                            entry->HoldMsg = 0; entry->Serial = 0; entry->Length = 0; entry->dcoFromID = 0; entry->dcoReceiveID = 0;
                        }
                    }
                    player++;
                    dco++;
                } while (player <= self->MaxGamePlayers);
            }
        }
        offset += 0x18;
        pno++;
    } while (offset <= 0x2ef8);
    return 0;
}
