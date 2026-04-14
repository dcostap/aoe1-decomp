class BaseClass {
public:
    virtual ~BaseClass();
    BaseClass(int param);
};

class RGE_Dialog_List : public BaseClass {
public:
    virtual ~RGE_Dialog_List();
    RGE_Dialog_List(int param);
};

RGE_Dialog_List::RGE_Dialog_List(int param) : BaseClass(param) {
}
