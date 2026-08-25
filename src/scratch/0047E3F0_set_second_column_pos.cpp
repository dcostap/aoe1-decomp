class RGE_Dialog_List {
public:
    virtual ~RGE_Dialog_List();
    virtual long setup(void*, RGE_Dialog_List*, long, long, long, long, unsigned char);
    virtual void set_rect(void*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                  long, long, RGE_Dialog_List*, RGE_Dialog_List*,
                                  RGE_Dialog_List*, RGE_Dialog_List*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int param);
    char gap_4[0x15A];
    int field_160;

    void set_second_column_pos(int value);
};

void RGE_Dialog_List::set_second_column_pos(int value) {
    this->field_160 = value;
    this->set_redraw(1);
}
