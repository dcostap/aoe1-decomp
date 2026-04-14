class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[152];
    int placeOnElevation_;

    int placeOnElevation() const;
};

int BuildItem::placeOnElevation() const {
    return this->placeOnElevation_;
}
