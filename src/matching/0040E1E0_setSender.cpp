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

void AIModuleMessage::setSender(int a, char* b) {
    this->sender.setID(a, b);
}
