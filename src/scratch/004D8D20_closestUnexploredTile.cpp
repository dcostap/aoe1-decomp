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
// - Best current codegen is 968 bytes versus 977, with a 0x38 frame and
//   72.92% shape similarity. The remaining drift starts in register setup.
// - Left in scratch: no exact match. The remaining gap is broad register,
//   stack-home, and block-layout drift after the clean typed reconstruction.

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

class TribeInformationAIModule {
public:
    char gap_000[0x100];
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
    RGE_Visible_Map* visible = this->md->player->visible;
    RGE_Static_Object* obj = this->md->player->world->object(objectId);

    if (obj == 0)
        return 0;

    int isBuilding = (obj->master_obj->object_group == 4);
    uchar initialZone = obj->currentZone();
    int direction = debug_rand(
        (char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0x397) % 4;

    int cPointX = (int)x;
    int cPointY = (int)y;
    int offLeft = 0;
    int offRight = 0;
    int offTop = 0;
    int offBottom = 0;
    int pathDistance = 0;
    float pathResult;

    for (;;) {
        if (offLeft != 0 && offRight != 0 && offTop != 0 && offBottom != 0) {
            this->setFullyExploredZone(objectId, 1);
            return 0;
        }

        ++pathDistance;
        for (int pass = 0; pass < 2; ++pass) {
            int i = 0;
            direction = (direction + 1) & 3;
            while (i < pathDistance) {
                switch (direction) {
                case 0:
                    ++cPointY;
                    break;
                case 1:
                    ++cPointX;
                    break;
                case 2:
                    --cPointY;
                    break;
                case 3:
                    --cPointX;
                    break;
                }

                if (cPointX < 0) {
                    offLeft = 1;
                } else if (cPointX >= this->mapXSizeValue) {
                    offRight = 1;
                } else if (cPointY < 0) {
                    offTop = 1;
                } else if (cPointY >= this->mapYSizeValue) {
                    offBottom = 1;
                } else {
                    int explored = this->pathMap.lookupValue(cPointX, cPointY);
                    uchar visibleValue = visible->get_visible(cPointX, cPointY);
                    if (visibleValue != 0x0f &&
                        ((isBuilding == 1 && explored == 0xff) ||
                         (isBuilding == 0 &&
                          (explored == 0xff || explored == 2)))) {
                        if (obj->passableTile((float)cPointX,
                                              (float)cPointY, 1) != 0 &&
                            obj->lookupZone(cPointX, cPointY) == initialZone) {
                            XYZPoint point;
                            point.x = cPointX;
                            point.y = cPointY;
                            point.z = (int)obj->world_z;
                            if (obj->canPath(
                                    point, obj->master_obj->los - DAT_00575564,
                                    -1, &pathResult, 1, -1, -1) == 0) {
                                this->pathMap.setValue(cPointX, cPointY, 1);

                                int bestScore = -1;
                                int bestX = 0;
                                int bestY = 0;
                                int quadrantX;
                                int quadrantY;
                                QuadrantLog* quadrant = &this->quadrantLog[0][0];
                                for (quadrantX = 0; quadrantX < 4; ++quadrantX) {
                                    for (quadrantY = 0; quadrantY < 4; ++quadrantY) {
                                        int score = quadrant->numberAttacksOnUs * 25 +
                                            quadrant->numberExploredTiles +
                                            debug_rand(
                                                (char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp",
                                                0x420) % 100;
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
                                switch (choice) {
                                case 0:
                                    cPointX = bestX;
                                    cPointY = bestY;
                                    break;
                                case 1:
                                    cPointX = bestX;
                                    cPointY = maxY;
                                    break;
                                case 2:
                                    cPointX = maxX;
                                    cPointY = maxY;
                                    break;
                                default:
                                    cPointX = maxX;
                                    cPointY = bestY;
                                    break;
                                }
                            } else {
                                this->pathMap.setValue(cPointX, cPointY, 0);
                            }
                            *outX = (float)cPointX;
                            *outY = (float)cPointY;
                            return 1;
                        }
                    }
                }
                ++i;
            }
        }
    }
}
