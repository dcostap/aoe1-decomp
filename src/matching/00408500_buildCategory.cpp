class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[112];
    int buildCategory_;

    int buildCategory() const;
};

int BuildItem::buildCategory() const {
    return this->buildCategory_;
}
