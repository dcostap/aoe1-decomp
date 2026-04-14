// STATUS: blocked
// FLAGS: config\flags\00532F00_victory_achieved.rsp
// BLOCKER: VC5 emits xor eax,eax before sete al; original lacks the xor
// NOTE: Original = cmp byte ptr [ecx+10h],2; sete al; ret (8B). All flag combos tried.
class RGE_Victory_Conditions {
public:
    virtual ~RGE_Victory_Conditions();
    char gap_4[0xC];
    unsigned char field_10;
    unsigned char victory_achieved();
};

unsigned char RGE_Victory_Conditions::victory_achieved() { return this->field_10 == 2; }
