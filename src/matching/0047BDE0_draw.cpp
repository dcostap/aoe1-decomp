class TScrollBarPanel {
public:
    virtual void draw();
};

class TVerticalSliderPanel : public TScrollBarPanel {
public:
    void draw();
};

void TVerticalSliderPanel::draw() { TScrollBarPanel::draw(); }
