// RegGetAscii (0047ED60, 98 bytes, registry.cpp)
//
// Attempt log:
// - attempt 1 (scratch): wrong TRegistry layout (Data before handles), wrong call type (direct vs IAT), no error-checked return
// - probe 1: fixed class layout to ghMachineKey(0)/ghUserKey(4)/ghMachineKeyRead(8)/gdwDisp(0xC)/Data(0x10),
//            used extern function pointer for IAT-resolved call, added error-checked return with ternary.
//            Diff dropped from 72 to 4 bytes — only init store order mismatched.
// - probe 2: swapped local declaration order (dwSize first, dwType second) to match VC5's init-store order.
//            EXACT MATCH at 0.0000% diff.

typedef long (__stdcall *RegQueryValueExA_t)(void*, const char*, unsigned long*, unsigned long*, unsigned char*, unsigned long*);
extern RegQueryValueExA_t RegQueryValueExA_ptr;

class TRegistry {
public:
    void* ghMachineKey;       // offset 0x00
    void* ghUserKey;          // offset 0x04
    void* ghMachineKeyRead;   // offset 0x08
    unsigned long gdwDisp;    // offset 0x0C
    char Data[256];           // offset 0x10

    char* RegGetAscii(int userKey, const char* name);
};

char* TRegistry::RegGetAscii(int userKey, const char* name) {
    unsigned long dwSize = 1;
    unsigned long dwType = 0xFF;

    if (userKey != 0) {
        return RegQueryValueExA_ptr(ghUserKey, name, 0, &dwSize, (unsigned char*)Data, &dwType) ? 0 : Data;
    } else {
        return RegQueryValueExA_ptr(ghMachineKeyRead, name, 0, &dwSize, (unsigned char*)Data, &dwType) ? 0 : Data;
    }
}
