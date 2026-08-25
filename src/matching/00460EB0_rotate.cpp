// VA: 00460EB0 RGE_Moving_Object::rotate(int)
// The canonical RGE_Moving_Object and RGE_Sprite layouts live in
// include/move_obj_context.h. new_angle is the inherited slot at +0xB4.
// The natural source remains the reduced standalone form.

void RGE_Moving_Object::rotate(int angleDeg) {
    void* obj;
    float rotation;

    obj = this->sprite;
    rotation = (float)(((double)angleDeg * 6.283185307179586) / (double)*(short*)((char*)obj + 0x60)) + this->angle;

    if (rotation < 0.0f) {
        do {
            rotation += 6.283185f;
        } while (rotation < 0.0f);
    }
    if (rotation >= 6.283185307179586) {
        do {
            rotation -= 6.283185f;
        } while (rotation >= 6.283185307179586);
    }

    this->new_angle(rotation);
}
