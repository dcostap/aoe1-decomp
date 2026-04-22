class RGE_Diamond_Map {
public:
    virtual ~RGE_Diamond_Map();
    RGE_Diamond_Map();
};

class RGE_Diamond_Map_View : public RGE_Diamond_Map {
public:
    char gap_04[0xBC];
    int field_C0;

    RGE_Diamond_Map_View();
};

RGE_Diamond_Map_View::RGE_Diamond_Map_View() : RGE_Diamond_Map() {
    this->field_C0 = 0;
}
