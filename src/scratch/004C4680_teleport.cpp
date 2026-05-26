// VA: 004C4680 RGE_Static_Object::teleport
// PDB source: stat_obj.cpp
// Attempt log:
// - reconstructed main topology from packet: clamp target coords, compute map tile, detach/attach tile node, update pos/target fields, sprite-frame switch.
// - default /O2 compiles to 880 bytes vs target 1285, too short for extraction; many switch cases / exact sprite projection arms are missing or over-optimized.
// - tried /Od diagnostically: 1040 bytes, still too short and wrong frame family, so not viable.
// - restored default flags. Give-up: requires full source reconstruction of the 17-case tile-shape switch and exact map/type layout; no accepted_drift proposed.

extern long __ftol(float);

class TileList { public: void remove(void*, int); void add(void*); };
class ObjType { public: char gap0[0x38]; float radius; char gap3c[0x68-0x3c]; unsigned char shapeMode; };
class MapInfo { public: char gap0[8]; int width; int height; char gap10[0x28-0x10]; int screen_x_offset; char gap2c[0x8d8c-0x2c]; TileList** rows; short tile_h; short tile_w; };
class Scenario { public: char gap0[0x3c]; MapInfo* map; };
class RGE_Static_Object_4C4680 {
public:
    void* vt; char gap4[4]; ObjType* type; Scenario* scenario; char gap10[0x1c-0x10]; TileList* tile; int busy; char gap24[4]; short sx1, sy1, sx2, sy2; char gap30[8]; float x, y, z;
    int removeFromObstructionMap(int); int addToObstructionMap(int); void update_sprite(Scenario*, int, int);
    float teleport(float nx, float ny, float nz);
};

float RGE_Static_Object_4C4680::teleport(float nx, float ny, float nz)
{
    MapInfo* map;
    float rx, rz;
    int tx, ty;
    TileList* newTile;
    float zero = *(float*)0x574720;

    map = this->scenario->map;
    if (this->busy != 0) return zero;

    if ((double)this->type->radius > *(double*)0x574718) this->removeFromObstructionMap(2);
    if (nx < zero) nx = 0.0f;
    if (!(nx < (float)map->width)) nx = nx - *(float*)0x574744;
    if (ny < zero) ny = 0.0f;
    if (!(ny < (float)map->height)) ny = ny - *(float*)0x574744;

    tx = (int)nx;
    ty = (int)ny;
    rx = nx - (float)tx;
    rz = ny - (float)ty;
    if (tx >= map->width) tx = map->width - 1; else if (tx < 0) tx = 0;
    if (ty >= map->height) ty = map->height - 1; else if (ty < 0) ty = 0;

    newTile = (TileList*)((char*)map->rows[ty] + (tx + tx * 2) * 8);
    if (newTile == this->tile && this->busy == 0) {
        this->x = nx; this->y = ny; this->z = nz;
    } else {
        if (this->tile) this->tile->remove(this, 0);
        newTile->add(this);
        if (this->tile) this->update_sprite(this->scenario, 0, -1);
        this->x = nx; this->y = ny; this->z = nz; this->tile = newTile;
        if (this->type->shapeMode == 2) this->update_sprite(this->scenario, 0, -1);
    }

    if ((double)this->type->radius > *(double*)0x574718) this->addToObstructionMap(2);

    float frame = zero;
    switch (((unsigned char*)newTile)[4]) {
    case 0: if (rx + rz < *(float*)0x57472c) frame = rx; break;
    case 1: if (rx + rz < *(float*)0x57472c) frame = rz; break;
    case 2: frame = (*(float*)0x57472c <= rz ? *(float*)0x57472c - rx : *(float*)0x57472c - rz); break;
    case 3: frame = (*(float*)0x57472c <= rz ? rz : rx); break;
    case 4: frame = *(float*)0x57472c - rz; break;
    case 5: frame = *(float*)0x57472c - rx; break;
    case 6: frame = rx; break;
    case 7: frame = rz; break;
    default: frame = zero; break;
    }
    this->z = frame;
    this->sx1 = (short)((rx + rz) * *(short*)((char*)map + 0x8d9c));
    this->sy1 = (short)((frame + rx - *(float*)0x574730 - rz - this->z) * *(short*)((char*)map + 0x8d9a));
    if (this->type->shapeMode == 0) { this->sx2 = this->sx1; this->sy2 = this->sy1; }
    else if (this->type->shapeMode == 1) {
        this->sx2 = (short)((rx + rz) * *(short*)((char*)map + 0x8d9c));
        this->sy2 = (short)((frame - rz) * *(short*)((char*)map + 0x8d9a));
    }
    return frame;
}
