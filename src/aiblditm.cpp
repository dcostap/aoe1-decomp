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

BuildItem::BuildItem(int bc, int ti, int bi, int n, int p, int bf, char* name,
                     float x, float y, float z, int tSet, int tOne, int tTwo,
                     int pEle)
    : BaseItem(ti, -1, bi, name, -1.0f, -1.0f, -1.0f, x, y, z),
      next(0), prev(0), buildCategoryValue(bc), numberValue(n),
      priorityValue(p), progressValue(0), builtValue(0),
      buildAttemptsValue(0), buildFromValue(bf), terrainSetValue(tSet),
      placeOnElevationValue(pEle), numberBuildsValue(0),
      buildCapValue(-1), skipCyclesValue(0), permanentSkipValue(0) {
    terrainAdjacencyValue[0] = tOne;
    terrainAdjacencyValue[1] = tTwo;
}

BuildItem::BuildItem(BuildItem* bi)
    : BaseItem(static_cast<BaseItem*>(bi)), next(0), prev(0),
      buildCategoryValue(bi->buildCategoryValue),
      numberValue(bi->numberValue), priorityValue(bi->priorityValue),
      progressValue(bi->progressValue), builtValue(bi->progressValue),
      buildAttemptsValue(bi->buildAttemptsValue),
      buildFromValue(bi->buildFromValue), terrainSetValue(bi->terrainSetValue),
      placeOnElevationValue(bi->placeOnElevationValue),
      numberBuildsValue(0), buildCapValue(-1), skipCyclesValue(0),
      permanentSkipValue(0) {
    terrainAdjacencyValue[0] = bi->terrainAdjacencyValue[0];
    terrainAdjacencyValue[1] = bi->terrainAdjacencyValue[1];
}

BuildItem::BuildItem(const BuildItem& bi)
    : BaseItem(static_cast<const BaseItem&>(bi)), next(0), prev(0),
      buildCategoryValue(bi.buildCategoryValue),
      numberValue(bi.numberValue), priorityValue(bi.priorityValue),
      progressValue(bi.progressValue), builtValue(bi.progressValue),
      buildAttemptsValue(bi.buildAttemptsValue),
      buildFromValue(bi.buildFromValue), terrainSetValue(bi.terrainSetValue),
      placeOnElevationValue(bi.placeOnElevationValue),
      numberBuildsValue(0), buildCapValue(-1), skipCyclesValue(0),
      permanentSkipValue(0) {
    terrainAdjacencyValue[0] = bi.terrainAdjacencyValue[0];
    terrainAdjacencyValue[1] = bi.terrainAdjacencyValue[1];
}

BuildItem::~BuildItem() {
}

int __cdecl operator==(const BuildItem& one, const BuildItem& two) {
    return one.typeIDValue == two.typeIDValue;
}

int __cdecl operator!=(const BuildItem& one, const BuildItem& two) {
    return one.typeIDValue != two.typeIDValue;
}

int __cdecl operator<(const BuildItem& one, const BuildItem& two) {
    return one.typeIDValue < two.typeIDValue;
}

int __cdecl operator>(const BuildItem& one, const BuildItem& two) {
    return one.typeIDValue > two.typeIDValue;
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

int BuildItem::terrainAdjacency(int v) const {
    if ((v >= 1) && (v <= 2)) {
        return terrainAdjacencyValue[v - 1];
    }
    return -1;
}

int BuildItem::placeOnElevation() const {
    return placeOnElevationValue;
}

void BuildItem::setInProgress(int p) {
    progressValue = p;
}

void BuildItem::setBuilt(int v) {
    builtValue = v;
}

void BuildItem::setBuildAttempts(int v) {
    buildAttemptsValue = v;
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

void BuildItem::setNumberBuilds(int v) {
    numberBuildsValue = v;
}

int BuildItem::buildCap() {
    return buildCapValue;
}

void BuildItem::setBuildCap(int v) {
    buildCapValue = v;
}

int BuildItem::skipCycles() {
    return skipCyclesValue;
}

void BuildItem::incrementSkipCycles() {
    ++skipCyclesValue;
}

void BuildItem::setSkipCycles(int v) {
    skipCyclesValue = v;
}

unsigned char BuildItem::permanentSkip() {
    return permanentSkipValue;
}

void BuildItem::setPermanentSkip(unsigned char v) {
    permanentSkipValue = v;
}
