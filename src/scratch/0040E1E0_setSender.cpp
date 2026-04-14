class SubType {
public:
    void target_method(int a, int b);
};

class AIModuleMessage {
public:
    char gap_0[0x8C];
    SubType sub_8C;

    void setSender(int a, int b);
};

void AIModuleMessage::setSender(int a, int b) {
    this->sub_8C.target_method(a, b);
}
