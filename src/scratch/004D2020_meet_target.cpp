// VA: 004D2020 TRIBE_Action_Repair::meet_target (388 B)
// PDB source: tact_rep.cpp
// LEFT IN SCRATCH after 12+ attempts.
//
// Issues:
// 1. Virtual calls at vt+0xCC (idx 51), +0x134 (idx 77), +0x154 (idx 85), +0x1B4 (idx 109)
//    require 110+ virtual method declarations. All approaches (pure virtual, outline defs,
//    inline bodies) produce extra code that shifts meet_target out of the expected .text range.
//    The VT110 helper struct works but generates vtable + stub code bloat.
// 2. get_action (00404840), targetX (00407D30), targetY (00407D40) use __thiscall.
//    extern "C" declarations default to __cdecl, producing wrong push/pop sequences.
//    Member function pointer approaches require struct definitions that don't match real layouts.
// 3. Class layout with vtable pointer: TRIBE_Action_Repair extends RGE_Action which has a vtable.
//    Standalone class with no virtuals doesn't add vtable slot, shifting all offsets by 4.
//    Adding VBase with virtual dummy() fixes offsets but changes class identity.
//
// Partial successes: type check at entry, linked list traversal, ftol pattern, field offsets
// all modeled correctly. Control flow logic is sound.

struct RGE_Action_Node {
    void* action;
    RGE_Action_Node* next;
};

struct VBase {
    virtual void dummy() {}
};

// Class layout matching RGE_Action(0x40) + TRIBE_Action_Repair fields (total 0x44)
class TRIBE_Action_Repair : public VBase {
public:
    // RGE_Action base fields
    char gap_04[4];              // +0x04: action_type(short) + pad(2)
    void* obj;                   // +0x08: RGE_Action_Object*
    unsigned char state;         // +0x0C
    char pad_0D[3];              // +0x0D
    void* target_obj;            // +0x10: RGE_Static_Object*
    char pad_14[0x0C];           // +0x14: target_obj2, targetID, target2ID
    float target_x;              // +0x20
    float target_y;              // +0x24
    float target_z;              // +0x28
    char pad_2C[8];              // +0x2C: timer(4) + gap to 0x34
    void* sub_actions;           // +0x34
    char pad_38[4];              // +0x38: sprite? gap to 0x3C
    void* sprite;                // +0x3C
    char pad_40[4];              // +0x40: subActionValue(1) + pad(3)
    unsigned char save_flag;     // +0x44: save_target_command_flag

    void meet_target();
};

// Key extern functions (__thiscall) at known addresses:
// 00404840: void* RGE_Action_Object::get_action() - returns *this->action_ptr
// 00407D30: float RGE_Action::targetX() - returns this->target_x
// 00407D40: float RGE_Action::targetY() - returns this->target_y
extern "C" void* get_action(void*);
extern "C" float targetX(void*);
extern "C" float targetY(void*);

void TRIBE_Action_Repair::meet_target() {
    void* target = this->target_obj;

    // Check target type
    short targetType = *(short*)((char*)*(void**)((char*)target + 8) + 0x14);
    if (targetType != 2 && targetType != 0x14 && targetType != 0x15 && targetType != 0x16)
        return;

    // Walk action list via linked list nodes
    int** p1 = (int**)((char*)this->obj + 0x0C);
    int** p2 = (int**)((char*)*p1 + 0x28);
    RGE_Action_Node* node = *(RGE_Action_Node**)((char*)*p2 + 4);

    while (node) {
        void* act = node->action;
        node = node->next;

        if (act == this->obj)
            continue;

        short t = *(short*)((char*)*(void**)((char*)act + 8) + 0x10);
        if (t != 0x9C)
            continue;

        // TODO: virtual call at vt+0xCC (index 51) - needs 110+ vfunc declarations
        // TODO: virtual call at vt+0x134 (index 77) - needs 110+ vfunc declarations
        // TODO: virtual call at vt+0x1B4 (index 109) - needs 110+ vfunc declarations
        // TODO: virtual call at vt+0x154 (index 85) - needs 110+ vfunc declarations
        // TODO: extern __thiscall calls need proper calling convention

        break; // Placeholder: logic incomplete due to vtbl dispatch limitations
    }

    // TODO: implement main path with ftol and position computation
}
