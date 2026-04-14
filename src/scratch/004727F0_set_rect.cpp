class TDropDownButtonPanel {
public:
    void target_method(int a, int b, int c, int d);

    void set_rect(int a, int b, int c, int d);
};

void TDropDownButtonPanel::set_rect(int a, int b, int c, int d) {
    this->target_method(a, b, c, d);
}
