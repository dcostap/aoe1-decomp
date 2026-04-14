struct TribeInformationAIModule {
    char gap_0[0x120];
    int importantObjects[10];
    int numberImportantObjects;
};

int __fastcall addImportantObject(TribeInformationAIModule* self, int, int objectId) {
    if (self->numberImportantObjects >= 10)
        return 0;
    self->importantObjects[self->numberImportantObjects] = objectId;
    self->numberImportantObjects++;
    return 1;
}
