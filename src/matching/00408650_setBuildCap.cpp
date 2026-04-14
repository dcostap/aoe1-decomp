class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[160];
    int buildCap_;

    void setBuildCap(int);
};

void BuildItem::setBuildCap(int val) {
    this->buildCap_ = val;
}
