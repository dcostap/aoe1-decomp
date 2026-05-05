// VA: 00507880, TribeArtifactUnitAIModule::TribeArtifactUnitAIModule
// Donor: exact UnitAIModule-derived constructor shape from taiuaimd.cpp.
// FLAGS: config/flags/00507880_TribeArtifactUnitAIModule.rsp

#include <stddef.h>

void* operator new(size_t size);
struct RGE_Static_Object;

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    char pad_04[0xFC - 4];
    unsigned int adjustedIdleTimeoutValue;
    unsigned int idleTimeoutValue;
    char pad_104[0x124 - 0x104];
    int* importantObjects;
    int numberImportantObjects;

    UnitAIModule(RGE_Static_Object* obj, int param);
    void setAdjustedIdleTimeout(void);
};

class TribeArtifactUnitAIModule : public UnitAIModule {
public:
    TribeArtifactUnitAIModule(RGE_Static_Object* obj, int param);
};

TribeArtifactUnitAIModule::TribeArtifactUnitAIModule(
    RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x13;
    importantObjects = (int*)operator new(0x4C);

    if (importantObjects) {
        importantObjects[0] = 0;
        this->importantObjects[1] = 4;
        this->importantObjects[2] = 0x1A;
        this->importantObjects[3] = 0x18;
        this->importantObjects[4] = 6;
        this->importantObjects[5] = 0x23;
        this->importantObjects[6] = 0x19;
        this->importantObjects[7] = 0x11;
        this->importantObjects[8] = 0x0C;
        this->importantObjects[9] = 0x17;
        this->importantObjects[10] = 0x24;
        this->importantObjects[11] = 0x1C;
        this->importantObjects[12] = 0x12;
        this->importantObjects[13] = 0x0D;
        this->importantObjects[14] = 0x16;
        this->importantObjects[15] = 0x14;
        this->importantObjects[16] = 2;
        this->importantObjects[17] = 0x15;
        this->importantObjects[18] = 0x27;
    }

    idleTimeoutValue = 0x1388;
    setAdjustedIdleTimeout();
}
