// VA: 004C6DA0 RGE_Static_Object::changeInfluenceMap
// Attempt log:
// 1: direct reconstruction from packet with local offset stubs and natural floor/ceil/cell loops.
// 2: corrected InfluenceMap calls to incrementValue/decrementValue and probed min/max compare polarity; default source still compiles 608B vs original 647B, indicating FPU/topology source shape is still too simple.
// 3: fixed master object offsets (los +28, radius_x +30, radius_y +34) and duplicated mode call inside gradient/non-gradient branches to mirror original call blocks.
// 4: removed persistent ObjectType* local and used direct member access; major improvement to same-size 647B, exact through tile-bound calculations until FPU object-bounds stack-order region.
// 5: probed min/max compare polarity for lower bounds toward original `test ah,41` branches; edit diff improved but positional worsened, rolled back to best same-size source.
// left in scratch: same-size 647B and exact through first tile-bound phase; remaining mismatch begins at offset 0x104 in the FPU object-bounds setup. Rebuilt computes equivalent min/max floats but stores/fxch them in a different FPU stack order, then cascades through gradient min/max comparisons and loop tail. Not accepted_drift-safe.

extern "C" double __cdecl floor(double);
extern "C" double __cdecl ceil(double);

struct ObjectType {
    char gap_00[0x28];
    float radius;
    char gap_2c[4];
    float centerX;
    float centerY;
};

struct InfluenceMap {
    int incrementValue(int y, int x, int v);
    int decrementValue(int y, int x, int v);
};

class RGE_Static_Object {
public:
    char gap_00[8];
    ObjectType* object_type;
    char gap_0c[0x2c];
    float x;
    float y;
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
        minY = (int)floor(this->x - this->object_type->centerX);
        maxY = (int)ceil(this->object_type->centerX + this->x);
        minX = (int)floor(this->y - this->object_type->centerY);
        maxX = (int)ceil(this->object_type->centerY + this->y);
    } else {
        minY = (int)floor(this->x - this->object_type->centerX - this->object_type->radius);
        maxY = (int)ceil(this->object_type->centerX + this->object_type->radius + this->x);
        minX = (int)floor(this->y - this->object_type->centerY - this->object_type->radius);
        maxX = (int)ceil(this->object_type->centerY + this->object_type->radius + this->y);
    }

    if (useRadius == 0) {
        objectMinX = this->x - this->object_type->centerX;
        objectMinY = this->y - this->object_type->centerY;
        objectMaxX = this->object_type->centerX + this->x;
        objectMaxY = this->object_type->centerY + this->y;
    } else {
        objectMinX = this->x - this->object_type->centerX - this->object_type->radius;
        objectMinY = this->y - this->object_type->centerY - this->object_type->radius;
        objectMaxX = this->object_type->centerX + this->object_type->radius + this->x;
        objectMaxY = this->object_type->centerY + this->object_type->radius + this->y;
    }

    for (int xTile = minX; xTile < maxX; xTile++) {
        for (int yTile = minY; yTile < maxY; yTile++) {
            if (gradient) {
                float left = (float)yTile;
                if (left < objectMinX) left = objectMinX;
                float right = (float)(yTile + 1);
                if (objectMaxX < right) right = objectMaxX;
                float top = (float)xTile;
                if (top < objectMinY) top = objectMinY;
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
