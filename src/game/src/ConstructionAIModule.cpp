#include "../include/ConstructionAIModule.h"

#include "../include/AIModule.h"
#include "../include/BaseItem.h"
#include "../include/globals.h"

#include <cstring>
#include <io.h>
#include <new>

// TODO: STUB - Full ConstructionItem transliteration is not yet present in this repository.
ConstructionItem::~ConstructionItem() {}

namespace {
BaseItem* construction_base_item(ConstructionItem* item) {
    return reinterpret_cast<BaseItem*>(item);
}

const BaseItem* construction_base_item(const ConstructionItem* item) {
    return reinterpret_cast<const BaseItem*>(item);
}

void construction_init_lot_head(ConstructionItem* head) {
    if (head == nullptr) {
        return;
    }
    head->next = head;
    head->prev = head;
    head->inProgressValue = 0;
    head->builtValue = 0;
    head->buildAttemptsValue = 0;
    BaseItem* base = construction_base_item(head);
    base->setTypeID(-1);
    base->setGameID(-1);
    base->setUniqueID(-1);
    base->setName((char*)"");
    base->setX(0.0f);
    base->setY(0.0f);
    base->setZ(0.0f);
    base->setXSize(0.0f);
    base->setYSize(0.0f);
    base->setZSize(0.0f);
    base->setSkip(0);
}

void construction_append_lot(ConstructionItem* head, ConstructionItem* item) {
    item->next = head;
    item->prev = head->prev;
    head->prev->next = item;
    head->prev = item;
}

ConstructionItem* construction_allocate_lot() {
    ConstructionItem* item = reinterpret_cast<ConstructionItem*>(::operator new(sizeof(ConstructionItem), std::nothrow));
    if (item == nullptr) {
        return nullptr;
    }
    std::memset(item, 0, sizeof(ConstructionItem));
    return item;
}

ConstructionItem* construction_clone_lot(const ConstructionItem* source) {
    ConstructionItem* item = construction_allocate_lot();
    if (item == nullptr) {
        return nullptr;
    }
    std::memcpy(item, source, sizeof(ConstructionItem));
    item->next = nullptr;
    item->prev = nullptr;
    return item;
}

void construction_destroy_list_nodes(ConstructionItem* head) {
    ConstructionItem* item = head->next;
    while ((item != head) && (item != nullptr)) {
        ConstructionItem* next = item->next;
        // TODO: STUB - original uses ConstructionItem scalar-deleting destructor dispatch.
        ::operator delete(item);
        item = next;
    }
    head->next = head;
    head->prev = head;
}

int construction_items_equal(const ConstructionItem* lhs, const ConstructionItem* rhs) {
    return operator==(*construction_base_item(lhs), *construction_base_item(rhs));
}

int construction_item_build_attempts(const ConstructionItem* item) {
    return item->buildAttemptsValue;
}

void construction_item_set_build_attempts(ConstructionItem* item, int value) {
    item->buildAttemptsValue = value;
}

void construction_item_increment_build_attempts(ConstructionItem* item) {
    item->buildAttemptsValue = item->buildAttemptsValue + 1;
}

void construction_item_decrement_build_attempts(ConstructionItem* item) {
    item->buildAttemptsValue = item->buildAttemptsValue - 1;
}

int construction_item_in_progress(const ConstructionItem* item) {
    return item->inProgressValue;
}

void construction_item_set_in_progress(ConstructionItem* item, int value) {
    item->inProgressValue = value;
}

int construction_item_built(const ConstructionItem* item) {
    return item->builtValue;
}

void construction_item_set_built(ConstructionItem* item, int value) {
    item->builtValue = value;
}
}

// Offset: 0x0040AA90
// TODO: Partial parity pending flattened AIModule base layout.
ConstructionAIModule::ConstructionAIModule(void* param_1, int param_2) {
    (void)param_1;
    (void)param_2;
    this->numberConstructionLotsValue = 0;
    construction_init_lot_head(&this->constructionLots);
    this->numberRandomConstructionLotsValue = 0;
    construction_init_lot_head(&this->randomConstructionLots);
    this->xReferencePointValue = -1.0f;
    this->yReferencePointValue = -1.0f;
    this->zReferencePointValue = -1.0f;
    this->mapXSizeValue = -1;
    this->mapYSizeValue = -1;
    this->lastPlacementReturnCodeValue = PlacementResult_0;
    this->constructionPlanNameValue[0] = '\0';
}

// Offset: 0x0040ABB0
// TODO: Partial parity pending flattened AIModule base layout and ConstructionItem constructor parity.
ConstructionAIModule::ConstructionAIModule(int param_1, int param_2) {
    (void)param_1;
    this->numberConstructionLotsValue = 0;
    construction_init_lot_head(&this->constructionLots);
    this->numberRandomConstructionLotsValue = 0;
    construction_init_lot_head(&this->randomConstructionLots);
    this->xReferencePointValue = -1.0f;
    this->yReferencePointValue = -1.0f;
    this->zReferencePointValue = -1.0f;
    this->mapXSizeValue = -1;
    this->mapYSizeValue = -1;
    this->lastPlacementReturnCodeValue = PlacementResult_0;
    this->constructionPlanNameValue[0] = '\0';

    rge_read(param_2, &this->numberConstructionLotsValue, 4);
    float plan_name_len_f = 0.0f;
    rge_read(param_2, &plan_name_len_f, 4);
    int plan_name_len = (int)plan_name_len_f;
    if (plan_name_len < 0) {
        plan_name_len = 0;
    }
    if (plan_name_len > 256) {
        plan_name_len = 256;
    }
    if (plan_name_len > 0) {
        rge_read(param_2, this->constructionPlanNameValue, plan_name_len);
    }
    this->constructionPlanNameValue[plan_name_len] = '\0';
    rge_read(param_2, &this->xReferencePointValue, 4);
    rge_read(param_2, &this->yReferencePointValue, 4);
    rge_read(param_2, &this->zReferencePointValue, 4);
    rge_read(param_2, &this->mapXSizeValue, 4);
    rge_read(param_2, &this->mapYSizeValue, 4);

    int loaded_construction = this->numberConstructionLotsValue;
    this->numberConstructionLotsValue = 0;
    for (int i = 0; i < loaded_construction; ++i) {
        float lot_name_len_f = 0.0f;
        char lot_name[257];
        int type_id = -1;
        int in_progress_value = 0;
        int skip_value = 0;
        int y_i = 0;
        int z_size_i = 0;
        int game_id = 0;
        int y_size_i = 0;
        int i_value = 0;
        int x_size_i = 0;
        int built_value = 0;
        int z_i = 0;
        int unique_id = 0;
        float build_attempts_f = 0.0f;

        rge_read(param_2, &lot_name_len_f, 4);
        int lot_name_len = (int)lot_name_len_f;
        if (lot_name_len < 0) {
            lot_name_len = 0;
        }
        if (lot_name_len > 256) {
            lot_name_len = 256;
        }
        if (lot_name_len > 0) {
            rge_read(param_2, lot_name, lot_name_len);
        }
        lot_name[lot_name_len] = '\0';
        rge_read(param_2, &type_id, 4);
        rge_read(param_2, &in_progress_value, 4);
        rge_read(param_2, &skip_value, 4);
        rge_read(param_2, &y_i, 4);
        rge_read(param_2, &z_size_i, 4);
        rge_read(param_2, &game_id, 4);
        rge_read(param_2, &y_size_i, 4);
        rge_read(param_2, &i_value, 4);
        rge_read(param_2, &x_size_i, 4);
        rge_read(param_2, &built_value, 4);
        rge_read(param_2, &z_i, 4);
        rge_read(param_2, &unique_id, 4);
        rge_read(param_2, &build_attempts_f, 4);

        ConstructionItem* item = construction_allocate_lot();
        if (item == nullptr) {
            continue;
        }
        construction_init_lot_head(item);
        BaseItem* base = construction_base_item(item);
        base->setTypeID(type_id);
        base->setGameID(in_progress_value);
        base->setUniqueID(skip_value);
        base->setX((float)y_i);
        base->setY((float)z_size_i);
        base->setZ((float)game_id);
        base->setXSize((float)y_size_i);
        base->setYSize((float)i_value);
        base->setZSize((float)x_size_i);
        base->setSkip(built_value);
        base->setName(lot_name);
        construction_item_set_in_progress(item, z_i);
        construction_item_set_built(item, unique_id);
        construction_item_set_build_attempts(item, (int)build_attempts_f);
        construction_append_lot(&this->constructionLots, item);
        this->numberConstructionLotsValue = this->numberConstructionLotsValue + 1;
    }

    rge_read(param_2, &this->numberRandomConstructionLotsValue, 4);
    int loaded_random = this->numberRandomConstructionLotsValue;
    this->numberRandomConstructionLotsValue = 0;
    for (int i = 0; i < loaded_random; ++i) {
        float lot_name_len_f = 0.0f;
        char lot_name[257];
        int built_value = 0;
        int i_value = 0;
        int x_size_i = 0;
        int y_i = 0;
        int z_i = 0;
        int unique_id = 0;
        int build_attempts_value = 0;
        int in_progress_value = 0;
        int skip_value = 0;
        int type_id = -1;
        int z_size_i = 0;
        int game_id = 0;
        float y_size_f = 0.0f;

        rge_read(param_2, &lot_name_len_f, 4);
        int lot_name_len = (int)lot_name_len_f;
        if (lot_name_len < 0) {
            lot_name_len = 0;
        }
        if (lot_name_len > 256) {
            lot_name_len = 256;
        }
        if (lot_name_len > 0) {
            rge_read(param_2, lot_name, lot_name_len);
        }
        lot_name[lot_name_len] = '\0';
        rge_read(param_2, &built_value, 4);
        rge_read(param_2, &i_value, 4);
        rge_read(param_2, &x_size_i, 4);
        rge_read(param_2, &y_i, 4);
        rge_read(param_2, &z_i, 4);
        rge_read(param_2, &unique_id, 4);
        rge_read(param_2, &build_attempts_value, 4);
        rge_read(param_2, &in_progress_value, 4);
        rge_read(param_2, &skip_value, 4);
        rge_read(param_2, &type_id, 4);
        rge_read(param_2, &z_size_i, 4);
        rge_read(param_2, &game_id, 4);
        rge_read(param_2, &y_size_f, 4);

        ConstructionItem* item = construction_allocate_lot();
        if (item == nullptr) {
            continue;
        }
        construction_init_lot_head(item);
        BaseItem* base = construction_base_item(item);
        base->setTypeID(built_value);
        base->setGameID(i_value);
        base->setUniqueID(x_size_i);
        base->setX((float)y_i);
        base->setY((float)z_i);
        base->setZ((float)unique_id);
        base->setXSize((float)build_attempts_value);
        base->setYSize((float)in_progress_value);
        base->setZSize((float)skip_value);
        base->setSkip(type_id);
        base->setName(lot_name);
        construction_item_set_in_progress(item, z_size_i);
        construction_item_set_built(item, game_id);
        construction_item_set_build_attempts(item, (int)y_size_f);
        construction_append_lot(&this->randomConstructionLots, item);
        this->numberRandomConstructionLotsValue = this->numberRandomConstructionLotsValue + 1;
    }
}

// Offset: 0x0040B120
// TODO: Partial parity pending ConstructionItem destructor parity.
ConstructionAIModule::~ConstructionAIModule() {
    if (0 < this->numberConstructionLotsValue) {
        this->removeOldLots();
    }
    construction_destroy_list_nodes(&this->randomConstructionLots);
    this->numberRandomConstructionLotsValue = 0;
}

int ConstructionAIModule::loggingHistory() {
    return reinterpret_cast<AIModule*>(this)->AIModule::loggingHistory();
}

void ConstructionAIModule::setLogHistory(int param_1) {
    reinterpret_cast<AIModule*>(this)->AIModule::setLogHistory(param_1);
}

void ConstructionAIModule::toggleLogHistory() {
    reinterpret_cast<AIModule*>(this)->AIModule::toggleLogHistory();
}

void ConstructionAIModule::setHistoryFilename(char* param_1) {
    reinterpret_cast<AIModule*>(this)->AIModule::setHistoryFilename(param_1);
}

int ConstructionAIModule::loggingCommonHistory() {
    return reinterpret_cast<AIModule*>(this)->AIModule::loggingCommonHistory();
}

void ConstructionAIModule::setLogCommonHistory(int param_1) {
    reinterpret_cast<AIModule*>(this)->AIModule::setLogCommonHistory(param_1);
}

void ConstructionAIModule::toggleLogCommonHistory() {
    reinterpret_cast<AIModule*>(this)->AIModule::toggleLogCommonHistory();
}

int ConstructionAIModule::loadState(char* param_1) {
    return reinterpret_cast<AIModule*>(this)->AIModule::loadState(param_1);
}

int ConstructionAIModule::saveState(char* param_1) {
    return reinterpret_cast<AIModule*>(this)->AIModule::saveState(param_1);
}

int ConstructionAIModule::gleanState(int param_1) {
    return reinterpret_cast<AIModule*>(this)->AIModule::gleanState(param_1);
}

int ConstructionAIModule::processMessage(AIModuleMessage* param_1) {
    return reinterpret_cast<AIModule*>(this)->AIModule::processMessage(param_1);
}

int ConstructionAIModule::update(int param_1) {
    return reinterpret_cast<AIModule*>(this)->AIModule::update(param_1);
}

void ConstructionAIModule::setCallbackMessage(AIModuleMessage* param_1) {
    reinterpret_cast<AIModule*>(this)->AIModule::setCallbackMessage(param_1);
}

int ConstructionAIModule::filterOutMessage(AIModuleMessage* param_1) {
    return reinterpret_cast<AIModule*>(this)->AIModule::filterOutMessage(param_1);
}

// Offset: 0x0040B1A0
// TODO: Partial parity pending ConstructionItem constructor/destructor parity.
int ConstructionAIModule::save(int param_1) const {
    rge_write(param_1, (void*)&this->numberConstructionLotsValue, 4);

    float plan_len = (float)std::strlen(this->constructionPlanNameValue);
    rge_write(param_1, &plan_len, 4);
    rge_write(param_1, (void*)this->constructionPlanNameValue, (int)plan_len);
    rge_write(param_1, (void*)&this->xReferencePointValue, 4);
    rge_write(param_1, (void*)&this->yReferencePointValue, 4);
    rge_write(param_1, (void*)&this->zReferencePointValue, 4);
    rge_write(param_1, (void*)&this->mapXSizeValue, 4);
    rge_write(param_1, (void*)&this->mapYSizeValue, 4);

    const ConstructionItem* head = &this->constructionLots;
    const ConstructionItem* item = this->constructionLots.next;
    while ((item != head) && (item != nullptr)) {
        const BaseItem* base = construction_base_item(item);
        float lot_name_len = (float)std::strlen(base->nameValue);
        rge_write(param_1, &lot_name_len, 4);
        rge_write(param_1, (void*)base->nameValue, (int)lot_name_len);

        float type_id = (float)base->typeID();
        float game_id = (float)base->gameID();
        float unique_id = (float)base->uniqueID();
        int x = (int)base->x();
        int y = (int)base->y();
        int z = (int)base->z();
        int x_size = (int)base->xSize();
        int y_size = (int)base->ySize();
        int z_size = (int)base->zSize();
        int skip = base->skip();
        int in_progress = construction_item_in_progress(item);
        int built = construction_item_built(item);
        float attempts = (float)construction_item_build_attempts(item);

        rge_write(param_1, &type_id, 4);
        rge_write(param_1, &game_id, 4);
        rge_write(param_1, &unique_id, 4);
        rge_write(param_1, &x, 4);
        rge_write(param_1, &y, 4);
        rge_write(param_1, &z, 4);
        rge_write(param_1, &x_size, 4);
        rge_write(param_1, &y_size, 4);
        rge_write(param_1, &z_size, 4);
        rge_write(param_1, &skip, 4);
        rge_write(param_1, &in_progress, 4);
        rge_write(param_1, &built, 4);
        rge_write(param_1, &attempts, 4);
        item = item->next;
    }

    rge_write(param_1, (void*)&this->numberRandomConstructionLotsValue, 4);
    head = &this->randomConstructionLots;
    item = this->randomConstructionLots.next;
    while ((item != head) && (item != nullptr)) {
        const BaseItem* base = construction_base_item(item);
        float lot_name_len = (float)std::strlen(base->nameValue);
        rge_write(param_1, &lot_name_len, 4);
        rge_write(param_1, (void*)base->nameValue, (int)lot_name_len);

        float type_id = (float)base->typeID();
        float game_id = (float)base->gameID();
        float unique_id = (float)base->uniqueID();
        int x = (int)base->x();
        int y = (int)base->y();
        int z = (int)base->z();
        int x_size = (int)base->xSize();
        int y_size = (int)base->ySize();
        int z_size = (int)base->zSize();
        int skip = base->skip();
        int in_progress = construction_item_in_progress(item);
        int built = construction_item_built(item);
        float attempts = (float)construction_item_build_attempts(item);

        rge_write(param_1, &type_id, 4);
        rge_write(param_1, &game_id, 4);
        rge_write(param_1, &unique_id, 4);
        rge_write(param_1, &x, 4);
        rge_write(param_1, &y, 4);
        rge_write(param_1, &z, 4);
        rge_write(param_1, &x_size, 4);
        rge_write(param_1, &y_size, 4);
        rge_write(param_1, &z_size, 4);
        rge_write(param_1, &skip, 4);
        rge_write(param_1, &in_progress, 4);
        rge_write(param_1, &built, 4);
        rge_write(param_1, &attempts, 4);
        item = item->next;
    }
    return 1;
}

// Offset: 0x0040B690
// TODO: Partial parity pending ConstructionItem constructor/destructor parity.
int ConstructionAIModule::loadConstructionPlan(char* param_1, int param_2, int param_3, float param_4, float param_5, float param_6) const {
    ConstructionAIModule* self = const_cast<ConstructionAIModule*>(this);
    self->setReferencePoint(param_2, param_3, param_4, param_5, param_6);
    if (0 < self->numberConstructionLotsValue) {
        self->removeOldLots();
    }

    std::strncpy(self->constructionPlanNameValue, param_1, 0x3F);
    self->constructionPlanNameValue[0x3F] = '\0';

    if (std::strcmp(self->constructionPlanNameValue, "NONE") == 0) {
        reinterpret_cast<AIModule*>(self)->AIModule::logCommonHistory((char*)"There is no construction plan to load.");
        return 1;
    }

    reinterpret_cast<AIModule*>(self)->AIModule::logCommonHistory((char*)"Loading construction plan in file '%s'.", param_1);
    char path[260];
    ::sprintf(path, "%s", self->constructionPlanNameValue);
    FILE* fp = ::fopen(path, "r");
    if (fp == nullptr) {
        return 1;
    }

    char line[256];
    while (::fgets(line, sizeof(line), fp) != nullptr) {
        if ((line[0] == '/') && (line[1] == '/')) {
            continue;
        }

        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
        float x_size = 0.0f;
        float y_size = 0.0f;
        float z_size = 0.0f;
        int type_id = -1;
        char name[64];
        name[0] = '\0';
        if (::sscanf(line, "%f %f %f %f %f %f %d %63s", &x, &y, &z, &x_size, &y_size, &z_size, &type_id, name) != 8) {
            continue;
        }

        x = self->xReferencePointValue + x;
        y = self->yReferencePointValue + y;
        z = self->zReferencePointValue + z;
        if (self->lot(x, y) != nullptr) {
            continue;
        }

        ConstructionItem* item = construction_allocate_lot();
        if (item == nullptr) {
            continue;
        }
        construction_init_lot_head(item);
        BaseItem* base = construction_base_item(item);
        base->setX(x);
        base->setY(y);
        base->setZ(z);
        base->setXSize(x_size);
        base->setYSize(y_size);
        base->setZSize(z_size);
        base->setTypeID(type_id);
        base->setName(name);
        construction_append_lot(&self->constructionLots, item);
        self->numberConstructionLotsValue = self->numberConstructionLotsValue + 1;
    }

    ::fclose(fp);
    if (std::strstr(self->constructionPlanNameValue, ".tmp") != nullptr) {
        _unlink(self->constructionPlanNameValue);
    }
    return 1;
}

// Offset: 0x0040B970
// Fully verified. Source of truth: aiconmod.cpp.decomp @ 0x0040B970
char* ConstructionAIModule::constructionPlanName() {
    return this->constructionPlanNameValue;
}

// Offset: 0x0040B980
// Fully verified. Source of truth: aiconmod.cpp.decomp @ 0x0040B980
void ConstructionAIModule::setReferencePoint(int param_1, int param_2, float param_3, float param_4, float param_5) {
    this->mapXSizeValue = param_1;
    this->mapYSizeValue = param_2;
    this->xReferencePointValue = param_3;
    this->yReferencePointValue = param_4;
    this->zReferencePointValue = param_5;

    if ((param_3 <= 0.0f) || (param_4 <= 0.0f) || ((float)param_1 <= param_3) || ((float)param_2 <= param_4)) {
        removeOldLots();
        return;
    }

    ConstructionItem* head = &this->constructionLots;
    ConstructionItem* item = head->next;
    while ((item != head) && (item != nullptr)) {
        ConstructionItem* next = item->next;
        BaseItem* base = construction_base_item(item);
        base->setX(base->x() + param_3);
        base->setY(base->y() + param_4);
        base->setZ(base->z() + param_5);

        const float x = base->x();
        const float y = base->y();
        const float x_size = base->xSize();
        const float y_size = base->ySize();
        const int out_of_bounds =
            (x - x_size * 0.5f < 0.0f) ||
            (y - y_size * 0.5f < 0.0f) ||
            ((float)(this->mapXSizeValue - 1) < x + x_size * 0.5f) ||
            ((float)(this->mapYSizeValue - 1) < y + y_size * 0.5f);
        if (out_of_bounds != 0) {
            this->numberConstructionLotsValue = this->numberConstructionLotsValue - 1;
            item->prev->next = item->next;
            item->next->prev = item->prev;
            ::operator delete(item);
        }
        item = next;
    }
}

// Offset: 0x0040BB70
// Fully verified. Source of truth: aiconmod.cpp.decomp @ 0x0040BB70
float ConstructionAIModule::xReferencePoint() {
    return this->xReferencePointValue;
}

// Offset: 0x0040BB80
// Fully verified. Source of truth: aiconmod.cpp.decomp @ 0x0040BB80
float ConstructionAIModule::yReferencePoint() {
    return this->yReferencePointValue;
}

// Offset: 0x0040BB90
// Fully verified. Source of truth: aiconmod.cpp.decomp @ 0x0040BB90
ConstructionItem* ConstructionAIModule::placeStructure(BuildItem* param_1) const {
    (void)param_1;
    return nullptr;
}

// Offset: 0x0040BBA0
// Fully verified. Source of truth: aiconmod.cpp.decomp @ 0x0040BBA0
ConstructionAIModule::PlacementResult ConstructionAIModule::lastPlacementReturnCode() {
    return this->lastPlacementReturnCodeValue;
}

// Offset: 0x0040BBB0
// Fully verified. Source of truth: aiconmod.cpp.decomp @ 0x0040BBB0
void ConstructionAIModule::setBuilt(ConstructionItem* param_1, int param_2) const {
    ConstructionItem* item = this->constructionLots.next;
    while ((item != &this->constructionLots) && (item != nullptr)) {
        if (construction_items_equal(item, param_1) != 0) {
            construction_item_set_built(item, param_2);
            return;
        }
        item = item->next;
    }
}

// Offset: 0x0040BC00
// Fully verified. Source of truth: aiconmod.cpp.decomp @ 0x0040BC00
int ConstructionAIModule::unplaceStructure(ConstructionItem* param_1, int param_2) const {
    ConstructionItem* item = this->constructionLots.next;
    while ((item != &this->constructionLots) && (item != nullptr)) {
        if (construction_items_equal(item, param_1) != 0) {
            construction_item_set_in_progress(item, 0);
            construction_item_set_built(item, 0);
            int unique_id = construction_base_item(item)->uniqueID();
            construction_base_item(item)->setUniqueID(-1);
            if (param_2 == 1) {
                construction_item_decrement_build_attempts(item);
            }
            return unique_id;
        }
        item = item->next;
    }
    return -1;
}

// Offset: 0x0040BC80
// Fully verified. Source of truth: aiconmod.cpp.decomp @ 0x0040BC80
int ConstructionAIModule::unplaceStructure(float param_1, float param_2, int param_3) const {
    ConstructionItem* item = this->constructionLots.next;
    while ((item != &this->constructionLots) && (item != nullptr)) {
        const BaseItem* base = construction_base_item(item);
        if ((base->x() == param_1) && (base->y() == param_2)) {
            construction_item_set_in_progress(item, 0);
            construction_item_set_built(item, 0);
            int unique_id = construction_base_item(item)->uniqueID();
            construction_base_item(item)->setUniqueID(-1);
            if (param_3 == 1) {
                construction_item_decrement_build_attempts(item);
            }
            return unique_id;
        }
        item = item->next;
    }
    return -1;
}

// Offset: 0x0040BD10
// Fully verified. Source of truth: aiconmod.cpp.decomp @ 0x0040BD10
void ConstructionAIModule::decrementBuildAttempts(float param_1, float param_2, int param_3) const {
    ConstructionItem* item = const_cast<ConstructionAIModule*>(this)->lot(param_1, param_2);
    if ((item != nullptr) && (0 < param_3)) {
        do {
            construction_item_decrement_build_attempts(item);
            param_3 = param_3 - 1;
        } while (param_3 != 0);
    }
}

// Offset: 0x0040BD40
// Fully verified. Source of truth: aiconmod.cpp.decomp @ 0x0040BD40
void ConstructionAIModule::incrementBuildAttempts(float param_1, float param_2, int param_3) const {
    ConstructionItem* item = const_cast<ConstructionAIModule*>(this)->lot(param_1, param_2);
    if ((item != nullptr) && (0 < param_3)) {
        do {
            construction_item_increment_build_attempts(item);
            param_3 = param_3 - 1;
        } while (param_3 != 0);
    }
}

// Offset: 0x0040BD70
// Fully verified. Source of truth: aiconmod.cpp.decomp @ 0x0040BD70
ConstructionItem* ConstructionAIModule::lot(float param_1, float param_2) {
    ConstructionItem* item = this->constructionLots.next;
    while ((item != &this->constructionLots) && (item != nullptr)) {
        BaseItem* base = construction_base_item(item);
        if ((base->x() == param_1) && (base->y() == param_2)) {
            return item;
        }
        item = item->next;
    }

    item = this->randomConstructionLots.next;
    while ((item != &this->randomConstructionLots) && (item != nullptr)) {
        BaseItem* base = construction_base_item(item);
        if ((base->x() == param_1) && (base->y() == param_2)) {
            return item;
        }
        item = item->next;
    }
    return nullptr;
}

// Offset: 0x0040BE10
// Fully verified. Source of truth: aiconmod.cpp.decomp @ 0x0040BE10
ConstructionItem* ConstructionAIModule::randomLot(float param_1, float param_2) {
    ConstructionItem* item = this->randomConstructionLots.next;
    while ((item != &this->randomConstructionLots) && (item != nullptr)) {
        BaseItem* base = construction_base_item(item);
        if ((base->x() == param_1) && (base->y() == param_2)) {
            return item;
        }
        item = item->next;
    }
    return nullptr;
}

// Offset: 0x0040BE70
// TODO: Partial parity pending ConstructionItem scalar deleting destructor parity.
void ConstructionAIModule::removeOldLots() {
    construction_destroy_list_nodes(&this->constructionLots);
    this->numberConstructionLotsValue = 0;
}
