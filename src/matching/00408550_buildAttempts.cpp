class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[132];
    int buildAttempts_;

    int buildAttempts() const;
};

int BuildItem::buildAttempts() const {
    return this->buildAttempts_;
}
