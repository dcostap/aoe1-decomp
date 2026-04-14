class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[84];
    float z_;

    void setZ(float);
};

void BaseItem::setZ(float val) {
    this->z_ = val;
}
