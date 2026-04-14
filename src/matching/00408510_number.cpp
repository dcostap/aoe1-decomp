class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[116];
    int number_;

    int number() const;
};

int BuildItem::number() const {
    return this->number_;
}
