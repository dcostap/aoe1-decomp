class TEasy_Panel {
public:
    virtual void draw();
};

class TribeAboutDialog : public TEasy_Panel {
public:
    void draw();
};

void TribeAboutDialog::draw() { TEasy_Panel::draw(); }
