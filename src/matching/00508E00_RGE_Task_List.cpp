class RGE_Task_List {
public:
    virtual void destroy();
    int list;
    short list_num;

    RGE_Task_List();
};

RGE_Task_List::RGE_Task_List() {
    list_num = 0;
    list = 0;
}
