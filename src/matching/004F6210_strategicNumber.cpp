struct TribeTacticalAIModule {
    char gap_0[0x194];
    int strategicNumbers[226];
};

int __fastcall strategicNumber(TribeTacticalAIModule* self, int, int index) {
    if (index < 0 || index >= 226)
        return -1;
    return self->strategicNumbers[index];
}
