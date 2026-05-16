// VA: 004C8ED0, TRIBE_Building_Object::check, 467 bytes
// Source: t_b_obj.cpp lines 577-642
// Attempt log:
// - v1: natural reconstruction from packet/decompiler; local object/master/world/map list layout.
// - v2: modeled four neighbor checks with direct RGE_Object_List::find_by_master_id calls and stack counter local.
// - v3: first build had extra frame/register pressure (EDI=this), not original ESI=this.
// - v4: rewrote to use direct member access and only original-like locals (counter,w,h,max_y).
// - v5: route world_x through long wx before assigning w; no register change, rolled back.
// - v6: predeclared y before w assignment; no change.
// - v7: swapped source variable roles (w=world_y, y=world_x) while preserving behavior; worsened size, rolled back.
// - v8: tried register short w to force x into EBX; no change.
// - v9: declared y in local block before w to probe allocation; no change.
// - v10: paused in scratch. Best check: 467/467 bytes, positional diff 64.8822%, edit diff 11.9914%, first mismatch +0x1e.
//   Blocker: localized but cascading EBX/EBP allocation swap for tile x/y after the two __ftol calls. Original keeps
//   world_x in EBX and world_y in EBP, then reuses EBX for out pointer; rebuilt keeps world_x in EBP and world_y in EBX.
//   Control flow, call set, stack cleanup, map/list address arithmetic, owner checks, and return behavior are close, but the
//   register swap shifts branch offsets and out-pointer stores. Tried direct members, reduced locals, predeclared y, register w,
//   and swapped semantic variable roles (rolled back). No inline asm.

class RGE_Player;
class RGE_Object_List;

class RGE_Static_Object {
public:
    char gap_00[0x0c];
    RGE_Player* owner; // +0x0c
};

class RGE_Object_List {
public:
    RGE_Static_Object* find_by_master_id(int master_id, float x, float y, unsigned char a, unsigned char b, RGE_Static_Object* c);
};

class MapRows {
public:
    char gap_00[8];
    short width;
    char gap_0a[2];
    short height;
    char gap_0e[0x8d8c - 0x0e];
    RGE_Object_List** row_lists;
};

class WorldLike { public: char gap_00[0x28]; MapRows* map_rows; };
class MasterObj { public: char gap_00[0x10]; short master_id; };

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    char gap_10[0x38 - 0x10];
    float world_x;
    float world_y;
    long check(TRIBE_Building_Object** out);
};

long TRIBE_Building_Object::check(TRIBE_Building_Object** out)
{
    int counter;
    short h;
    short y;
    short w;
    short max_y;

    MapRows* map = (*(WorldLike**)((char*)this->owner + 0x3c))->map_rows;
    w = (short)(long)this->world_x;
    y = (short)(long)this->world_y;
    h = map->width - 1;
    counter = 0;
    max_y = map->height - 1;

    if (y > 0) {
        out[0] = (TRIBE_Building_Object*)((RGE_Object_List*)((char*)map->row_lists[y - 1] + ((int)w + (int)w * 2) * 8 + 0x0c))->find_by_master_id((int)(*(MasterObj**)((char*)this + 8))->master_id, -1.0f, -1.0f, 0, 0, 0);
        if (out[0] != 0) {
            if (out[0]->owner == this->owner) {
                counter = 1;
            } else {
                out[0] = 0;
            }
        }
    } else {
        out[0] = 0;
    }

    if (w > 0) {
        out[1] = (TRIBE_Building_Object*)((RGE_Object_List*)((char*)map->row_lists[y] + ((int)w + (int)w * 2) * 8 - 0x0c))->find_by_master_id((int)(*(MasterObj**)((char*)this + 8))->master_id, -1.0f, -1.0f, 0, 0, 0);
        if (out[1] != 0) {
            if (out[1]->owner == this->owner) {
                counter++;
            } else {
                out[1] = 0;
            }
        }
    } else {
        out[1] = 0;
    }

    if (w < h) {
        out[2] = (TRIBE_Building_Object*)((RGE_Object_List*)((char*)map->row_lists[y] + ((int)w + (int)w * 2) * 8 + 0x24))->find_by_master_id((int)(*(MasterObj**)((char*)this + 8))->master_id, -1.0f, -1.0f, 0, 0, 0);
        if (out[2] != 0) {
            if (out[2]->owner == this->owner) {
                counter++;
            } else {
                out[2] = 0;
            }
        }
    } else {
        out[2] = 0;
    }

    if (y < max_y) {
        out[3] = (TRIBE_Building_Object*)((RGE_Object_List*)((char*)map->row_lists[y + 1] + ((int)w + (int)w * 2) * 8 + 0x0c))->find_by_master_id((int)(*(MasterObj**)((char*)this + 8))->master_id, -1.0f, -1.0f, 0, 0, 0);
        if (out[3] != 0) {
            if (out[3]->owner == this->owner) {
                counter++;
                return counter;
            }
        }
    }
    out[3] = 0;
    return counter;
}
