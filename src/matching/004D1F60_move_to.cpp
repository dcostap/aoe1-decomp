// 004D1F60 TRIBE_Action_Repair::move_to
// Source: tact_rep.cpp lines 457-464. 51 bytes. __thiscall, ret 10h.
//
// MATCHED. Exact 51-byte match confirmed via local check_function.py.
// Lesson from ZephyrStone (sibling 004CD920): assign move_x = x BEFORE move_y = y.
// The original source code at tact_rep.cpp:461 writes x first, then y, then z.
// This naturally reads x and z before push esi (at [esp+8]/[esp+10h]) and
// reads y after push esi (at [esp+10h]), matching the original EXE.

class TRIBE_Action_Repair {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void reset_target(int value);
    virtual void vf58(void);
    virtual int set_state(int value);

    char gap_04[0x1C];
    float move_x;
    float move_y;
    float move_z;

    int move_to(void* obj, float x, float y, float z);
};

int TRIBE_Action_Repair::move_to(void* obj, float x, float y, float z) {
    this->move_x = x;
    this->move_y = y;
    this->move_z = z;
    this->reset_target(0);
    this->set_state(0x0B);
    return 1;
}
