class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
};

// The shipped body is a direct thunk to RGE_Static_Object::~RGE_Static_Object.
class __declspec(novtable) RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Animated_Object();
};

RGE_Animated_Object::~RGE_Animated_Object() {}
