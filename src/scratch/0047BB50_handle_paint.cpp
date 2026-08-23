class TPanel {
public:
    void drawSelf();
    int handle_paint();
};

int TPanel::handle_paint() {
    this->drawSelf();
    return 0;
}
