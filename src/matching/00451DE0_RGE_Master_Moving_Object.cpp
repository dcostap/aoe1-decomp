#ifndef RGE_MO_OBJ_SHARED_CONTEXT
class Base_RGE_Master_Moving_Object {
public:
    virtual ~Base_RGE_Master_Moving_Object();
};

class RGE_Master_Moving_Object : public Base_RGE_Master_Moving_Object {
public:
    virtual ~RGE_Master_Moving_Object();
};
#endif

RGE_Master_Moving_Object::~RGE_Master_Moving_Object() {
}
