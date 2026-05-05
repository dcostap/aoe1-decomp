// VA: 00504B60, TribeCivilianUnitAIModule::TribeCivilianUnitAIModule
// Reworked with the exact taiuaimd.cpp UnitAIModule constructor pattern:
// visible virtual base dtor + /GX triggers the lightweight constructor EH frame;
// cache importantObjects[0], reload this->importantObjects for later source lines.
// FLAGS: config/flags/00504B60_TribeCivilianUnitAIModule.rsp

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

class TribeCivilianUnitAIModule : public UnitAIModule {
public:
    TribeCivilianUnitAIModule(RGE_Static_Object* obj, int param);
};

TribeCivilianUnitAIModule::TribeCivilianUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0xb;
    importantObjects = (int*)operator new(0x2c);

    if (importantObjects) {
        importantObjects[0] = 3;
        this->importantObjects[1] = 7;
        this->importantObjects[2] = 8;
        this->importantObjects[3] = 9;
        this->importantObjects[4] = 0xa;
        this->importantObjects[5] = 0xf;
        this->importantObjects[6] = 0x11;
        this->importantObjects[7] = 0x12;
        this->importantObjects[8] = 0x20;
        this->importantObjects[9] = 0x21;
        this->importantObjects[10] = 0x1b;
    }
}
