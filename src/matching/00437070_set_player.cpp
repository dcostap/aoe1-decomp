class TRIBE_Gaia {
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
    char gap_4[0xF2];
    int field_F8;
    void set_player(int value);
};

void TRIBE_Gaia::set_player(int value) {
    this->field_F8 = value;
    this->notify(2);
}
