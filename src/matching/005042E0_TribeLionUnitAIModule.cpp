// VA: 005042E0, TribeLionUnitAIModule::TribeLionUnitAIModule
// Same taiuaimd.cpp constructor pattern as TribeHuntedAnimalUnitAIModule: visible virtual base dtor + /GX for EH frame; reload member after first importantObjects store.
// FLAGS: config/flags/005042E0_TribeLionUnitAIModule.rsp

#include <stddef.h>
#ifndef TAIUAIMD_COMPLETE_TU

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

class TribeLionUnitAIModule : public UnitAIModule {
public:
    TribeLionUnitAIModule(RGE_Static_Object* obj, int param);
};
#endif

TribeLionUnitAIModule::TribeLionUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x11;
    importantObjects = (int*)operator new(0x44);

    if (importantObjects) {
        importantObjects[0] = 0x1d;
        this->importantObjects[1] = 9;
        this->importantObjects[2] = 0;
        this->importantObjects[3] = 4;
        this->importantObjects[4] = 0x1a;
        this->importantObjects[5] = 0x18;
        this->importantObjects[6] = 6;
        this->importantObjects[7] = 0x19;
        this->importantObjects[8] = 0x11;
        this->importantObjects[9] = 0xd;
        this->importantObjects[10] = 0xc;
        this->importantObjects[11] = 0x23;
        this->importantObjects[12] = 0x17;
        this->importantObjects[13] = 0x24;
        this->importantObjects[14] = 0x1c;
        this->importantObjects[15] = 0x12;
        this->importantObjects[16] = 0x27;
    }

    idleTimeoutValue = 0x1770;
    setAdjustedIdleTimeout();
}
