class MemberType {
public:
    void target_method2();
};

class RGE_Combat_Object {
public:
    char gap_0[0x184];
    MemberType* member_184;

    void target_method1(int param);
    void transform(int param);
};

void RGE_Combat_Object::transform(int param) {
    this->target_method1(param);
    this->member_184->target_method2();
}
