// VA: 0046D280 PathingSystem::passable
// PDB source: pathsys.cpp
// Attempt log:
// - packet shows large optimized terrain/object passability test: computes footprint bounds from object/type data and x/y floats, scans terrain rows/nibbles, then optional object collision list.
// - initial local stub below only captures call signature/major parameters; exact source requires full PathingSystem/terrain-map layout and tile/object collision bitmap model.
// - checked related pathsys matches: obstruction/incrementObstruction confirm obstructionValue at +0xCE624 and 255-row byte packing; ctor scratch only gives broad object size. That is not enough to model the large passable footprint/terrain scan.
// - default /O2 compile is only 128 bytes vs target 1207 (too short for extraction); no meaningful byte comparison possible from this placeholder.
// - give-up: original contains several intertwined FPU footprint conversions, terrain-cost exception cases, nibble map scans, and optional object-collision cleanup calls. Needs a dedicated full-layout reconstruction; no accepted_drift proposed.

extern int __ftol(float);

struct ObjLike { char gap0[8]; void* master; };
class PathingSystem_46D280 {
public:
    char pad[0x11DC3C];
    void* map3c;
    void* world40;
    ObjLike* obj44;
    int unk48;
    int unk4c;
    float* terrain_costs;
    int passA, passB, passC, passD, minY, minX, maxY, maxX;
    char rest[0x11DCF4 - 0x11DCA4];
    void* listF4;
    int passable(ObjLike* obj, float x, float y, int checkObjects);
};

int PathingSystem_46D280::passable(ObjLike* obj, float x, float y, int checkObjects)
{
    // Minimal behavioral placeholder from first-pass packet reading.
    // Original has ~1207 bytes of optimized FPU/grid scanning and cannot be
    // safely approximated as accepted drift.
    this->obj44 = obj;
    this->passA = -1;
    this->passB = -1;
    this->minY = -1;
    this->minX = -1;
    this->maxY = -1;
    this->maxX = -1;
    int ix = (int)x;
    int iy = (int)y;
    if (obj == 0) return 0;
    if (checkObjects) {
        return (ix >= 0 && iy >= 0) ? 1 : 0;
    }
    return 1;
}
