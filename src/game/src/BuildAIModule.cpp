#include "../include/BuildAIModule.h"

#include "../include/AIModule.h"
#include "../include/AIModuleID.h"
#include "../include/BaseItem.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/globals.h"

#include <io.h>
#include <new>
#include <stdio.h>
#include <string.h>

namespace {
struct AIModulePrefix {
    void* vftable;
    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[64];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    FILE* historyLogFile;
    char historyLogFilename[64];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;
};
static_assert(sizeof(AIModulePrefix) == 0xF0, "AIModule prefix size mismatch");

BaseItem* build_item_base(BuildItem* item) {
    return reinterpret_cast<BaseItem*>(item);
}

AIModule* as_ai(BuildAIModule* self) {
    return reinterpret_cast<AIModule*>(self);
}

void write_string(int handle, const char* text) {
    int length = (int)strlen(text);
    rge_write(handle, &length, 4);
    if (length > 0) {
        rge_write(handle, (void*)text, length);
    }
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

void initialize_build_item_defaults(BuildItem* item) {
    BaseItem* base = build_item_base(item);
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

    item->next = nullptr;
    item->prev = nullptr;
    item->buildCategoryValue = -1;
    item->numberValue = 0;
    item->priorityValue = 0;
    item->progressValue = 0;
    item->builtValue = 0;
    item->buildAttemptsValue = 0;
    item->buildFromValue = -1;
    item->terrainSetValue = -1;
    item->terrainAdjacencyValue[0] = -1;
    item->terrainAdjacencyValue[1] = -1;
    item->placeOnElevationValue = 0;
    item->numberBuildsValue = 0;
    item->buildCapValue = -1;
    item->skipCyclesValue = 0;
    item->permanentSkipValue = '\0';
}

BuildItem* allocate_build_item(int build_category, int type_id, int unique_id, int number_value, int priority_value, int build_from,
                               char* name, float x_size, float y_size, float z_size, int terrain_set, int terrain_adj_1, int terrain_adj_2,
                               int place_on_elevation) {
    BuildItem* item = (BuildItem*)::operator new(sizeof(BuildItem), std::nothrow);
    if (item == nullptr) {
        return nullptr;
    }

    BaseItem* base = build_item_base(item);
    base->setTypeID(type_id);
    base->setGameID(-1);
    base->setUniqueID(unique_id);
    base->setName(name);
    base->setX(-1.0f);
    base->setY(-1.0f);
    base->setZ(-1.0f);
    base->setXSize(x_size);
    base->setYSize(y_size);
    base->setZSize(z_size);
    base->setSkip(0);

    item->next = nullptr;
    item->prev = nullptr;
    item->buildCategoryValue = build_category;
    item->numberValue = number_value;
    item->priorityValue = priority_value;
    item->progressValue = 0;
    item->builtValue = 0;
    item->buildAttemptsValue = 0;
    item->buildFromValue = build_from;
    item->terrainSetValue = terrain_set;
    item->terrainAdjacencyValue[0] = terrain_adj_1;
    item->terrainAdjacencyValue[1] = terrain_adj_2;
    item->placeOnElevationValue = place_on_elevation;
    item->numberBuildsValue = 0;
    item->buildCapValue = -1;
    item->skipCyclesValue = 0;
    item->permanentSkipValue = '\0';

    return item;
}

void append_build_item(BuildAIModule* self, BuildItem* item) {
    BuildItem* head = &self->buildList;
    BuildItem* tail = head->prev;
    item->next = head;
    item->prev = tail;
    tail->next = item;
    head->prev = item;
}

void initialize_ai_prefix(BuildAIModule* self, int player_number) {
    AIModulePrefix* ai_prefix = reinterpret_cast<AIModulePrefix*>(self);
    new (&ai_prefix->idValue) AIModuleID((char*)"Build AI", 0x3E9);
    ai_prefix->playerNumberValue = player_number;
    strncpy(ai_prefix->playerNameValue, "Unknown", 0x3F);
    ai_prefix->playerNameValue[0x3F] = '\0';
    ai_prefix->runningValue = 0;
    ai_prefix->pausedValue = 0;
    ai_prefix->logHistoryValue = 0;
    ai_prefix->logCommonHistoryValue = 0;
    ai_prefix->historyLogFile = nullptr;
    ai_prefix->historyLogFilename[0] = '\0';
    ai_prefix->intelligenceLevelValue = 5;
    ai_prefix->priorityValue = 0x32;
    ai_prefix->processFrameValue = 0;
}
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408470
BuildItem::~BuildItem() {}

// TODO: Partial parity to preserve flattened AIModule/BuildAIModule layout.
BuildAIModule::BuildAIModule(void* param_1, int param_2) {
    (void)param_1;
    initialize_ai_prefix(this, param_2);
    initialize_build_item_defaults(&this->buildList);
    this->buildList.next = &this->buildList;
    this->buildList.prev = &this->buildList;
    this->buildListLengthValue = 0;
    this->numberItemsIntoBuildListValue = 0;
    this->typesToIgnore.value = nullptr;
    this->typesToIgnore.numberValue = 0;
    this->typesToIgnore.desiredNumberValue = 0;
    this->typesToIgnore.maximumSizeValue = 0;
    this->buildListNameValue[0] = '\0';
    strncpy(this->lastBuildItemRequestedValue, "None", 0x100);
    this->lastBuildItemRequestedValue[0x100] = '\0';
    strncpy(this->currentBuildItemRequestedValue, "None", 0x100);
    this->currentBuildItemRequestedValue[0x100] = '\0';
    strncpy(this->nextBuildItemRequestedValue, "None", 0x100);
    this->nextBuildItemRequestedValue[0x100] = '\0';
}

// TODO: Partial parity to preserve flattened AIModule/BuildAIModule layout.
BuildAIModule::BuildAIModule(int param_1, int param_2) {
    initialize_ai_prefix(this, param_1);
    initialize_build_item_defaults(&this->buildList);
    this->buildList.next = &this->buildList;
    this->buildList.prev = &this->buildList;
    this->buildListLengthValue = 0;
    this->numberItemsIntoBuildListValue = 0;
    this->typesToIgnore.value = nullptr;
    this->typesToIgnore.numberValue = 0;
    this->typesToIgnore.desiredNumberValue = 0;
    this->typesToIgnore.maximumSizeValue = 0;

    rge_read(param_2, &this->buildListLengthValue, 4);
    read_string(param_2, this->buildListNameValue, (int)sizeof(this->buildListNameValue));
    read_string(param_2, this->lastBuildItemRequestedValue, (int)sizeof(this->lastBuildItemRequestedValue));
    read_string(param_2, this->currentBuildItemRequestedValue, (int)sizeof(this->currentBuildItemRequestedValue));
    if (save_game_version < 3.1f) {
        strncpy(this->nextBuildItemRequestedValue, "None", 0x100);
        this->nextBuildItemRequestedValue[0x100] = '\0';
    } else {
        read_string(param_2, this->nextBuildItemRequestedValue, (int)sizeof(this->nextBuildItemRequestedValue));
    }

    int loaded_count = this->buildListLengthValue;
    this->buildListLengthValue = 0;
    rge_read(param_2, &this->numberItemsIntoBuildListValue, 4);

    for (int index = 0; index < loaded_count; ++index) {
        char name[257];
        read_string(param_2, name, (int)sizeof(name));

        int type_id = -1;
        int game_id = -1;
        int unique_id = -1;
        float x = -1.0f;
        float y = -1.0f;
        float z = -1.0f;
        float x_size = 0.0f;
        float y_size = 0.0f;
        float z_size = 0.0f;
        int skip = 0;
        int build_category = -1;
        int in_progress = 0;
        int built = 0;
        int build_attempts = 0;
        int build_from = -1;
        int terrain_set = -1;
        int terrain_adj_1 = -1;
        int terrain_adj_2 = -1;
        int place_on_elevation = 0;
        int number_builds = 0;
        int build_cap = -1;
        int skip_cycles = 0;
        uchar permanent_skip = 0;

        rge_read(param_2, &type_id, 4);
        rge_read(param_2, &game_id, 4);
        rge_read(param_2, &unique_id, 4);
        rge_read(param_2, &x, 4);
        rge_read(param_2, &y, 4);
        rge_read(param_2, &z, 4);
        rge_read(param_2, &x_size, 4);
        rge_read(param_2, &y_size, 4);
        rge_read(param_2, &z_size, 4);
        rge_read(param_2, &skip, 4);
        rge_read(param_2, &build_category, 4);
        rge_read(param_2, &in_progress, 4);
        rge_read(param_2, &built, 4);
        rge_read(param_2, &build_attempts, 4);
        rge_read(param_2, &build_from, 4);
        rge_read(param_2, &terrain_set, 4);
        rge_read(param_2, &terrain_adj_1, 4);
        rge_read(param_2, &terrain_adj_2, 4);
        rge_read(param_2, &place_on_elevation, 4);
        rge_read(param_2, &number_builds, 4);
        if (save_game_version >= 2.2f) {
            rge_read(param_2, &build_cap, 4);
        }
        rge_read(param_2, &skip_cycles, 4);
        rge_read(param_2, &permanent_skip, 1);

        BuildItem* item =
            allocate_build_item(build_category, type_id, unique_id, 1, 0, build_from, name, x_size, y_size, z_size, terrain_set, terrain_adj_1, terrain_adj_2, place_on_elevation);
        if (item == nullptr) {
            continue;
        }

        BaseItem* base = build_item_base(item);
        base->setGameID(game_id);
        base->setX(x);
        base->setY(y);
        base->setZ(z);
        base->setSkip(skip);
        item->progressValue = in_progress;
        item->builtValue = built;
        item->buildAttemptsValue = build_attempts;
        item->numberBuildsValue = number_builds;
        item->buildCapValue = build_cap;
        item->skipCyclesValue = skip_cycles;
        item->permanentSkipValue = permanent_skip;

        append_build_item(this, item);
        this->buildListLengthValue = this->buildListLengthValue + 1;
    }
}

// TODO: Partial parity to preserve flattened AIModule/BuildAIModule layout.
BuildAIModule::~BuildAIModule() {
    if (this->buildListLengthValue > 0) {
        removeOldList();
    }

    if (this->typesToIgnore.value != nullptr) {
        ::operator delete(this->typesToIgnore.value);
        this->typesToIgnore.value = nullptr;
    }
    this->typesToIgnore.numberValue = 0;
    this->typesToIgnore.desiredNumberValue = 0;
    this->typesToIgnore.maximumSizeValue = 0;

    AIModulePrefix* ai_prefix = reinterpret_cast<AIModulePrefix*>(this);
    if ((ai_prefix->logCommonHistoryValue != 0) && (commonHistoryLogFile != nullptr)) {
        fclose(commonHistoryLogFile);
        commonHistoryLogFile = nullptr;
    }
    ai_prefix->idValue.~AIModuleID();
}

// TODO: Partial parity to preserve flattened AIModule/BuildAIModule layout.
int BuildAIModule::loggingHistory() {
    return as_ai(this)->AIModule::loggingHistory();
}

// TODO: Partial parity to preserve flattened AIModule/BuildAIModule layout.
void BuildAIModule::setLogHistory(int param_1) {
    as_ai(this)->AIModule::setLogHistory(param_1);
}

// TODO: Partial parity to preserve flattened AIModule/BuildAIModule layout.
void BuildAIModule::toggleLogHistory() {
    as_ai(this)->AIModule::toggleLogHistory();
}

// TODO: Partial parity to preserve flattened AIModule/BuildAIModule layout.
void BuildAIModule::setHistoryFilename(char* param_1) {
    as_ai(this)->AIModule::setHistoryFilename(param_1);
}

// TODO: Partial parity to preserve flattened AIModule/BuildAIModule layout.
int BuildAIModule::loggingCommonHistory() {
    return as_ai(this)->AIModule::loggingCommonHistory();
}

// TODO: Partial parity to preserve flattened AIModule/BuildAIModule layout.
void BuildAIModule::setLogCommonHistory(int param_1) {
    as_ai(this)->AIModule::setLogCommonHistory(param_1);
}

// TODO: Partial parity to preserve flattened AIModule/BuildAIModule layout.
void BuildAIModule::toggleLogCommonHistory() {
    as_ai(this)->AIModule::toggleLogCommonHistory();
}

// TODO: Partial parity to preserve flattened AIModule/BuildAIModule layout.
int BuildAIModule::loadState(char* param_1) {
    return as_ai(this)->AIModule::loadState(param_1);
}

// TODO: Partial parity to preserve flattened AIModule/BuildAIModule layout.
int BuildAIModule::saveState(char* param_1) {
    return as_ai(this)->AIModule::saveState(param_1);
}

// TODO: Partial parity to preserve flattened AIModule/BuildAIModule layout.
int BuildAIModule::gleanState(int param_1) {
    return as_ai(this)->AIModule::gleanState(param_1);
}

// TODO: Partial parity to preserve flattened AIModule/BuildAIModule layout.
int BuildAIModule::processMessage(AIModuleMessage* param_1) {
    return as_ai(this)->AIModule::processMessage(param_1);
}

// TODO: Partial parity to preserve flattened AIModule/BuildAIModule layout.
int BuildAIModule::update(int param_1) {
    return as_ai(this)->AIModule::update(param_1);
}

// TODO: Partial parity to preserve flattened AIModule/BuildAIModule layout.
void BuildAIModule::setCallbackMessage(AIModuleMessage* param_1) {
    as_ai(this)->AIModule::setCallbackMessage(param_1);
}

// TODO: Partial parity to preserve flattened AIModule/BuildAIModule layout.
int BuildAIModule::filterOutMessage(AIModuleMessage* param_1) {
    return as_ai(this)->AIModule::filterOutMessage(param_1);
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x00408DF0
int BuildAIModule::save(int param_1) {
    rge_write(param_1, &this->buildListLengthValue, 4);
    write_string(param_1, this->buildListNameValue);
    write_string(param_1, this->lastBuildItemRequestedValue);
    write_string(param_1, this->currentBuildItemRequestedValue);
    write_string(param_1, this->nextBuildItemRequestedValue);
    rge_write(param_1, &this->numberItemsIntoBuildListValue, 4);

    BuildItem* item = this->buildList.next;
    while ((item != &this->buildList) && (item != nullptr)) {
        BaseItem* base = build_item_base(item);
        write_string(param_1, base->name());

        int type_id = base->typeID();
        int game_id = base->gameID();
        int unique_id = base->uniqueID();
        float x = base->x();
        float y = base->y();
        float z = base->z();
        float x_size = base->xSize();
        float y_size = base->ySize();
        float z_size = base->zSize();
        int skip = base->skip();
        int build_category = item->buildCategoryValue;
        int in_progress = item->progressValue;
        int built = item->builtValue;
        int build_attempts = item->buildAttemptsValue;
        int build_from = item->buildFromValue;
        int terrain_set = item->terrainSetValue;
        int terrain_adj_1 = item->terrainAdjacencyValue[0];
        int terrain_adj_2 = item->terrainAdjacencyValue[1];
        int place_on_elevation = item->placeOnElevationValue;
        int number_builds = item->numberBuildsValue;
        int build_cap = item->buildCapValue;
        int skip_cycles = item->skipCyclesValue;
        uchar permanent_skip = item->permanentSkipValue;

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
        rge_write(param_1, &build_category, 4);
        rge_write(param_1, &in_progress, 4);
        rge_write(param_1, &built, 4);
        rge_write(param_1, &build_attempts, 4);
        rge_write(param_1, &build_from, 4);
        rge_write(param_1, &terrain_set, 4);
        rge_write(param_1, &terrain_adj_1, 4);
        rge_write(param_1, &terrain_adj_2, 4);
        rge_write(param_1, &place_on_elevation, 4);
        rge_write(param_1, &number_builds, 4);
        rge_write(param_1, &build_cap, 4);
        rge_write(param_1, &skip_cycles, 4);
        rge_write(param_1, &permanent_skip, 1);

        item = item->next;
    }
    return 1;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x004092F0
void BuildAIModule::displayBuildList() {
    as_ai(this)->AIModule::logCommonHistory((char*)"Build list: %s", this->buildListNameValue);

    for (BuildItem* item = this->buildList.next; (item != &this->buildList) && (item != nullptr); item = item->next) {
        BaseItem* base = build_item_base(item);
        if (item->builtValue == 1) {
            as_ai(this)->AIModule::logCommonHistory((char*)"BLT Type %4d, %-20s gID %4d Cat %4d", base->typeID(), base->name(), base->gameID(), item->buildCategoryValue);
        } else {
            as_ai(this)->AIModule::logCommonHistory((char*)"    Type %4d, %-20s gID %4d Cat %4d", base->typeID(), base->name(), base->gameID(), item->buildCategoryValue);
        }
    }
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x00409430
int BuildAIModule::loadBuildList(char* param_1, RGE_Player* param_2) {
    strncpy(this->buildListNameValue, param_1, 0x3F);
    this->buildListNameValue[0x3F] = '\0';

    if ((strcmp(this->buildListNameValue, "NONE") == 0) || (this->buildListNameValue[0] == '\0')) {
        as_ai(this)->AIModule::logCommonHistory((char*)"There is no build list to load.");
        return 1;
    }

    as_ai(this)->AIModule::logCommonHistory((char*)"Trying to load build list in file: %s", param_1);

    char temp_line[256];
    sprintf(temp_line, "%s", this->buildListNameValue);
    FILE* file_in = fopen(temp_line, "r");
    if (file_in == nullptr) {
        as_ai(this)->AIModule::logCommonHistory((char*)"  I cannot do it cap'n.");
        return 0;
    }

    as_ai(this)->AIModule::logCommonHistory((char*)"  File open successful, nuking and rebuilding list.");
    if (this->buildListLengthValue > 0) {
        removeOldList();
    }
    this->buildListLengthValue = 0;

    while (fgets(temp_line, (int)sizeof(temp_line), file_in) != nullptr) {
        if ((temp_line[0] == '/') && (temp_line[1] == '/')) {
            continue;
        }

        char type_char = '\0';
        int object_type_id = 0;
        char name[64];
        int item_count = 0;
        int build_from = 0;
        int build_cap = -1;
        memset(name, 0, sizeof(name));
        if (sscanf(temp_line, " %c %d %63s %d %d", &type_char, &object_type_id, name, &item_count, &build_from) < 5) {
            continue;
        }

        int build_category = -1;
        switch (type_char) {
        case 'A':
            build_category = 0;
            sscanf(temp_line, " %*c %d %63s %d %d %d", &object_type_id, name, &item_count, &build_from, &build_cap);
            break;
        case 'B':
            build_category = 0;
            break;
        case 'C':
            build_category = 4;
            break;
        case 'E':
            build_category = 5;
            break;
        case 'G':
            build_category = 6;
            break;
        case 'L':
            build_category = 3;
            break;
        case 'R':
            build_category = 1;
            break;
        case 'T':
            build_category = 2;
            sscanf(temp_line, " %*c %d %63s %d %d %d", &object_type_id, name, &item_count, &build_from, &build_cap);
            break;
        case 'U':
            build_category = 2;
            break;
        default:
            continue;
        }

        if (build_category == 0) {
            bool ignored = false;
            for (int index = 0; index < this->typesToIgnore.numberValue; ++index) {
                if (index >= this->typesToIgnore.maximumSizeValue) {
                    break;
                }
                if (this->typesToIgnore.value[index] == object_type_id) {
                    ignored = true;
                    break;
                }
            }
            if (ignored) {
                continue;
            }
        }

        float x_size = 3.0f;
        float y_size = 3.0f;
        if (((build_category == 0) || (build_category == 2)) && (object_type_id >= 0) && (object_type_id < param_2->master_object_num)) {
            RGE_Master_Static_Object* master_obj = param_2->master_objects[object_type_id];
            if (master_obj != nullptr) {
                x_size = master_obj->radius_x + master_obj->radius_x;
                y_size = master_obj->radius_y + master_obj->radius_y;
            }
        }

        for (int index = 0; index < item_count; ++index) {
            BuildItem* item = allocate_build_item(build_category, object_type_id, this->buildListLengthValue, 1, 0, build_from, name, x_size, y_size, 0.0f, -1, -1, -1, 0);
            if (item == nullptr) {
                continue;
            }
            item->buildCapValue = build_cap;
            append_build_item(this, item);
            this->buildListLengthValue = this->buildListLengthValue + 1;
        }
    }

    fclose(file_in);
    if (strstr(this->buildListNameValue, ".tmp") != nullptr) {
        _unlink(this->buildListNameValue);
    }
    return 1;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x004098A0
int BuildAIModule::buildListLength() const {
    return this->buildListLengthValue;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x004098B0
char* BuildAIModule::buildListName() {
    return this->buildListNameValue;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x004098C0
int BuildAIModule::haveBuildList() const {
    if (strcmp(this->buildListNameValue, "NONE") == 0) {
        return 0;
    }
    if (strcmp(this->buildListNameValue, "NULL") == 0) {
        return 0;
    }
    return (uint)(this->buildListNameValue[0] != '\0');
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x00409950
int BuildAIModule::insertItem(RGE_Player* param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    if (this->buildListLengthValue < param_7) {
        return 0;
    }

    BuildItem* insert_after = this->buildList.next;
    for (int index = 0; (insert_after != &this->buildList) && (index < param_7); ++index) {
        insert_after = insert_after->next;
    }

    char name[64];
    float x_size = 3.0f;
    float y_size = 3.0f;
    if (param_4 == 6) {
        strncpy(name, "SetGatherPercentage", 0x3F);
        name[0x3F] = '\0';
    } else {
        if (param_1->master_objects[param_2] == nullptr) {
            strncpy(name, "AddedBuildListItem", 0x3F);
            name[0x3F] = '\0';
        } else {
            strncpy(name, param_1->master_objects[param_2]->name, 0x3F);
            name[0x3F] = '\0';
            x_size = param_1->master_objects[param_2]->radius_x + param_1->master_objects[param_2]->radius_x;
            y_size = param_1->master_objects[param_2]->radius_y + param_1->master_objects[param_2]->radius_y;
        }
    }

    int unique_id = this->buildListLengthValue;
    for (int index = 0; index < param_3; ++index) {
        BuildItem* item = allocate_build_item(param_4, param_2, unique_id, 1, 0, param_5, name, x_size, y_size, 1.0f, -1, -1, -1, 0);
        if (item == nullptr) {
            return 0;
        }

        BaseItem* base = build_item_base(item);
        item->builtValue = 0;
        item->progressValue = 0;
        item->buildAttemptsValue = 0;
        base->setSkip(0);
        base->setGameID(-1);
        base->setX(-1.0f);
        base->setY(-1.0f);
        base->setZ(-1.0f);
        item->numberBuildsValue = 0;
        item->buildCapValue = param_6;
        item->skipCyclesValue = 0;
        item->permanentSkipValue = '\0';

        item->prev = insert_after;
        item->next = insert_after->next;
        insert_after->next->prev = item;
        insert_after->next = item;

        unique_id = unique_id + 1;
        this->buildListLengthValue = this->buildListLengthValue + 1;
    }

    return 1;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x00409B70
int BuildAIModule::numberItemsBuilt() const {
    int count = 0;
    for (BuildItem* item = this->buildList.next; (item != &this->buildList) && (item != nullptr); item = item->next) {
        if (item->builtValue == 1) {
            count = count + 1;
        }
    }
    return count;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x00409BB0
int BuildAIModule::numberItemsInProgress() const {
    int count = 0;
    for (BuildItem* item = this->buildList.next; (item != &this->buildList) && (item != nullptr); item = item->next) {
        if (item->progressValue == 1) {
            count = count + 1;
        }
    }
    return count;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x00409BF0
int BuildAIModule::numberItemsBuiltOrInProgress() const {
    int count = 0;
    for (BuildItem* item = this->buildList.next; (item != &this->buildList) && (item != nullptr); item = item->next) {
        if ((item->progressValue == 1) || (item->builtValue == 1)) {
            count = count + 1;
        }
    }
    return count;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x00409C30
int BuildAIModule::numberItemsIntoBuildList() const {
    return this->numberItemsIntoBuildListValue;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x00409C40
char* BuildAIModule::lastBuildItemRequested() const {
    return (char*)this->lastBuildItemRequestedValue;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x00409C50
char* BuildAIModule::currentBuildItemRequested() const {
    return (char*)this->currentBuildItemRequestedValue;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x00409C60
char* BuildAIModule::nextBuildItemRequested() const {
    return (char*)this->nextBuildItemRequestedValue;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x00409C70
int BuildAIModule::numberItemsOfType(int param_1, int param_2) {
    int count = 0;
    for (BuildItem* item = this->buildList.next; (item != &this->buildList) && (item != nullptr); item = item->next) {
        if ((build_item_base(item)->typeID() == param_1) && (item->buildCategoryValue == param_2)) {
            count = count + 1;
        }
    }
    return count;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x00409CD0
int BuildAIModule::numberBuiltItemsOfType(int param_1, int param_2) {
    int count = 0;
    for (BuildItem* item = this->buildList.next; (item != &this->buildList) && (item != nullptr); item = item->next) {
        if ((build_item_base(item)->typeID() == param_1) && (item->buildCategoryValue == param_2) && (item->builtValue == 1)) {
            count = count + 1;
        }
    }
    return count;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x00409D40
int BuildAIModule::numberUnbuiltItemsOfType(int param_1, int param_2) {
    int count = 0;
    for (BuildItem* item = this->buildList.next; (item != &this->buildList) && (item != nullptr); item = item->next) {
        if ((build_item_base(item)->typeID() == param_1) && (item->buildCategoryValue == param_2) && (item->builtValue == 0)) {
            count = count + 1;
        }
    }
    return count;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x00409DB0
int BuildAIModule::numberBuiltOrInProgressItemsOfType(int param_1, int param_2) {
    int count = 0;
    for (BuildItem* item = this->buildList.next; (item != &this->buildList) && (item != nullptr); item = item->next) {
        if ((build_item_base(item)->typeID() == param_1) && (item->buildCategoryValue == param_2) && ((item->builtValue == 1) || (item->progressValue == 1))) {
            count = count + 1;
        }
    }
    return count;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x00409E20
int BuildAIModule::numberInProgressItemsOfType(int param_1, int param_2) {
    int count = 0;
    for (BuildItem* item = this->buildList.next; (item != &this->buildList) && (item != nullptr); item = item->next) {
        if ((build_item_base(item)->typeID() == param_1) && (item->buildCategoryValue == param_2) && (item->progressValue == 1)) {
            count = count + 1;
        }
    }
    return count;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x00409E90
void BuildAIModule::removeOldList() {
    BuildItem* head = &this->buildList;
    BuildItem* item = head->next;
    while ((item != head) && (item != nullptr)) {
        BuildItem* next = item->next;
        item->~BuildItem();
        ::operator delete(item);
        item = next;
    }

    this->buildList.next = head;
    this->buildList.prev = head;
    this->buildListLengthValue = 0;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x00409EE0
BuildItem* BuildAIModule::anyBuildListItem(int param_1, int param_2, int param_3) {
    BuildItem* item = this->buildList.next;
    while ((item != &this->buildList) && (item != nullptr)) {
        if ((build_item_base(item)->typeID() == param_1) && ((param_2 == 0) || ((param_2 == 1) && (item->builtValue == param_3)))) {
            return item;
        }
        item = item->next;
    }
    return nullptr;
}

// Fully verified. Source of truth: aibldmod.cpp.decomp @ 0x00409F50
BuildItem* BuildAIModule::specificBuildListItem(int param_1) {
    BuildItem* item = this->buildList.next;
    while ((item != &this->buildList) && (item != nullptr)) {
        if (build_item_base(item)->uniqueID() == param_1) {
            return item;
        }
        item = item->next;
    }
    return nullptr;
}
