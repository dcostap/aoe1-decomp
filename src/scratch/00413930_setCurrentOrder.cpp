class UnitAIModule {
public:
    char gap_0[0x28];
    int field_28;
    char gap_2C[0x24];
    int field_50;

    void setCurrentOrder(int value);
};

void UnitAIModule::setCurrentOrder(int value) {
    this->field_50 = this->field_28;
    this->field_28 = value;
}
