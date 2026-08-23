// VA: 0042B270 TCommunications_Handler::CommOut
// Com_hand.cpp:4087-4459
//
// Canonical reconstruction of the period communications packet builder.  The
// header/packet records, PlayerOptions fields, DestMap, and DirectPlay Send
// slot are named owners of the binary-proven accesses; helper calls retain the
// real Com_hand.cpp member ABIs.
//
// Attempt log:
// - prior scaffold used fake C wrappers and an incorrect local class surface;
//   replaced with typed packet records, named member helpers, and DirectPlay.
// - reordered the guaranteed-delivery and final HRESULT arms to reproduce the
//   original inline block/call order; ordered calls reached 31/31.
// - reordered packet locals to the FullLength/HeaderLength/OutCommBuff/
//   packet/OutgoingCount/SyncTurn/GTDString topology; frame stayed 0x24 and
//   code size reached 1504 versus the 1505-byte original.
// - caching the DirectPlay object before Send reproduced the original single
//   global load and improved the call-site basin; signed count temporaries were
//   codegen-neutral.  A post-scan hr initialization changed the local-home
//   basin, so the best codegen source leaves that assignment out.
// - split the guaranteed-delivery accounting and StoreForResend tests.  This
//   reproduces the original second TEST EBX, exact size, and 84.24% block
//   coverage, but the function remains non-exact.
// - BINARY NOTE: the original no-send path zeros EBX at 0042B728. The prior
//   uninitialized hr model reused the data argument there, which changed the
//   return and called ShowReturn for a non-null data pointer. Keep hr initialized
//   even though this changes the wider register basin.
// - BINARY NOTE: exact donor 00426530 uses int,int,int,int,uchar,int for
//   AddCommand.  This local declaration emits the same bytes.
// - restored the typed packet-header owner for the four binary-proven fields;
//   emitted code was unchanged, so kept the natural typed source.
// - scoped send/count temporaries to mirror the original seven named stack
//   locals; first diff improved by one byte, but size and CFG parity worsened,
//   so restored the clean source.
// - left in scratch: current best is a broad local-home/CFG mismatch.  The
//   rebuilt OutCommBuff home remains [esp+1c] versus original [esp+18], while
//   the original outgoing count home is [esp+20] versus rebuilt [esp+14].
// Accepted-drift review: branch-local hr initialization now reproduces the
// executable's zero result when no recipient exists. All early errors, header
// fields, destination-map writes, 31 calls and arguments, send flags, serial
// rollback, traffic counters, resend storage, logging values, AddCommand,
// deletes, and returns match. The private header allocation has no external
// alias. Residual drift is local-home and equivalent argument scheduling.

#include <string.h>

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef long HRESULT;

class TDebuggingLog;
class RGE_Comm_Error;
class RGE_Communications_Queue;
class IDirectPlay2;

extern unsigned long debug_timeGetTime(const char* file, int line);
extern void* operator new(unsigned int size);
extern void operator delete(void* ptr);

class TDebuggingLog {
public:
    void Log(char* format, ...);
};

#define L (*(TDebuggingLog**)0x0062C4FC)
#define DIRECT_PLAY (*(IDirectPlay2**)0x0062C5EC)
#define DCO_SELF (*(ulong*)0x0062CF04)
#define COM_HAND_CPP ((const char*)0x00580BF4)

class RGE_Comm_Error {
public:
    void ShowReturn(long result, char* name);
};

class IDirectPlay2 {
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
    virtual long __stdcall Send(ulong from, ulong to, ulong flags,
                                void* data, ulong size) = 0;
};

struct MSGFORMAT_HEADER_GUARANTEED {
    uchar Command;
    uchar Sequence;
    ushort pad_02;
    ulong ExecuteOnTurn;
    ulong Serialno;
};

struct COMMPLAYEROPTIONS {
    char gap_00[8];
    int ProgramState;
    char gap_0C[0x40 - 0x0C];
    uchar CommandTurnIncrement;
    char gap_41[0x1D0 - 0x41];
};

class TCommunications_Handler {
public:
    char gap_00[0x10C8];
    ulong current_turn;
    char gap_10CC[0x10E0 - 0x10CC];
    ulong Me;
    int Multiplayer;
    char gap_10E8[0x12C0 - 0x10E8];
    ulong TXPacketLength;
    char gap_12C4[0x12D8 - 0x12C4];
    ushort MaxGamePlayers;
    char gap_12DA[0x1338 - 0x12DA];
    ulong TXPackets;
    char gap_133C[0x14E0 - 0x133C];
    RGE_Comm_Error* Err;
    ulong GTDSerialNo;
    char gap_14E8[0x14EC - 0x14E8];
    uint DestMap[10];
    uchar RGE_Guaranteed_Delivery;
    char gap_1515[0x1528 - 0x1515];
    uint PlayerHighSerialNumber[10];
    COMMPLAYEROPTIONS PlayerOptions;

    int IsPlayerHuman(uint player);
    uchar GetNextSequence(ulong turn);
    int StoreForResend(uint serial, char* message, uint length,
                       uint* dest_map);
    int AddCommand(int turn, int data, int length, int player,
                   uchar sequence, int flags);

protected:
    long CommOut(ulong to, uchar type, void* data, int length, uchar flags);
};

long TCommunications_Handler::CommOut(ulong to, uchar type, void* data,
                                      int length, uchar flags)
{
    uint full_length;
    uint header_length;
    MSGFORMAT_HEADER_GUARANTEED* out;
    char* packet;
    int outgoing_count;
    ulong sync_turn;
    char GTDString[10];
    uint i;
    int recipient_count;
    uint send_start;
    uint send_elapsed;
    long hr;
    IDirectPlay2* play;

    i = 0;
    if (this->Multiplayer == 0) {
        return 0;
    }
    if (DIRECT_PLAY == 0) {
        return 0;
    }
    if (this->GTDSerialNo == 0) {
        L->Log("SER Not set - no transmit done.");
        return 0;
    }

    out = (MSGFORMAT_HEADER_GUARANTEED*)operator new(0x0C);

    if (type == '1' || type == '2' || type == '?' || type == 'A') {
        L->Log("+++BAD Msg type -- ASSERT");
    }

    if (this->RGE_Guaranteed_Delivery != 0) {
        out->Serialno = this->GTDSerialNo;
        this->PlayerHighSerialNumber[this->Me] = this->GTDSerialNo;
        ++this->GTDSerialNo;
        header_length = 0x0C;
    } else {
        header_length = 8;
        out->Serialno = 0;
    }

    full_length = header_length + length;
    if (full_length > 0xFA0) {
        L->Log("ERROR: Full length > %d, Header=%d  Length=%d",
               0xFA0, header_length, length);
    }

    out->Sequence = 0;
    out->Command = 0;
    sync_turn = this->current_turn +
                (uint)this->PlayerOptions.CommandTurnIncrement;
    ((MSGFORMAT_HEADER_GUARANTEED*)out)->ExecuteOnTurn = sync_turn;

    uint* dest_map = this->DestMap;
    i = 0;
    do {
        if (this->IsPlayerHuman(i) == 0 || i == this->Me) {
            dest_map[i] = 0;
        } else {
            dest_map[i] = 0xF0;
        }
        ++i;
    } while (i <= this->MaxGamePlayers);

    if (type == '1' || type == '2' || type == '?' || type == 'A') {
        L->Log("ASSERT - BAD MSG TYPE");
    } else {
        out->Sequence = this->GetNextSequence(sync_turn);
        if (this->PlayerOptions.ProgramState != 5 &&
            out->Sequence == 0) {
            operator delete(out);
            return (long)0x8877010E;
        }
    }

    out->Command = type;
    packet = (char*)operator new(full_length + 1);
    memcpy(packet, out, header_length);
    if (length != 0) {
        memcpy(packet + header_length, data, length);
    }

    outgoing_count = 0;
    i = 0;
    dest_map = this->DestMap;
    do {
        if (this->IsPlayerHuman(i) == 0 || i == this->Me) {
            dest_map[i] = 0;
        } else {
            dest_map[i] = 0xF0;
            ++outgoing_count;
        }
        ++i;
    } while (i <= this->MaxGamePlayers);

    if (this->RGE_Guaranteed_Delivery != 0) {
        if (full_length == 0) {
            L->Log("+++Damaged Msg 0b");
            return (long)0x80004005;
        }
        if (outgoing_count != 0) {
            if (DCO_SELF == 0) {
                L->Log("+++BAD DCOID=0 NO TX");
                --this->GTDSerialNo;
                return (long)0x80004005;
            }

            send_start = debug_timeGetTime(COM_HAND_CPP, 0x10AA);
            play = DIRECT_PLAY;
            hr = play->Send(DCO_SELF, to, 0, packet, full_length);
            send_elapsed = debug_timeGetTime(COM_HAND_CPP, 0x10B5) -
                           send_start;
            if (send_elapsed > 0x32) {
                L->Log("!!!CommOut slow - %ld msec", send_elapsed);
            }

            if (to == 0) {
                recipient_count = 0;
                if (this->MaxGamePlayers != 0) {
                    i = 1;
                    do {
                        if (this->IsPlayerHuman(i) != 0 &&
                            i != this->Me) {
                            ++recipient_count;
                        }
                        ++i;
                    } while (i <= this->MaxGamePlayers);
                }
            } else {
                recipient_count = 1;
            }

            // BINARY NOTE: the shipped code tests the Send result twice.
            if (hr == 0) {
                this->TXPacketLength += recipient_count * full_length;
            }
            if (hr == 0) {
                this->StoreForResend(
                    out->Serialno, packet,
                    full_length,
                                     this->DestMap);
            } else {
                --this->GTDSerialNo;
                this->Err->ShowReturn(hr, "TX RGTGTD");
            }
            goto sent;
        }
        hr = 0;
    } else if (outgoing_count != 0) {
        if (DCO_SELF == 0) {
            L->Log("+++BAD DCOID=0 NO TX");
            return (long)0x80004005;
        }

        send_start = debug_timeGetTime(COM_HAND_CPP, 0x10EE);
        play = DIRECT_PLAY;
        hr = play->Send(DCO_SELF, to, 0, packet, full_length);
        send_elapsed = debug_timeGetTime(COM_HAND_CPP, 0x10F9) -
                       send_start;
        if (send_elapsed > 0x32) {
            L->Log("!!!CommOut2 slow - %ld msec", send_elapsed);
        }

        if (to == 0) {
            recipient_count = 0;
            if (this->MaxGamePlayers != 0) {
                i = 1;
                do {
                    if (this->IsPlayerHuman(i) != 0 &&
                        i != this->Me) {
                        ++recipient_count;
                    }
                    ++i;
                } while (i <= this->MaxGamePlayers);
            }
        } else {
            recipient_count = 1;
        }

        if (hr == 0) {
            this->TXPacketLength += recipient_count * full_length;
        }
    } else {
        hr = 0;
    }

sent:
    if (outgoing_count != 0) {
        if (this->RGE_Guaranteed_Delivery != 0) {
            strcpy(GTDString, "GTD");
        } else {
            strcpy(GTDString, "!GTD");
        }
        L->Log("COMM: Ser#%d %s TX To=%d Len=%d+%d HDR> Seq=%d",
               out->Serialno,
               GTDString + 4, to, length, header_length,
               out->Sequence, sync_turn,
               out->Command,
               out->Command,
               (int)(char)packet[header_length],
               (int)(char)packet[header_length], outgoing_count, hr,
               debug_timeGetTime(COM_HAND_CPP, 0x112B));
    }

    if (hr != 0) {
        this->Err->ShowReturn(hr, "TX");
    } else {
        ++this->TXPackets;
        if (type == '>') {
            this->AddCommand((int)sync_turn, (int)data, (int)length,
                             this->Me,
                             out->Sequence,
                             0);
        }
    }

    operator delete(out);
    operator delete(packet);
    return hr;
}
