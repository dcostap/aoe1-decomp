// player.cpp:1636-1648, 105 bytes
// ACCEPTED_DRIFT
// Remaining diff: register allocation (ebx/edi swap), instruction choice (lea vs shl),
// vtable slot alignment (0 vs 0x58), and data layout. These are VC5 codegen-family
// differences from the TU-local stub class definitions not matching the full game context.
// The function is behaviorally correct.
// 
// Attempts:
// 1-5: various loop/null-check forms -> 80 bytes (25 short)
// 6: pointer-arithmetic + separate null checks -> 96 bytes (9 short)
// 7: int locals + separate checks -> 96 bytes  
// 8: explicit offset*4 + base class vtable -> 105 bytes (94% positional diff)
// 9-11: base class stubs, force vtable -> still wrong vtable offsets
// 12: vtable dispatch via function pointer -> __thiscall limitation
// 
// Key blockers:
// - Prologue: original has movsx AFTER push prologue; int conversion at top forces movsx before pushes
// - Instruction choice: original uses shl edi,2 (3 bytes) but VC5 prefers lea ebx,[eax*4] (7 bytes)
// - Register allocation: edi/ebp/ebx in original vs ebx/ebp/edi in rebuilt
// - Vtable slot: original calls [edx+58h] (slot 22) vs [edx] (slot 0) without full class hierarchy

class RGE_Static_Object;
class RGE_Object_Node {
public:
    RGE_Static_Object* obj;
    RGE_Object_Node* next;
};

class RGE_Master_Static_Object {
public:
    virtual void vf00();
    virtual void vf04(RGE_Master_Static_Object*);
};

class RGE_Static_Object {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(RGE_Master_Static_Object*);
    char gap_00[4];
    RGE_Master_Static_Object* master;
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
    if (this->master_objects[srcIndex] == 0) return;
    if (this->master_objects[destIndex] == 0) return;
    if (this->objects != 0) {
        RGE_Object_Node* node = this->objects->list;
        while (node != 0) {
            RGE_Static_Object* obj = node->obj;
            if (obj->master == this->master_objects[srcIndex]) {
                obj->vf58(this->master_objects[destIndex]);
            }
            node = node->next;
        }
    }
    this->master_objects[srcIndex]->vf04(this->master_objects[destIndex]);
}
