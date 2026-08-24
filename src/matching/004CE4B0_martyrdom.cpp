// VA: 004CE4B0 TRIBE_Action_Convert::martyrdom
// Source policy recovery: use the shared typed action hierarchy and named
// virtual methods.  The prior raw offset and fake-slot probe is not retained.

void TRIBE_Action_Convert::martyrdom()
{
    if (this->state != 7) {
        return;
    }
    if (this->target_obj == 0) {
        return;
    }
    if (this->target_obj->master_obj->object_group == 0x12) {
        return;
    }

    int target_id = this->target_obj->owner->id;
    int source_id = this->obj->owner->id;

    rge_base_game->notification(0x7B, source_id, target_id, 0, 0);
    this->target_obj->change_ownership(this->obj->owner);
    this->obj->owner->add_attribute_num(0x29, 1.0f, 0);
    this->obj->set_attribute(0x22, 0);
    this->set_state(3);
}
