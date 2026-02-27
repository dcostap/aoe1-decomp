#include "../include/ResearchAIModule.h"

#include "../include/AIModule.h"
#include "../include/ResourceItem.h"
#include "../include/globals.h"

#include <io.h>
#include <new>
#include <stdio.h>
#include <string.h>

namespace {
char kResearchAIName[] = "Research AI";
char kNone[] = "NONE";

AIModule* as_ai(ResearchAIModule* self) {
    return reinterpret_cast<AIModule*>(self);
}

void initialize_tech_sentinel(ResearchAIModule* self) {
    self->techTree.next = &self->techTree;
    self->techTree.prev = &self->techTree;
    self->techTree.idValue = 0;
    self->techTree.nameValue[0] = '\0';
    self->techTree.resourceCostValue = nullptr;
}

void copy_name(char* dest, int capacity, const char* src) {
    if (capacity < 1) {
        return;
    }
    if (src == nullptr) {
        dest[0] = '\0';
        return;
    }
    strncpy(dest, src, (size_t)(capacity - 1));
    dest[capacity - 1] = '\0';
}

void discard_bytes(int handle, int bytes_to_discard) {
    char discard_buffer[256];
    while (bytes_to_discard > 0) {
        int chunk = bytes_to_discard;
        if (chunk > (int)sizeof(discard_buffer)) {
            chunk = (int)sizeof(discard_buffer);
        }
        rge_read(handle, discard_buffer, chunk);
        bytes_to_discard -= chunk;
    }
}

void read_string(int handle, char* out_buffer, int out_capacity) {
    int length = 0;
    rge_read(handle, &length, 4);
    if (length < 0) {
        length = 0;
    }
    int copy_length = length;
    if (copy_length >= out_capacity) {
        copy_length = out_capacity - 1;
    }
    if (copy_length > 0) {
        rge_read(handle, out_buffer, copy_length);
    }
    out_buffer[copy_length] = '\0';
    if (length > copy_length) {
        discard_bytes(handle, length - copy_length);
    }
}

void write_string(int handle, const char* text) {
    int length = (int)strlen(text);
    rge_write(handle, &length, 4);
    if (length > 0) {
        rge_write(handle, (void*)text, length);
    }
}

ResourceItem* create_resource_cost(const int costs[4]) {
    ResourceItem* cost = new (std::nothrow) ResourceItem;
    if (cost == nullptr) {
        return nullptr;
    }

    memset(cost, 0, sizeof(ResourceItem));
    cost->next = cost;
    cost->prev = cost;
    cost->numberValue = 4;
    for (int i = 0; i < 4; ++i) {
        cost->valueValue[i] = costs[i];
        cost->sortedValue[i] = costs[i];
        cost->sortedIndexValue[i] = i;
    }
    for (int i = 4; i < 8; ++i) {
        cost->sortedIndexValue[i] = i;
    }

    return cost;
}

TechnologyItem* create_technology_item(int id, const char* name, const int costs[4]) {
    TechnologyItem* tech = new (std::nothrow) TechnologyItem;
    if (tech == nullptr) {
        return nullptr;
    }

    memset(tech, 0, sizeof(TechnologyItem));
    tech->next = tech;
    tech->prev = tech;
    tech->idValue = id;
    copy_name(tech->nameValue, (int)sizeof(tech->nameValue), name);
    tech->resourceCostValue = create_resource_cost(costs);
    return tech;
}

void destroy_technology_item(TechnologyItem* tech) {
    if (tech == nullptr) {
        return;
    }
    delete tech;
}

void append_technology_item(ResearchAIModule* self, TechnologyItem* tech) {
    TechnologyItem* sentinel = &self->techTree;
    tech->next = sentinel;
    tech->prev = sentinel->prev;
    sentinel->prev->next = tech;
    sentinel->prev = tech;
}
}

// TODO: STUB - TechnologyItem destructor body not yet transliterated from aitchitm.cpp.decomp.
TechnologyItem::~TechnologyItem() {
    delete this->resourceCostValue;
    this->resourceCostValue = nullptr;
}

// TODO: STUB - ResourceItem destructor body not yet transliterated from airesitm.cpp.decomp.
ResourceItem::~ResourceItem() {}

// Offset: 0x00411670
// Fully verified. Source of truth: airchmod.cpp.decomp @ 0x00411670
ResearchAIModule::ResearchAIModule(void* param_1, int param_2) {
    new ((AIModule*)this) AIModule(kResearchAIName, 0x3EE, param_2, param_1);
    this->md = nullptr;
    initialize_tech_sentinel(this);
    this->techTreeLengthValue = 0;
    this->techTreeNameValue[0] = '\0';
}

// Offset: 0x00411740
// Fully verified. Source of truth: airchmod.cpp.decomp @ 0x00411740
ResearchAIModule::ResearchAIModule(int param_1, int param_2) {
    new ((AIModule*)this) AIModule(kResearchAIName, 0x3EE, param_1, nullptr);
    this->md = nullptr;
    initialize_tech_sentinel(this);

    int name_length = 0;
    rge_read(param_2, &this->techTreeLengthValue, 4);
    rge_read(param_2, &name_length, 4);
    if (name_length > 0) {
        rge_read(param_2, this->techTreeNameValue, name_length);
    }
    this->techTreeNameValue[name_length] = '\0';

    for (int type_id = 0; type_id < this->techTreeLengthValue; ++type_id) {
        char name[257];
        int item_name_length = 0;
        int id = 0;
        int costs[4] = {0, 0, 0, 0};

        rge_read(param_2, &item_name_length, 4);
        if (item_name_length > 0) {
            rge_read(param_2, name, item_name_length);
        }
        name[item_name_length] = '\0';
        rge_read(param_2, &id, 4);
        for (int i = 0; i < 4; ++i) {
            rge_read(param_2, &costs[i], 4);
        }

        TechnologyItem* tech = create_technology_item(id, name, costs);
        if (tech != nullptr) {
            append_technology_item(this, tech);
        }
    }
}

// Offset: 0x00411940
// Fully verified. Source of truth: airchmod.cpp.decomp @ 0x00411940
ResearchAIModule::~ResearchAIModule() {
    if (0 < this->techTreeLengthValue) {
        removeOldTechTree();
    }
    as_ai(this)->~AIModule();
}

// TODO: Header model declares explicit overrides; forward to AIModule base behavior.
int ResearchAIModule::loggingHistory() {
    return as_ai(this)->loggingHistory();
}

void ResearchAIModule::setLogHistory(int param_1) {
    as_ai(this)->setLogHistory(param_1);
}

void ResearchAIModule::toggleLogHistory() {
    as_ai(this)->toggleLogHistory();
}

void ResearchAIModule::setHistoryFilename(char* param_1) {
    as_ai(this)->setHistoryFilename(param_1);
}

int ResearchAIModule::loggingCommonHistory() {
    return as_ai(this)->loggingCommonHistory();
}

void ResearchAIModule::setLogCommonHistory(int param_1) {
    as_ai(this)->setLogCommonHistory(param_1);
}

void ResearchAIModule::toggleLogCommonHistory() {
    as_ai(this)->toggleLogCommonHistory();
}

int ResearchAIModule::loadState(char* param_1) {
    return as_ai(this)->loadState(param_1);
}

int ResearchAIModule::saveState(char* param_1) {
    return as_ai(this)->saveState(param_1);
}

int ResearchAIModule::gleanState(int param_1) {
    return as_ai(this)->gleanState(param_1);
}

int ResearchAIModule::processMessage(AIModuleMessage* param_1) {
    return as_ai(this)->processMessage(param_1);
}

int ResearchAIModule::update(int param_1) {
    return as_ai(this)->update(param_1);
}

void ResearchAIModule::setCallbackMessage(AIModuleMessage* param_1) {
    as_ai(this)->setCallbackMessage(param_1);
}

int ResearchAIModule::filterOutMessage(AIModuleMessage* param_1) {
    return as_ai(this)->filterOutMessage(param_1);
}

// Offset: 0x004119B0
// Fully verified. Source of truth: airchmod.cpp.decomp @ 0x004119B0
void ResearchAIModule::setMainDecisionAI(MainDecisionAIModule* param_1) {
    this->md = param_1;
}

// Offset: 0x004119C0
// Fully verified. Source of truth: airchmod.cpp.decomp @ 0x004119C0
int ResearchAIModule::save(int param_1) {
    rge_write(param_1, &this->techTreeLengthValue, 4);
    write_string(param_1, this->techTreeNameValue);

    TechnologyItem* sentinel = &this->techTree;
    TechnologyItem* node = sentinel->next;
    while ((node != sentinel) && (node != nullptr)) {
        write_string(param_1, node->nameValue);
        rge_write(param_1, &node->idValue, 4);
        for (int i = 0; i < 4; ++i) {
            int value = 0;
            if (node->resourceCostValue != nullptr) {
                value = node->resourceCostValue->valueValue[i];
            }
            rge_write(param_1, &value, 4);
        }
        node = node->next;
    }

    return 1;
}

// Offset: 0x00411B40
// Fully verified. Source of truth: airchmod.cpp.decomp @ 0x00411B40
ResourceItem* ResearchAIModule::resourceCost(int param_1) {
    TechnologyItem* tech = item(param_1);
    if (tech == nullptr) {
        return nullptr;
    }
    return tech->resourceCostValue;
}

// Offset: 0x00411B60
// Fully verified. Source of truth: airchmod.cpp.decomp @ 0x00411B60
int ResearchAIModule::buildable(BuildItem* param_1) {
    (void)param_1;
    return 1;
}

// Offset: 0x00411B70
// Fully verified. Source of truth: airchmod.cpp.decomp @ 0x00411B70
void ResearchAIModule::research(BuildItem* param_1) {
    (void)param_1;
}

// Offset: 0x00411B80
// TODO: Partial parity - file parsing format string still needs asm audit.
int ResearchAIModule::loadTechnologyTree(char* param_1) {
    if (0 < this->techTreeLengthValue) {
        removeOldTechTree();
    }

    copy_name(this->techTreeNameValue, (int)sizeof(this->techTreeNameValue), param_1);
    if (_stricmp(this->techTreeNameValue, kNone) == 0) {
        as_ai(this)->logCommonHistory((char*)"loadTechnologyTree(\"%s\")", this->techTreeNameValue);
        return 1;
    }

    as_ai(this)->logCommonHistory((char*)"loadTechnologyTree(\"%s\")", this->techTreeNameValue);
    FILE* file = fopen(this->techTreeNameValue, "r");
    if (file == nullptr) {
        return 0;
    }

    char line[256];
    while (fgets(line, (int)sizeof(line), file) != nullptr) {
        int id = 0;
        int costs[4] = {0, 0, 0, 0};
        char name[64];
        name[0] = '\0';

        if (sscanf(line, "%d %63s %d %d %d %d", &id, name, &costs[0], &costs[1], &costs[2], &costs[3]) == 6) {
            TechnologyItem* tech = create_technology_item(id, name, costs);
            if (tech != nullptr) {
                append_technology_item(this, tech);
                this->techTreeLengthValue = this->techTreeLengthValue + 1;
            }
        }
    }

    fclose(file);
    if (strstr(this->techTreeNameValue, ".tmp") != nullptr) {
        _unlink(this->techTreeNameValue);
    }
    return 1;
}

// Offset: 0x00411E00
// Fully verified. Source of truth: airchmod.cpp.decomp @ 0x00411E00
int ResearchAIModule::numberTechnologyItems() const {
    return this->techTreeLengthValue;
}

// Offset: 0x00411E10
// Fully verified. Source of truth: airchmod.cpp.decomp @ 0x00411E10
char* ResearchAIModule::technologyTreeName() {
    return this->techTreeNameValue;
}

// Offset: 0x00411E20
// Fully verified. Source of truth: airchmod.cpp.decomp @ 0x00411E20
void ResearchAIModule::removeOldTechTree() {
    TechnologyItem* sentinel = &this->techTree;
    TechnologyItem* node = sentinel->next;
    while ((node != sentinel) && (node != nullptr)) {
        TechnologyItem* next = node->next;
        destroy_technology_item(node);
        node = next;
    }
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
    this->techTreeLengthValue = 0;
}

// Offset: 0x00411E70
// Fully verified. Source of truth: airchmod.cpp.decomp @ 0x00411E70
TechnologyItem* ResearchAIModule::item(int param_1) {
    TechnologyItem* node = this->techTree.next;
    if (node != &this->techTree) {
        while (node != nullptr) {
            if (node->idValue == param_1) {
                return node;
            }
            node = node->next;
            if (node == &this->techTree) {
                return nullptr;
            }
        }
    }
    return nullptr;
}
