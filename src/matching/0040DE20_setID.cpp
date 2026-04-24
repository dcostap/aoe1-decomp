#include <string.h>

class AIModuleID {
public:
    void* vtable_ptr;
    int id;
    char name[64];

    void setID(int param_1, char* param_2);
};

void AIModuleID::setID(int param_1, char* param_2) {
    this->id = param_1;
    if (param_2 != 0) {
        strncpy(this->name, param_2, 0x3F);
        return;
    }
    strcpy(this->name, "");
}
