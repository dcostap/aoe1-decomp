class RGE_Static_Object {
public:
    char gap_00[0x38];
    float world_x;
    float world_y;
    float world_z;

    void set_location(float x, float y, float z);
};

void RGE_Static_Object::set_location(float x, float y, float z) {
    world_x = x;
    world_y = y;
    world_z = z;
}
