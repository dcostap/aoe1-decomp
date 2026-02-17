#include "../include/PathingSystem.h"
#include "../include/RGE_Map.h"

#include <new>
#include <stddef.h>
#include <string.h>

namespace {
// Source of truth: pathsys.cpp.asm @ 0x0046B207..0x0046B236.
// This table is consumed with `index & 0xFF` in pathing cost heuristics.
int DiagionalDistance[256];

static void init_diagional_distance_table() {
    const float kMulA = 1.414199948310852f; // DAT_00570e48
    const float kMulB = -16.0f;             // DAT_00570e4c
    const float kBias = 0.5f;               // DAT_00570e50

    for (int i = 0; i < (int)(sizeof(DiagionalDistance) / sizeof(DiagionalDistance[0])); ++i) {
        const float value = kBias - ((float)i * kMulA * kMulB);
        DiagionalDistance[i] = (int)value; // __ftol truncation semantics for positive values.
    }
}
}

PathingSystem pathSystem(0xFF, 0xFF, 0, nullptr, nullptr);
PathingSystem aiPathSystem(0xFF, 0xFF, 1, nullptr, nullptr);

PathingSystem::PathingSystem(int param_1, int param_2, int param_3, RGE_Map* param_4,
                             RGE_Game_World* param_5) {
    // Source of truth: pathsys.cpp.decomp @ 0x0046B0F0
    this->initialCollidingObjects.value = nullptr;
    this->initialCollidingObjects.numberValue = 0;
    this->initialCollidingObjects.desiredNumberValue = 0;
    this->initialCollidingObjects.maximumSizeValue = 0;

    this->currentUnobstructibles.value = nullptr;
    this->currentUnobstructibles.numberValue = 0;
    this->currentUnobstructibles.desiredNumberValue = 0;
    this->currentUnobstructibles.maximumSizeValue = 0;

    this->aiPS = param_3;
    this->xSizeValue = -1;
    this->ySizeValue = -1;
    this->currentTerrainException1 = -1;
    this->currentTerrainException2 = -1;

    this->numberOpenPathsValue = 0;
    this->numberTraversedPathsValue = 0;
    this->mapValue = nullptr;
    this->worldValue = nullptr;
    this->currentObject = nullptr;

    this->averageNumWaypoints = 0.0f;
    this->averagePathLength = 0.0f;
    this->averagePathIterations = 0.0f;
    this->averageClosestTargetDistance = 0.0f;

    this->numAttempts = 0;
    this->numFails = 0;
    this->numSuccesses = 0;
    this->numInitialPathsValue = 0;
    this->numContinuePathsValue = 0;
    this->numCanPathsValue = 0;

    this->averageSuccessTime = 0.0f;
    this->averageFailTime = 0.0f;

    this->initialize(param_1, param_2, param_4, param_5);
    this->initMisc(0);
    this->zeroObstructionMap();
    init_diagional_distance_table();
}

PathingSystem::~PathingSystem() {
    // Source of truth: pathsys.cpp.decomp @ 0x0046B270
    if (this->currentUnobstructibles.value != nullptr) {
        ::operator delete(this->currentUnobstructibles.value);
        this->currentUnobstructibles.value = nullptr;
    }
    this->currentUnobstructibles.numberValue = 0;
    this->currentUnobstructibles.desiredNumberValue = 0;
    this->currentUnobstructibles.maximumSizeValue = 0;

    if (this->initialCollidingObjects.value != nullptr) {
        ::operator delete(this->initialCollidingObjects.value);
        this->initialCollidingObjects.value = nullptr;
    }
    this->initialCollidingObjects.numberValue = 0;
    this->initialCollidingObjects.desiredNumberValue = 0;
    this->initialCollidingObjects.maximumSizeValue = 0;
}

int PathingSystem::initialize(int param_1, int param_2, RGE_Map* param_3, RGE_Game_World* param_4) {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046B310
    this->mapValue = param_3;
    this->worldValue = param_4;
    if (param_3 != nullptr) {
        this->xSizeValue = param_3->map_width;
        this->ySizeValue = param_3->map_height;
        this->CurrentFacetMask = 0xF0;
        return 1;
    }

    this->ySizeValue = param_2;
    this->xSizeValue = param_1;
    this->CurrentFacetMask = 0xF0;
    return 1;
}

void PathingSystem::initMisc(uchar param_1) {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046B590
    memset(this->miscValue, param_1, sizeof(this->miscValue));
}

void PathingSystem::zeroObstructionMap() {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046B5C0
    memset(this->obstructionValue, 0, sizeof(this->obstructionValue));
}
