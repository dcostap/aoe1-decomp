class BaseClass {
public:
    virtual ~BaseClass();
    BaseClass(int param);
};

class TRIBE_Action_List : public BaseClass {
public:
    virtual ~TRIBE_Action_List();
    TRIBE_Action_List(int param);
};

TRIBE_Action_List::TRIBE_Action_List(int param) : BaseClass(param) {
}
