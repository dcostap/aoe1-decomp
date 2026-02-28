#include "../include/TribeUnitAIModules.h"

#include <new>

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CB8D0
UnitAIModule* CreateTribeUnitAIModule(RGE_Static_Object* object, short object_group, short master_id) {
    switch (object_group) {
        case 1:
            if (master_id == 99 || master_id == 10) {
                return nullptr;
            }
            return new (std::nothrow) TribeArtifactUnitAIModule(object, 5);
        case 2:
            return new (std::nothrow) TribeTradeShipUnitAIModule(object, 10);
        case 3:
        case 0x1B:
            if (master_id == 0x4F || master_id == 199 || master_id == 0x45 ||
                master_id == 0x116 || master_id == 0x17F || master_id == 0x17C) {
                return new (std::nothrow) TribeTowerUnitAIModule(object, 10);
            }
            return new (std::nothrow) TribeBuildingUnitAIModule(object, 10);
        case 4:
            return new (std::nothrow) TribeCivilianUnitAIModule(object, 10);
        case 9:
            return new (std::nothrow) TribeHuntedAnimalUnitAIModule(object, 10);
        case 10:
            if (master_id == 0x9D) {
                return new (std::nothrow) TribeHuntedAnimalUnitAIModule(object, 10);
            }
            if (master_id == 0x30) {
                return new (std::nothrow) TribeElephantUnitAIModule(object, 10);
            }
            if (master_id == 0x7E) {
                return new (std::nothrow) TribeLionUnitAIModule(object, 10);
            }
            return new (std::nothrow) TribePreditorUnitAIModule(object, 10);
        case 0x12:
            return new (std::nothrow) TribePriestUnitAIModule(object, 10);
        case 0x14:
            return new (std::nothrow) TribeTransportShipUnitAIModule(object, 10);
        case 0x15:
            return new (std::nothrow) TribeFishingShipUnitAIModule(object, 10);
        case 5:
        case 7:
        case 8:
        case 0x0B:
        case 0x0E:
        case 0x0F:
        case 0x10:
        case 0x1D:
        case 0x1E:
        case 0x1F:
        case 0x20:
        case 0x21:
            return nullptr;
        default:
            return new (std::nothrow) TribeSoldierUnitAIModule(object, 10);
    }
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415120
int TribeElephantUnitAIModule::importantWhenDead(int param_1) {
    return UnitAIModule::importantWhenDead(param_1);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415150
int TribeElephantUnitAIModule::retryableOrder(int param_1) {
    return UnitAIModule::retryableOrder(param_1);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415160
int TribeElephantUnitAIModule::actionRequiresLiveTarget(int param_1) {
    return UnitAIModule::actionRequiresLiveTarget(param_1);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004151B0
int TribeElephantUnitAIModule::bestUnitToAttack(int param_1, int param_2, float* param_3) {
    return UnitAIModule::bestUnitToAttack(param_1, param_2, param_3);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415A10
int TribeElephantUnitAIModule::mostDangerousEnemy(float* param_1) {
    return UnitAIModule::mostDangerousEnemy(param_1);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415AD0
int TribeElephantUnitAIModule::weakestEnemy(float* param_1) {
    return UnitAIModule::weakestEnemy(param_1);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415B50
int TribeElephantUnitAIModule::closestAttacker(float* param_1) {
    return UnitAIModule::closestAttacker(param_1);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415CA0
int TribeElephantUnitAIModule::closestObject(int param_1, int param_2, int param_3, int param_4, int* param_5) {
    return UnitAIModule::closestObject(param_1, param_2, param_3, param_4, param_5);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415E50
int TribeElephantUnitAIModule::closestResourceObject(int param_1, int* param_2) {
    return UnitAIModule::closestResourceObject(param_1, param_2);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00415F40
int TribeElephantUnitAIModule::closestUndiscoveredTile(int* param_1, int* param_2, int param_3) {
    return UnitAIModule::closestUndiscoveredTile(param_1, param_2, param_3);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004162A0
int TribeElephantUnitAIModule::canAttackUnit(RGE_Static_Object* param_1) {
    return UnitAIModule::canAttackUnit(param_1);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004162B0
int TribeElephantUnitAIModule::canAttackUnitAtNeutrality(int param_1) {
    return UnitAIModule::canAttackUnitAtNeutrality(param_1);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004162C0
int TribeElephantUnitAIModule::stopObject(int param_1) {
    return UnitAIModule::stopObject(param_1);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416340
int TribeElephantUnitAIModule::attackObject(int param_1, int param_2) {
    return UnitAIModule::attackObject(param_1, param_2);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004163C0
int TribeElephantUnitAIModule::attackRoundupObject(int param_1) {
    return UnitAIModule::attackRoundupObject(param_1);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416470
int TribeElephantUnitAIModule::huntObject(int param_1, int param_2) {
    return UnitAIModule::huntObject(param_1, param_2);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416550
int TribeElephantUnitAIModule::convertObject(int param_1, int param_2) {
    return UnitAIModule::convertObject(param_1, param_2);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004165F0
int TribeElephantUnitAIModule::healObject(int param_1, int param_2) {
    return UnitAIModule::healObject(param_1, param_2);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416690
int TribeElephantUnitAIModule::gatherObject(int param_1, int param_2) {
    return UnitAIModule::gatherObject(param_1, param_2);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416730
int TribeElephantUnitAIModule::repairObject(int param_1, int param_2) {
    return UnitAIModule::repairObject(param_1, param_2);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004167D0
int TribeElephantUnitAIModule::buildObject(int param_1, int param_2) {
    return UnitAIModule::buildObject(param_1, param_2);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416870
int TribeElephantUnitAIModule::tradeWithObject(int param_1, int param_2) {
    return UnitAIModule::tradeWithObject(param_1, param_2);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416910
int TribeElephantUnitAIModule::explore(int param_1, int param_2, int param_3) {
    return UnitAIModule::explore(param_1, param_2, param_3);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416980
int TribeElephantUnitAIModule::enterObject(int param_1, int param_2) {
    return UnitAIModule::enterObject(param_1, param_2);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004169E0
int TribeElephantUnitAIModule::transportObject(float param_1, float param_2, float param_3, int param_4) {
    return UnitAIModule::transportObject(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416A50
int TribeElephantUnitAIModule::unload(int param_1, float param_2, float param_3) {
    return UnitAIModule::unload(param_1, param_2, param_3);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416AF0
int TribeElephantUnitAIModule::moveTo(int param_1, int param_2) {
    return UnitAIModule::moveTo(param_1, param_2);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416B80
int TribeElephantUnitAIModule::moveTo(int param_1, float param_2, int param_3) {
    return UnitAIModule::moveTo(param_1, param_2, param_3);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416C10
int TribeElephantUnitAIModule::moveTo(float param_1, float param_2, float param_3, float param_4, int param_5) {
    return UnitAIModule::moveTo(param_1, param_2, param_3, param_4, param_5);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416C80
int TribeElephantUnitAIModule::evasiveMoveTo(float param_1, float param_2, float param_3, int param_4) {
    return UnitAIModule::evasiveMoveTo(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00416F30
int TribeElephantUnitAIModule::intelligentEvasiveMoveTo(float param_1, float param_2, float param_3, int param_4, int param_5) {
    return UnitAIModule::intelligentEvasiveMoveTo(param_1, param_2, param_3, param_4, param_5);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004171F0
int TribeElephantUnitAIModule::runAwayFromAttackers(int param_1) {
    return UnitAIModule::runAwayFromAttackers(param_1);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00417360
int TribeElephantUnitAIModule::followObject(int param_1, float param_2, int param_3) {
    return UnitAIModule::followObject(param_1, param_2, param_3);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004173D0
int TribeElephantUnitAIModule::defendObject(int param_1, float param_2, int param_3) {
    return UnitAIModule::defendObject(param_1, param_2, param_3);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00417440
int TribeElephantUnitAIModule::defendPosition(float param_1, float param_2, float param_3, int param_4) {
    return UnitAIModule::defendPosition(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004174A0
int TribeElephantUnitAIModule::seekAndDestroy(int param_1, int param_2, int param_3, int param_4) {
    return UnitAIModule::seekAndDestroy(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00417510
int TribeElephantUnitAIModule::exploreAndDestroy(int param_1, int param_2, int param_3) {
    return UnitAIModule::exploreAndDestroy(param_1, param_2, param_3);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x004177C0
int TribeElephantUnitAIModule::convertToLOSResourceType(int param_1) {
    return UnitAIModule::convertToLOSResourceType(param_1);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00417B50
int TribeElephantUnitAIModule::processOrder(OrderEvent* param_1, int param_2) {
    return UnitAIModule::processOrder(param_1, param_2);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00419510
void TribeElephantUnitAIModule::processGroupNotify(NotifyEvent* param_1) {
    UnitAIModule::processGroupNotify(param_1);
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00419650
int TribeElephantUnitAIModule::processMisc() {
    return UnitAIModule::processMisc();
}

// Fully verified. Source of truth: aiuaimod.cpp.decomp @ 0x00419BC0
int TribeElephantUnitAIModule::processRetryableOrder() {
    return UnitAIModule::processRetryableOrder();
}
