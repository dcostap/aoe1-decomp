class RGE_Dialog_List {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void notify(int param);
    char gap_4[0x15A];
    int field_160;

    void set_second_column_pos(int value);
};

void RGE_Dialog_List::set_second_column_pos(int value) {
    this->field_160 = value;
    this->notify(1);
}
