class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[164];
    int skipCycles_;

    void incrementSkipCycles();
};

void BuildItem::incrementSkipCycles() {
    this->skipCycles_++;
}
