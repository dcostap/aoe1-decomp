#ifndef AOE1_REGISTRY_H
#define AOE1_REGISTRY_H

#include <windows.h>

// TRegistry stores three registry handles, a disposition value, and the
// 256-byte query buffer at offset 0x10.

class TRegistry {
  public:
    HKEY ghMachineKey;
    HKEY ghUserKey;
    HKEY ghMachineKeyRead;
    unsigned long gdwDisp;
    char Data[256];

    TRegistry(const char* Key);
    ~TRegistry();
    int RegSet(int UseUserKey, const char* lptszName, unsigned char* lpData, unsigned long dwSize);
    int RegSetInt(int UseUserKey, const char* lptszName, int Value);
    int RegSetAscii(int UseUserKey, const char* lptszName, unsigned char* lpData, unsigned long dwSize);
    char* RegGetAscii(int UseUserKey, const char* lptszName);
    long RegGet(int UseUserKey, const char* lptszName, unsigned char* lpData, unsigned long* lpdwDataSize);
    int RegGetInt(int UseUserKey, const char* lptszName);
};

typedef char registry_size_check[(sizeof(TRegistry) == 0x110) ? 1 : -1];

#endif
