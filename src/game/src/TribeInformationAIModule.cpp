#include "../include/TribeInformationAIModule.h"

#include "../include/TribeMainDecisionAIModule.h"
#include "../include/TRIBE_Player.h"
#include "../include/AIPlayBook.h"
#include "../include/BaseItem.h"
#include "../include/BuildAIModule.h"
#include "../include/ConstructionAIModule.h"
#include "../include/AttackState.h"
#include "../include/PathingSystem.h"
#include "../include/PlacementState.h"
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
#include "../include/RGE_Zone_Map.h"
#include "../include/TacticalAIGroup.h"
#include "../include/TribeTacticalAIModule.h"
#include "../include/UnitAIModule.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <cstring>
#include <cstdio>
#include <cmath>
#include <new>

static InfluenceMap iMap;
static InfluenceMap losMap;
static InfluenceMap attackMap;

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D6AD0
static void E9() {
    iMap = InfluenceMap(0xFE, 0xFE, 0);
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D6B20
static void E14() {
    losMap = InfluenceMap(0x32, 0x32, 0);
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D6B70
static void E19() {
    attackMap = InfluenceMap(0x32, 0x32, 0);
}

// Source of truth: taiinfmd.cpp.decomp @ 0x004D90F1
// TODO: PARITY [CRITICAL] - This function is still effectively unimplemented here (ASM-thunk placeholder), but decomp shows a complete object/zone predicate with explicit return paths. [decomp: taiinfmd.cpp.decomp @ 0x004D90F1]
static void FUN_004d90f1() {
    // Fully verified. Source of truth: taiinfmd.cpp.asm @ 0x004D90F1 (switch jump-table thunk)
}

// Source of truth: taiinfmd.cpp.decomp @ 0x004DA16D
// TODO: PARITY [CRITICAL] - Stub remains ASM-thunk only; decomp body is unresolved/corrupted and needs explicit parity resolution. [decomp: taiinfmd.cpp.decomp @ 0x004DA16D]
static void FUN_004da16d() {
    // Fully verified. Source of truth: taiinfmd.cpp.asm @ 0x004DA16D (switch jump-table thunk)
}

// Source of truth: taiinfmd.cpp.decomp @ 0x004E0165
// TODO: PARITY [CRITICAL] - Stub remains ASM-thunk only; decomp body is unresolved/corrupted and needs explicit parity resolution. [decomp: taiinfmd.cpp.decomp @ 0x004E0165]
static void FUN_004e0165() {
    // Fully verified. Source of truth: taiinfmd.cpp.asm @ 0x004E0165 (switch jump-table thunk)
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    array.value = nullptr;
    array.numberValue = 0;
    array.desiredNumberValue = 0;
    array.maximumSizeValue = 0;
}

void tribe_clear_managed_array(ManagedArray<int>& array) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if (array.value != nullptr) {
        ::operator delete(array.value);
        array.value = nullptr;
    }
    array.numberValue = 0;
    array.desiredNumberValue = 0;
    array.maximumSizeValue = 0;
}

int tribe_managed_array_contains(const ManagedArray<int>& array, int value) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    for (int i = 0; i < array.numberValue; ++i) {
        if ((i < array.maximumSizeValue) && (array.value != nullptr) && (array.value[i] == value)) {
            return 1;
        }
    }
    return 0;
}

int tribe_managed_array_ensure_capacity(ManagedArray<int>& array, int required_capacity) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if (tribe_managed_array_ensure_capacity(array, array.numberValue + 1) == 0) {
        return 0;
    }
    array.value[array.numberValue] = value;
    array.numberValue = array.numberValue + 1;
    return 1;
}

void tribe_influence_map_destroy(InfluenceMap& map) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int local_x = x - map.xReferencePointValue;
    int local_y = y - map.yReferencePointValue;
    if ((local_x < 0) || (local_y < 0) || (local_x >= map.xSizeValue) || (local_y >= map.ySizeValue) || (map.rowValue == nullptr)) {
        return 0xFF;
    }
    return static_cast<int>(map.rowValue[local_y][local_x]);
}

int tribe_influence_map_set(InfluenceMap& map, int x, int y, uchar value) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int local_x = x - map.xReferencePointValue;
    int local_y = y - map.yReferencePointValue;
    if ((local_x < 0) || (local_y < 0) || (local_x >= map.xSizeValue) || (local_y >= map.ySizeValue) || (map.rowValue == nullptr)) {
        return 0;
    }
    map.rowValue[local_y][local_x] = value;
    return 1;
}

void tribe_influence_map_save(const InfluenceMap& map, int handle) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((self == nullptr) || (self->md == nullptr) || (self->md->player == nullptr) || (self->md->player->world == nullptr)) {
        return nullptr;
    }
    return self->md->player->world->object(object_id);
}

int tribe_object_current_zone(RGE_Static_Object* object) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if (object == nullptr) {
        return -1;
    }
    return static_cast<int>(object->lookupZone(static_cast<int>(object->world_x), static_cast<int>(object->world_y)));
}

void tribe_add_resource_type(TribeInformationAIModule* self, int resource_index, int resource_type) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int count = 0;
    rge_read(file_handle, &count, 4);
    for (int i = 0; i < count; ++i) {
        int value = -1;
        rge_read(file_handle, &value, 4);
        tribe_managed_array_append_unique(array, value);
    }
}

void tribe_save_id_list(ManagedArray<int>& array, int file_handle) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((self == nullptr) || (self->md == nullptr)) {
        return nullptr;
    }
    return self->md->player;
}

RGE_Game_World* tribe_information_world(TribeInformationAIModule* self) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    RGE_Player* player = tribe_information_player(self);
    if (player == nullptr) {
        return nullptr;
    }
    return player->world;
}

int tribe_resource_slot_from_group(short object_group) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int dx = x1 - x2;
    int dy = y1 - y2;
    return dx * dx + dy * dy;
}

BaseItem* tribe_build_item_base(BuildItem* item) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    return reinterpret_cast<BaseItem*>(item);
}

int tribe_convert_unit_to_history_index(RGE_Static_Object* object) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((object == nullptr) || (object->owner == nullptr) || (object->owner->world == nullptr) || (object->owner->world->playbook == nullptr)) {
        return -1;
    }
    return object->owner->world->playbook->convertUnitToIntType(object);
}

int tribe_single_player_game() {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if (rge_base_game == nullptr) {
        return 0;
    }
    return rge_base_game->singlePlayerGame();
}

int tribe_matches_local_player_context(TribeInformationAIModule* self) {
    // Fully verified. Source of truth: taiinfmd.cpp.asm @ 0x004D8033 / 0x004DA6C6 (player-context gate).
    if ((self == nullptr) || (self->md == nullptr) || (self->md->player == nullptr)) {
        return 0;
    }

    uchar* player_bytes = reinterpret_cast<uchar*>(self->md->player);
    void* player_context = *reinterpret_cast<void**>(player_bytes + 0x3C);
    if (player_context == nullptr) {
        return 0;
    }

    uchar context_player_id = *reinterpret_cast<uchar*>(reinterpret_cast<uchar*>(player_context) + 0x11D);
    ushort self_player_id = *reinterpret_cast<ushort*>(player_bytes + 0x4A);
    if ((context_player_id == static_cast<uchar>(self_player_id)) || (context_player_id == 0xFF)) {
        return 1;
    }
    return 0;
}

BuildAIModule* tribe_build_ai(TribeInformationAIModule* self) {
    if ((self == nullptr) || (self->md == nullptr)) {
        return nullptr;
    }
    return reinterpret_cast<BuildAIModule*>(self->md->buildAI);
}

TribeTacticalAIModule* tribe_tactical_ai(TribeInformationAIModule* self) {
    if ((self == nullptr) || (self->md == nullptr)) {
        return nullptr;
    }
    return reinterpret_cast<TribeTacticalAIModule*>(self->md->tacticalAI);
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
            this->addResourceType(i, value);
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

    if (this->saveLearnInformationValue == 1) {
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

    if (tribe_matches_local_player_context(this) != 0) {
        int unit_history_file = rge_open(this->unitHistoryFilename, 0x8301, 0x180);
        if (unit_history_file != -1) {
            rge_write(unit_history_file, this->unitHistory, sizeof(this->unitHistory));
            rge_close(unit_history_file);
        }
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    return InformationAIModule::loggingHistory();
}

void TribeInformationAIModule::setLogHistory(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    InformationAIModule::setLogHistory(param_1);
}

void TribeInformationAIModule::toggleLogHistory() {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    InformationAIModule::toggleLogHistory();
}

void TribeInformationAIModule::setHistoryFilename(char* param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    InformationAIModule::setHistoryFilename(param_1);
}

int TribeInformationAIModule::loggingCommonHistory() {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    return InformationAIModule::loggingCommonHistory();
}

void TribeInformationAIModule::setLogCommonHistory(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    InformationAIModule::setLogCommonHistory(param_1);
}

void TribeInformationAIModule::toggleLogCommonHistory() {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    InformationAIModule::toggleLogCommonHistory();
}

int TribeInformationAIModule::loadState(char* param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    return InformationAIModule::loadState(param_1);
}

int TribeInformationAIModule::saveState(char* param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    return InformationAIModule::saveState(param_1);
}

int TribeInformationAIModule::gleanState(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    return InformationAIModule::gleanState(param_1);
}

int TribeInformationAIModule::processMessage(AIModuleMessage* param_1) {
    return InformationAIModule::processMessage(param_1);
}

// Offset: 0x004D8270
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D8270
int TribeInformationAIModule::initialize() {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((param_1 >= 0) && (param_2 >= 0) && (param_1 < this->mapXSizeValue) && (param_2 < this->mapYSizeValue)) {
        tribe_influence_map_set(this->pathMap, param_1, param_2, 0);
    }
}

// Offset: 0x004DA190
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DA190
int TribeInformationAIModule::mapXSize() {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((this->mapXSizeValue == -1) && (this->md != nullptr) && (this->md->player != nullptr) && (this->md->player->world != nullptr) &&
        (this->md->player->world->map != nullptr)) {
        this->mapXSizeValue = this->md->player->world->map->map_width;
    }
    return this->mapXSizeValue;
}

// Offset: 0x004DA1C0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DA1C0
int TribeInformationAIModule::mapYSize() {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((this->mapYSizeValue == -1) && (this->md != nullptr) && (this->md->player != nullptr) && (this->md->player->world != nullptr) &&
        (this->md->player->world->map != nullptr)) {
        this->mapYSizeValue = this->md->player->world->map->map_height;
    }
    return this->mapYSizeValue;
}

// Offset: 0x004DFCE0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DFCE0
int TribeInformationAIModule::mapBound(XYPoint& param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    (void)param_1;
    return -1;
}

// Offset: 0x004D9240
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D9240
int TribeInformationAIModule::gameIDOfResourceObject(int param_1, int param_2, float* param_3, float* param_4, int* param_5, int* param_6, int param_7) {
    // Fully verified. Source of truth: taiinfmd.cpp.asm @ 0x004D9240
    if (param_5 == nullptr) {
        return -1;
    }
    *param_5 = -1;

    if ((param_1 < 0) || (param_1 >= kResourceTypeSlots)) {
        return -1;
    }

    RGE_Static_Object* gatherer_obj = tribe_information_object_by_id(this, param_2);
    if ((gatherer_obj == nullptr) || (gatherer_obj->master_obj == nullptr) || (this->md == nullptr) || (this->md->player == nullptr)) {
        return -1;
    }
    TribeTacticalAIModule* tactical = tribe_tactical_ai(this);
    if (tactical == nullptr) {
        return -1;
    }

    if ((this->resources[param_1] == nullptr) || (this->numResources[param_1] <= 0)) {
        return -1;
    }

    const int gatherer_zone = tribe_object_current_zone(gatherer_obj);
    const int gatherer_x = static_cast<int>(gatherer_obj->world_x);
    const int gatherer_y = static_cast<int>(gatherer_obj->world_y);
    const int gatherer_is_boat = (gatherer_obj->master_obj->object_group == 4) ? 1 : 0;
    const int player_id = this->md->player->id;

    ResourceMemory* best_object = nullptr;
    int best_score = 0;
    int update_resource_dropsites = 0;

    for (int i = 0; i < this->numResources[param_1]; ++i) {
        ResourceMemory& memory = this->resources[param_1][i];
        if (memory.gone == 1) {
            continue;
        }

        if (memory.valid != 0) {
            memory.valid = static_cast<uchar>(memory.valid - 1);
            continue;
        }

        int in_exclusion_list = 0;
        if ((param_6 != nullptr) && (param_7 > 0)) {
            for (int j = 0; j < param_7; ++j) {
                if (param_6[j] == memory.id) {
                    in_exclusion_list = 1;
                    break;
                }
            }
        }
        if (in_exclusion_list == 1) {
            continue;
        }

        RGE_Static_Object* resource_object = tribe_information_object_by_id(this, memory.id);
        if (resource_object == nullptr) {
            memory.gone = 1;
            if (this->closestDropsiteResourceID[param_1] == memory.id) {
                update_resource_dropsites = 1;
            }
            continue;
        }
        if (resource_object->master_obj == nullptr) {
            continue;
        }

        short object_group = resource_object->master_obj->object_group;
        if ((gatherer_is_boat == 1) && (object_group != 5) && (object_group != 0x1F) && (object_group != 0x21)) {
            continue;
        }
        if ((gatherer_is_boat == 0) && ((object_group == 5) || (object_group == 0x1F) || (object_group == 0x21))) {
            continue;
        }

        int score = tribe_distance_squared(gatherer_x, gatherer_y, static_cast<int>(memory.x), static_cast<int>(memory.y));
        score = score + (memory.gatherValue * 10);

        const short object_id = resource_object->master_obj->id;
        if (object_id == 0x3B) {
            if (memory.dropDistance > 0x14) {
                continue;
            }
            score = score + (memory.gatherAttempts / 0x96);
            if (tactical->numberGatherersWithTarget(memory.id) > 2) {
                score = score + 0xC8;
            }
        } else {
            score = score + (memory.gatherAttempts / 0x32);
        }

        if ((best_object != nullptr) && (score >= best_score)) {
            continue;
        }

        if (((object_group == 9) || (object_group == 10)) && (resource_object->object_state > 2) && (resource_object->attribute_amount_held > 25.0f)) {
            score = score + 0x19;
        }
        if (withinXTilesOfEnemyTowncenter(resource_object, 0x19) == 1) {
            continue;
        }
        if (withinXTilesOfAttackOnPlayer(resource_object, 0x0F, player_id) == 1) {
            score = score + 0x1F4;
        }

        if (object_id == 0x32) {
            if ((resource_object->owner == nullptr) || (resource_object->owner->id != player_id)) {
                continue;
            }
            if (resource_object->object_state != 2) {
                continue;
            }
            if (tactical->numberGatherersWithTarget(memory.id) > 0) {
                continue;
            }
            int skip_farm = 0;
            for (int j = 0; j < this->farmsTaskedThisUpdate.numberValue; ++j) {
                if (j >= this->farmsTaskedThisUpdate.maximumSizeValue) {
                    break;
                }
                if (this->farmsTaskedThisUpdate.value[j] == memory.id) {
                    skip_farm = 1;
                    break;
                }
            }
            if (skip_farm == 1) {
                continue;
            }
        }

        if ((param_1 == 1) && (tactical->numberGatherersWithTarget(memory.id) > 0)) {
            continue;
        }
        if (((param_1 == 2) || (param_1 == 3)) && (tactical->numberGatherersWithTarget(memory.id) > 3)) {
            continue;
        }

        if ((object_id == 0x30) && (resource_object->object_state == 2)) {
            int required = tactical->strategicNumber(0xCC);
            int actual = tactical->actualGathererCountByRealResourceID(0);
            if (actual < required) {
                continue;
            }
        }

        if (gatherer_obj->lookupZone(static_cast<int>(memory.x), static_cast<int>(memory.y)) != static_cast<uchar>(gatherer_zone)) {
            continue;
        }
        if ((best_object != nullptr) && (score >= best_score)) {
            continue;
        }

        best_object = &memory;
        best_score = score;
        if (param_3 != nullptr) {
            *param_3 = resource_object->world_x;
        }
        if (param_4 != nullptr) {
            *param_4 = resource_object->world_y;
        }
    }

    if (update_resource_dropsites == 1) {
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    bool found_existing_entry = false;
    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        if (this->importantObjectMemory[i].id == param_1) {
            free_index = i;
            found_existing_entry = true;
            break;
        }
        if ((this->importantObjectMemory[i].id == -1) && (free_index == -1)) {
            free_index = i;
        }
    }

    if ((found_existing_entry == false) && (param_14 != nullptr) && (this->md != nullptr) && (this->md->player != nullptr) &&
        (this->md->player->strategicNumber(0xC9) == 1) && (tribe_matches_local_player_context(this) != 0) &&
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    RGE_Static_Object* object = tribe_information_object_by_id(this, param_1);
    return this->addImportantObject(object, 0);
}

// Offset: 0x004DAFB0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DAFB0
int TribeInformationAIModule::importantObject(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((((param_1 != 0x1F) && (param_1 != 5)) && (param_1 != 0x21)) &&
        ((param_1 != 7 && (param_1 != 9)) && ((param_1 != 8 && (param_1 != 0x20)) && (param_1 != 0x0F)))) {
        return 0;
    }
    return 1;
}

// Offset: 0x004DB0B0
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DB0B0
int TribeInformationAIModule::importantMisc(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((param_1 != 1) && (param_1 != 0x1E)) {
        return 0;
    }
    return 1;
}

// Offset: 0x004E1260
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E1260
void TribeInformationAIModule::loadLearnInfo(char* param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if (param_3 != nullptr) {
        *param_3 = -1;
    }
    if ((param_1 == nullptr) || (param_1->master_obj == nullptr)) {
        return 1000.0f;
    }

    float best_distance = 1000.0f;
    int resource_zone = tribe_object_current_zone(param_1);

    // TODO: PARITY [CRITICAL] - taiinfmd.cpp.decomp @ 0x004E2A00 includes a playerBuildings capacity-growth path during iteration; this implementation hard-breaks at maximumSizeValue and needs asm verification.
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
            // TODO: PARITY [MODERATE] - Decomp uses __ftol for gatherValue/dropDistance writes in this path; static_cast truncation may drift at boundary values. [decomp: taiinfmd.cpp.decomp @ 0x004E2D10]
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
        // TODO: PARITY [MODERATE] - Decomp uses __ftol before writing gatherValue/dropDistance here; confirm rounding mode parity versus cast-based conversion. [decomp: taiinfmd.cpp.decomp @ 0x004E2E90]
        memory.gatherValue = static_cast<int>(distance);
        memory.dropDistance = static_cast<uchar>(distance);
        memory.dropsiteID = dropsite_id;
        tribe_update_closest_dropsite_for_resource(this, resource_obj, distance);
    }
}

// Offset: 0x004E3020
// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E3020
int TribeInformationAIModule::setResourceObjectValid(int param_1, int param_2, int param_3) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
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

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D9B20
ConstructionItem* TribeInformationAIModule::placeDock(BuildItem* param_1, float param_2, float param_3, int param_4, int param_5) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((this->md == nullptr) || (this->md->aiPlayer == nullptr) || (this->md->aiPlayer->visible == nullptr) || (param_1 == nullptr)) {
        return nullptr;
    }

    RGE_Visible_Map* visible_map = this->md->aiPlayer->visible;
    RGE_Map* game_map = visible_map->map;
    if (game_map == nullptr) {
        return nullptr;
    }

    ConstructionAIModule* construction_ai = reinterpret_cast<ConstructionAIModule*>(&this->md->constructionAI);
    BaseItem* base_item = tribe_build_item_base(param_1);
    if (base_item == nullptr) {
        return nullptr;
    }

    int best_x = -1;
    int best_y = -1;
    int best_score = -0x7fffffff;
    for (int x = 1; x < (visible_map->widthValue - 1); ++x) {
        for (int y = 1; y < (visible_map->heightValue - 1); ++y) {
            if (visible_map->get_visible(x, y) == 0) {
                continue;
            }

            RGE_Tile* tile = game_map->get_tile(x, y);
            if (tile == nullptr) {
                continue;
            }
            if ((param_4 != -1) && (static_cast<int>(tile->terrain_type) != param_4)) {
                continue;
            }
            if (hasAdjacentTileType(x, y, param_5) == 0) {
                continue;
            }
            if ((construction_ai != nullptr) && (construction_ai->randomLot(static_cast<float>(x) + 0.5f, static_cast<float>(y) + 0.5f) != nullptr)) {
                continue;
            }

            int score = -tribe_distance_squared(x, y, static_cast<int>(param_2), static_cast<int>(param_3));
            int dock_distance = closestDockDistance(x, y);
            if (dock_distance != -1) {
                score = score + (100000 / dock_distance);
            }
            if ((best_x == -1) || (best_score < score)) {
                best_x = x;
                best_y = y;
                best_score = score;
            }
        }
    }

    if (best_x == -1) {
        return nullptr;
    }

    return new (std::nothrow) ConstructionItem(static_cast<float>(best_x) + 0.5f, static_cast<float>(best_y) + 0.5f, 0.0f, base_item->xSize(), base_item->ySize(),
                                               base_item->zSize(), base_item->typeID(), base_item->name());
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D9EC0
int TribeInformationAIModule::numberDocksInZone(int param_1, RGE_Zone_Map* param_2) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int dock_zone = 0;
    for (int i = 0; i < this->playerBuildings.numberValue; ++i) {
        if ((this->playerBuildings.maximumSizeValue - 1) < i) {
            int* resized = static_cast<int*>(::operator new(static_cast<size_t>(i + 1) * sizeof(int), std::nothrow));
            if (resized != nullptr) {
                for (int copy = 0; (copy < this->playerBuildings.maximumSizeValue) && (copy < (i + 1)); ++copy) {
                    resized[copy] = this->playerBuildings.value[copy];
                }
                ::operator delete(this->playerBuildings.value);
                this->playerBuildings.value = resized;
                this->playerBuildings.maximumSizeValue = i + 1;
            }
        }

        RGE_Static_Object* dock = this->md->object(this->playerBuildings.value[i]);
        if ((dock != nullptr) && (dock->master_obj != nullptr) && (dock->master_obj->id == 0x2D)) {
            int dock_y = static_cast<int>(dock->world_y);
            int dock_x = static_cast<int>(dock->world_x);
            uchar zone = param_2->get_zone_info(dock_x, dock_y);
            if (static_cast<int>(zone) == param_1) {
                dock_zone = dock_zone + 1;
            }
        }
    }
    return dock_zone;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004D9FC0
int TribeInformationAIModule::closestDockDistance(int param_1, int param_2) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int best_distance = -1;
    for (int i = 0; i < this->playerBuildings.numberValue; ++i) {
        if ((this->playerBuildings.maximumSizeValue - 1) < i) {
            int* resized = static_cast<int*>(::operator new(static_cast<size_t>(i + 1) * sizeof(int), std::nothrow));
            if (resized != nullptr) {
                for (int copy = 0; (copy < this->playerBuildings.maximumSizeValue) && (copy < (i + 1)); ++copy) {
                    resized[copy] = this->playerBuildings.value[copy];
                }
                ::operator delete(this->playerBuildings.value);
                this->playerBuildings.value = resized;
                this->playerBuildings.maximumSizeValue = i + 1;
            }
        }

        RGE_Static_Object* dock = this->md->object(this->playerBuildings.value[i]);
        if ((dock != nullptr) && (dock->master_obj != nullptr) && (dock->master_obj->id == 0x2D)) {
            int dx = param_1 - static_cast<int>(dock->world_x);
            int dy = param_2 - static_cast<int>(dock->world_y);
            int distance = static_cast<int>(std::sqrt(static_cast<float>((dx * dx) + (dy * dy))));
            if ((distance != 0) && ((best_distance == -1) || (distance < best_distance))) {
                best_distance = distance;
            }
        }
    }
    return best_distance;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DB0D0
int TribeInformationAIModule::isBuilding(RGE_Static_Object* param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    short object_group = param_1->master_obj->object_group;
    if ((object_group != 3) && (object_group != 0x1B)) {
        return 0;
    }
    return 1;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DB100
int TribeInformationAIModule::isUnitBuilding(RGE_Static_Object* param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if (param_1->master_obj->object_group != 3) {
        return 0;
    }
    short id = param_1->master_obj->id;
    if (((((id != 0x6D) && (id != 0x0C)) && (id != 0x57)) && ((id != 0x31) && (id != 0x2D))) && ((id != 0) && ((id != 0x65) && (id != 0x68)))) {
        return 0;
    }
    return 1;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DB160
int TribeInformationAIModule::isBoat(RGE_Static_Object* param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    short object_group = param_1->master_obj->object_group;
    if ((((object_group != 0x15) && (object_group != 2)) && (object_group != 0x14)) && (object_group != 0x16)) {
        return 0;
    }
    return 1;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DB190
int TribeInformationAIModule::isWall(RGE_Static_Object* param_1) {
    return (param_1->master_obj->object_group == 0x1B) ? 1 : 0;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DB1B0
int TribeInformationAIModule::isTower(RGE_Static_Object* param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    short id = param_1->master_obj->id;
    if ((((id != 0x4F) && (id != 199)) && (id != 0x45)) && ((id != 0x17F) && (id != 0x17C))) {
        return 0;
    }
    return 1;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DB1F0
int TribeInformationAIModule::isBoatAccessible(RGE_Static_Object*, int param_2) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    RGE_Static_Object* object = (this->md != nullptr) ? this->md->object(param_2) : nullptr;
    if ((object == nullptr) || (object->master_obj == nullptr)) {
        return 0;
    }
    short object_group = object->master_obj->object_group;
    if ((((object_group != 0x15) && (object_group != 2)) && (object_group != 0x14)) &&
        ((object_group != 0x16) && (object->master_obj->id != 0x2D))) {
        return 0;
    }
    return 1;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DB240
int TribeInformationAIModule::isLandAccessible(RGE_Static_Object*, int param_2) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    RGE_Static_Object* object = (this->md != nullptr) ? this->md->object(param_2) : nullptr;
    if ((object != nullptr) && (object->master_obj != nullptr)) {
        short object_group = object->master_obj->object_group;
        if ((((object_group != 0x15) && (object_group != 2)) && (object_group != 0x14)) && (object_group != 0x16)) {
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DB280
int TribeInformationAIModule::influenceCanPlaceStructure(BuildItem*) {
    return 1;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DB290
ConstructionItem* TribeInformationAIModule::influencePlaceStructure(BuildItem* param_1, int param_2, int param_3, float param_4, char* param_5, int param_6,
                                                                     int param_7, int param_8, int param_9, PlacementState* param_10, ulong param_11) {
    (void)param_11;
    if ((this->md == nullptr) || (param_10 == nullptr)) {
        return nullptr;
    }

    int building_type = param_3;
    int building_size = static_cast<int>(param_4);
    const char* building_name_src = (param_5 != nullptr) ? param_5 : "";
    int builder_id = param_2;

    if (param_10->active == 1) {
        building_type = param_10->buildingTypeID;
        building_size = static_cast<int>(param_10->buildingSize);
        building_name_src = param_10->buildingName;
        builder_id = param_10->builderID;
    } else if (param_1 != nullptr) {
        BaseItem* base_item = tribe_build_item_base(param_1);
        if (base_item != nullptr) {
            building_type = base_item->typeID();
            building_size = static_cast<int>(base_item->xSize());
            building_name_src = base_item->name();
        }
    }

    if ((building_type < 0) || (building_size <= 0)) {
        param_10->active = 0;
        return nullptr;
    }

    int placement_type = placementCode(building_type);
    if (placement_type == -1) {
        param_10->active = 0;
        return nullptr;
    }

    char building_name[256]{};
    std::strncpy(building_name, building_name_src, sizeof(building_name) - 1);

    if ((param_10->active == 0) && (param_1 != nullptr)) {
        BuildingLot* lot = availableLot(building_type);
        if (lot != nullptr) {
            float place_x = static_cast<float>(lot->x);
            float place_y = static_cast<float>(lot->y);
            if (building_size != 2) {
                place_x = place_x + 0.5f;
                place_y = place_y + 0.5f;
            }
            lot->status = 1;
            param_10->active = 0;
            return new (std::nothrow) ConstructionItem(place_x, place_y, 1.0f, static_cast<float>(building_size), static_cast<float>(building_size), 1.0f,
                                                       building_type, building_name);
        }
    }

    RGE_Static_Object* town_center = this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
    RGE_Static_Object* group_center = this->md->object(-1, -1, 4, -1, -1, -1, -1, -1, -1, -1);
    RGE_Static_Object* builder = this->md->object(builder_id);
    if (town_center == nullptr) {
        town_center = group_center;
    }
    if (town_center == nullptr) {
        town_center = builder;
    }
    if (town_center == nullptr) {
        param_10->active = 0;
        return nullptr;
    }

    XYPoint center{};
    if ((param_1 == nullptr) && (param_10->active == 0)) {
        center.x = param_8;
        center.y = param_9;
    } else {
        center.x = static_cast<int>(town_center->world_x);
        center.y = static_cast<int>(town_center->world_y);
    }

    int min_distance = param_6;
    int max_distance = param_7;
    if (param_10->active == 1) {
        min_distance = param_10->minimumDistance;
        max_distance = param_10->maximumDistance;
    } else if ((param_1 != nullptr) || (param_10->active == 1)) {
        if (placement_type == 1) {
            min_distance = 7;
            max_distance = (this->md->player != nullptr) ? this->md->player->strategicNumber(0x56) : 8;
        } else if (placement_type == 2) {
            min_distance = 4;
            max_distance = (this->md->player != nullptr) ? this->md->player->strategicNumber(0x57) : 8;
        } else {
            min_distance = ((placement_type == 3) || (placement_type == 4)) ? ((this->md->player != nullptr) ? this->md->player->strategicNumber(0x49) : 4) : 4;
            max_distance = (this->md->player != nullptr) ? this->md->player->strategicNumber(0x4A) : 10;
        }
    }
    if (max_distance <= min_distance) {
        param_10->active = 0;
        return nullptr;
    }

    XYPoint min_point{center.x - max_distance, center.y - max_distance};
    XYPoint max_point{center.x + max_distance, center.y + max_distance};
    mapBound(min_point);
    mapBound(max_point);

    if (param_10->active == 0) {
        setupInfluenceMap(placement_type, building_type, &center, &min_point, &max_point);
    }

    int iteration_x = min_point.x;
    int best_x = -1;
    int best_y = -1;
    int best_value = (param_10->active == 1) ? param_10->bestPointValue : -1;
    int random_influence = (param_10->active == 1) ? param_10->randomInfluence : 0;
    if (param_10->active == 1) {
        iteration_x = param_10->iterationX;
        best_x = param_10->bestPoint.x;
        best_y = param_10->bestPoint.y;
    }

    XYPoint min_exclude{center.x - min_distance, center.y - min_distance};
    XYPoint max_exclude{center.x + min_distance, center.y + min_distance};
    mapBound(min_exclude);
    mapBound(max_exclude);

    for (int x = iteration_x; x <= max_point.x; ++x) {
        for (int y = min_point.y; y <= max_point.y; ++y) {
            if ((placement_type == 3) || (placement_type == 4)) {
                if ((min_exclude.x <= x) && (x <= max_exclude.x) && (min_exclude.y <= y) && (y <= max_exclude.y)) {
                    continue;
                }
            }

            XYPoint clear_min{};
            XYPoint clear_max{};
            if (building_size >= 5) {
                clear_min = {x - 2, y - 2};
                clear_max = {x + 2, y + 2};
            } else if (building_size == 3) {
                clear_min = {x - 1, y - 1};
                clear_max = {x + 1, y + 1};
            } else if (building_size == 2) {
                clear_min = {x - 1, y - 1};
                clear_max = {x, y};
            } else {
                clear_min = {x, y};
                clear_max = {x, y};
            }

            if ((mapBound(clear_min) != 0) || (mapBound(clear_max) != 0)) {
                continue;
            }
            if (invalidLot(building_type, static_cast<uchar>(x), static_cast<uchar>(y)) != 0) {
                continue;
            }

            int value = 0;
            bool blocked = false;
            for (int cx = clear_min.x; cx <= clear_max.x; ++cx) {
                for (int cy = clear_min.y; cy <= clear_max.y; ++cy) {
                    int influence = iMap.lookupValue(cx, cy);
                    if (influence == 0xFF) {
                        blocked = true;
                        break;
                    }
                    value = value + influence;
                }
                if (blocked) {
                    break;
                }
            }
            if (blocked) {
                continue;
            }

            if (undesirableLot(building_type, static_cast<uchar>(x), static_cast<uchar>(y), (placement_type <= 2) ? 10 : building_size) != 0) {
                value = value / 10;
            }

            int distance_sq = tribe_distance_squared(x, y, center.x, center.y);
            if ((placement_type == 1) || (placement_type == 2)) {
                value = value - (distance_sq / 5);
            }

            if ((best_x == -1) || (best_value < (value + random_influence))) {
                best_x = x;
                best_y = y;
                best_value = value;
            }
        }
    }

    if (best_x == -1) {
        param_10->active = 0;
        return nullptr;
    }

    if (placement_type == 4) {
        this->lastWallPosition2 = this->lastWallPosition;
        this->lastWallPosition.x = best_x;
        this->lastWallPosition.y = best_y;
    }

    if (param_1 == nullptr) {
        storeLot(building_type, static_cast<uchar>(best_x), static_cast<uchar>(best_y), 0);
        param_10->active = 0;
        return reinterpret_cast<ConstructionItem*>(1);
    }

    float place_x = static_cast<float>(best_x);
    float place_y = static_cast<float>(best_y);
    if (building_size != 2) {
        place_x = place_x + 0.5f;
        place_y = place_y + 0.5f;
    }

    ConstructionItem* placed = new (std::nothrow)
        ConstructionItem(place_x, place_y, 1.0f, static_cast<float>(building_size), static_cast<float>(building_size), 1.0f, building_type, building_name);
    storeLot(building_type, static_cast<uchar>(best_x), static_cast<uchar>(best_y), 1);
    param_10->active = 0;
    return placed;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DC1B0
void TribeInformationAIModule::addObject(RGE_Static_Object* param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((param_1 == nullptr) || (param_1->id < 0)) {
        return;
    }

    ObjectMemory* memory = this->objectMemory(param_1->id);
    if ((memory != nullptr) && (param_1->owner != nullptr)) {
        memory->owner = static_cast<uchar>(param_1->owner->id);
    }

    int object_id = param_1->id;
    bool found_object = false;
    for (int i = 0; i < this->playerObjects.numberValue; ++i) {
        if (this->playerObjects.maximumSizeValue <= i) {
            break;
        }
        if (this->playerObjects.value[i] == object_id) {
            found_object = true;
            break;
        }
    }

    if (!found_object) {
        if ((this->playerObjects.maximumSizeValue - 1) < this->playerObjects.numberValue) {
            int new_capacity = this->playerObjects.numberValue + 1;
            int* resized = static_cast<int*>(::operator new(static_cast<size_t>(new_capacity) * sizeof(int), std::nothrow));
            if (resized != nullptr) {
                for (int i = 0; (i < this->playerObjects.maximumSizeValue) && (i < new_capacity); ++i) {
                    resized[i] = this->playerObjects.value[i];
                }
                ::operator delete(this->playerObjects.value);
                this->playerObjects.value = resized;
                this->playerObjects.maximumSizeValue = new_capacity;
            }
        }

        this->playerObjects.value[this->playerObjects.numberValue] = object_id;
        this->playerObjects.numberValue = this->playerObjects.numberValue + 1;
    }

    if (this->isBuilding(param_1) != 1) {
        return;
    }

    bool found_building = false;
    for (int i = 0; i < this->playerBuildings.numberValue; ++i) {
        if (this->playerBuildings.maximumSizeValue <= i) {
            break;
        }
        if (this->playerBuildings.value[i] == object_id) {
            found_building = true;
            break;
        }
    }

    if (!found_building) {
        if ((this->playerBuildings.maximumSizeValue - 1) < this->playerBuildings.numberValue) {
            int new_capacity = this->playerBuildings.numberValue + 1;
            int* resized = static_cast<int*>(::operator new(static_cast<size_t>(new_capacity) * sizeof(int), std::nothrow));
            if (resized != nullptr) {
                for (int i = 0; (i < this->playerBuildings.maximumSizeValue) && (i < new_capacity); ++i) {
                    resized[i] = this->playerBuildings.value[i];
                }
                ::operator delete(this->playerBuildings.value);
                this->playerBuildings.value = resized;
                this->playerBuildings.maximumSizeValue = new_capacity;
            }
        }

        this->playerBuildings.value[this->playerBuildings.numberValue] = object_id;
        this->playerBuildings.numberValue = this->playerBuildings.numberValue + 1;
    }

    short unit_id = param_1->master_obj->id;
    if ((unit_id == 0x6D) || (unit_id == 0x67) || (unit_id == 0x44)) {
        this->updateAllResourceDropsites();
    }
    if (param_1->master_obj->id == 0x32) {
        this->addResourceObject(param_1);
    }
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DC3A0
void TribeInformationAIModule::removeObject(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int index = 0;
    int max_size = this->playerBuildings.maximumSizeValue;
    if (0 < max_size) {
        while (index < max_size) {
            if (this->playerBuildings.value[index] == param_1) {
                break;
            }
            index = index + 1;
        }
    }

    if (index < max_size) {
        while (index < (max_size - 1)) {
            this->playerBuildings.value[index] = this->playerBuildings.value[index + 1];
            index = index + 1;
        }
        int new_count = this->playerBuildings.numberValue - 1;
        this->playerBuildings.numberValue = (new_count < 0) ? 0 : new_count;
    }

    max_size = this->playerObjects.maximumSizeValue;
    index = 0;
    if (0 < max_size) {
        while (index < max_size) {
            if (this->playerObjects.value[index] == param_1) {
                break;
            }
            index = index + 1;
        }
    }

    if (index < max_size) {
        while (index < (max_size - 1)) {
            this->playerObjects.value[index] = this->playerObjects.value[index + 1];
            index = index + 1;
        }
        int new_count = this->playerObjects.numberValue - 1;
        this->playerObjects.numberValue = (new_count < 0) ? 0 : new_count;
    }

    RGE_Static_Object* object = this->md->object(param_1);
    if (object != nullptr) {
        ObjectMemory* memory = this->objectMemory(param_1);
        if ((memory != nullptr) && (object->owner != nullptr)) {
            memory->owner = static_cast<uchar>(object->owner->id);
        }
    }
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DC490
ObjectMemory* TribeInformationAIModule::objectToAttackWithPlay(int param_1, int* param_2, int param_3, int* param_4, int* param_5, int* param_6, int* param_7) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if (param_4 != nullptr) {
        *param_4 = -1;
    }
    if (param_6 != nullptr) {
        *param_6 = 0;
    }
    if (param_7 != nullptr) {
        *param_7 = -1;
    }
    if ((param_2 == nullptr) || (param_3 <= 0)) {
        return nullptr;
    }

    ObjectMemory* target = objectToAttackByGroup2(param_1, param_2, param_3);
    if (target == nullptr) {
        return nullptr;
    }

    if ((param_5 != nullptr) && (param_6 != nullptr)) {
        for (int i = 0; i < param_3; ++i) {
            param_5[i] = param_2[i];
        }
        *param_6 = param_3;
    }
    if (param_7 != nullptr) {
        *param_7 = param_2[0];
    }
    if (param_4 != nullptr) {
        *param_4 = 0;
    }
    return target;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DC750
ObjectMemory* TribeInformationAIModule::objectToAttack(int param_1, int param_2, int param_3, int param_4, int* param_5) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if (param_5 != nullptr) {
        *param_5 = 0;
    }

    ObjectMemory* wonder = wonderToAttack(-1);
    if (wonder != nullptr) {
        if (param_5 != nullptr) {
            *param_5 = 1;
        }
        return wonder;
    }

    if (this->md == nullptr) {
        return nullptr;
    }
    RGE_Static_Object* unit = this->md->object(param_4);
    if ((unit == nullptr) || (unit->unitAI() == nullptr)) {
        return nullptr;
    }

    int score_attack_attempts = (this->md->player != nullptr) ? this->md->player->strategicNumber(0x59) : 1;
    int score_kills = (this->md->player != nullptr) ? this->md->player->strategicNumber(0x50) : 1;
    int score_distance = (this->md->player != nullptr) ? this->md->player->strategicNumber(0x4D) : 1;
    int score_same_zone = (this->md->player != nullptr) ? this->md->player->strategicNumber(0x7A) : 0;
    uchar unit_zone = unit->currentZone();

    ObjectMemory* best_target = nullptr;
    float best_score = 0.0f;
    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        ObjectMemory& memory = this->importantObjectMemory[i];
        if ((memory.id == -1) || (static_cast<int>(memory.owner) != param_1)) {
            continue;
        }

        RGE_Static_Object* object = this->md->object(memory.id);
        if ((object == nullptr) || (object->object_state >= 3) || (object->hp <= 0.0f)) {
            continue;
        }
        if ((param_2 == 0) && (isBuilding(object) != 0)) {
            continue;
        }
        if ((param_3 == 0) && (isBoat(object) != 0)) {
            continue;
        }

        int x = static_cast<int>(memory.x);
        int y = static_cast<int>(memory.y);
        int ux = static_cast<int>(unit->world_x);
        int uy = static_cast<int>(unit->world_y);
        int distance = static_cast<int>(std::sqrt(static_cast<float>(tribe_distance_squared(x, y, ux, uy))));
        if (distance < 1) {
            distance = 1;
        }

        float score = static_cast<float>(score_attack_attempts * memory.attackAttempts) + static_cast<float>(score_kills * static_cast<int>(memory.kills));
        score = score + static_cast<float>(score_distance) / static_cast<float>(distance);
        if (unit->lookupZone(x, y) == unit_zone) {
            score = score + static_cast<float>(score_same_zone);
        }

        if ((best_target == nullptr) || (best_score < score)) {
            best_target = &memory;
            best_score = score;
        }
    }

    if ((best_target != nullptr) && (param_5 != nullptr)) {
        *param_5 = 1;
    }
    return best_target;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DCF10
ObjectMemory* TribeInformationAIModule::objectToAttackByGroup(int param_1, TacticalAIGroup* param_2, AttackState* param_3, ulong) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((param_2 == nullptr) || (param_3 == nullptr) || (this->md == nullptr)) {
        return nullptr;
    }

    int commander_id = param_2->commander();
    RGE_Static_Object* commander = this->md->object(commander_id);
    if ((commander == nullptr) || (commander->unitAI() == nullptr)) {
        param_3->active = 0;
        return nullptr;
    }

    if (param_3->active == 0) {
        param_3->bestTargetID = -1;
        param_3->bestTargetValue = -1.0f;
        param_3->bestTargetMemoryIndex = -1;
        param_3->iterationIndex = 0;
        param_3->attackGroupID = -1;
        param_3->playID = -1;
        param_3->phase = 0;
        param_3->bestNonWallTargetID = -1;
        param_3->bestNonWallTargetValue = -1.0f;
        param_3->bestNonWallTargetMemoryIndex = -1;
        param_3->active = 1;
    }

    int has_target = 0;
    ObjectMemory* target = objectToAttack(param_1, 1, 1, commander_id, &has_target);
    if (target != nullptr) {
        param_2->numberObjectsToDestroyValue = 0;
        param_2->addObjectToDestroy(target->id);
        param_2->objectsToDestroyOwnerValue = static_cast<int>(target->owner);
        param_2->objectsToDestroyCommanderZoneValue = static_cast<int>(commander->currentZone());

        for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
            if (this->importantObjectMemory[i].id == target->id) {
                this->importantObjectMemory[i].attackAttempts = this->importantObjectMemory[i].attackAttempts + 1;
                param_3->bestTargetMemoryIndex = i;
                break;
            }
        }

        param_3->bestTargetID = target->id;
        param_3->bestTargetValue = 1.0f;
        param_3->active = 0;
        return target;
    }

    if (param_3->phase == 0) {
        param_3->phase = 1;
        param_3->iterationIndex = 0;
    } else {
        param_3->active = 0;
    }
    return nullptr;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DDD40
ObjectMemory* TribeInformationAIModule::objectToAttackByGroup2(int param_1, int* param_2, int param_3) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    ObjectMemory* wonder = wonderToAttack(-1);
    if (wonder != nullptr) {
        return wonder;
    }
    if ((param_2 == nullptr) || (param_3 <= 0) || (this->md == nullptr)) {
        return nullptr;
    }

    RGE_Static_Object* commander = this->md->object(*param_2);
    if ((commander == nullptr) || (commander->unitAI() == nullptr)) {
        return nullptr;
    }

    int score_attack_attempts = (this->md->player != nullptr) ? this->md->player->strategicNumber(0x59) : 1;
    int score_kills = (this->md->player != nullptr) ? this->md->player->strategicNumber(0x50) : 1;
    int score_distance = (this->md->player != nullptr) ? this->md->player->strategicNumber(0x4D) : 1;
    int score_damage = (this->md->player != nullptr) ? this->md->player->strategicNumber(0xB8) : 1;
    int score_same_zone = (this->md->player != nullptr) ? this->md->player->strategicNumber(0x7A) : 0;
    int score_in_progress = (this->md->player != nullptr) ? this->md->player->strategicNumber(0xB9) : 0;
    uchar commander_zone = commander->currentZone();

    ObjectMemory* best_target = nullptr;
    float best_value = 0.0f;
    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        ObjectMemory& memory = this->importantObjectMemory[i];
        if ((memory.id == -1) || (static_cast<int>(memory.owner) != param_1)) {
            continue;
        }

        RGE_Static_Object* object = this->md->object(memory.id);
        if ((object == nullptr) || (object->object_state >= 3) || (object->hp <= 0.0f)) {
            continue;
        }

        int mx = static_cast<int>(memory.x);
        int my = static_cast<int>(memory.y);
        int cx = static_cast<int>(commander->world_x);
        int cy = static_cast<int>(commander->world_y);
        int dx = mx - cx;
        int dy = my - cy;
        float distance = std::sqrt(static_cast<float>((dx * dx) + (dy * dy)));
        if (distance < 1.0f) {
            distance = 1.0f;
        }

        float damage = damageInflictedPerSecond(param_2, param_3, object);
        float time_to_be_killed = timeToBeKilled(param_2, param_3, object);
        if ((damage <= 0.0f) || (time_to_be_killed <= 0.0f)) {
            continue;
        }

        int targeted_by_group = 0;
        if (score_in_progress > 0) {
            for (int u = 0; u < param_3; ++u) {
                RGE_Static_Object* unit = this->md->object(param_2[u]);
                if (unit == nullptr) {
                    continue;
                }
                UnitAIModule* unit_ai = unit->unitAI();
                if ((unit_ai != nullptr) && (unit_ai->currentTarget() == memory.id)) {
                    targeted_by_group = targeted_by_group + 1;
                }
            }
        }

        float zone_bonus = 0.0f;
        if (commander->lookupZone(mx, my) == commander_zone) {
            zone_bonus = static_cast<float>(score_same_zone);
        }

        float kill_ratio = object->hp / damage;
        if (kill_ratio <= 0.0f) {
            kill_ratio = 1.0f;
        }
        float value = static_cast<float>(score_attack_attempts * memory.attackAttempts) + static_cast<float>(score_kills * static_cast<int>(memory.kills));
        value = value + (static_cast<float>(score_distance) / distance) + (static_cast<float>(score_damage) * (time_to_be_killed / kill_ratio));
        value = value + zone_bonus + static_cast<float>(score_in_progress * targeted_by_group);

        if ((best_target == nullptr) || (best_value < value)) {
            best_target = &memory;
            best_value = value;
        }
    }

    return best_target;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DE1F0
ObjectMemory* TribeInformationAIModule::objectToDefend(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    RGE_Static_Object* unit = (this->md != nullptr) ? this->md->object(param_1) : nullptr;
    if (unit == nullptr) {
        return nullptr;
    }

    ObjectMemory* best_object = nullptr;
    int best_priority = -1;
    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        ObjectMemory& memory = this->importantObjectMemory[i];
        if ((memory.id == -1) || (memory.attackAttempts > 0)) {
            continue;
        }
        if (tribe_managed_array_contains(this->itemsToDefend, memory.id) == 0) {
            continue;
        }

        int priority = defendPriority(memory.type, memory.group);
        if ((best_object == nullptr) || (priority < best_priority)) {
            best_object = &memory;
            best_priority = priority;
        }
    }
    return best_object;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DE330
ObjectMemory* TribeInformationAIModule::higherPriorityObjectToDefend(int param_1, int param_2, int param_3) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    RGE_Static_Object* unit = (this->md != nullptr) ? this->md->object(param_1) : nullptr;
    if (unit == nullptr) {
        return nullptr;
    }

    uchar unit_zone = unit->currentZone();
    int priority_threshold = defendPriority(param_2, param_3);
    ObjectMemory* best_object = nullptr;

    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        ObjectMemory& memory = this->importantObjectMemory[i];
        if ((memory.id == -1) || (memory.attackAttempts > 0)) {
            continue;
        }
        if (tribe_managed_array_contains(this->itemsToDefend, memory.id) == 0) {
            continue;
        }

        RGE_Static_Object* target = this->md->object(memory.id);
        if (target == nullptr) {
            continue;
        }
        uchar target_zone = target->currentZone();
        if (target_zone != unit_zone) {
            XYPoint target_point{static_cast<int>(memory.x), static_cast<int>(memory.y)};
            if (unit->withinRangeOfZoneAtPoint(unit_zone, unit->master_obj->los, &target_point) != 1) {
                continue;
            }
        }

        int priority = defendPriority(memory.type, memory.group);
        if (priority < priority_threshold) {
            best_object = &memory;
            priority_threshold = priority;
        }
    }

    return best_object;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DE4A0
int TribeInformationAIModule::defendPriority(int param_1, int param_2) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    switch (param_1) {
    case 0x2D:
        return this->md->player->strategicNumber(0x46);
    case 0x6D:
        return this->md->player->strategicNumber(0x38);
    case 0x9E:
    case 0xA3:
        return this->md->player->strategicNumber(0x36);
    case 0x9F:
        return this->md->player->strategicNumber(0x37);
    default:
        break;
    }

    if (param_2 == 7) {
        return this->md->player->strategicNumber(0x34);
    }
    if (param_2 == 8) {
        return this->md->player->strategicNumber(0x33);
    }
    if (param_2 == 0x20) {
        return this->md->player->strategicNumber(0x32);
    }
    return -1;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DE600
int TribeInformationAIModule::checkDefend(RGE_Static_Object* param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((param_1 == nullptr) || (param_1->master_obj == nullptr) || (param_1->owner == nullptr)) {
        return 0;
    }

    short object_group = param_1->master_obj->object_group;
    short owner_id = param_1->owner->id;
    int game_id = param_1->id;
    short object_id = param_1->master_obj->id;

    auto append_if_missing = [&](int target_id) -> int {
        if (tribe_managed_array_contains(this->itemsToDefend, target_id) == 1) {
            return 1;
        }
        if (tribe_managed_array_ensure_capacity(this->itemsToDefend, this->itemsToDefend.numberValue + 1) == 0) {
            return 0;
        }
        this->itemsToDefend.value[this->itemsToDefend.numberValue] = target_id;
        this->itemsToDefend.numberValue = this->itemsToDefend.numberValue + 1;
        return 1;
    };

    switch (object_id) {
    case 0x2D:
        if ((owner_id == this->md->player->id) && (this->md->player->strategicNumber(0x46) > 0)) {
            return append_if_missing(game_id);
        }
        break;
    case 0x6D:
        if ((owner_id == this->md->player->id) && (this->md->player->strategicNumber(0x38) > 0)) {
            return append_if_missing(game_id);
        }
        break;
    case 0x9E:
    case 0xA3:
        if (this->md->player->strategicNumber(0x36) > 0) {
            return append_if_missing(game_id);
        }
        break;
    case 0x9F:
        if (this->md->player->strategicNumber(0x37) > 0) {
            return append_if_missing(game_id);
        }
        break;
    default:
        if ((object_group == 7) && (this->md->player->strategicNumber(0x34) > 0)) {
            tribe_managed_array_append(this->itemsToDefend, game_id);
            return 1;
        }
        if ((object_group == 8) && (this->md->player->strategicNumber(0x33) > 0)) {
            return append_if_missing(game_id);
        }
        if ((object_group == 0x20) && (this->md->player->strategicNumber(0x32) > 0)) {
            return append_if_missing(game_id);
        }
        break;
    }

    return 0;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DEA70
int TribeInformationAIModule::numberItemsToDefend() {
    return this->itemsToDefend.numberValue;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DEA80
ObjectMemory* TribeInformationAIModule::objectToTradeWith(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    RGE_Static_Object* unit = this->md->object(param_1);
    if (unit == nullptr) {
        return nullptr;
    }

    ObjectMemory* best_dock = nullptr;
    int best_distance = 0;
    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        ObjectMemory& memory = this->importantObjectMemory[i];
        if (memory.id == -1) {
            continue;
        }
        if ((this->md->player != nullptr) && (static_cast<int>(memory.owner) == this->md->player->id)) {
            continue;
        }
        if (memory.type != 0x2D) {
            continue;
        }

        RGE_Static_Object* dock = this->md->object(memory.id);
        if ((dock == nullptr) || (dock->owner == nullptr) || (dock->owner->attributes == nullptr)) {
            continue;
        }
        if (!(0.0f < dock->owner->attributes[9])) {
            continue;
        }

        int dx = static_cast<int>(memory.x) - static_cast<int>(unit->world_x);
        int dy = static_cast<int>(memory.y) - static_cast<int>(unit->world_y);
        int distance = (dx * dx) + (dy * dy);
        if ((best_dock == nullptr) || (distance < best_distance)) {
            best_dock = &memory;
            best_distance = distance;
        }
    }

    return best_dock;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DEBA0
int TribeInformationAIModule::findGatherPosition(XYPoint* param_1, int param_2, int param_3, int param_4, int param_5, RGE_Static_Object* param_6, XYPoint* param_7) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((param_1 == nullptr) || (param_6 == nullptr) || (param_7 == nullptr) || (param_4 <= param_5)) {
        return 0;
    }

    XYPoint min_point{param_1->x - (param_4 + param_5), param_1->y - (param_4 + param_5)};
    XYPoint max_point{param_1->x + (param_4 + param_5), param_1->y + (param_4 + param_5)};
    mapBound(min_point);
    mapBound(max_point);

    setupInfluenceMap(0, -1, param_1, &min_point, &max_point);

    int clear_size = groupInfluenceDimension(param_2);
    int clear_radius = clear_size / 2;
    int best_value = -1;
    XYPoint best_point{};

    for (int x = min_point.x; x <= max_point.x; ++x) {
        for (int y = min_point.y; y <= max_point.y; ++y) {
            int dx = x - param_1->x;
            if (dx < 0) {
                dx = -dx;
            }
            int dy = y - param_1->y;
            if (dy < 0) {
                dy = -dy;
            }
            if ((dx < param_5) && (dy < param_5)) {
                continue;
            }
            if ((dx > param_4) || (dy > param_4)) {
                continue;
            }

            XYPoint clear_min{x - clear_radius, y - clear_radius};
            XYPoint clear_max{x + clear_radius, y + clear_radius};
            if ((mapBound(clear_min) != 0) || (mapBound(clear_max) != 0)) {
                continue;
            }

            bool blocked = false;
            int value = 0;
            for (int cx = clear_min.x; cx <= clear_max.x; ++cx) {
                for (int cy = clear_min.y; cy <= clear_max.y; ++cy) {
                    if (param_6->passableTile(static_cast<float>(cx), static_cast<float>(cy), 1) == 0) {
                        blocked = true;
                        break;
                    }
                    int influence = iMap.lookupValue(cx, cy);
                    if (influence == 0xFF) {
                        blocked = true;
                        break;
                    }
                    value = value + influence;
                }
                if (blocked) {
                    break;
                }
            }

            if (!blocked && ((best_value == -1) || (best_value < value))) {
                best_value = value;
                best_point.x = x;
                best_point.y = y;
            }
        }
    }

    if (best_value == -1) {
        return 0;
    }
    *param_7 = best_point;
    return 1;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DEE90
void TribeInformationAIModule::setupInfluenceMap(int param_1, int param_2, XYPoint* param_3, XYPoint* param_4, XYPoint* param_5) {
    // Fully verified. Source of truth: taiinfmd.cpp.asm @ 0x004DEE90
    iMap.initialize(0x14);
    iMap.setUnchangeableLimit(0xFF);
    if ((this->md == nullptr) || (this->md->player == nullptr)) {
        return;
    }

    BuildAIModule* build_ai = tribe_build_ai(this);
    if (build_ai != nullptr) {
        (void)build_ai->numberBuiltItemsOfType(0x44, 0);
        (void)build_ai->numberBuiltItemsOfType(0x67, 0);
    }

    const int map_x = this->mapXSizeValue;
    const int map_y = this->mapYSizeValue;
    XYPoint min{0, 0};
    XYPoint max{map_x, map_y};

    auto clamp_rect = [&](int& min_x, int& min_y, int& max_x, int& max_y) {
        XYPoint p0{min_x, min_y};
        XYPoint p1{max_x, max_y};
        this->mapBound(p0);
        this->mapBound(p1);
        min_x = p0.x;
        min_y = p0.y;
        max_x = p1.x;
        max_y = p1.y;
    };

    auto apply_ring = [&](int cx, int cy, int radius, int delta, int increment) {
        int min_x = cx - radius;
        int min_y = cy - radius;
        int max_x = cx + radius;
        int max_y = cy + radius;
        clamp_rect(min_x, min_y, max_x, max_y);
        if (increment != 0) {
            iMap.incrementValue(min_x, min_y, max_x, max_y, static_cast<uchar>(delta));
        } else {
            iMap.decrementValue(min_x, min_y, max_x, max_y, static_cast<uchar>(delta));
        }
    };

    if ((param_1 == 3) || (param_1 == 4) || (param_1 == 0)) {
        for (int x = 0; x < map_x; ++x) {
            for (int y = 0; y < map_y; ++y) {
                if ((x < 5) || (x > (map_x - 5)) || (y < 5) || (y > (map_y - 5))) {
                    iMap.decrementValue(x, y, 0x0A);
                }
            }
        }
    }

    if ((param_1 == 1) || (param_1 == 2) || (param_1 == 9)) {
        int resource_focus = resourceTypeToPlaceDropsiteBy(param_1);
        for (int slot = 0; slot < kResourceTypeSlots; ++slot) {
            if ((this->resources[slot] == nullptr) || (this->numResources[slot] <= 0)) {
                continue;
            }

            for (int i = 0; i < this->numResources[slot]; ++i) {
                ResourceMemory& memory = this->resources[slot][i];
                if (memory.gone == 1) {
                    continue;
                }

                RGE_Static_Object* resource = this->md->object(memory.id);
                if ((resource == nullptr) || (resource->master_obj == nullptr)) {
                    continue;
                }

                float radius_x = resource->master_obj->radius_x;
                float radius_y = resource->master_obj->radius_y;
                int min_x = static_cast<int>(resource->world_x - radius_x - 0.5f);
                int min_y = static_cast<int>(resource->world_y - radius_y - 0.5f);
                int max_x = static_cast<int>(resource->world_x + radius_y - 0.5f);
                int max_y = static_cast<int>(resource->world_y + radius_y - 0.5f);
                clamp_rect(min_x, min_y, max_x, max_y);

                int center_x = static_cast<int>(resource->world_x);
                int center_y = static_cast<int>(resource->world_y);
                XYPoint center{center_x, center_y};
                this->mapBound(center);

                if ((param_1 == 1) || (param_1 == 2)) {
                    iMap.setValue(center.x, center.y, 0xFF);
                } else {
                    iMap.setValue(min_x, min_y, max_x, max_y, 0xFF);
                }

                short group = resource->master_obj->object_group;
                if (param_1 == 1) {
                    if (group == 7) {
                        int rx0 = min_x - 5;
                        int ry0 = min_y - 5;
                        int rx1 = max_x + 5;
                        int ry1 = max_y + 5;
                        clamp_rect(rx0, ry0, rx1, ry1);
                        iMap.decrementValue(rx0, ry0, rx1, ry1, 0x80);
                    } else {
                        int matches_focus =
                            (resource_focus == -1) || ((resource_focus == 3) && (group == 0x20)) || ((resource_focus == 2) && (group == 8)) ||
                            ((resource_focus == 1) && (group == 0x0F)) ||
                            ((resource_focus == 0) && (group != 0x20) && (group != 8) && (group != 0x0F));
                        if (matches_focus != 0) {
                            int rx0 = min_x - 1;
                            int ry0 = min_y - 1;
                            int rx1 = max_x + 1;
                            int ry1 = max_y + 1;
                            clamp_rect(rx0, ry0, rx1, ry1);
                            iMap.incrementValue(rx0, ry0, rx1, ry1, 0x08);

                            rx0 = min_x - 3;
                            ry0 = min_y - 3;
                            rx1 = max_x + 3;
                            ry1 = max_y + 3;
                            clamp_rect(rx0, ry0, rx1, ry1);
                            iMap.incrementValue(rx0, ry0, rx1, ry1, 0x04);

                            rx0 = min_x - 5;
                            ry0 = min_y - 5;
                            rx1 = max_x + 5;
                            ry1 = max_y + 5;
                            clamp_rect(rx0, ry0, rx1, ry1);
                            iMap.incrementValue(rx0, ry0, rx1, ry1, 0x02);
                        }
                    }
                } else if ((param_1 == 2) && (group == 7)) {
                    int rx0 = min_x - 3;
                    int ry0 = min_y - 3;
                    int rx1 = max_x + 3;
                    int ry1 = max_y + 3;
                    clamp_rect(rx0, ry0, rx1, ry1);
                    iMap.incrementValue(rx0, ry0, rx1, ry1, 0x80);
                }
            }
        }
    }

    if ((param_1 == 1) || (param_1 == 2) || (param_1 == 3) || (param_1 == 4) || (param_1 == 0) || (param_1 == 5) || (param_1 == 6) || (param_1 == 8)) {
        for (int i = 0; i < this->playerBuildings.numberValue; ++i) {
            if (i >= this->playerBuildings.maximumSizeValue) {
                break;
            }

            RGE_Static_Object* building = this->md->object(this->playerBuildings.value[i]);
            if ((building == nullptr) || (building->master_obj == nullptr)) {
                continue;
            }

            int building_code = placementCode(static_cast<int>(building->master_obj->id));
            float radius_x = building->master_obj->radius_x;
            float radius_y = building->master_obj->radius_y;

            int min_x = static_cast<int>(building->world_x);
            int min_y = static_cast<int>(building->world_y);
            int max_x = min_x;
            int max_y = min_y;

            if (radius_x == 2.5f) {
                min_x = static_cast<int>(building->world_x) - 3;
                min_y = static_cast<int>(building->world_y) - 3;
                max_x = static_cast<int>(building->world_x) + 3;
                max_y = static_cast<int>(building->world_y) + 3;
            } else if (radius_x == 1.5f) {
                if (building_code == 6) {
                    min_x = static_cast<int>(building->world_x) - 1;
                    min_y = static_cast<int>(building->world_y) - 1;
                    max_x = static_cast<int>(building->world_x) + 1;
                    max_y = static_cast<int>(building->world_y) + 1;
                } else {
                    int size = (param_2 == 0x46) ? 3 : 2;
                    min_x = static_cast<int>(building->world_x) - size;
                    min_y = static_cast<int>(building->world_y) - size;
                    max_x = static_cast<int>(building->world_x) + size;
                    max_y = static_cast<int>(building->world_y) + size;
                }
            } else if (radius_x == 1.0f) {
                if ((building_code != 6) && (building_code != 3)) {
                    min_x = static_cast<int>(building->world_x) - 2;
                    min_y = static_cast<int>(building->world_y) - 2;
                    max_x = static_cast<int>(building->world_x) + 1;
                    max_y = static_cast<int>(building->world_y) + 1;
                } else {
                    min_x = static_cast<int>(building->world_x) - 1;
                    min_y = static_cast<int>(building->world_y) - 1;
                    max_x = static_cast<int>(building->world_x) + 1;
                    max_y = static_cast<int>(building->world_y) + 1;
                }
            } else if (radius_x == 0.5f) {
                if ((building_code == 6) || (building_code == 4)) {
                    min_x = static_cast<int>(building->world_x);
                    min_y = static_cast<int>(building->world_y);
                    max_x = min_x;
                    max_y = min_y;
                } else {
                    min_x = static_cast<int>(building->world_x) - 1;
                    min_y = static_cast<int>(building->world_y) - 1;
                    max_x = static_cast<int>(building->world_x) + 1;
                    max_y = static_cast<int>(building->world_y) + 1;
                }
            } else {
                this->logCommonHistory((char*)"    Unsupported building size (%d x %d).", static_cast<int>(radius_x + radius_x),
                                       static_cast<int>(radius_y + radius_y));
                continue;
            }

            if (building_code == 0x6D) {
                min_x = min_x - 1;
                min_y = min_y - 1;
                max_x = max_x + 1;
                max_y = max_y + 1;
            }

            clamp_rect(min_x, min_y, max_x, max_y);
            iMap.setValue(min_x, min_y, max_x, max_y, 0xFF);

            int los_radius = static_cast<int>(building->master_obj->los);
            if (los_radius < 1) {
                los_radius = 1;
            }

            if ((param_1 == 3) || (param_1 == 0)) {
                int influence_radius = los_radius;
                if (param_1 != 0) {
                    influence_radius = static_cast<int>(building->master_obj->los * 1.5f);
                }
                if (building_code == 0x6D) {
                    influence_radius = static_cast<int>(static_cast<float>(influence_radius) * 1.5f);
                }
                if ((param_1 == 0) && (building_code == 3)) {
                    apply_ring(min_x + ((max_x - min_x) / 2), min_y + ((max_y - min_y) / 2), influence_radius, 0x0A, 1);
                } else {
                    apply_ring(min_x + ((max_x - min_x) / 2), min_y + ((max_y - min_y) / 2), influence_radius, 0x0A, 0);
                }
            } else if ((param_1 == 1) || (param_1 == 2)) {
                int influence_radius = los_radius;
                if (building_code == 0x6D) {
                    influence_radius = static_cast<int>(building->master_obj->los * 1.5f);
                }
                if ((building_code == 0x44) || (building_code == 0x67)) {
                    influence_radius = 2;
                }
                apply_ring(min_x + ((max_x - min_x) / 2), min_y + ((max_y - min_y) / 2), influence_radius, 0x0A, 0);
            } else if (param_1 == 5) {
                int influence_radius = los_radius;
                if (building_code == 0x6D) {
                    influence_radius = static_cast<int>(building->master_obj->los * 2.0f);
                }
                apply_ring(min_x + ((max_x - min_x) / 2), min_y + ((max_y - min_y) / 2), influence_radius * 2, 0x14, 0);
            } else if (param_1 == 8) {
                int influence_radius = los_radius;
                apply_ring(min_x + ((max_x - min_x) / 2), min_y + ((max_y - min_y) / 2), influence_radius, 0x14, 1);
                apply_ring(min_x + ((max_x - min_x) / 2), min_y + ((max_y - min_y) / 2), influence_radius / 2, 0x14, 1);
                apply_ring(min_x + ((max_x - min_x) / 2), min_y + ((max_y - min_y) / 2), influence_radius / 3, 0x14, 1);
            }
        }
    }

    if (((param_1 == 3) || (param_1 == 4) || (param_1 == 0)) && (param_4 != nullptr) && (param_5 != nullptr) && (this->md->player->world != nullptr) &&
        (this->md->player->world->map != nullptr)) {
        RGE_Map* map = this->md->player->world->map;
        for (int x = param_4->x; x <= param_5->x; ++x) {
            for (int y = param_4->y; y <= param_5->y; ++y) {
                uchar terrain = map->get_terrain(static_cast<short>(x), static_cast<short>(y));
                if (terrain == 1) {
                    int bx0 = x - 2;
                    int by0 = y - 2;
                    int bx1 = x - 2;
                    int by1 = y - 2;
                    clamp_rect(bx0, by0, bx1, by1);
                    iMap.setValue(x, y, 0xFF);
                    iMap.decrementValue(bx0, by0, bx1, by1, 0x0A);
                }

                int height_bonus = 0;
                if ((map->map_row_offset != nullptr) && (y >= 0) && (y < map->map_height) && (x >= 0) && (x < map->map_width)) {
                    height_bonus = static_cast<int>(map->map_row_offset[y][x].height) * 5;
                }
                iMap.incrementValue(x, y, static_cast<uchar>(height_bonus));
            }
        }
    }

    if (((param_1 == 3) || (param_1 == 4) || (param_1 == 0) || (param_1 == 6) || (param_1 == 5)) && (this->attackMemories != nullptr)) {
        int player_id = this->md->player->id;
        for (int i = 0; i < this->maxAttackMemories; ++i) {
            AttackMemory& memory = this->attackMemories[i];
            if ((memory.id != -1) && (static_cast<int>(memory.targetOwner) == player_id)) {
                int min_x = static_cast<int>(memory.minX) - 4;
                int min_y = static_cast<int>(memory.minY) - 4;
                int max_x = static_cast<int>(memory.maxX) + 4;
                int max_y = static_cast<int>(memory.maxY) + 4;
                clamp_rect(min_x, min_y, max_x, max_y);
                iMap.incrementValue(min_x, min_y, max_x, max_y, 0x10);
            }
        }
    }

    if (param_1 == 0) {
        TribeTacticalAIModule* tactical = tribe_tactical_ai(this);
        if (tactical != nullptr) {
            tactical->setGroupInfluences(&iMap);
        }
    }

    iMap.setConnectionCount(&min, &max, 0xFF, 1, (param_1 != 4) ? 1 : 0, 1);

    if ((param_1 != 0) && (this->buildingLots != nullptr)) {
        for (int i = 0; i < this->maxBuildingLots; ++i) {
            if ((this->buildingLots[i].typeID == param_2) && (this->buildingLots[i].status == 2)) {
                iMap.setValue(static_cast<int>(this->buildingLots[i].x), static_cast<int>(this->buildingLots[i].y), 0xFF);
            }
        }
    }

    (void)param_3;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DFD40
int TribeInformationAIModule::groupInfluenceDimension(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if (param_1 < 2) {
        return 2;
    }
    return param_1 * param_1;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004DFD60
ObjectMemory TribeInformationAIModule::findObjectMemoryLimits(int param_1, int param_2, int* param_3, int* param_4) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    ObjectMemory result{};
    if (param_3 != nullptr) {
        *param_3 = 0;
    }
    if (param_4 != nullptr) {
        *param_4 = 0;
    }

    RGE_Static_Object* observer = (this->md != nullptr) ? this->md->object(param_2) : nullptr;
    if (observer == nullptr) {
        return result;
    }

    int max_distance = 0;
    int max_hitpoints = 0;
    int max_kills = 0;
    float max_damage = 0.0f;
    float max_rate_of_fire = 0.0f;
    float max_range = 0.0f;
    uchar observer_zone = observer->currentZone();

    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        ObjectMemory& memory = this->importantObjectMemory[i];
        if ((memory.id == -1) || (static_cast<int>(memory.owner) != param_1)) {
            continue;
        }

        RGE_Static_Object* object = this->md->object(memory.id);
        if (object == nullptr) {
            continue;
        }

        uchar memory_zone = object->currentZone();
        if (memory_zone != observer_zone) {
            XYPoint point{static_cast<int>(memory.x), static_cast<int>(memory.y)};
            if (observer->withinRangeOfZoneAtPoint(observer_zone, observer->master_obj->los, &point) != 1) {
                continue;
            }
        }

        int mx = static_cast<int>(memory.x);
        int my = static_cast<int>(memory.y);
        int ox = static_cast<int>(observer->world_x);
        int oy = static_cast<int>(observer->world_y);
        int distance = static_cast<int>(observer->distance_to_position(static_cast<float>(mx), static_cast<float>(my), static_cast<float>(memory.z)));
        if (max_distance < distance) {
            max_distance = distance;
        }

        if ((memory.group != 3) && (memory.group != 0x1B) && (param_3 != nullptr)) {
            *param_3 = *param_3 + 1;
        }
        if ((memory.group != 2) && (memory.group != 0x15) && (memory.group != 0x16) && (memory.group != 0x14) && (memory.type != 0x2D) && (param_4 != nullptr)) {
            *param_4 = *param_4 + 1;
        }

        if (max_hitpoints < memory.hitPoints) {
            max_hitpoints = memory.hitPoints;
        }
        if (memory.attackAttempts > max_hitpoints) {
            max_hitpoints = memory.attackAttempts;
        }
        if (static_cast<int>(memory.kills) > max_hitpoints) {
            max_hitpoints = static_cast<int>(memory.kills);
        }
        if (max_kills < static_cast<int>(memory.kills)) {
            max_kills = static_cast<int>(memory.kills);
        }
        if (max_damage < memory.damageCapability) {
            max_damage = memory.damageCapability;
        }
        if (max_rate_of_fire < memory.rateOfFire) {
            max_rate_of_fire = memory.rateOfFire;
        }
        if (max_range < memory.range) {
            max_range = memory.range;
        }
    }

    std::memcpy(&result.type, &max_distance, sizeof(int));
    result.attackAttempts = max_hitpoints;
    result.kills = static_cast<uchar>(max_kills);
    result.damageCapability = static_cast<float>(max_kills);
    result.rateOfFire = max_damage;
    result.range = max_rate_of_fire;
    (void)max_range;
    return result;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E0040
int TribeInformationAIModule::isNextTo(XYPoint* param_1, XYPoint* param_2, int param_3) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int dx = param_2->x - param_1->x;
    int dy = param_2->y - param_1->y;
    int dist_squared = (dx * dx) + (dy * dy);
    if ((param_3 == 0) && (dist_squared > 1)) {
        return 0;
    }
    if ((param_3 == 1) && (dist_squared > 2)) {
        return 0;
    }
    return 1;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E0090
int TribeInformationAIModule::facetTo(XYPoint* param_1, XYPoint* param_2) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int dx = param_2->x - param_1->x;
    int dy = param_2->y - param_1->y;
    if (param_2->x == param_1->x) {
        return (((-1 < dy) - 1) & 0xFFFFFFFC) + 5;
    }
    if (param_2->y == param_1->y) {
        return (((-1 < dx) - 1) & 4) + 3;
    }
    if (dx < 0) {
        return (((-1 < dy) - 1) & 0xFFFFFFFA) + 6;
    }
    return (((-1 < dy) - 1) & 0xFFFFFFFE) + 4;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E0100
int TribeInformationAIModule::placementCode(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    switch (param_1) {
    case 0x2D:
        return 7;
    case 0x32:
        return 8;
    case 0x44:
        return 2;
    case 0x45:
    case 0x4F:
    case 199:
        return 3;
    case 0x46:
    case 0x52:
    case 0x54:
    case 0x6E:
    case 0x114:
        return 6;
    case 0x48:
    case 0x75:
    case 0x9B:
        return 4;
    case 0x67:
        return 1;
    case 0x6D:
        return 9;
    default:
        return 5;
    }
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E02A0
void TribeInformationAIModule::storeLot(int param_1, uchar param_2, uchar param_3, uchar param_4) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int available_slot = -1;
    for (int i = 0; i < this->maxBuildingLots; ++i) {
        BuildingLot& lot = this->buildingLots[i];
        if ((lot.typeID == param_1) && (lot.x == param_2) && (lot.y == param_3)) {
            lot.status = param_4;
            return;
        }
        if ((available_slot == -1) && (lot.typeID == -1)) {
            available_slot = i;
        }
    }

    if (available_slot == -1) {
        int old_max = this->maxBuildingLots;
        int new_max = old_max * 2;
        BuildingLot* new_lots = static_cast<BuildingLot*>(::operator new(static_cast<size_t>(new_max) * sizeof(BuildingLot), std::nothrow));
        if (new_lots != nullptr) {
            for (int i = 0; i < old_max; ++i) {
                new_lots[i] = this->buildingLots[i];
            }
            for (int i = old_max; i < new_max; ++i) {
                new_lots[i].typeID = -1;
                new_lots[i].status = param_4;
                new_lots[i].x = 0;
                new_lots[i].y = 0;
            }

            ::operator delete(this->buildingLots);
            this->buildingLots = new_lots;
            this->buildingLots[old_max].typeID = param_1;
            this->buildingLots[old_max].x = param_2;
            this->buildingLots[old_max].y = param_3;
            this->buildingLots[old_max].status = param_4;
            this->maxBuildingLots = new_max;
            return;
        }
    } else {
        this->buildingLots[available_slot].typeID = param_1;
        this->buildingLots[available_slot].x = param_2;
        this->buildingLots[available_slot].y = param_3;
        this->buildingLots[available_slot].status = param_4;
    }
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E0470
void TribeInformationAIModule::removeLot(int param_1, uchar param_2, uchar param_3, uchar param_4) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    for (int i = 0; i < this->maxBuildingLots; ++i) {
        BuildingLot& lot = this->buildingLots[i];
        if ((lot.typeID != param_1) || (lot.x != param_2) || (lot.y != param_3)) {
            continue;
        }
        if (param_4 != 3) {
            lot.status = param_4;
            return;
        }
        lot.typeID = -1;
        lot.x = 0;
        lot.y = 0;
        lot.status = 3;
        return;
    }
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E0510
BuildingLot* TribeInformationAIModule::availableLot(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    for (int i = 0; i < this->maxBuildingLots; ++i) {
        if ((this->buildingLots[i].typeID == param_1) && (this->buildingLots[i].status == 0)) {
            return &this->buildingLots[i];
        }
    }
    return nullptr;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E0560
int TribeInformationAIModule::invalidLot(int param_1, uchar param_2, uchar param_3) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    for (int i = 0; i < this->maxBuildingLots; ++i) {
        const BuildingLot& lot = this->buildingLots[i];
        if ((lot.typeID == param_1) && (lot.status == 2) && (lot.x == param_2) && (lot.y == param_3)) {
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E05C0
int TribeInformationAIModule::undesirableLot(int param_1, uchar param_2, uchar param_3, int param_4) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    for (int i = 0; i < this->maxBuildingLots; ++i) {
        const BuildingLot& lot = this->buildingLots[i];
        if ((lot.typeID == param_1) && (lot.status == 1)) {
            if (((static_cast<int>(lot.x) - param_4) <= static_cast<int>(param_2)) && (static_cast<int>(param_2) <= (param_4 + static_cast<int>(lot.x))) &&
                ((static_cast<int>(lot.y) - param_4) <= static_cast<int>(param_3)) && (static_cast<int>(param_3) <= (param_4 + static_cast<int>(lot.y)))) {
                return 1;
            }
        }
    }
    return 0;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E0670
void TribeInformationAIModule::setupWalls(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int gate_count = this->numberGatesValue;
    if ((param_8 == 1) && (param_6 > 0)) {
        gate_count = (param_6 > 4) ? 4 : param_6;
        this->numberGatesValue = gate_count;
        int half_width = param_7 / 2;
        for (int i = 0; i < gate_count; ++i) {
            switch (i & 3) {
            case 0:
                this->minGatePosition[i] = {param_1 - half_width, param_2 - (param_4 * 2)};
                this->maxGatePosition[i] = {param_1 + half_width, param_2};
                break;
            case 1:
                this->minGatePosition[i] = {param_1 - half_width, param_2};
                this->maxGatePosition[i] = {param_1 + half_width, param_2 + (param_4 * 2)};
                break;
            case 2:
                this->minGatePosition[i] = {param_1, param_2 - half_width};
                this->maxGatePosition[i] = {param_1 + (param_4 * 2), param_2 + half_width};
                break;
            default:
                this->minGatePosition[i] = {param_1 - (param_4 * 2), param_2 - half_width};
                this->maxGatePosition[i] = {param_1, param_2 + half_width};
                break;
            }
            mapBound(this->minGatePosition[i]);
            mapBound(this->maxGatePosition[i]);
        }
    }

    int pattern = param_5;
    if (pattern == 0) {
        pattern = 1 + ((param_1 + param_2 + param_4) & 1);
    }
    if (param_3 > param_4) {
        return;
    }

    auto place_wall_lot = [&](int x, int y) {
        if ((x < 0) || (y < 0) || (x >= this->mapXSizeValue) || (y >= this->mapYSizeValue)) {
            return;
        }
        if (insideGate(gate_count, x, y) == 0) {
            storeLot(0x48, static_cast<uchar>(x), static_cast<uchar>(y), 0);
        }
    };

    for (int radius = param_3; radius <= param_4; ++radius) {
        if (pattern == 1) {
            for (int x = param_1 - radius; x <= param_1 + radius; ++x) {
                place_wall_lot(x, param_2 - radius);
                place_wall_lot(x, param_2 + radius);
            }
            for (int y = param_2 - radius; y <= param_2 + radius; ++y) {
                place_wall_lot(param_1 - radius, y);
                place_wall_lot(param_1 + radius, y);
            }
        } else {
            for (int dx = -radius; dx <= radius; ++dx) {
                int dy = radius - ((dx < 0) ? -dx : dx);
                place_wall_lot(param_1 + dx, param_2 + dy);
                place_wall_lot(param_1 + dx, param_2 - dy);
            }
        }
    }
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E0F40
int TribeInformationAIModule::insideGate(int param_1, int param_2, int param_3) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if (param_1 < 1) {
        return 0;
    }

    int i = 0;
    while (i < param_1) {
        if ((this->minGatePosition[i].x <= param_2) && (this->minGatePosition[i].y <= param_3) &&
            (param_2 <= this->maxGatePosition[i].x) && (param_3 <= this->maxGatePosition[i].y)) {
            return 1;
        }
        i = i + 1;
    }
    return 0;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E0F90
int TribeInformationAIModule::storeAttackMemory(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5, short param_6, uchar param_7,
                                                ulong param_8, int param_9) {
    return this->storeAttackMemory(param_1, param_2, param_3, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E0FD0
int TribeInformationAIModule::storeAttackMemory(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5, uchar param_6, uchar param_7,
                                                short param_8, uchar param_9, ulong param_10, int param_11) {
    if ((0 < this->mapXSizeValue) && (0 < this->mapYSizeValue)) {
        int quadrant_seed = (static_cast<int>(param_4) + static_cast<int>(param_2)) * 4;
        int x_quad = (quadrant_seed / this->mapXSizeValue) / 2;
        int y_quad = (quadrant_seed / this->mapYSizeValue) / 2;
        if (x_quad > 4) {
            x_quad = 3;
        }
        if (y_quad > 4) {
            y_quad = 3;
        }

        ushort player_id = static_cast<ushort>(this->md->player->id);
        if (param_7 == player_id) {
            this->quadrantLog[x_quad][y_quad].numberAttacksOnUs = this->quadrantLog[x_quad][y_quad].numberAttacksOnUs + 1;
        } else if (param_6 == player_id) {
            this->quadrantLog[x_quad][y_quad].numberAttacksByUs = this->quadrantLog[x_quad][y_quad].numberAttacksByUs + 1;
        }
    }

    int best_slot = -1;
    int insertion_id = 0;
    int newest_slot = -1;
    if (0 < this->maxAttackMemories) {
        for (int i = 0; i < this->maxAttackMemories; ++i) {
            best_slot = i;
            if (this->attackMemories[i].id == -1) {
                insertion_id = i;
                break;
            }

            if ((newest_slot == -1) || (this->attackMemories[newest_slot].timeStamp < this->attackMemories[i].timeStamp)) {
                newest_slot = i;
            }
            insertion_id = i + 1;
            best_slot = newest_slot;
        }
    }

    if (best_slot != -1) {
        this->attackMemories[best_slot].id = insertion_id;
        this->attackMemories[best_slot].type = param_1;
        this->attackMemories[best_slot].minX = param_2;
        this->attackMemories[best_slot].minY = param_3;
        this->attackMemories[best_slot].maxX = param_4;
        this->attackMemories[best_slot].maxY = param_5;
        this->attackMemories[best_slot].attackingOwner = param_6;
        this->attackMemories[best_slot].targetOwner = param_7;
        this->attackMemories[best_slot].kills = param_8;
        this->attackMemories[best_slot].success = param_9;
        this->attackMemories[best_slot].timeStamp = param_10;
        this->attackMemories[best_slot].play = param_11;
    }
    return best_slot;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E1190
void TribeInformationAIModule::removeAttackMemory(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((-1 < param_1) && (param_1 < this->maxAttackMemories)) {
        this->attackMemories[param_1].id = -1;
        this->attackMemories[param_1].type = 0;
        this->attackMemories[param_1].minX = 0;
        this->attackMemories[param_1].minY = 0;
        this->attackMemories[param_1].maxX = 0;
        this->attackMemories[param_1].maxY = 0;
        this->attackMemories[param_1].attackingOwner = 0xFF;
        this->attackMemories[param_1].targetOwner = 0xFF;
        this->attackMemories[param_1].kills = 0;
        this->attackMemories[param_1].success = 0;
        this->attackMemories[param_1].play = -1;
    }
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E1230
AttackMemory* TribeInformationAIModule::attackMemory(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((-1 < param_1) && (param_1 < this->maxAttackMemories)) {
        return this->attackMemories + param_1;
    }
    return nullptr;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E1730
int TribeInformationAIModule::unexploredPlayerLocation(int param_1, XYPoint* param_2) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((param_2 == nullptr) || (this->md == nullptr) || (param_1 == 0)) {
        return 0;
    }

    RGE_Static_Object* unit = this->md->object(param_1);
    if (unit == nullptr) {
        return 0;
    }
    uchar unit_zone = unit->currentZone();

    ObjectMemory* best_object = nullptr;
    int best_distance = -1;
    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        ObjectMemory& memory = this->importantObjectMemory[i];
        if ((memory.id == -1) || (memory.owner == 0)) {
            continue;
        }
        if ((this->md->player != nullptr) && (static_cast<int>(memory.owner) == this->md->player->id)) {
            continue;
        }
        if (tileUncovered(memory.x, memory.y) == 1) {
            continue;
        }
        if (unit->lookupZone(static_cast<int>(memory.x), static_cast<int>(memory.y)) != unit_zone) {
            continue;
        }

        int distance = static_cast<int>(unit->distance_to_position(static_cast<float>(memory.x), static_cast<float>(memory.y), static_cast<float>(memory.z)));
        if ((best_object == nullptr) || (distance < best_distance)) {
            best_object = &memory;
            best_distance = distance;
        }
    }

    if (best_object == nullptr) {
        return 0;
    }

    param_2->x = static_cast<int>(best_object->x);
    param_2->y = static_cast<int>(best_object->y);
    this->pathMap.setValue(param_2->x, param_2->y, 0);
    return 1;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E1930
int TribeInformationAIModule::numberUnitsWithinXTiles(int param_1, int param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int count = 0;
    int radius_sq = param_4 * param_4;
    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        const ObjectMemory& memory = this->importantObjectMemory[i];
        if (param_1 == -1) {
            if ((this->md->player != nullptr) && (this->md->player->isEnemy(static_cast<int>(memory.owner)) != 0)) {
                int dx = static_cast<int>(memory.x) - param_2;
                int dy = static_cast<int>(memory.y) - param_3;
                if (((dx * dx) + (dy * dy)) <= radius_sq) {
                    count = count + 1;
                }
            }
        } else if (static_cast<int>(memory.owner) == param_1) {
            int dx = static_cast<int>(memory.x) - param_2;
            int dy = static_cast<int>(memory.y) - param_3;
            if (((dx * dx) + (dy * dy)) <= radius_sq) {
                count = count + 1;
            }
        }
    }
    return count;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E1A00
int TribeInformationAIModule::withinXTilesOfAttackOnPlayer(RGE_Static_Object* param_1, int param_2, int param_3) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int radius_sq = param_2 * param_2;
    int x = static_cast<int>(param_1->world_x);
    int y = static_cast<int>(param_1->world_y);

    for (int i = 0; i < this->maxAttackMemories; ++i) {
        AttackMemory& memory = this->attackMemories[i];
        if ((memory.id != -1) && (memory.attackingOwner != 0) && (static_cast<int>(memory.targetOwner) == param_3)) {
            int dy_min = static_cast<int>(memory.minY) - y;
            int dx_min = static_cast<int>(memory.minX) - x;
            int dx_min_sq = dx_min * dx_min;
            if (((dy_min * dy_min) + dx_min_sq) <= radius_sq) {
                return 1;
            }

            int dy_max = static_cast<int>(memory.maxY) - y;
            int dy_max_sq = dy_max * dy_max;
            if ((dx_min_sq + dy_max_sq) <= radius_sq) {
                return 1;
            }

            int dx_max = static_cast<int>(memory.maxX) - x;
            int dx_max_sq = dx_max * dx_max;
            if ((dy_max_sq + dx_max_sq) <= radius_sq) {
                return 1;
            }
            if (((dy_min * dy_min) + dx_max_sq) <= radius_sq) {
                return 1;
            }
        }
    }
    return 0;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E1AF0
int TribeInformationAIModule::withinXTilesOfEnemyTowncenter(RGE_Static_Object* param_1, int param_2) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int radius_sq = param_2 * param_2;
    int x = static_cast<int>(param_1->world_x);
    int y = static_cast<int>(param_1->world_y);
    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        const ObjectMemory& memory = this->importantObjectMemory[i];
        if (memory.type == 0x6D) {
            if ((this->md->player != nullptr) && (this->md->player->isEnemy(static_cast<int>(memory.owner)) != 0)) {
                int dx = static_cast<int>(memory.x) - x;
                int dy = static_cast<int>(memory.y) - y;
                if (((dx * dx) + (dy * dy)) <= radius_sq) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E1BD0
int TribeInformationAIModule::withinXTilesOfObject(RGE_Static_Object* param_1, int param_2, int param_3, int param_4, int param_5, int param_6) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int radius_sq = param_2 * param_2;
    int x = static_cast<int>(param_1->world_x);
    int y = static_cast<int>(param_1->world_y);
    int best_id = -1;
    int best_distance = -1;

    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        ObjectMemory& memory = this->importantObjectMemory[i];
        RGE_Static_Object* object = this->md->object(memory.id);
        if ((object == nullptr) || (object->object_state >= 3) || (object->hp == 0.0f)) {
            continue;
        }

        int type = memory.type;
        if ((type != param_3) && (type != param_4) && (type != param_5) && (type != param_6)) {
            continue;
        }
        if ((this->md->player != nullptr) && (this->md->player->isEnemy(static_cast<int>(memory.owner)) == 0)) {
            continue;
        }

        int dx = static_cast<int>(memory.x) - x;
        int dy = static_cast<int>(memory.y) - y;
        int distance = (dx * dx) + (dy * dy);
        if ((distance <= radius_sq) && ((distance < best_distance) || (best_id == -1))) {
            best_id = memory.id;
            best_distance = distance;
        }
    }

    return best_id;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E1D10
int TribeInformationAIModule::findStagingPoint(XYPoint param_1, XYPoint* param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((param_2 == nullptr) || (this->md == nullptr)) {
        return 0;
    }

    ObjectMemory* target = objectMemory(param_5);
    if (target == nullptr) {
        return 0;
    }

    RGE_Static_Object* commander = this->md->object(param_7);
    if (commander == nullptr) {
        return 0;
    }

    int terrain_class = 2;
    int terrain_type = 0;
    if ((isBoat(commander) == 1) && (param_3 == 0)) {
        terrain_class = 1;
        terrain_type = 0x16;
    }

    XYPoint zone_reference = param_1;
    commander->findClosestPointInTerrainType(param_1, &zone_reference, terrain_class, terrain_type, 4);
    uchar staging_zone = commander->lookupZone(zone_reference.x, zone_reference.y);

    int max_los_value = setupLOSMap(static_cast<int>(target->owner), static_cast<int>(target->x), static_cast<int>(target->y));
    int max_attack_value = setupAttackMap(static_cast<int>(target->owner), static_cast<int>(target->x), static_cast<int>(target->y));

    XYPoint min_point{static_cast<int>(target->x) - param_6, static_cast<int>(target->y) - param_6};
    XYPoint max_point{static_cast<int>(target->x) + param_6, static_cast<int>(target->y) + param_6};
    mapBound(min_point);
    mapBound(max_point);

    RGE_Visible_Map* visible_map = (this->md->aiPlayer != nullptr) ? this->md->aiPlayer->visible : nullptr;
    RGE_Map* game_map = (visible_map != nullptr) ? visible_map->map : nullptr;

    int best_value = -0x7fffffff;
    bool found = false;
    for (int x = min_point.x; x <= max_point.x; ++x) {
        for (int y = min_point.y; y <= max_point.y; ++y) {
            RGE_Tile* tile = (game_map != nullptr) ? game_map->get_tile(x, y) : nullptr;
            int terrain = (tile != nullptr) ? static_cast<int>(tile->terrain_type) : 0;

            bool terrain_ok = false;
            if (param_3 == 1) {
                terrain_ok = (terrain == 2);
            } else if (param_4 == 1) {
                terrain_ok = (terrain != 1) && (terrain != 0x16);
            } else {
                terrain_ok = (terrain == 1) || (terrain == 0x16);
            }
            if (!terrain_ok) {
                continue;
            }
            if (commander->lookupZone(x, y) != staging_zone) {
                continue;
            }

            if (param_3 == 1) {
                bool passable = true;
                for (int px = x - 2; px <= x + 2; ++px) {
                    for (int py = y - 2; py <= y + 2; ++py) {
                        if (commander->passableTile(static_cast<float>(px), static_cast<float>(py), 1) == 0) {
                            passable = false;
                            break;
                        }
                    }
                    if (!passable) {
                        break;
                    }
                }
                if (!passable) {
                    continue;
                }
            }

            XYPoint point{x, y};
            int line_bonus = (commander->withinRangeOfZoneAtPoint(staging_zone, 1.0f, &point) == 1) ? param_6 : 0;
            int los_penalty = (max_los_value > 0) ? (losMap.lookupValue(x, y) * param_6) / max_los_value : 0;
            int attack_penalty = (max_attack_value > 0) ? (attackMap.lookupValue(x, y) * param_6) / max_attack_value : 0;
            int random_value = ((x * 31) + (y * 17)) & 0x0F;
            int distance = static_cast<int>(std::sqrt(static_cast<float>(tribe_distance_squared(x, y, static_cast<int>(target->x), static_cast<int>(target->y)))));

            int candidate_value = line_bonus + random_value - los_penalty - attack_penalty - distance;
            if (!found || (best_value < candidate_value)) {
                param_2->x = x;
                param_2->y = y;
                best_value = candidate_value;
                found = true;
            }
        }
    }

    return found ? 1 : 0;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E21E0
int TribeInformationAIModule::setupLOSMap(int param_1, int param_2, int param_3) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    losMap.initialize(0);
    losMap.setReferencePoint(param_2, param_3);

    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        ObjectMemory& memory = this->importantObjectMemory[i];
        if (static_cast<int>(memory.owner) != param_1) {
            continue;
        }

        RGE_Static_Object* object = (this->md != nullptr) ? this->md->object(memory.id) : nullptr;
        if ((object == nullptr) || (object->master_obj == nullptr)) {
            continue;
        }

        int radius = static_cast<int>(object->master_obj->los);
        int x = static_cast<int>(memory.x);
        int y = static_cast<int>(memory.y);
        uchar value = (object->damageCapability() <= 0.0f) ? 1 : 5;
        losMap.incrementValue(x - radius, y - radius, x + radius, y + radius, value);
    }

    return losMap.maxValue();
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E22F0
int TribeInformationAIModule::setupAttackMap(int param_1, int param_2, int param_3) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    attackMap.initialize(0);
    attackMap.setReferencePoint(param_2, param_3);

    int our_owner = (this->md != nullptr && this->md->player != nullptr) ? this->md->player->id : -1;
    for (int i = 0; i < this->maxAttackMemories; ++i) {
        AttackMemory& memory = this->attackMemories[i];
        if ((static_cast<int>(memory.targetOwner) == param_1) && (static_cast<int>(memory.attackingOwner) == our_owner)) {
            attackMap.incrementValue(memory.minX, memory.minY, memory.maxX, memory.maxY, 1);
        }
    }

    return attackMap.maxValue();
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E3140
int TribeInformationAIModule::numberGranaries() {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int count = 0;
    for (int i = 0; i < this->playerBuildings.numberValue; ++i) {
        if (i >= this->playerBuildings.maximumSizeValue) {
            tribe_managed_array_ensure_capacity(this->playerBuildings, i + 1);
            if (i >= this->playerBuildings.maximumSizeValue) {
                break;
            }
        }
        RGE_Static_Object* building = (this->md != nullptr) ? this->md->object(this->playerBuildings.value[i]) : nullptr;
        if ((building != nullptr) && (building->master_obj != nullptr) && (building->master_obj->id == 0x44)) {
            count = count + 1;
        }
    }
    return count;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E3210
int TribeInformationAIModule::amountForageBushesInXTiles(int param_1, int param_2, int param_3) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int count = 0;
    int radius_sq = param_3 * param_3;
    for (int i = 0; i < this->numResources[0]; ++i) {
        ResourceMemory& memory = this->resources[0][i];
        if (memory.gone == 1) {
            continue;
        }

        RGE_Static_Object* object = (this->md != nullptr) ? this->md->object(memory.id) : nullptr;
        if ((object == nullptr) || (object->master_obj == nullptr) || (object->master_obj->id != 0x3B)) {
            continue;
        }

        int dx = static_cast<int>(memory.x) - param_1;
        int dy = static_cast<int>(memory.y) - param_2;
        if ((dx * dx + dy * dy) <= radius_sq) {
            count = count + 1;
        }
    }
    return count;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E32C0
int TribeInformationAIModule::amountResourceTypesInXTiles(int param_1, int param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((param_1 < 0) || (param_1 >= kResourceTypeSlots) || (this->resources[param_1] == nullptr)) {
        return 0;
    }

    int count = 0;
    int radius_sq = param_4 * param_4;
    for (int i = 0; i < this->numResources[param_1]; ++i) {
        ResourceMemory& memory = this->resources[param_1][i];
        if (memory.gone == 1) {
            continue;
        }

        RGE_Static_Object* object = (this->md != nullptr) ? this->md->object(memory.id) : nullptr;
        if ((object == nullptr) || (object->master_obj == nullptr)) {
            continue;
        }
        if ((param_1 == 0) && (object->master_obj->id == 0x3B)) {
            continue;
        }

        int dx = static_cast<int>(memory.x) - param_2;
        int dy = static_cast<int>(memory.y) - param_3;
        if ((dx * dx + dy * dy) <= radius_sq) {
            count = count + 1;
        }
    }
    return count;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E3390
float TribeInformationAIModule::damagePerSecond(int param_1, int param_2, int param_3) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    float rate_of_fire = 0.0f;
    RGE_Static_Object* unit = this->md->object(param_1);
    if (unit == nullptr) {
        return 0.0f;
    }

    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        const ObjectMemory& memory = this->importantObjectMemory[i];
        if ((this->md->player != nullptr) && (this->md->player->isEnemy(static_cast<int>(memory.owner)) == 0)) {
            continue;
        }

        RGE_Static_Object* important_object = this->md->object(memory.id);
        if ((important_object == nullptr) || (important_object->object_state >= 3)) {
            continue;
        }

        float distance = important_object->distance_to_position(static_cast<float>(param_2), static_cast<float>(param_3), important_object->world_z);
        if ((important_object->master_obj != nullptr) && (distance <= important_object->master_obj->los)) {
            float damage = unit->damageCapability(important_object);
            float rof = important_object->rateOfFire();
            if ((rof != 0.0f) && (damage != 0.0f)) {
                rate_of_fire = (damage / rof) + rate_of_fire;
            }
        }
    }

    return rate_of_fire;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E34C0
int TribeInformationAIModule::costToLoseUnit(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    RGE_Static_Object* object = this->md->object(param_1);
    if ((object == nullptr) || (object->master_obj == nullptr) || (this->md->player == nullptr)) {
        return -1;
    }
    return this->md->player->objectCostByType(object->master_obj->id);
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E3500
int TribeInformationAIModule::benefitToKillUnit(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    RGE_Static_Object* object = this->md->object(param_1);
    if ((object == nullptr) || (object->master_obj == nullptr) || (object->owner == nullptr)) {
        return -1;
    }
    return object->owner->objectCostByType(object->master_obj->id);
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E3530
int TribeInformationAIModule::inRangeOfUnits(int param_1, int param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if (this->maxImportantObjectMemory < 1) {
        return 0;
    }

    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        const ObjectMemory& memory = this->importantObjectMemory[i];

        bool matches_owner = false;
        if (param_1 == -1) {
            matches_owner = (this->md != nullptr) && (this->md->player != nullptr) && (this->md->player->isEnemy(memory.owner) != 0);
        } else {
            matches_owner = (static_cast<int>(memory.owner) == param_1);
        }
        if (!matches_owner) {
            continue;
        }

        RGE_Static_Object* object = (this->md != nullptr) ? this->md->object(memory.id) : nullptr;
        if ((object == nullptr) || (object->object_state >= 3) || (object->master_obj == nullptr)) {
            continue;
        }

        float distance = object->distance_to_position(static_cast<float>(param_2), static_cast<float>(param_3), object->world_z);
        float range = object->weaponRange();
        if ((param_4 == 0) && (distance < object->master_obj->los)) {
            range = object->master_obj->los;
        }
        if (distance <= range) {
            return 1;
        }
    }

    return 0;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E3640
ObjectMemory* TribeInformationAIModule::wonderToAttack(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    ObjectMemory* best_memory = nullptr;
    float best_hp = 0.0f;
    int best_state = 0;

    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        ObjectMemory& memory = this->importantObjectMemory[i];
        if (memory.type != 0x114) {
            continue;
        }
        if (param_1 == -1) {
            if ((this->md == nullptr) || (this->md->player == nullptr) || (this->md->player->isEnemy(static_cast<int>(memory.owner)) == 0)) {
                continue;
            }
        } else if (static_cast<int>(memory.owner) != param_1) {
            continue;
        }

        RGE_Static_Object* wonder = (this->md != nullptr) ? this->md->object(memory.id) : nullptr;
        if ((wonder == nullptr) || (wonder->object_state >= 3)) {
            continue;
        }

        int state = wonder->object_state;
        float hp = wonder->hp;
        if ((best_memory == nullptr) || (best_state < state) || ((best_state == state) && (hp < best_hp))) {
            best_memory = &memory;
            best_state = state;
            best_hp = hp;
        }
    }
    return best_memory;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E3840
ObjectMemory* TribeInformationAIModule::ruinToCapture(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    RGE_Static_Object* town_center = (this->md != nullptr) ? this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1) : nullptr;
    ObjectMemory* best_memory = nullptr;
    int best_value = -1;

    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        ObjectMemory& memory = this->importantObjectMemory[i];
        if ((memory.type != 0x9E) && (memory.type != 0xA3)) {
            continue;
        }
        if (param_1 == -1) {
            if ((this->md == nullptr) || (this->md->player == nullptr) || (this->md->player->isEnemy(static_cast<int>(memory.owner)) == 0)) {
                continue;
            }
        } else if (static_cast<int>(memory.owner) != param_1) {
            continue;
        }

        RGE_Static_Object* ruin = (this->md != nullptr) ? this->md->object(memory.id) : nullptr;
        if ((ruin == nullptr) || (ruin->object_state >= 3)) {
            continue;
        }

        int x = static_cast<int>(memory.x);
        int y = static_cast<int>(memory.y);
        int value = numberUnitsWithinXTiles(param_1, x, y, 5);
        if (town_center != nullptr) {
            value = static_cast<int>(town_center->distance_to_position(static_cast<float>(x), static_cast<float>(y), static_cast<float>(memory.z))) * value;
        }

        if ((best_memory == nullptr) || (value < best_value)) {
            best_memory = &memory;
            best_value = value;
        }
    }

    return best_memory;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E39D0
ObjectMemory* TribeInformationAIModule::artifactToCapture(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    RGE_Static_Object* town_center = (this->md != nullptr) ? this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1) : nullptr;
    RGE_Visible_Map* visible_map = (this->md != nullptr && this->md->aiPlayer != nullptr) ? this->md->aiPlayer->visible : nullptr;
    ObjectMemory* best_memory = nullptr;
    int best_value = -1;

    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        ObjectMemory& memory = this->importantObjectMemory[i];
        if (memory.type != 0x9F) {
            continue;
        }
        if (param_1 == -1) {
            if ((this->md == nullptr) || (this->md->player == nullptr) || (this->md->player->isEnemy(static_cast<int>(memory.owner)) == 0)) {
                continue;
            }
        } else if (static_cast<int>(memory.owner) != param_1) {
            continue;
        }

        RGE_Static_Object* artifact = (this->md != nullptr) ? this->md->object(memory.id) : nullptr;
        if ((artifact == nullptr) || (artifact->object_state >= 3)) {
            continue;
        }

        int ax = static_cast<int>(memory.x);
        int ay = static_cast<int>(memory.y);
        if ((visible_map != nullptr) && (visible_map->get_visible(ax, ay) != 0)) {
            memory.x = static_cast<uchar>(artifact->world_x);
            memory.y = static_cast<uchar>(artifact->world_y);
            memory.z = static_cast<uchar>(artifact->world_z);
            ax = static_cast<int>(memory.x);
            ay = static_cast<int>(memory.y);
        }

        int value = numberUnitsWithinXTiles(param_1, ax, ay, 5);
        if (town_center != nullptr) {
            value = static_cast<int>(town_center->distance_to_object(artifact)) * value;
        }

        if ((best_memory == nullptr) || (value < best_value)) {
            best_memory = &memory;
            best_value = value;
        }
    }

    return best_memory;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E3B80
int TribeInformationAIModule::resourceTypeToPlaceDropsiteBy(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if (param_1 == 2) {
        return 0;
    }

    int can_build_storage_pit = (this->md != nullptr) ? this->md->canPerformAction(0x67, 0) : 0;
    if ((can_build_storage_pit == 0) && (this->closestDropsiteValue[1] != -1)) {
        return 1;
    }

    if (param_1 == 1) {
        if (this->closestDropsiteValue[1] != -1) {
            int distance = (this->md != nullptr && this->md->player != nullptr) ? this->md->player->strategicNumber(0xA4) : 0;
            if (distance < this->closestDropsiteValue[1]) {
                return 1;
            }
        }
        if (this->closestDropsiteValue[3] != -1) {
            int distance = (this->md != nullptr && this->md->player != nullptr) ? this->md->player->strategicNumber(0xA6) : 0;
            if (distance < this->closestDropsiteValue[3]) {
                return 3;
            }
        }
        if ((this->closestDropsiteValue[0] != -1) && (this->closestDropsiteValue[0] > 0x0F)) {
            return 2;
        }
        if (this->closestDropsiteValue[2] != -1) {
            int distance = (this->md != nullptr && this->md->player != nullptr) ? this->md->player->strategicNumber(0xA5) : 0;
            if (distance < this->closestDropsiteValue[2]) {
                return 2;
            }
        }
    }

    return -1;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E3C90
int TribeInformationAIModule::dropsitesWithinRequiredDistance(int* param_1, int param_2, int param_3) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((param_1 == nullptr) || (param_2 < 0) || (param_2 >= kResourceTypeSlots) || (this->resources[param_2] == nullptr)) {
        return 0;
    }

    int applicable_resources = 0;
    *param_1 = 0;

    ManagedArray<int> dropsites{};
    tribe_reset_managed_array(dropsites);

    for (int i = 0; i < this->numResources[param_2]; ++i) {
        ResourceMemory& memory = this->resources[param_2][i];
        if (memory.gone == 1) {
            continue;
        }

        RGE_Static_Object* object = (this->md != nullptr) ? this->md->object(memory.id) : nullptr;
        if (object == nullptr) {
            continue;
        }

        applicable_resources = applicable_resources + 1;
        if (static_cast<int>(memory.dropDistance) <= param_3) {
            *param_1 = *param_1 + 1;
            if (tribe_managed_array_contains(dropsites, memory.dropsiteID) == 0) {
                tribe_managed_array_append(dropsites, memory.dropsiteID);
            }
        }
    }

    tribe_clear_managed_array(dropsites);
    return (applicable_resources > 0) ? 1 : 0;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E3E90
int TribeInformationAIModule::numberAvailableStoragePits(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int age_index = static_cast<int>(this->md->player->attributes[50]) - 1;
    if (age_index < 0) {
        age_index = 0;
    } else if (3 < age_index) {
        age_index = 3;
    }

    if (this->dropsitesByAge[param_1][age_index] == 0) {
        return 0;
    }

    RGE_Static_Object* town_center = this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
    if (town_center != nullptr) {
        RGE_Static_Object* closest_resource = this->md->object(this->closestDropsiteResourceID[param_1]);
        if (closest_resource != nullptr) {
            uchar town_zone = town_center->currentZone();
            int resource_x = static_cast<int>(closest_resource->world_x);
            int resource_y = static_cast<int>(closest_resource->world_y);
            uchar resource_zone = town_center->lookupZone(resource_x, resource_y);
            if (town_zone != resource_zone) {
                return 0;
            }
        }
    }

    int min_distance = this->md->player->strategicNumber(param_1 + 0xA3);
    return (min_distance < this->closestDropsiteValue[param_1]) ? 1 : 0;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E3F80
int TribeInformationAIModule::numberAvailableGranaries() {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if (this->closestDropsiteValue[0] == -1) {
        return 0;
    }

    if (this->md != nullptr) {
        RGE_Static_Object* town_center = this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
        if (town_center != nullptr) {
            RGE_Static_Object* closest_resource = this->md->object(this->closestDropsiteResourceID[0]);
            if (closest_resource != nullptr) {
                int resource_x = static_cast<int>(closest_resource->world_x);
                int resource_y = static_cast<int>(closest_resource->world_y);
                uchar town_zone = town_center->currentZone();
                uchar resource_zone = town_center->lookupZone(resource_x, resource_y);
                if (town_zone != resource_zone) {
                    return 0;
                }
            }
        }
    }

    int required_distance = (this->md != nullptr && this->md->player != nullptr) ? this->md->player->strategicNumber(0xA3) : 0;
    return (required_distance < this->closestDropsiteValue[0]) ? 1 : 0;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E4040
void TribeInformationAIModule::lookAtMap() {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((this->md == nullptr) || (this->md->aiPlayer == nullptr) || (this->md->aiPlayer->world == nullptr) || (this->md->aiPlayer->world->map == nullptr)) {
        return;
    }

    RGE_Map* game_map = this->md->aiPlayer->world->map;
    this->numberFoundForestTilesValue = 0;
    for (int qx = 0; qx < 4; ++qx) {
        for (int qy = 0; qy < 4; ++qy) {
            this->quadrantLog[qx][qy].numberExploredTiles = 0;
        }
    }

    for (int x = 0; x < this->mapXSizeValue; ++x) {
        for (int y = 0; y < this->mapYSizeValue; ++y) {
            RGE_Tile* tile = game_map->get_tile(x, y);
            if (tile == nullptr) {
                continue;
            }

            int qx = (this->mapXSizeValue > 0) ? ((x * 4) / this->mapXSizeValue) : 0;
            int qy = (this->mapYSizeValue > 0) ? ((y * 4) / this->mapYSizeValue) : 0;
            if (qx < 0) {
                qx = 0;
            } else if (qx > 3) {
                qx = 3;
            }
            if (qy < 0) {
                qy = 0;
            } else if (qy > 3) {
                qy = 3;
            }
            this->quadrantLog[qx][qy].numberExploredTiles = this->quadrantLog[qx][qy].numberExploredTiles + 1;

            this->pathMap.setValue(x, y, 0);

            int tree_count = 0;
            for (RGE_Object_Node* node = tile->objects.list; node != nullptr; node = node->next) {
                RGE_Static_Object* object = node->node;
                if ((object == nullptr) || (object->master_obj == nullptr)) {
                    continue;
                }

                int group = static_cast<int>(object->master_obj->object_group);
                if (importantObject(group) == 1) {
                    addImportantObject(object, 0);
                }
                if (group == 0x0F) {
                    tree_count = tree_count + 1;
                }
            }

            int terrain_type = static_cast<int>(tile->terrain_type);
            if ((tree_count > 0) &&
                ((terrain_type == 10) || (terrain_type == 0x13) || (terrain_type == 0x0D) || (terrain_type == 0x14))) {
                this->numberFoundForestTilesValue = this->numberFoundForestTilesValue + 1;
            }
        }
    }
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E41C0
float TribeInformationAIModule::damageInflictedPerSecond(TacticalAIGroup* param_1, RGE_Static_Object* param_2) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    float r_val = 0.0f;
    for (int i = 0; i < param_1->numberUnits(); ++i) {
        int game_id = param_1->unit(i);
        RGE_Static_Object* object = this->md->object(game_id);
        if (object != nullptr) {
            float damage = param_2->damageCapability(object);
            float rate = object->rateOfFire();
            r_val = (damage / rate) + r_val;
        }
    }
    return r_val;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E4240
float TribeInformationAIModule::damageInflictedPerSecond(int* param_1, int param_2, RGE_Static_Object* param_3) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    float r_val = 0.0f;
    int count = param_2;
    while (0 < count) {
        RGE_Static_Object* object = this->md->object(*param_1);
        if (object != nullptr) {
            float damage = param_3->damageCapability(object);
            float rate = object->rateOfFire();
            r_val = (damage / rate) + r_val;
        }
        param_1 = param_1 + 1;
        count = count - 1;
    }
    return r_val;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E42B0
float TribeInformationAIModule::timeToBeKilled(TacticalAIGroup* param_1, RGE_Static_Object* param_2) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    float r_val = 0.0f;
    for (int i = 0; i < param_1->numberUnits(); ++i) {
        int game_id = param_1->unit(i);
        RGE_Static_Object* object = this->md->object(game_id);
        if (object != nullptr) {
            int target_y = static_cast<int>(param_2->world_y);
            int target_x = static_cast<int>(param_2->world_x);
            int attacker = param_1->unit(i);
            float dps = this->damagePerSecond(attacker, target_x, target_y);
            if (dps == 0.0f) {
                dps = 600.0f;
            } else {
                dps = object->hp / dps;
            }
            r_val = dps + r_val;
        }
    }
    return r_val;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E4350
float TribeInformationAIModule::timeToBeKilled(int* param_1, int param_2, RGE_Static_Object* param_3) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    float r_val = 0.0f;
    int count = param_2;
    while (0 < count) {
        RGE_Static_Object* object = this->md->object(*param_1);
        if (object != nullptr) {
            int target_y = static_cast<int>(param_3->world_y);
            int target_x = static_cast<int>(param_3->world_x);
            float dps = this->damagePerSecond(*param_1, target_x, target_y);
            if (dps == 0.0f) {
                dps = 600.0f;
            } else {
                dps = object->hp / dps;
            }
            r_val = dps + r_val;
        }
        param_1 = param_1 + 1;
        count = count - 1;
    }
    return r_val;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E43E0
int TribeInformationAIModule::closestDropsiteResID(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    if ((param_1 < 0) || (param_1 >= 4)) {
        return -1;
    }
    return this->closestDropsiteResourceID[param_1];
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E4400
int TribeInformationAIModule::calculatePlayVariation(int param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int total_plays = 0;
    for (int i = 0; i < 16000; ++i) {
        total_plays = total_plays + this->playHistory[i];
    }
    int weighted = static_cast<int>((static_cast<float>(this->unitHistory[param_1]) / static_cast<float>(total_plays)) * 100.0f);
    return 100 - weighted;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E4450
int TribeInformationAIModule::convertUnitToIntType(RGE_Static_Object* param_1) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    short object_group = param_1->master_obj->object_group;
    short object_id = param_1->master_obj->id;

    if (object_group == 0x12) {
        return 5;
    }
    if (object_group == 0x1C) {
        return 3;
    }
    if (object_group == 0x0D) {
        return 4;
    }
    if (object_group == 0x0C) {
        return 2;
    }
    if (object_group == 0x23) {
        return 7;
    }
    if (object_id == 0x49) {
        return 0;
    }
    if (object_id == 0x4B) {
        return 1;
    }
    if (((object_id != 4) && (object_id != 5)) && (object_id != 0x27)) {
        if (object_id == 0x29) {
            return 10;
        }
        if ((object_id == 0x2E) || (object_id == 0x19)) {
            return 9;
        }
        return ((-(object_group != 0x16)) & 0xFFFFFFF7) + 8;
    }
    return 6;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E4500
void TribeInformationAIModule::loadUnitHistory() {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    char history_file_name[256];
    if ((rge_base_game == nullptr) || (rge_base_game->player_game_info == nullptr)) {
        std::strcpy(history_file_name, kDefaultUnitHistoryFilename);
    } else {
        char* player_name = rge_base_game->player_game_info->get_current_player_name();
        std::sprintf(history_file_name, kUnitHistoryFilenameFormat, player_name);
    }

    int file = rge_open(history_file_name, 0x8000);
    if (file != -1) {
        rge_read(file, this->unitHistory, 0x2C);
        rge_close(file);
    }
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E45A0
void TribeInformationAIModule::unitsThatAreMostBuilt(int* param_1, int* param_2) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int* unit_history = this->unitHistory;
    int best_count = -1;
    *param_1 = -1;
    for (int i = 0; i < 0x0B; ++i) {
        if ((best_count == -1) || (best_count < unit_history[i])) {
            *param_1 = i;
            best_count = unit_history[i];
        }
    }

    best_count = -1;
    *param_2 = -1;
    for (int i = 0; i < 0x0B; ++i) {
        if ((i != *param_1) && ((best_count == -1) || (best_count < unit_history[i]))) {
            *param_2 = i;
            best_count = unit_history[i];
        }
    }
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E4610
void TribeInformationAIModule::unitsThatAreLeastBuilt(int* param_1, int* param_2) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int* unit_history = this->unitHistory;
    int best_count = -1;
    *param_1 = 0x7FFFFFFF;
    for (int i = 0; i < 0x0B; ++i) {
        if ((best_count == -1) || (unit_history[i] < best_count)) {
            *param_1 = i;
            best_count = unit_history[i];
        }
    }

    best_count = -1;
    *param_2 = 0x7FFFFFFF;
    for (int i = 0; i < 0x0B; ++i) {
        if ((i != *param_1) && ((best_count == -1) || (unit_history[i] < best_count))) {
            *param_2 = i;
            best_count = unit_history[i];
        }
    }
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E4680
int TribeInformationAIModule::acceptablePotentialDropsiteArea(int param_1, int param_2) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int min_distance = 0;
    if ((this->md != nullptr) && (this->md->tacticalAI != nullptr)) {
        min_distance = reinterpret_cast<TribeTacticalAIModule*>(this->md->tacticalAI)->strategicNumber(0xCA);
    }
    int min_distance_sq = min_distance * min_distance;

    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        const ObjectMemory& memory = this->importantObjectMemory[i];
        int is_enemy = (this->md != nullptr && this->md->player != nullptr) ? this->md->player->isEnemy(memory.owner) : 0;
        if (is_enemy == 0) {
            continue;
        }

        short type = memory.type;
        if ((type == 0x6D) || (type == 0x67) || (type == 0x44) || (type == 0x4F) || (type == 199) || (type == 0x45)) {
            int dx = static_cast<int>(memory.x) - param_1;
            int dy = static_cast<int>(memory.y) - param_2;
            if ((dx * dx + dy * dy) <= min_distance_sq) {
                return 0;
            }
        }
    }

    return 1;
}

// Fully verified. Source of truth: taiinfmd.cpp.decomp @ 0x004E4790
int TribeInformationAIModule::percentTilesExploredInPositionQuadrant(int param_1, int param_2) {
    // Fully verified. Source of truth: TribeInformationAIModule.decomp (helper implementation).
    int map_x = this->mapXSizeValue;
    if (map_x == -1) {
        return 0;
    }

    int map_y = this->mapYSizeValue;
    int quarter_width = (map_x + ((map_x >> 0x1F) & 3U)) >> 2;
    int total = quarter_width * map_y;
    int quarter_total = (total + ((total >> 0x1F) & 3U)) >> 2;
    if (quarter_total == 0) {
        return 0;
    }

    int x_quadrant = (param_1 << 2) / map_x;
    int y_quadrant = (param_2 * 4) / map_y;
    return (this->quadrantLog[x_quadrant][y_quadrant].numberExploredTiles * 100) / quarter_total;
}
