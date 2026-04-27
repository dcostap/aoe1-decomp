// VA: 004CCDF0 TRIBE_Action_Artifact::update
// tact_art.cpp lines 120-164

// attempt 1: natural C++ with vtable helper classes → 199/199 size match!
// attempt 2: dummy virtuals for slot positions → vf23 at slot 23 confirmed
// attempt 3: class layout fix (action_type + gaps for correct field offsets)
// attempt 4: member-style delete_list (thiscall) + fixed pointer arithmetic
// 
// Status: SCRATCH. 199/199 bytes exact size. 122 diff bytes.
// Remaining issues:
//   - je vs jbe at offset 14 (cosmetic branch encoding)
//   - VC5 not generating jump table data section for switch dispatch
//   - Different register allocation throughout
//   - Float compare generates fcom dword vs original fcom qword
// Left in scratch: codegen-basin differences, not logic errors.

#include <stddef.h>

class RGE_Action_List {
public:
    virtual ~RGE_Action_List();
    virtual void vf01();
    virtual void vf02();
    virtual unsigned char vf03();  // slot 3 (0x0C)
    void delete_list();
};

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17(void* arg);  // slot 17 (0x44)
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    unsigned short action_type;
    char gap_06[2];
};

class TRIBE_Action_Artifact : public RGE_Action {
public:
    RGE_Action_Object* object;     // +0x08
    unsigned char state;            // +0x0C
    char gap_10[3];                 // padding
    void* target_info;              // +0x10
    char gap_14[0x0C];              // +0x14 to +0x1F
    float target_x;                 // +0x20
    float target_y;                 // +0x24
    float target_z;                 // +0x28
    float timer;                    // +0x2C
    void* sprite;                   // +0x30
    RGE_Action_List* action_list;   // +0x34

    // Virtuals to push to slot 23
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23(int arg);     // slot 23 (0x5C)

    void* check_ownership();
    unsigned char update();
};

unsigned char TRIBE_Action_Artifact::update() {
    unsigned char val = action_list->vf03();
    if (val != 0 && val <= 3) {
        action_list->delete_list();
    }
    switch (state) {
    case 1:
        return 1;
    case 6: {
        void* owner = check_ownership();
        if (owner != 0) {
            action_list->delete_list();
            object->vf17(owner);
            return 0;
        }
        this->vf23(10);
        return 0;
    }
    case 10: {
        float speed = timer - *(float*)(*(int*)(*(int*)((char*)object + 0xC) + 0x3C) + 0x84);
        timer = speed;
        if (speed > 0.0f) {
            return 0;
        }
        this->vf23(6);
        return 0;
    }
    case 100:
        object->vf17(*(void**)(*(int*)(*(int*)((char*)object + 0xC) + 0x3C) + 0x40));
        this->vf23(6);
        return 0;
    default:
        return 0;
    }
}
