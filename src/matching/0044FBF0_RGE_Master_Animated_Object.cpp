class Base_RGE_Master_Animated_Object {
public:
    virtual ~Base_RGE_Master_Animated_Object();
};

class RGE_Master_Animated_Object : public Base_RGE_Master_Animated_Object {
public:
    virtual ~RGE_Master_Animated_Object();
};

RGE_Master_Animated_Object::~RGE_Master_Animated_Object() {
}
