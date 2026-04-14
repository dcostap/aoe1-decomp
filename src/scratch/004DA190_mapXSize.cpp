struct TribeInformationAIModule {
    char gap_0[0x104];
    int mapXSizeValue;
};

int __fastcall mapXSize(TribeInformationAIModule* self, int) {
    return self->mapXSizeValue;
}
