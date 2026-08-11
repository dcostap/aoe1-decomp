// VA: 004C6DA0 RGE_Static_Object::changeInfluenceMap
// Attempt log:
// 1: direct reconstruction from packet with local offset stubs and natural floor/ceil/cell loops.
// 2: corrected InfluenceMap calls to incrementValue/decrementValue and probed min/max compare polarity; default source still compiles 608B vs original 647B, indicating FPU/topology source shape is still too simple.
// 3: fixed master object offsets (los +28, radius_x +30, radius_y +34) and duplicated mode call inside gradient/non-gradient branches to mirror original call blocks.
// 4: removed persistent ObjectType* local and used direct member access; major improvement to same-size 647B, exact through tile-bound calculations until FPU object-bounds stack-order region.
// 5: probed min/max compare polarity for lower bounds toward original `test ah,41` branches; edit diff improved but positional worsened, rolled back to best same-size source.
// 6: reordered object-bound assignments as minX, maxX, minY, maxY; testing whether the original VC5 FPU stack schedule follows source result order.
// 7: reversed lower-bound predicates to `objectMinX > yTile` / `objectMinY > xTile`, matching the original fcomp operand order while preserving max-clamp behavior.
// 8: source audit renamed the proven master/object fields to their canonical stat_obj ownership names (los, radius_x/radius_y, world_x/world_y); no layout or behavior change intended.
// exact: the result-assignment order fixes the VC5 x87 stack/store order; reversed lower-bound operands fix fcomp versus fcom. Final audit retains typed donor-backed layouts and default flags; local validation matched all 647 bytes.

extern "C" double __cdecl floor(double);
extern "C" double __cdecl ceil(double);

struct RGE_Master_Static_Object {
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x24];
    float los;
    char gap_2c[4];
    float radius_x;
    float radius_y;
};

struct InfluenceMap {
    virtual ~InfluenceMap();
    int incrementValue(int y, int x, int v);
    int decrementValue(int y, int x, int v);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    char gap_0c[0x2c];
    float world_x;
    float world_y;
    void changeInfluenceMap(InfluenceMap* map, int mode, int gradient, int useRadius);
};

void RGE_Static_Object::changeInfluenceMap(InfluenceMap* map, int mode, int gradient, int useRadius)
{
    int minYTile;
    int minXTile;
    int maxYTile;
    int maxXTile;
    float objectMaxY;
    float objectMinY;
    float objectMaxX;
    float objectMinX;

    int minY;
    int maxY;
    int minX;
    int maxX;

    if (useRadius == 0) {
        minY = (int)floor(this->world_x - this->master_obj->radius_x);
        maxY = (int)ceil(this->master_obj->radius_x + this->world_x);
        minX = (int)floor(this->world_y - this->master_obj->radius_y);
        maxX = (int)ceil(this->master_obj->radius_y + this->world_y);
    } else {
        minY = (int)floor(this->world_x - this->master_obj->radius_x - this->master_obj->los);
        maxY = (int)ceil(this->master_obj->radius_x + this->master_obj->los + this->world_x);
        minX = (int)floor(this->world_y - this->master_obj->radius_y - this->master_obj->los);
        maxX = (int)ceil(this->master_obj->radius_y + this->master_obj->los + this->world_y);
    }

    if (useRadius == 0) {
        objectMinX = this->world_x - this->master_obj->radius_x;
        objectMaxX = this->master_obj->radius_x + this->world_x;
        objectMinY = this->world_y - this->master_obj->radius_y;
        objectMaxY = this->master_obj->radius_y + this->world_y;
    } else {
        objectMinX = this->world_x - this->master_obj->radius_x - this->master_obj->los;
        objectMaxX = this->master_obj->radius_x + this->master_obj->los + this->world_x;
        objectMinY = this->world_y - this->master_obj->radius_y - this->master_obj->los;
        objectMaxY = this->master_obj->radius_y + this->master_obj->los + this->world_y;
    }

    for (int xTile = minX; xTile < maxX; xTile++) {
        for (int yTile = minY; yTile < maxY; yTile++) {
            if (gradient) {
                float left = (float)yTile;
                if (objectMinX > (float)yTile) left = objectMinX;
                float right = (float)(yTile + 1);
                if (objectMaxX < right) right = objectMaxX;
                float top = (float)xTile;
                if (objectMinY > (float)xTile) top = objectMinY;
                float bottom = (float)(xTile + 1);
                if (objectMaxY < bottom) bottom = objectMaxY;
                int value = (int)((right - left) * (bottom - top) * *(float*)0x00574774);
                if (mode == 1) {
                    map->incrementValue(yTile, xTile, value);
                } else {
                    map->decrementValue(yTile, xTile, value);
                }
            } else {
                if (mode == 1) {
                    map->incrementValue(yTile, xTile, 255);
                } else {
                    map->decrementValue(yTile, xTile, 255);
                }
            }
        }
    }
}
