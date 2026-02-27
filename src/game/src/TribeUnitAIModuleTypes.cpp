#include "../include/TribeUnitAIModules.h"

#include <new>

namespace {
void initializeImportantObjects(UnitAIModule* module, const int* values, int count) {
    module->numberImportantObjects = count;
    module->importantObjects = new (std::nothrow) int[count];
    if (module->importantObjects == nullptr) {
        return;
    }

    for (int i = 0; i < count; ++i) {
        module->importantObjects[i] = values[i];
    }
}

void setField100(UnitAIModule* module, int value) {
    *reinterpret_cast<int*>(reinterpret_cast<char*>(module) + 0x100) = value;
}
} // namespace

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00507880
TribeArtifactUnitAIModule::TribeArtifactUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {0, 4, 0x1A, 0x18, 6, 0x23, 0x19, 0x11, 0x0C, 0x17, 0x24, 0x1C, 0x12, 0x0D, 0x16, 0x14, 2, 0x15, 0x27};
    initializeImportantObjects(this, kImportantObjects, 0x13);
    setField100(this, 5000);
    setAdjustedIdleTimeout();
}

TribeArtifactUnitAIModule::~TribeArtifactUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504B60
TribeCivilianUnitAIModule::TribeCivilianUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {3, 7, 8, 9, 10, 0x0F, 0x11, 0x12, 0x20, 0x21, 0x1B};
    initializeImportantObjects(this, kImportantObjects, 0x0B);
}

TribeCivilianUnitAIModule::~TribeCivilianUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00505820
TribePriestUnitAIModule::TribePriestUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {3, 0, 4, 0x1A, 0x18, 6, 0x19, 0x11, 10, 0x0C, 0x23, 0x17, 0x24, 0x1C, 0x12, 0x0D, 0x27};
    initializeImportantObjects(this, kImportantObjects, 0x11);
}

TribePriestUnitAIModule::~TribePriestUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00503BB0
TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {0, 4, 0x1A, 0x18, 6, 0x19, 0x11, 10, 0x0C, 0x23, 0x17, 0x24, 0x1C, 0x12, 0x0D, 0x27};
    initializeImportantObjects(this, kImportantObjects, 0x10);
    setField100(this, 4000);
    setAdjustedIdleTimeout();
}

TribeHuntedAnimalUnitAIModule::~TribeHuntedAnimalUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504170
TribeElephantUnitAIModule::TribeElephantUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {}

TribeElephantUnitAIModule::~TribeElephantUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x005042E0
TribeLionUnitAIModule::TribeLionUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {0x1D, 9, 0, 4, 0x1A, 0x18, 6, 0x19, 0x11, 0x0D, 0x0C, 0x23, 0x17, 0x24, 0x1C, 0x12, 0x27};
    initializeImportantObjects(this, kImportantObjects, 0x11);
    setField100(this, 6000);
    setAdjustedIdleTimeout();
}

TribeLionUnitAIModule::~TribeLionUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00503F20
TribePreditorUnitAIModule::TribePreditorUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {0x1D, 9, 0, 4, 0x1A, 0x18, 6, 0x19, 0x11, 0x0D, 0x0C, 0x23, 0x17, 0x24, 0x1C, 0x12, 0x27};
    initializeImportantObjects(this, kImportantObjects, 0x11);
}

TribePreditorUnitAIModule::~TribePreditorUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00506B70
TribeFishingShipUnitAIModule::TribeFishingShipUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {3, 0x16, 0x14, 2, 0x15, 5, 0x1F, 0x21};
    initializeImportantObjects(this, kImportantObjects, 8);
}

TribeFishingShipUnitAIModule::~TribeFishingShipUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00506240
TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {3, 0x16, 0x14, 2, 0x15};
    initializeImportantObjects(this, kImportantObjects, 5);
}

TribeTradeShipUnitAIModule::~TribeTradeShipUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x005067D0
TribeTransportShipUnitAIModule::TribeTransportShipUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {3, 0x16, 0x14, 2, 0x15};
    initializeImportantObjects(this, kImportantObjects, 5);
}

TribeTransportShipUnitAIModule::~TribeTransportShipUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00508170
TribeBuildingUnitAIModule::TribeBuildingUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {0, 3, 4, 0x1A, 0x18, 6, 0x23, 0x19, 0x11, 0x0C, 0x17, 0x24, 0x1C, 0x12, 0x0D, 0x1B, 0x16, 0x14, 2, 0x15, 0x27};
    initializeImportantObjects(this, kImportantObjects, 0x15);
}

TribeBuildingUnitAIModule::~TribeBuildingUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00507F60
TribeTowerUnitAIModule::TribeTowerUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {0, 3, 4, 0x1A, 0x18, 6, 0x23, 0x19, 0x11, 0x0C, 0x17, 0x24, 0x1C, 0x12, 0x0D, 0x1B, 0x16, 0x14, 2, 0x15, 0x27};
    initializeImportantObjects(this, kImportantObjects, 0x15);
}

TribeTowerUnitAIModule::~TribeTowerUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00506FE0
TribeSoldierUnitAIModule::TribeSoldierUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {
    static const int kImportantObjects[] = {0, 3, 4, 0x1A, 0x18, 6, 0x23, 0x19, 0x11, 0x0C, 0x17, 0x24, 0x1C, 0x12, 0x0D, 0x1B, 0x16, 0x14, 2, 0x15, 0x27};
    initializeImportantObjects(this, kImportantObjects, 0x15);
    setField100(this, 0x5DC);
    setAdjustedIdleTimeout();
}

TribeSoldierUnitAIModule::~TribeSoldierUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504700
TribeRangedUnitAIModule::TribeRangedUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {}

TribeRangedUnitAIModule::~TribeRangedUnitAIModule() = default;

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504880
TribeRangedUnitAIModule2::TribeRangedUnitAIModule2(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2) {}

TribeRangedUnitAIModule2::~TribeRangedUnitAIModule2() = default;
