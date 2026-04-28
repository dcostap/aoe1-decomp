// 00506B70 TribeFishingShipUnitAIModule::TribeFishingShipUnitAIModule(RGE_Static_Object*, int)
// Constructor, EH frame — needs /GX flag
// Source: taiuaimd.cpp lines 2155-2168
// Size: 207 bytes
//
// MATCHED. Exact 207-byte match confirmed via local check_function.py.
//
// Key findings:
// - /GX needed for EH prologue/epilogue (fs:[0] save/restore with handler)
// - Virtual ~UnitAIModule() needed to trigger constructor EH frame
//   (operator new alone insufficient in single-function TU)
// - this->importantObjects[i] for writes 1-7 forces per-index reload from [esi+124h]
//   matching original's mov reg,[esi+124h]; mov [reg+offset],val pattern
// - importantObjects at +0x124, numberImportantObjects at +0x128

#include <stddef.h>

void* operator new(size_t size);

struct RGE_Static_Object;

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    char pad[0x124 - 4];
    int* importantObjects; // +0x124
    int numberImportantObjects; // +0x128

    UnitAIModule(RGE_Static_Object* obj, int param);
};

class TribeFishingShipUnitAIModule : public UnitAIModule {
public:
    TribeFishingShipUnitAIModule(RGE_Static_Object* obj, int param);
};

TribeFishingShipUnitAIModule::TribeFishingShipUnitAIModule(
    RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 8;
    importantObjects = (int*)operator new(0x20);

    if (importantObjects) {
        importantObjects[0] = 3;
        this->importantObjects[1] = 0x16;
        this->importantObjects[2] = 0x14;
        this->importantObjects[3] = 2;
        this->importantObjects[4] = 0x15;
        this->importantObjects[5] = 5;
        this->importantObjects[6] = 0x1F;
        this->importantObjects[7] = 0x21;
    }
}
