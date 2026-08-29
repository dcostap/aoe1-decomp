#include "../include/aiblditm.h"

BuildItem::BuildItem()
    : next(0), prev(0), numberValue(0), priorityValue(0),
      progressValue(0), builtValue(0), buildAttemptsValue(0),
      terrainSetValue(-1),
      placeOnElevationValue(0), numberBuildsValue(0), skipCyclesValue(0),
      permanentSkipValue(0), buildCategoryValue(-1),
      buildFromValue(-1),
      buildCapValue(-1) {
    terrainAdjacencyValue[0] = -1;
    terrainAdjacencyValue[1] = -1;
}

BuildItem::BuildItem(int category, int typeID, int uniqueID, int number,
                     int priority, int buildFrom, char* name, float xSize,
                     float ySize, float zSize, int terrainSet, int adjacency0,
                     int adjacency1, int elevation)
    : BaseItem(typeID, -1, uniqueID, name, -1.0f, -1.0f, -1.0f,
               xSize, ySize, zSize),
      next(0), prev(0), buildCategoryValue(category), numberValue(number),
      priorityValue(priority), progressValue(0), builtValue(0),
      buildAttemptsValue(0), buildFromValue(buildFrom),
      terrainSetValue(terrainSet),
      placeOnElevationValue(elevation), numberBuildsValue(0),
      buildCapValue(-1), skipCyclesValue(0), permanentSkipValue(0) {
    terrainAdjacencyValue[0] = adjacency0;
    terrainAdjacencyValue[1] = adjacency1;
}

BuildItem::BuildItem(BuildItem* source)
    : BaseItem(static_cast<BaseItem*>(source)), next(0), prev(0),
      buildCategoryValue(source->buildCategoryValue),
      numberValue(source->numberValue), priorityValue(source->priorityValue),
      progressValue(source->progressValue), builtValue(source->progressValue),
      buildAttemptsValue(source->buildAttemptsValue),
      buildFromValue(source->buildFromValue),
      terrainSetValue(source->terrainSetValue),
      placeOnElevationValue(source->placeOnElevationValue),
      numberBuildsValue(0), buildCapValue(-1), skipCyclesValue(0),
      permanentSkipValue(0) {
    terrainAdjacencyValue[0] = source->terrainAdjacencyValue[0];
    terrainAdjacencyValue[1] = source->terrainAdjacencyValue[1];
}

BuildItem::BuildItem(const BuildItem& source)
    : BaseItem(static_cast<const BaseItem&>(source)), next(0), prev(0),
      buildCategoryValue(source.buildCategoryValue),
      numberValue(source.numberValue), priorityValue(source.priorityValue),
      progressValue(source.progressValue), builtValue(source.progressValue),
      buildAttemptsValue(source.buildAttemptsValue),
      buildFromValue(source.buildFromValue),
      terrainSetValue(source.terrainSetValue),
      placeOnElevationValue(source.placeOnElevationValue),
      numberBuildsValue(0), buildCapValue(-1), skipCyclesValue(0),
      permanentSkipValue(0) {
    terrainAdjacencyValue[0] = source.terrainAdjacencyValue[0];
    terrainAdjacencyValue[1] = source.terrainAdjacencyValue[1];
}

BuildItem::~BuildItem() {
}

int __cdecl operator==(const BuildItem& left, const BuildItem& right) {
    return left.typeIDValue == right.typeIDValue;
}

int __cdecl operator!=(const BuildItem& left, const BuildItem& right) {
    return left.typeIDValue != right.typeIDValue;
}

int __cdecl operator<(const BuildItem& left, const BuildItem& right) {
    return left.typeIDValue < right.typeIDValue;
}

int __cdecl operator>(const BuildItem& left, const BuildItem& right) {
    return left.typeIDValue > right.typeIDValue;
}

int BuildItem::buildCategory() const {
    return buildCategoryValue;
}

int BuildItem::number() const {
    return numberValue;
}

int BuildItem::priority() const {
    return priorityValue;
}

int BuildItem::inProgress() const {
    return progressValue;
}

int BuildItem::built() const {
    return builtValue;
}

int BuildItem::buildAttempts() const {
    return buildAttemptsValue;
}

int BuildItem::buildFrom() const {
    return buildFromValue;
}

int BuildItem::terrainSet() const {
    return terrainSetValue;
}

int BuildItem::terrainAdjacency(int index) const {
    if ((index >= 1) && (index <= 2)) {
        return terrainAdjacencyValue[index - 1];
    }
    return -1;
}

int BuildItem::placeOnElevation() const {
    return placeOnElevationValue;
}

void BuildItem::setInProgress(int value) {
    progressValue = value;
}

void BuildItem::setBuilt(int value) {
    builtValue = value;
}

void BuildItem::setBuildAttempts(int value) {
    buildAttemptsValue = value;
}

void BuildItem::incrementBuildAttempts() {
    ++buildAttemptsValue;
}

void BuildItem::decrementBuildAttempts() {
    --buildAttemptsValue;
    if (buildAttemptsValue < 0) {
        buildAttemptsValue = 0;
    }
}

int BuildItem::numberBuilds() {
    return numberBuildsValue;
}

void BuildItem::incrementNumberBuilds() {
    ++numberBuildsValue;
}

void BuildItem::setNumberBuilds(int value) {
    numberBuildsValue = value;
}

int BuildItem::buildCap() {
    return buildCapValue;
}

void BuildItem::setBuildCap(int value) {
    buildCapValue = value;
}

int BuildItem::skipCycles() {
    return skipCyclesValue;
}

void BuildItem::incrementSkipCycles() {
    ++skipCyclesValue;
}

void BuildItem::setSkipCycles(int value) {
    skipCyclesValue = value;
}

unsigned char BuildItem::permanentSkip() {
    return permanentSkipValue;
}

void BuildItem::setPermanentSkip(unsigned char value) {
    permanentSkipValue = value;
}
