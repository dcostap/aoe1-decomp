struct RGE_Victory_Conditions {
    char gap_0[0x10];
    unsigned char field_10;
};

unsigned char __fastcall victory_achieved(struct RGE_Victory_Conditions* this_) {
    return this_->field_10 == 2;
}
