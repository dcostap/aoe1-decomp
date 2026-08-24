#ifndef AOE1_REGISTRY_CONTEXT_H
#define AOE1_REGISTRY_CONTEXT_H

// Canonical registry.cpp declarations. TRegistry stores three registry
// handles, a disposition value, and the 256-byte query buffer at offset 0x10.
#include <windows.h>

typedef LONG (WINAPI *RegCreateKeyExA_t)(
    HKEY, LPCSTR, DWORD, LPSTR, DWORD, REGSAM,
    LPSECURITY_ATTRIBUTES, PHKEY, LPDWORD);
extern RegCreateKeyExA_t RegCreateKeyExA_ptr;

typedef LONG (WINAPI *RegSetValueExA_t)(
    HKEY, LPCSTR, DWORD, DWORD, const BYTE*, DWORD);
extern RegSetValueExA_t RegSetValueExA_ptr;

typedef LONG (WINAPI *RegQueryValueExA_t)(
    HKEY, LPCSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD);
extern RegQueryValueExA_t RegQueryValueExA_ptr;

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

typedef char registry_context_size_check[(sizeof(TRegistry) == 0x110) ? 1 : -1];

#endif
