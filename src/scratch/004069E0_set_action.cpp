class MemberType {
public:
    void target_method(int param);
};

class RGE_Action_Object {
public:
    char gap_0[0x184];
    MemberType* member_184;

    void set_action(int param);
};

void RGE_Action_Object::set_action(int param) {
    if (param) {
        this->member_184->target_method(param);
    }
}
