class TEasy_Panel {
public:
    virtual void draw();
};

class TScreenPanel : public TEasy_Panel {
public:
    void draw();
};

void TScreenPanel::draw() { TEasy_Panel::draw(); }
