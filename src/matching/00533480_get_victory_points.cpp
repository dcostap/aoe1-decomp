class RGE_Victory_Conditions {
public:
    virtual ~RGE_Victory_Conditions();
    char gap_0[0x18];
    int field_1C;
    int get_victory_points();
};

int RGE_Victory_Conditions::get_victory_points() { return this->field_1C; }
