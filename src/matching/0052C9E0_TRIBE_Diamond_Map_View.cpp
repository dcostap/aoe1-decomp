class RGE_Diamond_Map_View {
public:
    virtual ~RGE_Diamond_Map_View();
    char gap_04[0x168];
    int field_16C;
    int field_170;

    RGE_Diamond_Map_View();
};

class TRIBE_Diamond_Map_View : public RGE_Diamond_Map_View {
public:
    TRIBE_Diamond_Map_View();
};

TRIBE_Diamond_Map_View::TRIBE_Diamond_Map_View() : RGE_Diamond_Map_View() {
    this->field_16C = 0;
    this->field_170 = 0;
}
