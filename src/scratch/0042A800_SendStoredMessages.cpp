// VA: 0042A800 TCommunications_Handler::SendStoredMessages
// Com_hand.cpp:3567-3782
//
// Canonical reconstruction: the resend store is an array of 0x38-byte RESENDER
// records.  Serial/TimeSent/Length/DestMap and the PlayerOptions dcoID array are
// named owners of the accesses proved by the packet; the DirectPlay call uses
// the period IDirectPlay3 __stdcall Send surface.
//
// Attempt log:
// - prior scaffold used a synthetic StoredMsg layout, raw absolute helpers, and
//   incorrect resend fields; it was retained only as evidence and replaced here.
// - baseline: canonical RESENDER/PlayerOptions/DirectPlay reconstruction; 1232B,
//   24/24 calls, but frame 0x24 versus original 0x20 and broad CFG drift.
// - control-flow: shared no-transmit tail removed the extra Log call; calls became
//   24/24 and edit similarity improved, while the frame/register basin remained.
// - ABI: proven absolute communications globals restored relocation addresses;
//   no structural gain, so retained only for globals without living definitions.
// - control-flow: <=6 and explicit nonzero shutdown branch matched the observed
//   compare polarity; strict diff improved to 1168B.
// - behavior: ratio-first float/integer timing spelling recovered fild/fidiv shape;
//   the remaining x87 compare still uses fcompp rather than the oracle's fcomp.
// - context: proven error-string addresses recovered the branch immediate; final
//   current check is 1222B, 24/24 calls, 90.5058% positional diff, frame 0x24.
// - paused after 9 meaningful hypotheses: remaining gap is broad this/register,
//   frame, local-home, and source-block topology, not a localized safe drift.
// - control-flow: replaced the error-text goto with direct Log returns to test
//   compiler tail merging at the first push/jump hunk; this added one Log call
//   and worsened the diff, so it was restored.

struct TDebuggingLog;
struct RGE_Comm_Error;
struct RGE_Communications_Speed;
struct IDirectPlay3;

extern unsigned long debug_timeGetTime(const char* file, int line);
extern "C" int sprintf(char* buffer, const char* format, ...);

class TDebuggingLog {
public:
    void Log(const char* format, ...);
};

#define L (*(TDebuggingLog**)0x0062C4FC)
#define DAT_0062c5ec (*(IDirectPlay3**)0x0062C5EC)
#define DAT_0062cf04 (*(unsigned int*)0x0062CF04)
#define DAT_0062cf08 (*(int*)0x0062CF08)
#define DAT_0062cf0c (*(int*)0x0062CF0C)
#define DAT_0062cf28 (*(unsigned int*)0x0062CF28)
#define DAT_0062c5e4 (*(unsigned char*)0x0062C5E4)
#define DAT_0062c5a8 (*(unsigned int*)0x0062C5A8)
#define resend_adj1 (*(int*)0x0062CF08)
#define resend_adj2 (*(int*)0x0062CF0C)
#define DAT_0056f210 (*(float*)0x0056F210)
#define s_Com_hand_cpp ((const char*)0x00580BF4)
#define S_SENDSTORE ((const char*)0x00582264)
#define S_BAD_DCOID ((const char*)0x005810B0)

class RGE_Comm_Error {
public:
    void ShowReturn(long result, const char* text);
};

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
    virtual long __stdcall Send(unsigned int from, unsigned int to,
                                int flags, void* data,
                                unsigned int size) = 0;
};

struct RESENDER {
    unsigned int TimeSent;
    unsigned int Serial;
    char* ResendMsg;
    unsigned int Length;
    unsigned int DestMap[10];
};

struct COMMPLAYEROPTIONS {
    char gap_00[0x14];
    unsigned int dcoID[10];
    char gap_3C[0x1D0 - 0x3C];
};

class RGE_Communications_Speed {
public:
    char gap_00[0x20C];
    unsigned int HighestLatencyMsec;
};

struct MSGFORMAT_MISSING_PLAYER {
    unsigned char Command;
    unsigned char gap_01[3];
    unsigned int PlayerID;
};

class TCommunications_Handler {
public:
    char gap_00[0x1C];
    int MeHost;
    char gap_20[0xFC5 - 0x20];
    char TBuff[0x101];
    char gap_10C6[2];
    int CurrentTurn;
    char gap_10CC[0x10E0 - 0x10CC];
    unsigned int Me;
    char gap_10E4[0x12A8 - 0x10E4];
    int ShuttingDown;
    char gap_12AC[0x12C0 - 0x12AC];
    unsigned int TXPacketLength;
    char gap_12C4[0x12D8 - 0x12C4];
    unsigned short MaxGamePlayers;
    char gap_12DA[0x132C - 0x12DA];
    unsigned int ResentToOther;
    char gap_1330[0x149C - 0x1330];
    int Kicked[10];
    char gap_14C4[0x14D4 - 0x14C4];
    RGE_Communications_Speed* Speed;
    char gap_14D8[0x14E0 - 0x14D8];
    RGE_Comm_Error* Err;
    char gap_14E4[0x1514 - 0x14E4];
    unsigned char RGE_Guaranteed_Delivery;
    char gap_1515[0x1518 - 0x1515];
    int IntentionallyDropPackets;
    unsigned int WaitingForAck;
    RESENDER* Resend;
    char gap_1524[0x1550 - 0x1524];
    COMMPLAYEROPTIONS PlayerOptions;
    unsigned int LastTurnAck[10];
    unsigned int HoldCount;

    int PurgeAcknowledgedStoredMessages();
    int IsPlayerHuman(unsigned int player);
    char* GetPlayerName(unsigned int player);
    int Kick(unsigned int player);
    long FastSend(unsigned long to, void* data, unsigned long size,
                  int param_4, int param_5);

    int SendStoredMessages();
};

int TCommunications_Handler::SendStoredMessages()
{
    const char* error_text;
    {
    unsigned long now;
    unsigned int items;
    unsigned int oldest_message_slot;
    unsigned int resend_slot;
    unsigned int max_dest_delay;
    unsigned int player;
    long hr;
    MSGFORMAT_MISSING_PLAYER m;
    RESENDER* resend;
    RESENDER* selected;
    unsigned int* dest_map;
    unsigned int* map;
    unsigned int* dest;
    unsigned int* dco;
    unsigned int slot;
    unsigned int count;
    unsigned int elapsed;
    unsigned int offset;
    unsigned int limit;
    unsigned long send_start;
    unsigned long send_elapsed;
    char* name;

    if (this->RGE_Guaranteed_Delivery == 0) {
        error_text = S_SENDSTORE;
        goto no_transmit;
    }

    if ((DAT_0062c5e4 & 1) == 0) {
        DAT_0062c5e4 |= 1;
        DAT_0062c5a8 = debug_timeGetTime(s_Com_hand_cpp, 0xE00);
    }

    now = debug_timeGetTime(s_Com_hand_cpp, 0xE02);
    if (!((float)DAT_0062cf28 / (now - DAT_0062c5a8) <=
          DAT_0056f210)) {
        return 0;
    }

    DAT_0062c5a8 = now;
    DAT_0062cf28 = 0;
    oldest_message_slot = 0;
    resend_slot = 0;
    items = 0;
    this->PurgeAcknowledgedStoredMessages();

    resend = this->Resend;
    dest_map = resend->DestMap;
    slot = 0;
    max_dest_delay = 0;
    do {
        if (resend->Serial != 0) {
            ++items;
            elapsed = now - resend->TimeSent;
            if (elapsed > oldest_message_slot) {
                oldest_message_slot = elapsed;
                resend_slot = slot;
            }

            map = dest_map;
            count = this->MaxGamePlayers;
            while (count != 0) {
                int free_delay = 0xF0 - *map;
                if (free_delay > (int)max_dest_delay) {
                    max_dest_delay = free_delay;
                }
                ++map;
                --count;
            }
        }
        ++slot;
        ++resend;
        dest_map += 0x0E;
    } while (slot <= 0x1F5);

    if (items == 0) {
        return 0;
    }

    if (this->CurrentTurn <= 6) {
        if (oldest_message_slot < 2000) {
            return 0;
        }
    } else if (this->ShuttingDown != 0) {
        if (oldest_message_slot < 0xFA) {
            return 0;
        }
    } else {
        limit = resend_adj2 + this->Speed->HighestLatencyMsec * 2;
        if (limit < resend_adj1 + 500U) {
            limit = resend_adj1 + 500U;
        }
        if (oldest_message_slot < limit) {
            return 0;
        }
    }

    offset = resend_slot * 0x38;
    this->Resend[resend_slot].TimeSent =
        debug_timeGetTime(s_Com_hand_cpp, 0xE55);

    if (this->MaxGamePlayers == 0) {
        return this->ResentToOther;
    }

    selected = (RESENDER*)((char*)this->Resend + offset);
    dest = selected->DestMap;
    dco = this->PlayerOptions.dcoID + 1;
    player = 1;

    do {
        if (dest[0] != 0 && this->IsPlayerHuman(player) != 0 &&
            dco[0] != 0 && player != this->Me) {
            if (dest[0] != 0) {
                --dest[0];
            }

            L->Log("Resending #%d to P#%d dcoid=%d Length=%d  (elapsed=%d)",
                   resend_slot, player, dco[0], selected->Length,
                   oldest_message_slot,
                   debug_timeGetTime(s_Com_hand_cpp, 0xE69));

            if (DAT_0062cf04 == 0) {
                error_text = S_BAD_DCOID;
                goto no_transmit;
            }

            send_start = debug_timeGetTime(s_Com_hand_cpp, 0xE76);
            L->Log("  >TX STOR #%d %d (%d)", player, resend_slot,
                   selected->Length);
            hr = DAT_0062c5ec->Send(DAT_0062cf04, dco[0], 0,
                                    selected->ResendMsg, selected->Length);
            send_elapsed = debug_timeGetTime(s_Com_hand_cpp, 0xE86) - send_start;
            if (send_elapsed > 0x32) {
                L->Log("!!!SendStoredMessages slow - %ld msec",
                       send_elapsed);
            }

            if (hr == 0) {
                ++this->ResentToOther;
                this->TXPacketLength += selected->Length;
                DAT_0062cf28 += selected->Length;
                L->Log("COMM: RESENT TX Ser#%d To=P#%d Len=%d",
                       selected->Serial, player, selected->Length);
            } else {
                this->Err->ShowReturn(hr, "RESEND Transmit");
            }

            if (dest[0] == 0 && this->IsPlayerHuman(player) != 0 &&
                dco[0] != 0 && player != this->Me) {
                name = this->GetPlayerName(player);
                sprintf(this->TBuff,
                        "Max resends to Player #%d '%s' ", player, name);
                L->Log(this->TBuff);
                if (this->MeHost != 0) {
                    L->Log("HOST Rcvd MAX TX for player #%d", player);
                    this->Kicked[player] = 1;
                    this->Kick(player);
                } else {
                    L->Log("TX Missing Player report for player=%d ",
                           dco[0]);
                    m.Command = '?';
                    L->Log("  >TX MP (%d)", 8);
                    this->FastSend(0, &m, 8, 0, 0);
                }
            }
        }

        ++player;
        ++dest;
        ++dco;
    } while (player <= this->MaxGamePlayers);

    return this->ResentToOther;
    }

no_transmit:
    L->Log(error_text);
    return 0;
}
