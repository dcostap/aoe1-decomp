// VA: 004C5F00 distance_to_position (152B)
// stat_obj.cpp

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap4[0x34];
    float field_38;
    float field_3C;
    
    float distance_to_position(float x, float y);
};

float RGE_Static_Object::distance_to_position(float x, float y) {
    float dx = x - field_38;
    float dy = y - field_3C;
    
    if (dx < 0.0f) dx = -dx;
    if (dy < 0.0f) dy = -dy;
    
    return dx + dy;
}
