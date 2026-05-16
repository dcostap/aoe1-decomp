// VA: 0045AB20 RGE_Missile_Object::make_object_collision_list
// PDB source: misl_obj.cpp lines 148-236
// attempt log:
// 1: natural decompiler-shaped C++ with /GX likely needed for new/delete EH.
// 2: explicit operator_new + placement ctor was too small (736B) and lacked EH cleanup.
// 3: C++ new/delete with /GX gives 800B vs original 802B; extraction stops before diff, likely close EH/source-shape but still short.
// 4: reversed initial radius check order; no size change.
// 5: flag probes: /O2 /GX no /Oy still 800B; /O1 /GX 678B; /Od /GX reaches 802B but broad mismatch from offset 0, rolled back.
// FLAGS: config/flags/0045AB20_make_object_collision_list.rsp (/nologo /c /O2 /Oy /GX)
// left in scratch: needs exact misl_obj.cpp EH/new source shape; current best is 2 bytes short with plausible behavior.

typedef unsigned char uchar;

class RGE_Static_Object;
class RGE_Check_List {
public:
    void* list;
    RGE_Check_List();
    ~RGE_Check_List();
    void add_node(RGE_Static_Object* obj, float a, float b, int flag);
};
void* operator_new(unsigned int size);
void operator_delete(void* p);
inline void* operator new(unsigned int, void* p) { return p; }

struct RGE_Master_Static_Object { char gap0[0x30]; float radius_x; float radius_y; float radius_z; };
struct RGE_Tile { char gap0[0x10]; void* objects; };
struct RGE_Map { char gap0[8]; int width; int height; char gap10[0x8D8C-0x10]; RGE_Tile** rows; };
class RGE_Missile_Object {
public:
    char gap00[8];
    RGE_Master_Static_Object* master; // +8
    RGE_Map* map; // +c
    char gap10[0x28];
    float x; float y; float z; // +38 +3c +40
    RGE_Check_List* make_object_collision_list(float extra);
};
struct ObjNode { RGE_Static_Object* obj; ObjNode* next; };
class RGE_Static_Object { public: char gap00[8]; RGE_Master_Static_Object* master; char gap0c[0x2c]; float x; float y; float z; };

RGE_Check_List* RGE_Missile_Object::make_object_collision_list(float extra) {
    float dx = this->master->radius_x;
    float dy = this->master->radius_y;
    if (dy <= 0.0f || dx <= 0.0f) return 0;
    short y0 = (short)(int)(this->x - 0.5f);
    short x0 = (short)(int)(this->y - 0.5f);
    short y1 = (short)(int)(this->x - 1.5f);
    short x1 = (short)(int)(this->y - 1.5f);
    RGE_Map* map = this->map;
    RGE_Check_List* list = new RGE_Check_List;

    if (y0 < 0) y0 = 0;
    if ((int)y1 >= map->width) y1 = (short)(map->width - 1);
    if (x0 < 0) x0 = 0;
    if ((int)x1 >= map->height) x1 = (short)(map->height - 1);

    if (x0 <= x1) {
        short row = x0;
        int rowCount = (int)x1 - (int)x0 + 1;
        int rowOff = (int)x0 * 4;
        do {
            RGE_Tile* tile = map->rows[rowOff/4] + y0;
            if (y0 <= y1) {
                int colCount = (int)y1 - (int)y0 + 1;
                do {
                    ObjNode* node = (ObjNode*)tile->objects;
                    while (node != 0) {
                        RGE_Static_Object* obj = node->obj;
                        if (obj != (RGE_Static_Object*)this) {
                            RGE_Master_Static_Object* m = obj->master;
                            if (m->radius_y > 0.0f && m->radius_x > 0.0f) {
                                float dz = obj->z - this->z;
                                if (-(m->radius_z + 0.1f) <= dz && dz <= this->master->radius_z + 0.1f) {
                                    float rx = obj->x - this->x;
                                    float ry = obj->y - this->y;
                                    if (rx < 0.0f) rx = -rx;
                                    if (ry < 0.0f) ry = -ry;
                                    rx = rx - (m->radius_x + dx + extra);
                                    ry = ry - (m->radius_y + dy + extra);
                                    if (rx <= 0.0f && ry <= 0.0f) list->add_node(obj, rx, ry, 0);
                                }
                            }
                        }
                        node = node->next;
                    }
                    tile++;
                    colCount--;
                } while (colCount != 0);
            }
            rowOff += 4;
            rowCount--;
        } while (rowCount != 0);
    }
    if (list->list == 0) {
        delete list;
        list = 0;
    }
    return list;
}
