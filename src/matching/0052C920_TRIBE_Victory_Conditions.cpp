class BaseClass {
public:
    virtual ~BaseClass();
    BaseClass(int param);
};

class TRIBE_Victory_Conditions : public BaseClass {
public:
    virtual ~TRIBE_Victory_Conditions();
    TRIBE_Victory_Conditions(int param);
};

TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(int param) : BaseClass(param) {
}
