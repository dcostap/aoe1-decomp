// VA: 0042AD10 TCommunications_Handler::TXResendReply
// Com_hand.cpp
// Attempt log:
// baseline: prior worker's broad behavioral scaffold; wrong helper/call surface,
// local buffers, and non-canonical resend ownership left an 807-byte body.
// behavior: restored the proven RESENDER/MSGFORMAT_RESEND ownership, DirectPlay
// Send ABI, FastSend/TXAcknowledge/ClearTX/Purge call family, and exact log text.
// control-flow: merged the invalid-player and zero-DCOID failures through one
// binary-proven log/return tail; emitted size became 894B but the compiler still
// placed the cold tail before the post-scan decision.
// liveness: removed the persistent RESENDER pointer and used repeated typed
// slot-relative accesses; this recovered the 0x18 frame and ESI=this basin,
// reaching 896B with 727 differing bytes, 22/22 call targets, and exact early
// guard/throttle islands. Register/stack coloring in the scan and send tail
// remains broad; an explicit positive scan backedge was emitted-code duplicate.
// liveness: a stable player copy before/after the dco guard, counter declaration
// order, and early offset initialization were tested; no further useful output.
// control-flow: direct Log-and-return branches restore the original invalid-player
// push/jump block and improve the diff by 25 bytes; the inner BAD-DCOID log remains
// a relocated shared cold block, so the ordered call gap is still -1/+1.
// behavior: corrected the TX RES REP log to pass the preserved player number,
// not the transformed resend-slot offset; the oracle pushes the player register.
// This improved edit/resync shape and exact block coverage, but widened the byte
// diff because VC5 changed the early register and local layout basin.
// layout: indexing the early dcoID guard through the preserved player number was
// source-canonical but emitted-code duplicate.
// control-flow: shared error-tail and post-scan error-state forms were tested;
// both moved farther than the direct typed branches and were rolled back.
// liveness/ABI: ordinary loop locals and unsigned counter types were tested;
// both emitted identical code and are kept as the natural typed declarations.
// liveness: a separate four-byte Send result local is required to recover the
// original 0x18 frame, the send-result home, and the long exact middle islands;
// direct assignment through nosuch leaves a 0x14 frame.
// ownership: a narrow RESENDER* local in the retransmit-log block follows the
// decompiler's pRVar1 evidence and reduces the body to 907B/91.10% shape, but
// changes player/base register colors and is not positionally better than the
// direct repeated-member form (907B, 820 differing bytes).
// unresolved: the first durable mismatch is the early dcoID guard (the oracle
// uses cmp [player slot],zero-reg; VC5 emits load/test). The shared invalid and
// BAD-DCOID tail is now source-modeled with one binary-proven errorText label,
// but VC5 still lowers its two string selections through a moved value. The
// loop/send tail has register and argument-scheduling drift.
// follow-up H23: moving playerNumber before the guard added a call and a 0x1C
// frame; restored the post-guard copy. H24/H25: the shared error tail reached
// 901B/797-diff with separate Send result; reversed equality was codegen duplicate.
// H27/H36/H38: persistent, branch-local, and late RESENDER aliases worsened the
// frame or shape. H29/H31: reusing nosuch.Serialno reached 723 diff but lost the
// 0x18 frame. H32: separate Send result with the shared tail and direct record
// accesses reaches 906B/0x18, 84.70% shape, 22/22 calls, and 717 differing
// bytes. H34 reordering the transformed player worsened 826 diff; H39's reviewed
// char* ShowReturn ABI and H40's named packet-length temporary were duplicates.
// Current source is unresolved and retains no accepted-drift residue.

typedef unsigned int uint;

#if !defined(COM_HAND_TU_CONTEXT)
class TDebuggingLog {
public:
    void Log(char* fmt, ...);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Comm_Error {
public:
    void ShowReturn(long result, char* text);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class IDirectPlay3 {
public:
    virtual long __stdcall QueryInterface(void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall AddPlayerToGroup() = 0;
    virtual long __stdcall Close() = 0;
    virtual long __stdcall CreateGroup() = 0;
    virtual long __stdcall CreatePlayer() = 0;
    virtual long __stdcall DeletePlayerFromGroup() = 0;
    virtual long __stdcall DestroyGroup() = 0;
    virtual long __stdcall DestroyPlayer() = 0;
    virtual long __stdcall EnumGroupPlayers() = 0;
    virtual long __stdcall EnumGroups() = 0;
    virtual long __stdcall EnumPlayers() = 0;
    virtual long __stdcall EnumSessions() = 0;
    virtual long __stdcall GetCaps() = 0;
    virtual long __stdcall GetGroupData() = 0;
    virtual long __stdcall GetGroupName() = 0;
    virtual long __stdcall GetMessageCount() = 0;
    virtual long __stdcall GetPlayerAddress() = 0;
    virtual long __stdcall GetPlayerCaps() = 0;
    virtual long __stdcall GetPlayerData() = 0;
    virtual long __stdcall GetPlayerName() = 0;
    virtual long __stdcall GetSessionDesc() = 0;
    virtual long __stdcall Initialize() = 0;
    virtual long __stdcall Open() = 0;
    virtual long __stdcall Receive() = 0;
    virtual int __stdcall Send(unsigned int from, unsigned int to,
                               int flags, void* data, unsigned int size) = 0;
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
extern unsigned long debug_timeGetTime(const char* file, int line);
#endif // COM_HAND_TU_CONTEXT
extern "C" int sprintf(char* buffer, const char* format, ...);
extern void* operator new(unsigned int size);
extern void operator delete(void* ptr);
#if !defined(COM_HAND_TU_CONTEXT)
extern TDebuggingLog* L;
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern unsigned int DAT_0062cf04;
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern IDirectPlay3* DAT_0062c5ec;
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
struct RESENDER {
    unsigned long TimeSent;
    unsigned int Serial;
    char* ResendMsg;
    unsigned int Length;
    unsigned int DestMap[10];
};
#endif // COM_HAND_TU_CONTEXT


struct MSGFORMAT_RESEND {
    unsigned char Command;
    unsigned char pad[3];
    unsigned int Serialno;
};

#if !defined(COM_HAND_TU_CONTEXT)
struct COMMPLAYEROPTIONS {
    char pad_00[8];
    int ProgramState;
    char pad_0c[8];
    unsigned int dcoID[10];
    char tail[0x1D0 - 0x3C];
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0000[0xFC5];
    char TBuff[0x101];
    char gap_10C6[0x12C0 - 0x10C6];
    unsigned int TXPacketLength;
    char gap_12C4[0x1434 - 0x12C4];
    unsigned int LastSerialRepliedTX[10];
    unsigned int LastRequestRepliedTX[10];
    char gap_1484[0x14E0 - 0x1484];
    RGE_Comm_Error* Err;
    unsigned int GTDSerialNo;
    char gap_14E8[0x1514 - 0x14E8];
    unsigned char RGE_Guaranteed_Delivery;
    char gap_1515[0x1520 - 0x1515];
    RESENDER* Resend;
    char gap_1524[0x1550 - 0x1524];
    COMMPLAYEROPTIONS PlayerOptions;

    int TXResendReply(uint serial, uint player);
    long FastSend(unsigned int to, void* data, unsigned int size,
                  int param_4, int param_5);
    void TXAcknowledgeMessage(uint serial, uint player);
    void ClearTXForPlayer(uint player);
    int PurgeAcknowledgedStoredMessages();
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::TXResendReply(uint serial, uint player)
{
    unsigned int offset;
    uint playerNumber;
    unsigned long now;
    uint GoodTransmitCount;
    uint i;
    long hr;
    MSGFORMAT_RESEND nosuch;
    char* errorText;

    if (this->RGE_Guaranteed_Delivery == 0) {
        return 0;
    }

    offset = 0;
    if (this->PlayerOptions.dcoID[player] == 0) {
        errorText = "Invalid player req.";
        goto resend_failure;
    }

    playerNumber = player;

    if (DAT_0062cf04 == 0) {
        return 0;
    }
    now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0xEE7);
    if (serial == this->LastSerialRepliedTX[player]) {
        unsigned long elapsed = now - this->LastRequestRepliedTX[player];
        if (elapsed < 500) {
            L->Log("Res reply too soon #%u %u", serial, elapsed);
            return 0;
        }
    }

    this->LastSerialRepliedTX[player] = serial;
    this->LastRequestRepliedTX[player] = now;

    hr = 0;
    i = 0;
    GoodTransmitCount = 0;
    player = player * 4 + 0x10;

    do {
        if (*(unsigned int*)((char*)this->Resend + offset + 4) == serial) {
            sprintf(this->TBuff, "Found Resend Ser#%d for P#%d",
                    *(unsigned int*)((char*)this->Resend + offset + 4),
                    playerNumber);
            L->Log(this->TBuff);

            nosuch.Serialno = (uint)operator new(
                *(unsigned int*)((char*)this->Resend + offset + 0xC));
            (*(unsigned int*)((char*)this->Resend + player))--;

            if (DAT_0062cf04 == 0) {
                errorText = "+++BAD DCOID=0 NO TX";
                goto resend_failure;
            }

            unsigned long send_start =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0xF19);
            L->Log("  >TX RES REP #%d %d (%d)", playerNumber, serial,
                   *(unsigned int*)((char*)this->Resend + offset + 0xC));
            int send_result = DAT_0062c5ec->Send(
                DAT_0062cf04,
                this->PlayerOptions.dcoID[playerNumber], 0,
                *(char**)((char*)this->Resend + offset + 8),
                *(unsigned int*)((char*)this->Resend + offset + 0xC));
            unsigned long send_elapsed =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0xF28)
                - send_start;
            if (send_elapsed > 0x32) {
                L->Log("!!!TXResendReply slow - %ld msec", send_elapsed);
            }

            if (send_result == 0) {
                ++hr;
                this->TXPacketLength +=
                    *(unsigned int*)((char*)this->Resend + offset + 0xC);
            } else {
                this->Err->ShowReturn(send_result, "Resend TX");
                ++i;
            }

            nosuch.Serialno = (uint)(signed char)*(
                *(char**)((char*)this->Resend + offset + 8));
            unsigned long log_time =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0xF42);
            L->Log("COMM: >>>>> RETRANSMIT P#%d Ser#%d (Slot#%d) Cmd %d '%c' MsgLength=%d Retx left=%d timeGetTime=%d",
                   playerNumber,
                   *(unsigned int*)((char*)this->Resend + offset + 4),
                   GoodTransmitCount, nosuch.Serialno, nosuch.Serialno,
                   *(unsigned int*)((char*)this->Resend + offset + 0xC),
                   *(unsigned int*)((char*)this->Resend + player),
                   log_time);
            operator delete((void*)nosuch.Serialno);
        }

        offset += 0x38;
        ++GoodTransmitCount;
        player += 0x38;
    } while (offset <= 0x6D98);

    if ((hr == 0) && (i == 0)) {
        if (this->PlayerOptions.ProgramState == 3) {
            L->Log("+++ Did not have requested Ser#%d for P#%d ",
                   serial, playerNumber);
            nosuch.Command = 'Y';
            nosuch.Serialno = this->GTDSerialNo - 1;
            L->Log("  >TX RNSM #%d %d (%d)",
                   playerNumber, serial, 8);
            this->FastSend(this->PlayerOptions.dcoID[playerNumber], &nosuch,
                           8, 0, 0);
            L->Log("+++ TX: No such message as #%d..resynchronizing ser#s", serial);
            this->ClearTXForPlayer(playerNumber);
        }
    } else {
        L->Log("RESEND to P#%d FULFILLED:  GoodTX=%d BadTX=%d Total=%d",
               playerNumber, hr, i, hr + i);
    }

    this->PurgeAcknowledgedStoredMessages();
    return 1;

resend_failure:
    L->Log(errorText);
    return 0;
}
