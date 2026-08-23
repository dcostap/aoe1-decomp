struct AIPlayPhaseCommand {
    unsigned char field_0;
    unsigned char field_1;
    char gap_2[2];
    int field_4;
    int field_8;
    int field_C;
};

AIPlayPhaseCommand* __fastcall AIPlayPhaseCommand_ctor(AIPlayPhaseCommand* self, int, unsigned char p1, unsigned char p2, int p3, int p4, int p5) {
    self->field_0 = p1;
    self->field_1 = p2;
    self->field_4 = p3;
    self->field_8 = p4;
    self->field_C = p5;
    return self;
}
