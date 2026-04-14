class Base_RGE_Action_List {
public:
    virtual ~Base_RGE_Action_List();
};

class RGE_Action_List : public Base_RGE_Action_List {
public:
    virtual ~RGE_Action_List();
};

RGE_Action_List::~RGE_Action_List() {
}
