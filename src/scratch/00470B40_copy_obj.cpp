// player.cpp:1636-1648, 105 bytes
// attempt 1: cast-based vf calls -> 80 bytes (25 short)
// attempt 2: typed pointers + separate guards + goto -> 80 bytes
// attempt 3: do-while + goto -> 80 bytes
// attempt 4: combined guard (src||dest) + while -> 80 bytes
// attempt 5: int params instead of short -> 80 bytes
// BLOCKER: VC5 always emits 80 bytes. Original uses verbose two-null-guard + do-while loop
//   with esi pushed inside the block (not prolog). VC5 combines guards and uses compact while-loop.
//   25 bytes short = codegen-family gap.
class RGE_Static_Object;

class RGE_Master_Static_Object {
public:
    virtual void vf00();
    virtual void vf04(RGE_Master_Static_Object*);
};

class RGE_Object_Node {
public:
    RGE_Static_Object* obj;
    RGE_Object_Node* next;
};

class RGE_Static_Object {
public:
    char gap_00[8];
    RGE_Master_Static_Object* master;
    char gap_0C[0x58 - 0x0C];
    virtual void vf58(RGE_Master_Static_Object*);
};

class RGE_Object_List {
public:
    char gap_00[4];
    RGE_Object_Node* list;
};

class RGE_Player {
public:
    char gap_00[0x24];
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;

    void copy_obj(short srcIndex, short destIndex);
};

void RGE_Player::copy_obj(short srcIndex, short destIndex) {
    RGE_Master_Static_Object* srcMaster = this->master_objects[srcIndex];
    RGE_Master_Static_Object* destMaster = this->master_objects[destIndex];
    if (srcMaster == 0 || destMaster == 0) {
        return;
    }
    RGE_Object_List* objList = this->objects;
    if (objList != 0) {
        RGE_Object_Node* node = objList->list;
        while (node != 0) {
            RGE_Static_Object* obj = node->obj;
            if (obj->master == srcMaster) {
                obj->vf58(destMaster);
            }
            node = node->next;
        }
    }
    srcMaster->vf04(destMaster);
}
