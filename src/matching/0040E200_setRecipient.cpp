#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleID {
public:
    void setID(int a, char* b);
};

class AIModuleMessage {
public:
    char gap_0[0xD4];
    AIModuleID recipient;

    void setRecipient(int a, char* b);
};
#endif

void AIModuleMessage::setRecipient(int a, char* b) {
    this->recipient.setID(a, b);
}
