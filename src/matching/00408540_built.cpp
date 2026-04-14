class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[128];
    int built_;

    int built() const;
};

int BuildItem::built() const {
    return this->built_;
}
