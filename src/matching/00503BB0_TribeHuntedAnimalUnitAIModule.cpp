// VA: 00503BB0, TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule
// Reworked with the exact taiuaimd.cpp UnitAIModule constructor pattern:
// visible virtual base dtor + /GX triggers the lightweight constructor EH frame;
// cache importantObjects[0], reload this->importantObjects for later source lines.
// FLAGS: config/flags/00503BB0_TribeHuntedAnimalUnitAIModule.rsp

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

class TribeHuntedAnimalUnitAIModule : public UnitAIModule {
public:
    TribeHuntedAnimalUnitAIModule(RGE_Static_Object* obj, int param);
};

TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x10;
    importantObjects = (int*)operator new(0x40);

    if (importantObjects) {
        importantObjects[0] = 0;
        this->importantObjects[1] = 4;
        this->importantObjects[2] = 0x1a;
        this->importantObjects[3] = 0x18;
        this->importantObjects[4] = 6;
        this->importantObjects[5] = 0x19;
        this->importantObjects[6] = 0x11;
        this->importantObjects[7] = 0xa;
        this->importantObjects[8] = 0xc;
        this->importantObjects[9] = 0x23;
        this->importantObjects[10] = 0x17;
        this->importantObjects[11] = 0x24;
        this->importantObjects[12] = 0x1c;
        this->importantObjects[13] = 0x12;
        this->importantObjects[14] = 0xd;
        this->importantObjects[15] = 0x27;
    }

    idleTimeoutValue = 0xFA0;
    setAdjustedIdleTimeout();
}
