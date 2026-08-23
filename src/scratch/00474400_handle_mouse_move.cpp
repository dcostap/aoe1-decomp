class TDropDownPanel {
public:
    void target_method(int a, int b, int c, int d);

    void handle_mouse_move(int a, int b, int c, int d);
};

void TDropDownPanel::handle_mouse_move(int a, int b, int c, int d) {
    this->target_method(a, b, c, d);
}
