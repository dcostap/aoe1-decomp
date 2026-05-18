// 0042DF90 TCommunications_Handler::UpdatePlayer
// Com_hand.cpp
// Attempt log:
// try 1: broad reconstruction from packet: state switch, DirectPlay GetPlayerName-like calls, string copies, cleanup.
// try 2: modeled stack frame/local set: name pointer, size local, chat char/temp locals; initial frame matches `sub esp,0Ch`.
// try 3: modeled player index parameter in EBP and this in EBX; switch on state[player] at +0x16D4 and dpid[player] at +0x1564.
// try 4: fixed array layout by adding +0x155C padding so dpid/flag/state loads use +0x1564/+0x1594/+0x16D4.
// try 5: modeled state 0/1 paths logging, clearing dpid/flag, then optional UI update.
// try 6: modeled states 2..5 logging and the common DirectPlay GetPlayerName path using global +0x62C5EC vtable +0x54, calloc(size,1), second call, lobby log.
// try 7: modeled success path copying `name+8`/`name+0x0C` strings to +0x12C8/+0x12CC 0x80-stride buffers, state=2, free.
// try 8: modeled HRESULT branches: invalid-player/name-not-found clears to default string/state 0, DPERR_UNAVAILABLE case can send '?' chat for human in mode 3, generic error clears state/dpid.
// try 9: modeled default switch case writing unknown string to playerShortNames and logging state/player.
// try 10: current rebuild has exact original size 968B but broad mismatch remains (724 positional bytes, 74.79%). First 30 bytes now match through state/dpid loads; divergence begins at switch lowering/block order because source emits an extra save of dpid and different jump table/layout.
// left in scratch: behavior/call surface is broad and size-matched, but exact switch block topology, DirectPlay/player-name structure, and chat-call argument shape are unresolved. No accepted_drift: broad control-flow/layout drift.

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" char* __cdecl strcpy(char*, const char*);
extern "C" void* __cdecl calloc(unsigned int,unsigned int);
extern "C" void __cdecl free(void*);
extern void log_printf(void*, const char*, ...);
extern void* DAT_0062c4fc;
struct DPVtbl { char gap54[0x54]; int (__stdcall *GetPlayerName)(void*, unsigned long, void*, unsigned long*); };
struct DPObj { DPVtbl* vt; };
extern DPObj* DAT_0062c5ec;

struct PlayerName { char gap0[8]; char* shortName; char* longName; };
class Lobby { public: int formatName(char*); int playerReady(unsigned int); };

class TCommunications_Handler {
public:
    char gap_0000[0x12C8];
    char* playerShortNames; // +12c8 0x80 stride
    char* playerLongNames;  // +12cc 0x80 stride
    char gap_12D0[0x14E0-0x12D0];
    Lobby* lobby;           // +14e0
    char gap_14E4[0x1558-0x14E4];
    int mode;               // +1558
    char gap_155C[8];
    int dpid[12];           // +1564
    int flag[12];           // +1594
    char gap_15C4[0x16D4-0x15C4];
    int state[12];          // +16d4

    void UpdatePlayer(unsigned int player, int do_update);
    int IsPlayerHuman(unsigned int player);
    void send_chat(int,int,int,char*,int);
    void update_ui(int);
};

void TCommunications_Handler::UpdatePlayer(unsigned int player, int do_update) {
    int id = dpid[player];
    PlayerName* name = 0;
    unsigned long size;
    int hr;
    char ch;

    switch (state[player]) {
    case 0:
        log_printf(DAT_0062c4fc, (const char*)0x582CC0, player);
        dpid[player] = 0; flag[player] = 0;
        break;
    case 1:
        log_printf(DAT_0062c4fc, (const char*)0x582CB0, player);
        dpid[player] = 0; flag[player] = 0;
        break;
    case 2:
        log_printf(DAT_0062c4fc, (const char*)0x582CA4, player);
        goto common;
    case 3:
        log_printf(DAT_0062c4fc, (const char*)0x582C94, player);
        goto common2;
    case 4:
        log_printf(DAT_0062c4fc, (const char*)0x582C88, player);
        goto common;
    case 5:
        flag[player] = 1;
        log_printf(DAT_0062c4fc, (const char*)0x582C78, player);
common:
        if (id == 0) {
            log_printf(DAT_0062c4fc, (const char*)0x582BBC, player);
            return;
        }
        size = 0;
        DAT_0062c5ec->vt->GetPlayerName(DAT_0062c5ec, id, 0, &size);
        name = (PlayerName*)calloc(size,1);
        hr = DAT_0062c5ec->vt->GetPlayerName(DAT_0062c5ec, id, name, &size);
        log_printf(lobby, (const char*)0x582C68, hr);
        if (hr == 0) {
            strcpy(playerShortNames + (player << 7), name->shortName);
            strcpy(playerLongNames + (player << 7), name->longName);
            state[player] = 2;
            free(name);
            break;
        }
        if (hr == (int)0x8877001e || hr == (int)0x80070057 || hr == (int)0x88770082) {
            log_printf(DAT_0062c4fc, (const char*)0x582BE8, hr);
            strcpy(playerShortNames + (player << 7), (const char*)0x582BE0);
            state[player] = 0;
            free(name);
            break;
        }
        if (hr == (int)0x88770096) {
            log_printf(DAT_0062c4fc, (const char*)0x582C28, id);
            if (mode == 3) {
                state[player] = 2;
                if (IsPlayerHuman(player)) {
                    log_printf(DAT_0062c4fc, (const char*)0x582C18);
                    log_printf(DAT_0062c4fc, (const char*)0x582130, id);
                    ch = '?';
                    log_printf(DAT_0062c4fc, (const char*)0x582C04, 8, &ch);
                    send_chat(0, &ch ? 8 : 8, 0, &ch, 0);
                    free(name);
                    break;
                }
            }
            free(name);
            break;
        }
        log_printf(DAT_0062c4fc, (const char*)0x582C48);
        state[player] = 0; dpid[player] = 0;
        free(name);
        break;
    case 6:
common2:
        log_printf(DAT_0062c4fc, (const char*)0x582BB0, player);
        dpid[player] = 0;
        flag[player] = 1;
        break;
    default:
        strcpy(playerShortNames + (player << 7), (const char*)0x582BA8);
        log_printf(DAT_0062c4fc, (const char*)0x582B80, player, state[player]);
        break;
    }
    if (do_update) update_ui(0x17A4);
}
