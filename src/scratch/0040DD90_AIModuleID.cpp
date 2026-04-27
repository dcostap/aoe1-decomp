// AIModuleID::AIModuleID (0040DD90, 92 bytes, aimodule.cpp)
// Attempt 3: use strcpy instead of memcpy

char* strncpy(char* dest, const char* src, unsigned int count);
char* strcpy(char* dest, const char* src);

class AIModuleID {
public:
    void* vtable;
    int id;
    char name[0x3F];

    AIModuleID(const char* name, int id);
};

AIModuleID::AIModuleID(const char* name, int id) {
    this->id = id;
    this->vtable = (void*)0x56E928;
    if (name != 0) {
        strncpy(this->name, name, 0x3F);
    } else {
        strcpy(this->name, "");
    }
}
