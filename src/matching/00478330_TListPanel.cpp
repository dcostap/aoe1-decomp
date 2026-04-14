class Base_TListPanel {
public:
    virtual ~Base_TListPanel();
};

class TListPanel : public Base_TListPanel {
public:
    virtual ~TListPanel();
};

TListPanel::~TListPanel() {
}
