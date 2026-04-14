class SubType {
public:
    void target_method(int param);
};

class TribeMainDecisionAIModule {
public:
    char gap_0[0x1146C];
    SubType sub_1146C;

    void detask(int param);
};

void TribeMainDecisionAIModule::detask(int param) {
    this->sub_1146C.target_method(param);
}
