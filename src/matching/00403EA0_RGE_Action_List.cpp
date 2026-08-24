#ifndef ACT_LIST_SHARED_CONTEXT
class RGE_Action_List {
public:
    virtual void dummy();
    int field_4;
    int field_8;

    RGE_Action_List(class RGE_Action_Object* param);
};
#endif

RGE_Action_List::RGE_Action_List(RGE_Action_Object* param) {
    this->obj = param;
    this->list = 0;
}
