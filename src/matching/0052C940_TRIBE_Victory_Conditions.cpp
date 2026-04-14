class Base_TRIBE_Victory_Conditions {
public:
    virtual ~Base_TRIBE_Victory_Conditions();
};

class TRIBE_Victory_Conditions : public Base_TRIBE_Victory_Conditions {
public:
    virtual ~TRIBE_Victory_Conditions();
};

TRIBE_Victory_Conditions::~TRIBE_Victory_Conditions() {
}
