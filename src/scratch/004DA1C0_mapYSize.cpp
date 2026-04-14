struct TribeInformationAIModule {
    char gap_0[0x108];
    int mapYSizeValue;
};

int __fastcall mapYSize(TribeInformationAIModule* self, int) {
    return self->mapYSizeValue;
}
