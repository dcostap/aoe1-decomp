class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[164];
    int skipCycles_;

    int skipCycles() const;
};

int BuildItem::skipCycles() const {
    return this->skipCycles_;
}
