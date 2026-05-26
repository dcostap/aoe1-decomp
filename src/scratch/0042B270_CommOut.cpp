// 0042B270 TCommunications_Handler::CommOut
// Attempt log:
// try 1: direct reconstruction from packet/Ghidra line map: header allocation/copy, per-player masks, DP Send call, pending-byte accounting, cleanup; default /O2 too small (.text 1472 vs 1505).
// try 2: inlined repeated count-other-human loops instead of helper; default /O2 improved to .text 1504 vs 1505 but still not comparable.
// try 3: diagnostic impossible full_len == -1 log only to get exact-size compare; broad mismatch 88.0399% positional / 60.7309% edit, first mismatch prologue (frame 0x10 vs original 0x24, this in ESI vs original EBP); rolled hack back.
// try 4: /GX on exact-size diagnostic source no change; rolled back.
// try 5: /Od exact-size diagnostic source worse debug-basin mismatch (90.4319% positional / 123.9203% edit); rolled back.
// left in scratch: no custom flags retained. Not accepted_drift quality; likely needs exact original TCommunications_Handler/DirectPlay/logging declarations and source local topology to recover 0x24 stack frame and EBP this-register allocation.

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long DWORD;
typedef long HRESULT;

extern "C" void* __cdecl operator_new(uint size);
extern "C" void __cdecl operator_delete(void* p);
extern "C" void __cdecl TDebuggingLog_Log(void* log, const char* fmt, ...);
extern "C" uint __cdecl debug_time(const char* file, int line);
extern "C" void __cdecl log_error(void* logger, const char* fmt, HRESULT hr);

#define G_LOG (*(void**)0x0062C4FC)
#define G_DP  (*(DPObj**)0x0062C5EC)
#define G_DPPLAYER (*(DWORD*)0x0062CF04)

struct DPObj;
struct DPVtbl { char pad[0x68]; HRESULT (__stdcall *Send)(DPObj*, DWORD, DWORD, DWORD, void*, DWORD); };
struct DPObj { DPVtbl* lpVtbl; };

struct OutCommBuff { uchar type; uchar seq; ushort pad; DWORD turn; DWORD serial; };

class TCommunications_Handler {
public:
    char gap0[0x10C8];
    DWORD turn;
    char gap1[0x14];
    int my_player;
    int current_send;
    char gap2[0x1F0];
    int pending_bytes;
    char gap3[0x14];
    ushort num_players;
    char gap4[0x206];
    int ser;
    int ser_count;
    int out_mask[0x20];
    uchar sending_out_of_band;
    char gap5[0x3B];
    uchar seq_base;

    uchar GetNextSequence(DWORD turn);
    int IsPlayerHuman(int player);
    void SendLocal(int serial, void* buf, int len, int* mask);
    void SendIHaveCheckSums(void* data, DWORD len, uchar seq, int player, int a, int b);
    HRESULT CommOut(char* data, char type, int player, int len, int flag);
};

HRESULT TCommunications_Handler::CommOut(char* data, char type, int player, int len, int flag)
{
    if (this->current_send == 0) return 0;
    if (G_DP == 0) return 0;
    if (this->ser == 0) {
        TDebuggingLog_Log(G_LOG, (const char*)0x582604);
        return 0;
    }

    OutCommBuff* out = (OutCommBuff*)operator_new(0x0C);
    if (type == '1' || type == '2' || type == '?' || type == 'A') {
        TDebuggingLog_Log(G_LOG, (const char*)0x5825E8);
    }

    int header;
    if (this->sending_out_of_band) {
        out->serial = this->ser;
        this->out_mask[this->my_player] = this->ser;
        ++this->ser;
        header = 0x0C;
    } else {
        header = 8;
        out->serial = 0;
    }

    int full_len = header + len;
    if (full_len > 0xFA0) {
        TDebuggingLog_Log(G_LOG, (const char*)0x5825B8, 0xFA0, header, len);
    }

    out->type = 0;
    out->seq = 0;
    out->turn = this->turn + this->seq_base;

    int i;
    for (i = 0; i <= this->num_players; ++i) {
        if (this->IsPlayerHuman(i) && i != this->my_player) this->out_mask[i] = 0xF0;
        else this->out_mask[i] = 0;
    }

    if (!(type == '1' || type == '2' || type == '?' || type == 'A')) {
        out->seq = this->GetNextSequence(out->turn);
        if (this->ser_count != 5 && out->seq == 0) {
            operator_delete(out);
            return (HRESULT)0x8877010E;
        }
    } else {
        TDebuggingLog_Log(G_LOG, (const char*)0x5825A0);
    }

    out->type = type;
    char* packet = (char*)operator_new(full_len + 1);
    char* dst = packet;
    char* src = (char*)out;
    for (i = header; i; --i) *dst++ = *src++;
    if (len) {
        src = data;
        for (i = len; i; --i) *dst++ = *src++;
    }

    int masked = 0;
    for (i = 0; i <= this->num_players; ++i) {
        if (this->IsPlayerHuman(i) && i != this->my_player) { this->out_mask[i] = 0xF0; ++masked; }
        else this->out_mask[i] = 0;
    }

    HRESULT hr = 0;
    if (this->sending_out_of_band) {
        if (full_len == 0) {
            TDebuggingLog_Log(G_LOG, (const char*)0x58258C);
            return (HRESULT)0x80004005;
        }
        if (masked != 0) {
            if (G_DPPLAYER == 0) {
                TDebuggingLog_Log(G_LOG, (const char*)0x5810B0);
                --this->ser;
                return (HRESULT)0x80004005;
            }
            uint t0 = debug_time((const char*)0x580BF4, 0x10AA);
            hr = G_DP->lpVtbl->Send(G_DP, G_DPPLAYER, (DWORD)player, 0, packet, full_len);
            uint dt = debug_time((const char*)0x580BF4, 0x10B5) - t0;
            if (dt > 50) TDebuggingLog_Log(G_LOG, (const char*)0x582570, dt);
            int n;
            if (player) n = 1;
            else {
                n = 0;
                for (int j = 1; j <= this->num_players; ++j) {
                    if (this->IsPlayerHuman(j) && j != this->my_player) ++n;
                }
            }
            if (hr == 0) {
                this->pending_bytes += n * full_len;
                this->SendLocal(out->serial, packet, full_len, this->out_mask);
            } else {
                --this->ser;
                log_error(*(void**)((char*)this + 0x14E0), (const char*)0x582564, hr);
            }
        } else {
            hr = 0;
        }
    } else {
        if (masked != 0) {
            if (G_DPPLAYER == 0) {
                TDebuggingLog_Log(G_LOG, (const char*)0x5810B0);
                return (HRESULT)0x80004005;
            }
            uint t0 = debug_time((const char*)0x580BF4, 0x10EE);
            hr = G_DP->lpVtbl->Send(G_DP, G_DPPLAYER, (DWORD)player, 0, packet, full_len);
            uint dt = debug_time((const char*)0x580BF4, 0x10F9) - t0;
            if (dt > 50) TDebuggingLog_Log(G_LOG, (const char*)0x582548, dt);
            int n;
            if (player) n = 1;
            else {
                n = 0;
                for (int j = 1; j <= this->num_players; ++j) {
                    if (this->IsPlayerHuman(j) && j != this->my_player) ++n;
                }
            }
            if (hr == 0) this->pending_bytes += n * full_len;
        } else {
            hr = 0;
        }
    }

    if (masked) {
        const char* prefix = this->sending_out_of_band ? (const char*)0x582544 : (const char*)0x58253C;
        TDebuggingLog_Log(G_LOG, (const char*)0x5824C4, out->turn, player, flag, type, type, out->seq, out->seq, data[len], packet, hr, debug_time((const char*)0x580BF4, 0x112B), prefix);
    }

    if (hr) log_error(*(void**)((char*)this + 0x14E0), (const char*)0x5824C0, hr);
    else {
        ++*(int*)((char*)this + 0x1338);
        if (type == '>') this->SendIHaveCheckSums(data, (DWORD)player, out->seq, this->my_player, len, 0);
    }

    operator_delete(out);
    operator_delete(packet);
    return hr;
}
