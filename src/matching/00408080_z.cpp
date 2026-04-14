class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[84];
    float z_;

    float z() const;
};

float BaseItem::z() const {
    return this->z_;
}
