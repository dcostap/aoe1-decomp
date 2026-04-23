struct ObjectMemory {
    int id;
    char gap_04[0x20];
};

class TribeInformationAIModule {
public:
    char gap_000[0x110];
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;

    ObjectMemory* objectMemory(int param_1);
};

ObjectMemory* TribeInformationAIModule::objectMemory(int param_1) {
    int iVar1;
    ObjectMemory* pOVar2;
    ObjectMemory* base;

    if (param_1 != -1) {
        iVar1 = 0;
        if (0 < this->maxImportantObjectMemory) {
            base = this->importantObjectMemory;
            pOVar2 = base;
            while (iVar1 < this->maxImportantObjectMemory) {
                if (pOVar2->id == param_1) {
                    return base + iVar1;
                }
                iVar1 = iVar1 + 1;
                pOVar2 = pOVar2 + 1;
            }
            return 0;
        }
    }
    return 0;
}
