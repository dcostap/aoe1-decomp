class BaseClass {
public:
    virtual ~BaseClass();
    BaseClass();
};

class THorizontalSliderPanel : public BaseClass {
public:
    virtual ~THorizontalSliderPanel();
    THorizontalSliderPanel();
};

THorizontalSliderPanel::THorizontalSliderPanel() : BaseClass() {
}
