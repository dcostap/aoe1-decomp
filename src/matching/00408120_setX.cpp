class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[76];
    float x_;

    void setX(float);
};

void BaseItem::setX(float val) {
    this->x_ = val;
}
