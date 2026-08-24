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
// - v10: paused in scratch. Best earlier check: 467/467 bytes, positional diff
//   64.8822%, edit diff 11.9914%, first mismatch +0x1e.
// - v11-v12: restored the binary-backed RGE_Tile/RGE_Player/RGE_Master_Static_Object
//   ownership instead of raw row/master/world offsets; VC5 emitted identical
//   bytes, confirming the typed model without a metric-only cursor scaffold.
// - v13: changed the neighbor counter to its period-accurate `long` spelling;
//   this improves block coverage/shape (98.67%) but does not change the
//   persistent world_x/world_y EBX/EBP coloring.
// - v14: declaration/initialization placement of map locals was a codegen
//   duplicate. Current source remains typed and natural; no inline asm.
// - v15: restored the earlier int-counter/declaration-order source basin as a
//   diagnostic rollback while retaining typed virtual class surfaces.
// - v16: retained the ordinary common return, owner-mismatch clear, and
//   boundary clear in the final neighbor arm; this restored the original
//   counter stack store and produced an exact default-flag match.
//
// Exact under the repository default flags. The source uses named typed
// world/player/master/map/list ownership and ordinary neighbor checks; no raw
// offset plumbing, explicit vptr stores, novtable/manual-vtable surface, or
// inline asm is retained.
// Main-agent audit restored canonical polymorphic master/static/map/world/player
// ownership and retained typed neighboring-tile searches.

#ifndef T_B_OBJ_CONTEXT_H
class RGE_Player;
class RGE_Object_List;
class RGE_Game_World;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short master_id; // +0x10
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner; // +0x0c
    char gap_10[0x28];
    float world_x; // +0x38
    float world_y; // +0x3c
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    char gap_04[0x08];
    RGE_Static_Object* find_by_master_id(int master_id, float x, float y, unsigned char a, unsigned char b, RGE_Static_Object* c);
};

class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
    unsigned char border_type;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    RGE_Object_List objects; // +0x0C, tile stride 0x18
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[4];
    short width;
    char gap_0a[2];
    short height;
    char gap_0e[0x8d8c - 0x0e];
    RGE_Tile** row_lists;
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    char gap_04[0x24];
    RGE_Map* map;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world; // +0x3C
};

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    long check(TRIBE_Building_Object** out);
};
#endif

long TRIBE_Building_Object::check(TRIBE_Building_Object** out)
{
    int counter;
    short h;
    short w;
    short y;
    short max_y;

    RGE_Map* map = this->owner->world->map;
    w = (short)(long)this->world_x;
    y = (short)(long)this->world_y;
    h = map->width - 1;
    counter = 0;
    max_y = map->height - 1;

    if (y > 0) {
        out[0] = (TRIBE_Building_Object*)map->row_lists[y - 1][w].objects.find_by_master_id(
            (int)this->master_obj->master_id, -1.0f, -1.0f, 0, 0, 0);
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
        out[1] = (TRIBE_Building_Object*)map->row_lists[y][w - 1].objects.find_by_master_id(
            (int)this->master_obj->master_id, -1.0f, -1.0f, 0, 0, 0);
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
        out[2] = (TRIBE_Building_Object*)map->row_lists[y][w + 1].objects.find_by_master_id(
            (int)this->master_obj->master_id, -1.0f, -1.0f, 0, 0, 0);
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
        out[3] = (TRIBE_Building_Object*)map->row_lists[y + 1][w].objects.find_by_master_id(
            (int)this->master_obj->master_id, -1.0f, -1.0f, 0, 0, 0);
        if (out[3] != 0) {
            if (out[3]->owner == this->owner) {
                counter++;
            } else {
                out[3] = 0;
            }
        }
    } else {
        out[3] = 0;
    }
    return counter;
}
