class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[92];
    float ySize_;

    float ySize() const;
};

float BaseItem::ySize() const {
    return this->ySize_;
}
