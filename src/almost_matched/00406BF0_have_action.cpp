// STATUS: almost_matched
// CLASS: boolean-conversion-idiom
// RISK: low
// WHY: VC5 generates neg/sbb/neg for != 0 but original uses test al,al;setne al — identical semantics
// NEXT: investigate TU context or older compiler version
class MemberType {
public:
    unsigned char target_method();
};

class RGE_Action_Object {
public:
    char gap_0[0x184];
    MemberType* member_184;
    unsigned char have_action();
};

unsigned char RGE_Action_Object::have_action() {
    return this->member_184->target_method() != 0;
}
