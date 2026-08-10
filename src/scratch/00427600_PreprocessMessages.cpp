// VA: 00427600 TCommunications_Handler::PreprocessMessages
// PDB donor: Com_hand.cpp:1281-1920
//
// Canonical reconstruction baseline: the incoming buffer is a byte-oriented
// communications packet.  The common guaranteed header uses command/sequence
// bytes at +0/+1, execute/data turn at +4, and serial at +8.  Ready packets
// have the proven 0x28-byte seven-user/version layout; the local DONE/PONG
// packets are the proven 0x0c-byte command/turn records.  Player identity is
// owned by PlayerOptions.dcoID[10], with the Low/HighPlayerNumber bounds;
// per-player ready/user arrays, LastTurnAck, and PlayerHighSerialNumber are
// named members at their binary offsets.  msg[0] dispatch remains the natural
// period source family of sibling Com_hand.cpp handlers.
//
// ATTEMPT LOG:
// 1 baseline: natural typed packet/member reconstruction; 3384B, frame 0x1B8,
//    86 original versus 91 rebuilt calls.  Canonical ownership and ordered
//    call families were established before tuning.
// 2 behavior: removed an incorrect command-'3' DONE/speed side effect and
//    duplicate GetPlayerName; 3168B, 84 calls, diff improved 3176->2950.
// 3 control-flow: branch-local Chat owner did not change emitted code; kept
//    evidence only while continuing with source review.
// 4 layout: removed an unused local ready packet; frame 0x1B8->0x190.
// 5 layout: scoped disjoint ACK/DONE/PONG/speed/result locals; frame ->0x184.
// 6 liveness: cached Chat before command-'3' logging to preserve the oracle's
//    separate Log/AddChat call sites; 86/86 calls but +44B, so this remains a
//    documented binary-supported context clue rather than a metric-only hack.
// 7 behavior: corrected '?' from a non-host to return at the common final tail.
// 8 layout: moving NextSerialNumber to function scope was codegen-duplicate.
// 9 liveness: delayed the serial pointer until after the second dco lookup;
//    EBX now carries incoming from first, matching the original prologue basin;
//    edit/resync similarity reached 71.84% and size reached 3196B.
// 10 control-flow: delayed player-zero initialization into the from branches;
//    final natural reconstruction is 3200B, frame 0x184, 86/86 calls.
// 11-12 validation/context: replaced the legacy dplay.h surface with the
//    period IDirectPlay2 method order (Send at vslot+0x68); final check remains
//    structural mismatch, not an ABI/call-target mismatch.
// 13-20 (current pass): reused the first player index directly, laid out the
//    missing-DCO failure arm before Send, removed the ready-value byte temp,
//    and tried pointer/temporary lifetime variants.  These recovered the
//    original early call order (84/86 sites, 97.67% aligned in the best CFG
//    layout) and reduced the source to a 3209-byte structural candidate.
//    The remaining blocker is the broad VC5 local/frame basin (0x184 versus
//    original 0x180) plus message/parameter temporary coloring; no ABI or
//    call-target uncertainty remains.  The positive guaranteed-delivery arm
//    is retained because it matches the oracle's late non-GTD LogRXMsg block.

typedef unsigned long ulong;
typedef unsigned int uint;
typedef unsigned char uchar;

enum COMMSTATUS {
    SERVICE_AVAILABLE = 5
};

enum COMMMESSAGES {
    COMM_UPDATE_PLAYERS = 0x17A4,
    COMM_PLAYER_KICKED = 0x17AA,
    COMM_PLAYER_SERVICE_ERROR = 0x17B7
};

enum PLAYERHUMANITY {
    ME_HUMAN = 2
};

#define S(x) ((char*)(x))
#define CS(x) ((const char*)(x))

class TDebuggingLog {
public:
    void Log(char* format, ...);
};

class TChat {
public:
    int AddChatMsg(char* speaker, char* text, uchar taunt);
};

class RGE_Comm_Error {
public:
    void ShowReturn(long result, char* text);
};

// DirectPlay 2 is the period interface held at 0062C5EC.  Its named Send
// method is vtable slot 26 (+0x68); keeping the real interface order avoids a
// fabricated dispatch view while preserving the COM __stdcall ABI.
class IDirectPlay2 {
public:
    virtual long __stdcall QueryInterface(void* iid, void** object) = 0;
    virtual ulong __stdcall AddRef() = 0;
    virtual ulong __stdcall Release() = 0;
    virtual long __stdcall AddPlayerToGroup(ulong group, ulong player) = 0;
    virtual long __stdcall Close() = 0;
    virtual long __stdcall CreateGroup(void* id, void* name, void* data,
                                       ulong data_size, ulong flags) = 0;
    virtual long __stdcall CreatePlayer(void* id, void* name, void* event,
                                        void* data, ulong data_size,
                                        ulong flags) = 0;
    virtual long __stdcall DeletePlayerFromGroup(ulong group, ulong player) = 0;
    virtual long __stdcall DestroyGroup(ulong group) = 0;
    virtual long __stdcall DestroyPlayer(ulong player) = 0;
    virtual long __stdcall EnumGroupPlayers(ulong group, void* instance,
                                             void* callback, void* context,
                                             ulong flags) = 0;
    virtual long __stdcall EnumGroups(void* instance, void* callback,
                                      void* context, ulong flags) = 0;
    virtual long __stdcall EnumPlayers(void* instance, void* callback,
                                       void* context, ulong flags) = 0;
    virtual long __stdcall EnumSessions(void* desc, ulong timeout,
                                        void* callback, void* context,
                                        ulong flags) = 0;
    virtual long __stdcall GetCaps(void* caps, ulong flags) = 0;
    virtual long __stdcall GetGroupData(ulong group, void* data, ulong* size,
                                        ulong flags) = 0;
    virtual long __stdcall GetGroupName(ulong group, void* data, ulong* size) = 0;
    virtual long __stdcall GetMessageCount(ulong player, ulong* count) = 0;
    virtual long __stdcall GetPlayerAddress(ulong player, void* data, ulong* size) = 0;
    virtual long __stdcall GetPlayerCaps(ulong player, void* caps, ulong flags) = 0;
    virtual long __stdcall GetPlayerData(ulong player, void* data, ulong* size,
                                         ulong flags) = 0;
    virtual long __stdcall GetPlayerName(ulong player, void* data, ulong* size) = 0;
    virtual long __stdcall GetSessionDesc(void* data, ulong* size) = 0;
    virtual long __stdcall Initialize(void* guid) = 0;
    virtual long __stdcall Open(void* desc, ulong flags) = 0;
    virtual long __stdcall Receive(ulong* from, ulong* to, ulong flags,
                                   void* data, ulong* size) = 0;
    virtual long __stdcall Send(ulong from, ulong to, ulong flags, void* data,
                                ulong size) = 0;
    virtual long __stdcall SetGroupData(ulong group, void* data, ulong size,
                                        ulong flags) = 0;
    virtual long __stdcall SetGroupName(ulong group, void* name, ulong flags) = 0;
    virtual long __stdcall SetPlayerData(ulong player, void* data, ulong size,
                                         ulong flags) = 0;
    virtual long __stdcall SetPlayerName(ulong player, void* name, ulong flags) = 0;
    virtual long __stdcall SetSessionDesc(void* desc, ulong flags) = 0;
};

class RGE_Communications_Speed {
public:
    uchar GetHighLatencyCenti();
    uint GetAvgFrameRate();
    void SetPlayerTurnSpeed(uint player, uchar avg_frame, uchar high_latency);
    void SetActualLatency(uint player, ulong elapsed);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void* window, uint message, uint wparam, long lparam);
    virtual void set_prog_mode(int mode);
    virtual void set_game_mode(int mode, int value);
    virtual void set_player(short player);
    virtual int get_error_code();
    virtual char* get_string(int type, long id, char* buffer, int size);
    virtual char* get_string(long id, char* buffer, int size);
    virtual char* get_string(long id);
    virtual char* get_string2(int type, long id, long value, char* buffer,
                              int size);
};

struct MSGFORMAT_ACKNOWLEDGE_GUARANTEED {
    uchar Command;
    uchar pad_01[3];
    uint Serialno;
};

struct MSGFORMAT_LATENCY {
    uchar Command;
    uchar pad_01[3];
    ulong Initiated;
    ulong CurrentTurn;
};

struct MSGFORMAT_ALL_DONE {
    uchar Command;
    uchar pad_01[3];
    ulong ExecuteOnTurn;
    uchar HighLatencyCenti;
    uchar FrameRateMsec;
    uchar pad_0A[2];
};

struct MSGFORMAT_SETREADYOPTIONS {
    uchar Command;
    uchar Ready;
    uchar pad_02[2];
    ulong User1;
    ulong User2;
    ulong User3;
    ulong User4;
    ulong User5;
    ulong User6;
    ulong User7;
    ulong CommunicationsVersionCode;
    uchar RGEGuaranteed;
    uchar pad_25[3];
};

struct COMMPLAYEROPTIONS {
    uchar NeedsToBeSent;
    uchar pad_01[3];
    ulong LastSentTime;
    int ProgramState;
    ulong CurrentTurn;
    uchar TurnSpeedMsec;
    uchar pad_11[3];
    ulong dcoID[10];
    ulong AcknowledgeAfterMsec;
    uchar CommandTurnIncrement;
    uchar pad_41[3];
    int PlayerReady[10];
    ulong User1[10];
    ulong User2[10];
    ulong User3[10];
    ulong User4[10];
    ulong User5[10];
    ulong User6[10];
    ulong User7[10];
    int Humanity[10];
    uchar InvalidPlayer[10];
    uchar pad_1B6[2];
    ulong Initialized;
    ulong RandomSeed;
    unsigned short HighPlayerNumber;
    unsigned short LowPlayerNumber;
    uint HostPlayerNumber;
    int GameHasStarted;
    ulong DataSizeToFollow;
};

extern ulong debug_timeGetTime(char* file, int line);
extern "C" int sprintf(char* buffer, const char* format, ...);

#define L (*(TDebuggingLog**)0x0062C4FC)
#define DCO_SELF (*(ulong*)0x0062CF04)
#define DIRECT_PLAY (*(IDirectPlay2**)0x0062C5EC)
#define RX_MESSAGE_PTR (*(uint**)0x0062CF1C)
#define RX_MESSAGE_BASE (*(ulong*)0x0062CF20)
#define DROP_COUNT (*(ulong*)0x0062CF24)
#define LAST_SENT_TIME (*(ulong*)0x008884D4)
#define RGE_BASE_GAME (*(RGE_Base_Game**)0x0062C574)

class TCommunications_Handler {
public:
    char gap_00[0x18];
    TChat* Chat;
    int MeHost;
    char gap_20[0xFC5 - 0x20];
    char TBuff[257];
    char gap_10C6[0x10C8 - 0x10C6];
    ulong current_turn;
    ulong next_command_turn;
    uint sequence;
    long WaitOnPlayer;
    ulong TurnSpeedMsec;
    ulong AcknowledgeAfterMsec;
    uint Me;
    int Multiplayer;
    int OutOfSyncFlag;
    ulong dwStopTime;
    char gap_10F0[0x12A4 - 0x10F0];
    ulong CommunicationsVersionCode;
    int ShuttingDown;
    char gap_12AC[0x12C0 - 0x12AC];
    ulong TXPacketLength;
    char gap_12C4[0x1330 - 0x12C4];
    ulong DroppedPacketCount;
    char gap_1334[0x1344 - 0x1334];
    ulong LastPlayerCommunication[10];
    char gap_136C[0x14D4 - 0x136C];
    RGE_Communications_Speed* Speed;
    char gap_14D8[0x14E0 - 0x14D8];
    RGE_Comm_Error* Err;
    char gap_14E4[0x1514 - 0x14E4];
    uchar RGE_Guaranteed_Delivery;
    uchar pad_1515[3];
    int IntentionallyDropPackets;
    uint WaitingForAck;
    void* Resend;
    void* OnHold;
    uint PlayerHighSerialNumber[10];
    COMMPLAYEROPTIONS PlayerOptions;
    ulong LastTurnAck[10];
    uint HoldCount;
    int WasKicked[10];

    COMMSTATUS UnlinkToLevel(COMMSTATUS level);
    void NotifyWindow(COMMMESSAGES message);
    void NotifyWindowParam(COMMMESSAGES message, long player);
    int RXAcknowledgeStoredMessage(uint serial, uint player);
    int PurgeAcknowledgedStoredMessages();
    int TXAcknowledgeMessage(uint serial, uint player);
    void UpdatePlayer(uint player, int flags);
    int IsPlayerHuman(uint player);
    void SetPlayerHumanity(uint player, PLAYERHUMANITY humanity);
    long SendSharedData(int force);
    void ClearRXForPlayer(uint player);
    int Kick(uint player);
    long TXResendReply(uint serial, uint player);
    int StoreIncoming(uint serial, char* message, uint p1, ulong p2, ulong p3);
    int TXResendRequest(uint serial, uint player);
    void LogRXMsg(uint serial, uint player, ulong execute_turn, uchar command, uchar sequence);
    int EvaluatePlayerMessage(ulong p1, uint player, ulong p3, uchar command,
                              uchar sequence, char* message, uint p7,
                              ulong p8, ulong p9);
    long CommOut(ulong to, uchar command, void* message, int length, uchar flags);
    char* GetPlayerName(uint player);
    long FastSend(ulong to, void* message, ulong length, int p4, int p5);

    int PreprocessMessages(ulong param_1, char* message, ulong from,
                           ulong to, int cached);
};

int TCommunications_Handler::PreprocessMessages(ulong param_1, char* message,
                                                 ulong from, ulong to, int cached)
{
    char msg[256];
    char msg_str[100];
    int player;

    if (from != 0) {
        int high = this->PlayerOptions.HighPlayerNumber;
        player = this->PlayerOptions.LowPlayerNumber;
        if (player <= high) {
            do {
                ulong* dco = this->PlayerOptions.dcoID + player;
                if (*dco == from) {
                    goto player_lookup_found;
                }
                ++player;
            } while (player <= high);
        }
    }
    player = 0;

player_lookup_found:

    if (*message == 'I') {
        this->UnlinkToLevel(SERVICE_AVAILABLE);
        this->NotifyWindow(COMM_UPDATE_PLAYERS);
        this->NotifyWindow(COMM_PLAYER_KICKED);
        return 1;
    }

    if (player == 0) {
        MSGFORMAT_ACKNOWLEDGE_GUARANTEED bad_ack;
        L->Log(S(0x5815A4), from);
        bad_ack.Serialno = *(uint*)(message + 8);
        bad_ack.Command = 'A';
        if (DCO_SELF == 0) {
            L->Log(S(0x5810B0));
            return 0;
        }
        DIRECT_PLAY->Send(DCO_SELF, from, 0, &bad_ack, 8);
        this->TXPacketLength += 8;
        return 0;
    }

    this->LastPlayerCommunication[player] =
        debug_timeGetTime(S(0x580BF4), 0x543);

    player = 0;
    if (from != 0) {
        int i = this->PlayerOptions.LowPlayerNumber;
        int high = this->PlayerOptions.HighPlayerNumber;
        if (i <= high) {
            do {
                if (this->PlayerOptions.dcoID[i] == from) {
                    player = i;
                    break;
                }
                ++i;
            } while (i <= high);
        }
    }

    uint* serial = (uint*)(message + 8);
    L->Log(S(0x58156C), (int)*message, player, from, *serial,
           debug_timeGetTime(S(0x580BF4), 0x54D));

    if (*message == 'K' && this->PlayerOptions.ProgramState == 3) {
        ulong kill_dco = *(ulong*)(message + 0x10);
        L->Log(S(0x581538), from, kill_dco);
        if (*serial == this->PlayerHighSerialNumber[player] + 1) {
            this->PlayerHighSerialNumber[player] = *serial;
        }
        L->Log(S(0x58151C), player, *serial, 8);
        this->TXAcknowledgeMessage(*serial, player);
        uint kill_player = *(uint*)(message + 0x0C);
        this->PlayerHighSerialNumber[kill_player] = kill_player * 2000;
        if (*(ulong*)(message + 0x10) == DCO_SELF) {
            this->NotifyWindow(COMM_PLAYER_KICKED);
            return 1;
        }
    }

    if (*message == 'C') {
        char* chat = this->RGE_Guaranteed_Delivery != 0
            ? message + 0x0C : message + 0x08;
        uchar pregame = (uchar)chat[0x10];
        if (pregame != 0 && this->PlayerOptions.ProgramState != 3) {
            L->Log(S(0x5814F0), (uint)pregame,
                   this->PlayerOptions.ProgramState, chat + 0x11);
            return 0;
        }
        L->Log(S(0x5814C8), (uint)pregame,
               this->PlayerOptions.ProgramState, chat + 0x11);
    }

    if (*message == 'A') {
        this->RXAcknowledgeStoredMessage(*(uint*)(message + 4), player);
        this->PurgeAcknowledgedStoredMessages();
        return 1;
    }

    if (*message == 'R') {
        L->Log(S(0x5814B4));
        if (this->MeHost == 0) {
            return 1;
        }

        this->PlayerOptions.PlayerReady[player] = (uint)(uchar)message[1];
        L->Log(S(0x581494), (uint)(uchar)message[1], player);
        this->PlayerOptions.User1[player] = *(ulong*)(message + 4);
        this->PlayerOptions.User2[player] = *(ulong*)(message + 8);
        this->PlayerOptions.User3[player] = *(ulong*)(message + 0x0C);
        this->PlayerOptions.User4[player] = *(ulong*)(message + 0x10);
        this->PlayerOptions.User5[player] = *(ulong*)(message + 0x14);
        this->PlayerOptions.User6[player] = *(ulong*)(message + 0x18);
        this->PlayerOptions.User7[player] = *(ulong*)(message + 0x1C);
        if (!this->IsPlayerHuman(player)) {
            this->SetPlayerHumanity(player, ME_HUMAN);
        }
        if (this->CommunicationsVersionCode == *(ulong*)(message + 0x20)) {
            L->Log(S(0x581458), player, this->CommunicationsVersionCode);
        } else {
            this->NotifyWindowParam(COMM_PLAYER_SERVICE_ERROR, player);
            sprintf(this->TBuff, CS(0x5813BC), player);
            L->Log(this->TBuff);
        }
        this->PlayerOptions.NeedsToBeSent = 1;
        this->SendSharedData(0);
        this->UpdatePlayer(player, 0);
        sprintf(this->TBuff, CS(0x581380),
                this->PlayerOptions.PlayerReady[1],
                this->PlayerOptions.PlayerReady[2],
                this->PlayerOptions.PlayerReady[3],
                this->PlayerOptions.PlayerReady[4],
                this->PlayerOptions.PlayerReady[5],
                this->PlayerOptions.PlayerReady[6],
                this->PlayerOptions.PlayerReady[7],
                this->PlayerOptions.PlayerReady[8]);
        L->Log(this->TBuff);
        this->NotifyWindow(COMM_UPDATE_PLAYERS);
        return 1;
    }

    if (*message == '1') {
        MSGFORMAT_ALL_DONE done;
        MSGFORMAT_LATENCY pong;
        ulong turn = this->current_turn;
        if (this->Multiplayer != 0 && this->PlayerOptions.ProgramState != 3 &&
            this->LastTurnAck[this->Me] != turn) {
            this->LastTurnAck[this->Me] = turn;
            if (turn > 6) {
                uchar high_latency = this->Speed->GetHighLatencyCenti();
                uchar avg_frame = (uchar)this->Speed->GetAvgFrameRate();
                this->Speed->SetPlayerTurnSpeed(this->Me, avg_frame, high_latency);
            }
            LAST_SENT_TIME = debug_timeGetTime(S(0x580BF4), 0xBF9);
            done.Command = 'D';
            done.ExecuteOnTurn = this->PlayerOptions.CommandTurnIncrement + turn;
            L->Log(S(0x580EA4), 0x0C);
            this->CommOut(0, 0x44, &done, 0x0C, 0);
        }
        pong.Command = '2';
        pong.Initiated = *(ulong*)(message + 4);
        pong.CurrentTurn = turn;
        L->Log(S(0x58136C), player, 0x0C);
        long result = this->FastSend(this->PlayerOptions.dcoID[player],
                                     &pong, 0x0C, 0, 0);
        this->Err->ShowReturn(result, S(0x581364));
        return 1;
    }

    if (*message == '3') {
        MSGFORMAT_LATENCY pong;
        ulong turn = this->current_turn;
        pong.Command = '4';
        pong.Initiated = *(ulong*)(message + 4);
        pong.CurrentTurn = turn;
        L->Log(S(0x581348), player, 0x0C);
        long result = this->FastSend(this->PlayerOptions.dcoID[player],
                                     &pong, 0x0C, 0, 0);
        this->Err->ShowReturn(result, S(0x581338));
        sprintf(msg, CS(0x581314), this->GetPlayerName(player), player);
        TChat* chat = this->Chat;
        L->Log(msg);
        chat->AddChatMsg(S(0x58130C), msg, 0);
        return 1;
    }

    if (*message == '?') {
        if (this->MeHost == 0) {
            return 1;
        }
        ulong missing_dco = *(ulong*)(message + 4);
        uint missing_player = 0;
        if (missing_dco != 0) {
            int i = this->PlayerOptions.LowPlayerNumber;
            int high = this->PlayerOptions.HighPlayerNumber;
            if (i <= high) {
                do {
                    if (this->PlayerOptions.dcoID[i] == missing_dco) {
                        missing_player = i;
                        break;
                    }
                    ++i;
                } while (i <= high);
            }
        }
        if (this->PlayerOptions.ProgramState != 3) {
            L->Log(S(0x581268), missing_player, missing_dco, player);
            this->Kick(missing_player);
            return 1;
        }
        sprintf(this->TBuff, CS(0x5812E0), player, missing_player, missing_dco);
        L->Log(this->TBuff);
        L->Log(S(0x5812A0), missing_player, missing_dco, player);
        this->PlayerOptions.PlayerReady[missing_player] = 0;
        this->PlayerOptions.InvalidPlayer[missing_player] = 1;
        this->PlayerOptions.NeedsToBeSent = 1;
        return 1;
    }

command_2:
    if (*message == '2') {
        MSGFORMAT_ALL_DONE done;
        ulong turn = this->current_turn;
        ulong elapsed = debug_timeGetTime(S(0x580BF4), 0x672)
                      - *(ulong*)(message + 4);
        if (this->Multiplayer != 0 && this->PlayerOptions.ProgramState != 3 &&
            this->LastTurnAck[this->Me] != turn) {
            this->LastTurnAck[this->Me] = turn;
            if (turn > 6) {
                uchar high_latency = this->Speed->GetHighLatencyCenti();
                uchar avg_frame = (uchar)this->Speed->GetAvgFrameRate();
                this->Speed->SetPlayerTurnSpeed(this->Me, avg_frame, high_latency);
            }
            LAST_SENT_TIME = debug_timeGetTime(S(0x580BF4), 0xBF9);
            done.Command = 'D';
            done.ExecuteOnTurn = this->PlayerOptions.CommandTurnIncrement + turn;
            L->Log(S(0x580EA4), 0x0C);
            this->CommOut(0, 0x44, &done, 0x0C, 0);
        }
        this->Speed->SetActualLatency(player, elapsed);
        return 1;
    }

    if (*message == '4') {
        ulong elapsed = debug_timeGetTime(S(0x580BF4), 0x68B)
                      - *(ulong*)(message + 4);
        char* name = this->GetPlayerName(player);
        sprintf(msg, CS(0x581248), name, player, elapsed);
        L->Log(msg);
        this->Chat->AddChatMsg(S(0x58130C), msg, 0);
        return 1;
    }

    if (*message == 'Y' && this->PlayerOptions.ProgramState == 3) {
        uint value = *(uint*)(message + 4);
        this->PlayerHighSerialNumber[player] = value;
        this->ClearRXForPlayer(player);
        L->Log(S(0x581218), player,
               this->PlayerHighSerialNumber[player], value);
        return 1;
    }

    if (this->RGE_Guaranteed_Delivery != 0) {
        if (this->IntentionallyDropPackets != 0 && this->current_turn > 6) {
            ++DROP_COUNT;
            if (DROP_COUNT > 8) {
                RGE_BASE_GAME->get_string(0x4BC, msg_str, 100);
                sprintf(this->TBuff, msg_str, *serial,
                        (int)message[0], (int)message[0]);
                L->Log(this->TBuff);
                DROP_COUNT = 0;
                return 1;
            }
        }

        if (*message == 'X') {
            this->TXResendReply(*(uint*)(message + 4), player);
            return 1;
        }

        if (this->PlayerHighSerialNumber[player] == 0) {
            L->Log(S(0x5811E4), player, *serial);
            this->PlayerHighSerialNumber[player] = *serial - 1;
        }

        uint next_serial = this->PlayerHighSerialNumber[player] + 1;
        if (*serial < next_serial) {
            sprintf(this->TBuff, CS(0x581198), *serial, next_serial, player);
            L->Log(this->TBuff);
            L->Log(S(0x581180), player, *serial, 8);
            this->TXAcknowledgeMessage(*serial, player);
            return 1;
        }
        if (next_serial < *serial) {
            ++this->DroppedPacketCount;
            sprintf(this->TBuff, CS(0x58115C), *serial, player);
            L->Log(this->TBuff);
            this->StoreIncoming(*serial, message, param_1, from, to);
            L->Log(S(0x581144), player, *serial, 8);
            this->TXAcknowledgeMessage(*serial, player);
            this->TXResendRequest(next_serial, player);
            return 1;
        }
        if (cached == 0) {
            L->Log(S(0x58112C), player, *serial, 8);
            this->TXAcknowledgeMessage(*serial, player);
        }
        RX_MESSAGE_BASE = param_1 - 0x0C;
        this->PlayerHighSerialNumber[player] = *serial;
        RX_MESSAGE_PTR = (uint*)(message + 0x0C);
    } else {
        this->LogRXMsg(*serial, player, *(ulong*)(message + 4),
                       (uchar)message[0], (uchar)message[1]);
        RX_MESSAGE_BASE = param_1 - 8;
        RX_MESSAGE_PTR = (uint*)(message + 0x0C);
    }

    L->Log(S(0x5810E0), *serial, (uint)(uchar)message[0],
           (uint)(uchar)message[0], (uint)(uchar)message[1],
           *(ulong*)(message + 4), param_1, from, to);
    if (this->ShuttingDown == 0) {
        this->EvaluatePlayerMessage(param_1, player, *(ulong*)(message + 4),
                                    (uchar)message[0], (uchar)message[1],
                                    (char*)RX_MESSAGE_PTR, (uint)RX_MESSAGE_BASE,
                                    from, to);
    }
    return 1;
}
