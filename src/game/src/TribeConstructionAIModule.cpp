#include "../include/TribeConstructionAIModule.h"

#include "../include/BaseItem.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Static_Object.h"

#include <cstring>
#include <new>

namespace {
static int kUseInfluencePlacement = 0;

BaseItem* tribe_base_item(ConstructionItem* item) {
    return reinterpret_cast<BaseItem*>(item);
}

const BaseItem* tribe_base_item(const ConstructionItem* item) {
    return reinterpret_cast<const BaseItem*>(item);
}

void tribe_lot_set_in_progress(ConstructionItem* item, int value) {
    item->inProgressValue = value;
}

int tribe_lot_in_progress(const ConstructionItem* item) {
    return item->inProgressValue;
}

void tribe_lot_set_built(ConstructionItem* item, int value) {
    item->builtValue = value;
}

int tribe_lot_built(const ConstructionItem* item) {
    return item->builtValue;
}

int tribe_lot_build_attempts(const ConstructionItem* item) {
    return item->buildAttemptsValue;
}

void tribe_lot_increment_attempts(ConstructionItem* item) {
    item->buildAttemptsValue = item->buildAttemptsValue + 1;
}

ConstructionItem* tribe_clone_lot(const ConstructionItem* source) {
    ConstructionItem* item = reinterpret_cast<ConstructionItem*>(::operator new(sizeof(ConstructionItem), std::nothrow));
    if (item == nullptr) {
        return nullptr;
    }
    std::memcpy(item, source, sizeof(ConstructionItem));
    item->next = nullptr;
    item->prev = nullptr;
    return item;
}

void tribe_clear_temp_list(ConstructionItem* head) {
    ConstructionItem* item = head->next;
    while ((item != head) && (item != nullptr)) {
        ConstructionItem* next = item->next;
        ::operator delete(item);
        item = next;
    }
    head->next = head;
    head->prev = head;
}

void tribe_temp_append(ConstructionItem* head, ConstructionItem* item) {
    item->next = head;
    item->prev = head->prev;
    head->prev->next = item;
    head->prev = item;
}

// TODO: STUB - TribeInformationAIModule::influenceCanPlaceStructure is not transliterated yet.
int tribe_influence_can_place_structure(TribeConstructionAIModule* self, BuildItem* item) {
    (void)self;
    (void)item;
    return 0;
}

// TODO: STUB - TribeInformationAIModule::influencePlaceStructure is not transliterated yet.
ConstructionItem* tribe_influence_place_structure(TribeConstructionAIModule* self, BuildItem* item, int builder_id, PlacementState* state, ulong flags) {
    (void)self;
    (void)item;
    (void)builder_id;
    (void)state;
    (void)flags;
    return nullptr;
}

// TODO: STUB - TribeInformationAIModule::placeDock is not transliterated yet.
ConstructionItem* tribe_information_place_dock(TribeConstructionAIModule* self, BuildItem* item) {
    (void)self;
    (void)item;
    return nullptr;
}

// TODO: STUB - TribeInformationAIModule::storeLot is not transliterated yet.
void tribe_information_store_lot(TribeConstructionAIModule* self, int type_id, int x, int y, unsigned char occupied) {
    (void)self;
    (void)type_id;
    (void)x;
    (void)y;
    (void)occupied;
}

// TODO: STUB - MainDecisionAIModule::object overloads are not transliterated yet.
RGE_Static_Object* tribe_main_decision_object(TribeConstructionAIModule* self, int param_1, int param_2) {
    (void)self;
    (void)param_1;
    (void)param_2;
    return nullptr;
}
}

// Offset: 0x004D5E60
// Fully verified. Source of truth: taiconmd.cpp.decomp @ 0x004D5E60
TribeConstructionAIModule::TribeConstructionAIModule(void* param_1, int param_2)
    : ConstructionAIModule(param_1, param_2) {
    this->md = nullptr;
}

// Offset: 0x004D5EB0
// Fully verified. Source of truth: taiconmd.cpp.decomp @ 0x004D5EB0
TribeConstructionAIModule::TribeConstructionAIModule(int param_1, int param_2)
    : ConstructionAIModule(param_1, param_2) {
    this->md = nullptr;
}

// Offset: 0x004D5EE0
// Fully verified. Source of truth: taiconmd.cpp.decomp @ 0x004D5EE0
TribeConstructionAIModule::~TribeConstructionAIModule() {
    this->md = nullptr;
}

int TribeConstructionAIModule::loggingHistory() {
    return ConstructionAIModule::loggingHistory();
}

void TribeConstructionAIModule::setLogHistory(int param_1) {
    ConstructionAIModule::setLogHistory(param_1);
}

void TribeConstructionAIModule::toggleLogHistory() {
    ConstructionAIModule::toggleLogHistory();
}

void TribeConstructionAIModule::setHistoryFilename(char* param_1) {
    ConstructionAIModule::setHistoryFilename(param_1);
}

int TribeConstructionAIModule::loggingCommonHistory() {
    return ConstructionAIModule::loggingCommonHistory();
}

void TribeConstructionAIModule::setLogCommonHistory(int param_1) {
    ConstructionAIModule::setLogCommonHistory(param_1);
}

void TribeConstructionAIModule::toggleLogCommonHistory() {
    ConstructionAIModule::toggleLogCommonHistory();
}

int TribeConstructionAIModule::loadState(char* param_1) {
    return ConstructionAIModule::loadState(param_1);
}

int TribeConstructionAIModule::saveState(char* param_1) {
    return ConstructionAIModule::saveState(param_1);
}

int TribeConstructionAIModule::gleanState(int param_1) {
    return ConstructionAIModule::gleanState(param_1);
}

int TribeConstructionAIModule::processMessage(AIModuleMessage* param_1) {
    return ConstructionAIModule::processMessage(param_1);
}

int TribeConstructionAIModule::update(int param_1) {
    return ConstructionAIModule::update(param_1);
}

void TribeConstructionAIModule::setCallbackMessage(AIModuleMessage* param_1) {
    ConstructionAIModule::setCallbackMessage(param_1);
}

int TribeConstructionAIModule::filterOutMessage(AIModuleMessage* param_1) {
    return ConstructionAIModule::filterOutMessage(param_1);
}

int TribeConstructionAIModule::save(int param_1) const {
    return ConstructionAIModule::save(param_1);
}

int TribeConstructionAIModule::loadConstructionPlan(char* param_1, int param_2, int param_3, float param_4, float param_5, float param_6) const {
    return ConstructionAIModule::loadConstructionPlan(param_1, param_2, param_3, param_4, param_5, param_6);
}

ConstructionItem* TribeConstructionAIModule::placeStructure(BuildItem* param_1) const {
    return const_cast<TribeConstructionAIModule*>(this)->placeStructure(param_1, -1, nullptr, 0);
}

void TribeConstructionAIModule::setBuilt(ConstructionItem* param_1, int param_2) const {
    ConstructionAIModule::setBuilt(param_1, param_2);
}

int TribeConstructionAIModule::unplaceStructure(float param_1, float param_2, int param_3) const {
    return ConstructionAIModule::unplaceStructure(param_1, param_2, param_3);
}

int TribeConstructionAIModule::unplaceStructure(ConstructionItem* param_1, int param_2) const {
    return ConstructionAIModule::unplaceStructure(param_1, param_2);
}

void TribeConstructionAIModule::decrementBuildAttempts(float param_1, float param_2, int param_3) const {
    ConstructionAIModule::decrementBuildAttempts(param_1, param_2, param_3);
}

void TribeConstructionAIModule::incrementBuildAttempts(float param_1, float param_2, int param_3) const {
    ConstructionAIModule::incrementBuildAttempts(param_1, param_2, param_3);
}

// Offset: 0x004D5EF0
// Fully verified. Source of truth: taiconmd.cpp.decomp @ 0x004D5EF0
void TribeConstructionAIModule::setMainDecisionAI(TribeMainDecisionAIModule* param_1) {
    this->md = param_1;
}

// Offset: 0x004D5F00
// TODO: Partial parity pending TribeInformationAIModule dependency transliteration.
int TribeConstructionAIModule::canPlace(BuildItem* param_1) {
    if ((0.0f < this->xReferencePointValue) &&
        (0.0f < this->yReferencePointValue) &&
        (this->xReferencePointValue < (float)this->mapXSizeValue) &&
        (this->yReferencePointValue < (float)this->mapYSizeValue)) {
        if (tribe_base_item(reinterpret_cast<ConstructionItem*>(param_1))->typeID() == 0x2D) {
            return 1;
        }

        if ((kUseInfluencePlacement != 1) && (this->numberConstructionLotsValue != 0)) {
            ConstructionItem* item = this->constructionLots.next;
            while ((item != &this->constructionLots) && (item != nullptr)) {
                int item_type = tribe_base_item(item)->typeID();
                int target_type = tribe_base_item(reinterpret_cast<ConstructionItem*>(param_1))->typeID();
                if ((item_type == target_type) ||
                    ((tribe_base_item(item)->xSize() == tribe_base_item(reinterpret_cast<ConstructionItem*>(param_1))->xSize()) &&
                     (tribe_base_item(item)->ySize() == tribe_base_item(reinterpret_cast<ConstructionItem*>(param_1))->ySize()) &&
                     (tribe_base_item(item)->typeID() == -1))) {
                    if ((tribe_lot_built(item) == 0) && (tribe_lot_in_progress(item) == 0)) {
                        return 1;
                    }
                }
                item = item->next;
            }
            return 0;
        }
    }

    return tribe_influence_can_place_structure(this, param_1);
}

// Offset: 0x004D60E0
// TODO: Partial parity pending TribeInformation/MainDecision dependency transliteration.
ConstructionItem* TribeConstructionAIModule::placeStructure(BuildItem* param_1, int param_2, PlacementState* param_3, ulong param_4) {
    if ((this->xReferencePointValue <= 0.0f) ||
        (this->yReferencePointValue <= 0.0f) ||
        ((float)this->mapXSizeValue <= this->xReferencePointValue) ||
        ((float)this->mapYSizeValue <= this->yReferencePointValue)) {
        return tribe_influence_place_structure(this, param_1, param_2, param_3, param_4);
    }

    if (tribe_base_item(reinterpret_cast<ConstructionItem*>(param_1))->typeID() == 0x2D) {
        ConstructionItem* dock_lot = placeDock(param_1);
        if (dock_lot != nullptr) {
            return tribe_clone_lot(dock_lot);
        }
        return nullptr;
    }

    const int type_id = tribe_base_item(reinterpret_cast<ConstructionItem*>(param_1))->typeID();
    if ((type_id == 0x67) || (type_id == 0x44) || (type_id == 0x4F) || (type_id == 199) ||
        (type_id == 0x45) || (type_id == 0x48) || (type_id == 0x75) || (type_id == 0x9B) ||
        (kUseInfluencePlacement == 1) || (this->numberConstructionLotsValue == 0)) {
        return tribe_influence_place_structure(this, param_1, param_2, param_3, param_4);
    }

    RGE_Static_Object* builder = tribe_main_decision_object(this, param_2, -1);
    if (builder == nullptr) {
        return nullptr;
    }

    ConstructionItem temp_lots;
    temp_lots.next = &temp_lots;
    temp_lots.prev = &temp_lots;
    int number_temp_lots = 0;
    int min_build_attempts = -1;

    ConstructionItem* item = this->constructionLots.next;
    while ((item != &this->constructionLots) && (item != nullptr)) {
        const int lot_type = tribe_base_item(item)->typeID();
        if ((lot_type == type_id) || (lot_type == -1)) {
            if ((tribe_base_item(item)->xSize() == tribe_base_item(reinterpret_cast<ConstructionItem*>(param_1))->xSize()) &&
                (tribe_base_item(item)->ySize() == tribe_base_item(reinterpret_cast<ConstructionItem*>(param_1))->ySize()) &&
                (tribe_lot_built(item) != 1) &&
                (tribe_lot_in_progress(item) != 1)) {
                ConstructionItem* cloned = tribe_clone_lot(item);
                if (cloned != nullptr) {
                    tribe_temp_append(&temp_lots, cloned);
                    number_temp_lots = number_temp_lots + 1;
                    if ((min_build_attempts == -1) || (tribe_lot_build_attempts(item) < min_build_attempts)) {
                        min_build_attempts = tribe_lot_build_attempts(item);
                    }
                }
            }
        }
        item = item->next;
    }

    if (((1 < min_build_attempts) || (min_build_attempts == -1))) {
        ConstructionItem* influenced = tribe_influence_place_structure(this, param_1, param_2, param_3, param_4);
        if (influenced != nullptr) {
            tribe_clear_temp_list(&temp_lots);
            return influenced;
        }
    }

    if (number_temp_lots == 0) {
        this->lastPlacementReturnCodeValue = (PlacementResult)5;
        tribe_clear_temp_list(&temp_lots);
        return nullptr;
    }

    ConstructionItem* best = temp_lots.next;
    if (tribe_base_item(reinterpret_cast<ConstructionItem*>(param_1))->typeID() == 0x48) {
        ConstructionItem* it = best;
        while ((it != &temp_lots) && (it != nullptr)) {
            if (tribe_lot_build_attempts(it) + 5 < tribe_lot_build_attempts(best)) {
                best = it;
            }
            it = it->next;
        }
    } else {
        ConstructionItem* it = best;
        while ((it != &temp_lots) && (it != nullptr)) {
            best = compare(best, it);
            it = it->next;
        }
    }

    ConstructionItem* source = this->lot(tribe_base_item(best)->x(), tribe_base_item(best)->y());
    if (source == nullptr) {
        tribe_clear_temp_list(&temp_lots);
        this->lastPlacementReturnCodeValue = (PlacementResult)5;
        return nullptr;
    }

    tribe_lot_set_in_progress(source, 1);
    tribe_lot_increment_attempts(source);
    tribe_base_item(source)->setUniqueID(tribe_base_item(reinterpret_cast<ConstructionItem*>(param_1))->uniqueID());
    this->lastPlacementReturnCodeValue = PlacementResult_0;

    ConstructionItem* placed = tribe_clone_lot(source);
    if (placed != nullptr) {
        tribe_base_item(placed)->setTypeID(tribe_base_item(reinterpret_cast<ConstructionItem*>(param_1))->typeID());
    }
    tribe_clear_temp_list(&temp_lots);
    return placed;
}

// Offset: 0x004D6780
// TODO: Partial parity pending TribeInformationAIModule::placeDock transliteration.
ConstructionItem* TribeConstructionAIModule::placeDock(BuildItem* param_1) {
    ConstructionItem* item = tribe_information_place_dock(this, param_1);
    if (item != nullptr) {
        item->next = &this->randomConstructionLots;
        item->prev = this->randomConstructionLots.prev;
        this->randomConstructionLots.prev->next = item;
        this->randomConstructionLots.prev = item;
        this->numberRandomConstructionLotsValue = this->numberRandomConstructionLotsValue + 1;
        this->lastPlacementReturnCodeValue = PlacementResult_0;
        return item;
    }
    this->lastPlacementReturnCodeValue = (PlacementResult)5;
    return nullptr;
}

// Offset: 0x004D6800
// TODO: Partial parity pending TribeInformationAIModule::storeLot transliteration.
void TribeConstructionAIModule::setBuilt(RGE_Static_Object* param_1, int param_2) {
    ConstructionItem* item = this->constructionLots.next;
    while ((item != &this->constructionLots) && (item != nullptr)) {
        if ((tribe_base_item(item)->typeID() == param_1->master_obj->id) &&
            (tribe_base_item(item)->x() == param_1->world_x) &&
            (tribe_base_item(item)->y() == param_1->world_y)) {
            tribe_lot_set_built(item, param_2);
            return;
        }
        item = item->next;
    }

    tribe_information_store_lot(this, param_1->master_obj->id, (int)param_1->world_x, (int)param_1->world_y, 1);
}

// Offset: 0x004D68A0
// Fully verified. Source of truth: taiconmd.cpp.decomp @ 0x004D68A0
ConstructionItem* TribeConstructionAIModule::compare(ConstructionItem* param_1, ConstructionItem* param_2) {
    int attempts_1 = tribe_lot_build_attempts(param_1);
    int attempts_2 = tribe_lot_build_attempts(param_2);
    if (attempts_1 <= attempts_2) {
        return param_1;
    }
    return param_2;
}
