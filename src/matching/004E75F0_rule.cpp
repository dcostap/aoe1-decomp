class VictoryConditionRuleSystem {
public:
    char gap_0[0x4];
    int arr_[226];
    int rule(int index);
};

int VictoryConditionRuleSystem::rule(int index) {
    if (index < 0 || index >= 226) return -1;
    return this->arr_[index];
}
