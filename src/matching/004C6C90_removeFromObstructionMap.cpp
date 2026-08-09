// VA: 004C6C90 RGE_Static_Object::removeFromObstructionMap
// PDB source: stat_obj.cpp, lines 4298-4361
// Attempt log:
// baseline: natural typed reconstruction mirrored from the exact same-TU
// obstruction-map update, with named master/object fields and pathing systems.
// Main-agent audit replaced raw vptr storage with canonical destructors;
// emitted code remains exact.

extern float DAT_00574720;
extern float DAT_00574768;

class PathingSystem {
public:
    void decrementObstruction(int x, int y);
};

extern PathingSystem pathSystem;
extern PathingSystem aiPathSystem;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x24];
    float los;                    // +0x28
    char gap_2C[0x04];
    float radius_x;               // +0x30
    float radius_y;               // +0x34
    float radius_z;               // +0x38
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj; // +0x08
    char gap_0C[0x2C];
    float world_x;                        // +0x38
    float world_y;                        // +0x3C
    char gap_40[0x44];
    unsigned char inObstructionMapValue;       // +0x84
    unsigned char lastInObstructionMapValue;    // +0x85

    int removeFromObstructionMap(int mode);
};

int RGE_Static_Object::removeFromObstructionMap(int mode)
{
    if (this->master_obj->radius_z <= DAT_00574720) {
        return 0;
    }
    if (this->inObstructionMapValue == 0) {
        return 0;
    }

    int obMapMinX = (int)((this->world_x - this->master_obj->radius_x) * DAT_00574768);
    if (obMapMinX < 0) {
        obMapMinX = 0;
    }
    int obMapMinY = (int)((this->world_y - this->master_obj->radius_y) * DAT_00574768);
    if (obMapMinY < 0) {
        obMapMinY = 0;
    }
    int obMapMaxX = (int)((this->master_obj->radius_x + this->world_x) * DAT_00574768);
    int obMapMaxY = (int)((this->master_obj->radius_y + this->world_y) * DAT_00574768);

    for (int x = obMapMinX; x < obMapMaxX; x++) {
        for (int y = obMapMinY; y < obMapMaxY; y++) {
            if (mode != 1) {
                pathSystem.decrementObstruction(x, y);
            }
            if (mode != 0) {
                aiPathSystem.decrementObstruction(x, y);
            }
        }
    }

    this->lastInObstructionMapValue = this->inObstructionMapValue;
    this->inObstructionMapValue = 0;
    return 1;
}
