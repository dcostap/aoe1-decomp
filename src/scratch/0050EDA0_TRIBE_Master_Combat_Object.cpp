#ifndef TM_CO_OB_SHARED_CONTEXT
class Base_TRIBE_Master_Combat_Object {
public:
    virtual ~Base_TRIBE_Master_Combat_Object();
};

class TRIBE_Master_Combat_Object : public Base_TRIBE_Master_Combat_Object {
public:
    virtual ~TRIBE_Master_Combat_Object();
};
#endif

TRIBE_Master_Combat_Object::~TRIBE_Master_Combat_Object() {
}
