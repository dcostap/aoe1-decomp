// AIPlayPhaseTrigger constructor
// ret 18h = 6 stack params + this in ecx

struct AIPlayPhaseTrigger {
    unsigned char field_0;
    char gap_1[3];
    int field_4;
    int field_8;
    unsigned char field_C;
    unsigned char field_D;
    char gap_E[2];
    int field_10;
};

AIPlayPhaseTrigger* __fastcall AIPlayPhaseTrigger_ctor(AIPlayPhaseTrigger* self, int /*edx*/, unsigned char p1, int p2, int p3, unsigned char p4, unsigned char p5, int p6) {
    self->field_0 = p1;
    self->field_4 = p2;
    self->field_8 = p3;
    self->field_C = p4;
    self->field_D = p5;
    self->field_10 = p6;
    return self;
}
