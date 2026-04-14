class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[124];
    int inProgress_;

    int inProgress() const;
};

int BuildItem::inProgress() const {
    return this->inProgress_;
}
