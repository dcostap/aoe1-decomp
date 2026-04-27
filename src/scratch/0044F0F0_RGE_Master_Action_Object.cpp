// m_ac_obj.cpp:38-41, 109 bytes
// attempt 1: 64 bytes, too small
// attempt 2: 64 bytes, still too small
// attempt 3: compile error, no default ctor
// attempt 4: no .text section, ctor inlined
// attempt 5: compile error, duplicate ctor
// attempt 6: 109 bytes but 67.9% diff, wrong layout
// attempt 7: 96 bytes without virt dtor
// attempt 8: 64 bytes, not a ctor
// attempt 9: 109 bytes but 75.2%, new expr
// attempt 10: 67.0%, still EH at offset (0044F140 not 0044F0F0)
// BEST: 67.0%. BLOCKER: VC5 emits vptr=0 fast path at entry
//   while original has EH frame at entry. Codegen basin mismatch
//   for constructor with base ctor call + conditional setup call.
//   /GX rsp needed. Core logic (base ctor, conditional setup,
//   vptr store) all correct.
class RGE_Sprite;
class RGE_Sound;

class RGE_Master_Moving_Object {
public:
    virtual void vf00() {}
    virtual ~RGE_Master_Moving_Object() {}
    RGE_Master_Moving_Object(int, RGE_Sprite**, RGE_Sound**, int);
};

RGE_Master_Moving_Object::RGE_Master_Moving_Object(int, RGE_Sprite**, RGE_Sound**, int) {}

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    void setup(int, RGE_Sprite**, RGE_Sound**);
    void* member_ptr;

    RGE_Master_Action_Object(int, RGE_Sprite**, RGE_Sound**, int);
};

void RGE_Master_Action_Object::setup(int, RGE_Sprite**, RGE_Sound**) {}

RGE_Master_Action_Object::RGE_Master_Action_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : RGE_Master_Moving_Object(param_1, param_2, param_3, 0), member_ptr(0) {
    if (param_4 != 0) {
        setup(param_1, param_2, param_3);
    }
}
