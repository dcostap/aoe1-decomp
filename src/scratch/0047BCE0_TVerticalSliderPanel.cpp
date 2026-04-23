class TScrollBarPanel {
public:
    virtual void vf00(void);
    TScrollBarPanel();
};

class TVerticalSliderPanel : public TScrollBarPanel {
public:
    char gap_04[0x1C0];
    int drawBox;
    int spineWidth;

    TVerticalSliderPanel();
};

TVerticalSliderPanel::TVerticalSliderPanel()
    : TScrollBarPanel() {
    this->drawBox = 1;
    this->spineWidth = 0;
}
