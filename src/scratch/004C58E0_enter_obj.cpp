// VA: 004C58E0 | RGE_Static_Object::enter_obj(RGE_Static_Object*) | stat_obj.cpp:2877-2901 | 118 bytes
//
// Attempt log:
// [1] VTableProxy approach. 5% diff. Two issues: RGE_Object_List is embedded not pointer;
//     register allocation for world_x/world_y copy.
// [2] Fix RGE_Tile to embed RGE_Object_List, fix register allocation.

#include "../../include/game_types.h"

#include "../../include/stat_obj_context.h"
#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
#define RGE_STAT_OBJ_SHARED_CONTEXT 1
#endif

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
struct ObjVTableProxy {
    virtual void _d00(); virtual void _d01(); virtual void _d02(); virtual void _d03();
    virtual void _d04(); virtual void _d05(); virtual void _d06(); virtual void _d07();
    virtual void _d08(); virtual void _d09(); virtual void _d10(); virtual void _d11();
    virtual void _d12(); virtual void _d13(); virtual void _d14(); virtual void _d15();
    virtual void _d16(); virtual void _d17(); virtual void _d18(); virtual void _d19();
    virtual void _d20(); virtual void _d21(); virtual void _d22(); virtual void _d23();
    virtual void _d24(); virtual void _d25(); virtual void _d26(); virtual void _d27();
    virtual void _d28(); virtual void _d29(); virtual void _d30(); virtual void _d31();
    virtual void _d32(); virtual void _d33(); virtual void _d34(); virtual void _d35();
    virtual void _d36(); virtual void _d37(); virtual void _d38(); virtual void _d39();
    virtual void _d40(); virtual void _d41(); virtual void _d42(); virtual void _d43();
    virtual void _d44(); virtual void _d45(); virtual void _d46(); virtual void _d47();
    virtual void _d48(); virtual void _d49(); virtual void _d50(); virtual void _d51();
    virtual void _d52();
    virtual void funcD4();
    virtual void _d54();
    virtual void funcDC(void* owner, int zero, int neg1);
};

class RGE_Object_List {
public:
    void remove_node(void* obj, void* node);
    void add_node(void* obj);
};

class RGE_Tile {
public:
    char _gap_00[0x0C];
    RGE_Object_List objects; // +0x0C (embedded, not a pointer)
};

class RGE_Static_Object {
public:
    void** vtable;
    char _gap_04[0x08];
    class RGE_Player* owner;
    char _gap_10[0x0C];
    RGE_Tile* tile;
    RGE_Static_Object* inside_obj;
    RGE_Object_List* objects;
    char _gap_28[0x10];
    float world_x;
    float world_y;

    unsigned char more_room();
    void enter_obj(RGE_Static_Object* target);
    void removeFromObstructionMap(int state);
};
#endif

void RGE_Static_Object::enter_obj(RGE_Static_Object* target) {
    if (!target->more_room()) {
        return;
    }

    if (inside_obj != 0) {
        inside_obj->exit_obj();
    }

    if (tile != 0) {
        this->unexplore_terrain(owner, 0, -1);

        tile->objects.remove_node(this, 0);
        tile = 0;
    }

    removeFromObstructionMap(2);
    target->objects->add_node(this);
    inside_obj = target;
    world_x = target->world_x;
    world_y = target->world_y;
}
