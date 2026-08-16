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

void AIModuleMessage::setRecipient(int a, char* b) {
    this->recipient.setID(a, b);
}
