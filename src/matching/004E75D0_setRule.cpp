class VictoryConditionRuleSystem {
public:
    char gap_0[0x4];
    int arr_[226];
    void setRule(int index, int val);
};

void VictoryConditionRuleSystem::setRule(int index, int val) {
    if (index < 0 || index >= 226) return;
    this->arr_[index] = val;
}
