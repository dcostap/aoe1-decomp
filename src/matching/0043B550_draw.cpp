#ifndef DLG_ABT_CANONICAL_TU
class TEasy_Panel {
public:
    virtual void draw();
};

class TribeAboutDialog : public TEasy_Panel {
public:
    void draw();
};
#endif

void TribeAboutDialog::draw() { TEasy_Panel::draw(); }
