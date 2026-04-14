class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[80];
    float y_;

    float y() const;
};

float BaseItem::y() const {
    return this->y_;
}
