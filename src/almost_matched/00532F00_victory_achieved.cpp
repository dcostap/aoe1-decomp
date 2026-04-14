// STATUS: almost_matched
// CLASS: setcc codegen mismatch
// RISK: low
// WHY: VC5 inserts xor eax,eax before sete al, generating mov/xor/cmp instead of
//      direct cmp byte [mem],imm; sete al. All flag combinations tested. Semantically identical.
// NEXT: TU context investigation or compiler service pack change
// FLAGS: config\flags\00532F00_victory_achieved.rsp

class RGE_Victory_Conditions {
public:
    char gap_0[0x10];
    unsigned char field_10;

    unsigned char victory_achieved();
};

unsigned char RGE_Victory_Conditions::victory_achieved() {
    return this->field_10 == 2;
}