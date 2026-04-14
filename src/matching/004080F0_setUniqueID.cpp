class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[8];
    int uniqueID_;

    void setUniqueID(int);
};

void BaseItem::setUniqueID(int val) {
    this->uniqueID_ = val;
}
