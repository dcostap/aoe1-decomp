#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Static_Object {
public:
    char gap_00[0x44];
    float attribute_amount_held;
    char gap_48[0x04];
    short attribute_type_held;

    void set_attribute(short param1, float param2);
};

#endif

void RGE_Static_Object::set_attribute(short param1, float param2) {
    attribute_type_held = param1;
    attribute_amount_held = param2;
}
