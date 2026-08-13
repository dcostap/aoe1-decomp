// VA: 004C7030 RGE_Static_Object::objectCollisionList
// Attempt log:
// 1: direct reconstruction from packet/decompiler; /GX is required for the EH-framed new path.
// 2: canonicalized the proven owner->world->map chain, map row offset, and RGE_Check_List ABI from same-TU donors; frame/size moved to the original basin.
// 3: a preloaded radius_y local reproduces the binary's fld radius_y / fld radius_x / fcomp x87 guard order; radius_z uses the binary-proven double zero.
// 4: moved rowOffset into each outer row and computed the typed Tile/Object_List cell before the inner bound guard; VC5 still hoists the row load after that guard.
// 5: early invalid-radius return with result initialized only in the valid path is behavior-correct but leaves a +18-byte structural drift and a broad later FPU/object-bound mismatch.
// 6: direct typed row indexing, integer cell addresses, and an early range continue were codegen duplicates.
// 7: volatile row-entry access kept the row load before the range guard and reduced the diagnostic diff to 224B, but is not plausible living source.
// 8: delaying the typed cell address until after that guard improved the volatile diagnostic topology; restored nonvolatile ownership for the final source.
// 9: candidate radius_z uses the binary-proven double-zero comparison; this is retained in the clean source.
// 10: nested dz guards and reversed coordinate compare operands are source-backed natural forms; the former was a duplicate, while the latter only improved edit alignment.
// 11: replaced the embedded-list stub with the proven RGE_Tile objects_list field at +0x10; a split tile-base local preserves the binary row address before the inner guard.
// 12: reversed the lower dz comparison to `dz >= -radius_z`, reproducing the target fcompp block.
// 13: replaced ternary x/y overlap expressions with nested positive guards; this recovered the target 245-instruction body and reduced the strict diff to 17 bytes.
// 14: modeled invalid-radius and valid-body result assignments; this restored exact size and leaves only EH-handler relocation plus return-tail scheduling drift.
// - Normalized the living source to typed tile indexing and ordinary overlap
//   predicates. This is farther from current bytes, but it removes raw cursor
//   arithmetic and decompiler labels.
// Current typed source: 776B rebuilt vs 776B original, five direct calls, and
// 17 strict differing bytes. Remaining drift is localized to the EH handler
// relocation and the shared invalid-return tail; it is not exact yet.

struct MasterObj {
    virtual ~MasterObj();
    char gap04[0x24];
    float los;
    char gap2c[4];
    float radius_x;
    float radius_y;
    float radius_z;
};
struct Map {
    virtual ~Map();
    char gap04[4];
    int width;
    int height;
    char gap10[0x8d7c];
    struct Tile** rows;
};
struct World {
    virtual ~World();
    char gap04[0x24];
    Map* map;
};
struct Owner {
    virtual ~Owner();
    char gap04[0x38];
    World* world;
};
struct Node { void* obj; Node* next; };
struct Tile {
    short screen_xpos;
    short screen_ypos;
    unsigned char fields[8];
    char gap0c[4];
    Node* objects_list;
    char gap14[4];
};
class RGE_Static_Object;
struct RGE_Check_List {
    virtual ~RGE_Check_List();
    RGE_Check_List();
    void add_node(RGE_Static_Object*, float, float, unsigned char);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    MasterObj* master_obj;
    Owner* owner;
    char gap10[0x28];
    float x;
    float y;
    float z;
    RGE_Check_List* objectCollisionList(float extra);
};

RGE_Check_List* RGE_Static_Object::objectCollisionList(float extra)
{
    MasterObj* mo = this->master_obj;
    float radius_y = mo->radius_y;
    RGE_Check_List* result;
    if (mo->radius_x <= 0.0f || radius_y <= 0.0f || mo->radius_z <= 0.0) {
        result = 0;
    } else {
        Map* map = this->owner->world->map;
        int minY = (int)this->x - 3;
        int maxY = (int)this->x + 3;
        int minX = (int)this->y - 3;
        int maxX = (int)this->y + 3;
        if (minY < 0) minY = 0;
        if (maxY >= map->width) maxY = map->width - 1;
        if (minX < 0) minX = 0;
        if (maxX >= map->height) maxX = map->height - 1;
        result = 0;
        for (int yy = minX; yy <= maxX; ++yy) {
        Tile* tile = &map->rows[yy][minY];
        if (minY <= maxY) {
            Node** list = &tile->objects_list;
            int count = maxY - minY + 1;
            do {
                for (Node* n = *list; n; n = n->next) {
                        RGE_Static_Object* obj = (RGE_Static_Object*)n->obj;
                        if (obj != this) {
                            MasterObj* om = obj->master_obj;
                            if (om->radius_z > 0.0) {
                                float rx = om->radius_x;
                                float ry = om->radius_y;
                                if (rx > 0.0f && ry > 0.0f) {
                                    float dz = obj->z - this->z;
                                    if (dz <= 0.0f || dz <= this->master_obj->radius_z) {
                                        if (dz >= 0.0f || dz >= -om->radius_z) {
                                            MasterObj* tm = this->master_obj;
                                            if (this->x < obj->x) {
                                                if ((obj->x - rx) -
                                                        (tm->radius_x + this->x) > extra)
                                                    continue;
                                            } else {
                                                if ((rx + obj->x) -
                                                        (this->x - tm->radius_x) < -extra)
                                                    continue;
                                            }
                                            if (this->y < obj->y) {
                                                if ((obj->y - ry) -
                                                        (tm->radius_y + this->y) > extra)
                                                    continue;
                                            } else {
                                                if ((ry + obj->y) -
                                                        (this->y - tm->radius_y) < -extra)
                                                    continue;
                                            }
                                            if (result == 0) {
                                                result = new RGE_Check_List;
                                            }
                                            result->add_node(obj, 0.0f, 0.0f, 0);
                                        }
                                    }
                                }
                    }
                }
                }
                list = (Node**)((char*)list + sizeof(Tile));
                --count;
            } while (count != 0);
        }
        }

    }
    return result;
}
