class UnitAIModule {
public:
    char gap_0[0x30];
    int field_30;
    char gap_34[0x20];
    int field_54;

    void setCurrentAction(int value);
};

void UnitAIModule::setCurrentAction(int value) {
    this->field_54 = this->field_30;
    this->field_30 = value;
}
