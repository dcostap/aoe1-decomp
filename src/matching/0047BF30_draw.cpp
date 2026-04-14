class TScrollBarPanel {
public:
    virtual void draw();
};

class THorizontalSliderPanel : public TScrollBarPanel {
public:
    void draw();
};

void THorizontalSliderPanel::draw() { TScrollBarPanel::draw(); }
