class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[136];
    int buildFrom_;

    int buildFrom() const;
};

int BuildItem::buildFrom() const {
    return this->buildFrom_;
}
