extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(void* key, const char* valueName, unsigned long* reserved, unsigned long* type, unsigned char* data, unsigned long* dataSize);

class TRegistry {
public:
    void* ghMachineKey;
    void* ghUserKey;
    void* ghMachineKeyRead;
    unsigned long gdwDisp;
    char Data[255];

    long RegGet(int useUserKey, char* valueName, unsigned char* data, unsigned long* dataSize);
};

// compact registry getter first
// expected basin: one branch on the selector, then RegQueryValueExA with the live key handle and the length slot reused as lpType storage
// remaining risk, if any, is only the exact stack-slot shape for the fourth argument
long TRegistry::RegGet(int useUserKey, char* valueName, unsigned char* data, unsigned long* dataSize) {
    if (useUserKey != 0) {
        return RegQueryValueExA(this->ghUserKey, valueName, 0, (unsigned long*)&dataSize, data, dataSize);
    }
    return RegQueryValueExA(this->ghMachineKeyRead, valueName, 0, (unsigned long*)&dataSize, data, dataSize);
}
