// 004CACE0 TRIBE_Combat_Object::reposition_artifact
// Attempt log:
// 1: natural source from packet/decompiler, local object/map surfaces.
// 2: fixed map-holder layout (+0x28 map, +0x40 object) after first compile error.
// 3: default /O2 build is too small for configured function: .text 784 bytes vs original 862; no normal comparison possible.
// 4: probed /GX response file; no size/codegen change (still 784), removed.
// 5: probed /Od only as diagnostic; it gives comparable 862 bytes but EBP-frame debug-basin code with 88.86% positional diff, not a viable match path; removed flag.
// 6: Current source represents behavior/calls: choose parent/self position, expand rectangle around artifact, terrain checks for 1/2, can_place vtable +0x20 with flag variants, fallback original position, set_location, parent update, virtual +0x34/+0x44/+0x9c, scale=1.0.
// 7: Main blocker is source shape: natural helpers/structured loops collapse the /O2 body far below original size; original uses explicit unrolled edge scans and many stack locals.
// 8: Likely needs a much more literal single-function CFG with duplicated can_place blocks and hand-shaped loop labels, not helper functions.
// 9: No accepted_drift proposal: either size-short under real flags or broad /Od diagnostic drift.
// GIVEUP: left in scratch with no custom flags.

extern "C" long __cdecl _ftol(void);

class RGE_Map {
public:
    char gap_00[8];
    int map_width;   // +8
    int map_height;  // +c
    unsigned char get_terrain(short x, short y);
};

class RGE_Game_World_MapHolder { public: char gap_00[0x28]; RGE_Map* map; char gap_2c[0x40 - 0x2c]; void* something40; };
class RGE_Game_World { public: char gap_00[0x3c]; RGE_Game_World_MapHolder* map_holder; };

class MasterObj {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual unsigned char can_place(void* world, float x, float y, int a, int b, int c, int d, int e, int f, int g); // +20
};

class TRIBE_Combat_Object {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30();
    virtual float vf34(float x, float y, float z);
    virtual void v38(); virtual void v3c(); virtual void v40();
    virtual void vf44(void* p);
    virtual void v48(); virtual void v4c(); virtual void v50(); virtual void v54();
    virtual void v58(); virtual void v5c(); virtual void v60(); virtual void v64();
    virtual void v68(); virtual void v6c(); virtual void v70(); virtual void v74();
    virtual void v78(); virtual void v7c(); virtual void v80(); virtual void v84();
    virtual void v88(); virtual void v8c(); virtual void v90(); virtual void v94();
    virtual void v98();
    virtual void vf9c(int a, float x, float y, float z);
    virtual void va0(); virtual void va4(); virtual void va8(); virtual void vac();
    virtual void vb0(); virtual void vb4(); virtual void vb8(); virtual void vbc();
    virtual void vc0(); virtual void vc4(); virtual void vc8(); virtual void vcc();
    virtual void vd0(); virtual void vfd4();

    char gap_04[4];
    MasterObj* master; // +8
    RGE_Game_World* world; // +c
    char gap_10[0x10];
    TRIBE_Combat_Object* artifact_parent; // +20
    char gap_24[0x0c];
    float scale; // +30
    char gap_34[4];
    float x; // +38
    float y; // +3c
    float z; // +40

    void set_location(float x, float y, float z);
    void reposition_artifact();
};

static int ok_terrain(unsigned char t) { return t == 1 || t == 2; }

static int can_place_obj(TRIBE_Combat_Object* obj, int ix, int iy, int last_flags)
{
    float fx = (float)ix - -0.5f;
    float fy = (float)iy - -0.5f;
    if (last_flags) {
        return obj->master->can_place(obj->world, fx, fy, 0, 0, 1, 1, 0, 1, 1);
    }
    return obj->master->can_place(obj->world, fx, fy, 0, 1, 1, 1, 0, 1, 1);
}

void TRIBE_Combat_Object::reposition_artifact()
{
    int y2;
    int x2;
    int y1;
    int x1;
    float x_pos;
    float y_pos;
    int found_pos;
    int x;
    int map_max_x;
    int map_max_y;

    TRIBE_Combat_Object* p = this->artifact_parent;
    if (p != 0) {
        y2 = (int)p->x;
        x2 = (int)p->y;
        y1 = *(int*)&p->x;
        x_pos = p->y;
    } else {
        y2 = (int)this->x;
        x2 = (int)this->y;
        y1 = *(int*)&this->x;
        x_pos = this->y;
    }
    x1 = y2;
    found_pos = x2;

    RGE_Map* map = this->world->map_holder->map;
    x = 0;
    map_max_x = map->map_width - 1;
    map_max_y = map->map_height - 1;

    while (1) {
        int found = 0;
        int i = y2;
        for (; i <= x1; i++) {
            unsigned char t = map->get_terrain((short)i, (short)x2);
            if (!ok_terrain(t)) {
                if (!can_place_obj(this, i, x2, 0)) { found = 1; break; }
            }
            t = map->get_terrain((short)i, (short)found_pos);
            if (!ok_terrain(t)) {
                if (!can_place_obj(this, i, found_pos, 0)) { found = 1; break; }
            }
        }
        if (!found) {
            int j = x2 + 1;
            for (; j <= found_pos - 1; j++) {
                unsigned char t = map->get_terrain((short)y2, (short)j);
                if (!ok_terrain(t)) {
                    if (!can_place_obj(this, y2, j, 0)) { found = 1; break; }
                }
                t = map->get_terrain((short)x1, (short)j);
                if (!ok_terrain(t)) {
                    if (!can_place_obj(this, x1, j, 1)) { found = 1; break; }
                }
            }
        }
        if (found) break;

        if (y2 == 0 && x1 == map_max_x && x2 == 0 && found_pos == map_max_y) {
            p = this->artifact_parent;
            if (p != 0) {
                y1 = *(int*)&p->x;
                x_pos = p->y;
            } else {
                y1 = *(int*)&this->x;
                x_pos = this->y;
            }
            break;
        }
        if (y2 > 0) y2--;
        if (x2 > 0) x2--;
        if (x1 < map_max_x) x1++;
        if (found_pos < map_max_y) found_pos++;
    }

    float new_x = *(float*)&y1;
    this->set_location(new_x, x_pos, this->z);
    if (this->artifact_parent != 0) {
        this->vfd4();
    }
    this->vf34(new_x, x_pos, this->z);
    this->vf44(this->world->map_holder->something40);
    this->vf9c(0, new_x, x_pos, this->z);
    this->scale = 1.0f;
}
