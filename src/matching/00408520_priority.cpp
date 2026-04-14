class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[120];
    int priority_;

    int priority() const;
};

int BuildItem::priority() const {
    return this->priority_;
}
