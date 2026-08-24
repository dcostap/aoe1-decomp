#ifndef RGE_MAN_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    void copy_obj(RGE_Master_Static_Object* object);
    char gap_00[0xB8];
    float speed;
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    void copy_obj(RGE_Master_Static_Object* object);
};
#endif

void RGE_Master_Animated_Object::copy_obj(RGE_Master_Static_Object* object) {
    RGE_Master_Static_Object::copy_obj(object);
#ifdef RGE_MAN_OBJ_SHARED_CONTEXT
    this->speed = ((RGE_Master_Animated_Object*)object)->speed;
#else
    this->speed = object->speed;
#endif
}
