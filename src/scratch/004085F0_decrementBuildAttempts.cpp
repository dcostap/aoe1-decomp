class BuildItem {
public:
    char gap_0[0x88];
    int field_88;

    void decrementBuildAttempts();
};

void BuildItem::decrementBuildAttempts() {
    this->field_88--;
    if (this->field_88 < 0) {
        this->field_88 = 0;
    }
}
