// VA: 004C5E50 distance_to_object (167B)
// stat_obj.cpp

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap4[0x34];
    float field_38;
    float field_3C;
    char gap40[0x44];
    float field_7C;
    
    float distance_to_object(RGE_Static_Object* other);
};

extern float zero_float;

float RGE_Static_Object::distance_to_object(RGE_Static_Object* other) {
    float dx = other->field_38 - field_38;
    float dy = other->field_3C - field_3C;
    
    if (dx < 0.0f) dx = -dx;
    if (dy < 0.0f) dy = -dy;
    
    return dx + dy;
}
