// STATUS: blocked
// FLAGS: config\flags\o2.rsp
// BLOCKER: VC5 insists on xor eax,eax before sete al but original lacks it
// NOTE: All flag combos and source shapes tried, sete codegen fundamental to VC5

class RGE_Victory_Conditions {
public:
    char gap_0[0x10];
    unsigned char field_10;
    unsigned char victory_achieved();
};

unsigned char RGE_Victory_Conditions::victory_achieved() {
    return this->field_10 == 2;
}
