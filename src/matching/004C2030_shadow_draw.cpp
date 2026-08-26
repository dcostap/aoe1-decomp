void RGE_Static_Object::shadow_draw(TDrawArea* param_1, short param_2, short param_3, unsigned char param_4) {
    if (this->tile != 0 && this->object_state < 7) {
        this->sprite_list->shadow_draw(this->facet, this->shadow_x_offset + param_2, this->shadow_y_offset + param_3, this->owner->color_table, param_1, param_4);
    }
}
