class RGE_Master_Static_Object {
public:
    char gap_00[0x7C];
    short attribute_max_amount;
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    char gap_04[0x4];
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x38];
    float attribute_amount_held;

    void set_attribute_amount(float amount, unsigned char add, unsigned char clamp);
};

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
