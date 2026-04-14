class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[8];
    int uniqueID_;

    int uniqueID() const;
};

int BaseItem::uniqueID() const {
    return this->uniqueID_;
}
