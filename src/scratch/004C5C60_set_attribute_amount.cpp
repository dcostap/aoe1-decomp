// VA: 004C5C60 RGE_Static_Object::set_attribute_amount (71B)
// PDB source: stat_obj.cpp lines 3151-3159
// tried direct add/assign forms and clamp-local variants
// best result is 68/71 bytes equal: only remaining drift is the add-path FPU operand order (`fld current; fadd amount`) while the original wants `fld amount; fadd current`; the rest of the store/jump/clamp sequence matches

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
        this->attribute_amount_held = amount + this->attribute_amount_held;
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
