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

extern "C" double floor(double value);
extern "C" long __ftol(void);

extern float DAT_00570e68;
extern float DAT_00570e74;
extern double DAT_00570e80;
extern const unsigned long ObstructionMasks[];
extern const unsigned char ObstructionValueShift[];

typedef unsigned char uchar;

typedef unsigned int uint;

struct XYPoint {
    int x;
    int y;
};

struct RGE_Master_Static_Object {
    char gap_00[0x30];
    float radius_x;
    float radius_y;
    float radius_z;
    char gap_3c[0x2A];
    short terrain;
};

struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    void* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    RGE_Static_Object* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    uchar curr_damage_percent;
    uchar facet;
    uchar selected;
    uchar selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    uchar object_state;
    uchar sleep_flag;
    uchar dopple_flag;
    uchar goto_sleep_flag;
    short attribute_type_held;
    uchar type;
    uchar worker_num;
    void* player_object_node;
    char pathingGroupMembers[0x10];
    char groupMembers[0x10];
    void* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    uchar inObstructionMapValue;
    uchar lastInObstructionMapValue;
    uchar underAttackValue;
    uchar pad_87;

    int removeFromObstructionMap(int aiPS);
    int addToObstructionMap(int aiPS);
};

struct RGE_Moving_Object : public RGE_Static_Object {
};

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    uchar tile_type;
    uchar terrain_type;
    uchar border_type;
    uchar gap_07[0x11];
};

struct RGE_Border_Set {
    uchar gap_00[0x59C];
    short underlay_terrain;
    short border_style;
};

struct RGE_Map {
    virtual ~RGE_Map();
    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    uchar gap_18[0x3374];
    RGE_Border_Set border_types[16];
    RGE_Tile** map_row_offset;
};

struct RGE_Game_World {
    uchar gap_00[0x54];
    float** terrains;
};

struct ManagedArray_int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class PathingSystem {
public:
    virtual ~PathingSystem();
    int xSizeValue;
    int ySizeValue;
    uchar facetValue[255][255];
    uchar gap_FE0D[3];
    int MGP_costValue[255][255];

    struct MGP_FloatHeap {
        uchar x;
        uchar y;
        unsigned short next;
        int total;
    };

    MGP_FloatHeap MGP_openPaths[65026];
    uchar obstructionValue[1020][255];
    uchar miscValue[255][255];
    uchar gap_11DC29[3];
    int numberOpenPathsValue;
    MGP_FloatHeap MGP_bestTraversedPath;
    int numberTraversedPathsValue;
    RGE_Map* mapValue;
    RGE_Game_World* worldValue;
    RGE_Moving_Object* currentObject;
    int currentObjectInObMap;
    int currentTargetID;
    float* currentTerrainTable;
    float currentXOffset;
    float currentYOffset;
    int currentTerrainException1;
    int currentTerrainException2;
    ManagedArray_int initialCollidingObjects;
    int startOfPath;
    int checkTerrainOnFirstPass;
    XYPoint initialTile;
    XYPoint minTarget;
    XYPoint maxTarget;
    XYPoint minInitialPosition;
    XYPoint maxInitialPosition;
    float averageNumWaypoints;
    float averagePathLength;
    float averagePathIterations;
    int numAttempts;
    int numFails;
    int numSuccesses;
    int numInitialPathsValue;
    int numContinuePathsValue;
    int numCanPathsValue;
    int MGP_closestTargetDistance;
    float averageClosestTargetDistance;
    float averageSuccessTime;
    float averageFailTime;
    uchar CurrentFacetMask;
    uchar gap_11DCD9[3];
    int currentUnobstructibleGroupID;
    int currentUnobstructiblePlayerID;
    ManagedArray_int currentUnobstructibles;
    int aiPS;

    int passable(RGE_Moving_Object* object, float x, float y, int checkObjects);
};

int PathingSystem::passable(RGE_Moving_Object* object, float x, float y,
                            int checkObjects)
{
    uint obstruction_column = 0;

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
    int xRadius = (int)(((xFraction - DAT_00570e68) - radiusX) *
                        DAT_00570e74);
    int xMin = xTile * 4 - xRadius - 400;

    int yTile = (int)y;
    int yRadius = (int)(((yFraction - DAT_00570e68) - radiusY) *
                        DAT_00570e74);
    int yMin = yTile * 4 - yRadius - 400;

    int xOtherRadius = (int)(((xFraction + radiusX) - DAT_00570e68) *
                             DAT_00570e74);
    int xMax = xTile * 4 - xOtherRadius - 400;

    int yOtherRadius = (int)(((yFraction + radiusY) - DAT_00570e68) *
                             DAT_00570e74);
    int yMax = yTile * 4 - yOtherRadius - 400;

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
                        obstruction_column = col;
                        if (this->initialTile.x != obstruction_column ||
                            this->initialTile.y != row) {
                            int terrain = tile->terrain_type & 0x1F;
                            if (terrain != this->currentTerrainException1 &&
                                terrain != this->currentTerrainException2 &&
                                this->currentTerrainTable[terrain] <=
                                    DAT_00570e80) {
                                int border = tile->border_type & 0x0F;
                                if (border == 0 ||
                                    this->currentTerrainTable[
                                        this->mapValue->border_types[border]
                                            .underlay_terrain] <= DAT_00570e80)
                                    return 0;
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
    int height = yMax - yMin - 1;

    if (height >= 0) {
        if (height < 0x18 &&
            (this->maxTarget.x < xMin || this->maxTarget.y < yMin ||
             xMax < this->minTarget.x || yMax < this->minTarget.y)) {
            int maskIndex = (yMin & 3) + height * 4;
            uint maskA = ObstructionMasks[maskIndex * 2];
            uint maskB = ObstructionMasks[maskIndex * 2 + 1];

            if (xMin < xMax) {
                uchar* obstruction = this->obstructionValue[xMin] + (yMin >> 2);
                int row = xMin;
                do {
                    if ((*(uint*)obstruction & maskA) != 0 ||
                        (maskB != 0 && (*(uint*)(obstruction + 4) & maskB) != 0)) {
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
                    obstruction_column = (uint)col;
                    uchar packed = this->obstructionValue[0]
                        [row * 0xFF + (obstruction_column >> 2)];
                    if (((packed >>
                          (ObstructionValueShift[obstruction_column & 3] & 0x1F)) & 3) != 0) {
                        if (this->currentTargetID == -1 ||
                            row < this->minTarget.x ||
                            this->maxTarget.x < row ||
                            (int)obstruction_column < this->minTarget.y ||
                            this->maxTarget.y < (int)obstruction_column) {
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
