// 004CBD40 TRIBE_Combat_Object::higher_check_for_cliff
// Source: t_c_obj.cpp lines 1379-1442
// attempt 1: natural decompiler-shaped source with local layout/types; close but RGE_Tile size wrong (20 vs 24), fcom constants double, and register coloring differs.
// attempt 2: fixed RGE_Tile to 0x18 so map_row_offset[row][col] emits lea x+x*2 then [row+x*8+10h]; moved first mismatch from tile indexing to register coloring.
// attempt 3: used absolute float constants for 0.0/2pi; got correct dword global fcom/fsub addresses but introduced extra FPU stack shuffling when a was a named float.
// attempt 4: kept double atan2/fpatan value with absolute float constants; better size, but remaining broad drift starts at EBX/EBP/EDI allocation for node/angle/y2.
// attempt 5: rewrote angle tests using decompiler's outside-range condition; improved to best edit diff 120B and first mismatch 70.
// attempt 6: tried register-qualified node/angle/y2 locals; VC5 ignored/helped none, no metric improvement.
// attempt 7: tried while(1) with explicit null-return at loop bottom; worsened early branch spans.
// attempt 8: tried explicit angle_local/y2_bits locals to force EDI/EBP; worsened to first mismatch 19.
// attempt 9: tried for-loop over node->next; worsened loop entry/null-test shape.
// attempt 10: tried naming lines_intersect result local; worsened call/branch scheduling and reverted.
// Left in scratch: behavior and call set look right, but broad register-allocation/FPU compare drift remains; not an accepted_drift candidate.

extern "C" double __cdecl atan2(double, double);

typedef unsigned char uchar;

class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short object_group;
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    long id;
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x29];
    uchar facet;                 // +0x35
    char gap_36[2];
    float world_x;               // +0x38
    float world_y;               // +0x3C
};

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    void* vtable_ptr;
    RGE_Object_Node* list;
};

class RGE_Tile {
public:
    char gap_00[0x10];
    RGE_Object_Node* list;       // objects.list at +0x10
    char gap_14[4];
};

class RGE_Map {
public:
    void* vtable_ptr;
    RGE_Tile* map;
    long map_width;
    long map_height;
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;
};

extern "C" int __cdecl lines_intersect(float, float, float, float, float, float, float, float);

#define F32(addr) (*(float*)(addr))
#define CLIFF_TABLE ((float*)0x00587258)

class TRIBE_Combat_Object : public RGE_Static_Object {
public:
    int higher_check_for_cliff(RGE_Static_Object* obj, int col, int row,
                               float x1, float y1, float x2, float y2,
                               RGE_Map* map, RGE_Static_Object* old_obj,
                               float* angle, int* dir);
};

int TRIBE_Combat_Object::higher_check_for_cliff(RGE_Static_Object* obj, int col, int row,
                                                float x1, float y1, float x2, float y2,
                                                RGE_Map* map, RGE_Static_Object* old_obj,
                                                float* angle, int* dir)
{
    if (row < 0 || row >= map->map_height || col < 0 || col >= map->map_width) {
        return 0;
    }

    RGE_Object_Node* node = map->map_row_offset[row][col].list;
    if (node == 0) {
        return 0;
    }
    do {
        RGE_Static_Object* cliff = node->node;
        if (cliff->master_obj->object_group == 0x22 && cliff != old_obj) {
            old_obj = cliff;
            if (*angle == -1.0f) {
                double a = atan2((double)(obj->world_y - this->world_y), (double)(obj->world_x - this->world_x));
                *angle = (float)a;
                if (a < F32(0x00574C98)) {
                    *angle = (float)(a - F32(0x00574CA4));
                }
            }

            int facet = cliff->facet;
            int off = facet << 5;
            if (lines_intersect(x1, y1, x2, y2,
                                F32(0x00587268 + off) + x1,
                                F32(0x0058726C + off) + y1,
                                F32(0x00587270 + off) + x2,
                                F32(0x00587274 + off) + y2)) {
                if (((0x18 < facet) || (*angle < F32(0x00587258 + off)) || (F32(0x0058725C + off) < *angle)) &&
                    ((*angle < F32(0x00587260 + off)) || (F32(0x00587264 + off) < *angle))) {
                    --*dir;
                    return 1;
                }
                ++*dir;
                return 1;
            }
        }
        node = node->next;
    } while (node != 0);

    return 0;
}
