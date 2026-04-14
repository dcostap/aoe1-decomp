class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[128];
    int built_;

    void setBuilt(int);
};

void BuildItem::setBuilt(int val) {
    this->built_ = val;
}
