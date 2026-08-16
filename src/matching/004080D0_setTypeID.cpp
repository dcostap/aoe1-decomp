class BaseItem {
public:
    virtual ~BaseItem();
    int typeIDValue;

    void setTypeID(int);
};

void BaseItem::setTypeID(int value) {
    typeIDValue = value;
}
