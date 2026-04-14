class BaseClass {
public:
    virtual ~BaseClass();
    BaseClass();
};

class TScreenPanel : public BaseClass {
public:
    virtual ~TScreenPanel();
    TScreenPanel();
};

TScreenPanel::TScreenPanel() : BaseClass() {
}
