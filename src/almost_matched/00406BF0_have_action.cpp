// STATUS: almost_matched
// CLASS: setcc codegen mismatch
// RISK: low
// WHY: VC5 generates neg/sbb/neg (6 bytes) instead of test/setne (5 bytes) for bool conversion.
//      All flag combinations and source shapes tested. Semantically identical.
// NEXT: TU context investigation or compiler service pack change
// FLAGS: config\flags\00406BF0_have_action.rsp

class RGE_Action_List {
public:
    unsigned char have_action();
};

class RGE_Action_Object {
public:
    char gap_0[0x184];
    RGE_Action_List* actions;

    unsigned char have_action();
};

unsigned char RGE_Action_Object::have_action() {
    return this->actions->have_action() != 0;
}