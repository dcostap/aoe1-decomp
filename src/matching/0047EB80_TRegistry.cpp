// TRegistry::TRegistry (0047EB80, 124 bytes, registry.cpp)
// Attempt 1

typedef struct HKEY__ *HKEY;

typedef long (__stdcall *RegCreateKeyExA_t)(HKEY, const char*, unsigned long, const char*, unsigned long, unsigned long, void*, HKEY*, unsigned long*);

extern RegCreateKeyExA_t RegCreateKeyExA_ptr;

class TRegistry {
public:
    HKEY ghMachineKey;
    HKEY ghUserKey;
    HKEY ghMachineKeyRead;
    unsigned long gdwDisp;

    TRegistry(const char* name);
};

TRegistry::TRegistry(const char* name) {
    this->ghMachineKey = 0;
    this->ghUserKey = 0;
    this->ghMachineKeyRead = 0;
    RegCreateKeyExA_ptr((HKEY)0x80000001, name, 0, 0, 0, 0xf003f, 0, &this->ghUserKey, &this->gdwDisp);
    RegCreateKeyExA_ptr((HKEY)0x80000002, name, 0, 0, 0, 0xf003f, 0, &this->ghMachineKey, &this->gdwDisp);
    RegCreateKeyExA_ptr((HKEY)0x80000002, name, 0, 0, 0, 1, 0, &this->ghMachineKeyRead, &this->gdwDisp);
}
