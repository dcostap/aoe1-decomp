// VA: 00508170, TribeBuildingUnitAIModule::TribeBuildingUnitAIModule
// Donor: exact UnitAIModule-derived constructor shape from taiuaimd.cpp.
// FLAGS: config/flags/00508170_TribeBuildingUnitAIModule.rsp

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

class TribeBuildingUnitAIModule : public UnitAIModule {
public:
    TribeBuildingUnitAIModule(RGE_Static_Object* obj, int param);
};

TribeBuildingUnitAIModule::TribeBuildingUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x15;
    importantObjects = (int*)operator new(0x54);

    if (importantObjects) {
        importantObjects[0] = 0;
        this->importantObjects[1] = 3;
        this->importantObjects[2] = 4;
        this->importantObjects[3] = 0x1A;
        this->importantObjects[4] = 0x18;
        this->importantObjects[5] = 6;
        this->importantObjects[6] = 0x23;
        this->importantObjects[7] = 0x19;
        this->importantObjects[8] = 0x11;
        this->importantObjects[9] = 0x0C;
        this->importantObjects[10] = 0x17;
        this->importantObjects[11] = 0x24;
        this->importantObjects[12] = 0x1C;
        this->importantObjects[13] = 0x12;
        this->importantObjects[14] = 0x0D;
        this->importantObjects[15] = 0x1B;
        this->importantObjects[16] = 0x16;
        this->importantObjects[17] = 0x14;
        this->importantObjects[18] = 2;
        this->importantObjects[19] = 0x15;
        this->importantObjects[20] = 0x27;
    }
}
