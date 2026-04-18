struct InnerObj {
    void method(short a, short b);
};
class TRIBE_World {
public:
    void send_cheat(short code);
    char pad[0x58];
    InnerObj* field_58;
    char pad2[0x20];
    short field_7C;
};
void TRIBE_World::send_cheat(short code) {
    this->field_58->method(this->field_7C, code);
}
