class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[96];
    float zSize_;

    void setZSize(float);
};

void BaseItem::setZSize(float val) {
    this->zSize_ = val;
}
