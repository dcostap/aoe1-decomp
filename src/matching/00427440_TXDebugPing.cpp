// VA: 00427440 TCommunications_Handler::TXDebugPing (99 B)
// PDB source: Com_hand.cpp lines 1169-1187

extern "C" unsigned long __cdecl debug_timeGetTime(char* path, int line);

extern void* DAT_0062c4fc;  // TDebuggingLog* L
void __cdecl debug_log(void* log, const char* fmt, ...);

extern char _str_path[];    // "C:\msdev\work\age1_x1\Com_hand.cpp" at 0x580BF4
extern char _str_fmt[];     // "  >TX DEBUG PING #%d (%d)" at 0x581050

extern unsigned char DAT_0062c5d8;  // packet type byte
extern unsigned long DAT_0062c5dc;  // timestamp dword
extern unsigned long DAT_0062c5e0;  // turn dword

class TCommunications_Handler {
public:
    char gap_00[0x10C8];
    unsigned long current_turn;  // +0x10C8

    long FastSend(int a, void* data, int len, int b, int c);
    int TXDebugPing(void);
};

int TCommunications_Handler::TXDebugPing(void) {
    DAT_0062c5d8 = 0x33;

    unsigned long t = debug_timeGetTime(_str_path, 0x496);
    DAT_0062c5dc = t;
    DAT_0062c5e0 = this->current_turn;

    debug_log(DAT_0062c4fc, _str_fmt, 0, 0x0C);

    long result = this->FastSend(0, &DAT_0062c5d8, 0x0C, 0, 0);
    return (result == 0);
}
