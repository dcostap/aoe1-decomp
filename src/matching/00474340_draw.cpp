#ifndef PNL_DROP_CONTEXT
class TPanel {
public:
    virtual void draw();
};

class TDropDownPanel : public TPanel {
public:
    void draw();
};
#endif

void TDropDownPanel::draw() { TPanel::draw(); }
