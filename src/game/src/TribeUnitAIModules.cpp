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
