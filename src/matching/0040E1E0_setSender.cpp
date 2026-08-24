#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleID {
public:
    void setID(int a, char* b);
};

class AIModuleMessage {
public:
    char gap_0[0x8C];
    AIModuleID sender;

    void setSender(int a, char* b);
};
#endif

void AIModuleMessage::setSender(int a, char* b) {
    this->sender.setID(a, b);
}
