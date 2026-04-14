class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[88];
    float xSize_;

    void setXSize(float);
};

void BaseItem::setXSize(float val) {
    this->xSize_ = val;
}
