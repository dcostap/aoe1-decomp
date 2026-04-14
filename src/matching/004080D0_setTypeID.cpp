class BaseItem {
public:
    virtual ~BaseItem();
    int typeID_;

    void setTypeID(int);
};

void BaseItem::setTypeID(int val) {
    this->typeID_ = val;
}
