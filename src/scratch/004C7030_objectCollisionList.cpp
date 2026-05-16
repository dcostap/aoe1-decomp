// VA: 004C7030 RGE_Static_Object::objectCollisionList
// Attempt log:
// 1: direct reconstruction from packet/decompiler; /GX likely required for EH around new RGE_Check_List.
// 2: fixed MasterObj offsets to radius_x +30, radius_y +34, radius_z +38 and owner->map +3c after dump showed initial field checks shifted.
// 3: tried parenthesized condition shape, reversed 0.0f compare spelling, delayed result initialization, and manual operator-new/placement-construction spelling; no size/topology improvement (or compile failure for placement new under local context).
// left in scratch: honest source compiles 768B vs original 776B (with /GX); early EH/prologue present but frame is 0x28 vs original 0x2c, initial radius-test FPU stack choreography differs, and broad loop/FPU topology remains. Not accepted_drift-safe.

struct MasterObj { char gap28[0x30]; float radius_x; float radius_y; float radius_z; };
struct Map { char gap0[8]; int width; int height; char gap10[0x8d7c]; void** rows; };
struct Owner { char gap0[0x3c]; Map* map; };
struct Node { void* obj; Node* next; };
struct RGE_Check_List { RGE_Check_List(); void add_node(void*, float, float, unsigned char); };

class RGE_Static_Object {
public:
    char gap0[8];
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
    RGE_Check_List* result = 0;
    MasterObj* mo = this->master_obj;
    if (mo->radius_x > 0.0f && mo->radius_y > 0.0f && mo->radius_z > 0.0f) {
        Map* map = this->owner->map;
        int minY = (int)this->x - 3;
        int maxY = (int)this->x + 3;
        int minX = (int)this->y - 3;
        int maxX = (int)this->y + 3;
        if (minY < 0) minY = 0;
        if (maxY >= map->width) maxY = map->width - 1;
        if (minX < 0) minX = 0;
        if (maxX >= map->height) maxX = map->height - 1;
        for (int yy = minX; yy <= maxX; ++yy) {
            if (minY <= maxY) {
                Node** cell = (Node**)((char*)map->rows[yy] + minY * 24 + 0x10);
                int count = maxY - minY + 1;
                do {
                    for (Node* n = *cell; n; n = n->next) {
                        RGE_Static_Object* obj = (RGE_Static_Object*)n->obj;
                        if (obj != this) {
                            MasterObj* om = obj->master_obj;
                            if (om->radius_z > 0.0f) {
                                float rx = om->radius_x;
                                float ry = om->radius_y;
                                if (rx > 0.0f && ry > 0.0f) {
                                    float dz = obj->z - this->z;
                                    if ((dz <= 0.0f || dz <= this->master_obj->radius_z) && (dz >= 0.0f || -om->radius_z <= dz)) {
                                        MasterObj* tm = this->master_obj;
                                        if (obj->x <= this->x) {
                                            if (!(-extra <= (rx + obj->x) - (this->x - tm->radius_x))) goto skip;
                                        } else {
                                            if (!((obj->x - rx) - (tm->radius_x + this->x) <= extra)) goto skip;
                                        }
                                        if (obj->y <= this->y) {
                                            if (!(-extra <= (ry + obj->y) - (this->y - tm->radius_y))) goto skip;
                                        } else {
                                            if (!((obj->y - ry) - (tm->radius_y + this->y) <= extra)) goto skip;
                                        }
                                        if (result == 0) {
                                            RGE_Check_List* p = new RGE_Check_List;
                                            result = p;
                                        }
                                        result->add_node(obj, 0.0f, 0.0f, 0);
                                    }
                                }
                            }
                        }
skip:;
                    }
                    cell = (Node**)((char*)cell + 0x18);
                    --count;
                } while (count != 0);
            }
        }
    }
    return result;
}
