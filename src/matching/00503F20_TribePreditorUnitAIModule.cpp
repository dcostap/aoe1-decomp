// VA: 00503F20, TribePreditorUnitAIModule::TribePreditorUnitAIModule, 328 bytes
// Source: taiuaimd.cpp lines 177-202
// FLAGS: /GX (EH frame for operator new + parent constructor)
//
// Key findings:
// - /GX needed for EH prologue/epilogue (fs:[0] save/restore with handler)
// - Virtual ~UnitAIModule() needed to trigger constructor EH frame
// - importantObjects[0] uses cached pointer; this->importantObjects[i] for i>=1
//   forces per-index reload from [esi+124h] with edx/eax/ecx register cycling
// - The canonical 0x134 base preserves exact /GX code and the PAV constructor symbol.

#include <stddef.h>
#include "../../include/taiuaimd_context.h"

void* operator new(size_t size);

TribePreditorUnitAIModule::TribePreditorUnitAIModule(
    RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x11;
    importantObjects = (int*)operator new(0x44);

    if (importantObjects) {
        importantObjects[0] = 0x1D;
        this->importantObjects[1] = 0x09;
        this->importantObjects[2] = 0x00;
        this->importantObjects[3] = 0x04;
        this->importantObjects[4] = 0x1A;
        this->importantObjects[5] = 0x18;
        this->importantObjects[6] = 0x06;
        this->importantObjects[7] = 0x19;
        this->importantObjects[8] = 0x11;
        this->importantObjects[9] = 0x0D;
        this->importantObjects[10] = 0x0C;
        this->importantObjects[11] = 0x23;
        this->importantObjects[12] = 0x17;
        this->importantObjects[13] = 0x24;
        this->importantObjects[14] = 0x1C;
        this->importantObjects[15] = 0x12;
        this->importantObjects[16] = 0x27;
    }
}
