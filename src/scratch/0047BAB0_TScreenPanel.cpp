class BaseClass {
public:
    virtual ~BaseClass();
    BaseClass(int param);
};

class TScreenPanel : public BaseClass {
public:
    virtual ~TScreenPanel();
    TScreenPanel(int param);
};

TScreenPanel::TScreenPanel(int param) : BaseClass(param) {
}
