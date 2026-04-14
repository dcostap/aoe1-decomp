class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[100];
    int skip_;

    void setSkip(int);
};

void BaseItem::setSkip(int val) {
    this->skip_ = val;
}
