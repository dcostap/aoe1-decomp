class MemberType {
public:
    unsigned char target_method();
};

class RGE_Action_Object {
public:
    char gap_0[0x184];
    MemberType* member_184;

    int have_action();
};

int RGE_Action_Object::have_action() {
    return this->member_184->target_method() != 0;
}
