class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[80];
    float y_;

    void setY(float);
};

void BaseItem::setY(float val) {
    this->y_ = val;
}
