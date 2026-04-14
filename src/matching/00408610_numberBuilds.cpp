class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[156];
    int numberBuilds_;

    int numberBuilds() const;
};

int BuildItem::numberBuilds() const {
    return this->numberBuilds_;
}
