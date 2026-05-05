// VA: 00506240, TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule
// Reworked with the exact taiuaimd.cpp UnitAIModule constructor pattern:
// visible virtual base dtor + /GX triggers the lightweight constructor EH frame.
// FLAGS: config/flags/00506240_TribeTradeShipUnitAIModule.rsp

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
};

class TribeTradeShipUnitAIModule : public UnitAIModule {
public:
    TribeTradeShipUnitAIModule(RGE_Static_Object* obj, int param);
};

TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 5;
    importantObjects = (int*)operator new(0x14);

    if (importantObjects) {
        importantObjects[0] = 3;
        this->importantObjects[1] = 0x16;
        this->importantObjects[2] = 0x14;
        this->importantObjects[3] = 2;
        this->importantObjects[4] = 0x15;
    }
}
