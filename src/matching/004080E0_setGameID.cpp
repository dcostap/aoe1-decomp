class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[4];
    int gameID_;

    void setGameID(int);
};

void BaseItem::setGameID(int val) {
    this->gameID_ = val;
}
