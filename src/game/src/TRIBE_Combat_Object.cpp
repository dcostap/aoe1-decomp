#include "../include/TRIBE_Combat_Object.h"

#include "../include/RGE_Game_World.h"
#include "../include/TRIBE_Master_Combat_Object.h"
#include "../include/TRIBE_Master_Building_Object.h"
#include "../include/TRIBE_Action_List.h"
#include "../include/TribeUnitAIModules.h"
#include "../include/globals.h"

#include <new>

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CA1A0
TRIBE_Combat_Object::TRIBE_Combat_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : RGE_Combat_Object(param_1, param_2, 0) {
    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CA210
TRIBE_Combat_Object::~TRIBE_Combat_Object() = default;

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CA510
RGE_Action_List* TRIBE_Combat_Object::create_action_list() {
    TRIBE_Action_List* list = new (std::nothrow) TRIBE_Action_List((RGE_Action_Object*)this);
    return (RGE_Action_List*)list;
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CA3E0, t_c_obj.cpp.asm @ 0x004CA3E0
int TRIBE_Combat_Object::setup(int param_1, RGE_Game_World* param_2) {
    int fd = param_1;
    RGE_Game_World* world = param_2;

    RGE_Combat_Object::setup(fd, world);
    this->type = 'F';

    rge_read(fd, &this->own_master, 1);
    if (this->own_master != 0) {
        unsigned char master_type = 0;
        rge_read(fd, &master_type, 1);

        if (master_type == 'F') {
            TRIBE_Master_Combat_Object* master =
                (TRIBE_Master_Combat_Object*)::operator new(sizeof(TRIBE_Master_Combat_Object), std::nothrow);
            if (master != nullptr) {
                new (master) TRIBE_Master_Combat_Object(fd, world->sprites, world->sounds, 1);
            }
            this->master_obj = master;
        } else if (master_type == 'P') {
            TRIBE_Master_Building_Object* master =
                (TRIBE_Master_Building_Object*)::operator new(sizeof(TRIBE_Master_Building_Object), std::nothrow);
            if (master != nullptr) {
                new (master) TRIBE_Master_Building_Object(fd, world->sprites, world->sounds, 1);
            }
            this->master_obj = master;
        }
    }

    int has_unit_ai = 0;
    rge_read(fd, &has_unit_ai, 4);
    if (has_unit_ai == 1) {
        this->initUnitAI();
        if (this->unitAIValue != nullptr) {
            this->unitAIValue->load(fd);
        }
    }

    return 1;
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CB8D0
void TRIBE_Combat_Object::initUnitAI() {
    if (this->master_obj == nullptr) {
        return;
    }

    short group = this->master_obj->object_group;
    short master_id = this->master_obj->id;

    switch (group) {
        case 1:
            if (master_id == 99 || master_id == 10) {
                return;
            }
            this->unitAIValue = new (std::nothrow) TribeArtifactUnitAIModule(this, 5);
            return;
        case 2:
            this->unitAIValue = new (std::nothrow) TribeTradeShipUnitAIModule(this, 10);
            return;
        case 3:
        case 0x1B:
            if (master_id == 0x4F || master_id == 199 || master_id == 0x45 ||
                master_id == 0x116 || master_id == 0x17F || master_id == 0x17C) {
                this->unitAIValue = new (std::nothrow) TribeTowerUnitAIModule(this, 10);
                return;
            }
            this->unitAIValue = new (std::nothrow) TribeBuildingUnitAIModule(this, 10);
            return;
        case 4:
            this->unitAIValue = new (std::nothrow) TribeCivilianUnitAIModule(this, 10);
            return;
        case 9:
            this->unitAIValue = new (std::nothrow) TribeHuntedAnimalUnitAIModule(this, 10);
            return;
        case 10:
            if (master_id == 0x9D) {
                this->unitAIValue = new (std::nothrow) TribeHuntedAnimalUnitAIModule(this, 10);
                return;
            }
            if (master_id == 0x30) {
                this->unitAIValue = new (std::nothrow) TribeElephantUnitAIModule(this, 10);
                return;
            }
            if (master_id == 0x7E) {
                this->unitAIValue = new (std::nothrow) TribeLionUnitAIModule(this, 10);
                return;
            }
            this->unitAIValue = new (std::nothrow) TribePreditorUnitAIModule(this, 10);
            return;
        case 0x12:
            this->unitAIValue = new (std::nothrow) TribePriestUnitAIModule(this, 10);
            return;
        case 0x14:
            this->unitAIValue = new (std::nothrow) TribeTransportShipUnitAIModule(this, 10);
            return;
        case 0x15:
            this->unitAIValue = new (std::nothrow) TribeFishingShipUnitAIModule(this, 10);
            return;
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
            return;
        default:
            this->unitAIValue = new (std::nothrow) TribeSoldierUnitAIModule(this, 10);
            return;
    }
}
