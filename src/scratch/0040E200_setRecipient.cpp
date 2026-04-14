class SubType {
public:
    void target_method(int a, int b);
};

class AIModuleMessage {
public:
    char gap_0[0xD4];
    SubType sub_D4;

    void setRecipient(int a, int b);
};

void AIModuleMessage::setRecipient(int a, int b) {
    this->sub_D4.target_method(a, b);
}
