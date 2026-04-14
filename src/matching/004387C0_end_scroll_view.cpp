struct Fwd_87C0 {
    void target();
};

class RGE_Game_World : public Fwd_87C0 {
public:
    char gap_0[0x154];
    int field_154;
    void end_scroll_view();
};

void RGE_Game_World::end_scroll_view() {
    this->field_154 = 0;
    this->target();
}
