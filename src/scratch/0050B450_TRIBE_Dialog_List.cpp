class BaseClass {
public:
    virtual ~BaseClass();
    BaseClass(int param);
};

class TRIBE_Dialog_List : public BaseClass {
public:
    virtual ~TRIBE_Dialog_List();
    TRIBE_Dialog_List(int param);
};

TRIBE_Dialog_List::TRIBE_Dialog_List(int param) : BaseClass(param) {
}
