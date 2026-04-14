class Base_TScrollBarPanel {
public:
    virtual ~Base_TScrollBarPanel();
};

class TScrollBarPanel : public Base_TScrollBarPanel {
public:
    virtual ~TScrollBarPanel();
};

TScrollBarPanel::~TScrollBarPanel() {
}
