class ConstructionItem {
public:
    char gap_0[0x7C];
    int field_7C;

    void decrementBuildAttempts();
};

void ConstructionItem::decrementBuildAttempts() {
    this->field_7C--;
    if (this->field_7C < 0) {
        this->field_7C = 0;
    }
}
