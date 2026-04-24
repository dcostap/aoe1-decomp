// attempt 1: __cdecl, had add esp,18h cleanup -> mismatch at offset 9
// attempt 2: __stdcall (no dllimport), size 80 (1 byte short)
// attempt 3: __stdcall + ret temp, still 80
// attempt 4: __stdcall, restructure, still 80
// attempt 5: dllimport __stdcall, size 81, mismatch at 35 (ecx vs edx for return temp)
// attempt 6: explicit if-return-0/1, same register issue
// attempt 7: added vtable, would shift offsets, rolled back
// attempt 8: unsigned char temp -> edx basin, but test al,al instead of test eax,eax
// attempt 9: unsigned long temp to get test eax,eax

extern "C" __declspec(dllimport) unsigned long __stdcall RegSetValueExA(void* key, const char* valueName, unsigned long reserved, unsigned long type, const unsigned char* data, unsigned long dataSize);

class TRegistry {
public:
    void* ghMachineKey;
    void* ghUserKey;

    int RegSetInt(int useUserKey, const char* valueName, int value);
};

int TRegistry::RegSetInt(int useUserKey, const char* valueName, int value) {
    unsigned long ret;
    if (useUserKey != 0) {
        ret = RegSetValueExA(ghUserKey, valueName, 0, 4, (const unsigned char*)&value, 4);
    }
    else {
        ret = RegSetValueExA(ghMachineKey, valueName, 0, 4, (const unsigned char*)&value, 4);
    }
    return (ret == 0);
}
