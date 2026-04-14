class MemberType {
public:
    void target_method2();
};

class TRIBE_Building_Object {
public:
    char gap_0[0x1D4];
    MemberType* member_1D4;

    void target_method1();
    void rehook();
};

void TRIBE_Building_Object::rehook() {
    this->target_method1();
    this->member_1D4->target_method2();
}
