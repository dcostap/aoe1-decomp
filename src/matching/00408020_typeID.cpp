class BaseItem {
public:
    virtual ~BaseItem();
    int typeID_;

    int typeID() const;
};

int BaseItem::typeID() const {
    return this->typeID_;
}
