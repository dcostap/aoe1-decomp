class RGE_Action_List {
public:
    virtual void dummy();
    int field_4;
    int field_8;

    RGE_Action_List(int param);
};

RGE_Action_List::RGE_Action_List(int param) {
    this->field_4 = param;
    this->field_8 = 0;
}
