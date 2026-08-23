class TPanel {
public:
    void set_redraw(int mode);
};

class RGE_Diamond_Map : public TPanel {
public:
    char gap_04[0x104];
    int render_all;

    void set_redraw(int mode);
};

void RGE_Diamond_Map::set_redraw(int mode) {
    TPanel::set_redraw(mode);
    if (mode == 2) {
        this->render_all = 1;
    }
}
