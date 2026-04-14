class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[140];
    int terrainSet_;

    int terrainSet() const;
};

int BuildItem::terrainSet() const {
    return this->terrainSet_;
}
