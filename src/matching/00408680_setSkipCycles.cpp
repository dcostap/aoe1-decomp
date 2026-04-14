class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[164];
    int skipCycles_;

    void setSkipCycles(int);
};

void BuildItem::setSkipCycles(int val) {
    this->skipCycles_ = val;
}
