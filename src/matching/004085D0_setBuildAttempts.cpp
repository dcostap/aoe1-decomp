class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[132];
    int buildAttempts_;

    void setBuildAttempts(int);
};

void BuildItem::setBuildAttempts(int val) {
    this->buildAttempts_ = val;
}
