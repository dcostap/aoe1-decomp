void RGE_Static_Object::get_starting_attribute()
{
    RGE_Master_Static_Object* master;
    unsigned char* attr_flag;
    short* attr_type;
    float* attr_amount;
    int count;

    master = this->master_obj;
    this->attribute_type_held = -1;
    this->attribute_amount_held = 0;
    attr_flag = master->attribute_flag;
    attr_amount = master->attribute_amount_held;
    attr_type = master->attribute_type_held;
    count = 3;
    do {
        if (*attr_flag == 0 && *attr_type != -1) {
            this->attribute_type_held = *attr_type;
            this->attribute_amount_held = *attr_amount;
        }
        attr_type++;
        attr_amount++;
        attr_flag++;
        count--;
    } while (count != 0);
}
