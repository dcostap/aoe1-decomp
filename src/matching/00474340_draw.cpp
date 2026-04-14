class TPanel {
public:
    virtual void draw();
};

class TDropDownPanel : public TPanel {
public:
    void draw();
};

void TDropDownPanel::draw() { TPanel::draw(); }
