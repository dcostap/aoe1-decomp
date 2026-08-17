// 004D8D20 TribeInformationAIModule::closestUnexploredTile
// taiinfmd.cpp:896-1116
// Attempt log:
// - Earlier source used an incorrect owner/world/map surface and omitted the
//   quadrant fallback. It was 560 bytes against 977 original bytes.
// - This reconstruction restores the typed md->player->visible/world chain,
//   the passableTile/canPath calls, the expanding scan, and quadrant choice.
// - Signed debug_rand % 4 matches the original remainder sequence for both
//   the scan direction and quadrant edge choice.
// - The zero canPath result owns the quadrant fallback. The nonzero result
//   sets the path value to zero. This source order recovers all 16 call sites.
// - XYPoint coordinates improved the structural basin to 977 bytes and 82.81%
//   shape similarity. The byte explored temporary preserves the original AL
//   lifetime; the typed uchar form is the retained semantic source.
// - Explicit pretested do loops, canonical base layout, and score-term order
//   produced no further code movement. All 16 ordered calls remain aligned.
// - The best diagnostic source used a signed char and reached diff 876, but
//   its 0xff comparison was not semantically safe. It is not retained.
// - This pass tested 20 source, type, layout, liveness, and control-flow
//   hypotheses. The quadrant choice if-chain improved the shape to 85.71%
//   and reduced the diff to 901 bytes. It preserves all 16 ordered calls.
// - Fixed-gap class ownership, split early assignments, score order, and the
//   early local declaration order produced no code movement.
// - Left in scratch: no exact match. The remaining drift starts in the
//   prologue register allocation and continues through stack-home placement.

typedef unsigned char uchar;

class RGE_Visible_Map {
public:
    uchar get_visible(int x, int y);
};

class RGE_Static_Object;

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    char gap_00[0x38];
    RGE_Visible_Map* visible;
    RGE_Game_World* world;
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
};

class InformationAIModule {
public:
    virtual ~InformationAIModule();
    char gap_04[0xec];
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short object_group;
    char gap_16[0x12];
    float los;
};

#define VPAD1(n) virtual void vf##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_e)
#define VPAD64(n) VPAD32(n) VPAD32(n##_f)

struct XYZPoint {
    int x;
    int y;
    int z;
};

struct XYPoint {
    int x;
    int y;
};

class RGE_Static_Object {
public:
    VPAD64(0)
    VPAD4(64)
    VPAD1(68)
    virtual int passableTile(float x, float y, int mode);
    VPAD32(70)
    virtual int canPath(XYZPoint point, float los, int mode, float* path,
                        int flag, int arg6, int arg7);

    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;

    uchar lookupZone(int x, int y);
    uchar currentZone();
};

#undef VPAD64
#undef VPAD32
#undef VPAD16
#undef VPAD8
#undef VPAD4
#undef VPAD2
#undef VPAD1

class InfluenceMap {
public:
    virtual ~InfluenceMap();

    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    uchar* valueValue;
    uchar** rowValue;
    int coverageCountValue;
    int connectionCountValue;
    uchar unchangeableLimitValue;
    uchar gap_end[3];

    int lookupValue(int x, int y);
    int setValue(int x, int y, uchar value);
};

struct QuadrantLog {
    int numberExploredTiles;
    int numberAttacksOnUs;
    int numberAttacksByUs;
};

extern "C" int debug_rand(char* file, int line);
extern float DAT_00575564;

struct ManagedArray_int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];
    TribeMainDecisionAIModule* md;
    int mapXSizeValue;
    int mapYSizeValue;
    char gap_10c[0x4c];
    InfluenceMap pathMap;
    char gap_180[0x288];
    QuadrantLog quadrantLog[4][4];

    int closestUnexploredTile(int objectId, float x, float y,
                              float* outX, float* outY);
    void setFullyExploredZone(int objectId, int value);
};

int TribeInformationAIModule::closestUnexploredTile(
    int objectId, float x, float y, float* outX, float* outY)
{
    XYPoint cPoint;
    RGE_Static_Object* obj;
    RGE_Visible_Map* visible;

    visible = this->md->player->visible;
    obj = this->md->player->world->object(objectId);

    if (obj == 0)
        return 0;

    int isBuilding = (obj->master_obj->object_group == 4);
    uchar initialZone = obj->currentZone();
    int direction = debug_rand(
        (char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0x397) % 4;

    cPoint.x = (int)x;
    cPoint.y = (int)y;
    int offLeft = 0;
    int offRight = 0;
    int offTop = 0;
    int offBottom = 0;
    int pathDistance = 0;
    float pathResult;
    int pass;
    int i;

    for (;;) {
        if (offLeft != 0 && offRight != 0 && offTop != 0 && offBottom != 0) {
            this->setFullyExploredZone(objectId, 1);
            return 0;
        }

        ++pathDistance;
        pass = 0;
        do {
            i = 0;
            direction = (direction + 1) & 3;
            if (pathDistance > 0) {
                do {
                switch (direction) {
                case 0:
                    ++cPoint.y;
                    break;
                case 1:
                    ++cPoint.x;
                    break;
                case 2:
                    --cPoint.y;
                    break;
                case 3:
                    --cPoint.x;
                    break;
                }

                if (cPoint.x < 0) {
                    offLeft = 1;
                } else if (cPoint.x >= this->mapXSizeValue) {
                    offRight = 1;
                } else if (cPoint.y < 0) {
                    offTop = 1;
                } else if (cPoint.y >= this->mapYSizeValue) {
                    offBottom = 1;
                } else {
                    uchar explored = (uchar)this->pathMap.lookupValue(
                        cPoint.x, cPoint.y);
                    uchar visibleValue = visible->get_visible(cPoint.x, cPoint.y);
                    if (visibleValue != 0x0f &&
                        ((isBuilding == 1 && explored == 0xff) ||
                         (isBuilding == 0 &&
                          (explored == 0xff || explored == 2)))) {
                        if (obj->passableTile((float)cPoint.x,
                                              (float)cPoint.y, 1) != 0 &&
                            obj->lookupZone(cPoint.x, cPoint.y) == initialZone) {
                            XYZPoint point;
                            point.x = cPoint.x;
                            point.y = cPoint.y;
                            point.z = (int)obj->world_z;
                            if (obj->canPath(
                                    point, obj->master_obj->los - DAT_00575564,
                                    -1, &pathResult, 1, -1, -1) == 0) {
                                this->pathMap.setValue(cPoint.x, cPoint.y, 1);

                                int bestScore = -1;
                                int bestX = 0;
                                int bestY = 0;
                                int quadrantX;
                                int quadrantY;
                                QuadrantLog* quadrant = &this->quadrantLog[0][0];
                                for (quadrantX = 0; quadrantX < 4; ++quadrantX) {
                                    for (quadrantY = 0; quadrantY < 4; ++quadrantY) {
                                        int score = quadrant->numberExploredTiles +
                                            debug_rand(
                                                (char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp",
                                                0x420) % 100 +
                                            quadrant->numberAttacksOnUs * 25;
                                        if (bestScore == -1 || score < bestScore) {
                                            bestScore = score;
                                    bestX = this->mapXSizeValue * quadrantX / 4;
                                    bestY = this->mapYSizeValue * quadrantY / 4;
                                        }
                                        ++quadrant;
                                    }
                                }

                                int maxX = this->mapXSizeValue / 4 - 1 + bestX;
                                int maxY = this->mapYSizeValue / 4 - 1 + bestY;
                                int choice = debug_rand(
                                    (char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp",
                                    0x430) % 4;
                                if (choice == 0) {
                                    cPoint.x = bestX;
                                    cPoint.y = bestY;
                                } else if (choice == 1) {
                                    cPoint.x = bestX;
                                    cPoint.y = maxY;
                                } else if (choice == 2) {
                                    cPoint.x = maxX;
                                    cPoint.y = maxY;
                                } else {
                                    cPoint.x = maxX;
                                    cPoint.y = bestY;
                                }
                            } else {
                                this->pathMap.setValue(cPoint.x, cPoint.y, 0);
                            }
                            *outX = (float)cPoint.x;
                            *outY = (float)cPoint.y;
                            return 1;
                        }
                    }
                }
                    ++i;
                } while (i < pathDistance);
            }
            ++pass;
        } while (pass < 2);
    }
}
