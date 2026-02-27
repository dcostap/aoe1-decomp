#include "../include/TribeInformationAIModule.h"

#include "../include/TribeMainDecisionAIModule.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_Info.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Tile.h"
#include "../include/RGE_Tile_List.h"
#include "../include/RGE_Tile_List_Node.h"
#include "../include/RGE_Visible_Map.h"
#include "../include/globals.h"

#include <cstring>
#include <cstdio>
#include <new>

namespace {
constexpr int kResourceTypeSlots = 4;
constexpr int kQuadrantCount = 4;
constexpr int kPathMapSize = 0xFE;
constexpr int kDefaultImportantMemory = 500;
constexpr int kDefaultBuildingLots = 200;
constexpr int kDefaultAttackMemories = 0x19;
constexpr int kPlayHistorySize = 16000;
constexpr int kUnitHistorySize = 11;

const char* kDefaultUnitHistoryFilename = "learn_Default.uh";
const char* kUnitHistoryFilenameFormat = "learn_%s.uh";

void tribe_reset_managed_array(ManagedArray<int>& array) {
    array.value = nullptr;
    array.numberValue = 0;
    array.desiredNumberValue = 0;
    array.maximumSizeValue = 0;
}

void tribe_clear_managed_array(ManagedArray<int>& array) {
    if (array.value != nullptr) {
        ::operator delete(array.value);
        array.value = nullptr;
    }
    array.numberValue = 0;
    array.desiredNumberValue = 0;
    array.maximumSizeValue = 0;
}

int tribe_managed_array_contains(const ManagedArray<int>& array, int value) {
    for (int i = 0; i < array.numberValue; ++i) {
        if ((i < array.maximumSizeValue) && (array.value != nullptr) && (array.value[i] == value)) {
            return 1;
        }
    }
    return 0;
}

int tribe_managed_array_ensure_capacity(ManagedArray<int>& array, int required_capacity) {
    if (required_capacity <= array.maximumSizeValue) {
        return 1;
    }

    int* new_values = static_cast<int*>(::operator new(static_cast<size_t>(required_capacity) * sizeof(int), std::nothrow));
    if (new_values == nullptr) {
        return 0;
    }

    int copy_count = array.maximumSizeValue;
    if (copy_count > required_capacity) {
        copy_count = required_capacity;
    }
    for (int i = 0; i < copy_count; ++i) {
        new_values[i] = array.value[i];
    }

    if (array.value != nullptr) {
        ::operator delete(array.value);
    }

    array.value = new_values;
    array.maximumSizeValue = required_capacity;
    return 1;
}

int tribe_managed_array_append_unique(ManagedArray<int>& array, int value) {
    if (tribe_managed_array_contains(array, value) != 0) {
        return 1;
    }

    if (tribe_managed_array_ensure_capacity(array, array.numberValue + 1) == 0) {
        return 0;
    }

    array.value[array.numberValue] = value;
    array.numberValue = array.numberValue + 1;
    return 1;
}

int tribe_managed_array_append(ManagedArray<int>& array, int value) {
    if (tribe_managed_array_ensure_capacity(array, array.numberValue + 1) == 0) {
        return 0;
    }
    array.value[array.numberValue] = value;
    array.numberValue = array.numberValue + 1;
    return 1;
}

void tribe_influence_map_destroy(InfluenceMap& map) {
    if (map.valueValue != nullptr) {
        ::operator delete(map.valueValue);
        map.valueValue = nullptr;
    }
    if (map.rowValue != nullptr) {
        ::operator delete(map.rowValue);
        map.rowValue = nullptr;
    }
    map.xSizeValue = 0;
    map.ySizeValue = 0;
    map.xReferencePointValue = 0;
    map.yReferencePointValue = 0;
    map.coverageCountValue = 0;
    map.connectionCountValue = 0;
    map.unchangeableLimitValue = 0xFF;
}

int tribe_influence_map_init(InfluenceMap& map, int x_size, int y_size, uchar fill) {
    tribe_influence_map_destroy(map);

    map.xSizeValue = x_size;
    map.ySizeValue = y_size;
    map.xReferencePointValue = 0;
    map.yReferencePointValue = 0;
    map.coverageCountValue = 0;
    map.connectionCountValue = 0;
    map.unchangeableLimitValue = 0xFF;

    if ((x_size <= 0) || (y_size <= 0)) {
        return 1;
    }

    size_t total_size = static_cast<size_t>(x_size) * static_cast<size_t>(y_size);
    map.valueValue = static_cast<uchar*>(::operator new(total_size, std::nothrow));
    if (map.valueValue == nullptr) {
        map.xSizeValue = 0;
        map.ySizeValue = 0;
        return 0;
    }
    std::memset(map.valueValue, fill, total_size);

    map.rowValue = static_cast<uchar**>(::operator new(static_cast<size_t>(y_size) * sizeof(uchar*), std::nothrow));
    if (map.rowValue == nullptr) {
        ::operator delete(map.valueValue);
        map.valueValue = nullptr;
        map.xSizeValue = 0;
        map.ySizeValue = 0;
        return 0;
    }

    for (int row = 0; row < y_size; ++row) {
        map.rowValue[row] = map.valueValue + static_cast<size_t>(row) * static_cast<size_t>(x_size);
    }

    return 1;
}

int tribe_influence_map_lookup(const InfluenceMap& map, int x, int y) {
    int local_x = x - map.xReferencePointValue;
    int local_y = y - map.yReferencePointValue;
    if ((local_x < 0) || (local_y < 0) || (local_x >= map.xSizeValue) || (local_y >= map.ySizeValue) || (map.rowValue == nullptr)) {
        return 0xFF;
    }
    return static_cast<int>(map.rowValue[local_y][local_x]);
}

int tribe_influence_map_set(InfluenceMap& map, int x, int y, uchar value) {
    int local_x = x - map.xReferencePointValue;
    int local_y = y - map.yReferencePointValue;
    if ((local_x < 0) || (local_y < 0) || (local_x >= map.xSizeValue) || (local_y >= map.ySizeValue) || (map.rowValue == nullptr)) {
        return 0;
    }
    map.rowValue[local_y][local_x] = value;
    return 1;
}

void tribe_influence_map_save(const InfluenceMap& map, int handle) {
    rge_write(handle, (void*)&map.xSizeValue, 4);
    rge_write(handle, (void*)&map.ySizeValue, 4);
    rge_write(handle, (void*)&map.xReferencePointValue, 4);
    rge_write(handle, (void*)&map.yReferencePointValue, 4);
    rge_write(handle, (void*)&map.unchangeableLimitValue, 1);

    for (int row = 0; row < map.ySizeValue; ++row) {
        for (int col = 0; col < map.xSizeValue; ++col) {
            rge_write(handle, (void*)&map.rowValue[row][col], 1);
        }
    }
}

void tribe_influence_map_load(InfluenceMap& map, int handle) {
    int x_size = 0;
    int y_size = 0;
    int x_ref = 0;
    int y_ref = 0;
    uchar unchangeable_limit = 0xFF;

    rge_read(handle, &x_size, 4);
    rge_read(handle, &y_size, 4);
    rge_read(handle, &x_ref, 4);
    rge_read(handle, &y_ref, 4);
    rge_read(handle, &unchangeable_limit, 1);

    tribe_influence_map_init(map, x_size, y_size, 0xFF);
    map.xReferencePointValue = x_ref;
    map.yReferencePointValue = y_ref;
    map.unchangeableLimitValue = unchangeable_limit;

    for (int row = 0; row < map.ySizeValue; ++row) {
        for (int col = 0; col < map.xSizeValue; ++col) {
            rge_read(handle, &map.rowValue[row][col], 1);
        }
    }
}

void tribe_initialize_common_state(TribeInformationAIModule* self) {
    tribe_reset_managed_array(self->farmsTaskedThisUpdate);
    self->md = nullptr;
    self->mapXSizeValue = -1;
    self->mapYSizeValue = -1;
    self->lastUpdateRowValue = 0;
    self->maxImportantObjectMemory = kDefaultImportantMemory;
    self->importantObjectMemory = nullptr;
    tribe_reset_managed_array(self->importantObjects);
    tribe_reset_managed_array(self->importantUnits);
    tribe_reset_managed_array(self->importantMiscs);
    tribe_reset_managed_array(self->itemsToDefend);

    self->pathMap.valueValue = nullptr;
    self->pathMap.rowValue = nullptr;
    self->pathMap.xSizeValue = 0;
    self->pathMap.ySizeValue = 0;
    self->pathMap.xReferencePointValue = 0;
    self->pathMap.yReferencePointValue = 0;
    self->pathMap.coverageCountValue = 0;
    self->pathMap.connectionCountValue = 0;
    self->pathMap.unchangeableLimitValue = 0xFF;
    tribe_influence_map_init(self->pathMap, kPathMapSize, kPathMapSize, 0xFF);

    tribe_reset_managed_array(self->playerObjects);
    tribe_reset_managed_array(self->playerBuildings);

    self->lastWallPosition.x = -1;
    self->lastWallPosition.y = -1;
    self->lastWallPosition2.x = -1;
    self->lastWallPosition2.y = -1;
    self->numberGatesValue = -1;
    for (int i = 0; i < kQuadrantCount; ++i) {
        self->minGatePosition[i].x = -1;
        self->minGatePosition[i].y = -1;
        self->maxGatePosition[i].x = -1;
        self->maxGatePosition[i].y = -1;
    }

    self->maxBuildingLots = kDefaultBuildingLots;
    self->buildingLots = nullptr;
    self->maxAttackMemories = kDefaultAttackMemories;
    self->attackMemories = nullptr;
    self->saveLearnInformationValue = 0;
    self->learnFileName[0] = '\0';
    self->numberFoundForestTilesValue = 0;

    std::strncpy(self->unitHistoryFilename, kDefaultUnitHistoryFilename, sizeof(self->unitHistoryFilename) - 1);
    self->unitHistoryFilename[sizeof(self->unitHistoryFilename) - 1] = '\0';

    std::memset(self->fullyExploredZoneValue, 0, sizeof(self->fullyExploredZoneValue));
    std::memset(self->quadrantLog, 0, sizeof(self->quadrantLog));

    if (self->resourceTypesValue == nullptr) {
        self->resourceTypesValue = static_cast<int**>(::operator new(sizeof(int*) * kResourceTypeSlots, std::nothrow));
    }
    if (self->numberResourceTypesValue == nullptr) {
        self->numberResourceTypesValue = static_cast<int*>(::operator new(sizeof(int) * kResourceTypeSlots, std::nothrow));
    }
    if (self->resourceTypesValue != nullptr) {
        for (int i = 0; i < kResourceTypeSlots; ++i) {
            self->resourceTypesValue[i] = nullptr;
        }
    }
    if (self->numberResourceTypesValue != nullptr) {
        for (int i = 0; i < kResourceTypeSlots; ++i) {
            self->numberResourceTypesValue[i] = 0;
        }
    }

    for (int i = 0; i < kResourceTypeSlots; ++i) {
        self->resources[i] = nullptr;
        self->numResources[i] = 0;
        self->maxResources[i] = 0;
        self->closestDropsiteValue[i] = -1;
        self->closestDropsiteResourceID[i] = -1;
        self->dropsitesByAge[i][0] = 0;
        self->dropsitesByAge[i][1] = 1;
        self->dropsitesByAge[i][2] = 1;
        self->dropsitesByAge[i][3] = 1;
    }

    std::memset(self->playHistory, 0, sizeof(self->playHistory));
    std::memset(self->unitHistory, 0, sizeof(self->unitHistory));
}

void tribe_initialize_default_object_memory(TribeInformationAIModule* self) {
    self->importantObjectMemory = static_cast<ObjectMemory*>(::operator new(static_cast<size_t>(self->maxImportantObjectMemory) * sizeof(ObjectMemory), std::nothrow));
    if (self->importantObjectMemory == nullptr) {
        return;
    }

    for (int i = 0; i < self->maxImportantObjectMemory; ++i) {
        ObjectMemory& memory = self->importantObjectMemory[i];
        memory.id = -1;
        memory.type = -1;
        memory.group = -1;
        memory.x = 0;
        memory.y = 0;
        memory.z = 0;
        memory.owner = 0;
        memory.hitPoints = 0;
        memory.attackAttempts = 0;
        memory.kills = 0;
        memory.damageCapability = 0.0f;
        memory.rateOfFire = 0.0f;
        memory.range = 0.0f;
    }
}

void tribe_initialize_default_building_lots(TribeInformationAIModule* self) {
    self->buildingLots = static_cast<BuildingLot*>(::operator new(static_cast<size_t>(self->maxBuildingLots) * sizeof(BuildingLot), std::nothrow));
    if (self->buildingLots == nullptr) {
        return;
    }

    for (int i = 0; i < self->maxBuildingLots; ++i) {
        self->buildingLots[i].typeID = -1;
        self->buildingLots[i].x = 0;
        self->buildingLots[i].y = 0;
        self->buildingLots[i].status = 0;
    }
}

void tribe_initialize_default_attack_memory(TribeInformationAIModule* self) {
    self->attackMemories = static_cast<AttackMemory*>(::operator new(static_cast<size_t>(self->maxAttackMemories) * sizeof(AttackMemory), std::nothrow));
    if (self->attackMemories == nullptr) {
        return;
    }

    for (int i = 0; i < self->maxAttackMemories; ++i) {
        AttackMemory& memory = self->attackMemories[i];
        memory.id = -1;
        memory.type = static_cast<uchar>(-1);
        memory.minX = 0;
        memory.minY = 0;
        memory.maxX = 0;
        memory.maxY = 0;
        memory.attackingOwner = 0xFF;
        memory.targetOwner = 0xFF;
        memory.kills = 0;
        memory.success = 0;
        memory.timeStamp = 0;
        memory.play = -1;
    }
}

RGE_Static_Object* tribe_information_object_by_id(TribeInformationAIModule* self, int object_id) {
    if ((self == nullptr) || (self->md == nullptr) || (self->md->player == nullptr) || (self->md->player->world == nullptr)) {
        return nullptr;
    }
    return self->md->player->world->object(object_id);
}

int tribe_object_current_zone(RGE_Static_Object* object) {
    if (object == nullptr) {
        return -1;
    }
    return static_cast<int>(object->lookupZone(static_cast<int>(object->world_x), static_cast<int>(object->world_y)));
}

void tribe_add_resource_type(TribeInformationAIModule* self, int resource_index, int resource_type) {
    if ((resource_index < 0) || (resource_index >= kResourceTypeSlots) || (self->resourceTypesValue == nullptr) || (self->numberResourceTypesValue == nullptr)) {
        return;
    }

    int count = self->numberResourceTypesValue[resource_index];
    int* values = self->resourceTypesValue[resource_index];
    for (int i = 0; i < count; ++i) {
        if (values[i] == resource_type) {
            return;
        }
    }

    int* resized = static_cast<int*>(::operator new(static_cast<size_t>(count + 1) * sizeof(int), std::nothrow));
    if (resized == nullptr) {
        return;
    }
    for (int i = 0; i < count; ++i) {
        resized[i] = values[i];
    }
    resized[count] = resource_type;

    if (values != nullptr) {
        ::operator delete(values);
    }
    self->resourceTypesValue[resource_index] = resized;
    self->numberResourceTypesValue[resource_index] = count + 1;
}

void tribe_load_id_list(ManagedArray<int>& array, int file_handle) {
    int count = 0;
    rge_read(file_handle, &count, 4);
    for (int i = 0; i < count; ++i) {
        int value = -1;
        rge_read(file_handle, &value, 4);
        tribe_managed_array_append_unique(array, value);
    }
}

void tribe_save_id_list(ManagedArray<int>& array, int file_handle) {
    int count = array.numberValue;
    rge_write(file_handle, &count, 4);
    for (int i = 0; i < array.numberValue; ++i) {
        if (i >= array.maximumSizeValue) {
            break;
        }
        int value = array.value[i];
        rge_write(file_handle, &value, 4);
    }
}
}

// Offset: 0x0044E080
// Fully verified. Source of truth: infmap.cpp.decomp @ 0x0044E080
InfluenceMap::~InfluenceMap() {
    tribe_influence_map_destroy(*this);
}

// Offset: 0x004D6BB0
// TODO: Part 2 - constructor exception-edge parity and stack unwinding audit against ASM.
TribeInformationAIModule::TribeInformationAIModule(void* param_1, int param_2)
    : InformationAIModule(param_1, param_2) {
    this->resourceTypesValue = nullptr;
    this->numberResourceTypesValue = nullptr;
    tribe_initialize_common_state(this);
    tribe_initialize_default_object_memory(this);
    tribe_initialize_default_building_lots(this);
    tribe_initialize_default_attack_memory(this);
}

// Offset: 0x004D7070
// TODO: Part 2 - load-constructor parity for legacy save versions and defensive failure paths.
TribeInformationAIModule::TribeInformationAIModule(int param_1, int param_2)
    : InformationAIModule(nullptr, param_1) {
    this->resourceTypesValue = nullptr;
    this->numberResourceTypesValue = nullptr;
    tribe_initialize_common_state(this);

    for (int i = 0; i < kResourceTypeSlots; ++i) {
        int num_to_load = 0;
        rge_read(param_2, &num_to_load, 4);
        for (int j = 0; j < num_to_load; ++j) {
            int value = 0;
            rge_read(param_2, &value, 4);
            tribe_add_resource_type(this, i, value);
        }
    }

    rge_read(param_2, &this->mapXSizeValue, 4);
    rge_read(param_2, &this->mapYSizeValue, 4);
    rge_read(param_2, &this->lastUpdateRowValue, 4);
    rge_read(param_2, &this->maxImportantObjectMemory, 4);

    if (this->importantObjectMemory != nullptr) {
        ::operator delete(this->importantObjectMemory);
        this->importantObjectMemory = nullptr;
    }
    this->importantObjectMemory = static_cast<ObjectMemory*>(::operator new(static_cast<size_t>(this->maxImportantObjectMemory) * sizeof(ObjectMemory), std::nothrow));
    if (this->importantObjectMemory != nullptr) {
        for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
            rge_read(param_2, &this->importantObjectMemory[i], sizeof(ObjectMemory));
        }
    }

    rge_read(param_2, &this->maxBuildingLots, 4);
    if (this->buildingLots != nullptr) {
        ::operator delete(this->buildingLots);
        this->buildingLots = nullptr;
    }
    this->buildingLots = static_cast<BuildingLot*>(::operator new(static_cast<size_t>(this->maxBuildingLots) * sizeof(BuildingLot), std::nothrow));
    if (this->buildingLots != nullptr) {
        for (int i = 0; i < this->maxBuildingLots; ++i) {
            rge_read(param_2, &this->buildingLots[i], sizeof(BuildingLot));
        }
    }

    rge_read(param_2, &this->maxAttackMemories, 4);
    if (this->attackMemories != nullptr) {
        ::operator delete(this->attackMemories);
        this->attackMemories = nullptr;
    }
    this->attackMemories = static_cast<AttackMemory*>(::operator new(static_cast<size_t>(this->maxAttackMemories) * sizeof(AttackMemory), std::nothrow));
    if (this->attackMemories != nullptr) {
        for (int i = 0; i < this->maxAttackMemories; ++i) {
            rge_read(param_2, &this->attackMemories[i], sizeof(AttackMemory));
        }
    }

    tribe_load_id_list(this->importantObjects, param_2);
    tribe_load_id_list(this->importantUnits, param_2);
    tribe_load_id_list(this->importantMiscs, param_2);
    tribe_load_id_list(this->itemsToDefend, param_2);
    tribe_load_id_list(this->playerBuildings, param_2);
    tribe_load_id_list(this->playerObjects, param_2);

    tribe_influence_map_load(this->pathMap, param_2);
    rge_read(param_2, &this->lastWallPosition, 8);
    rge_read(param_2, &this->lastWallPosition2, 8);

    int number_gates_bytes = (save_game_version < 1.6f) ? 8 : 4;
    rge_read(param_2, &this->numberGatesValue, number_gates_bytes);
    for (int i = 0; i < kQuadrantCount; ++i) {
        rge_read(param_2, &this->minGatePosition[i], 8);
        rge_read(param_2, &this->maxGatePosition[i], 8);
    }

    rge_read(param_2, &this->saveLearnInformationValue, 4);
    if (save_game_version < 1.6f) {
        this->learnFileName[0] = '\0';
    } else {
        int filename_size = 0;
        rge_read(param_2, &filename_size, 4);
        if (filename_size < 0) {
            filename_size = 0;
        }
        if (filename_size >= static_cast<int>(sizeof(this->learnFileName))) {
            filename_size = static_cast<int>(sizeof(this->learnFileName) - 1);
        }
        if (filename_size > 0) {
            rge_read(param_2, this->learnFileName, filename_size);
        }
        this->learnFileName[filename_size] = '\0';
    }

    rge_read(param_2, this->fullyExploredZoneValue, 0xFF);
    if (save_game_version < 2.5f) {
        std::memset(this->quadrantLog, 0, sizeof(this->quadrantLog));
    } else {
        rge_read(param_2, this->quadrantLog, sizeof(this->quadrantLog));
    }

    rge_read(param_2, this->maxResources, sizeof(this->maxResources));
    rge_read(param_2, this->numResources, sizeof(this->numResources));
    for (int i = 0; i < kResourceTypeSlots; ++i) {
        if (this->resources[i] != nullptr) {
            ::operator delete(this->resources[i]);
            this->resources[i] = nullptr;
        }
        if (this->maxResources[i] > 0) {
            this->resources[i] = static_cast<ResourceMemory*>(::operator new(static_cast<size_t>(this->maxResources[i]) * sizeof(ResourceMemory), std::nothrow));
            if (this->resources[i] != nullptr) {
                rge_read(param_2, this->resources[i], this->maxResources[i] * static_cast<int>(sizeof(ResourceMemory)));
            }
        }
    }

    if (save_game_version >= 6.8f) {
        rge_read(param_2, this->dropsitesByAge, sizeof(this->dropsitesByAge));
        rge_read(param_2, this->closestDropsiteValue, sizeof(this->closestDropsiteValue));
        rge_read(param_2, this->closestDropsiteResourceID, sizeof(this->closestDropsiteResourceID));
    }
    if (save_game_version >= 6.91f) {
        rge_read(param_2, &this->numberFoundForestTilesValue, 4);
    }
    if (save_game_version >= 6.99f) {
        rge_read(param_2, this->playHistory, sizeof(this->playHistory));
    }
}

// Offset: 0x004D7CB0
// TODO: Part 2 - learned-info persistence parity and write-order audit against ASM.
TribeInformationAIModule::~TribeInformationAIModule() {
    for (int i = 0; i < kResourceTypeSlots; ++i) {
        if ((this->resourceTypesValue != nullptr) && (this->resourceTypesValue[i] != nullptr)) {
            ::operator delete(this->resourceTypesValue[i]);
            this->resourceTypesValue[i] = nullptr;
        }
    }
    if (this->resourceTypesValue != nullptr) {
        ::operator delete(this->resourceTypesValue);
        this->resourceTypesValue = nullptr;
    }
    if (this->numberResourceTypesValue != nullptr) {
        ::operator delete(this->numberResourceTypesValue);
        this->numberResourceTypesValue = nullptr;
    }

    if (this->importantObjectMemory != nullptr) {
        ::operator delete(this->importantObjectMemory);
        this->importantObjectMemory = nullptr;
    }
    if (this->buildingLots != nullptr) {
        ::operator delete(this->buildingLots);
        this->buildingLots = nullptr;
    }
    if (this->attackMemories != nullptr) {
        ::operator delete(this->attackMemories);
        this->attackMemories = nullptr;
    }

    for (int i = 0; i < kResourceTypeSlots; ++i) {
        if (this->resources[i] != nullptr) {
            ::operator delete(this->resources[i]);
            this->resources[i] = nullptr;
        }
    }

    tribe_clear_managed_array(this->playerBuildings);
    tribe_clear_managed_array(this->playerObjects);
    tribe_clear_managed_array(this->itemsToDefend);
    tribe_clear_managed_array(this->importantMiscs);
    tribe_clear_managed_array(this->importantUnits);
    tribe_clear_managed_array(this->importantObjects);
    tribe_clear_managed_array(this->farmsTaskedThisUpdate);
}

int TribeInformationAIModule::loggingHistory() {
    return InformationAIModule::loggingHistory();
}

void TribeInformationAIModule::setLogHistory(int param_1) {
    InformationAIModule::setLogHistory(param_1);
}

void TribeInformationAIModule::toggleLogHistory() {
    InformationAIModule::toggleLogHistory();
}

void TribeInformationAIModule::setHistoryFilename(char* param_1) {
    InformationAIModule::setHistoryFilename(param_1);
}

int TribeInformationAIModule::loggingCommonHistory() {
    return InformationAIModule::loggingCommonHistory();
}

void TribeInformationAIModule::setLogCommonHistory(int param_1) {
    InformationAIModule::setLogCommonHistory(param_1);
}

void TribeInformationAIModule::toggleLogCommonHistory() {
    InformationAIModule::toggleLogCommonHistory();
}

int TribeInformationAIModule::loadState(char* param_1) {
    return InformationAIModule::loadState(param_1);
}

int TribeInformationAIModule::saveState(char* param_1) {
    return InformationAIModule::saveState(param_1);
}

int TribeInformationAIModule::gleanState(int param_1) {
    return InformationAIModule::gleanState(param_1);
}

int TribeInformationAIModule::processMessage(AIModuleMessage* param_1) {
    return InformationAIModule::processMessage(param_1);
}

// Offset: 0x004D8270
// TODO: Part 2 - initialize parity for missing legacy codepaths.
int TribeInformationAIModule::initialize() {
    if ((this->md != nullptr) && (this->md->player != nullptr) && (this->md->player->world != nullptr) && (this->md->player->world->map != nullptr)) {
        this->mapXSizeValue = this->md->player->world->map->map_width;
        this->mapYSizeValue = this->md->player->world->map->map_height;
    }

    if ((rge_base_game != nullptr) && (rge_base_game->player_game_info != nullptr)) {
        char* player_name = rge_base_game->player_game_info->get_current_player_name();
        if (player_name != nullptr) {
            ::sprintf(this->unitHistoryFilename, kUnitHistoryFilenameFormat, player_name);
            return 1;
        }
    }

    std::strncpy(this->unitHistoryFilename, kDefaultUnitHistoryFilename, sizeof(this->unitHistoryFilename) - 1);
    this->unitHistoryFilename[sizeof(this->unitHistoryFilename) - 1] = '\0';
    return 1;
}

// Offset: 0x004D8300
// TODO: Part 2 - update parity depends on full addImportantObject/resource tracking transliteration.
int TribeInformationAIModule::update(int param_1) {
    (void)param_1;

    if ((this->md == nullptr) || (this->md->player == nullptr) || (this->md->player->world == nullptr) || (this->md->player->visible == nullptr)) {
        return 1;
    }

    RGE_Tile_List_Node* tile_list = nullptr;
    int tile_list_size = 0;
    this->md->player->tile_list.get_list_info(&tile_list, &tile_list_size);

    int new_count = this->md->player->tile_list.get_new_count();
    int start_index = tile_list_size - new_count;
    if ((new_count > 0) && (start_index < tile_list_size) && (tile_list != nullptr)) {
        RGE_Map* map = this->md->player->world->map;
        RGE_Visible_Map* visible_map = this->md->player->visible;
        if ((map == nullptr) || (map->map_row_offset == nullptr)) {
            return 1;
        }

        for (int index = start_index; index < tile_list_size; ++index) {
            int col = tile_list[index].col;
            int row = tile_list[index].row;
            if ((row < 0) || (col < 0) || (row >= map->map_height) || (col >= map->map_width)) {
                continue;
            }

            uchar visible_status = visible_map->get_visible(col, row);
            RGE_Tile* tile = &map->map_row_offset[row][col];
            int tile_type = tile->terrain_type & 0x1F;

            if ((this->mapXSizeValue > 0) && (this->mapYSizeValue > 0)) {
                int qx = (col * 4) / this->mapXSizeValue;
                int qy = (row * 4) / this->mapYSizeValue;
                if (qx < 0) {
                    qx = 0;
                } else if (qx >= 4) {
                    qx = 3;
                }
                if (qy < 0) {
                    qy = 0;
                } else if (qy >= 4) {
                    qy = 3;
                }
                this->quadrantLog[qx][qy].numberExploredTiles = this->quadrantLog[qx][qy].numberExploredTiles + 1;
            }

            tribe_influence_map_set(this->pathMap, col, row, 0);

            int forest_objects_on_tile = 0;
            RGE_Object_Node* object_node = tile->objects.list;
            while (object_node != nullptr) {
                RGE_Static_Object* object = object_node->node;
                if ((object != nullptr) && (object->master_obj != nullptr)) {
                    if ((visible_status != 0x80) || (object->master_obj->fog_flag != 0)) {
                        int group = static_cast<int>(object->master_obj->object_group);
                        if (this->importantObject(group) == 1) {
                            this->addImportantObject(object, 0);
                        }
                        if (group == 0x0F) {
                            forest_objects_on_tile = forest_objects_on_tile + 1;
                        }
                    }
                }
                object_node = object_node->next;
            }

            if ((forest_objects_on_tile > 0) && ((tile_type == 10) || (tile_type == 0x13) || (tile_type == 0x0D) || (tile_type == 0x14))) {
                this->numberFoundForestTilesValue = this->numberFoundForestTilesValue + 1;
            }
        }
    }

    return 1;
}

void TribeInformationAIModule::setCallbackMessage(AIModuleMessage* param_1) {
    InformationAIModule::setCallbackMessage(param_1);
}

int TribeInformationAIModule::filterOutMessage(AIModuleMessage* param_1) {
    return InformationAIModule::filterOutMessage(param_1);
}

// Offset: 0x004D84D0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D84D0
void TribeInformationAIModule::setMainDecisionAI(TribeMainDecisionAIModule* param_1) {
    this->md = param_1;
}

// Offset: 0x004D84E0
// TODO: Part 2 - save parity for resize edge cases and exact write order checks.
int TribeInformationAIModule::save(int param_1) {
    for (int i = 0; i < kResourceTypeSlots; ++i) {
        int count = (this->numberResourceTypesValue != nullptr) ? this->numberResourceTypesValue[i] : 0;
        rge_write(param_1, &count, 4);
        for (int j = 0; j < count; ++j) {
            int value = this->resourceTypesValue[i][j];
            rge_write(param_1, &value, 4);
        }
    }

    rge_write(param_1, &this->mapXSizeValue, 4);
    rge_write(param_1, &this->mapYSizeValue, 4);
    rge_write(param_1, &this->lastUpdateRowValue, 4);
    rge_write(param_1, &this->maxImportantObjectMemory, 4);
    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        rge_write(param_1, &this->importantObjectMemory[i], sizeof(ObjectMemory));
    }

    rge_write(param_1, &this->maxBuildingLots, 4);
    for (int i = 0; i < this->maxBuildingLots; ++i) {
        rge_write(param_1, &this->buildingLots[i], sizeof(BuildingLot));
    }

    rge_write(param_1, &this->maxAttackMemories, 4);
    for (int i = 0; i < this->maxAttackMemories; ++i) {
        rge_write(param_1, &this->attackMemories[i], sizeof(AttackMemory));
    }

    tribe_save_id_list(this->importantObjects, param_1);
    tribe_save_id_list(this->importantUnits, param_1);
    tribe_save_id_list(this->importantMiscs, param_1);
    tribe_save_id_list(this->itemsToDefend, param_1);
    tribe_save_id_list(this->playerBuildings, param_1);
    tribe_save_id_list(this->playerObjects, param_1);

    tribe_influence_map_save(this->pathMap, param_1);
    rge_write(param_1, &this->lastWallPosition, 8);
    rge_write(param_1, &this->lastWallPosition2, 8);
    rge_write(param_1, &this->numberGatesValue, 4);
    for (int i = 0; i < kQuadrantCount; ++i) {
        rge_write(param_1, &this->minGatePosition[i], 8);
        rge_write(param_1, &this->maxGatePosition[i], 8);
    }

    rge_write(param_1, &this->saveLearnInformationValue, 4);
    int learn_name_length = static_cast<int>(std::strlen(this->learnFileName));
    rge_write(param_1, &learn_name_length, 4);
    if (learn_name_length > 0) {
        rge_write(param_1, this->learnFileName, learn_name_length);
    }

    rge_write(param_1, this->fullyExploredZoneValue, 0xFF);
    rge_write(param_1, this->quadrantLog, sizeof(this->quadrantLog));
    rge_write(param_1, this->maxResources, sizeof(this->maxResources));
    rge_write(param_1, this->numResources, sizeof(this->numResources));
    for (int i = 0; i < kResourceTypeSlots; ++i) {
        if ((this->maxResources[i] > 0) && (this->resources[i] != nullptr)) {
            rge_write(param_1, this->resources[i], this->maxResources[i] * static_cast<int>(sizeof(ResourceMemory)));
        }
    }
    rge_write(param_1, this->dropsitesByAge, sizeof(this->dropsitesByAge));
    rge_write(param_1, this->closestDropsiteValue, sizeof(this->closestDropsiteValue));
    rge_write(param_1, this->closestDropsiteResourceID, sizeof(this->closestDropsiteResourceID));
    rge_write(param_1, &this->numberFoundForestTilesValue, 4);
    rge_write(param_1, this->playHistory, sizeof(this->playHistory));
    return 1;
}

// Offset: 0x004D8C80
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D8C80
void TribeInformationAIModule::blotExploredMap(int param_1, int param_2, int param_3, int param_4) {
    XYPoint min;
    XYPoint max;

    min.y = param_1;
    min.x = param_4;
    this->mapBound(min);

    max.y = param_3;
    max.x = param_2;
    this->mapBound(max);

    for (int y = min.y; y <= max.y; ++y) {
        for (int x = max.x; x <= min.x; ++x) {
            int map_value = tribe_influence_map_lookup(this->pathMap, y, x);
            if (map_value != 1) {
                tribe_influence_map_set(this->pathMap, y, x, 2);
            }
        }
    }
}

// Offset: 0x004D8D20
// TODO: Part 2 - closestUnexploredTile full parity requires pathing and zone heuristics audit.
int TribeInformationAIModule::closestUnexploredTile(int param_1, float param_2, float param_3, float* param_4, float* param_5) {
    if ((param_4 == nullptr) || (param_5 == nullptr)) {
        return 0;
    }

    RGE_Static_Object* object = tribe_information_object_by_id(this, param_1);
    if (object == nullptr) {
        return 0;
    }
    RGE_Visible_Map* visible_map = (this->md != nullptr && this->md->player != nullptr) ? this->md->player->visible : nullptr;
    int zone = tribe_object_current_zone(object);
    if (zone < 0) {
        return 0;
    }

    int center_x = static_cast<int>(param_2);
    int center_y = static_cast<int>(param_3);
    int max_radius = this->mapXSize();
    if (this->mapYSize() > max_radius) {
        max_radius = this->mapYSize();
    }

    for (int radius = 1; radius < max_radius; ++radius) {
        for (int dy = -radius; dy <= radius; ++dy) {
            for (int dx = -radius; dx <= radius; ++dx) {
                if ((dx != -radius) && (dx != radius) && (dy != -radius) && (dy != radius)) {
                    continue;
                }

                int x = center_x + dx;
                int y = center_y + dy;
                if ((x < 0) || (y < 0) || (x >= this->mapXSize()) || (y >= this->mapYSize())) {
                    continue;
                }

                int path_value = tribe_influence_map_lookup(this->pathMap, x, y);
                if ((path_value != 0xFF) && (path_value != 2)) {
                    continue;
                }
                if ((visible_map != nullptr) && (visible_map->get_visible(x, y) == 0x0F)) {
                    continue;
                }
                if (object->lookupZone(x, y) != static_cast<uchar>(zone)) {
                    continue;
                }

                tribe_influence_map_set(this->pathMap, x, y, 1);
                *param_4 = static_cast<float>(x);
                *param_5 = static_cast<float>(y);
                return 1;
            }
        }
    }

    this->setFullyExploredZone(param_1, 1);
    return 0;
}

// Offset: 0x004D9110
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D9110
int TribeInformationAIModule::fullyExploredZone(int param_1) {
    RGE_Static_Object* object = tribe_information_object_by_id(this, param_1);
    if (object != nullptr) {
        int zone = tribe_object_current_zone(object);
        if ((zone >= 0) && (zone < static_cast<int>(sizeof(this->fullyExploredZoneValue))) && (this->fullyExploredZoneValue[zone] == 0)) {
            return 1;
        }
    }
    return 0;
}

// Offset: 0x004D9160
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D9160
void TribeInformationAIModule::setFullyExploredZone(int param_1, int param_2) {
    RGE_Static_Object* object = tribe_information_object_by_id(this, param_1);
    if (object != nullptr) {
        int zone = tribe_object_current_zone(object);
        if ((zone >= 0) && (zone < static_cast<int>(sizeof(this->fullyExploredZoneValue)))) {
            this->fullyExploredZoneValue[zone] = static_cast<uchar>(param_2);
        }
    }
}

// Offset: 0x004D91A0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D91A0
int TribeInformationAIModule::tileUncovered(int param_1, int param_2) {
    if ((param_1 >= 0) && (param_2 >= 0) && (param_1 < this->mapXSizeValue) && (param_2 < this->mapYSizeValue)) {
        if (tribe_influence_map_lookup(this->pathMap, param_1, param_2) != 0xFF) {
            return 1;
        }
    }
    return 0;
}

// Offset: 0x004D91F0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D91F0
void TribeInformationAIModule::setTileExplored(int param_1, int param_2) {
    if ((param_1 >= 0) && (param_2 >= 0) && (param_1 < this->mapXSizeValue) && (param_2 < this->mapYSizeValue)) {
        tribe_influence_map_set(this->pathMap, param_1, param_2, 0);
    }
}

// Offset: 0x004DA190
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DA190
int TribeInformationAIModule::mapXSize() {
    if ((this->mapXSizeValue == -1) && (this->md != nullptr) && (this->md->player != nullptr) && (this->md->player->world != nullptr) &&
        (this->md->player->world->map != nullptr)) {
        this->mapXSizeValue = this->md->player->world->map->map_width;
    }
    return this->mapXSizeValue;
}

// Offset: 0x004DA1C0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DA1C0
int TribeInformationAIModule::mapYSize() {
    if ((this->mapYSizeValue == -1) && (this->md != nullptr) && (this->md->player != nullptr) && (this->md->player->world != nullptr) &&
        (this->md->player->world->map != nullptr)) {
        this->mapYSizeValue = this->md->player->world->map->map_height;
    }
    return this->mapYSizeValue;
}

// Offset: 0x004DFCE0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DFCE0
int TribeInformationAIModule::mapBound(XYPoint& param_1) {
    int bounded = 0;
    if (param_1.x < 0) {
        param_1.x = 0;
        bounded = 1;
    } else if (param_1.x >= this->mapXSizeValue) {
        param_1.x = this->mapXSizeValue - 1;
        bounded = 1;
    }

    if (param_1.y < 0) {
        param_1.y = 0;
        return 1;
    }
    if (param_1.y >= this->mapYSizeValue) {
        param_1.y = this->mapYSizeValue - 1;
        bounded = 1;
    }
    return bounded;
}

// Offset: 0x004DABB0
// TODO: Part 2 - addImportantObject full parity depends on tactical/resource/object-memory integration.
int TribeInformationAIModule::addImportantObject(RGE_Static_Object* param_1, int param_2) {
    (void)param_2;
    if ((param_1 == nullptr) || (param_1->master_obj == nullptr) || (param_1->id < 0)) {
        return 0;
    }

    int object_group = static_cast<int>(param_1->master_obj->object_group);
    if (this->importantObject(object_group) == 0) {
        return 0;
    }

    tribe_managed_array_append_unique(this->importantObjects, static_cast<int>(param_1->id));

    if (this->importantUnit(object_group) == 1) {
        tribe_managed_array_append_unique(this->importantUnits, static_cast<int>(param_1->id));
    } else if (this->importantMisc(object_group) == 1) {
        tribe_managed_array_append_unique(this->importantMiscs, static_cast<int>(param_1->id));
    } else if (this->importantResource(object_group) == 1) {
        // TODO: Part 2 - resource memory tracking.
    }

    return 1;
}

// Offset: 0x004DAF80
// TODO: Part 2 - addImportantObject(int) parity depends on MainDecisionAIModule::object coverage.
int TribeInformationAIModule::addImportantObject(int param_1) {
    RGE_Static_Object* object = tribe_information_object_by_id(this, param_1);
    return this->addImportantObject(object, 0);
}

// Offset: 0x004DAFB0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DAFB0
int TribeInformationAIModule::importantObject(int param_1) {
    if (this->importantUnit(param_1) == 0) {
        if (this->importantResource(param_1) == 0) {
            if (this->importantMisc(param_1) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Offset: 0x004DAFF0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DAFF0
int TribeInformationAIModule::importantUnit(int param_1) {
    if (((((((param_1 != 0) && (param_1 != 3)) && (param_1 != 4)) &&
           ((param_1 != 0x18 && (param_1 != 0x15)) &&
            (param_1 != 6 && (param_1 != 0x19 && (param_1 != 0x11))))) &&
          (param_1 != 0x1A && ((param_1 != 0x0C && (param_1 != 0x23)) && (param_1 != 0x17)))) &&
         ((param_1 != 0x24 && (param_1 != 0x1C)) &&
          (param_1 != 0x12 && ((param_1 != 0x0D && (param_1 != 2)) && (param_1 != 0x14))))) &&
        ((param_1 != 0x1B && (param_1 != 0x16)) && (param_1 != 0x27))) {
        return 0;
    }
    return 1;
}

// Offset: 0x004DB070
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DB070
int TribeInformationAIModule::importantResource(int param_1) {
    if ((((param_1 != 0x1F) && (param_1 != 5)) && (param_1 != 0x21)) &&
        ((param_1 != 7 && (param_1 != 9)) && ((param_1 != 8 && (param_1 != 0x20)) && (param_1 != 0x0F)))) {
        return 0;
    }
    return 1;
}

// Offset: 0x004DB0B0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DB0B0
int TribeInformationAIModule::importantMisc(int param_1) {
    if ((param_1 != 1) && (param_1 != 0x1E)) {
        return 0;
    }
    return 1;
}
