#ifndef AOE1_PNL_LST_CONTEXT_H
class TTextPanel {
public:
    virtual ~TTextPanel();
};

class TListPanel : public TTextPanel {
public:
    virtual ~TListPanel();
};
#endif

TListPanel::~TListPanel() {
}
