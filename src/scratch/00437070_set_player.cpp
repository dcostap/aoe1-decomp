class RGE_Diamond_Map {
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
    char gap_0[0xF8];
    int field_F8;

    void set_player(int value);
};

void RGE_Diamond_Map::set_player(int value) {
    this->field_F8 = value;
    this->notify(2);
}
