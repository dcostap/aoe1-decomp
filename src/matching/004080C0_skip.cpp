class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[100];
    int skip_;

    int skip() const;
};

int BaseItem::skip() const {
    return this->skip_;
}
