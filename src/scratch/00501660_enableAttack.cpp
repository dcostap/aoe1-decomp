struct TribeTacticalAIModule {
    char gap_0[0xE18];
    int attackEnabled;
};

void __fastcall enableAttack(TribeTacticalAIModule* self, int, int enable) {
    self->attackEnabled = enable;
}
