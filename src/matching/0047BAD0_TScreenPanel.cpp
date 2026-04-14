class Base_TScreenPanel {
public:
    virtual ~Base_TScreenPanel();
};

class TScreenPanel : public Base_TScreenPanel {
public:
    virtual ~TScreenPanel();
};

TScreenPanel::~TScreenPanel() {
}
