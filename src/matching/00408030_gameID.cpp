class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[4];
    int gameID_;

    int gameID() const;
};

int BaseItem::gameID() const {
    return this->gameID_;
}
