class TSpan_Node_List {
public:
    char gap_0[0x2C];
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    void ResetStats();
};

void TSpan_Node_List::ResetStats() {
    this->field_2C = 0;
    this->field_30 = 0;
    this->field_34 = 0;
    this->field_38 = 0;
}
