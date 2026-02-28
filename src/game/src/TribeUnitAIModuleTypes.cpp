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

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x005040A0
int TribePreditorUnitAIModule::canAttackUnitAtNeutrality(int param_1) {
    (void)param_1;
    return 1;
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x005040B0)
int TribePreditorUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    return UnitAIModule::processNotify(param_1, param_2);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00503D30)
int TribeHuntedAnimalUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    return UnitAIModule::processNotify(param_1, param_2);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00503E30)
int TribeHuntedAnimalUnitAIModule::processIdle(int param_1) {
    return UnitAIModule::processIdle(param_1);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x005041C0)
int TribeElephantUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    return UnitAIModule::processNotify(param_1, param_2);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x005042D0
int TribeElephantUnitAIModule::processIdle(int param_1) {
    (void)param_1;
    return 5;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504430
int TribeLionUnitAIModule::canAttackUnitAtNeutrality(int param_1) {
    (void)param_1;
    return 1;
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00504440)
int TribeLionUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    return UnitAIModule::processNotify(param_1, param_2);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x005044F0)
int TribeLionUnitAIModule::processIdle(int param_1) {
    return UnitAIModule::processIdle(param_1);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00504600)
int TribeRangedUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    return UnitAIModule::processNotify(param_1, param_2);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00504780)
int TribeRangedUnitAIModule2::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    return UnitAIModule::processNotify(param_1, param_2);
}

// TODO: decomp transliteration in progress (aiuaimod.cpp.decomp @ 0x00417710)
int TribeRangedUnitAIModule2::processIdle(int param_1) {
    return UnitAIModule::processIdle(param_1);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504D30
int TribeCivilianUnitAIModule::importantWhenDead(int param_1) {
    return this->importantObject(param_1);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00504D50)
int TribeCivilianUnitAIModule::attackObject(int param_1, int param_2) {
    return UnitAIModule::attackObject(param_1, param_2);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504DE0
int TribeCivilianUnitAIModule::canAttackUnit(RGE_Static_Object* param_1) {
    return UnitAIModule::canAttackUnit(param_1);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504E20
int TribeCivilianUnitAIModule::canAttackUnitAtNeutrality(int param_1) {
    (void)param_1;
    return 0;
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00504E30
int TribeCivilianUnitAIModule::retryableOrder(int param_1) {
    return UnitAIModule::retryableOrder(param_1);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00504E70)
int TribeCivilianUnitAIModule::convertToLOSResourceType(int param_1) {
    return UnitAIModule::convertToLOSResourceType(param_1);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00505360)
int TribeCivilianUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    return UnitAIModule::processNotify(param_1, param_2);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00505740)
int TribeCivilianUnitAIModule::processIdle(int param_1) {
    return UnitAIModule::processIdle(param_1);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00505780)
int TribeCivilianUnitAIModule::processMisc() {
    return UnitAIModule::processMisc();
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x005059D0)
int TribePriestUnitAIModule::attackObject(int param_1, int param_2) {
    return UnitAIModule::attackObject(param_1, param_2);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00505A70
int TribePriestUnitAIModule::retryableOrder(int param_1) {
    switch (param_1) {
        case 1:
        case 2:
        case 6:
        case 7:
            return 1;
        default:
            return 0;
    }
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00505AB0
int TribePriestUnitAIModule::canConvert(int param_1) {
    (void)param_1;
    return 1;
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00505B20)
int TribePriestUnitAIModule::canAttackUnit(RGE_Static_Object* param_1) {
    return UnitAIModule::canAttackUnit(param_1);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00505EA0)
int TribePriestUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    return UnitAIModule::processNotify(param_1, param_2);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00506160)
int TribePriestUnitAIModule::processIdle(int param_1) {
    return UnitAIModule::processIdle(param_1);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00506200)
int TribePriestUnitAIModule::processMisc() {
    return UnitAIModule::processMisc();
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00506410)
int TribeTradeShipUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    return UnitAIModule::processNotify(param_1, param_2);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00506660)
int TribeTradeShipUnitAIModule::processIdle(int param_1) {
    return UnitAIModule::processIdle(param_1);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00506950)
int TribeTransportShipUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    return UnitAIModule::processNotify(param_1, param_2);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00506AB0)
int TribeTransportShipUnitAIModule::processIdle(int param_1) {
    return UnitAIModule::processIdle(param_1);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00506D00
int TribeFishingShipUnitAIModule::importantWhenDead(int param_1) {
    return this->importantObject(param_1);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00506D40)
int TribeFishingShipUnitAIModule::convertToLOSResourceType(int param_1) {
    return UnitAIModule::convertToLOSResourceType(param_1);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00506D80)
int TribeFishingShipUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    return UnitAIModule::processNotify(param_1, param_2);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00506F20)
int TribeFishingShipUnitAIModule::processIdle(int param_1) {
    return UnitAIModule::processIdle(param_1);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00507190)
int TribeSoldierUnitAIModule::canAttackUnit(RGE_Static_Object* param_1) {
    return UnitAIModule::canAttackUnit(param_1);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x005071D0)
int TribeSoldierUnitAIModule::canAttackUnitAtNeutrality(int param_1) {
    return UnitAIModule::canAttackUnitAtNeutrality(param_1);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00507220)
int TribeSoldierUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    return UnitAIModule::processNotify(param_1, param_2);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x005074A0)
int TribeSoldierUnitAIModule::processIdle(int param_1) {
    return UnitAIModule::processIdle(param_1);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00507A30)
int TribeArtifactUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    return UnitAIModule::processNotify(param_1, param_2);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00507D90)
int TribeArtifactUnitAIModule::processIdle(int param_1) {
    return UnitAIModule::processIdle(param_1);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00507DF0)
int TribeArtifactUnitAIModule::processMisc() {
    return UnitAIModule::processMisc();
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00507FC0)
int TribeTowerUnitAIModule::canAttackUnit(RGE_Static_Object* param_1) {
    return UnitAIModule::canAttackUnit(param_1);
}

// Fully verified. Source of truth: taiuaimd.cpp.decomp @ 0x00508020
int TribeTowerUnitAIModule::canAttackUnitAtNeutrality(int param_1) {
    (void)param_1;
    return 1;
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x005082F0)
int TribeBuildingUnitAIModule::processNotify(NotifyEvent* param_1, unsigned long param_2) {
    return UnitAIModule::processNotify(param_1, param_2);
}

// TODO: decomp transliteration in progress (taiuaimd.cpp.decomp @ 0x00508470)
int TribeBuildingUnitAIModule::processIdle(int param_1) {
    return UnitAIModule::processIdle(param_1);
}
