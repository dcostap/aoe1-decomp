// VA: 0044F820 modify_delta (41B, m_ac_obj.cpp)
// Modifies an attribute by a delta value. If attribute is 0x0D (work_rate),
// adds value directly to field_0xE4. Otherwise delegates to base class.
//
// Attempt log:
// - Correct branch condition and FPU order differ from original
// - Original: je→fadd (branch to IF block); call_other as fall-through
// - Rebuilt:  jne→call_other (branch to ELSE block); fadd as fall-through
// - VC5 inverts condition when shorter block can be fall-through
// - Using `if (attr != 0x0D) { call_other } else { fadd }` 
//   still puts fadd as fall-through (inverted from original)
// - Can't prevent VC5 from inverting; likely flags/codegen-version dependent

class RGE_Master_Moving_Object {
public:
    virtual void modify_delta(float value, unsigned char attribute);
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_04[0xE0];
    float work_rate; // +0xE4

    void modify_delta(float value, unsigned char attribute);
};

void RGE_Master_Action_Object::modify_delta(float value, unsigned char attribute) {
    if (attribute != 0x0D) {
        RGE_Master_Moving_Object::modify_delta(value, attribute);
    } else {
        this->work_rate = value + this->work_rate;
    }
}
