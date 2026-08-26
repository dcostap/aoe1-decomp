void RGE_Static_Object::set_attribute_amount(float amount, unsigned char add, unsigned char clamp)
{
    if (add != 0) {
        this->attribute_amount_held = *(volatile float*)&amount + this->attribute_amount_held;
    }
    else {
        this->attribute_amount_held = amount;
    }

    if (clamp != 0) {
        if ((float)(int)this->master_obj->attribute_max_amount < this->attribute_amount_held) {
            this->attribute_amount_held = (float)(int)this->master_obj->attribute_max_amount;
        }
    }
}
