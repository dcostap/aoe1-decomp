class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[88];
    float xSize_;

    float xSize() const;
};

float BaseItem::xSize() const {
    return this->xSize_;
}
