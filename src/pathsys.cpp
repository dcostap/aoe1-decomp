
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
extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);
extern void* operator new(unsigned int size, void* ptr);
extern int DiagionalDistance[256];
extern int FacetSkipMask[8];
extern const unsigned char ObstructionValueShift[4];
extern const unsigned char ObstructionValueMask[4];
extern const unsigned int ObstructionMasks[];
extern RGE_Base_Game* rge_base_game;

// This two-byte cursor is local to pathsys.cpp. No shared owner declares it.
struct BYTEPoint {
    uchar x;
    uchar y;
};

// The compiler owns the startup wrappers and destructor registration for
PathingSystem pathSystem(0xFF, 0xFF, 0, 0, 0);
PathingSystem aiPathSystem(0xFF, 0xFF, 1, 0, 0);

PathingSystem::PathingSystem(int xSize, int ySize, int aiPS,
                             RGE_Map* map, RGE_Game_World* world)
{
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

    this->initialize(xSize, ySize, map, world);
    this->initMisc(0);
    this->zeroObstructionMap();

    aiPS = 0;
    int* distance = DiagionalDistance;
    do {
        *distance = (int)(DAT_00570e50 - (float)aiPS * DAT_00570e48 * DAT_00570e4c);
        ++aiPS;
        ++distance;
    } while ((int)distance < (int)(DiagionalDistance + 256));
}

PathingSystem::~PathingSystem()
{
}

int PathingSystem::initialize(int xSize, int ySize, RGE_Map* map, RGE_Game_World* world) {
    mapValue = map;
    worldValue = world;
    if (map != 0) {
        xSizeValue = map->map_width;
        ySizeValue = map->map_height;
    } else {
        xSizeValue = xSize;
        ySizeValue = ySize;
    }
    CurrentFacetMask = 0xF0;
    return 1;
}

void PathingSystem::printToFile(char* filename)
{
    int column;
    int i;
    if (filename != 0) {
        FILE* file = fopen(filename, "wa");
        if (file != 0) {
            fprintf(file, "FILENAME: %s\n", filename);
            fprintf(file, "  Dimensions: %d X %d\n",
                    this->xSizeValue << 2, this->ySizeValue << 2);
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

unsigned char PathingSystem::lookupMisc(int row, int column) {
    return this->miscValue[row][column];
}

void PathingSystem::setMisc(int row, int column, unsigned char value) {
    this->miscValue[row][column] = value;
}

void PathingSystem::initMisc(unsigned char value) {
    memset(this->miscValue, value, 0xFE01);
}

void PathingSystem::zeroObstructionMap(void) {
    memset(obstructionValue, 0, sizeof(obstructionValue));
}

unsigned char PathingSystem::obstruction(int x, int y) {
    return (unsigned char)(this->obstructionValue[x][y >> 2] >> ObstructionValueShift[y & 3]) & 3;
}

void PathingSystem::incrementObstruction(int x, int y) {
    unsigned char* ptr = &obstructionValue[x][y >> 2];
    unsigned char val = *ptr;
    unsigned char field = (val >> ObstructionValueShift[y & 3]) & 3;
    if (field >= 3) {
        return;
    }
    *ptr = (ObstructionValueMask[y & 3] & val) | ((field + 1) << ObstructionValueShift[y & 3]);
}

void PathingSystem::decrementObstruction(int x, int y) {
    unsigned char val = obstructionValue[x][y >> 2];
    unsigned char field = (val >> ObstructionValueShift[y & 3]) & 3;
    if (field > 0) {
        obstructionValue[x][y >> 2] =
            (ObstructionValueMask[y & 3] & val) | ((field - 1) << ObstructionValueShift[y & 3]);
    }
}

static __inline void restoreCollidingObjects(PathingSystem* ps)
{
    RGE_Moving_Object* object = ps->currentObject;
    int index = 0;
    while (index < object->pathingGroupMembers.numberValue) {
        RGE_Static_Object* other =
            ps->worldValue->object(object->pathingGroupMembers[index]);
        if (other != 0 && other->id != ps->currentObject->id &&
            other->lastInObstructionMapValue == 1 && other->inside_obj == 0) {
            other->addToObstructionMap(ps->aiPS);
        }
        ++index;
    }
}

static __inline int estimateDistanceOrdered(int ax, int ay, int bx, int by)
{
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
int PathingSystem::findTilePath(int startX, int startY, int goalX, int goalY, RGE_Moving_Object* obj,
                                float tolerance, int targetID, int mode, float* costOut,
                                int useIterationCap, int checkTerrain, int checkObstructions,
                                int step, int unobPlayerID, int unobGroupID)
{
    int dist;
    int currentEstimate;
    int MGP_goalTolerance;
    int numberIterationCap;
    int iterations;
    int i;
    int SkipBit;
    int heapCount;
    int hole;
    int child;
    int copiedX;
    int copiedY;
    XYPoint bestPathPoint;
    XYPoint temp;
    int status;
    unsigned char terrainStatus;
    int found;
    int hitCount;
    int hitId;
    int objectCountOnTile;
    int row;
    int col;
    int minScanX;
    int minScanY;
    int maxScanX;
    int maxScanY;
    int left;
    int right;
    int top;
    int bottom;
    int h;
    int maskIndex;
    int foundBlockingOwnGroup;
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
    int quarterMinX;
    int quarterMinY;
    int yDeltaDown4;
    int xDeltaRight4;
    int scanLeftRaw;
    int scanTopRaw;
    int scanRightRaw;
    int scanBottomRaw;
    int tmp;
    int tmp2;
    int openIndex;
    int parentIndex;
    int insertIndex;
    int restoreResult;
    int reached;
    float unobstructibleObjectHitpoints;
    float fx;
    float fy;
    RGE_Map* map;
    RGE_Tile* tile;
    RGE_Static_Object* target;
    RGE_Static_Object* other;
    RGE_Moving_Object* curObj;
    RGE_Master_Static_Object* master;
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
        if (mode == 1) {
            path = obj->storePathInExceptionPath == 0 ? &obj->pathValue : &obj->exceptionPathValue;
            path->killPath();
        }
        return 0;
    }

    if (tolerance > DAT_00570e54) {
        dist = estimateDistanceOrdered(goalX, goalY, startX, startY);
        if ((float)dist < tolerance * DAT_00570e58) {
            if (costOut != 0) *costOut = 0;
            if (mode == 1) {
                path = obj->storePathInExceptionPath == 0 ? &obj->pathValue : &obj->exceptionPathValue;
                path->killPath();
            }
            return 1;
        }
        if (obj->maximumSpeed() == DAT_00570e5c) {
            if (costOut != 0) *costOut = 0;
            if (mode == 1) {
                path = obj->storePathInExceptionPath == 0 ? &obj->pathValue : &obj->exceptionPathValue;
                path->killPath();
            }
            return 0;
        }
    }

    this->currentObject = obj;
    this->currentTerrainTable = this->worldValue->terrains[obj->master_obj->terrain];
    this->currentTerrainException1 = obj->currentTerrainException1;
    this->currentTerrainException2 = obj->currentTerrainException2;
    this->currentUnobstructiblePlayerID = unobPlayerID;
    this->currentUnobstructibleGroupID = unobGroupID;
    this->currentUnobstructibles.numberValue = 0;

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
            }
            ++row;
            map = this->mapValue;
        }
        // The assembly dispatches get_view_panel() then TPanel::set_redraw(2).
        rge_base_game->get_view_panel()->set_redraw(TPanel::RedrawImmediate);
    }

    this->minTarget.x = goalX * 4;
    this->minTarget.y = goalY * 4;
    this->currentTargetID = targetID;
    this->maxTarget.x = goalX * 4 + 3;
    this->maxTarget.y = goalY * 4 + 3;
    if (targetID != -1) {
        target = this->worldValue->object(targetID);
        if (target == 0) {
            this->currentTargetID = -1;
        } else {
            this->minTarget.x = (int)((target->world_x - target->master_obj->radius_x) * DAT_00570e60);
            this->minTarget.y = (int)((target->world_y - target->master_obj->radius_y) * DAT_00570e60);
            this->maxTarget.x = (int)((target->master_obj->radius_x + target->world_x) * DAT_00570e60);
            this->maxTarget.y = (int)((target->master_obj->radius_y + target->world_y) * DAT_00570e60);
        }
    }

    this->startOfPath = 1;
    this->checkTerrainOnFirstPass = checkTerrain;
    this->currentObjectInObMap = obj->removeFromObstructionMap(this->aiPS);

    fx = (float)floor((double)obj->world_x) - DAT_00570e64;
    fy = (float)floor((double)obj->world_y) - DAT_00570e64;
    if (this->passable(obj, fx, fy, 1) == 0) {
        this->currentXOffset = obj->world_x - (float)floor((double)obj->world_x);
        this->currentYOffset = obj->world_y - (float)floor((double)obj->world_y);
    } else {
        this->currentXOffset = DAT_00570e64;
        this->currentYOffset = DAT_00570e64;
    }

    curObj = this->currentObject;
    if (curObj->continueCounter >= 10 && curObj->pathingGroupMembers.numberValue > 0) {
        i = 0;
        while (i < curObj->pathingGroupMembers.numberValue) {
            if (curObj->pathingGroupMembers.maximumSizeValue - 1 < i) {
                int* newValue = (int*)operator_new(i * 4 + 4);
                if (newValue != 0) {
                    int j = 0;
                    while (j < curObj->pathingGroupMembers.maximumSizeValue && j < i + 1) {
                        newValue[j] = curObj->pathingGroupMembers.value[j];
                        ++j;
                    }
                    operator_delete(curObj->pathingGroupMembers.value);
                    curObj->pathingGroupMembers.value = newValue;
                    curObj->pathingGroupMembers.maximumSizeValue = i + 1;
                }
            }
            other = this->worldValue->object(curObj->pathingGroupMembers.value[i]);
            if (other != 0 && other->id != this->currentObject->id) {
                unsigned char canShare = other->waitingToMove();
                float cap = other->getSpeed();
                float held = other->attribute_amount_held;
                if (canShare != 0 || cap != DAT_00570e5c || held > DAT_00570e5c) {
                    other->removeFromObstructionMap(this->aiPS);
                }
            }
            curObj = this->currentObject;
            ++i;
        }
    }

    curObj = this->currentObject;
    master = curObj->master_obj;
    this->minInitialPosition.x = (int)((curObj->world_x - master->radius_x) * DAT_00570e60);
    if (this->minInitialPosition.x < 0) this->minInitialPosition.x = 0;
    this->minInitialPosition.y = (int)((curObj->world_y - master->radius_y) * DAT_00570e60);
    if (this->minInitialPosition.y < 0) this->minInitialPosition.y = 0;
    this->maxInitialPosition.x = (int)((master->radius_x + curObj->world_x) * DAT_00570e60);
    tmp = this->xSizeValue * 4;
    if (this->maxInitialPosition.x > tmp) this->maxInitialPosition.x = tmp;
    this->maxInitialPosition.y = (int)((master->radius_y + curObj->world_y) * DAT_00570e60);
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

    if ((float)step <= tolerance) MGP_goalTolerance = (int)(tolerance * DAT_00570e58);
    else MGP_goalTolerance = step << 4;

    fx = (this->currentXOffset - DAT_00570e68) - master->radius_x;
    xDeltaLeft = (int)(fx - DAT_00570e6c) - 100;
    xDeltaRight = (int)((master->radius_x + this->currentXOffset) - DAT_00570e70) - 100;
    quarterMinX = -400 - (int)(fx * DAT_00570e74);
    xDeltaRight4 = -400 - (int)((master->radius_x + this->currentXOffset - DAT_00570e68) * DAT_00570e74);
    fy = (this->currentYOffset - DAT_00570e68) - master->radius_y;
    yDeltaUp = (int)(fy - DAT_00570e6c) - 100;
    yDeltaDown = (int)((master->radius_y + this->currentYOffset) - DAT_00570e70) - 100;
    quarterMinY = -400 - (int)(fy * DAT_00570e74);
    yDeltaDown4 = -400 - (int)((master->radius_y + this->currentYOffset - DAT_00570e68) * DAT_00570e74);

    tmp = goalX - startX;
    tmp2 = goalY - startY;
    dist = (int)(sqrt((double)(tmp * tmp) + (double)(tmp2 * tmp2)) * DAT_00570e78);
    dist = (dist + ((dist >> 31) & 0x0f)) >> 4;
    if (dist <= 10) numberIterationCap = (dist * numberPathingIterations) / 10;
    else numberIterationCap = (dist * numberPathingIterations) / 100;
    if (this->currentObject->owner->id == 0 && numberIterationCap > 100) numberIterationCap = 100;
    if (this->currentObject->owner->computerPlayer() == 1) numberIterationCap = (dist * 0x9c4) / 100;

    iterations = 0;
    while (this->numberOpenPathsValue > 0) {
        if (numberPathingIterations != -1 && useIterationCap == 1 && iterations > numberIterationCap) break;
        if (iterations > 0x4e20) break;

        bestPathPoint.x = this->MGP_openPaths[1].x;
        bestPathPoint.y = this->MGP_openPaths[1].y;
        if (MapPathsDisplay != 0) {
            this->mapValue->map_row_offset[bestPathPoint.y][bestPathPoint.x].draw_attribute = 0x81;
        }

        tmp = goalX - this->MGP_openPaths[1].x;
        tmp2 = goalY - this->MGP_openPaths[1].y;
        currentEstimate = (int)(sqrt((double)(tmp * tmp) + (double)(tmp2 * tmp2)) * DAT_00570e78);
        if (this->MGP_closestTargetDistance == -1 || currentEstimate < this->MGP_closestTargetDistance) {
            this->MGP_closestTargetDistance = currentEstimate;
        }

        if (currentEstimate < MGP_goalTolerance) {
            if (mode == 1 && this->copyPath(step) == 0) {
                path = obj->storePathInExceptionPath == 0 ? &obj->pathValue : &obj->exceptionPathValue;
                    path->killPath();
                restoreCollidingObjects(this);
                restoreResult = 0;
                goto final_failure_restore;
            }
            if (costOut != 0) *costOut = (float)this->MGP_costValue[bestPathPoint.x][bestPathPoint.y];
            restoreCollidingObjects(this);
            restoreResult = 1;
            goto final_success_restore;
        }

        if (currentEstimate < this->MGP_bestTraversedPath.total) {
            this->MGP_bestTraversedPath.total = currentEstimate;
            this->MGP_bestTraversedPath.x = (unsigned char)bestPathPoint.x;
            this->MGP_bestTraversedPath.y = (unsigned char)bestPathPoint.y;
        }

        ++this->numberTraversedPathsValue;
        heapCount = this->numberOpenPathsValue;
        this->MGP_openPaths[1] = this->MGP_openPaths[heapCount];
        --heapCount;
        this->numberOpenPathsValue = heapCount;
        copiedX = this->MGP_openPaths[1].x;
        copiedY = this->MGP_openPaths[1].y;
        int savedTotal = this->MGP_openPaths[1].total;
        hole = 1;
        while (hole < heapCount / 2) {
            child = hole * 2;
            if (child < heapCount && this->MGP_openPaths[child + 1].total < this->MGP_openPaths[child].total) ++child;
            if (savedTotal < this->MGP_openPaths[child].total) break;
            this->MGP_openPaths[hole] = this->MGP_openPaths[child];
            hole = child;
        }
        if (hole != 1) {
            this->MGP_openPaths[hole].x = (unsigned char)copiedX;
            this->MGP_openPaths[hole].y = (unsigned char)copiedY;
            this->MGP_openPaths[hole].total = savedTotal;
        }

        i = 0;
        SkipBit = 1;
        temp.x = bestPathPoint.x;
        temp.y = bestPathPoint.y;
        while (i < 8) {
            switch (i) {
            case 0: temp.x -= step; temp.y -= step; break;
            case 1:
            case 2: temp.x += step; break;
            case 3:
            case 4: temp.y += step; break;
            case 5:
            case 6: temp.x -= step; break;
            case 7: temp.y -= step; break;
            }

            facetByte = this->facetValue[bestPathPoint.x][bestPathPoint.y];
            if ((facetByte & 0xf8) == this->CurrentFacetMask) currentFacet = facetByte & 7;
            else currentFacet = 8;
            if ((FacetSkipMask[currentFacet] & SkipBit) != 0) goto next_direction;
            if (temp.x < 0 || temp.y < 0 || temp.x >= this->xSizeValue || temp.y >= this->ySizeValue) goto next_direction;
            if (temp.x == this->initialTile.x && temp.y == this->initialTile.y) goto next_direction;

            tmp = temp.x - bestPathPoint.x;
            tmp2 = temp.y - bestPathPoint.y;
            tmp = (int)(sqrt((double)(tmp * tmp) + (double)(tmp2 * tmp2)) * DAT_00570e78);
            parentCost = this->MGP_costValue[bestPathPoint.x][bestPathPoint.y];
            oldHeuristic = estimateDistanceOrdered(goalX, goalY, bestPathPoint.x, bestPathPoint.y);
            newHeuristic = estimateDistanceOrdered(goalX, goalY, temp.x, temp.y);
            newTotal = newHeuristic + tmp + parentCost - oldHeuristic;

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
                maxScanY = bestPathPoint.y + yDeltaDown;
                scanLeftRaw = temp.x * 4 + quarterMinX;
                scanTopRaw = temp.y * 4 + quarterMinY;
                scanRightRaw = bestPathPoint.x * 4 + xDeltaRight4;
                scanBottomRaw = bestPathPoint.y * 4 + yDeltaDown4;
                break;
            case 1:
                minScanX = bestPathPoint.x + xDeltaLeft;
                minScanY = temp.y + yDeltaUp;
                maxScanX = bestPathPoint.x + xDeltaRight;
                maxScanY = bestPathPoint.y + yDeltaDown;
                scanLeftRaw = bestPathPoint.x * 4 + quarterMinX;
                scanTopRaw = temp.y * 4 + quarterMinY;
                scanRightRaw = bestPathPoint.x * 4 + xDeltaRight4;
                scanBottomRaw = bestPathPoint.y * 4 + yDeltaDown4;
                break;
            case 2:
                minScanX = bestPathPoint.x + xDeltaLeft;
                minScanY = temp.y + yDeltaUp;
                maxScanX = temp.x + xDeltaRight;
                maxScanY = bestPathPoint.y + yDeltaDown;
                scanLeftRaw = bestPathPoint.x * 4 + quarterMinX;
                scanTopRaw = temp.y * 4 + quarterMinY;
                scanRightRaw = temp.x * 4 + xDeltaRight4;
                scanBottomRaw = bestPathPoint.y * 4 + yDeltaDown4;
                break;
            case 3:
                minScanX = bestPathPoint.x + xDeltaLeft;
                minScanY = bestPathPoint.y + yDeltaUp;
                maxScanX = temp.x + xDeltaRight;
                maxScanY = bestPathPoint.y + yDeltaDown;
                scanLeftRaw = bestPathPoint.x * 4 + quarterMinX;
                scanTopRaw = bestPathPoint.y * 4 + quarterMinY;
                scanRightRaw = temp.x * 4 + xDeltaRight4;
                scanBottomRaw = bestPathPoint.y * 4 + yDeltaDown4;
                break;
            case 4:
                minScanX = bestPathPoint.x + xDeltaLeft;
                minScanY = bestPathPoint.y + yDeltaUp;
                maxScanX = temp.x + xDeltaRight;
                maxScanY = temp.y + yDeltaDown;
                scanLeftRaw = bestPathPoint.x * 4 + quarterMinX;
                scanTopRaw = bestPathPoint.y * 4 + quarterMinY;
                scanRightRaw = temp.x * 4 + xDeltaRight4;
                scanBottomRaw = temp.y * 4 + yDeltaDown4;
                break;
            case 5:
                minScanX = bestPathPoint.x + xDeltaLeft;
                minScanY = bestPathPoint.y + yDeltaUp;
                maxScanX = bestPathPoint.x + xDeltaRight;
                maxScanY = temp.y + yDeltaDown;
                scanLeftRaw = bestPathPoint.x * 4 + quarterMinX;
                scanTopRaw = bestPathPoint.y * 4 + quarterMinY;
                scanRightRaw = bestPathPoint.x * 4 + xDeltaRight4;
                scanBottomRaw = temp.y * 4 + yDeltaDown4;
                break;
            case 6:
                minScanX = temp.x + xDeltaLeft;
                minScanY = bestPathPoint.y + yDeltaUp;
                maxScanX = bestPathPoint.x + xDeltaRight;
                maxScanY = temp.y + yDeltaDown;
                scanLeftRaw = temp.x * 4 + quarterMinX;
                scanTopRaw = bestPathPoint.y * 4 + quarterMinY;
                scanRightRaw = bestPathPoint.x * 4 + xDeltaRight4;
                scanBottomRaw = temp.y * 4 + yDeltaDown4;
                break;
            case 7:
                minScanX = temp.x + xDeltaLeft;
                minScanY = bestPathPoint.y + yDeltaUp;
                maxScanX = bestPathPoint.x + xDeltaRight;
                maxScanY = bestPathPoint.y + yDeltaDown;
                scanLeftRaw = temp.x * 4 + quarterMinX;
                scanTopRaw = bestPathPoint.y * 4 + quarterMinY;
                scanRightRaw = bestPathPoint.x * 4 + xDeltaRight4;
                scanBottomRaw = bestPathPoint.y * 4 + yDeltaDown4;
                break;
            default:
                minScanX = temp.x;
                minScanY = temp.y;
                maxScanX = temp.x;
                maxScanY = temp.y;
                scanLeftRaw = temp.x * 4 + quarterMinX;
                scanTopRaw = temp.y * 4 + quarterMinY;
                scanRightRaw = temp.x * 4 + xDeltaRight4;
                scanBottomRaw = temp.y * 4 + yDeltaDown4;
                break;
            }
            if (minScanX < 0) ++minScanX;
            if (minScanY < 0) ++minScanY;
            if (maxScanX < 0) ++maxScanX;
            if (maxScanY < 0) ++maxScanY;
            map = this->mapValue;
            if ((maxScanX & 0xff) >= map->map_width || (maxScanY & 0xff) >= map->map_height) {
                terrainStatus = 0xfe;
            } else {
                terrainRow = (unsigned char)minScanY;
                while (terrainRow <= (unsigned char)maxScanY && terrainStatus == 1) {
                    terrainCol = (unsigned char)minScanX;
                    while (terrainCol <= (unsigned char)maxScanX) {
                        if (this->initialTile.x != terrainCol || this->initialTile.y != terrainRow) {
                            tile = &map->map_row_offset[terrainRow][terrainCol];
                            tmp = tile->terrain_type & 0x1f;
                            if (tmp != this->currentTerrainException1 &&
                                tmp != this->currentTerrainException2 &&
                                this->currentTerrainTable[tmp] <= DAT_00570e80) {
                                tmp = tile->border_type & 0x0f;
                                if (tmp == 0 ||
                                    this->currentTerrainTable[
                                        map->border_types[tmp].underlay_terrain] <= DAT_00570e80) {
                                    terrainStatus = 0xfe;
                                    break;
                                }
                            }
                        }
                        ++terrainCol;
                    }
                    ++terrainRow;
                }
            }
            status = terrainStatus;

            if (status == 1 && checkObstructions == 1) {
                left = scanLeftRaw;
                right = scanRightRaw;
                top = scanTopRaw;
                bottom = scanBottomRaw;
                if (left < 0) ++left;
                if (right < 0) ++right;
                if (top < 0) ++top;
                if (bottom < 0) ++bottom;
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
                status = foundBlockingOwnGroup != 1;
                goto obstruction_done;

obstruction_found:
                status = 0xfe;
obstruction_done:
                ;
            }

            unobstructibleObjectHitpoints = DAT_00570e5c;
            reached = 0;
            if (status == 0xfe) {
                if (this->currentUnobstructibleGroupID == -1) goto next_direction;
                found = 0;
                hitCount = 0;
                minScanX = temp.x - 1;
                if (minScanX < 0) minScanX = 0;
                maxScanX = temp.x + 1;
                row = minScanX;
                while (row <= maxScanX && row < this->xSizeValue && hitCount == 0) {
                    minScanY = temp.y - 1;
                    if (minScanY < 0) minScanY = 0;
                    maxScanY = temp.y + 1;
                    col = minScanY;
                    while (col <= maxScanY && col < this->ySizeValue && hitCount == 0) {
                        objectCountOnTile = 0;
                        hitId = this->worldValue->objectGroupOnTile(this->currentUnobstructiblePlayerID, this->currentUnobstructibleGroupID, row, col, objectCountOnTile);
                        if (hitId == -1) {
                            if (objectCountOnTile > 0) found = 1;
                        } else {
                            other = this->worldValue->object(hitId);
                            if (other != 0) {
                                unobstructibleObjectHitpoints = other->hp;
                                reached = 1;
                            }
                        }
                        ++col;
                        hitCount = found;
                    }
                    ++row;
                }
                if (hitCount == 1) goto next_direction;
            }

            misc = this->miscValue[temp.x][temp.y];
            newTotal += misc * 0x10;
            if (reached == 1) {
                if (unobstructibleObjectHitpoints < 10.0f) newTotal += 0x10;
                else newTotal += 0x3c;
            }
            facetByte = this->facetValue[bestPathPoint.x][bestPathPoint.y];
            if ((facetByte & 0xf8) == this->CurrentFacetMask) facetLow = facetByte & 7;
            else facetLow = 0xff;
            if (i != facetLow) ++newTotal;
            if (status == 0) newTotal = 0;

            this->MGP_costValue[temp.x][temp.y] = newTotal;
            this->facetValue[temp.x][temp.y] = (unsigned char)((i & 7) | this->CurrentFacetMask);
            openIndex = this->numberOpenPathsValue + 1;
            this->numberOpenPathsValue = openIndex;
            this->MGP_openPaths[openIndex].x = (unsigned char)temp.x;
            this->MGP_openPaths[openIndex].y = (unsigned char)temp.y;
            this->MGP_openPaths[openIndex].total = newTotal;

            insertIndex = openIndex;
            if (insertIndex > 0) {
                int savedTotal;
                copiedX = this->MGP_openPaths[insertIndex].x;
                copiedY = this->MGP_openPaths[insertIndex].y;
                savedTotal = this->MGP_openPaths[insertIndex].total;
                parentIndex = insertIndex / 2;
                while (savedTotal < this->MGP_openPaths[parentIndex].total) {
                    this->MGP_openPaths[insertIndex] = this->MGP_openPaths[parentIndex];
                    insertIndex = insertIndex / 2;
                    parentIndex = parentIndex / 2;
                }
                if (insertIndex != openIndex) {
                    this->MGP_openPaths[insertIndex].x = (unsigned char)copiedX;
                    this->MGP_openPaths[insertIndex].y = (unsigned char)copiedY;
                    this->MGP_openPaths[insertIndex].total = savedTotal;
                }
            }
            if (status == 0) {
                if (mode == 1 && this->copyPath(step) == 0) {
                    path = obj->storePathInExceptionPath == 0 ? &obj->pathValue : &obj->exceptionPathValue;
                    path->killPath();
                    restoreCollidingObjects(this);
                    restoreResult = 0;
                    goto final_failure_restore;
                }
                if (costOut != 0) *costOut = (float)this->MGP_costValue[bestPathPoint.x][bestPathPoint.y];
                restoreCollidingObjects(this);
                restoreResult = 1;
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
        int savedTotal;
        copiedX = this->MGP_openPaths[openIndex].x;
        copiedY = this->MGP_openPaths[openIndex].y;
        savedTotal = this->MGP_openPaths[openIndex].total;
        insertIndex = openIndex;
        parentIndex = insertIndex / 2;
        while (savedTotal < this->MGP_openPaths[parentIndex].total) {
            this->MGP_openPaths[insertIndex] = this->MGP_openPaths[parentIndex];
            insertIndex = insertIndex / 2;
            parentIndex = parentIndex / 2;
        }
        if (insertIndex != openIndex) {
            this->MGP_openPaths[insertIndex].x = (unsigned char)copiedX;
            this->MGP_openPaths[insertIndex].y = (unsigned char)copiedY;
            this->MGP_openPaths[insertIndex].total = savedTotal;
        }
    }

    if (mode == 1 && this->copyPath(step) == 0) {
        path = obj->storePathInExceptionPath == 0 ? &obj->pathValue : &obj->exceptionPathValue;
                    path->killPath();
        restoreCollidingObjects(this);
        restoreResult = 0;
    } else {
        if (costOut != 0) *costOut = (float)this->MGP_bestTraversedPath.total;
        restoreCollidingObjects(this);
        restoreResult = 0;
    }

    goto final_failure_restore;

final_failure_restore:
    if (this->currentObjectInObMap == 1 && this->currentObject->inside_obj == 0) {
        this->currentObject->addToObstructionMap(this->aiPS);
    }
    return restoreResult;
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

int PathingSystem::passable(RGE_Moving_Object* object, float x, float y,
                            int checkObjects)
{
    int local_14 = 0;
    uchar terrain;
    uchar mapByte;
    uchar shift;

    this->currentObject = object;
    this->currentTerrainTable =
        this->worldValue->terrains[object->master_obj->terrain];

    this->initialTile.x = -1;
    this->initialTile.y = -1;
    this->minInitialPosition.x = -1;
    this->minInitialPosition.y = -1;
    this->maxInitialPosition.x = -1;
    this->maxInitialPosition.y = -1;

    float xFraction = x - (float)floor((double)x);
    float yFraction = y - (float)floor((double)y);
    float radiusX = object->master_obj->radius_x;
    float radiusY = object->master_obj->radius_y;

    int xTile = (int)x;
    xTile *= 4;
    int xMin = xTile;
    xMin -= (int)(((xFraction - DAT_00570e68) - radiusX) *
                  DAT_00570e74);
    xMin -= 400;

    int yTile = (int)y;
    yTile *= 4;
    int yMin = yTile;
    yMin -= (int)(((yFraction - DAT_00570e68) - radiusY) *
                  DAT_00570e74);
    yMin -= 400;

    int xMax = xTile;
    xMax -= (int)(((xFraction + radiusX) - DAT_00570e68) *
                  DAT_00570e74);
    xMax -= 400;

    int yMax = yTile;
    yMax -= (int)(((yFraction + radiusY) - DAT_00570e68) *
                  DAT_00570e74);
    yMax -= 400;

    if (xMin < 0)
        ++xMin;
    if (yMin < 0)
        ++yMin;

    if (checkObjects != 0) {
        uchar minY = (uchar)(yMin >> 2);
        uchar maxY = (uchar)(yMax >> 2);
        uchar minX = (uchar)(xMin >> 2);
        uchar maxX = (uchar)(xMax >> 2);

        if ((int)maxX >= this->mapValue->map_width ||
            (int)maxY >= this->mapValue->map_height)
            return 0;

        if (minY <= maxY) {
            uchar row = minY;
            do {
                uchar col = minX;
                if (col <= maxX) {
                    RGE_Tile* tile =
                        &this->mapValue->map_row_offset[row][minX];
                    do {
                        local_14 = col;
                        if (this->initialTile.x != local_14 ||
                            this->initialTile.y != row) {
                            terrain = tile->terrain_type & 0x1F;
                            if (this->currentTerrainTable[terrain] <=
                                DAT_00570e80) {
                                if (terrain != this->currentTerrainException1 &&
                                    terrain != this->currentTerrainException2) {
                                    int border = tile->border_type & 0x0F;
                                    if (border == 0 ||
                                        this->currentTerrainTable[
                                            this->mapValue->border_types[border]
                                                .underlay_terrain] <= DAT_00570e80)
                                        return 0;
                                }
                            }
                        }
                        tile++;
                        ++col;
                    } while (col <= maxX);
                }
                ++row;
            } while (row <= maxY);
        }
    }

    int removed = object->removeFromObstructionMap(this->aiPS);
    bool foundBlockingGroup = false;
    uchar* obstruction;
    int height = yMax - yMin - 1;

    if (height >= 0) {
        if (height < 0x18 &&
            (xMin > this->maxTarget.x || yMin > this->maxTarget.y ||
             xMax < this->minTarget.x || yMax < this->minTarget.y)) {
            int maskIndex = (yMin & 3) + height * 4;
            maskIndex *= 2;

            uint maskB = ObstructionMasks[maskIndex + 1];
            uint maskA = ObstructionMasks[maskIndex];
            if (maskB == 0) {
                if (xMin < xMax) {
                    obstruction = this->obstructionValue[xMin] + (yMin >> 2);
                    int row = xMin;
                    do {
                        if ((*(uint*)obstruction & maskA) != 0)
                            goto blocked;
                        ++row;
                        obstruction += 0xFF;
                    } while (row < xMax);
                }
            } else if (xMin < xMax) {
                    obstruction = this->obstructionValue[xMin] + (yMin >> 2);
                    int row = xMin;
                    do {
                        if ((*(uint*)obstruction & maskA) != 0 ||
                            (*(uint*)(obstruction + 4) & maskB) != 0) {
                            goto blocked;
                        }
                        ++row;
                        obstruction += 0xFF;
                    } while (row < xMax);
            }
        } else if (xMin < xMax) {
            int row = xMin;
            do {
                int col = yMin;
                while (col < yMax) {
                    local_14 = col;
                    mapByte = this->obstructionValue[0]
                        [row * 0xFF + (local_14 >> 2)];
                    shift = ObstructionValueShift[local_14 & 3];
                    if (((mapByte >> (shift & 0x1F)) & 3) != 0) {
                        if (this->currentTargetID == -1 ||
                            row < this->minTarget.x ||
                            this->maxTarget.x < row ||
                            (int)local_14 < this->minTarget.y ||
                            this->maxTarget.y < (int)local_14) {
                            goto blocked;
                        }
                        foundBlockingGroup = true;
                    }
                    ++col;
                }
                if (foundBlockingGroup)
                    break;
                ++row;
            } while (row < xMax);
        }

        if (foundBlockingGroup)
            goto blocked;
    }

    if (removed != 0 && object->inside_obj == 0)
        object->addToObstructionMap(this->aiPS);
    return 1;

blocked:
    if (removed != 0 && object->inside_obj == 0)
        object->addToObstructionMap(this->aiPS);
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

void PathingSystem::printState(RGE_Moving_Object* obj)
{
    obj->logDebug("    There are %d open paths and %d traversed paths.",
        this->numberOpenPathsValue, this->numberTraversedPathsValue);
    obj->logDebug("    The open paths:");

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
            obj->logDebug("      %5d: (%d, %d), total=%d, facet=%d.",
                i, path[-1], path[0], *(int*)(path + 3), facet);
            ++i;
            path += 8;
        } while (i <= this->numberOpenPathsValue);
    }
}

int PathingSystem::copyPath(int step)
{
    uchar previousFacet;

    {
        Path* path;
        if (this->currentObject->storePathInExceptionPath == 0)
            path = &this->currentObject->pathValue;
        else
            path = &this->currentObject->exceptionPathValue;
        path->killPath();
    }

    BYTEPoint currentPoint;
    currentPoint.x = this->MGP_openPaths[1].x;
    currentPoint.y = this->MGP_openPaths[1].y;
    int fooX = currentPoint.x;
    int fooY = currentPoint.y;
    previousFacet = 0xFF;
    uchar facetByte = this->facetValue[currentPoint.x][currentPoint.y];
    uchar currentFacet;
    if ((facetByte & 0xF8) == this->CurrentFacetMask)
        currentFacet = facetByte & 7;
    else
        currentFacet = 0xFF;

    RGE_Moving_Object* object = this->currentObject;
    Waypoint waypoint;
    waypoint.x = (float)fooX + this->currentXOffset;
    waypoint.y = (float)fooY + this->currentYOffset;
    waypoint.z = object->world_z;
    waypoint.facetToNextWaypoint = currentFacet;

    {
        Path* path = object->storePathInExceptionPath == 0
            ? &object->pathValue
            : &object->exceptionPathValue;
        path->initToStart();
    }

    do {
        if (this->initialTile.x == fooX && this->initialTile.y == fooY) {
            if (this->currentObject->storePathInExceptionPath == 0) {
                if (this->currentObject->pathValue.insertAtCurrent(waypoint) == 0)
                    return 0;
            } else {
                if (this->currentObject->exceptionPathValue.insertAtCurrent(waypoint) == 0)
                    return 0;
            }
            return 1;
        }

        if (currentFacet != previousFacet) {
            if (this->currentObject->storePathInExceptionPath == 0) {
                if (this->currentObject->pathValue.insertAtCurrent(waypoint) == 0)
                    return 0;
            } else {
                if (this->currentObject->exceptionPathValue.insertAtCurrent(waypoint) == 0)
                    return 0;
            }
        }

        if (this->currentUnobstructibleGroupID != -1) {
            int minX = fooX - 1;
            int maxX = fooX + 1;
            if (minX < 0) {
                minX = 0;
                ++maxX;
            } else if (maxX >= this->xSizeValue) {
                --minX;
                maxX = this->xSizeValue - 1;
            }

            int minY = fooY - 1;
            int maxY = fooY + 1;
            if (minY < 0) {
                minY = 0;
                ++maxY;
            } else if (maxY >= this->ySizeValue) {
                --minY;
                maxY = this->ySizeValue - 1;
            }

            for (int tileX = minX; tileX <= maxX; ++tileX) {
                for (int tileY = minY; tileY <= maxY; ++tileY) {
                    int objectCountOnTile = 0;
                    int id = this->worldValue->objectGroupOnTile(
                        this->currentUnobstructiblePlayerID,
                        this->currentUnobstructibleGroupID,
                        tileX, tileY, objectCountOnTile);
                    if (id != -1)
                        this->currentUnobstructibles.add(id);
                }
            }
        }

        switch ((int)currentFacet) {
        case 0:
            currentPoint.x += (uchar)step;
            currentPoint.y += (uchar)step;
            break;
        case 1:
            currentPoint.y += (uchar)step;
            break;
        case 2:
            currentPoint.x -= (uchar)step;
            currentPoint.y += (uchar)step;
            break;
        case 3:
            currentPoint.x -= (uchar)step;
            break;
        case 4:
            currentPoint.x -= (uchar)step;
            currentPoint.y -= (uchar)step;
            break;
        case 5:
            currentPoint.y -= (uchar)step;
            break;
        case 6:
            currentPoint.x += (uchar)step;
            currentPoint.y -= (uchar)step;
            break;
        case 7:
            currentPoint.x += (uchar)step;
            break;
        }

        previousFacet = currentFacet;
        fooX = currentPoint.x;
        fooY = currentPoint.y;
        facetByte = this->facetValue[fooX][fooY];
        if ((facetByte & 0xF8) == this->CurrentFacetMask)
            currentFacet = facetByte & 7;
        else
            currentFacet = 0xFF;
        waypoint.x = (float)fooX + this->currentXOffset;
        waypoint.y = (float)fooY + this->currentYOffset;
        waypoint.facetToNextWaypoint = currentFacet;
    } while (true);
}

void PathingSystem::copyUnobstructibles(ManagedArray<int>& out)
{
    int i = this->currentUnobstructibles.numberValue;
    if (i >= 0) {
        do {
            out.add(this->currentUnobstructibles[i]);

            --i;
        } while (i >= 0);
    }
}
