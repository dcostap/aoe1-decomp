class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[132];
    int buildAttempts_;

    void incrementBuildAttempts();
};

void BuildItem::incrementBuildAttempts() {
    this->buildAttempts_++;
}
