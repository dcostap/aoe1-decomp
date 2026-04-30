// 00426350 TCommunications_Handler::KillAnyMissingPlayers()
// Source: Com_hand.cpp lines 383-431
// Size: 247 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: PARKED — VC5 TU-context drift
// Complex function with virtual dispatch + multiple extern calls + globals
//
// Attempt log:
// Probe 1: extern C functions, __stdcall virtual call — 81.4% positional diff
// Probe 2: __thiscall member, extern C helpers — 82.6% positional diff
// Probe 3: member functions for helpers — goto issues
// Probe 4: declared vars at top — 82.6% positional diff
//
// Key findings:
// - +0x12D8: MaxGamePlayers (unsigned short)
// - +0x1568: player_dcoID[] (int array, 1-based indexing)
// - +0x10C8: current_turn (used as TDebuggingLog* for log calls)
// - +0x13C0 = +0x1568 - 0x1A8: flag (if 0, calls DropDeadPlayer)
// - Virtual calls at vtable[0x54] through global at [62C5ECh]
// - DebugLog: ecx=current_turn, stack=(g_pDebugObj[62C4FCh], fmt[580D40h], playerIdx, 0x0C)
// - operator_new at 0054B6F0h, operator_delete at 0054B660h
// - IsPlayerHuman (0042CCD0h): __thiscall ecx=this, stack=playerIdx
// - CommOut (0042B270h): __thiscall ecx=this, stack=(0, 0x4B, &kp, 0x0C, 0)
// - DropDeadPlayer (00428B10h): __thiscall ecx=this, stack=(playerIdx, dcoID)
//
// Remaining drift (VC5 TU-context):
// - Stack layout differs (more/less locals declared)
// - Register allocation (ebx/edi/esi/ebp choices)
// - Virtual dispatch calling convention (__thiscall vs __cdecl)
// - All external calls are placeholders (relocations)

extern "C" void* _new(unsigned int);
extern "C" void _delete(void*);

extern void* g_pNetObject;  // [62C5ECh]

struct TCommunications_Handler {
    char pad_000[0x10C8];
    int current_turn;              // +0x10C8
    char pad_10CC[0x12D8 - 0x10CC];
    unsigned short MaxGamePlayers; // +0x12D8
    char pad_12DA[0x1568 - 0x12DA];
    int player_dcoID[1];           // +0x1568

    void KillAnyMissingPlayers();
    int IsPlayerHuman(int player);
    int CommOut(int unk1, int msgType, void* data, int size, int flag);
    int DropDeadPlayer(int player, int dcoID);
};

struct TDebuggingLog {
    void Log(void* obj, const char* fmt, int player, int size);
};

void TCommunications_Handler::KillAnyMissingPlayers()
{
    int hr;
    void* buf;
    int playerNo;
    int* netObj;
    int* objVtable;
    int kp[3];

    if (MaxGamePlayers == 0)
        return;

    int playerIdx = 1;
    int* dcoID = player_dcoID;

    do {
        if (!IsPlayerHuman(playerIdx))
            goto next;

        netObj = (int*)g_pNetObject;
        objVtable = *(int**)netObj;
        hr = 0;

        ((int (__stdcall*)(int*, int, int, int*))objVtable[0x54 / 4])(netObj, *dcoID, 0, &hr);

        buf = _new(hr);
        playerNo = ((int (__stdcall*)(int*, int, void*, int*))objVtable[0x54 / 4])(netObj, *dcoID, buf, &hr);
        _delete(buf);

        if (playerNo == 0)
            goto next;

        ((TDebuggingLog*)current_turn)->Log(g_pNetObject, (const char*)0x580D40, playerIdx, 0x0C);

        kp[0] = *dcoID;
        kp[1] = playerNo;
        kp[2] = current_turn;
        CommOut(0, 0x4B, kp, 0x0C, 0);

        if (*(int*)((char*)dcoID - 0x1A8) == 0)
            DropDeadPlayer(playerIdx, *dcoID);

next:
        playerIdx++;
        dcoID++;
    } while (playerIdx <= (int)(unsigned short)MaxGamePlayers);
}
