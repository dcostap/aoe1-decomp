// VA: 00426FC0 TCommunications_Handler::GetDPLAYMessages
// PDB source: Com_hand.cpp lines 965-1113
// attempt log:
// 1: natural reconstruction from packet/decompiler, COM v44/v64 as __stdcall virtuals; exact 819B but broad 79.61% positional / 94.14% edit mismatch, first diff frame 0x18 vs 0x14.
// 2: inlined duplicated player-index scans instead of helper; edit diff improved to 59.46%, positional still broad and frame 0x14.
// 3: added volatile local_4 stack pressure; no frame improvement and worsened diff to 81.20%/61.54%, rolled back.
// 4: flag probes: /O2 no-/Oy and /GX same mismatch; /O1 shrinks to 733B; /Od same size but broad mismatch from offset 0. Rolled back to default /O2 /Oy.
// 5: kept direct COM vtable calls and direct member calls for PreprocessMessages/EvaluateSystemMessage; call set/behavior plausible but prologue/local scheduling differs from original.
// session: terminal EvaluateSystemMessage return restored the oracle's 21-call/3-return
// CFG. Unsigned HighPlayerNumber(+1710)/LowPlayerNumber(+1712) bounds recover the
// zero-extend loop shape; explicit persistent COM caching and raw vtable surfaces
// were worse. Remaining drift is frame/local-home and COM argument scheduling.
// FLAGS: config/flags/00426FC0_GetDPLAYMessages.rsp (/nologo /c /O2 /Oy)
// left in scratch: needs real Com_hand.cpp source/context to recover original prologue (global load before saves) and exact local stack topology.

typedef unsigned long ulong;
extern ulong __cdecl debug_timeGetTime(char* file, int line);
class TDebuggingLog { public: void Log(char* fmt, ...); };
class RGE_Comm_Error { public: void ShowReturn(long result, char* msg); };
#define log_obj (*(TDebuggingLog**)0x0062C4FC)
#define dplay (*(IDirectPlay4A**)0x0062C5EC)
#define dplay_id (*(ulong*)0x0062CF04)

class IDirectPlay4A {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40();
    virtual long __stdcall GetMessageCount(ulong id, ulong* count);
    virtual void v48(); virtual void v4C(); virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C(); virtual void v60();
    virtual long __stdcall Receive(ulong* from, ulong* to, unsigned long flags, void* data, ulong* size);
};

class TCommunications_Handler {
public:
    char gap_0000[0x24];
    char InCommBuff[0x1000];
    char gap_1024[0x12B8-0x1024];
    ulong RXPacketLength;
    char gap_12BC[0x1334-0x12BC];
    ulong RXPackets;
    char gap_1338[0x14E0-0x1338];
    RGE_Comm_Error* Err;
    char gap_14E4[0x1564-0x14E4];
    ulong dcoID[64];
    char gap_1664[0x1710-0x1664];
    unsigned short HighPlayerNumber;
    unsigned short LowPlayerNumber;
    void GetDPLAYMessages();
    void EvaluateSystemMessage(ulong size, char* msg, int a, ulong to);
    int PreprocessMessages(ulong size, char* msg, ulong from, ulong to, int cached);
};

void TCommunications_Handler::GetDPLAYMessages() {
    ulong dcoFromID = 0;
    ulong dcoReceiveID = 0;
    ulong dwCount = 0;
    ulong dwPreSize;
    ulong dwSize;
    ulong loopStartTime;
    ulong local_4;
    if (dplay == 0) return;
    dwSize = 4000;
    dcoFromID = 4000;
    char* buf = this->InCommBuff;
    local_4 = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x3d4);
    dwPreSize = 0;
    long hr = dplay->GetMessageCount(dplay_id, &dwPreSize);
    if (hr == 0 && dwPreSize > 10) log_obj->Log((char*)"!!! DPMsgCount = %u", dwPreSize);
    while (1) {
        ulong t = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x3e1);
        dcoFromID = 0;
        hr = dplay->Receive(&dcoFromID, &dcoReceiveID, 8, 0, &dwSize);
        ulong elapsed = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x3ec) - t;
        if (elapsed > 50) log_obj->Log((char*)"!!! Receive Peek slow - %u msec", elapsed);
        if (hr == 0 && dwSize >= 4000) { log_obj->Log((char*)"True overflow %d requested.  Max = %d", dwSize, 4000); return; }
        if (hr != 0) dwSize = 4000;
        t = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x403);
        hr = dplay->Receive(&dcoFromID, &dcoReceiveID, 1, buf, &dwSize);
        elapsed = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x40c) - t;
        if (elapsed > 50) log_obj->Log((char*)"!!! Receive slow - %u msec", elapsed);
        elapsed = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x417) - local_4;
        if (elapsed > 500) {
            ulong now = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x419);
            log_obj->Log((char*)"!!! In Receive Loop for %u ms", now - local_4);
        }
        if (hr == (long)0x887700BE) return;
        if (dwSize == 0) return;
        if (hr != 0) { this->Err->ShowReturn(hr, (char*)"Rcv MSG"); return; }
        int pno;
        if (dcoFromID != 0) {
            unsigned int i = this->LowPlayerNumber;
            unsigned int hi = this->HighPlayerNumber;
            if (i <= hi) {
                ulong* p = this->dcoID + i;
                do {
                    if (*p == dcoFromID)
                        goto found_first_player;
                    i++;
                    p++;
                } while (i <= hi);
            }
            i = 0;
found_first_player:
            pno = i;
        } else pno = 0;
        log_obj->Log((char*)"  >RX #%d %c-%d (%u)", pno, (int)*buf, (int)*buf, dwSize);
        if (dcoFromID != 0) {
            unsigned int i = this->LowPlayerNumber;
            unsigned int hi = this->HighPlayerNumber;
            if (i <= hi) {
                ulong* p = this->dcoID + i;
                do {
                    if (*p == dcoFromID)
                        goto found_second_player;
                    i++;
                    p++;
                } while (i <= hi);
            }
            i = 0;
found_second_player:
            pno = i;
        } else pno = 0;
        log_obj->Log((char*)"COMM: RX P#%d ID(%ld) siz=%db   MSG=%d '%c'", pno, dcoFromID, dwSize, (int)*buf, (int)*buf, debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x435));
        this->RXPacketLength += dwSize;
        this->RXPackets++;
        buf[dwSize] = 0;
        if (dcoFromID != 0) this->PreprocessMessages(dwSize, buf, dcoFromID, dcoReceiveID, 0);
        else {
            this->EvaluateSystemMessage(dwSize, buf, 0, dcoReceiveID);
            return;
        }
    }
}
