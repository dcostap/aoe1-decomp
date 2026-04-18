class UpdatePlayHost {
public:
    void helper(int v);
    void update_play(void);
    short field_00;
};

void UpdatePlayHost::update_play(void) {
    if (this->field_00 > 0) {
        this->helper(1);
        this->field_00 = 0;
    }
}
