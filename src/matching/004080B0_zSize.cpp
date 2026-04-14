class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[96];
    float zSize_;

    float zSize() const;
};

float BaseItem::zSize() const {
    return this->zSize_;
}
