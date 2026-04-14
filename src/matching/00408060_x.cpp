class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[76];
    float x_;

    float x() const;
};

float BaseItem::x() const {
    return this->x_;
}
