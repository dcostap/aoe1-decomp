class RGE_Master_Static_Object;

class RGE_Static_Object {
public:
    void transform(RGE_Master_Static_Object* master);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    void transform(RGE_Master_Static_Object* master);
};

void RGE_Animated_Object::transform(RGE_Master_Static_Object* master) {
    RGE_Static_Object::transform(master);
}
