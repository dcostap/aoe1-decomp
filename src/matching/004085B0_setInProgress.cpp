class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[124];
    int inProgress_;

    void setInProgress(int);
};

void BuildItem::setInProgress(int val) {
    this->inProgress_ = val;
}
