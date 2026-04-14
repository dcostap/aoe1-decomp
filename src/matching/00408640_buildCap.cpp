class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[160];
    int buildCap_;

    int buildCap() const;
};

int BuildItem::buildCap() const {
    return this->buildCap_;
}
