#include "../include/TribeInformationAIModule.h"

#include "../include/TribeMainDecisionAIModule.h"
#include "../include/TRIBE_Player.h"
#include "../include/AIPlayBook.h"
#include "../include/PathingSystem.h"
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
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <cstring>
#include <cstdio>
#include <cmath>
#include <new>

static InfluenceMap iMap;
static InfluenceMap losMap;
static InfluenceMap attackMap;

// Source of truth: taiinfmd.cpp.decomp @ 0x004D6AD0
static void E9() {
    iMap = InfluenceMap(0xFE, 0xFE, 0);
}

// Source of truth: taiinfmd.cpp.decomp @ 0x004D6B20
static void E14() {
    losMap = InfluenceMap(0x32, 0x32, 0);
}

// Source of truth: taiinfmd.cpp.decomp @ 0x004D6B70
static void E19() {
    attackMap = InfluenceMap(0x32, 0x32, 0);
}

// Source of truth: taiinfmd.cpp.decomp @ 0x004D90F1
static void FUN_004d90f1() {
    // TODO: STUB - decomp/asm indicates switch jump table thunk.
}

// Source of truth: taiinfmd.cpp.decomp @ 0x004DA16D
static void FUN_004da16d() {
    // TODO: STUB - decomp/asm indicates switch jump table thunk.
}

// Source of truth: taiinfmd.cpp.decomp @ 0x004E0165
static void FUN_004e0165() {
    // TODO: STUB - decomp/asm indicates switch jump table thunk.
}

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

RGE_Player* tribe_information_player(TribeInformationAIModule* self) {
    if ((self == nullptr) || (self->md == nullptr)) {
        return nullptr;
    }
    return self->md->player;
}

RGE_Game_World* tribe_information_world(TribeInformationAIModule* self) {
    RGE_Player* player = tribe_information_player(self);
    if (player == nullptr) {
        return nullptr;
    }
    return player->world;
}

int tribe_resource_slot_from_group(short object_group) {
    if (object_group == 0x0F) {
        return 1;
    }
    if (object_group == 8) {
        return 2;
    }
    if (object_group == 0x20) {
        return 3;
    }
    return 0;
}

void tribe_update_closest_dropsite_for_resource(TribeInformationAIModule* self, RGE_Static_Object* resource_obj, float distance) {
    if ((self == nullptr) || (resource_obj == nullptr) || (resource_obj->master_obj == nullptr)) {
        return;
    }

    int slot = tribe_resource_slot_from_group(resource_obj->master_obj->object_group);
    int new_distance = static_cast<int>(distance);
    if ((self->closestDropsiteValue[slot] == -1) || (new_distance < self->closestDropsiteValue[slot])) {
        self->closestDropsiteValue[slot] = new_distance;
        self->closestDropsiteResourceID[slot] = static_cast<int>(resource_obj->id);
    }
}

int tribe_distance_squared(int x1, int y1, int x2, int y2) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    return dx * dx + dy * dy;
}

int tribe_convert_unit_to_history_index(RGE_Static_Object* object) {
    if ((object == nullptr) || (object->owner == nullptr) || (object->owner->world == nullptr) || (object->owner->world->playbook == nullptr)) {
        return -1;
    }
    return object->owner->world->playbook->convertUnitToIntType(object);
}

int tribe_single_player_game() {
    if (rge_base_game == nullptr) {
        return 0;
    }
    return rge_base_game->singlePlayerGame();
}
}

// Offset: 0x0044E080
// Fully verified. Source of truth: infmap.cpp.decomp @ 0x0044E080
InfluenceMap::~InfluenceMap() {
    tribe_influence_map_destroy(*this);
}

// Offset: 0x004D6BB0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D6BB0
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
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D7070
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
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D7CB0
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

    if ((this->saveLearnInformationValue == 1) && (this->learnFileName[0] != '\0')) {
        int learn_file = rge_open(this->learnFileName, 0x8301, 0x180);
        if (learn_file != -1) {
            rge_write(learn_file, &this->mapXSizeValue, 4);
            rge_write(learn_file, &this->mapYSizeValue, 4);

            int saved_attack_memories = 0;
            if (this->attackMemories != nullptr) {
                for (int i = 0; i < this->maxAttackMemories; ++i) {
                    if (this->attackMemories[i].id != -1) {
                        saved_attack_memories = saved_attack_memories + 1;
                    }
                }
            }
            rge_write(learn_file, &saved_attack_memories, 4);
            if (this->attackMemories != nullptr) {
                for (int i = 0; i < this->maxAttackMemories; ++i) {
                    if (this->attackMemories[i].id != -1) {
                        rge_write(learn_file, &this->attackMemories[i], sizeof(AttackMemory));
                    }
                }
            }

            int saved_object_memories = 0;
            if (this->importantObjectMemory != nullptr) {
                for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
                    if ((this->importantObjectMemory[i].id != -1) && (this->importantObjectMemory[i].type == 0x6D)) {
                        saved_object_memories = saved_object_memories + 1;
                    }
                }
            }
            rge_write(learn_file, &saved_object_memories, 4);
            if (this->importantObjectMemory != nullptr) {
                for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
                    if ((this->importantObjectMemory[i].id != -1) && (this->importantObjectMemory[i].type == 0x6D)) {
                        rge_write(learn_file, &this->importantObjectMemory[i], sizeof(ObjectMemory));
                    }
                }
            }

            rge_write(learn_file, this->maxResources, sizeof(this->maxResources));
            rge_write(learn_file, this->numResources, sizeof(this->numResources));
            for (int i = 0; i < kResourceTypeSlots; ++i) {
                if ((this->maxResources[i] > 0) && (this->resources[i] != nullptr)) {
                    rge_write(learn_file, this->resources[i], this->maxResources[i] * static_cast<int>(sizeof(ResourceMemory)));
                }
            }

            tribe_save_id_list(this->importantMiscs, learn_file);
            tribe_save_id_list(this->itemsToDefend, learn_file);
            rge_close(learn_file);
        }
    }

    int unit_history_file = rge_open(this->unitHistoryFilename, 0x8301, 0x180);
    if (unit_history_file != -1) {
        rge_write(unit_history_file, this->unitHistory, sizeof(this->unitHistory));
        rge_close(unit_history_file);
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
    tribe_influence_map_destroy(this->pathMap);
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
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D8270
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
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D8300
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
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D84E0
int TribeInformationAIModule::save(int param_1) {
    for (int i = 0; i < kResourceTypeSlots; ++i) {
        int count = (this->numberResourceTypesValue != nullptr) ? this->numberResourceTypesValue[i] : 0;
        rge_write(param_1, &count, 4);
        for (int j = 0; j < count; ++j) {
            int value = ((this->resourceTypesValue != nullptr) && (this->resourceTypesValue[i] != nullptr)) ? this->resourceTypesValue[i][j] : 0;
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
    for (int i = 0; i < kResourceTypeSlots; ++i) {
        if ((this->maxResources[i] != 0) && (this->resources[i] == nullptr)) {
            this->maxResources[i] = 0;
        }
    }
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
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D8D20
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

    int x = static_cast<int>(param_2);
    int y = static_cast<int>(param_3);
    int direction = debug_rand("C:\\msdev\\work\\age1_x1\\taiinfmd.c", 0x397) & 3;
    int is_boat = (object->master_obj != nullptr) && (object->master_obj->object_group == 4);
    int off_top = 0;
    int off_right = 0;
    int off_bottom = 0;
    int off_left = 0;

    for (int step_size = 1;; ++step_size) {
        if ((off_top != 0) && (off_right != 0) && (off_bottom != 0) && (off_left != 0)) {
            this->setFullyExploredZone(param_1, 1);
            return 0;
        }

        for (int pass = 0; pass < 2; ++pass) {
            for (int i = 0; i < step_size; ++i) {
                switch (direction) {
                    case 0:
                        x = x + 1;
                        break;
                    case 1:
                        y = y + 1;
                        break;
                    case 2:
                        x = x - 1;
                        break;
                    default:
                        y = y - 1;
                        break;
                }

                if (x < 0) {
                    off_top = 1;
                    continue;
                }
                if (x >= this->mapXSizeValue) {
                    off_right = 1;
                    continue;
                }
                if (y < 0) {
                    off_bottom = 1;
                    continue;
                }
                if (y >= this->mapYSizeValue) {
                    off_left = 1;
                    continue;
                }

                int path_value = tribe_influence_map_lookup(this->pathMap, x, y);
                if (is_boat != 0) {
                    if (path_value != 0xFF) {
                        continue;
                    }
                } else {
                    if ((path_value != 0xFF) && (path_value != 2)) {
                        continue;
                    }
                }
                if ((visible_map != nullptr) && (visible_map->get_visible(x, y) == 0x0F)) {
                    continue;
                }
                if (object->passableTile(static_cast<float>(x), static_cast<float>(y), 1) == 0) {
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
            direction = (direction + 1) & 3;
        }
    }
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

// Offset: 0x004D9230
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D9230
int TribeInformationAIModule::ownerOfGameID(int param_1) {
    (void)param_1;
    return -1;
}

// Offset: 0x004D9240
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D9240
int TribeInformationAIModule::gameIDOfResourceObject(int param_1, int param_2, float* param_3, float* param_4, int* param_5, int* param_6, int param_7) {
    if (param_5 == nullptr) {
        return -1;
    }
    *param_5 = -1;

    RGE_Static_Object* gatherer_obj = tribe_information_object_by_id(this, param_2);
    if ((gatherer_obj == nullptr) || (gatherer_obj->master_obj == nullptr) || (param_1 < 0) || (param_1 >= kResourceTypeSlots)) {
        return -1;
    }

    int gatherer_zone = tribe_object_current_zone(gatherer_obj);
    int gatherer_x = static_cast<int>(gatherer_obj->world_x);
    int gatherer_y = static_cast<int>(gatherer_obj->world_y);
    int fishing_boat = (gatherer_obj->master_obj->object_group == 4) ? 1 : 0;
    int best_score = 0;
    ResourceMemory* best_object = nullptr;
    int update_dropsites = 0;

    if ((this->resources[param_1] == nullptr) || (this->numResources[param_1] <= 0)) {
        return -1;
    }

    for (int i = 0; i < this->numResources[param_1]; ++i) {
        ResourceMemory& memory = this->resources[param_1][i];
        if (memory.gone == 1) {
            continue;
        }
        if (memory.valid != 0) {
            if (memory.gone == 0) {
                memory.valid = static_cast<uchar>(memory.valid - 1);
            }
            continue;
        }

        int excluded = 0;
        for (int j = 0; j < param_7; ++j) {
            if ((param_6 != nullptr) && (param_6[j] == memory.id)) {
                excluded = 1;
                break;
            }
        }
        if (excluded != 0) {
            continue;
        }

        RGE_Static_Object* resource_object = tribe_information_object_by_id(this, memory.id);
        if (resource_object == nullptr) {
            memory.gone = 1;
            if (this->closestDropsiteResourceID[param_1] == memory.id) {
                update_dropsites = 1;
            }
            continue;
        }

        short group = resource_object->master_obj->object_group;
        if ((fishing_boat == 1) && (group != 5) && (group != 0x1F) && (group != 0x21)) {
            continue;
        }
        if ((fishing_boat == 0) && ((group == 5) || (group == 0x1F) || (group == 0x21))) {
            continue;
        }

        int score = tribe_distance_squared(gatherer_x, gatherer_y, static_cast<int>(memory.x), static_cast<int>(memory.y)) +
                    (memory.gatherValue * 10);
        if (resource_object->master_obj->id == 0x3B) {
            if (memory.dropDistance > 0x14) {
                continue;
            }
            score = score + (memory.gatherAttempts / 0x96);
        } else {
            score = score + (memory.gatherAttempts / 0x32);
        }

        if ((best_object == nullptr) || (score < best_score)) {
            int resource_zone = static_cast<int>(gatherer_obj->lookupZone(static_cast<int>(memory.x), static_cast<int>(memory.y)));
            if (resource_zone == gatherer_zone) {
                best_object = &memory;
                best_score = score;
                if (param_3 != nullptr) {
                    *param_3 = resource_object->world_x;
                }
                if (param_4 != nullptr) {
                    *param_4 = resource_object->world_y;
                }
            }
        }
    }

    if (update_dropsites != 0) {
        this->updateResourceDropsites(param_1);
    }
    if (best_object == nullptr) {
        return -1;
    }

    best_object->gatherAttempts = static_cast<uchar>(best_object->gatherAttempts + 1);
    *param_5 = best_object->dropsiteID;
    return best_object->id;
}

// Offset: 0x004D96B0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D96B0
int TribeInformationAIModule::gameIDsOfObjectType(int param_1, int** param_2, int** param_3, int param_4) {
    if ((param_2 == nullptr) || (param_3 == nullptr)) {
        return 0;
    }
    *param_2 = nullptr;
    *param_3 = nullptr;

    int capacity = 10;
    int count = 0;
    for (int i = 0; i < this->importantObjects.numberValue; ++i) {
        if (i >= this->importantObjects.maximumSizeValue) {
            break;
        }

        int object_id = this->importantObjects.value[i];
        RGE_Static_Object* object = tribe_information_object_by_id(this, object_id);
        if ((object == nullptr) || (object->owner == nullptr) || (object->master_obj == nullptr)) {
            continue;
        }

        int owner_id = object->owner->id;
        if ((param_4 == -5) && (this->md != nullptr) && (this->md->player != nullptr) && (owner_id == this->md->player->id)) {
            continue;
        }
        if ((param_4 == -6) && (this->md != nullptr) && (this->md->player != nullptr) && (this->md->player->isEnemy(owner_id) != 0)) {
            continue;
        }
        if ((param_4 >= 0) && (owner_id != param_4)) {
            continue;
        }
        if ((param_1 != -1) && (object->master_obj->id != param_1)) {
            continue;
        }

        if ((*param_2 == nullptr) || (count >= capacity)) {
            int new_capacity = capacity * 2;
            int* new_ids = static_cast<int*>(::operator new(static_cast<size_t>(new_capacity) * sizeof(int), std::nothrow));
            int* new_owners = static_cast<int*>(::operator new(static_cast<size_t>(new_capacity) * sizeof(int), std::nothrow));
            if ((new_ids == nullptr) || (new_owners == nullptr)) {
                if (new_ids != nullptr) {
                    ::operator delete(new_ids);
                }
                if (new_owners != nullptr) {
                    ::operator delete(new_owners);
                }
                break;
            }
            for (int j = 0; j < count; ++j) {
                new_ids[j] = (*param_2 != nullptr) ? (*param_2)[j] : 0;
                new_owners[j] = (*param_3 != nullptr) ? (*param_3)[j] : 0;
            }
            if (*param_2 != nullptr) {
                ::operator delete(*param_2);
            }
            if (*param_3 != nullptr) {
                ::operator delete(*param_3);
            }
            *param_2 = new_ids;
            *param_3 = new_owners;
            capacity = new_capacity;
        }

        (*param_2)[count] = object_id;
        (*param_3)[count] = owner_id;
        count = count + 1;
    }
    return count;
}

// Offset: 0x004D9970
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D9970
int TribeInformationAIModule::gameIDsOwnedBy(int param_1, int** param_2, int param_3) {
    if (param_2 == nullptr) {
        return 0;
    }
    *param_2 = nullptr;

    int capacity = 10;
    int count = 0;
    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        if (this->importantObjectMemory[i].id == -1) {
            continue;
        }
        if ((param_1 != -1) && (this->importantObjectMemory[i].type != param_1)) {
            continue;
        }

        RGE_Static_Object* object = tribe_information_object_by_id(this, this->importantObjectMemory[i].id);
        if ((object == nullptr) || (object->owner == nullptr) || (object->owner->id != param_3)) {
            continue;
        }

        if ((*param_2 == nullptr) || (count >= capacity)) {
            int new_capacity = capacity * 2;
            int* new_ids = static_cast<int*>(::operator new(static_cast<size_t>(new_capacity) * sizeof(int), std::nothrow));
            if (new_ids == nullptr) {
                break;
            }
            for (int j = 0; j < count; ++j) {
                new_ids[j] = (*param_2 != nullptr) ? (*param_2)[j] : 0;
            }
            if (*param_2 != nullptr) {
                ::operator delete(*param_2);
            }
            *param_2 = new_ids;
            capacity = new_capacity;
        }

        (*param_2)[count] = this->importantObjectMemory[i].id;
        count = count + 1;
    }
    return count;
}

// Offset: 0x004D9A90
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D9A90
int TribeInformationAIModule::numberGameIDsOwnedBy(int param_1, int param_2) {
    int count = 0;
    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        if (this->importantObjectMemory[i].id == -1) {
            continue;
        }
        if ((param_1 != -1) && (this->importantObjectMemory[i].type != param_1)) {
            continue;
        }
        RGE_Static_Object* object = tribe_information_object_by_id(this, this->importantObjectMemory[i].id);
        if ((object != nullptr) && (object->owner != nullptr) && (object->owner->id == param_2)) {
            count = count + 1;
        }
    }
    return count;
}

// Offset: 0x004DA0E0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DA0E0
int TribeInformationAIModule::hasAdjacentTileType(int param_1, int param_2, int param_3) {
    RGE_Game_World* world = tribe_information_world(this);
    if ((world == nullptr) || (world->map == nullptr) || (world->map->map_row_offset == nullptr)) {
        return 0;
    }

    static const int kOffsets[8][2] = {
        {-1, 0}, {-1, -1}, {0, -1}, {1, -1},
        {1, 0},  {1, 1},   {0, 1},  {-1, 1}
    };

    for (int i = 0; i < 8; ++i) {
        int x = param_1 + kOffsets[i][0];
        int y = param_2 + kOffsets[i][1];
        if ((x < 0) || (y < 0) || (x >= world->map->map_width) || (y >= world->map->map_height)) {
            continue;
        }
        int terrain = world->map->map_row_offset[y][x].terrain_type & 0x1F;
        if (terrain == param_3) {
            return 1;
        }
    }
    return 0;
}

// Offset: 0x004DA1F0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DA1F0
void TribeInformationAIModule::addEnemyInfluences(int param_1, int param_2) {
    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        ObjectMemory& memory = this->importantObjectMemory[i];
        if ((memory.id == -1) || (memory.owner != static_cast<uchar>(param_1)) || (memory.id == param_2)) {
            continue;
        }

        RGE_Static_Object* object = tribe_information_object_by_id(this, memory.id);
        if ((object == nullptr) || (object->master_obj == nullptr)) {
            continue;
        }

        XYPoint min_los;
        XYPoint max_los;
        min_los.x = static_cast<int>(object->world_x - object->master_obj->los);
        min_los.y = static_cast<int>(object->world_y - object->master_obj->los);
        max_los.x = static_cast<int>(object->world_x + object->master_obj->los);
        max_los.y = static_cast<int>(object->world_y + object->master_obj->los);
        this->mapBound(min_los);
        this->mapBound(max_los);

        for (int x = min_los.x; x <= max_los.x; ++x) {
            for (int y = min_los.y; y <= max_los.y; ++y) {
                int influence = static_cast<int>(aiPathSystem.lookupMisc(x, y)) + 10;
                if (influence > 0xFF) {
                    influence = 0xFF;
                }
                aiPathSystem.setMisc(x, y, static_cast<uchar>(influence));
            }
        }

        if (memory.range > 1.0f) {
            XYPoint min_range;
            XYPoint max_range;
            min_range.x = static_cast<int>(object->world_x - memory.range);
            min_range.y = static_cast<int>(object->world_y - memory.range);
            max_range.x = static_cast<int>(object->world_x + memory.range);
            max_range.y = static_cast<int>(object->world_y + memory.range);
            this->mapBound(min_range);
            this->mapBound(max_range);

            for (int x = min_range.x; x <= max_range.x; ++x) {
                for (int y = min_range.y; y <= max_range.y; ++y) {
                    int influence = static_cast<int>(aiPathSystem.lookupMisc(x, y)) + 10;
                    if (influence > 0xFF) {
                        influence = 0xFF;
                    }
                    aiPathSystem.setMisc(x, y, static_cast<uchar>(influence));
                }
            }
        }
    }
}

// Offset: 0x004DA420
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DA420
void TribeInformationAIModule::addPriorAttackInfluences(int param_1, int param_2) {
    (void)param_2;
    if ((this->md == nullptr) || (this->md->player == nullptr)) {
        return;
    }

    for (int i = 0; i < this->maxAttackMemories; ++i) {
        AttackMemory& memory = this->attackMemories[i];
        if ((memory.id == -1) || (memory.targetOwner != static_cast<uchar>(param_1)) || (memory.attackingOwner != static_cast<uchar>(this->md->player->id))) {
            continue;
        }

        XYPoint min;
        XYPoint max;
        min.x = memory.minX;
        min.y = memory.minY;
        max.x = memory.maxX;
        max.y = memory.maxY;
        this->mapBound(min);
        this->mapBound(max);

        for (int x = min.x; x <= max.x; ++x) {
            for (int y = min.y; y <= max.y; ++y) {
                aiPathSystem.setMisc(x, y, 0x4B);
            }
        }

        min.x = min.x - 5;
        min.y = min.y - 5;
        max.x = max.x + 5;
        max.y = max.y + 5;
        this->mapBound(min);
        this->mapBound(max);

        for (int x = min.x; x <= max.x; ++x) {
            for (int y = min.y; y <= max.y; ++y) {
                aiPathSystem.setMisc(x, y, 0x0F);
            }
        }
    }
}

// Offset: 0x004DA5A0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DA5A0
ObjectMemory* TribeInformationAIModule::objectMemory(int param_1) {
    if (param_1 == -1) {
        return nullptr;
    }
    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        if (this->importantObjectMemory[i].id == param_1) {
            return &this->importantObjectMemory[i];
        }
    }
    return nullptr;
}

// Offset: 0x004DA5F0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DA5F0
ObjectMemory* TribeInformationAIModule::addObjectMemory(RGE_Static_Object* param_1) {
    if ((param_1 == nullptr) || (param_1->master_obj == nullptr) || (param_1->owner == nullptr)) {
        return nullptr;
    }

    return this->addObjectMemory(
        static_cast<int>(param_1->id),
        param_1->master_obj->id,
        param_1->master_obj->object_group,
        static_cast<uchar>(param_1->world_x),
        static_cast<uchar>(param_1->world_y),
        static_cast<uchar>(param_1->world_z),
        static_cast<uchar>(param_1->owner->id),
        static_cast<short>(param_1->hp),
        0,
        0,
        param_1->damageCapability(),
        param_1->rateOfFire(),
        param_1->weaponRange(),
        param_1);
}

// Offset: 0x004DA680
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DA680
ObjectMemory* TribeInformationAIModule::addObjectMemory(int param_1, short param_2, short param_3, uchar param_4, uchar param_5, uchar param_6,
                                                        uchar param_7, short param_8, int param_9, uchar param_10, float param_11, float param_12,
                                                        float param_13, RGE_Static_Object* param_14) {
    int free_index = -1;
    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        if (this->importantObjectMemory[i].id == param_1) {
            free_index = i;
            break;
        }
        if ((this->importantObjectMemory[i].id == -1) && (free_index == -1)) {
            free_index = i;
        }
    }

    if ((param_14 != nullptr) && (this->md != nullptr) && (this->md->player != nullptr) && (this->md->player->strategicNumber(0xC9) == 1) &&
        (param_14->owner != nullptr) && (param_14->owner->id > 0) && (param_14->owner->computerPlayer() == 0) && (tribe_single_player_game() == 1)) {
        int history_index = tribe_convert_unit_to_history_index(param_14);
        if ((history_index >= 0) && (history_index < kUnitHistorySize)) {
            this->unitHistory[history_index] = this->unitHistory[history_index] + 1;
        }
    }

    if (free_index == -1) {
        int old_capacity = this->maxImportantObjectMemory;
        int new_capacity = (old_capacity > 0) ? (old_capacity * 2) : 1;
        ObjectMemory* resized = static_cast<ObjectMemory*>(::operator new(static_cast<size_t>(new_capacity) * sizeof(ObjectMemory), std::nothrow));
        if (resized == nullptr) {
            return nullptr;
        }

        for (int i = 0; i < old_capacity; ++i) {
            resized[i] = this->importantObjectMemory[i];
        }
        for (int i = old_capacity; i < new_capacity; ++i) {
            resized[i].id = -1;
            resized[i].type = -1;
            resized[i].group = -1;
            resized[i].x = 0;
            resized[i].y = 0;
            resized[i].z = 0;
            resized[i].owner = 0;
            resized[i].hitPoints = 0;
            resized[i].attackAttempts = 0;
            resized[i].kills = 0;
            resized[i].damageCapability = 0.0f;
            resized[i].rateOfFire = 0.0f;
            resized[i].range = 0.0f;
        }

        if (this->importantObjectMemory != nullptr) {
            ::operator delete(this->importantObjectMemory);
        }
        this->importantObjectMemory = resized;
        this->maxImportantObjectMemory = new_capacity;
        free_index = old_capacity;
    }

    ObjectMemory& entry = this->importantObjectMemory[free_index];
    entry.id = param_1;
    entry.type = param_2;
    entry.group = param_3;
    entry.x = param_4;
    entry.y = param_5;
    entry.z = param_6;
    entry.owner = param_7;
    entry.hitPoints = param_8;
    entry.attackAttempts = param_9;
    entry.kills = param_10;
    entry.damageCapability = param_11;
    entry.rateOfFire = param_12;
    entry.range = param_13;
    return &entry;
}

// Offset: 0x004DABB0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DABB0
int TribeInformationAIModule::addImportantObject(RGE_Static_Object* param_1, int param_2) {
    if ((param_1 == nullptr) || (param_1->master_obj == nullptr) || (param_1->id < 0)) {
        return 0;
    }

    int object_group = static_cast<int>(param_1->master_obj->object_group);
    if (this->importantObject(object_group) == 0) {
        return 0;
    }

    RGE_Game_World* world = tribe_information_world(this);
    if ((param_2 == 0) && (this->md != nullptr) && (this->md->player != nullptr) && (world != nullptr) &&
        (param_1->owner != nullptr) && (param_1->owner->id > 0) && (this->md->player->isEnemy(static_cast<int>(param_1->owner->id)) != 0) &&
        (world->player_num > 3) && (this->md->player->strategicNumber(0xC2) == 1)) {
        for (int i = 1; i < world->player_num; ++i) {
            if (i == this->md->player->id) {
                continue;
            }
            RGE_Player* other_player = world->players[i];
            if ((other_player == nullptr) || (other_player->computerPlayer() == 0)) {
                continue;
            }
            if ((this->md->player->isEnemy(i) == 0) || (other_player->isEnemy(this->md->player->id) == 0)) {
                continue;
            }
            TRIBE_Player* tribe_player = static_cast<TRIBE_Player*>(other_player);
            if (tribe_player->playerAI != nullptr) {
                TribeInformationAIModule* allied_info =
                    reinterpret_cast<TribeInformationAIModule*>(tribe_player->playerAI->informationAI);
                allied_info->addImportantObject(param_1, 1);
            }
        }
    }

    tribe_managed_array_append_unique(this->importantObjects, static_cast<int>(param_1->id));

    if (this->importantUnit(object_group) == 1) {
        tribe_managed_array_append_unique(this->importantUnits, static_cast<int>(param_1->id));
        this->addObjectMemory(param_1);
    } else if (this->importantResource(object_group) == 1) {
        this->addResourceObject(param_1);
    } else if (this->importantMisc(object_group) == 1) {
        tribe_managed_array_append_unique(this->importantMiscs, static_cast<int>(param_1->id));
    }

    return 1;
}

// Offset: 0x004DAF80
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DAF80
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

// Offset: 0x004E1260
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E1260
void TribeInformationAIModule::loadLearnInfo(char* param_1) {
    if (this->md == nullptr || this->md->player == nullptr) {
        return;
    }

    if (param_1 == nullptr) {
        ::sprintf(this->learnFileName, "learn_default_%d", static_cast<int>(this->md->player->id));
    } else {
        char* player_name = nullptr;
        if ((rge_base_game != nullptr) && (rge_base_game->player_game_info != nullptr)) {
            player_name = rge_base_game->player_game_info->get_current_player_name();
        }
        if (player_name == nullptr) {
            player_name = const_cast<char*>("");
        }
        ::sprintf(this->learnFileName, "learn_%s_%s_%d", param_1, player_name, static_cast<int>(this->md->player->id));
    }

    int learn_file = rge_open(this->learnFileName, 0x8000);
    if (learn_file == -1) {
        return;
    }

    rge_read(learn_file, &this->mapXSizeValue, 4);
    rge_read(learn_file, &this->mapYSizeValue, 4);

    int attack_count = 0;
    rge_read(learn_file, &attack_count, 4);
    for (int i = 0; i < attack_count; ++i) {
        AttackMemory temp_attack{};
        rge_read(learn_file, &temp_attack, sizeof(AttackMemory));
        int slot = -1;
        for (int j = 0; j < this->maxAttackMemories; ++j) {
            if (this->attackMemories[j].id == -1) {
                slot = j;
                break;
            }
        }
        if (slot != -1) {
            this->attackMemories[slot] = temp_attack;
        }
    }

    int memory_count = 0;
    rge_read(learn_file, &memory_count, 4);
    for (int i = 0; i < memory_count; ++i) {
        ObjectMemory temp_memory{};
        rge_read(learn_file, &temp_memory, sizeof(ObjectMemory));
        this->addObjectMemory(temp_memory.id, temp_memory.type, temp_memory.group, temp_memory.x, temp_memory.y, temp_memory.z,
                              temp_memory.owner, temp_memory.hitPoints, temp_memory.attackAttempts, temp_memory.kills,
                              temp_memory.damageCapability, temp_memory.rateOfFire, temp_memory.range, nullptr);
        tribe_managed_array_append_unique(this->importantUnits, temp_memory.id);
    }

    rge_read(learn_file, this->maxResources, sizeof(this->maxResources));
    rge_read(learn_file, this->numResources, sizeof(this->numResources));
    for (int i = 0; i < kResourceTypeSlots; ++i) {
        if (this->resources[i] != nullptr) {
            ::operator delete(this->resources[i]);
            this->resources[i] = nullptr;
        }
        if (this->maxResources[i] > 0) {
            this->resources[i] = static_cast<ResourceMemory*>(::operator new(static_cast<size_t>(this->maxResources[i]) * sizeof(ResourceMemory), std::nothrow));
            if (this->resources[i] != nullptr) {
                rge_read(learn_file, this->resources[i], this->maxResources[i] * static_cast<int>(sizeof(ResourceMemory)));
            }
        }
    }

    tribe_load_id_list(this->importantMiscs, learn_file);
    tribe_load_id_list(this->itemsToDefend, learn_file);
    rge_close(learn_file);
}

// Offset: 0x004E1720
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E1720
void TribeInformationAIModule::setSaveLearnInformation(int param_1) {
    this->saveLearnInformationValue = param_1;
}

// Offset: 0x004E23A0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E23A0
void TribeInformationAIModule::addResourceType(int param_1, int param_2) {
    if ((this->resourceTypesValue == nullptr) || (this->numberResourceTypesValue == nullptr) || (param_1 < 0) || (param_1 >= kResourceTypeSlots)) {
        return;
    }

    int current_count = this->numberResourceTypesValue[param_1];
    int* resized = static_cast<int*>(::operator new(static_cast<size_t>(current_count + 1) * sizeof(int), std::nothrow));
    if (resized == nullptr) {
        return;
    }
    for (int i = 0; i < current_count; ++i) {
        resized[i] = this->resourceTypesValue[param_1][i];
    }
    resized[current_count] = param_2;

    if (this->resourceTypesValue[param_1] != nullptr) {
        ::operator delete(this->resourceTypesValue[param_1]);
    }
    this->resourceTypesValue[param_1] = resized;
    this->numberResourceTypesValue[param_1] = current_count + 1;
}

// Offset: 0x004E2440
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E2440
int TribeInformationAIModule::resourceType(int param_1, int param_2) {
    if ((this->numberResourceTypesValue == nullptr) || (this->resourceTypesValue == nullptr) || (param_1 < 0) || (param_1 >= kResourceTypeSlots)) {
        return 0;
    }
    for (int i = 0; i < this->numberResourceTypesValue[param_1]; ++i) {
        if (this->resourceTypesValue[param_1][i] == param_2) {
            return 1;
        }
    }
    return 0;
}

// Offset: 0x004E2490
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E2490
int TribeInformationAIModule::addResourceObject(RGE_Static_Object* param_1) {
    if ((param_1 == nullptr) || (param_1->master_obj == nullptr)) {
        return 0;
    }

    int resource_slot = tribe_resource_slot_from_group(param_1->master_obj->object_group);
    if ((this->numResources[resource_slot] == this->maxResources[resource_slot]) || (this->resources[resource_slot] == nullptr)) {
        int new_size = (this->maxResources[resource_slot] == 0) ? 100 : (this->maxResources[resource_slot] * 2);
        ResourceMemory* resized =
            static_cast<ResourceMemory*>(::operator new(static_cast<size_t>(new_size) * sizeof(ResourceMemory), std::nothrow));
        if (resized == nullptr) {
            return 0;
        }

        int copied = 0;
        if (this->resources[resource_slot] != nullptr) {
            for (; copied < this->maxResources[resource_slot]; ++copied) {
                resized[copied] = this->resources[resource_slot][copied];
            }
        }
        for (; copied < new_size; ++copied) {
            resized[copied].id = -1;
            resized[copied].x = 0;
            resized[copied].y = 0;
            resized[copied].gatherAttempts = 0;
            resized[copied].gatherValue = 0xFF;
            resized[copied].valid = 0;
            resized[copied].gone = 0;
            resized[copied].dropDistance = 0xFF;
            resized[copied].resourceType = 0xFF;
            resized[copied].dropsiteID = -1;
        }

        if (this->resources[resource_slot] != nullptr) {
            ::operator delete(this->resources[resource_slot]);
        }
        this->resources[resource_slot] = resized;
        this->maxResources[resource_slot] = new_size;
    }

    for (int i = 0; i < this->maxResources[resource_slot]; ++i) {
        if (this->resources[resource_slot][i].id != param_1->id) {
            continue;
        }

        int dropsite_id = -1;
        float distance = this->findClosestDropsite(param_1, 1, &dropsite_id);
        this->resources[resource_slot][i].gatherValue = static_cast<int>(distance);
        this->resources[resource_slot][i].dropDistance = static_cast<uchar>(distance);
        this->resources[resource_slot][i].dropsiteID = dropsite_id;
        tribe_update_closest_dropsite_for_resource(this, param_1, distance);
        return 1;
    }

    ResourceMemory& memory = this->resources[resource_slot][this->numResources[resource_slot]];
    memory.id = static_cast<int>(param_1->id);
    memory.x = static_cast<uchar>(param_1->world_x);
    memory.y = static_cast<uchar>(param_1->world_y);
    memory.gatherAttempts = 0;
    memory.valid = 0;
    memory.gone = 0;
    memory.resourceType = static_cast<uchar>(resource_slot);

    int dropsite_id = -1;
    float distance = this->findClosestDropsite(param_1, 1, &dropsite_id);
    memory.gatherValue = static_cast<int>(distance);
    memory.dropDistance = static_cast<uchar>(distance);
    memory.dropsiteID = dropsite_id;
    this->numResources[resource_slot] = this->numResources[resource_slot] + 1;

    tribe_update_closest_dropsite_for_resource(this, param_1, distance);
    return 1;
}

// Offset: 0x004E2A00
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E2A00
float TribeInformationAIModule::findClosestDropsite(RGE_Static_Object* param_1, int param_2, int* param_3) {
    if (param_3 != nullptr) {
        *param_3 = -1;
    }
    if ((param_1 == nullptr) || (param_1->master_obj == nullptr)) {
        return 1000.0f;
    }

    float best_distance = 1000.0f;
    int resource_zone = tribe_object_current_zone(param_1);

    for (int i = 0; i < this->playerBuildings.numberValue; ++i) {
        if (i >= this->playerBuildings.maximumSizeValue) {
            break;
        }
        RGE_Static_Object* building = tribe_information_object_by_id(this, this->playerBuildings.value[i]);
        if ((building == nullptr) || (building->master_obj == nullptr)) {
            continue;
        }

        int zone = static_cast<int>(param_1->lookupZone(static_cast<int>(building->world_x), static_cast<int>(building->world_y)));
        if (zone != resource_zone) {
            continue;
        }

        int building_id = building->master_obj->id;
        int resource_id = param_1->master_obj->id;
        int valid_dropsite = 0;
        if ((building_id == 0x6D) && (param_2 != 0)) {
            valid_dropsite = 1;
        } else if ((building_id == 0x67) && (resource_id != 0x3B) && (resource_id != 0x32)) {
            valid_dropsite = 1;
        } else if ((building_id == 0x44) && ((resource_id == 0x3B) || (resource_id == 0x32))) {
            valid_dropsite = 1;
        }
        if (valid_dropsite == 0) {
            continue;
        }

        float dx = building->world_x - param_1->world_x;
        float dy = building->world_y - param_1->world_y;
        float distance = std::sqrt(dx * dx + dy * dy);
        if ((best_distance == 1000.0f) || (distance < best_distance)) {
            best_distance = distance;
            if (param_3 != nullptr) {
                *param_3 = static_cast<int>(building->id);
            }
        }
    }

    return best_distance;
}

// Offset: 0x004E2BA0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E2BA0
RGE_Static_Object* TribeInformationAIModule::findClosestReturnDropsite(RGE_Static_Object* param_1) {
    if (param_1 == nullptr) {
        return nullptr;
    }

    RGE_Static_Object* result = nullptr;
    float best_distance = 1000.0f;
    int unit_zone = tribe_object_current_zone(param_1);

    for (int i = 0; i < this->playerBuildings.numberValue; ++i) {
        if (i >= this->playerBuildings.maximumSizeValue) {
            break;
        }
        RGE_Static_Object* building = tribe_information_object_by_id(this, this->playerBuildings.value[i]);
        if ((building == nullptr) || (building->master_obj == nullptr)) {
            continue;
        }

        int zone = static_cast<int>(param_1->lookupZone(static_cast<int>(building->world_x), static_cast<int>(building->world_y)));
        if (zone != unit_zone) {
            continue;
        }

        int building_id = building->master_obj->id;
        int valid_dropsite = 0;
        if (building_id == 0x6D) {
            valid_dropsite = 1;
        } else if ((building_id == 0x67) && (param_1->attribute_type_held != 0x10)) {
            valid_dropsite = 1;
        } else if ((building_id == 0x44) && (param_1->attribute_type_held == 0x10)) {
            valid_dropsite = 1;
        }
        if (valid_dropsite == 0) {
            continue;
        }

        float dx = building->world_x - param_1->world_x;
        float dy = building->world_y - param_1->world_y;
        float distance = std::sqrt(dx * dx + dy * dy);
        if ((result == nullptr) || (distance < best_distance)) {
            result = building;
            best_distance = distance;
        }
    }

    return result;
}

// Offset: 0x004E2D10
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E2D10
void TribeInformationAIModule::updateAllResourceDropsites() {
    for (int slot = 0; slot < kResourceTypeSlots; ++slot) {
        this->closestDropsiteValue[slot] = -1;
        this->closestDropsiteResourceID[slot] = -1;
        for (int i = 0; i < this->numResources[slot]; ++i) {
            RGE_Static_Object* resource_obj = tribe_information_object_by_id(this, this->resources[slot][i].id);
            if (resource_obj == nullptr) {
                continue;
            }
            int dropsite_id = -1;
            float distance = this->findClosestDropsite(resource_obj, 1, &dropsite_id);
            this->resources[slot][i].gatherValue = static_cast<int>(distance);
            this->resources[slot][i].dropDistance = static_cast<uchar>(distance);
            this->resources[slot][i].dropsiteID = dropsite_id;
            tribe_update_closest_dropsite_for_resource(this, resource_obj, distance);
        }
    }
}

// Offset: 0x004E2E90
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E2E90
void TribeInformationAIModule::updateResourceDropsites(int param_1) {
    if ((param_1 < 0) || (param_1 >= kResourceTypeSlots)) {
        return;
    }

    this->closestDropsiteValue[param_1] = -1;
    this->closestDropsiteResourceID[param_1] = -1;
    for (int i = 0; i < this->numResources[param_1]; ++i) {
        ResourceMemory& memory = this->resources[param_1][i];
        if (memory.gone == 1) {
            continue;
        }

        RGE_Static_Object* resource_obj = tribe_information_object_by_id(this, memory.id);
        if (resource_obj == nullptr) {
            continue;
        }

        int dropsite_id = -1;
        float distance = this->findClosestDropsite(resource_obj, 1, &dropsite_id);
        memory.gatherValue = static_cast<int>(distance);
        memory.dropDistance = static_cast<uchar>(distance);
        memory.dropsiteID = dropsite_id;
        tribe_update_closest_dropsite_for_resource(this, resource_obj, distance);
    }
}

// Offset: 0x004E3020
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E3020
int TribeInformationAIModule::setResourceObjectValid(int param_1, int param_2, int param_3) {
    if ((param_1 < 0) || (param_1 >= kResourceTypeSlots) || (this->resources[param_1] == nullptr)) {
        return 0;
    }
    for (int i = 0; i < this->numResources[param_1]; ++i) {
        if (this->resources[param_1][i].id == param_2) {
            this->resources[param_1][i].valid = static_cast<uchar>(param_3);
            return 1;
        }
    }
    return 0;
}

// Offset: 0x004E3070
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E3070
int TribeInformationAIModule::numberStoragePits() {
    int count = 0;
    for (int i = 0; i < this->playerBuildings.numberValue; ++i) {
        if (i >= this->playerBuildings.maximumSizeValue) {
            break;
        }
        RGE_Static_Object* building = tribe_information_object_by_id(this, this->playerBuildings.value[i]);
        if ((building != nullptr) && (building->master_obj != nullptr) && (building->master_obj->id == 0x67)) {
            count = count + 1;
        }
    }
    return count;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004D9B20
// Source of truth: taiinfmd.cpp.decomp @ 0x004D9B20

ConstructionItem* TribeInformationAIModule::placeDock(BuildItem*, float, float, int, int) {
    return nullptr;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004D9EC0
// Source of truth: taiinfmd.cpp.decomp @ 0x004D9EC0

int TribeInformationAIModule::numberDocksInZone(int, RGE_Zone_Map*) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004D9FC0
// Source of truth: taiinfmd.cpp.decomp @ 0x004D9FC0

int TribeInformationAIModule::closestDockDistance(int, int) {
    return -1;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DB0D0
// Source of truth: taiinfmd.cpp.decomp @ 0x004DB0D0

int TribeInformationAIModule::isBuilding(RGE_Static_Object* param_1) {
    if ((param_1 == nullptr) || (param_1->master_obj == nullptr)) {
        return 0;
    }
    short object_group = param_1->master_obj->object_group;
    return ((object_group == 3) || (object_group == 0x1B)) ? 1 : 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DB640
// Source of truth: taiinfmd.cpp.decomp @ 0x004DB100

int TribeInformationAIModule::isUnitBuilding(RGE_Static_Object* param_1) {
    if ((param_1 == nullptr) || (param_1->master_obj == nullptr)) {
        return 0;
    }
    if (param_1->master_obj->object_group != 3) {
        return 0;
    }
    short id = param_1->master_obj->id;
    if ((id != 0x6D) && (id != 0x0C) && (id != 0x57) && (id != 0x31) && (id != 0x2D) && (id != 0x00) && (id != 0x65) && (id != 0x68)) {
        return 0;
    }
    return 1;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DB660
// Source of truth: taiinfmd.cpp.decomp @ 0x004DB160

int TribeInformationAIModule::isBoat(RGE_Static_Object* param_1) {
    if ((param_1 == nullptr) || (param_1->master_obj == nullptr)) {
        return 0;
    }
    short object_group = param_1->master_obj->object_group;
    return ((object_group == 0x15) || (object_group == 2) || (object_group == 0x14) || (object_group == 0x16)) ? 1 : 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DB680
// Source of truth: taiinfmd.cpp.decomp @ 0x004DB190

int TribeInformationAIModule::isWall(RGE_Static_Object* param_1) {
    if ((param_1 == nullptr) || (param_1->master_obj == nullptr)) {
        return 0;
    }
    return (param_1->master_obj->object_group == 0x1B) ? 1 : 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DB6A0
// Source of truth: taiinfmd.cpp.decomp @ 0x004DB1B0

int TribeInformationAIModule::isTower(RGE_Static_Object* param_1) {
    if ((param_1 == nullptr) || (param_1->master_obj == nullptr)) {
        return 0;
    }
    short id = param_1->master_obj->id;
    return ((id == 0x4F) || (id == 199) || (id == 0x45) || (id == 0x17F) || (id == 0x17C)) ? 1 : 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DB6C0
// Source of truth: taiinfmd.cpp.decomp @ 0x004DB1F0

int TribeInformationAIModule::isBoatAccessible(RGE_Static_Object*, int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DB940
// Source of truth: taiinfmd.cpp.decomp @ 0x004DB240

int TribeInformationAIModule::isLandAccessible(RGE_Static_Object*, int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DBA20
// Source of truth: taiinfmd.cpp.decomp @ 0x004DB280

int TribeInformationAIModule::influenceCanPlaceStructure(BuildItem*) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DBA70
// Source of truth: taiinfmd.cpp.decomp @ 0x004DB290

ConstructionItem* TribeInformationAIModule::influencePlaceStructure(BuildItem*, int, int, float, char*, int, int, int, int, PlacementState*, ulong) {
    return nullptr;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DC6D0
// Source of truth: taiinfmd.cpp.decomp @ 0x004DC1B0

void TribeInformationAIModule::addObject(RGE_Static_Object* param_1) {
    this->addImportantObject(param_1, 0);
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DC8D0
// Source of truth: taiinfmd.cpp.decomp @ 0x004DC3A0

void TribeInformationAIModule::removeObject(int param_1) {
    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        if (this->importantObjectMemory[i].id == param_1) {
            this->importantObjectMemory[i].id = -1;
            break;
        }
    }
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DCAC0
// Source of truth: taiinfmd.cpp.decomp @ 0x004DC490

ObjectMemory* TribeInformationAIModule::objectToAttackWithPlay(int, int*, int, int*, int*, int*, int*) {
    return nullptr;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DCCF0
// Source of truth: taiinfmd.cpp.decomp @ 0x004DC750

ObjectMemory* TribeInformationAIModule::objectToAttack(int, int, int, int, int*) {
    return nullptr;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DD130
// Source of truth: taiinfmd.cpp.decomp @ 0x004DCF10

ObjectMemory* TribeInformationAIModule::objectToAttackByGroup(int, TacticalAIGroup*, AttackState*, ulong) {
    return nullptr;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DD620
// Source of truth: taiinfmd.cpp.decomp @ 0x004DDD40

ObjectMemory* TribeInformationAIModule::objectToAttackByGroup2(int, int*, int) {
    return nullptr;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DD890
// Source of truth: taiinfmd.cpp.decomp @ 0x004DE1F0

ObjectMemory* TribeInformationAIModule::objectToDefend(int) {
    return nullptr;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DD930
// Source of truth: taiinfmd.cpp.decomp @ 0x004DE330

ObjectMemory* TribeInformationAIModule::higherPriorityObjectToDefend(int, int, int) {
    return nullptr;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DDA20
// Source of truth: taiinfmd.cpp.decomp @ 0x004DE4A0

int TribeInformationAIModule::defendPriority(int, int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DDA90
// Source of truth: taiinfmd.cpp.decomp @ 0x004DE600

int TribeInformationAIModule::checkDefend(RGE_Static_Object*) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DDC10
// Source of truth: taiinfmd.cpp.decomp @ 0x004DEA70

int TribeInformationAIModule::numberItemsToDefend() {
    return this->itemsToDefend.numberValue;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DDC30
// Source of truth: taiinfmd.cpp.decomp @ 0x004DEA80

ObjectMemory* TribeInformationAIModule::objectToTradeWith(int) {
    return nullptr;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DDD70
// Source of truth: taiinfmd.cpp.decomp @ 0x004DEBA0

int TribeInformationAIModule::findGatherPosition(XYPoint*, int, int, int, int, RGE_Static_Object*, XYPoint*) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DE560
// Source of truth: taiinfmd.cpp.decomp @ 0x004DEE90

void TribeInformationAIModule::setupInfluenceMap(int, int, XYPoint*, XYPoint*, XYPoint*) {
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DFC70
// Source of truth: taiinfmd.cpp.decomp @ 0x004DFD40

int TribeInformationAIModule::groupInfluenceDimension(int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DFD60
// Source of truth: taiinfmd.cpp.decomp @ 0x004DFD60

ObjectMemory TribeInformationAIModule::findObjectMemoryLimits(int, int, int*, int*) {
    ObjectMemory result{};
    result.id = -1;
    result.type = -1;
    result.group = -1;
    return result;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DFEF0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E0040

int TribeInformationAIModule::isNextTo(XYPoint* param_1, XYPoint* param_2, int param_3) {
    if ((param_1 == nullptr) || (param_2 == nullptr)) {
        return 0;
    }
    int dx = std::abs(param_1->x - param_2->x);
    int dy = std::abs(param_1->y - param_2->y);
    if (param_3 != 0) {
        return ((dx <= 1) && (dy <= 1)) ? 1 : 0;
    }
    return ((dx + dy) == 1) ? 1 : 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DFF60
// Source of truth: taiinfmd.cpp.decomp @ 0x004E0090

int TribeInformationAIModule::facetTo(XYPoint*, XYPoint*) {
    return -1;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DFFB0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E0100

int TribeInformationAIModule::placementCode(int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004DFFE0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E02A0

void TribeInformationAIModule::storeLot(int, uchar, uchar, uchar) {
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E01D0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E0470

void TribeInformationAIModule::removeLot(int, uchar, uchar, uchar) {
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E0320
// Source of truth: taiinfmd.cpp.decomp @ 0x004E0510

BuildingLot* TribeInformationAIModule::availableLot(int) {
    return nullptr;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E03A0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E0560

int TribeInformationAIModule::invalidLot(int, uchar, uchar) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E0460
// Source of truth: taiinfmd.cpp.decomp @ 0x004E05C0

int TribeInformationAIModule::undesirableLot(int, uchar, uchar, int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E0720
// Source of truth: taiinfmd.cpp.decomp @ 0x004E0670

void TribeInformationAIModule::setupWalls(int, int, int, int, int, int, int, int) {
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E0D70
// Source of truth: taiinfmd.cpp.decomp @ 0x004E0F40

int TribeInformationAIModule::insideGate(int, int, int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E0DF0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E0F90

int TribeInformationAIModule::storeAttackMemory(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5, short param_6, uchar param_7,
                                                ulong param_8, int param_9) {
    return this->storeAttackMemory(param_1, param_2, param_3, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E0EE0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E0FD0

int TribeInformationAIModule::storeAttackMemory(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5, uchar param_6, uchar param_7,
                                                short param_8, uchar param_9, ulong param_10, int param_11) {
    if (this->attackMemories == nullptr) {
        return -1;
    }
    for (int i = 0; i < this->maxAttackMemories; ++i) {
        if (this->attackMemories[i].id == -1) {
            this->attackMemories[i].id = i;
            this->attackMemories[i].type = param_1;
            this->attackMemories[i].minX = param_2;
            this->attackMemories[i].minY = param_3;
            this->attackMemories[i].maxX = param_4;
            this->attackMemories[i].maxY = param_5;
            this->attackMemories[i].attackingOwner = param_6;
            this->attackMemories[i].targetOwner = param_7;
            this->attackMemories[i].kills = param_8;
            this->attackMemories[i].success = param_9;
            this->attackMemories[i].timeStamp = param_10;
            this->attackMemories[i].play = param_11;
            return i;
        }
    }
    return -1;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E10F0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E1190

void TribeInformationAIModule::removeAttackMemory(int param_1) {
    if ((param_1 < 0) || (param_1 >= this->maxAttackMemories) || (this->attackMemories == nullptr)) {
        return;
    }
    this->attackMemories[param_1].id = -1;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E1120
// Source of truth: taiinfmd.cpp.decomp @ 0x004E1230

AttackMemory* TribeInformationAIModule::attackMemory(int param_1) {
    if ((param_1 < 0) || (param_1 >= this->maxAttackMemories) || (this->attackMemories == nullptr)) {
        return nullptr;
    }
    if (this->attackMemories[param_1].id == -1) {
        return nullptr;
    }
    return &this->attackMemories[param_1];
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E1520
// Source of truth: taiinfmd.cpp.decomp @ 0x004E1730

int TribeInformationAIModule::unexploredPlayerLocation(int, XYPoint*) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E16D0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E1930

int TribeInformationAIModule::numberUnitsWithinXTiles(int, int, int, int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E17B0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E1A00

int TribeInformationAIModule::withinXTilesOfAttackOnPlayer(RGE_Static_Object*, int, int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E18D0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E1AF0

int TribeInformationAIModule::withinXTilesOfEnemyTowncenter(RGE_Static_Object*, int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E1A40
// Source of truth: taiinfmd.cpp.decomp @ 0x004E1BD0

int TribeInformationAIModule::withinXTilesOfObject(RGE_Static_Object*, int, int, int, int, int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E1BD0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E1D10

int TribeInformationAIModule::findStagingPoint(XYPoint, XYPoint*, int, int, int, int, int) {
    return -1;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E1F70
// Source of truth: taiinfmd.cpp.decomp @ 0x004E21E0

int TribeInformationAIModule::setupLOSMap(int, int, int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E2030
// Source of truth: taiinfmd.cpp.decomp @ 0x004E22F0

int TribeInformationAIModule::setupAttackMap(int, int, int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E30E0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E3140

int TribeInformationAIModule::numberGranaries() {
    int count = 0;
    for (int i = 0; i < this->playerBuildings.numberValue; ++i) {
        if (i >= this->playerBuildings.maximumSizeValue) {
            break;
        }
        RGE_Static_Object* building = tribe_information_object_by_id(this, this->playerBuildings.value[i]);
        if ((building != nullptr) && (building->master_obj != nullptr) && (building->master_obj->id == 0x44)) {
            count = count + 1;
        }
    }
    return count;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E3130
// Source of truth: taiinfmd.cpp.decomp @ 0x004E3210

int TribeInformationAIModule::amountForageBushesInXTiles(int, int, int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E3230
// Source of truth: taiinfmd.cpp.decomp @ 0x004E32C0

int TribeInformationAIModule::amountResourceTypesInXTiles(int, int, int, int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E3380
// Source of truth: taiinfmd.cpp.decomp @ 0x004E3390

float TribeInformationAIModule::damagePerSecond(int, int, int) {
    return 0.0f;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E35A0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E34C0

int TribeInformationAIModule::costToLoseUnit(int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E3690
// Source of truth: taiinfmd.cpp.decomp @ 0x004E3500

int TribeInformationAIModule::benefitToKillUnit(int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E37D0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E3530

int TribeInformationAIModule::inRangeOfUnits(int, int, int, int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E3A10
// Source of truth: taiinfmd.cpp.decomp @ 0x004E3640

ObjectMemory* TribeInformationAIModule::wonderToAttack(int) {
    return nullptr;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E3A90
// Source of truth: taiinfmd.cpp.decomp @ 0x004E3840

ObjectMemory* TribeInformationAIModule::ruinToCapture(int) {
    return nullptr;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E3B10
// Source of truth: taiinfmd.cpp.decomp @ 0x004E39D0

ObjectMemory* TribeInformationAIModule::artifactToCapture(int) {
    return nullptr;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E3B90
// Source of truth: taiinfmd.cpp.decomp @ 0x004E3B80

int TribeInformationAIModule::resourceTypeToPlaceDropsiteBy(int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E3BF0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E3C90

int TribeInformationAIModule::dropsitesWithinRequiredDistance(int*, int, int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E3D40
// Source of truth: taiinfmd.cpp.decomp @ 0x004E3E90

int TribeInformationAIModule::numberAvailableStoragePits(int) {
    return this->numberStoragePits();
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E3D90
// Source of truth: taiinfmd.cpp.decomp @ 0x004E3F80

int TribeInformationAIModule::numberAvailableGranaries() {
    return this->numberGranaries();
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E3DE0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E4040

void TribeInformationAIModule::lookAtMap() {
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E3E40
// Source of truth: taiinfmd.cpp.decomp @ 0x004E41C0

float TribeInformationAIModule::damageInflictedPerSecond(TacticalAIGroup*, RGE_Static_Object*) {
    return 0.0f;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E3F40
// Source of truth: taiinfmd.cpp.decomp @ 0x004E4240

float TribeInformationAIModule::damageInflictedPerSecond(int*, int, RGE_Static_Object*) {
    return 0.0f;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E4070
// Source of truth: taiinfmd.cpp.decomp @ 0x004E42B0

float TribeInformationAIModule::timeToBeKilled(TacticalAIGroup*, RGE_Static_Object*) {
    return 0.0f;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E4170
// Source of truth: taiinfmd.cpp.decomp @ 0x004E4350

float TribeInformationAIModule::timeToBeKilled(int*, int, RGE_Static_Object*) {
    return 0.0f;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E42B0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E43E0

int TribeInformationAIModule::closestDropsiteResID(int param_1) {
    if ((param_1 < 0) || (param_1 >= kResourceTypeSlots)) {
        return -1;
    }
    return this->closestDropsiteResourceID[param_1];
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E4300
// Source of truth: taiinfmd.cpp.decomp @ 0x004E4400

int TribeInformationAIModule::calculatePlayVariation(int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E43E0
// Source of truth: taiinfmd.cpp.decomp @ 0x004E4450

int TribeInformationAIModule::convertUnitToIntType(RGE_Static_Object* param_1) {
    return tribe_convert_unit_to_history_index(param_1);
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E4480
// Source of truth: taiinfmd.cpp.decomp @ 0x004E4500

void TribeInformationAIModule::loadUnitHistory() {
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E4510
// Source of truth: taiinfmd.cpp.decomp @ 0x004E45A0

void TribeInformationAIModule::unitsThatAreMostBuilt(int* param_1, int* param_2) {
    if (param_1 != nullptr) {
        *param_1 = -1;
    }
    if (param_2 != nullptr) {
        *param_2 = -1;
    }
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E4590
// Source of truth: taiinfmd.cpp.decomp @ 0x004E4610

void TribeInformationAIModule::unitsThatAreLeastBuilt(int* param_1, int* param_2) {
    if (param_1 != nullptr) {
        *param_1 = -1;
    }
    if (param_2 != nullptr) {
        *param_2 = -1;
    }
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E4610
// Source of truth: taiinfmd.cpp.decomp @ 0x004E4680

int TribeInformationAIModule::acceptablePotentialDropsiteArea(int, int) {
    return 0;
}

// TODO: Partial parity pending taiinfmd.cpp.decomp @ 0x004E4740
// Source of truth: taiinfmd.cpp.decomp @ 0x004E4790

int TribeInformationAIModule::percentTilesExploredInPositionQuadrant(int, int) {
    return 0;
}
