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

    TRegistry(const char *name);
    ~TRegistry();
    int RegSet(int useUserKey, const char *name,
               unsigned char *value, unsigned long size);
    int RegSetInt(int useUserKey, const char *name, int value);
    int RegSetAscii(int useUserKey, const char *name,
                    unsigned char *value, unsigned long size);
    char *RegGetAscii(int useUserKey, const char *name);
    long RegGet(int useUserKey, const char *name,
                unsigned char *data, unsigned long *dataSize);
    int RegGetInt(int useUserKey, const char *name);
};

typedef char registry_size_check[(sizeof(TRegistry) == 0x110) ? 1 : -1];

#endif
