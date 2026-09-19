
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "../include/pathsys.h"
#include "../include/path.h"
#include "../include/game_globals.h"
#include "../include/move_obj.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/panel.h"

extern void operator delete(void* ptr);
extern void* operator new(unsigned int size, void* ptr);
extern int DiagionalDistance[256];
extern unsigned char ObstructionValueShift[4];
extern unsigned char ObstructionValueMask[4];
extern RGE_Base_Game* rge_base_game;

// This two-byte cursor is local to pathsys.cpp. No shared owner declares it.
struct BYTEPoint {
    uchar x;
    uchar y;
};

// The compiler owns the startup wrappers and destructor registration for
PathingSystem pathSystem(0xFF, 0xFF, 0, 0, 0);
PathingSystem aiPathSystem(0xFF, 0xFF, 1, 0, 0);

PathingSystem::PathingSystem(int x, int y, int aiPS, RGE_Map* map, RGE_Game_World* world) {
    this->aiPS = aiPS;
    this->xSizeValue = -1;
    this->ySizeValue = -1;
    this->currentTerrainException1 = -1;
    this->currentTerrainException2 = -1;

    this->numberOpenPathsValue = 0;
    this->numberTraversedPathsValue = 0;
    this->mapValue = 0;
    this->worldValue = 0;
    this->currentObject = 0;
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

    this->initialize(x, y, map, world);
    this->initMisc(0);
    this->zeroObstructionMap();

    aiPS = 0;
    int* distance = DiagionalDistance;
    do {
        *distance = (int)(g_path_diagonal_base - (float)aiPS * g_path_diagonal_scale * g_path_diagonal_sign);
        ++aiPS;
        ++distance;
    } while ((int)distance < (int)(DiagionalDistance + 256));
}

PathingSystem::~PathingSystem() {
}

int PathingSystem::initialize(int x, int y, RGE_Map* map, RGE_Game_World* world) {
    mapValue = map;
    worldValue = world;
    if (map != 0) {
        xSizeValue = map->map_width;
        ySizeValue = map->map_height;
    } else {
        xSizeValue = x;
        ySizeValue = y;
    }
    CurrentFacetMask = 0xF0;
    return 1;
}

void PathingSystem::printToFile(char* filename) {
    int column;
    int i;
    if (filename != 0) {
        FILE* file = fopen(filename, "wa");
        if (file != 0) {
            fprintf(file, "FILENAME: %s\n", filename);
            fprintf(file, "  Dimensions: %d X %d\n", this->xSizeValue << 2, this->ySizeValue << 2);
            fprintf(file, "\n");
            fprintf(file, "       ");

            i = 0;
            if (this->xSizeValue > 0) {
                do {
                    fprintf(file, "%04d ", i);
                    ++i;
                } while (i < this->xSizeValue);
            }

            fprintf(file, "\n");
            fprintf(file, "       ");
            i = 0;
            if (this->xSizeValue > 0) {
                do {
                    fprintf(file, "---- ", i);
                    ++i;
                } while (i < this->xSizeValue);
            }

            fprintf(file, "\n");

            for (i = 0; i < (this->ySizeValue << 2); ++i) {
                    if (i % 4 == 0) {
                        fprintf(file, "R%03d: ", i / 4);
                    } else {
                        fprintf(file, "      ");
                    }

                    for (column = 0; column < (this->xSizeValue << 2); ++column) {
                        if (column % 4 == 0) {
                            fprintf(file, " %1d", this->obstruction(column, i));
                        } else {
                            fprintf(file, "%1d", this->obstruction(column, i));
                        }
                    }

                    if (((i + 1) % 4) == 0) {
                        fprintf(file, "  :R%03d\n\n", i / 4);
                    } else {
                        fprintf(file, "\n", i / 4);
                    }
            }

            fprintf(file, "\n");
            fclose(file);
        }
    }
}

unsigned char PathingSystem::lookupMisc(int x, int y) {
    return this->miscValue[x][y];
}

void PathingSystem::setMisc(int x, int y, unsigned char v) {
    this->miscValue[x][y] = v;
}

void PathingSystem::initMisc(unsigned char v) {
    memset(this->miscValue, v, 65025);
}

void PathingSystem::zeroObstructionMap(void) {
    memset(obstructionValue, 0, sizeof(obstructionValue));
}

unsigned char PathingSystem::obstruction(int x, int y) {
    return (unsigned char)(this->obstructionValue[x][y >> 2] >> ObstructionValueShift[y & 3]) & 3;
}

void PathingSystem::incrementObstruction(int x, int y) {
    unsigned char val = obstructionValue[x][y >> 2];
    unsigned char field = (val >> ObstructionValueShift[y & 3]) & 3;
    if (field < 3) {
        obstructionValue[x][y >> 2] =
            (ObstructionValueMask[y & 3] & val) | ((field + 1) << ObstructionValueShift[y & 3]);
    }
}

void PathingSystem::decrementObstruction(int x, int y) {
    unsigned char val = obstructionValue[x][y >> 2];
    unsigned char field = (val >> ObstructionValueShift[y & 3]) & 3;
    if (field > 0) {
        obstructionValue[x][y >> 2] =
            (ObstructionValueMask[y & 3] & val) | ((field - 1) << ObstructionValueShift[y & 3]);
    }
}

static __inline int estimateDistanceOrdered(int ax, int ay, int bx, int by) {
    int swap;
    int diagonal;
    int straight;

    if (ax < bx) {
        swap = ax;
        ax = bx;
        bx = swap;
    }
    if (ay < by) {
        swap = ay;
        ay = by;
        by = swap;
    }

    ax -= bx;
    ay -= by;
    if (ax < ay) {
        diagonal = ax;
        straight = ay - ax;
    } else {
        diagonal = ay;
        straight = ax - ay;
    }
    return DiagionalDistance[diagonal & 0xff] + (straight << 4);
}

#pragma optimize("y", off)
int PathingSystem::findTilePath(int startX, int startY, int goalX, int goalY, RGE_Moving_Object* unit,
                                float actionRange, int cTargetID, int copyPathWhenDone, float* pathLength,
                                int checkPathingIterations, int checkTerrainFirstTime, int checkCollisions,
                                int stepSize, int unobstructiblePlayerID, int unobstructibleGroupID) {
    int dist;
    int currentEstimate;
    int MGP_goalTolerance;
    int numberIterationCap;
    int iterations;
    int i;
    int SkipBit;
    int copiedX;
    int copiedY;
    int badCollision;
    unsigned char terrainStatus;
    int found;
    int hitId;
    int objectCountOnTile;
    int row;
    int col;
    int minScanX;
    int minScanY;
    int maxScanX;
    int MaxY;
    int left;
    int right;
    int top;
    int bottom;
    int h;
    int maskIndex;
    int foundBlockingOwnGroup;
    int newCost;
    int oldTotal;
    int newTotal;
    int parentCost;
    int oldHeuristic;
    int newHeuristic;
    int misc;
    unsigned char directionFromHere;
    int currentFacet;
    int xDeltaLeft;
    int yDeltaUp;
    int xDeltaRight;
    int yDeltaDown;
    int xDeltaLeft4;
    int yDeltaUp4;
    int yDeltaDown4;
    int xDeltaRight4;
    int MinX4;
    int MinY4;
    int MaxX4;
    int MaxY4;
    int tmp;
    int tmp2;
    int openIndex;
    int parentIndex;
    int insertIndex;
    int hitUnobstructibleObject;
    float unobstructibleObjectHitpoints;
    float fx;
    float fy;
    RGE_Map* map;
    RGE_Tile* tile;
    RGE_Static_Object* target;
    RGE_Static_Object* other;
    RGE_Moving_Object* curObj;
    Path* path;
    unsigned char facetByte;
    unsigned char facetLow;
    unsigned char terrainRow;
    unsigned char terrainCol;
    unsigned int maskA;
    unsigned int maskB;
    unsigned char* obstructionPtr;

    if (startX < 0 || startY < 0 || startX > this->xSizeValue || startY > this->xSizeValue ||
        goalX < 0 || goalY < 0 || goalX > this->xSizeValue || goalY > this->xSizeValue) {
        if (copyPathWhenDone == 1) {
            path = unit->storePathInExceptionPath == 0 ? &unit->pathValue : &unit->exceptionPathValue;
            path->killPath();
        }
        return 0;
    }

    if (actionRange > g_path_min_action_range) {
        dist = estimateDistanceOrdered(goalX, goalY, startX, startY);
        if ((float)dist < actionRange * g_path_goal_tolerance_scale) {
            if (pathLength != 0) *pathLength = 0;
            if (copyPathWhenDone == 1) {
                path = unit->storePathInExceptionPath == 0 ? &unit->pathValue : &unit->exceptionPathValue;
                path->killPath();
            }
            return 1;
        }
        if (unit->maximumSpeed() == g_path_zero_speed) {
            if (pathLength != 0) *pathLength = 0;
            if (copyPathWhenDone == 1) {
                path = unit->storePathInExceptionPath == 0 ? &unit->pathValue : &unit->exceptionPathValue;
                path->killPath();
            }
            return 0;
        }
    }

    this->currentObject = unit;
    this->currentTerrainTable = this->worldValue->terrains[unit->master_obj->terrain];
    this->currentTerrainException1 = unit->currentTerrainException1;
    this->currentTerrainException2 = unit->currentTerrainException2;
    this->currentUnobstructiblePlayerID = unobstructiblePlayerID;
    this->currentUnobstructibleGroupID = unobstructibleGroupID;
    this->currentUnobstructibles.zeroNumber();

    if (MapPathsDisplay != 0) {
        map = this->mapValue;
        row = 0;
        while (row < map->map_height) {
            tile = map->map_row_offset[row];
            col = 0;
            while (col < map->map_width) {
                unsigned char drawAttribute = tile->draw_attribute;
                ++tile;
                ++col;
                (tile - 1)->draw_attribute = (unsigned char)(drawAttribute & 0x70);
                map = this->mapValue;
            }
            ++row;
            map = this->mapValue;
        }
        // The assembly dispatches get_view_panel() then TPanel::set_redraw(2).
        rge_base_game->get_view_panel()->set_redraw(TPanel::RedrawImmediate);
    }

    this->minTarget.x = goalX * 4;
    this->minTarget.y = goalY * 4;
    this->currentTargetID = cTargetID;
    this->maxTarget.x = goalX * 4 + 3;
    this->maxTarget.y = goalY * 4 + 3;
    if (cTargetID != -1) {
        target = this->worldValue->object(cTargetID);
        if (target == 0) {
            this->currentTargetID = -1;
        } else {
            this->minTarget.x = (int)((target->world_x - target->master_obj->radius_x) * g_path_coordinate_scale);
            this->minTarget.y = (int)((target->world_y - target->master_obj->radius_y) * g_path_coordinate_scale);
            this->maxTarget.x = (int)((target->master_obj->radius_x + target->world_x) * g_path_coordinate_scale);
            this->maxTarget.y = (int)((target->master_obj->radius_y + target->world_y) * g_path_coordinate_scale);
        }
    }

    this->startOfPath = 1;
    this->checkTerrainOnFirstPass = checkTerrainFirstTime;
    this->currentObjectInObMap = this->currentObject->removeFromObstructionMap(this->aiPS);

    // VC5 evaluates the Y floor argument before X.
    if (this->passable(this->currentObject, (float)(floor((double)this->currentObject->world_x) - g_path_tile_center_adjustment),
                       (float)(floor((double)this->currentObject->world_y) - g_path_tile_center_adjustment), 1)) {
        // The original stores positive half-tile offsets here.
        this->currentXOffset = 0.5f;
        this->currentYOffset = 0.5f;
    } else {
        this->currentXOffset = unit->world_x - (float)floor((double)unit->world_x);
        this->currentYOffset = unit->world_y - (float)floor((double)unit->world_y);
    }

    curObj = this->currentObject;
    if (curObj->continueCounter >= 10 && curObj->pathingGroupMembers.number() > 0) {
        i = 0;
        while (i < curObj->pathingGroupMembers.number()) {
            other = this->worldValue->object(curObj->pathingGroupMembers[i]);
            if (other != 0 && other->id != this->currentObject->id) {
                unsigned char canShare = other->waitingToMove();
                float cap = other->getSpeed();
                RGE_Moving_Object* movingOther = (RGE_Moving_Object*)other;
                float avoidanceDistance = movingOther->collisionAvoidanceDistance;
                if (canShare != 0 || cap != g_path_zero_speed || avoidanceDistance > g_path_zero_speed) {
                    other->removeFromObstructionMap(this->aiPS);
                }
            }
            curObj = this->currentObject;
            ++i;
        }
    }

    curObj = this->currentObject;
    this->minInitialPosition.x = (int)((curObj->world_x - curObj->master_obj->radius_x) * g_path_coordinate_scale);
    if (this->minInitialPosition.x < 0) this->minInitialPosition.x = 0;
    this->minInitialPosition.y = (int)((curObj->world_y - curObj->master_obj->radius_y) * g_path_coordinate_scale);
    if (this->minInitialPosition.y < 0) this->minInitialPosition.y = 0;
    this->maxInitialPosition.x = (int)((curObj->master_obj->radius_x + curObj->world_x) * g_path_coordinate_scale);
    tmp = this->xSizeValue * 4;
    if (this->maxInitialPosition.x > tmp) this->maxInitialPosition.x = tmp;
    this->maxInitialPosition.y = (int)((curObj->master_obj->radius_y + curObj->world_y) * g_path_coordinate_scale);
    tmp = this->ySizeValue * 4;
    if (this->maxInitialPosition.y > tmp) this->maxInitialPosition.y = tmp;

    curObj->setInitialPoints(this->minInitialPosition, this->maxInitialPosition);

    this->initialTile.y = startY;
    this->initialTile.x = startX;
    this->MGP_closestTargetDistance = -1;
    if (this->CurrentFacetMask >= 0xf0) {
        this->CurrentFacetMask = 0;
        memset(this->facetValue, 0xff, sizeof(this->facetValue));
    } else {
        this->CurrentFacetMask = (unsigned char)(this->CurrentFacetMask + 8);
    }
    this->numberOpenPathsValue = 1;
    this->numberTraversedPathsValue = 0;

    dist = estimateDistanceOrdered(goalX, goalY, startX, startY);
    this->MGP_costValue[startX][startY] = dist;
    this->MGP_openPaths[1].total = dist;
    this->MGP_bestTraversedPath.total = dist;
    this->MGP_openPaths[1].x = (unsigned char)startX;
    this->MGP_openPaths[1].y = (unsigned char)startY;
    this->MGP_openPaths[0].total = -2000000000;
    this->MGP_bestTraversedPath.x = (unsigned char)startX;
    this->MGP_bestTraversedPath.y = (unsigned char)startY;

    if ((float)stepSize <= actionRange) MGP_goalTolerance = (int)(actionRange * g_path_goal_tolerance_scale);
    else MGP_goalTolerance = stepSize << 4;

    float xRadius = this->currentObject->master_obj->radius_x;
    float yRadius = this->currentObject->master_obj->radius_y;
    fx = (this->currentXOffset - g_path_bounds_offset) - xRadius;
    xDeltaLeft = (int)(fx - g_path_rounding_adjustment) - 100;
    xRadius += this->currentXOffset;
    xDeltaRight = (int)(xRadius - g_path_bounds_offset_large) - 100;
    fy = (this->currentYOffset - g_path_bounds_offset) - yRadius;
    yDeltaUp = (int)(fy - g_path_rounding_adjustment) - 100;
    yRadius += this->currentYOffset;
    yDeltaDown = (int)(yRadius - g_path_bounds_offset_large) - 100;
    xDeltaLeft4 = -400 - (int)(fx * g_path_coordinate_scale_negative);
    xDeltaRight4 = -400 - (int)((xRadius - g_path_bounds_offset) * g_path_coordinate_scale_negative);
    yDeltaUp4 = -400 - (int)(fy * g_path_coordinate_scale_negative);
    yDeltaDown4 = -400 - (int)((yRadius - g_path_bounds_offset) * g_path_coordinate_scale_negative);

    iterations = 0;
    tmp = goalX - startX;
    tmp2 = goalY - startY;
    dist = (int)(sqrt((double)(tmp * tmp) + (double)(tmp2 * tmp2)) * g_path_distance_scale);
    dist /= 16;
    numberIterationCap = dist * numberPathingIterations;
    if (dist <= 10) numberIterationCap /= 10;
    else numberIterationCap /= 100;
    if (this->currentObject->owner->id == 0 && numberIterationCap > 100) numberIterationCap = 100;
    if (this->currentObject->owner->computerPlayer() == 1) numberIterationCap = (dist * 0x9c4) / 100;

    while (this->numberOpenPathsValue > 0) {
        XYPoint bestPathPoint;
        XYPoint temp;
        if (numberPathingIterations != -1 && checkPathingIterations == 1 && iterations > numberIterationCap) break;
        if (iterations > 0x4e20) break;

        bestPathPoint.x = this->MGP_openPaths[1].x;
        bestPathPoint.y = this->MGP_openPaths[1].y;
        if (MapPathsDisplay != 0) {
            this->mapValue->map_row_offset[bestPathPoint.y][bestPathPoint.x].draw_attribute = 0x81;
        }

        tmp = goalX - this->MGP_openPaths[1].x;
        tmp2 = goalY - this->MGP_openPaths[1].y;
        currentEstimate = (int)(sqrt((double)(tmp * tmp) + (double)(tmp2 * tmp2)) * g_path_distance_scale);
        if (this->MGP_closestTargetDistance == -1 || currentEstimate < this->MGP_closestTargetDistance) {
            this->MGP_closestTargetDistance = currentEstimate;
        }

        if (currentEstimate < MGP_goalTolerance) {
            if (copyPathWhenDone == 1 && this->copyPath(stepSize) == 0) {
                path = unit->storePathInExceptionPath == 0 ? &unit->pathValue : &unit->exceptionPathValue;
                path->killPath();
                curObj = this->currentObject;
                i = 0;
                while (i < curObj->pathingGroupMembers.number()) {
                    other = this->worldValue->object(curObj->pathingGroupMembers[i]);
                    if (other != 0 && other->id != this->currentObject->id &&
                        other->lastInObstructionMapValue == 1 && other->inside_obj == 0) {
                        other->addToObstructionMap(this->aiPS);
                    }
                    curObj = this->currentObject;
                    ++i;
                }
                goto final_failure_restore;
            }
            if (pathLength != 0) *pathLength = (float)this->MGP_costValue[bestPathPoint.x][bestPathPoint.y];
            curObj = this->currentObject;
            i = 0;
            while (i < curObj->pathingGroupMembers.number()) {
                other = this->worldValue->object(curObj->pathingGroupMembers[i]);
                if (other != 0 && other->id != this->currentObject->id &&
                    other->lastInObstructionMapValue == 1 && other->inside_obj == 0) {
                    other->addToObstructionMap(this->aiPS);
                }
                curObj = this->currentObject;
                ++i;
            }
            goto final_success_restore;
        }

        if (currentEstimate < this->MGP_bestTraversedPath.total) {
            this->MGP_bestTraversedPath.total = currentEstimate;
            this->MGP_bestTraversedPath.x = (unsigned char)bestPathPoint.x;
            this->MGP_bestTraversedPath.y = (unsigned char)bestPathPoint.y;
        }

        ++this->numberTraversedPathsValue;
        int hole = 1;
        int child;
        int heapCount;
        heapCount = this->numberOpenPathsValue;
        // The original heap node copies only the fields used by path search.
        // The two-byte next field is not copied here.
        this->MGP_openPaths[1].x = this->MGP_openPaths[heapCount].x;
        this->MGP_openPaths[1].y = this->MGP_openPaths[heapCount].y;
        this->MGP_openPaths[1].total = this->MGP_openPaths[heapCount].total;
        --heapCount;
        this->numberOpenPathsValue = heapCount;
        copiedX = this->MGP_openPaths[1].x;
        copiedY = this->MGP_openPaths[1].y;
        oldTotal = this->MGP_openPaths[1].total;
        while (hole < heapCount / 2) {
            child = hole * 2;
            if (child < heapCount && this->MGP_openPaths[child + 1].total < this->MGP_openPaths[child].total) ++child;
            if (oldTotal < this->MGP_openPaths[child].total) break;
            this->MGP_openPaths[hole] = this->MGP_openPaths[child];
            hole = child;
        }
        if (hole != 1) {
            this->MGP_openPaths[hole].x = (unsigned char)copiedX;
            this->MGP_openPaths[hole].y = (unsigned char)copiedY;
            this->MGP_openPaths[hole].total = oldTotal;
        }

        i = 0;
        SkipBit = 1;
        temp.x = bestPathPoint.x;
        temp.y = bestPathPoint.y;
        while (i < 8) {
            switch (i) {
            case 0: temp.x -= stepSize; temp.y -= stepSize; break;
            case 1:
            case 2: temp.x += stepSize; break;
            case 3: temp.y += stepSize; break;
            case 4: temp.y += stepSize; break;
            case 5:
            case 6: temp.x -= stepSize; break;
            case 7: temp.y -= stepSize; break;
            }

            facetByte = this->facetValue[bestPathPoint.x][bestPathPoint.y];
            if ((facetByte & 0xf8) == this->CurrentFacetMask) currentFacet = facetByte & 7;
            else currentFacet = 8;
            if ((FacetSkipMask[currentFacet] & SkipBit) != 0) goto next_direction;
            if (temp.x < 0 || temp.y < 0 || temp.x >= this->xSizeValue || temp.y >= this->ySizeValue) goto next_direction;
            if (temp.x == this->initialTile.x && temp.y == this->initialTile.y) goto next_direction;

            tmp = temp.x - bestPathPoint.x;
            tmp2 = temp.y - bestPathPoint.y;
            newCost = (int)(sqrt((double)(tmp * tmp) + (double)(tmp2 * tmp2)) * g_path_distance_scale);
            parentCost = this->MGP_costValue[bestPathPoint.x][bestPathPoint.y];
            oldHeuristic = estimateDistanceOrdered(goalX, goalY, bestPathPoint.x, bestPathPoint.y);
            newHeuristic = estimateDistanceOrdered(goalX, goalY, temp.x, temp.y);
            newTotal = newHeuristic + newCost + parentCost - oldHeuristic;

            facetByte = this->facetValue[temp.x][temp.y];
            if ((facetByte & 0xf8) == this->CurrentFacetMask) directionFromHere = facetByte & 7;
            else directionFromHere = 0xff;
            if (directionFromHere < 8 && this->MGP_costValue[temp.x][temp.y] <= newTotal) goto next_direction;

            terrainStatus = 1;
            switch (i) {
            case 0:
                minScanX = temp.x + xDeltaLeft;
                minScanY = temp.y + yDeltaUp;
                maxScanX = bestPathPoint.x + xDeltaRight;
                MaxY = bestPathPoint.y + yDeltaDown;
                MinX4 = temp.x * 4 + xDeltaLeft4;
                MinY4 = temp.y * 4 + yDeltaUp4;
                MaxX4 = bestPathPoint.x * 4 + xDeltaRight4;
                MaxY4 = bestPathPoint.y * 4 + yDeltaDown4;
                break;
            case 1:
                minScanX = bestPathPoint.x + xDeltaLeft;
                minScanY = temp.y + yDeltaUp;
                maxScanX = bestPathPoint.x + xDeltaRight;
                MaxY = bestPathPoint.y + yDeltaDown;
                MinX4 = bestPathPoint.x * 4 + xDeltaLeft4;
                MinY4 = temp.y * 4 + yDeltaUp4;
                MaxX4 = bestPathPoint.x * 4 + xDeltaRight4;
                MaxY4 = bestPathPoint.y * 4 + yDeltaDown4;
                break;
            case 2:
                minScanX = bestPathPoint.x + xDeltaLeft;
                minScanY = temp.y + yDeltaUp;
                maxScanX = temp.x + xDeltaRight;
                MaxY = bestPathPoint.y + yDeltaDown;
                MinX4 = bestPathPoint.x * 4 + xDeltaLeft4;
                MinY4 = temp.y * 4 + yDeltaUp4;
                MaxX4 = temp.x * 4 + xDeltaRight4;
                MaxY4 = bestPathPoint.y * 4 + yDeltaDown4;
                break;
            case 3:
                minScanX = bestPathPoint.x + xDeltaLeft;
                minScanY = bestPathPoint.y + yDeltaUp;
                maxScanX = temp.x + xDeltaRight;
                MaxY = bestPathPoint.y + yDeltaDown;
                MinX4 = bestPathPoint.x * 4 + xDeltaLeft4;
                MinY4 = bestPathPoint.y * 4 + yDeltaUp4;
                MaxX4 = temp.x * 4 + xDeltaRight4;
                MaxY4 = bestPathPoint.y * 4 + yDeltaDown4;
                break;
            case 4:
                minScanX = bestPathPoint.x + xDeltaLeft;
                minScanY = bestPathPoint.y + yDeltaUp;
                maxScanX = temp.x + xDeltaRight;
                MaxY = temp.y + yDeltaDown;
                MinX4 = bestPathPoint.x * 4 + xDeltaLeft4;
                MinY4 = bestPathPoint.y * 4 + yDeltaUp4;
                MaxX4 = temp.x * 4 + xDeltaRight4;
                MaxY4 = temp.y * 4 + yDeltaDown4;
                break;
            case 5:
                minScanX = bestPathPoint.x + xDeltaLeft;
                minScanY = bestPathPoint.y + yDeltaUp;
                maxScanX = bestPathPoint.x + xDeltaRight;
                MaxY = temp.y + yDeltaDown;
                MinX4 = bestPathPoint.x * 4 + xDeltaLeft4;
                MinY4 = bestPathPoint.y * 4 + yDeltaUp4;
                MaxX4 = bestPathPoint.x * 4 + xDeltaRight4;
                MaxY4 = temp.y * 4 + yDeltaDown4;
                break;
            case 6:
                minScanX = temp.x + xDeltaLeft;
                minScanY = bestPathPoint.y + yDeltaUp;
                maxScanX = bestPathPoint.x + xDeltaRight;
                MaxY = temp.y + yDeltaDown;
                MinX4 = temp.x * 4 + xDeltaLeft4;
                MinY4 = bestPathPoint.y * 4 + yDeltaUp4;
                MaxX4 = bestPathPoint.x * 4 + xDeltaRight4;
                MaxY4 = temp.y * 4 + yDeltaDown4;
                break;
            case 7:
                minScanX = temp.x + xDeltaLeft;
                minScanY = bestPathPoint.y + yDeltaUp;
                maxScanX = bestPathPoint.x + xDeltaRight;
                MaxY = bestPathPoint.y + yDeltaDown;
                MinX4 = temp.x * 4 + xDeltaLeft4;
                MinY4 = bestPathPoint.y * 4 + yDeltaUp4;
                MaxX4 = bestPathPoint.x * 4 + xDeltaRight4;
                MaxY4 = bestPathPoint.y * 4 + yDeltaDown4;
                break;
            default:
                minScanX = temp.x;
                minScanY = temp.y;
                maxScanX = temp.x;
                MaxY = temp.y;
                MinX4 = temp.x * 4 + xDeltaLeft4;
                MinY4 = temp.y * 4 + yDeltaUp4;
                MaxX4 = temp.x * 4 + xDeltaRight4;
                MaxY4 = temp.y * 4 + yDeltaDown4;
                break;
            }
            // Adjust minima only. Leave negative maxima unchanged.
            if (minScanX < 0) ++minScanX;
            if (minScanY < 0) ++minScanY;
            if (MinX4 < 0) ++MinX4;
            if (MinY4 < 0) ++MinY4;
            map = this->mapValue;
            if ((maxScanX & 0xff) >= map->map_width || (MaxY & 0xff) >= map->map_height) {
                terrainStatus = 0xfe;
            } else {
                terrainRow = (unsigned char)minScanY;
                if (terrainRow <= (unsigned char)MaxY) {
                    RGE_Tile** terrainRows = map->map_row_offset;
                    do {
                        terrainCol = (unsigned char)minScanX;
                        tile = &terrainRows[terrainRow][terrainCol];
                        while (terrainCol <= (unsigned char)maxScanX) {
                            if (this->initialTile.x != terrainCol || this->initialTile.y != terrainRow) {
                                unsigned char terrain = tile->terrain_type & 0x1f;
                                float* terrainTable = this->currentTerrainTable;
                                // The original loads cost even for a terrain exception.
                                float terrainValue = terrainTable[terrain];
                                if (terrain != this->currentTerrainException1 &&
                                    terrain != this->currentTerrainException2 && terrainValue <= g_path_zero_terrain_value) {
                                    tmp = tile->border_type & 0x0f;
                                    if (tmp == 0 || terrainTable[map->border_types[tmp].underlay_terrain] <= g_path_zero_terrain_value) {
                                        terrainStatus = 0xfe;
                                        break;
                                    }
                                }
                            }
                            ++tile;
                            ++terrainCol;
                        }
                        ++terrainRow;
                    } while (terrainRow <= (unsigned char)MaxY && terrainStatus == 1);
                }
            }
            badCollision = terrainStatus;

            if (badCollision == 1 && checkCollisions == 1) {
                left = MinX4;
                right = MaxX4;
                top = MinY4;
                bottom = MaxY4;
                h = bottom - top - 1;
                foundBlockingOwnGroup = 0;
                if (h >= 0) {
                    if (h < 0x18 && (this->maxTarget.x < left || this->maxTarget.y < top || right < this->minTarget.x || bottom < this->minTarget.y)) {
                        maskIndex = (top & 3) + h * 4;
                        maskA = ObstructionMasks[maskIndex * 2];
                        maskB = ObstructionMasks[maskIndex * 2 + 1];
                        if (left < right) {
                            obstructionPtr = this->obstructionValue[left] + (top >> 2);
                            col = left;
                            if (maskB == 0) {
                                while (col < right) {
                                    if ((*(unsigned int*)obstructionPtr & maskA) != 0) {
                                        goto obstruction_found;
                                    }
                                    ++col;
                                    obstructionPtr += 0xff;
                                }
                            } else {
                                while (col < right) {
                                    if (((*(unsigned int*)obstructionPtr & maskA) != 0) ||
                                        ((*(unsigned int*)(obstructionPtr + 4) & maskB) != 0)) {
                                        goto obstruction_found;
                                    }
                                    ++col;
                                    obstructionPtr += 0xff;
                                }
                            }
                        }
                    } else if (left < right) {
                        col = left;
                        while (col < right) {
                            row = top;
                            while (row < bottom) {
                                if (((this->obstructionValue[col][row >> 2] >> (ObstructionValueShift[row & 3] & 0x1f)) & 3) != 0) {
                                    if (this->currentTargetID == -1 || col < this->minTarget.x || this->maxTarget.x < col || row < this->minTarget.y || this->maxTarget.y < row) {
                                        goto obstruction_found;
                                    }
                                    foundBlockingOwnGroup = 1;
                                }
                                ++row;
                            }
                            ++col;
                        }
                    }
                }
                badCollision = foundBlockingOwnGroup != 1;
                goto obstruction_done;

obstruction_found:
                badCollision = 0xfe;
obstruction_done:
                ;
            }

            unobstructibleObjectHitpoints = 0.0f;
            hitUnobstructibleObject = 0;
            if (badCollision == 0xfe) {
                if (this->currentUnobstructibleGroupID == -1) goto next_direction;
                found = 0;
                minScanX = temp.x - 1;
                if (minScanX < 0) minScanX = 0;
                maxScanX = temp.x + 1;
                row = minScanX;
                while (row <= maxScanX && row < this->xSizeValue && found == 0) {
                    minScanY = temp.y - 1;
                    if (minScanY < 0) minScanY = 0;
                    MaxY = temp.y + 1;
                    col = minScanY;
                    while (col <= MaxY && col < this->ySizeValue && found == 0) {
                        objectCountOnTile = 0;
                        hitId = this->worldValue->objectGroupOnTile(this->currentUnobstructiblePlayerID, this->currentUnobstructibleGroupID, row, col, objectCountOnTile);
                        if (hitId == -1) {
                            if (objectCountOnTile > 0) found = 1;
                        } else {
                            other = this->worldValue->object(hitId);
                            if (other != 0) {
                                unobstructibleObjectHitpoints = other->hp;
                                hitUnobstructibleObject = 1;
                            }
                        }
                        ++col;
                    }
                    ++row;
                }
                if (found == 1) goto next_direction;
            }

            misc = this->miscValue[temp.x][temp.y];
            newTotal += misc * 0x10;
            if (hitUnobstructibleObject == 1) {
                if (unobstructibleObjectHitpoints < 10.0f) newTotal += 0x10;
                else newTotal += 0x3c;
            }
            facetByte = this->facetValue[bestPathPoint.x][bestPathPoint.y];
            if ((facetByte & 0xf8) == this->CurrentFacetMask) facetLow = facetByte & 7;
            else facetLow = 0xff;
            if (i != facetLow) ++newTotal;
            if (badCollision == 0) newTotal = 0;

            this->MGP_costValue[temp.x][temp.y] = newTotal;
            this->facetValue[temp.x][temp.y] = (unsigned char)((i & 7) | this->CurrentFacetMask);
            openIndex = this->numberOpenPathsValue + 1;
            this->numberOpenPathsValue = openIndex;
            this->MGP_openPaths[openIndex].x = (unsigned char)temp.x;
            this->MGP_openPaths[openIndex].y = (unsigned char)temp.y;
            this->MGP_openPaths[openIndex].total = newTotal;

            insertIndex = openIndex;
            if (insertIndex > 0) {
                copiedX = this->MGP_openPaths[insertIndex].x;
                copiedY = this->MGP_openPaths[insertIndex].y;
                oldTotal = this->MGP_openPaths[insertIndex].total;
                parentIndex = insertIndex / 2;
                while (oldTotal < this->MGP_openPaths[parentIndex].total) {
                    this->MGP_openPaths[insertIndex] = this->MGP_openPaths[parentIndex];
                    insertIndex = insertIndex / 2;
                    parentIndex = parentIndex / 2;
                }
                if (insertIndex != openIndex) {
                    this->MGP_openPaths[insertIndex].x = (unsigned char)copiedX;
                    this->MGP_openPaths[insertIndex].y = (unsigned char)copiedY;
                    this->MGP_openPaths[insertIndex].total = oldTotal;
                }
            }
            if (badCollision == 0) {
                if (copyPathWhenDone == 1 && this->copyPath(stepSize) == 0) {
                    path = unit->storePathInExceptionPath == 0 ? &unit->pathValue : &unit->exceptionPathValue;
                    path->killPath();
                    curObj = this->currentObject;
                    i = 0;
                    while (i < curObj->pathingGroupMembers.number()) {
                        other = this->worldValue->object(curObj->pathingGroupMembers[i]);
                        if (other != 0 && other->id != this->currentObject->id &&
                            other->lastInObstructionMapValue == 1 && other->inside_obj == 0) {
                            other->addToObstructionMap(this->aiPS);
                        }
                        curObj = this->currentObject;
                        ++i;
                    }
                    goto final_failure_restore;
                }
                if (pathLength != 0) *pathLength = (float)this->MGP_costValue[bestPathPoint.x][bestPathPoint.y];
                curObj = this->currentObject;
                i = 0;
                while (i < curObj->pathingGroupMembers.number()) {
                    other = this->worldValue->object(curObj->pathingGroupMembers[i]);
                    if (other != 0 && other->id != this->currentObject->id &&
                        other->lastInObstructionMapValue == 1 && other->inside_obj == 0) {
                        other->addToObstructionMap(this->aiPS);
                    }
                    curObj = this->currentObject;
                    ++i;
                }
                goto final_success_restore;
            }

next_direction:
            ++i;
            SkipBit <<= 1;
        }

        ++iterations;
        this->startOfPath = 0;
    }

    goto path_exhausted;

final_success_restore:
    if (this->currentObjectInObMap == 1 && this->currentObject->inside_obj == 0) {
        this->currentObject->addToObstructionMap(this->aiPS);
    }
    return 1;

path_exhausted:
    openIndex = this->numberOpenPathsValue + 1;
    this->numberOpenPathsValue = openIndex;
    this->MGP_openPaths[openIndex].x = this->MGP_bestTraversedPath.x;
    this->MGP_openPaths[openIndex].y = this->MGP_bestTraversedPath.y;
    this->MGP_openPaths[openIndex].total = 0;
    if (openIndex > 0) {
        copiedX = this->MGP_openPaths[openIndex].x;
        copiedY = this->MGP_openPaths[openIndex].y;
        oldTotal = this->MGP_openPaths[openIndex].total;
        insertIndex = openIndex;
        parentIndex = insertIndex / 2;
        while (oldTotal < this->MGP_openPaths[parentIndex].total) {
            this->MGP_openPaths[insertIndex] = this->MGP_openPaths[parentIndex];
            insertIndex = insertIndex / 2;
            parentIndex = parentIndex / 2;
        }
        if (insertIndex != openIndex) {
            this->MGP_openPaths[insertIndex].x = (unsigned char)copiedX;
            this->MGP_openPaths[insertIndex].y = (unsigned char)copiedY;
            this->MGP_openPaths[insertIndex].total = oldTotal;
        }
    }

    if (copyPathWhenDone == 1 && this->copyPath(stepSize) == 0) {
        path = unit->storePathInExceptionPath == 0 ? &unit->pathValue : &unit->exceptionPathValue;
        path->killPath();
        curObj = this->currentObject;
        i = 0;
        while (i < curObj->pathingGroupMembers.number()) {
            other = this->worldValue->object(curObj->pathingGroupMembers[i]);
            if (other != 0 && other->id != this->currentObject->id &&
                other->lastInObstructionMapValue == 1 && other->inside_obj == 0) {
                other->addToObstructionMap(this->aiPS);
            }
            curObj = this->currentObject;
            ++i;
        }
    } else {
        if (pathLength != 0) *pathLength = (float)this->MGP_bestTraversedPath.total;
        curObj = this->currentObject;
        i = 0;
        while (i < curObj->pathingGroupMembers.number()) {
            other = this->worldValue->object(curObj->pathingGroupMembers[i]);
            if (other != 0 && other->id != this->currentObject->id &&
                other->lastInObstructionMapValue == 1 && other->inside_obj == 0) {
                other->addToObstructionMap(this->aiPS);
            }
            curObj = this->currentObject;
            ++i;
        }
    }

    goto final_failure_restore;

final_failure_restore:
    if (this->currentObjectInObMap == 1 && this->currentObject->inside_obj == 0) {
        this->currentObject->addToObstructionMap(this->aiPS);
    }
    return 0;
}
#pragma optimize("y", on)

void PathingSystem::incrementInitialPaths() {
    ++numInitialPathsValue;
}

void PathingSystem::incrementContinuePaths() {
    ++numContinuePathsValue;
}

void PathingSystem::incrementCanPaths() {
    ++numCanPathsValue;
}

int PathingSystem::passable(RGE_Moving_Object* obj, float newX, float newY, int checkTerrain) {
    this->currentObject = obj;
    this->currentTerrainTable =
        this->worldValue->terrains[obj->master_obj->terrain];
    this->initialTile.x = -1;
    this->initialTile.y = -1;
    this->minInitialPosition.x = -1;
    this->minInitialPosition.y = -1;
    this->maxInitialPosition.x = -1;
    this->maxInitialPosition.y = -1;

    float currentXOffset = newX - (float)floor((double)newX);
    float currentYOffset = newY - (float)floor((double)newY);
    float xRadius = obj->master_obj->radius_x;
    float yRadius = obj->master_obj->radius_y;

    int minX = (int)newX * 4 -
        (int)(((currentXOffset - g_path_bounds_offset) - xRadius) * g_path_coordinate_scale_negative) - 400;
    int minY = (int)newY * 4 -
        (int)(((currentYOffset - g_path_bounds_offset) - yRadius) * g_path_coordinate_scale_negative) - 400;
    int maxX = (int)newX * 4 -
        (int)((xRadius + currentXOffset - g_path_bounds_offset) * g_path_coordinate_scale_negative) - 400;
    int maxY = (int)newY * 4 -
        (int)((yRadius + currentYOffset - g_path_bounds_offset) * g_path_coordinate_scale_negative) - 400;

    if (minX < 0) {
        ++minX;
    }
    if (minY < 0) {
        ++minY;
    }

    if (checkTerrain != 0) {
        unsigned char minTileX = (unsigned char)(minX >> 2);
        unsigned char minTileY = (unsigned char)(minY >> 2);
        unsigned char maxTileX = (unsigned char)(maxX >> 2);
        unsigned char maxTileY = (unsigned char)(maxY >> 2);

        if ((int)maxTileX >= this->mapValue->map_width || (int)maxTileY >= this->mapValue->map_height) {
            return 0;
        }

        unsigned char tileY = minTileY;
        if (tileY <= maxTileY) {
            do {
                unsigned char tileX = minTileX;
                RGE_Tile* tile = this->mapValue->map_row_offset[tileY] + tileX;
                if (tileX <= maxTileX) {
                    do {
                        if (this->initialTile.x != tileX || this->initialTile.y != tileY) {
                            int terrain = tile->terrain_type & 0x1f;
                            float terrainPassability = this->currentTerrainTable[terrain];
                            if (terrain != this->currentTerrainException1 && terrain != this->currentTerrainException2 &&
                                !(terrainPassability > g_path_zero_terrain_value)) {
                                int border = tile->border_type & 0x0f;
                                if (border == 0) {
                                    return 0;
                                }
                                int underlay =
                                    this->mapValue->border_types[border].underlay_terrain;
                                if (!(this->currentTerrainTable[underlay] > g_path_zero_terrain_value)) {
                                    return 0;
                                }
                            }
                        }
                        ++tile;
                        ++tileX;
                    } while (tileX <= maxTileX);
                }
                ++tileY;
            } while (tileY <= maxTileY);
        }
    }

    int inObMap = obj->removeFromObstructionMap(this->aiPS);
    int foundTargetObstruction = 0;
    int height = maxY - minY - 1;

    if (height >= 0) {
        if (height < 0x18 && (minX > this->maxTarget.x || minY > this->maxTarget.y ||
             maxX < this->minTarget.x || maxY < this->minTarget.y)) {
            int maskIndex = (minY & 3) + height * 4;
            unsigned long maskA = ObstructionMasks[maskIndex * 2];
            unsigned long maskB = ObstructionMasks[maskIndex * 2 + 1];
            int column = minX;
            if (column < maxX) {
                unsigned char* obstruction =
                    this->obstructionValue[column] + (minY >> 2);
                if (maskB == 0) {
                    do {
                        if ((*(unsigned long*)obstruction & maskA) != 0) {
                            goto obstruction_found;
                        }
                        ++column;
                        obstruction += 0xff;
                    } while (column < maxX);
                } else {
                    do {
                        if ((*(unsigned long*)obstruction & maskA) != 0 ||
                            (*(unsigned long*)(obstruction + 4) & maskB) != 0) {
                            goto obstruction_found;
                        }
                        ++column;
                        obstruction += 0xff;
                    } while (column < maxX);
                }
            }
        } else {
            int column = minX;
            if (column < maxX) {
                do {
                    int row = minY;
                    if (row < maxY) {
                        do {
                            if (((this->obstructionValue[column][row >> 2] >> (ObstructionValueShift[row & 3] & 0x1f)) &
                                 3) != 0) {
                                if (this->currentTargetID == -1 || column < this->minTarget.x ||
                                    this->maxTarget.x < column || row < this->minTarget.y || this->maxTarget.y < row) {
                                    goto obstruction_found;
                                }
                                foundTargetObstruction = 1;
                            }
                            ++row;
                        } while (row < maxY);
                    }
                    ++column;
                } while (column < maxX);
            }
        }
    }

    if (foundTargetObstruction == 1) {
        goto obstruction_found;
    }

    if (inObMap != 0 && obj->inside_obj == 0) {
        obj->addToObstructionMap(this->aiPS);
    }
    return 1;

obstruction_found:
    if (inObMap != 0 && obj->inside_obj == 0) {
        obj->addToObstructionMap(this->aiPS);
    }
    return 0;
}

long PathingSystem::checksum(void) {
    unsigned int value = 0;
    unsigned char (*row)[0xFF] = this->obstructionValue;
    int y = 0x3FC;

    do {
        int x = 0;
        do {
            value ^= (*row)[x];
            x++;
        } while (x < 0xFF);
        row = row + 1;
        y = y - 1;
    } while (y != 0);
    return value;
}

void PathingSystem::printState(RGE_Moving_Object* unit) {
    unit->logDebug("    There are %d open paths and %d traversed paths.",
                   this->numberOpenPathsValue, this->numberTraversedPathsValue);
    unit->logDebug("    The open paths:");

    int i = 1;
    if (i <= this->numberOpenPathsValue) {
        unsigned char* path = &this->MGP_openPaths[1].y;
        do {
            unsigned char facet = this->facetValue[path[-1]][path[0]];
            if ((facet & 0xf8) == this->CurrentFacetMask) {
                facet &= 7;
            } else {
                facet = 0xff;
            }
            unit->logDebug("      %5d: (%d, %d), total=%d, facet=%d.", i, path[-1], path[0], *(int*)(path + 3), facet);
            ++i;
            path += 8;
        } while (i <= this->numberOpenPathsValue);
    }
}

int PathingSystem::copyPath(int stepSize) {
    uchar previousFacet;

    {
        Path* path;
        if (this->currentObject->storePathInExceptionPath == 0)
            path = &this->currentObject->pathValue;
        else
            path = &this->currentObject->exceptionPathValue;
        path->killPath();
    }

    BYTEPoint temp;
    temp.x = this->MGP_openPaths[1].x;
    temp.y = this->MGP_openPaths[1].y;
    int fooX = temp.x;
    int fooY = temp.y;
    previousFacet = 0xFF;
    uchar facetByte = this->facetValue[temp.x][temp.y];
    uchar currentFacet;
    if ((facetByte & 0xF8) == this->CurrentFacetMask)
        currentFacet = facetByte & 7;
    else
        currentFacet = 0xFF;

    RGE_Moving_Object* object = this->currentObject;
    Waypoint wp;
    wp.x = (float)fooX + this->currentXOffset;
    wp.y = (float)fooY + this->currentYOffset;
    wp.z = object->world_z;
    wp.facetToNextWaypoint = currentFacet;

    {
        Path* path = object->storePathInExceptionPath == 0
            ? &object->pathValue
            : &object->exceptionPathValue;
        path->initToStart();
    }

    do {
        if (this->initialTile.x == fooX && this->initialTile.y == fooY) {
            if (this->currentObject->storePathInExceptionPath == 0) {
                if (this->currentObject->pathValue.insertAtCurrent(wp) == 0)
                    return 0;
            } else {
                if (this->currentObject->exceptionPathValue.insertAtCurrent(wp) == 0)
                    return 0;
            }
            return 1;
        }

        if (currentFacet != previousFacet) {
            if (this->currentObject->storePathInExceptionPath == 0) {
                if (this->currentObject->pathValue.insertAtCurrent(wp) == 0)
                    return 0;
            } else {
                if (this->currentObject->exceptionPathValue.insertAtCurrent(wp) == 0)
                    return 0;
            }
        }

        if (this->currentUnobstructibleGroupID != -1) {
            int minX = fooX - 1;
            int tWX2 = fooX + 1;
            if (minX < 0) {
                minX = 0;
                ++tWX2;
            } else if (tWX2 >= this->xSizeValue) {
                --minX;
                tWX2 = this->xSizeValue - 1;
            }

            int tWY1 = fooY - 1;
            int tWY2 = fooY + 1;
            if (tWY1 < 0) {
                tWY1 = 0;
                ++tWY2;
            } else if (tWY2 >= this->ySizeValue) {
                --tWY1;
                tWY2 = this->ySizeValue - 1;
            }

            for (int tileX = minX; tileX <= tWX2; ++tileX) {
                for (int tileY = tWY1; tileY <= tWY2; ++tileY) {
                    int objectCountOnTile = 0;
                    int id = this->worldValue->objectGroupOnTile(this->currentUnobstructiblePlayerID,
                                                                 this->currentUnobstructibleGroupID, tileX, tileY, objectCountOnTile);
                    if (id != -1)
                        this->currentUnobstructibles.add(id);
                }
            }
        }

        switch ((int)currentFacet) {
        case 0:
            temp.x += (uchar)stepSize;
            temp.y += (uchar)stepSize;
            break;
        case 1:
            temp.y += (uchar)stepSize;
            break;
        case 2:
            temp.x -= (uchar)stepSize;
            temp.y += (uchar)stepSize;
            break;
        case 3:
            temp.x -= (uchar)stepSize;
            break;
        case 4:
            temp.x -= (uchar)stepSize;
            temp.y -= (uchar)stepSize;
            break;
        case 5:
            temp.y -= (uchar)stepSize;
            break;
        case 6:
            temp.x += (uchar)stepSize;
            temp.y -= (uchar)stepSize;
            break;
        case 7:
            temp.x += (uchar)stepSize;
            break;
        }

        previousFacet = currentFacet;
        fooX = temp.x;
        fooY = temp.y;
        facetByte = this->facetValue[fooX][fooY];
        if ((facetByte & 0xF8) == this->CurrentFacetMask)
            currentFacet = facetByte & 7;
        else
            currentFacet = 0xFF;
        wp.x = (float)fooX + this->currentXOffset;
        wp.y = (float)fooY + this->currentYOffset;
        wp.facetToNextWaypoint = currentFacet;
    } while (true);
}

void PathingSystem::copyUnobstructibles(ManagedArray<int>& d) {
    int i = this->currentUnobstructibles.number();
    if (i >= 0) {
        do {
            d.add(this->currentUnobstructibles[i]);

            --i;
        } while (i >= 0);
    }
}
