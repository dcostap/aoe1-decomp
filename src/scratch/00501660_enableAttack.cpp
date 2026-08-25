#ifndef TAITACMD_SHARED_CONTEXT
#ifndef TAITACMD_SHARED_CONTEXT
struct TribeTacticalAIModule {
    char gap_0[0x3AC];
    int field_3AC;          // 0x3AC
    char gap_3B0[0xA68];
    int attackEnabled;      // 0xE18
};

#endif
void __fastcall enableAttack(TribeTacticalAIModule* self, int, int param) {
    if (self->attackEnabled == 1)
        return;
    if (self->field_3AC != 0 && self->field_3AC != param)
        return;
    self->attackEnabled = 1;
}
#else
void TribeTacticalAIModule::enableAttack(int) {}
#endif
