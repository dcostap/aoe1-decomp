// VA: 00460900 RGE_Moving_Object::waitingToMove
// The canonical RGE_Moving_Object declaration and named movement-state
// methods live in include/move_obj_context.h.

unsigned char RGE_Moving_Object::waitingToMove(void) const {
    unsigned int state = (unsigned char)this->movement_state();

    if ((state == 6) || (state == 7)) {
        return 0;
    }
    return this->waitingToMoveValue;
}
