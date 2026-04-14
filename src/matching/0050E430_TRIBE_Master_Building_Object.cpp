class Base_TRIBE_Master_Building_Object {
public:
    virtual ~Base_TRIBE_Master_Building_Object();
};

class TRIBE_Master_Building_Object : public Base_TRIBE_Master_Building_Object {
public:
    virtual ~TRIBE_Master_Building_Object();
};

TRIBE_Master_Building_Object::~TRIBE_Master_Building_Object() {
}
