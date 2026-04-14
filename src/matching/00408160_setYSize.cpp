class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[92];
    float ySize_;

    void setYSize(float);
};

void BaseItem::setYSize(float val) {
    this->ySize_ = val;
}
