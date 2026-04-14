class MemberType {
public:
    void target_method1();
};

class RGE_Combat_Object {
public:
    char gap_0[0x184];
    MemberType* member_184;

    void target_method2();
    void destroy_obj();
};

void RGE_Combat_Object::destroy_obj() {
    this->member_184->target_method1();
    this->target_method2();
}
