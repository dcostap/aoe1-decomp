struct Fwd_96B0 {
    void target();
};

class Pnl_ScenarioCreate : public Fwd_96B0 {
public:
    char gap_0[0x5E2];
    short field_5E2;
    void reset_buttons();
};

void Pnl_ScenarioCreate::reset_buttons() {
    this->field_5E2 = 0;
    this->target();
}
