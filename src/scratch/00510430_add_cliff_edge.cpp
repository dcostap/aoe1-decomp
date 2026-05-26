// 00510430 TRIBE_Map::add_cliff_edge
// Attempt log:
// try 1: direct control-flow reconstruction from packet, local cliff-info array and helper calls: exact-size comparable but broad mismatch (59.8330% positional, 38.3447% edit, first mismatch +6).
// try 2: /GX had no effect; rolled back.
// try 3: swapped x/y parameter spelling to match initial [esp+2c] load; first mismatch moved to +10 but edit diff worsened (40.3189%), rolled back.
// try 4: /O1 too small (.text 987 vs 1317), rolled back.
// try 5: /Od exact-size comparable but debug-basin mismatch (92.4070% positional), rolled back.
// left in scratch: broad but useful behavior skeleton; remaining mismatch is not accepted_drift quality and likely needs the exact original high-level cliff-info control-flow topology and real TRIBE_Cliff_Info/TRIBE_Map declarations.

struct TRIBE_Cliff_Info { long info[4]; };
class RGE_Static_Object { public: virtual void destroy(int); char gap[0x34]; float x; float y; };
class RGE_Tile_List { public: void add_node(int x, int y); };
struct TerrainPtr { char gap[0x40]; RGE_Tile_List** lists; char gap44[0x38]; short list_index; };
struct MapWorld { char gap[0x8dc0]; TerrainPtr* terrain; };
extern long __ftol();

class TRIBE_Map {
public:
    RGE_Static_Object* find_cliff(long x, long y);
    TRIBE_Cliff_Info* get_cliff_info(TRIBE_Cliff_Info* out, RGE_Static_Object* cliff);
    unsigned char check_cliff_valid(TRIBE_Cliff_Info info);
    long set_cliff(TRIBE_Cliff_Info info, long a, long b);
    void remove_cliff_edge(long x, long y, long facing);
    long add_cliff_edge(long x, long y, long facing, long existing, long otherFacing);
};

long TRIBE_Map::add_cliff_edge(long x, long y, long facing, long existing, long otherFacing)
{
    RGE_Static_Object* cliff = this->find_cliff(x, y);
    TRIBE_Cliff_Info ci;
    this->get_cliff_info(&ci, cliff);

    long possible_direction1 = 0;
    long possible_facing1 = -1;
    long possible_direction2 = 0;
    long possible_facing2 = -1;

    long old = ci.info[facing];
    if (old != 0) {
        if (existing == 0) return existing;
        if (existing == old) return existing;
    }

    if (cliff != 0) {
        for (long yy = -1; yy < 2; ++yy) {
            for (long xx = -1; xx < 2; ++xx) {
                TerrainPtr* t = ((MapWorld*)this)->terrain;
                long iy = (long)cliff->y + yy;
                long ix = (long)cliff->x + xx;
                RGE_Tile_List* list = t->lists[t->list_index] + 0x1b;
                list->add_node(ix, iy);
            }
        }
        cliff->destroy(1);
    }

    long replaceFacing = otherFacing;
    if (replaceFacing == facing) replaceFacing = -1;

    if (replaceFacing >= 0) {
        for (long i = 0; i < 4; ++i) {
            if (i != replaceFacing) {
                this->remove_cliff_edge(x, y, i);
                ci.info[i] = 0;
            }
        }
    } else {
        long count = 0;
        for (long i = 0; i < 4; ++i) {
            if (ci.info[i] != 0 && i != facing) ++count;
        }
        if (count == 2) {
            for (i = 0; i < 4; ++i) {
                if (ci.info[i] != 0 && i != facing) {
                    if (possible_facing1 < 0) {
                        possible_facing1 = i;
                        possible_direction1 = ci.info[i];
                    } else {
                        possible_facing2 = i;
                        possible_direction2 = ci.info[i];
                    }
                    ci.info[i] = 0;
                }
            }
        }
    }

    if (existing != 0) {
        ci.info[facing] = existing;
        if (possible_facing1 > -1) {
            ci.info[possible_facing1] = possible_direction1;
            if (!this->check_cliff_valid(ci)) {
                ci.info[possible_facing1] = 0;
                this->remove_cliff_edge(x, y, possible_facing1);
            }
        }
        if (possible_facing2 > -1) {
            ci.info[possible_facing2] = possible_direction2;
            if (!this->check_cliff_valid(ci)) {
                ci.info[possible_facing2] = 0;
                this->remove_cliff_edge(x, y, possible_facing2);
            }
        }
        if (!this->check_cliff_valid(ci)) {
            for (long j = 0; j < 4; ++j) {
                if (j != facing && ci.info[j] != 0) {
                    this->remove_cliff_edge(x, y, j);
                    ci.info[j] = 0;
                }
            }
        }
    } else {
        existing = 1;
        ci.info[facing] = 1;
        long ok = 0;
        if (possible_facing1 > -1) {
            ci.info[possible_facing1] = possible_direction1;
            if (!this->check_cliff_valid(ci)) ci.info[possible_facing1] = 0;
            else { ok = 1; possible_direction1 = 0; }
        }
        if (!ok && possible_facing2 > -1) {
            ci.info[possible_facing2] = possible_direction2;
            if (!this->check_cliff_valid(ci)) ci.info[possible_facing2] = 0;
            else { ok = 1; possible_direction2 = 0; }
        }
        if (!ok && !this->check_cliff_valid(ci)) {
            ci.info[facing] = -1;
            existing = -1;
            if (possible_facing1 > -1) {
                ci.info[possible_facing1] = possible_direction1;
                if (!this->check_cliff_valid(ci)) ci.info[possible_facing1] = 0;
                else { ok = 1; possible_direction1 = 0; }
            }
            if (!ok && possible_facing2 > -1) {
                ci.info[possible_facing2] = possible_direction2;
                if (!this->check_cliff_valid(ci)) ci.info[possible_facing2] = 0;
                else { ok = 1; possible_direction2 = 0; }
            }
            if (!ok && !this->check_cliff_valid(ci)) {
                for (long j = 0; j < 4; ++j) {
                    if (j != facing && ci.info[j] != 0) {
                        this->remove_cliff_edge(x, y, j);
                        ci.info[j] = 0;
                    }
                }
            }
        }
    }

    if (possible_direction1) this->remove_cliff_edge(x, y, possible_facing1);
    if (possible_direction2) this->remove_cliff_edge(x, y, possible_facing2);
    this->set_cliff(ci, x, y);
    return existing;
}
