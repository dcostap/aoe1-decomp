// VA: 0045AB20 RGE_Missile_Object::make_object_collision_list
// PDB source: misl_obj.cpp
// Attempt log:
// - 802 bytes, 43 line changes over 88 source lines — very complex
// - Creates a collision list for missile objects
// - Left in scratch as stub

struct RGE_Missile_Object_collision {
    char base[0x1C8];
    float max_range;
    void* make_object_collision_list(float p1);
};

void* RGE_Missile_Object_collision::make_object_collision_list(float p1)
{
    return 0;
}
