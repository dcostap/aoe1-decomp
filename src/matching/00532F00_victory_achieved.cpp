class RGE_Victory_Conditions {
public:
    char gap_0[0x10];
    unsigned char field_10;

    unsigned char victory_achieved(void);
};

unsigned char RGE_Victory_Conditions::victory_achieved(void) {
    if (this->field_10 == 2) {
        return 1;
    }
    return 0;
}
