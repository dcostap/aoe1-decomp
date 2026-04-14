class Base_RGE_Task_List {
public:
    virtual ~Base_RGE_Task_List();
};

class RGE_Task_List : public Base_RGE_Task_List {
public:
    virtual ~RGE_Task_List();
};

RGE_Task_List::~RGE_Task_List() {
}
