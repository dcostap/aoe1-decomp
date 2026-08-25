// 0044F0F0 RGE_Master_Action_Object::RGE_Master_Action_Object(int, RGE_Sprite**, RGE_Sound**, int)
// Source: m_ac_obj.cpp lines 38-41
// Size: 109 bytes, 39 asm lines
// Attempt 15: setup() defined externally (not in this TU). The constructor
// .text COMDAT should be the first code section emitted, so the checker
// extracts it correctly from the concatenated .text.

RGE_Master_Action_Object::RGE_Master_Action_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : RGE_Master_Moving_Object(param_1, param_2, param_3, 0) {
    if (param_4 != 0) {
        setup(param_1, param_2, param_3);
    }
}
