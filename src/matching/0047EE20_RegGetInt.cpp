// From registry.cpp

typedef struct HKEY__ *HKEY;

typedef long (__stdcall *RegQueryValueExA_t)(HKEY, const char*, unsigned long*, unsigned long*, unsigned char*, unsigned long*);

extern RegQueryValueExA_t RegQueryValueExA_ptr;

class TRegistry {
public:
    HKEY ghDefaultKey;
    HKEY ghUserKey;
    HKEY ghMachineKeyRead;

    int RegGetInt(int use_user, const char* name);
};

int TRegistry::RegGetInt(int use_user, const char* name) {
    unsigned long dwSize = 4;
    unsigned long dwType = 4;
    int result;
    long err;
    if (use_user) {
        err = RegQueryValueExA_ptr(this->ghUserKey, name, 0, &dwType, (unsigned char*)&result, &dwSize);
    } else {
        err = RegQueryValueExA_ptr(this->ghMachineKeyRead, name, 0, &dwType, (unsigned char*)&result, &dwSize);
    }
    if (err == 0) {
        return result;
    }
    return -1;
}
