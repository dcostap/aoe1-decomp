#pragma once
#include "../common.h"

class TribeAIPlayBook : public AIPlayBook       {
public:
    char _pad_0x4[0x4C];

    TribeAIPlayBook();

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeAIPlayBook() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 (Override)
    virtual int convertTargetNameToIntType(char* param_1); // Ghidra: convertTargetNameToIntType

    // [Slot 02] Offset 0x08 (Override)
    virtual int convertTargetCharacteristicNameToIntType(char* param_1); // Ghidra: convertTargetCharacteristicNameToIntType

    // [Slot 03] Offset 0x0C (Override)
    virtual int convertUnitNameToIntType(char* param_1); // Ghidra: convertUnitNameToIntType

    // [Slot 04] Offset 0x10 (Override)
    virtual int convertUnitToIntType(RGE_Static_Object* param_1); // Ghidra: convertUnitToIntType

};

static_assert(sizeof(TribeAIPlayBook) == 0x50, "TribeAIPlayBook Size Mismatch");

