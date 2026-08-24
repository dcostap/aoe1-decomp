// EnumPlayersCallback2 (0042F040)
// PDB source: Com_hand.cpp:6801-6823
// Size: 196 bytes
// Calling convention: __stdcall

extern "C" int __cdecl sprintf(char* buf, const char* fmt, ...);
#if !defined(COM_HAND_TU_CONTEXT)
extern "C" void Log(void* log, const char* fmt, ...);
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
struct DPNAME {
    unsigned long dwSize;       // +0x00
    unsigned long dwFlags;      // +0x04
    char* lpszShortName;        // +0x08  (ANSI version)
    char* lpszLongName;         // +0x0C
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    void UpdatePlayerInformation(unsigned long param_1, char* shortName, char* longName);
};
#endif // COM_HAND_TU_CONTEXT


// Globals
#if !defined(COM_HAND_TU_CONTEXT)
extern void* L;                       // [0x62C4FC] TDebuggingLog*
#endif // COM_HAND_TU_CONTEXT
extern char DAT_0062c5f0[];           // [0x62C5F0] sprintf buffer

int __stdcall EnumPlayersCallback2(
    unsigned long param_1,
    unsigned long param_2,
    DPNAME* param_3,
    unsigned long param_4,
    void* param_5)
{
    int i;
    int foundIndex;
    if (param_1 != 0) {
        i = *(unsigned short*)((char*)param_5 + 0x1712);
        int endIndex = *(unsigned short*)((char*)param_5 + 0x1710);
        if (i <= endIndex) {
            unsigned long* array = (unsigned long*)((char*)param_5 + 0x1564);
            for (; i <= endIndex; i++) {
                if (array[i] == param_1) {
                    foundIndex = i;
                    goto logging;
                }
            }
        }
    }
    foundIndex = 0;

logging:
    sprintf(DAT_0062c5f0, "ENUM %d name=%s id=%d", param_1, param_3->lpszShortName, foundIndex);
    Log(L, "ENUM DEBUG: %s", DAT_0062c5f0);
    Log(L, "FORCEENUM %d name=%s id=%d", param_1, param_3->lpszShortName, foundIndex);
    Log(L, "FILL PLAYER INFORMATION.");
    ((TCommunications_Handler*)param_5)->UpdatePlayerInformation(param_1, (char*)param_3->lpszShortName, (char*)param_3->lpszLongName);
    return 1;
}
