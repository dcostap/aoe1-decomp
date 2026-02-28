#include "../include/PathingSystem.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Moving_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/globals.h"

#include <new>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

namespace {
// Source of truth: pathsys.cpp.asm @ 0x0046B207..0x0046B236.
// This table is consumed with `index & 0xFF` in pathing cost heuristics.
int DiagionalDistance[256];

static void init_diagional_distance_table() {
    // Source of truth: pathsys.cpp.asm (float literals in .rdata)
    //   0x00570E48 float bits 0x3FB50481 = 1.414199948310852f
    //   0x00570E4C float bits 0xC1800000 = -16.0f
    //   0x00570E50 float bits 0x3F000000 = 0.5f
    const float kMulA = 1.414199948310852f; // DAT_00570E48
    const float kMulB = -16.0f;             // DAT_00570E4C
    const float kBias = 0.5f;               // DAT_00570E50

    for (int i = 0; i < (int)(sizeof(DiagionalDistance) / sizeof(DiagionalDistance[0])); ++i) {
        const float value = kBias - ((float)i * kMulA * kMulB);
        DiagionalDistance[i] = (int)value;
    }
}

struct BYTEPoint {
    uchar x;
    uchar y;
};

// Source of truth: pathsys.cpp.asm shows the table bytes in multiple sites, e.g.
//   passable @ 0x0046D677: ObstructionValueShift = 06 04 02 00
//   incrementObstruction @ 0x0046B65A: ObstructionValueMask  = 3F CF F3 FC
static const unsigned char ObstructionValueShift[4] = { 0x00, 0x02, 0x04, 0x06 };
static const unsigned char ObstructionValueMask[4]  = { 0xFC, 0xF3, 0xCF, 0x3F };

// Source of truth: pathsys.cpp.asm (data @ 0x00584F20).
// Referenced by pathsys.cpp.asm @ 0x0046C6F6 / 0x0046C6FD and pathsys.cpp.decomp in findTilePath/passable.
static const unsigned int kObstructionMasks[192] = {
    0x00000003u, 0x00000000u, 0x0000000Cu, 0x00000000u, 0x00000030u, 0x00000000u,
    0x000000C0u, 0x00000000u, 0x0000000Fu, 0x00000000u, 0x0000003Cu, 0x00000000u,
    0x000000F0u, 0x00000000u, 0x000003C0u, 0x00000000u, 0x0000003Fu, 0x00000000u,
    0x000000FCu, 0x00000000u, 0x000003F0u, 0x00000000u, 0x00000FC0u, 0x00000000u,
    0x000000FFu, 0x00000000u, 0x000003FCu, 0x00000000u, 0x00000FF0u, 0x00000000u,
    0x00003FC0u, 0x00000000u, 0x000003FFu, 0x00000000u, 0x00000FFCu, 0x00000000u,
    0x00003FF0u, 0x00000000u, 0x0000FFC0u, 0x00000000u, 0x00000FFFu, 0x00000000u,
    0x00003FFCu, 0x00000000u, 0x0000FFF0u, 0x00000000u, 0x0003FFC0u, 0x00000000u,
    0x00003FFFu, 0x00000000u, 0x0000FFFCu, 0x00000000u, 0x0003FFF0u, 0x00000000u,
    0x000FFFC0u, 0x00000000u, 0x0000FFFFu, 0x00000000u, 0x0003FFFCu, 0x00000000u,
    0x000FFFF0u, 0x00000000u, 0x003FFFC0u, 0x00000000u, 0x0003FFFFu, 0x00000000u,
    0x000FFFFCu, 0x00000000u, 0x003FFFF0u, 0x00000000u, 0x00FFFFC0u, 0x00000000u,
    0x000FFFFFu, 0x00000000u, 0x003FFFFCu, 0x00000000u, 0x00FFFFF0u, 0x00000000u,
    0x03FFFFC0u, 0x00000000u, 0x003FFFFFu, 0x00000000u, 0x00FFFFFCu, 0x00000000u,
    0x03FFFFF0u, 0x00000000u, 0x0FFFFFC0u, 0x00000000u, 0x00FFFFFFu, 0x00000000u,
    0x03FFFFFCu, 0x00000000u, 0x0FFFFFF0u, 0x00000000u, 0x3FFFFFC0u, 0x00000000u,
    0x03FFFFFFu, 0x00000000u, 0x0FFFFFFCu, 0x00000000u, 0x3FFFFFF0u, 0x00000000u,
    0xFFFFFFC0u, 0x00000000u, 0x0FFFFFFFu, 0x00000000u, 0x3FFFFFFCu, 0x00000000u,
    0xFFFFFFF0u, 0x00000000u, 0xFFFFFFC0u, 0x00000003u, 0x3FFFFFFFu, 0x00000000u,
    0xFFFFFFFCu, 0x00000000u, 0xFFFFFFF0u, 0x00000003u, 0xFFFFFFC0u, 0x0000000Fu,
    0xFFFFFFFFu, 0x00000000u, 0xFFFFFFFCu, 0x00000003u, 0xFFFFFFF0u, 0x0000000Fu,
    0xFFFFFFC0u, 0x0000003Fu, 0xFFFFFFFFu, 0x00000003u, 0xFFFFFFFCu, 0x0000000Fu,
    0xFFFFFFF0u, 0x0000003Fu, 0xFFFFFFC0u, 0x000000FFu, 0xFFFFFFFFu, 0x0000000Fu,
    0xFFFFFFFCu, 0x0000003Fu, 0xFFFFFFF0u, 0x000000FFu, 0xFFFFFFC0u, 0x000003FFu,
    0xFFFFFFFFu, 0x0000003Fu, 0xFFFFFFFCu, 0x000000FFu, 0xFFFFFFF0u, 0x000003FFu,
    0xFFFFFFC0u, 0x00000FFFu, 0xFFFFFFFFu, 0x000000FFu, 0xFFFFFFFCu, 0x000003FFu,
    0xFFFFFFF0u, 0x00000FFFu, 0xFFFFFFC0u, 0x00003FFFu, 0xFFFFFFFFu, 0x000003FFu,
    0xFFFFFFFCu, 0x00000FFFu, 0xFFFFFFF0u, 0x00003FFFu, 0xFFFFFFC0u, 0x0000FFFFu,
    0xFFFFFFFFu, 0x00000FFFu, 0xFFFFFFFCu, 0x00003FFFu, 0xFFFFFFF0u, 0x0000FFFFu,
    0xFFFFFFC0u, 0x0003FFFFu, 0xFFFFFFFFu, 0x00003FFFu, 0xFFFFFFFCu, 0x0000FFFFu,
    0xFFFFFFF0u, 0x0003FFFFu, 0xFFFFFFC0u, 0x000FFFFFu, 0xFFFFFFFFu, 0x0000FFFFu,
    0xFFFFFFFCu, 0x0003FFFFu, 0xFFFFFFF0u, 0x000FFFFFu, 0xFFFFFFC0u, 0x003FFFFFu,
};

// Source of truth: pathsys.cpp.asm (data @ 0x00584EF8).
// Referenced by pathsys.cpp.asm @ 0x0046C1C4.
static const unsigned int kFacetSkipMask[9] = {
    0x00000038u, 0x00000070u, 0x000000E0u, 0x000000C1u, 0x00000083u, 0x00000007u, 0x0000000Eu, 0x0000001Cu, 0x00000000u
};
}

PathingSystem pathSystem(0xFF, 0xFF, 0, nullptr, nullptr);
PathingSystem aiPathSystem(0xFF, 0xFF, 1, nullptr, nullptr);

void E9() {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046B060
    new (&pathSystem) PathingSystem(0xFF, 0xFF, 0, nullptr, nullptr);
}

void E14() {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046B0B0
    new (&aiPathSystem) PathingSystem(0xFF, 0xFF, 1, nullptr, nullptr);
}

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

// Lookup tables for 2-bit packed obstruction cells (4 cells per byte).
// ObstructionValueShift[i] = bit offset for cell (i & 3) within a byte.
// ObstructionValueMask[i]  = mask to clear cell (i & 3) within a byte.

void PathingSystem::incrementObstruction(int param_1, int param_2) {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046B620
    unsigned char cell = this->obstructionValue[param_1][param_2 >> 2];
    unsigned char shift = ObstructionValueShift[param_2 & 3];
    unsigned char val = (cell >> shift) & 3;
    if (val < 3) {
        this->obstructionValue[param_1][param_2 >> 2] =
            (ObstructionValueMask[param_2 & 3] & cell) | ((val + 1) << shift);
    }
}

void PathingSystem::decrementObstruction(int param_1, int param_2) {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046B680
    unsigned char cell = this->obstructionValue[param_1][param_2 >> 2];
    unsigned char shift = ObstructionValueShift[param_2 & 3];
    unsigned char val = (cell >> shift) & 3;
    if (val != 0) {
        this->obstructionValue[param_1][param_2 >> 2] =
            (ObstructionValueMask[param_2 & 3] & cell) | ((val - 1) << shift);
    }
}

void PathingSystem::printToFile(char* path) {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046B360
    if (path != nullptr) {
        FILE* f = fopen(path, "wa"); // pathsys.cpp.asm @ 0x0046B371: s_wa = "wa"
        if (f != nullptr) {
            fprintf(f, "FILENAME: %s\n", path);                                    // 0x0046B38B
            fprintf(f, "  Dimensions: %d X %d\n", this->xSizeValue << 2, this->ySizeValue << 2); // 0x0046B3A7
            fprintf(f, "\n");                                                     // 0x0046B3B5
            fprintf(f, "       ");                                                // 0x0046B3C3

            int iVar6 = 0;
            if (0 < this->xSizeValue) {
                do {
                    fprintf(f, "%04d ", iVar6); // 0x0046B3DB
                    iVar6 = iVar6 + 1;
                } while (iVar6 < this->xSizeValue);
            }

            fprintf(f, "\n");
            fprintf(f, "       ");

            iVar6 = 0;
            if (0 < this->xSizeValue) {
                do {
                    fprintf(f, "---- ", iVar6); // 0x0046B417
                    iVar6 = iVar6 + 1;
                } while (iVar6 < this->xSizeValue);
            }

            fprintf(f, "\n");

            unsigned int uVar7 = 0;
            unsigned int uVar5 = 0;
            if (0 < (this->ySizeValue << 2)) {
                do {
                    unsigned int uVar3 = (int)uVar7 >> 0x1f;
                    if ((((uVar7 ^ uVar3) - uVar3) & 3 ^ uVar3) == uVar3) {
                        fprintf(f, "R%03d: ", (int)(uVar7 + (uVar3 & 3)) >> 2); // 0x0046B467
                    } else {
                        fprintf(f, "      "); // 0x0046B477
                    }

                    uVar5 = 0;
                    if (0 < (this->xSizeValue << 2)) {
                        do {
                            unsigned int uVar4 = (int)uVar5 >> 0x1f;
                            uchar uVar1;
                            const char* pcVar8;
                            if ((((uVar5 ^ uVar4) - uVar4) & 3 ^ uVar4) == uVar4) {
                                uVar1 = this->obstruction((int)uVar5, (int)uVar7);
                                pcVar8 = " %1d"; // 0x0046B4B0
                            } else {
                                uVar1 = this->obstruction((int)uVar5, (int)uVar7);
                                pcVar8 = "%1d"; // 0x0046B4C2
                            }
                            fprintf(f, pcVar8, uVar1);
                            uVar5 = uVar5 + 1;
                        } while ((int)uVar5 < this->xSizeValue * 4);
                    }

                    uVar5 = uVar7 + 1;
                    unsigned int uVar4 = (int)uVar5 >> 0x1f;
                    const char* pcVar8;
                    if ((((uVar5 ^ uVar4) - uVar4) & 3 ^ uVar4) == uVar4) {
                        pcVar8 = "  :R%03d\n\n"; // 0x0046B4FA
                    } else {
                        pcVar8 = "\n";
                    }
                    fprintf(f, pcVar8, (int)(uVar7 + (uVar3 & 3)) >> 2);
                    uVar7 = uVar5;
                } while ((int)uVar5 < this->ySizeValue * 4);
            }
            fprintf(f, "\n");
            fclose(f);
        }
    }
}

uchar PathingSystem::lookupMisc(int x, int y) {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046B550
    return this->miscValue[x][y];
}

void PathingSystem::setMisc(int x, int y, uchar value) {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046B570
    this->miscValue[x][y] = value;
}

uchar PathingSystem::obstruction(int x, int y) {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046B5E0
    return (this->obstructionValue[x][y >> 2] >> (ObstructionValueShift[y & 3] & 0x1f)) & 3;
}

void PathingSystem::incrementInitialPaths() {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046D250
    this->numInitialPathsValue = this->numInitialPathsValue + 1;
}

void PathingSystem::incrementContinuePaths() {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046D260
    this->numContinuePathsValue = this->numContinuePathsValue + 1;
}

void PathingSystem::incrementCanPaths() {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046D270
    this->numCanPathsValue = this->numCanPathsValue + 1;
}

int PathingSystem::passable(RGE_Moving_Object* obj, float x, float y, int inObMap) {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046D280
    // Source of truth: pathsys.cpp.asm @ 0x0046D280.
    // Constants from pathsys.cpp.asm (.rdata):
    //   0x00570E68 float bits 0xC2C80000 = -100.0f
    //   0x00570E74 float bits 0xC0800000 = -4.0f
    const float kNeg100 = -100.0f; // DAT_00570E68
    const float kNeg4 = -4.0f;     // DAT_00570E74

    this->currentObject = obj;
    this->currentTerrainTable = this->worldValue->terrains[obj->master_obj->terrain];
    this->initialTile.x = -1;
    this->initialTile.y = -1;
    this->minInitialPosition.x = -1;
    this->minInitialPosition.y = -1;
    this->maxInitialPosition.x = -1;
    this->maxInitialPosition.y = -1;

    // Fractional parts, matching the `floor`/`FSUBR` pattern in asm.
    const float fx = x - (float)floor((double)x);
    const float fy = y - (float)floor((double)y);

    const float rx = obj->master_obj->radius_x;
    const float ry = obj->master_obj->radius_y;

    const int iVar2 = (int)(long)x; // __ftol(param_2)
    const int iVar4 = (int)(long)y; // __ftol(param_3)

    // Quarter-tile bounds (all computed in the same order as asm).
    int minX = (iVar2 << 2) - (int)(long)(((fx - kNeg100) - rx) * kNeg4) - 0x190;
    int minY = (iVar4 << 2) - (int)(long)(((fy - kNeg100) - ry) * kNeg4) - 0x190;
    int maxX = (iVar2 << 2) - (int)(long)(((rx + fx) - kNeg100) * kNeg4) - 0x190;
    int maxY = (iVar4 << 2) - (int)(long)(((ry + fy) - kNeg100) * kNeg4) - 0x190;

    if (minX < 0) {
        minX = minX + 1;
    }
    if (minY < 0) {
        minY = minY + 1;
    }

    if (inObMap != 0) {
        const int maxTileX = (maxX >> 2) & 0xff;
        const int minTileX = (minX >> 2) & 0xff;
        const int maxTileY = (maxY >> 2) & 0xff;
        int tileY = (minY >> 2) & 0xff;

        if (this->mapValue->map_width <= maxTileX) {
            return 0;
        }
        if (this->mapValue->map_height <= maxTileY) {
            return 0;
        }

        if (tileY <= maxTileY) {
            do {
                unsigned int local_14 = (unsigned int)minTileX;
                if (minTileX <= maxTileX) {
                    RGE_Tile* tile = &this->mapValue->map_row_offset[tileY][minTileX];
                    do {
                        if ((this->initialTile.x != (int)local_14) || (this->initialTile.y != tileY)) {
                            unsigned int terr = (unsigned int)tile->terrain_type;
                            if ((terr != (unsigned int)this->currentTerrainException1) &&
                                (terr != (unsigned int)this->currentTerrainException2) &&
                                (this->currentTerrainTable[terr] <= 0.0f)) {
                                unsigned int border = (unsigned int)tile->border_type;
                                if ((border & 0xf) == 0) {
                                    return 0;
                                }
                                if (this->currentTerrainTable[this->mapValue->border_types[border & 0xf].underlay_terrain] <= 0.0f) {
                                    return 0;
                                }
                            }
                        }
                        tile = tile + 1;
                        local_14 = (unsigned int)((uchar)local_14 + 1);
                    } while ((uchar)local_14 <= (uchar)maxTileX);
                }
                tileY = (int)(uchar)(tileY + 1);
            } while ((uchar)tileY <= (uchar)maxTileY);
        }
    }

    const int removed = ((RGE_Static_Object*)obj)->removeFromObstructionMap(this->aiPS);

    bool bVar1 = false;
    int iVar4h = (maxY - minY) - 1;
    if (-1 < iVar4h) {
        if ((iVar4h < 0x18) &&
            (this->maxTarget.x < minX || this->maxTarget.y < minY || maxX < this->minTarget.x || maxY < this->minTarget.y)) {
            const int idx = (minY & 3) + iVar4h * 4;
            const unsigned int mask1 = kObstructionMasks[idx * 2];
            const unsigned int mask2 = kObstructionMasks[idx * 2 + 1]; // (&DAT_00584F24)[idx]
            if (mask2 == 0) {
                if (minX < maxX) {
                    uchar* puVar13 = this->obstructionValue[minX] + ((unsigned int)minY >> 2);
                    int xx = minX;
                    do {
                        if ((*(unsigned int*)puVar13 & mask1) != 0) goto LAB_0046d6d7;
                        xx = xx + 1;
                        puVar13 = puVar13 + 0xff;
                    } while (xx < maxX);
                }
            } else if (minX < maxX) {
                uchar* puVar13 = this->obstructionValue[minX] + ((unsigned int)minY >> 2);
                int xx = minX;
                do {
                    if (((*(unsigned int*)puVar13 & mask1) != 0) || ((*(unsigned int*)(puVar13 + 4) & mask2) != 0)) goto LAB_0046d6d7;
                    xx = xx + 1;
                    puVar13 = puVar13 + 0xff;
                } while (xx < maxX);
            }
        } else {
            if (minX < maxX) {
                int iVar4row = minX * 0xff;
                unsigned int uVar8 = (unsigned int)minY;
                int xx = minX;
                do {
                    for (; (int)uVar8 < maxY; uVar8 = uVar8 + 1) {
                        if ((this->obstructionValue[0][iVar4row + ((int)uVar8 >> 2)] >>
                             (ObstructionValueShift[uVar8 & 3] & 0x1f) &
                             3) != 0) {
                            if ((this->currentTargetID == -1) || (xx < this->minTarget.x) || (this->maxTarget.x < xx) ||
                                ((int)uVar8 < this->minTarget.y) || (this->maxTarget.y < (int)uVar8)) {
                                goto LAB_0046d6d7;
                            }
                            bVar1 = true;
                        }
                    }
                    xx = xx + 1;
                    iVar4row = iVar4row + 0xff;
                    uVar8 = (unsigned int)minY;
                } while (xx < maxX);
            }
            if (bVar1) goto LAB_0046d6d7;
        }
    }

    if ((removed != 0) && (obj->inside_obj == nullptr)) {
        ((RGE_Static_Object*)obj)->addToObstructionMap(this->aiPS);
    }
    return 1;

LAB_0046d6d7:
    if ((removed != 0) && (obj->inside_obj == nullptr)) {
        ((RGE_Static_Object*)obj)->addToObstructionMap(this->aiPS);
    }
    return 0;
}

long PathingSystem::checksum() {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046D740
    unsigned int uVar3 = 0;
    uchar(*pauVar2)[255] = this->obstructionValue;
    int iVar4 = 0x3fc;
    do {
        int iVar1 = 0;
        do {
            uVar3 = uVar3 ^ (*pauVar2)[iVar1];
            iVar1 = iVar1 + 1;
        } while (iVar1 < 0xff);
        pauVar2 = pauVar2 + 1;
        iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    return (long)uVar3;
}

void PathingSystem::printState(RGE_Moving_Object* obj) {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046D770
    // Decomp/ASM show this is a printf-style varargs callback at vtable slot 0x144.
    // Source of truth: pathsys.cpp.asm @ 0x0046D784..0x0046D79C.
    obj->logDebug("    There are %d open paths and %d traversed paths.", this->numberOpenPathsValue, this->numberTraversedPathsValue);
    obj->logDebug("    The open paths:");

    int iVar4 = 1;
    if (0 < this->numberOpenPathsValue) {
        uchar* puVar3 = &this->MGP_openPaths[1].y;
        do {
            uchar bVar1 = this->facetValue[((MGP_FloatHeap*)(puVar3 + -1))->x][*puVar3];
            if ((bVar1 & 0xf8) == this->CurrentFacetMask) {
                bVar1 = bVar1 & 7;
            } else {
                bVar1 = 0xff;
            }
            obj->logDebug("      %5d: (%d, %d), total=%d, facet=%d.", iVar4, (uint)((MGP_FloatHeap*)(puVar3 + -1))->x, (uint)*puVar3,
                          *(int*)(puVar3 + 3), bVar1);
            iVar4 = iVar4 + 1;
            puVar3 = puVar3 + 8;
        } while (iVar4 <= this->numberOpenPathsValue);
    }
}

int PathingSystem::copyPath(int step) {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046D830
    Path* path = &this->currentObject->pathValue;
    if (this->currentObject->storePathInExceptionPath != 0) {
        path = &this->currentObject->exceptionPathValue;
    }
    path->killPath();

    uchar local_18 = this->MGP_openPaths[1].x;
    uchar bStack_17 = this->MGP_openPaths[1].y;
    unsigned int uVar16 = (unsigned int)local_18;
    unsigned int uVar15 = (unsigned int)bStack_17;

    uchar bVar2 = this->facetValue[uVar16][uVar15];
    int tWY2;
    if ((bVar2 & 0xf8) == this->CurrentFacetMask) {
        tWY2 = bVar2 & 7;
    } else {
        tWY2 = 0xff;
    }

    Waypoint wp;
    wp.x = (float)uVar16 + this->currentXOffset;
    wp.y = (float)uVar15 + this->currentYOffset;
    wp.z = this->currentObject->world_z;
    wp.facetToNextWaypoint = 0;

    path->initToStart();

    char cVar14 = -1;
    for (;;) {
        if ((this->initialTile.x == (int)uVar16) && (this->initialTile.y == (int)uVar15)) {
            if (this->currentObject->storePathInExceptionPath == 0) {
                if (this->currentObject->pathValue.insertAtCurrent(wp) == 0) {
                    return 0;
                }
            } else {
                if (this->currentObject->exceptionPathValue.insertAtCurrent(wp) == 0) {
                    return 0;
                }
            }
            return 1;
        }

        char cVar7 = (char)tWY2;
        if ((char)tWY2 != cVar14) {
            if (this->currentObject->storePathInExceptionPath == 0) {
                if (this->currentObject->pathValue.insertAtCurrent(wp) == 0) {
                    return 0;
                }
            } else {
                if (this->currentObject->exceptionPathValue.insertAtCurrent(wp) == 0) {
                    return 0;
                }
            }
        }

        if (this->currentUnobstructibleGroupID != -1) {
            int iVar8 = (int)uVar16 - 1;
            int tWY1 = (int)uVar16 + 1;
            if (iVar8 < 0) {
                iVar8 = 0;
                tWY1 = (int)uVar16 + 2;
            } else if (this->xSizeValue <= tWY1) {
                iVar8 = (int)uVar16 - 2;
                tWY1 = this->xSizeValue + -1;
            }

            int fooX = (int)uVar15 - 1;
            int tWX2 = (int)uVar15 + 1;
            if (fooX < 0) {
                tWX2 = (int)uVar15 + 2;
                fooX = 0;
            } else if (this->ySizeValue <= tWX2) {
                fooX = (int)uVar15 - 2;
                tWX2 = this->ySizeValue + -1;
            }

            for (; iVar8 <= tWY1; iVar8 = iVar8 + 1) {
                for (int iVar6 = fooX; iVar6 <= tWX2; iVar6 = iVar6 + 1) {
                    int objectCountOnTile = 0;
                    // NOTE: RGE_Game_World::objectGroupOnTile is not declared in headers in this task.
                    int iVar9 = this->worldValue->objectGroupOnTile(this->currentUnobstructiblePlayerID,
                                                                   this->currentUnobstructibleGroupID, iVar8, iVar6,
                                                                   objectCountOnTile);
                    if (iVar9 != -1) {
                        int count = this->currentUnobstructibles.numberValue;
                        int found = 0;
                        for (int k = 0; k < count; ++k) {
                            if (this->currentUnobstructibles.value[k] == iVar9) {
                                found = 1;
                                break;
                            }
                        }
                        if (found == 0) {
                            if (this->currentUnobstructibles.maximumSizeValue + -1 < count) {
                                int newCount = count + 1;
                                int* newArr = (int*)::operator new(newCount * 4);
                                if (newArr != nullptr) {
                                    for (int k = 0; k < this->currentUnobstructibles.maximumSizeValue && k < newCount; ++k) {
                                        newArr[k] = this->currentUnobstructibles.value[k];
                                    }
                                    ::operator delete(this->currentUnobstructibles.value);
                                    this->currentUnobstructibles.value = newArr;
                                    this->currentUnobstructibles.maximumSizeValue = newCount;
                                }
                            }
                            this->currentUnobstructibles.value[this->currentUnobstructibles.numberValue] = iVar9;
                            this->currentUnobstructibles.numberValue = this->currentUnobstructibles.numberValue + 1;
                        }
                    }
                }
            }
        }

        switch (tWY2) {
        case 0:
            local_18 = (uchar)(local_18 + (char)step);
            bStack_17 = (uchar)(bStack_17 + (char)step);
            break;
        case 1:
            bStack_17 = (uchar)(bStack_17 + (char)step);
            break;
        case 2:
            local_18 = (uchar)(local_18 - (char)step);
            bStack_17 = (uchar)(bStack_17 + (char)step);
            break;
        case 3:
            local_18 = (uchar)(local_18 - (char)step);
            break;
        case 4:
            local_18 = (uchar)(local_18 - (char)step);
            bStack_17 = (uchar)(bStack_17 - (char)step);
            break;
        case 5:
            bStack_17 = (uchar)(bStack_17 - (char)step);
            break;
        case 6:
            local_18 = (uchar)(local_18 + (char)step);
            bStack_17 = (uchar)(bStack_17 - (char)step);
            break;
        case 7:
            local_18 = (uchar)(local_18 + (char)step);
            break;
        }

        uVar15 = (unsigned int)bStack_17;
        uVar16 = (unsigned int)local_18;
        bVar2 = this->facetValue[uVar16][uVar15];
        if ((bVar2 & 0xf8) == this->CurrentFacetMask) {
            tWY2 = bVar2 & 7;
        } else {
            tWY2 = 0xff;
        }

        wp.x = (float)uVar16 + this->currentXOffset;
        wp.y = (float)uVar15 + this->currentYOffset;
        wp.z = this->currentObject->world_z;
        cVar14 = cVar7;
    }
}

int PathingSystem::FUN_0046d202(int step) {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046D202
    return this->copyPath(step);
}

void PathingSystem::FUN_0046dc8a(ManagedArray<int>& out) {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046DC8A
    this->copyUnobstructibles(out);
}

void PathingSystem::copyUnobstructibles(ManagedArray<int>& out) {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046DCB0
    int iVar6 = this->currentUnobstructibles.numberValue;
    for (;;) {
        if (iVar6 < 0) {
            return;
        }
        if (this->currentUnobstructibles.maximumSizeValue + -1 < iVar6) {
            int* piVar1 = (int*)::operator new(iVar6 * 4 + 4);
            if (piVar1 != nullptr) {
                int iVar2 = 0;
                if (0 < this->currentUnobstructibles.maximumSizeValue) {
                    while (true) {
                        if (iVar6 + 1 <= iVar2) {
                            break;
                        }
                        int iVar3 = iVar2 + 1;
                        piVar1[iVar2] = this->currentUnobstructibles.value[iVar2];
                        iVar2 = iVar3;
                        if (!(iVar3 < this->currentUnobstructibles.maximumSizeValue)) {
                            break;
                        }
                    }
                }
                ::operator delete(this->currentUnobstructibles.value);
                this->currentUnobstructibles.value = piVar1;
                this->currentUnobstructibles.maximumSizeValue = iVar6 + 1;
            }
        }

        int iVar2 = out.numberValue;
        int iVar3 = this->currentUnobstructibles.value[iVar6];
        int iVar4 = 0;
        if (0 < iVar2) {
            do {
                if (out.maximumSizeValue <= iVar4) break;
                if (out.value[iVar4] == iVar3) goto LAB_0046ddc8;
                iVar4 = iVar4 + 1;
            } while (iVar4 < iVar2);
        }

        if (out.maximumSizeValue + -1 < iVar2) {
            int newCount = iVar2 + 1;
            int* piVar1 = (int*)::operator new(newCount * 4);
            if (piVar1 != nullptr) {
                iVar4 = 0;
                if (0 < out.maximumSizeValue) {
                    while (true) {
                        if (newCount <= iVar4) break;
                        int iVar5 = iVar4 + 1;
                        piVar1[iVar4] = out.value[iVar4];
                        iVar4 = iVar5;
                        if (!(iVar5 < out.maximumSizeValue)) {
                            break;
                        }
                    }
                }
                ::operator delete(out.value);
                out.value = piVar1;
                out.maximumSizeValue = newCount;
            }
        }

        out.value[out.numberValue] = iVar3;
        out.numberValue = out.numberValue + 1;
    LAB_0046ddc8:
        iVar6 = iVar6 + -1;
    }
}

int PathingSystem::findTilePath(int startX, int startY, int goalX, int goalY, RGE_Moving_Object* obj, float goalTolerance,
                                int targetID, int clearPathOnFail, float* pathDistanceOut, int param_10, int checkTerrainOnFirstPass,
                                int param_12, int step, int unobstructiblePlayerID, int unobstructibleGroupID) {
    // Fully verified. Source of truth: pathsys.cpp.decomp @ 0x0046B6E0
    if ((startX < 0) || (startY < 0) || (this->xSizeValue < startX) || (this->xSizeValue < startY) || (goalX < 0) || (goalY < 0) ||
        (this->xSizeValue < goalX) || (this->xSizeValue < goalY)) {
        if (clearPathOnFail != 1) {
            return 0;
        }
        Path* p = &obj->pathValue;
        if (obj->storePathInExceptionPath != 0) {
            p = &obj->exceptionPathValue;
        }
        p->killPath();
        return 0;
    }

    // Constants from pathsys.cpp.asm (.rdata):
    //   0x00570E54 float bits 0x3F800000 = 1.0f
    //   0x00570E58 float bits 0x41800000 = 16.0f
    //   0x00570E5C float bits 0x00000000 = 0.0f
    //   0x00570E60 float bits 0x40800000 = 4.0f
    //   0x00570E64 float bits 0xBF000000 = -0.5f
    //   0x00570E68 float bits 0xC2C80000 = -100.0f
    //   0x00570E6C float bits 0xB851B717 = -4.999999873689376e-05f
    //   0x00570E70 float bits 0xC2C80007 = -100.00005340576172f
    //   0x00570E74 float bits 0xC0800000 = -4.0f
    //   0x00570E78 double bits 0x4030000000000000 = 16.0
    if (1.0f < goalTolerance) {
        int iMax = goalX;
        int iMin = startX;
        if (goalX < startX) {
            iMax = startX;
            iMin = goalX;
        }
        int jMin = startY;
        int jMax = goalY;
        if (goalY < startY) {
            jMin = goalY;
            jMax = startY;
        }
        unsigned int dx = (unsigned int)(iMax - iMin);
        unsigned int dy = (unsigned int)(jMax - jMin);
        int diff;
        if ((int)dx < (int)dy) {
            diff = (int)(dy - dx);
        } else {
            diff = (int)(dx - dy);
            dx = dy;
        }
        if ((float)(int)(DiagionalDistance[dx & 0xff] + diff * 0x10) < goalTolerance * 16.0f) {
            if (pathDistanceOut != nullptr) {
                *pathDistanceOut = 0.0f;
            }
            if (clearPathOnFail != 1) {
                return 1;
            }
            Path* p = &obj->pathValue;
            if (obj->storePathInExceptionPath != 0) {
                p = &obj->exceptionPathValue;
            }
            p->killPath();
            return 1;
        }

        // ASM: virtual call [vtable + 0xFC] (RGE_Moving_Object::maximumSpeed).
        float(__thiscall* maximumSpeedFn)(void*) = *(float(__thiscall**)(void*))(*(int*)obj + 0xfc);
        const float maximumSpeed = maximumSpeedFn(obj);
        if (maximumSpeed == 0.0f) { // DAT_00570E5C = 0.0f
            if (pathDistanceOut != nullptr) {
                *pathDistanceOut = 0.0f;
            }
            if (clearPathOnFail != 1) {
                return 0;
            }
            Path* p = &obj->pathValue;
            if (obj->storePathInExceptionPath != 0) {
                p = &obj->exceptionPathValue;
            }
            p->killPath();
            return 0;
        }
    }

    this->currentObject = obj;
    this->currentTerrainTable = this->worldValue->terrains[obj->master_obj->terrain];
    this->currentTerrainException1 = obj->currentTerrainException1;
    this->currentTerrainException2 = obj->currentTerrainException2;
    this->currentUnobstructiblePlayerID = unobstructiblePlayerID;
    this->currentUnobstructibleGroupID = unobstructibleGroupID;
    this->currentUnobstructibles.numberValue = 0;

    if (MapPathsDisplay != 0) {
        RGE_Map* map = this->mapValue;
        for (int yy = 0; yy < map->map_height; ++yy) {
            for (int xx = 0; xx < map->map_width; ++xx) {
                map->map_row_offset[yy][xx].draw_attribute &= 0x70;
            }
        }

        // ASM: call rge_base_game vfunc [vtbl + 0x2C] then panel vfunc [vtbl + 0x20] with arg 2.
        TPanel* (__thiscall* getViewPanelFn)(void*) = *(TPanel * (__thiscall**)(void*))(*(int*)rge_base_game + 0x2c);
        TPanel* panel = getViewPanelFn(rge_base_game);
        void(__thiscall* invalidateFn)(void*, int) = *(void(__thiscall**)(void*, int))(*(int*)panel + 0x20);
        invalidateFn(panel, 2);
    }

    this->minTarget.x = goalX * 4;
    this->minTarget.y = goalY * 4;
    this->currentTargetID = targetID;
    this->maxTarget.x = goalX * 4 + 3;
    this->maxTarget.y = goalY * 4 + 3;

    if (targetID != -1) {
        RGE_Static_Object* target = this->worldValue->object(targetID);
        if (target == nullptr) {
            this->currentTargetID = -1;
        } else {
            // ASM-audited: pathsys.cpp.asm @ 0x0046B93E..0x0046B9A0, scales by DAT_00570E60 (4.0).
            this->minTarget.x = (int)(long)((target->world_x - target->master_obj->radius_x) * 4.0f);
            this->minTarget.y = (int)(long)((target->world_y - target->master_obj->radius_y) * 4.0f);
            this->maxTarget.x = (int)(long)((target->world_x + target->master_obj->radius_x) * 4.0f);
            this->maxTarget.y = (int)(long)((target->world_y + target->master_obj->radius_y) * 4.0f);
        }
    }

    this->startOfPath = 1;
    this->checkTerrainOnFirstPass = checkTerrainOnFirstPass;
    this->currentObjectInObMap = ((RGE_Static_Object*)this->currentObject)->removeFromObstructionMap(this->aiPS);

    // Source of truth: pathsys.cpp.asm (.rdata)
    //   0x00570E64 float bits 0xBF000000 = -0.5f (used as `floor(v) - (-0.5f)` => floor(v) + 0.5f)
    const float wx = obj->world_x;
    const float wy = obj->world_y;
    const float cx = (float)floor((double)wx) - (-0.5f); // DAT_00570E64
    const float cy = (float)floor((double)wy) - (-0.5f); // DAT_00570E64

    if (this->passable(this->currentObject, cx, cy, 1) == 0) {
        this->currentXOffset = wx - (float)(long)floor((double)wx);
        this->currentYOffset = wy - (float)(long)floor((double)wy);
    } else {
        this->currentXOffset = 0.5f;
        this->currentYOffset = 0.5f;
    }

    // Fully verified. Source of truth: pathsys.cpp.asm @ 0x0046BA7A..0x0046BB8F.
    if (9 < obj->continueCounter) {
        int i = 0;
        if (0 < obj->pathingGroupMembers.numberValue) {
            do {
                if (obj->pathingGroupMembers.maximumSizeValue + -1 < i) {
                    int* newArr = (int*)::operator new(i * 4 + 4);
                    if (newArr != nullptr) {
                        int j = 0;
                        if (0 < obj->pathingGroupMembers.maximumSizeValue) {
                            do {
                                if (i + 1 <= j) break;
                                newArr[j] = obj->pathingGroupMembers.value[j];
                                j = j + 1;
                            } while (j < obj->pathingGroupMembers.maximumSizeValue);
                        }
                        ::operator delete(obj->pathingGroupMembers.value);
                        obj->pathingGroupMembers.value = newArr;
                        obj->pathingGroupMembers.maximumSizeValue = i + 1;
                    }
                }

                RGE_Static_Object* member = this->worldValue->object(obj->pathingGroupMembers.value[i]);
                if ((member != nullptr) && (member->id != obj->id)) {
                    // ASM: vfunc [vtbl + 0x130] (waitingToMove) and vfunc [vtbl + 0xF4] (getSpeed),
                    // and compare *(float*)((byte*)member + 0x130) (collisionAvoidanceDistance) > 0.0.
                    const uchar waiting = ((RGE_Moving_Object*)member)->waitingToMove();
                    float(__thiscall* getSpeedFn)(void*) = *(float(__thiscall**)(void*))(*(int*)member + 0xf4);
                    const float speed = getSpeedFn(member);
                    const float collisionAvoidanceDistance = *(float*)((byte*)member + 0x130); // RGE_Moving_Object + 0x130
                    if ((waiting != 0) || (speed != 0.0f) || (0.0f < collisionAvoidanceDistance)) {
                        member->removeFromObstructionMap(this->aiPS);
                    }
                }
                i = i + 1;
            } while (i < obj->pathingGroupMembers.numberValue);
        }
    }

    // Initial point bounds for object pathing (ASM: 0x0046BB8F..0x0046BC41).
    this->minInitialPosition.x = (int)(long)((obj->world_x - obj->master_obj->radius_x) * 4.0f);
    if (this->minInitialPosition.x < 0) {
        this->minInitialPosition.x = 0;
    }
    this->minInitialPosition.y = (int)(long)((obj->world_y - obj->master_obj->radius_y) * 4.0f);
    if (this->minInitialPosition.y < 0) {
        this->minInitialPosition.y = 0;
    }

    this->maxInitialPosition.x = (int)(long)((obj->world_x + obj->master_obj->radius_x) * 4.0f);
    const int maxXAllowed = this->xSizeValue * 4;
    if (maxXAllowed < this->maxInitialPosition.x) {
        this->maxInitialPosition.x = maxXAllowed;
    }

    this->maxInitialPosition.y = (int)(long)((obj->world_y + obj->master_obj->radius_y) * 4.0f);
    const int maxYAllowed = this->ySizeValue * 4;
    if (maxYAllowed < this->maxInitialPosition.y) {
        this->maxInitialPosition.y = maxYAllowed;
    }

    // NOTE: RGE_Moving_Object::setInitialPoints is not declared in headers in this task.
    obj->setInitialPoints(&this->minInitialPosition, &this->maxInitialPosition);

    this->initialTile.x = startX;
    this->initialTile.y = startY;

    this->MGP_closestTargetDistance = -1;
    if (this->CurrentFacetMask < 0xf0) {
        this->CurrentFacetMask = this->CurrentFacetMask + 8;
    } else {
        this->CurrentFacetMask = 0;
        memset(this->facetValue, 0xff, sizeof(this->facetValue));
    }

    this->numberOpenPathsValue = 1;
    this->numberTraversedPathsValue = 0;

    // Initial heuristic total for start.
    int iMax = goalX;
    int iMin = startX;
    if (goalX < startX) {
        iMax = startX;
        iMin = goalX;
    }
    int jMin = startY;
    int jMax = goalY;
    if (goalY < startY) {
        jMin = goalY;
        jMax = startY;
    }
    unsigned int dx = (unsigned int)(iMax - iMin);
    unsigned int dy = (unsigned int)(jMax - jMin);
    int diff;
    if ((int)dx < (int)dy) {
        diff = (int)(dy - dx);
    } else {
        diff = (int)(dx - dy);
        dx = dy;
    }
    int startTotal = DiagionalDistance[dx & 0xff] + diff * 0x10;
    this->MGP_costValue[startX][startY] = startTotal;
    this->MGP_openPaths[1].total = startTotal;
    this->MGP_bestTraversedPath.total = startTotal;
    this->MGP_openPaths[1].x = (uchar)startX;
    this->MGP_openPaths[1].y = (uchar)startY;
    this->MGP_openPaths[0].total = -2000000000;
    this->MGP_bestTraversedPath.x = (uchar)startX;
    this->MGP_bestTraversedPath.y = (uchar)startY;

    // MGP_goalTolerance is an integer distance in (tile-units * 16).
    int MGP_goalTolerance;
    if ((float)step <= goalTolerance) {
        // Source of truth: pathsys.cpp.asm @ 0x0046BD35..0x0046BD43 (FMUL 16.0 then __ftol).
        MGP_goalTolerance = (int)(long)(goalTolerance * 16.0f); // DAT_00570E58 = 16.0f
    } else {
        MGP_goalTolerance = step << 4;
    }

    // Precompute object deltas from current offsets & radii (ASM: 0x0046BD4F..0x0046BE3F).
    const float kNeg100 = -100.0f;                  // DAT_00570E68
    const float kNeg4 = -4.0f;                      // DAT_00570E74
    const float kEps = -4.999999873689376e-05f;     // DAT_00570E6C
    const float kNeg100Eps = -100.00005340576172f;  // DAT_00570E70
    const double k16d = 16.0;                       // DAT_00570E78

    const float rx = obj->master_obj->radius_x;
    const float ry = obj->master_obj->radius_y;
    const float a = (this->currentXOffset - kNeg100) - rx;
    const float b = rx + this->currentXOffset;
    const float c = (this->currentYOffset - kNeg100) - ry;
    const float d = ry + this->currentYOffset;

    const int xDeltaLeft = (int)(long)((a - kEps)) - 100;
    const int xDeltaRight = (int)(long)((b - kNeg100Eps)) - 100;
    const int yDeltaUp = (int)(long)((c - kEps)) - 100;
    const int yDeltaDown = (int)(long)((d - kNeg100Eps)) - 100;
    const int xDeltaLeft4 = -400 - (int)(long)((a * kNeg4));
    const int xDeltaRight4 = -400 - (int)(long)(((b - kNeg100) * kNeg4));
    const int yDeltaUp4 = -400 - (int)(long)((c * kNeg4));
    const int yDeltaDown4 = -400 - (int)(long)(((d - kNeg100) * kNeg4));

    int iterations = 0;
    // numberIterationCap computation (ASM-audited @ 0x0046BE32..0x0046BEB8).
    const int dx2 = (goalX - startX) * (goalX - startX);
    const int dy2 = (goalY - startY) * (goalY - startY);
    int iVar20 = (int)(long)(sqrt((double)(dx2 + dy2)) * k16d);
    iVar20 = (int)(iVar20 + ((iVar20 >> 0x1f) & 0xfU)) >> 4;
    int numberIterationCap;
    if (iVar20 < 0xb) {
        numberIterationCap = (iVar20 * numberPathingIterations) / 10;
    } else {
        numberIterationCap = (iVar20 * numberPathingIterations) / 100;
    }
    if ((obj->owner != nullptr) && (obj->owner->id == 0) && (100 < numberIterationCap)) {
        numberIterationCap = 100;
    }
    if ((obj->owner != nullptr) && (obj->owner->computerPlayer() == 1)) {
        numberIterationCap = (iVar20 * 0x9c4) / 100;
    }

    if (0 < this->numberOpenPathsValue) {
    LAB_0046bf0e:
        if ((((numberPathingIterations == -1) || (param_10 != 1)) || (iterations <= numberIterationCap)) && (iterations < 0x4e21)) {
            unsigned int uVar34 = (unsigned int)this->MGP_openPaths[1].x;
            unsigned int uVar10 = (unsigned int)this->MGP_openPaths[1].y;

            if (MapPathsDisplay != 0) {
                this->mapValue->map_row_offset[uVar10][uVar34].draw_attribute = 0x81;
            }

            XYPoint temp;
            temp.x = (int)uVar34;
            temp.y = (int)uVar10;

            const int ddx = goalX - temp.x;
            const int ddy = goalY - temp.y;
            const int distance16 = (int)(long)(sqrt((double)(ddx * ddx + ddy * ddy)) * k16d);
            if ((this->MGP_closestTargetDistance == -1) || (distance16 < this->MGP_closestTargetDistance)) {
                this->MGP_closestTargetDistance = distance16;
            }

            if (distance16 < MGP_goalTolerance) {
                if ((clearPathOnFail == 1) && (this->copyPath(step) == 0)) {
                    Path* p = &obj->pathValue;
                    if (obj->storePathInExceptionPath != 0) {
                        p = &obj->exceptionPathValue;
                    }
                    p->killPath();
                    goto LAB_0046d19f;
                }
                if (pathDistanceOut != nullptr) {
                    *pathDistanceOut = (float)this->MGP_costValue[uVar34][uVar10];
                }
                goto LAB_0046ceaf;
            }

            if (distance16 < this->MGP_bestTraversedPath.total) {
                this->MGP_bestTraversedPath.total = distance16;
                this->MGP_bestTraversedPath.x = this->MGP_openPaths[1].x;
                this->MGP_bestTraversedPath.y = this->MGP_openPaths[1].y;
            }

            this->numberTraversedPathsValue = this->numberTraversedPathsValue + 1;

            int heapCount = this->numberOpenPathsValue;
            this->MGP_openPaths[1] = this->MGP_openPaths[heapCount];
            heapCount = heapCount - 1;
            this->numberOpenPathsValue = heapCount;

            // Heapify down.
            int parent = 1;
            int total = this->MGP_openPaths[parent].total;
            uchar saveX = this->MGP_openPaths[parent].x;
            uchar saveY = this->MGP_openPaths[parent].y;

            while (parent * 2 <= heapCount) {
                int child = parent * 2;
                if ((child < heapCount) && (this->MGP_openPaths[child + 1].total < this->MGP_openPaths[child].total)) {
                    child = child + 1;
                }
                if (total < this->MGP_openPaths[child].total) break;
                this->MGP_openPaths[parent] = this->MGP_openPaths[child];
                parent = child;
            }
            this->MGP_openPaths[parent].x = saveX;
            this->MGP_openPaths[parent].y = saveY;
            this->MGP_openPaths[parent].total = total;

            int i = 0;
            int SkipBit = 1;
            unsigned int uVar36 = uVar34;
            XYPoint bestPathPoint;
            bestPathPoint.x = (int)uVar34;
            bestPathPoint.y = (int)uVar10;

        LAB_0046c153:
            switch (i) {
            case 0:
                uVar36 = uVar36 - step;
                bestPathPoint.y = bestPathPoint.y - step;
                bestPathPoint.x = (int)uVar36;
                break;
            case 1:
            case 2:
                uVar36 = uVar36 + step;
                bestPathPoint.x = (int)uVar36;
                break;
            case 3:
                bestPathPoint.y = bestPathPoint.y + step;
                break;
            case 4:
                bestPathPoint.y = bestPathPoint.y + step;
                break;
            case 5:
            case 6:
                uVar36 = uVar36 - step;
                bestPathPoint.x = (int)uVar36;
                break;
            case 7:
                bestPathPoint.y = bestPathPoint.y - step;
                break;
            }

            uchar bVar33 = this->facetValue[uVar34][uVar10];
            unsigned int uVar22;
            if ((bVar33 & 0xf8) == this->CurrentFacetMask) {
                uVar22 = bVar33 & 7;
            } else {
                uVar22 = 8;
            }

            if (((kFacetSkipMask[uVar22] & (unsigned int)SkipBit) != 0) || ((int)uVar36 < 0) || (bestPathPoint.y < 0) ||
                (this->xSizeValue <= (int)uVar36) || (this->ySizeValue <= bestPathPoint.y) ||
                ((uVar36 == (unsigned int)this->initialTile.x) && (bestPathPoint.y == this->initialTile.y))) {
                goto LAB_0046ca94;
            }

            // Heuristic newTotal (decomp structure preserved).
            int iVar20 = this->MGP_costValue[uVar34][uVar10];

            // Distance from neighbor to goal using DiagionalDistance lookup (tile units * 16).
            int iVar23 = goalX;
            int iVar43 = bestPathPoint.x;
            if (goalX < bestPathPoint.x) {
                iVar23 = bestPathPoint.x;
                iVar43 = goalX;
            }
            int iVar31 = bestPathPoint.y;
            int iVar38 = goalY;
            if (goalY < bestPathPoint.y) {
                iVar31 = goalY;
                iVar38 = bestPathPoint.y;
            }
            unsigned int dx2 = (unsigned int)(iVar23 - iVar43);
            unsigned int dy2 = (unsigned int)(iVar38 - iVar31);
            int diff2;
            if ((int)dx2 < (int)dy2) {
                diff2 = (int)(dy2 - dx2);
            } else {
                diff2 = (int)(dx2 - dy2);
                dx2 = dy2;
            }

            int newTotal = DiagionalDistance[dx2 & 0xff] + iVar20 + diff2 * 0x10;

            uchar* puVar12 = this->facetValue[bestPathPoint.x] + bestPathPoint.y;
            uchar prev = *puVar12;
            uchar prevFacet;
            if ((prev & 0xf8) == this->CurrentFacetMask) {
                prevFacet = prev & 7;
            } else {
                prevFacet = 0xff;
            }

            if ((prevFacet < 8) && (this->MGP_costValue[bestPathPoint.x][bestPathPoint.y] <= newTotal)) {
                goto LAB_0046ca94;
            }

            // Terrain and obstruction rectangle checks (decomp structure; uses deltas computed above).
            unsigned int uVar32 = 0;
            unsigned int uVar24 = 0;
            unsigned int uVar28 = 0;
            unsigned int uVar39 = uVar10;
            unsigned int uVar37 = (unsigned int)bestPathPoint.y;
            unsigned int uVar40 = (unsigned int)bestPathPoint.x;
            unsigned int uVar22x = uVar34;
            int param_1 = 0;
            float param_6f = 0.0f;
            int param_2i = 0;
            int param_14i = 0;

            switch (i) {
            case 0:
                uVar32 = (unsigned int)(xDeltaLeft + bestPathPoint.x);
                uVar24 = (unsigned int)(bestPathPoint.y + yDeltaUp);
                param_1 = xDeltaLeft4 + bestPathPoint.x * 4;
                break;
            case 1:
                uVar24 = (unsigned int)(bestPathPoint.y + yDeltaUp);
                uVar32 = (unsigned int)(xDeltaLeft + (int)uVar34);
                param_1 = xDeltaLeft4 + (int)uVar34 * 4;
                break;
            case 2:
            case 3:
                param_14i = yDeltaUp4 + (int)uVar10 * 4;
                param_1 = xDeltaLeft4 + (int)uVar34 * 4;
                uVar24 = (unsigned int)(yDeltaUp + (int)uVar10);
                uVar32 = (unsigned int)(xDeltaLeft + (int)uVar34);
                uVar28 = (unsigned int)(bestPathPoint.x + xDeltaRight);
                param_6f = (float)(yDeltaDown4 + (int)uVar10 * 4);
                param_2i = xDeltaRight4 + bestPathPoint.x * 4;
                goto LAB_0046c51b;
            case 4:
                uVar32 = (unsigned int)(xDeltaLeft + (int)uVar34);
                uVar24 = (unsigned int)(yDeltaUp + (int)uVar10);
                uVar28 = (unsigned int)(bestPathPoint.x + xDeltaRight);
                param_14i = yDeltaUp4 + bestPathPoint.y;
                goto LAB_0046c50f;
            default:
                uVar24 = (unsigned int)(yDeltaUp + (int)uVar10);
                uVar28 = (unsigned int)(xDeltaLeft + (int)uVar34);
                uVar32 = (unsigned int)(xDeltaLeft + (int)uVar34);
                uVar22x = (unsigned int)(bestPathPoint.x);
                uVar39 = (unsigned int)bestPathPoint.y;
            LAB_0046c50f:
                param_6f = (float)(yDeltaDown4 + (int)uVar39 * 4);
                param_1 = xDeltaLeft4 + (int)uVar22x * 4;
                param_2i = xDeltaRight4 + (int)uVar40 * 4;
                goto LAB_0046c51b;
            }

            param_14i = yDeltaUp4 + (int)uVar10;
            uVar28 = (unsigned int)(xDeltaRight + (int)uVar34);
            param_6f = (float)(yDeltaDown4 + (int)uVar37 * 4);
            param_2i = xDeltaRight4 + (int)uVar34 * 4;

        LAB_0046c51b:
            int param_15i = yDeltaDown4 + (int)uVar39 * 4;
            if ((int)uVar32 < 0) uVar32 = uVar32 + 1;
            if ((int)uVar24 < 0) uVar24 = uVar24 + 1;
            if (param_1 < 0) param_1 = param_1 + 1;
            if ((int)param_6f < 0) param_6f = (float)((int)param_6f + 1);

            // Terrain scan (as decomp).
            int param_14 = 0xfe;
            if (((int)(uVar28 & 0xff) < this->mapValue->map_width) && ((int)((unsigned int)param_14i & 0xffU) < this->mapValue->map_height)) {
                unsigned int local_34 = uVar24 & 0xff;
                if ((byte)uVar24 <= (byte)param_14i) {
                    do {
                        unsigned int local_30 = uVar32 & 0xff;
                        if ((byte)uVar32 <= (byte)uVar28) {
                            RGE_Tile* tile = &this->mapValue->map_row_offset[local_34][uVar32 & 0xff];
                            do {
                                if ((this->initialTile.x != (int)local_30) || (this->initialTile.y != (int)local_34)) {
                                    unsigned int terr = (unsigned int)tile->terrain_type;
                                    if ((terr != (unsigned int)this->currentTerrainException1) &&
                                        (terr != (unsigned int)this->currentTerrainException2) &&
                                        (this->currentTerrainTable[terr] <= 0.0f) &&
                                        ((tile->border_type == 0) ||
                                         (this->currentTerrainTable[this->mapValue->border_types[tile->border_type & 0xf].underlay_terrain] <= 0.0f))) {
                                        goto LAB_0046c674;
                                    }
                                }
                                tile = tile + 1;
                                local_30 = (unsigned int)((byte)local_30 + 1);
                            } while ((byte)local_30 <= (byte)uVar28);
                        }
                        local_34 = (unsigned int)((byte)local_34 + 1);
                    } while ((byte)local_34 <= (byte)param_14i);
                }
                param_14 = 1;
            } else {
            LAB_0046c674:
                param_14 = 0xfe;
            }

            if ((param_14 == 1) && (param_12 == 1)) {
                bool bVar7 = false;
                int height = (param_15i - (int)param_6f) + -1;
                if (height < 0) {
                    param_14 = 1;
                } else if ((height < 0x18) &&
                           ((this->maxTarget.x < param_1 || this->maxTarget.y < (int)param_6f || param_2i < this->minTarget.x ||
                             param_15i < this->minTarget.y))) {
                    int idx = ((int)param_6f & 3) + height * 4;
                    const unsigned int mask1 = kObstructionMasks[idx * 2];
                    const unsigned int mask2 = kObstructionMasks[idx * 2 + 1];
                    if (mask2 == 0) {
                        if (param_1 < param_2i) {
                            uchar* puVar25 = this->obstructionValue[param_1] + ((int)param_6f >> 2);
                            int xx = param_1;
                            do {
                                if ((*(unsigned int*)puVar25 & mask1) != 0) goto LAB_0046c826;
                                xx = xx + 1;
                                puVar25 = puVar25 + 0xff;
                            } while (xx < param_2i);
                        }
                    } else if (param_1 < param_2i) {
                        uchar* puVar25 = this->obstructionValue[param_1] + ((int)param_6f >> 2);
                        int xx = param_1;
                        do {
                            if (((*(unsigned int*)puVar25 & mask1) != 0) || ((*(unsigned int*)(puVar25 + 4) & mask2) != 0)) {
                                param_14 = 0xfe;
                                goto LAB_0046c83b;
                            }
                            xx = xx + 1;
                            puVar25 = puVar25 + 0xff;
                        } while (xx < param_2i);
                        param_14 = 1;
                        goto LAB_0046c83b;
                    }
                    param_14 = 1;
                } else {
                    if (param_1 < param_2i) {
                        float fVar27 = param_6f;
                        int row = param_1 * 0xff;
                        int xx = param_1;
                        do {
                            for (; row = row, (int)fVar27 < param_15i; fVar27 = (float)((int)fVar27 + 1)) {
                                if (this->obstruction(xx, (int)fVar27) != 0) {
                                    if ((this->currentTargetID == -1) || (xx < this->minTarget.x) || (this->maxTarget.x < xx) ||
                                        ((int)fVar27 < this->minTarget.y) || (this->maxTarget.y < (int)fVar27)) {
                                        goto LAB_0046c826;
                                    }
                                    bVar7 = true;
                                }
                            }
                            xx = xx + 1;
                            fVar27 = param_6f;
                        } while (xx < param_2i);
                    }
                    param_14 = (int)!bVar7;
                }
            }

        LAB_0046c83b:
            if (param_14 == 0) {
                goto LAB_0046ca94;
            }

            // Cost adjust and heap insert.
            newTotal = newTotal + (unsigned int)this->miscValue[bestPathPoint.x][bestPathPoint.y] * 0x10;
            this->MGP_costValue[bestPathPoint.x][bestPathPoint.y] = newTotal;
            *puVar12 = (uchar)(i & 7) | this->CurrentFacetMask;

            int heapN = this->numberOpenPathsValue;
            this->numberOpenPathsValue = heapN + 1;
            this->MGP_openPaths[heapN + 1].x = (uchar)bestPathPoint.x;
            this->MGP_openPaths[this->numberOpenPathsValue].y = (uchar)bestPathPoint.y;
            this->MGP_openPaths[this->numberOpenPathsValue].total = newTotal;

            // Percolate up.
            int pos = this->numberOpenPathsValue;
            if (0 < pos) {
                int parent2 = pos / 2;
                uchar sx = this->MGP_openPaths[pos].x;
                uchar sy = this->MGP_openPaths[pos].y;
                int st = this->MGP_openPaths[pos].total;
                while (st < this->MGP_openPaths[parent2].total) {
                    this->MGP_openPaths[pos] = this->MGP_openPaths[parent2];
                    pos = pos / 2;
                    parent2 = parent2 / 2;
                }
                if (pos != this->numberOpenPathsValue) {
                    this->MGP_openPaths[pos].x = sx;
                    this->MGP_openPaths[pos].y = sy;
                    this->MGP_openPaths[pos].total = st;
                }
            }

        LAB_0046ca94:
            i = i + 1;
            SkipBit = SkipBit << 1;
            if (7 < i) {
                iterations = iterations + 1;
                this->startOfPath = 0;
                if (this->numberOpenPathsValue < 1) {
                    goto LAB_0046cedf;
                }
                goto LAB_0046bf0e;
            }
            goto LAB_0046c153;
        }
    }

LAB_0046cedf:
    // Fall back to best traversed node.
    {
        int iVar11 = this->numberOpenPathsValue;
        this->numberOpenPathsValue = iVar11 + 1;
        this->MGP_openPaths[iVar11 + 1].x = this->MGP_bestTraversedPath.x;
        this->MGP_openPaths[this->numberOpenPathsValue].y = this->MGP_bestTraversedPath.y;
        this->MGP_openPaths[this->numberOpenPathsValue].total = 0;
    }

    if ((clearPathOnFail == 1) && (this->copyPath(step) == 0)) {
        Path* p = &obj->pathValue;
        if (obj->storePathInExceptionPath != 0) {
            p = &obj->exceptionPathValue;
        }
        p->killPath();
    } else {
        if (pathDistanceOut != nullptr) {
            *pathDistanceOut = (float)this->MGP_bestTraversedPath.total;
        }
    }

LAB_0046ceaf:
    // Restore current object obstruction map membership.
    if ((this->currentObjectInObMap == 1) && (this->currentObject->inside_obj == nullptr)) {
        ((RGE_Static_Object*)this->currentObject)->addToObstructionMap(this->aiPS);
    }

    // Restore group members that were removed.
    for (int idx = 0; idx < obj->pathingGroupMembers.numberValue; ++idx) {
        int memberId = obj->pathingGroupMembers.value[idx];
        RGE_Static_Object* member = this->worldValue->object(memberId);
        if ((member != nullptr) && (member->id != this->currentObject->id) && (member->lastInObstructionMapValue == 1) &&
            (member->inside_obj == nullptr)) {
            member->addToObstructionMap(this->aiPS);
        }
    }

    return 1;

LAB_0046c826:
    goto LAB_0046ca94;
LAB_0046d19f:
    if ((this->currentObjectInObMap == 1) && (this->currentObject->inside_obj == nullptr)) {
        ((RGE_Static_Object*)this->currentObject)->addToObstructionMap(this->aiPS);
        return 0;
    }
    return 0;
}
