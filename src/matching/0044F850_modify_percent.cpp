// BINARY NOTE: Attribute 0x0D multiplies work_rate. Other attributes use the
// inherited action-object path.
void RGE_Master_Action_Object::modify_percent(float value, unsigned char attribute) {
    if (attribute != 0x0D) {
        RGE_Master_Moving_Object::modify_percent(value, attribute);
        return;
    }
    value = value * this->work_rate;
    this->work_rate = value;
}
