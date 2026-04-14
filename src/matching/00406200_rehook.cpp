class MemberType {
public:
    void target_method2();
};

class RGE_Combat_Object {
public:
    char gap_0[0x184];
    MemberType* member_184;

    void target_method1();
    void rehook();
};

void RGE_Combat_Object::rehook() {
    this->target_method1();
    this->member_184->target_method2();
}
