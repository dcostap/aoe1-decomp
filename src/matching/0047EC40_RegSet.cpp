// From registry.cpp

typedef struct HKEY__ *HKEY;

typedef long (__stdcall *RegSetValueExA_t)(HKEY, const char*, unsigned long, unsigned long, const unsigned char*, unsigned long);

extern RegSetValueExA_t RegSetValueExA_ptr;

class TRegistry {
public:
    HKEY ghDefaultKey;
    HKEY ghUserKey;

    int RegSet(int param_1, const char* name, unsigned char* value, unsigned long size);
};

int TRegistry::RegSet(int use_user, const char* name, unsigned char* value, unsigned long size) {
    long err;
    if (use_user) {
        err = RegSetValueExA_ptr(this->ghUserKey, name, 0, 4, value, size);
    } else {
        err = RegSetValueExA_ptr(this->ghDefaultKey, name, 0, 4, value, size);
    }
    return (err == 0);
}
