#include <string.h>

#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleID {
public:
    virtual ~AIModuleID();
    int id;
    char name[64];

    void setID(int param_1, char* param_2);
};
#endif

void AIModuleID::setID(int param_1, char* param_2) {
    this->id = param_1;
    if (param_2 != 0) {
        strncpy(this->name, param_2, 0x3F);
        return;
    }
    strcpy(this->name, "");
}
