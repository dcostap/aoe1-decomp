class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[156];
    int numberBuilds_;

    void setNumberBuilds(int);
};

void BuildItem::setNumberBuilds(int val) {
    this->numberBuilds_ = val;
}
