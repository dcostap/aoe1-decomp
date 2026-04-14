class SubType {
public:
    void target_method(int param);
};

class TribeStrategyAIModule {
public:
    char gap_0[0x268];
    SubType sub_268;

    void rule(int param);
};

void TribeStrategyAIModule::rule(int param) {
    this->sub_268.target_method(param);
}
