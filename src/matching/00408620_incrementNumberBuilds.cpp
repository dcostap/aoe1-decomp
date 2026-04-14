class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[156];
    int numberBuilds_;

    void incrementNumberBuilds();
};

void BuildItem::incrementNumberBuilds() {
    this->numberBuilds_++;
}
