// VA: 004CCCB0 TRIBE_Action_Artifact::set_state
// tact_art.cpp lines 78-116

// attempt 1: natural C++ with 'new' expression + ctor, /GX flag
// Size: 304/312 bytes (8 short) - close but codegen doesn't match exactly
// Remaining issues:
//   - 8 bytes short (likely EH scope table alignment/padding)
//   - Switch dispatch uses if-else chain vs original's sub/dec/sub pattern
//   - Block layout differs for new+ctor tail (may be non-tail-merged vs original)
// Left in scratch: close but codegen basin not found.

class RGE_Action_List {
public:
    virtual ~RGE_Action_List();
    virtual void vf01();
    virtual void vf02();
    virtual unsigned char vf03();
    void delete_list();
    void add_action(void* action);
};

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    unsigned short action_type;
    char gap_06[2];
};

class RGE_Action_Move_To {
public:
    char gap_00[0x44];
    RGE_Action_Move_To(RGE_Action_Object* obj, float x, float y, float z, float speed, void* sprite_val);
};

class TRIBE_Action_Artifact : public RGE_Action {
public:
    RGE_Action_Object* object;     // +0x08
    unsigned char state;            // +0x0C
    char gap_10[3];
    void* target_info;              // +0x10
    char gap_14[0x0C];
    float target_x;                 // +0x20
    float target_y;                 // +0x24
    float target_z;                 // +0x28
    float timer;                    // +0x2C
    void* sprite;                   // +0x30
    RGE_Action_List* action_list;   // +0x34

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

    void set_state(unsigned char new_state);
};

void TRIBE_Action_Artifact::set_state(unsigned char new_state) {
    this->state = new_state;
    if (new_state == 4) {
        action_list->delete_list();
        RGE_Action_Move_To* move = new RGE_Action_Move_To(object, target_x, target_y, target_z, 0.0f,
            (void*)*(int*)((char*)sprite + 0x34));
        if (move != 0) {
            action_list->add_action(move);
            this->vf23(6);
        }
    } else if (new_state == 5) {
        action_list->delete_list();
        void* src = target_info;
        target_x = *(float*)((char*)src + 0x38);
        target_y = *(float*)((char*)src + 0x3C);
        target_z = *(float*)((char*)src + 0x40);
        target_info = 0;
        RGE_Action_Move_To* move = new RGE_Action_Move_To(object, target_x, target_y, target_z, 0.0f,
            (void*)*(int*)((char*)sprite + 0x34));
        if (move != 0) {
            action_list->add_action(move);
            this->vf23(6);
        }
    } else if (new_state == 10) {
        timer = 3.0f;
        return;
    }
}
