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

void RGE_Master_Animated_Object::copy_obj(RGE_Master_Static_Object* object) {
    RGE_Master_Static_Object::copy_obj(object);
    this->speed = object->speed;
}
