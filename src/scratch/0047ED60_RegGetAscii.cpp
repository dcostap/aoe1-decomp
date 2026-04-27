// RegGetAscii (0047ED60, 98 bytes, registry.cpp)
// Attempt 3: match local order and two-path convergence

long __stdcall RegQueryValueExA(void* hKey, const char* lpValueName, void* lpReserved,
    unsigned long* lpType, void* lpData, unsigned long* lpcbData);

class TRegistry {
public:
    char Data[256];
    void* ghUserKey;
    void* ghMachineKeyRead;

    char* RegGetAscii(int userKey, const char* name);
};

char* TRegistry::RegGetAscii(int userKey, const char* name) {
    unsigned long dwType = 0xFF;
    unsigned long dwSize = 1;

    if (userKey != 0) {
        RegQueryValueExA(ghUserKey, name, 0, &dwType, Data, &dwSize);
    } else {
        RegQueryValueExA(ghMachineKeyRead, name, 0, &dwType, Data, &dwSize);
    }
    return Data;
}
