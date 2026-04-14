class InnerInnerType {
public:
    void target_method(int param);
};

class InnerType {
public:
    char gap_0[0x3C];
    InnerInnerType* inner_3C;
};

class MainDecisionAIModule {
public:
    char gap_0[0xF0];
    InnerType* member_F0;

    void object(int param);
};

void MainDecisionAIModule::object(int param) {
    this->member_F0->inner_3C->target_method(param);
}
