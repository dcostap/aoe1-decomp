// VA: 0046D280 PathingSystem::passable(RGE_Moving_Object*, float, float, int)
// pathsys.cpp lines 2049-2217 (1207B)
//
// Attempt log:
// - Replaced the former 128-byte placeholder with the packet-supported typed
//   terrain/map/obstruction reconstruction.  The executable uses the moving
//   object's master radius and terrain table, four sub-tile footprint bounds,
//   optional terrain-row scanning, temporary obstruction-map removal, the
//   short-row mask fast path, and the general packed obstruction scan.
// - The source deliberately uses named RGE_Map/RGE_Tile/RGE_Static_Object
//   ownership and ordinary casts/loops; the original executable remains the
//   behavior oracle for the still-unmatched FPU expression grouping.
// - Final bounded pass: the 11 direct calls and their order are aligned,
//   including both addToObstructionMap cleanup tails.  The remaining drift is
//   the VC5 local/frame/FPU grouping and the large scan CFG (rebuilt 1076B,
//   frame 0x18 versus target 1207B, frame 0x20); this is left as a readable
//   reconstruction rather than padded or volatile compiler steering.
// - Probe 12 split each footprint bound into ordinary multiply, subtraction,
//   and -400 statements.  It improved resync similarity but worsened strict
//   diff by 7 bytes, so restore the validated typed reconstruction.
// - Structural follow-up: split the fast obstruction scan into the original
//   zero-mask and two-word-mask loops, with the DAT_00584F24 word loaded first.
//   This improved the structural diff from 1016 to 1003 bytes.
// - Kept explicit scaled tile variables and bound subtraction statements.
//   The rebuilt size moved from -131 to -10 bytes, with 66.27% shape match.
// - Named the fixed tile-row byte offset used by the terrain scan.  The best
//   restored checkpoint is 837 bytes of positional diff, frame 0x1C, and
//   9.88% exact-block coverage; the remaining gap is stack-home/CFG layout.
// - Follow-up probes 2-34 tested flag width, terrain local width/scope,
//   declaration order, tile-pointer forms, guard nesting/order, radius forms,
//   mask order, signed packed indices, and math-header context.  Most changes
//   were duplicate compiler basins or worse.  The retained basin uses a byte
//   terrain local, a signed packed index, a table-threshold-first terrain guard,
//   and the natural typed row/tile and split mask loops.
// - Best current clean reconstruction: 1200 rebuilt bytes, frame 0x20,
//   76.04% shape similarity, 699 positional diff bytes, 22.46% exact-block
//   coverage, and all 11 direct calls aligned.  Reversing the first two fast
//   overlap predicates to match the target compare polarity improved shape.
// - A distinct source improvement is `maskIndex *= 2` before the two mask
//   loads.  It recovers the target's explicit shift and scale-4 address form.
//   It reduced positional diff from 782 to 699 and closed the size gap to 7.
//   Function-scope byte temporaries and one obstruction cursor were natural,
//   target-supported tests.  They duplicate the same emitted code.
// - Tested bound declaration order, unsigned terrain scope, typed row indexing,
//   radius order, fast cursor declaration order, tile-bound order, and a
//   carried general-scan row cursor.  These were worse or duplicate basins.
// - The unresolved gap is source-level VC5 register/home allocation in the
//   footprint prelude and packed obstruction scan.  The original reloads
//   xMin, yMin, and xMax through dead parameter homes.  Current typed source
//   preserves the proven behavior and call set without volatile or assembly.

#include <math.h>

extern "C" double floor(double value);
extern "C" long __ftol(void);

extern float DAT_00570e68;
extern float DAT_00570e74;
extern double DAT_00570e80;
extern const unsigned long ObstructionMasks[];
extern const unsigned char ObstructionValueShift[];

#include "../../include/pathsys_context.h"

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
            int tileOffset = minX * (int)sizeof(RGE_Tile);
            uchar row = minY;
            do {
                uchar col = minX;
                if (col <= maxX) {
                    RGE_Tile* tile = (RGE_Tile*)
                        ((char*)this->mapValue->map_row_offset[row] +
                         tileOffset);
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
