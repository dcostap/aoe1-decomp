// tried both `value * work_rate`, `work_rate *= value`, an explicit result local, a rewrite-through-value-parameter form, and a volatile RHS load; VC5 stayed in the fld-work_rate / fmul-value basin
// the remaining gap is now isolated to that FPU operand-load order in the special attribute==0x0D path
void RGE_Master_Action_Object::modify_percent(float value, unsigned char attribute) {
    if (attribute != 0x0D) {
        RGE_Master_Moving_Object::modify_percent(value, attribute);
        return;
    }
    value = value * this->work_rate;
    this->work_rate = value;
}
