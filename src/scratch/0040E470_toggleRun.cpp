class AIModule {
public:
    char gap_0[0x90];
    int field_90;

    void toggleRun();
};

void AIModule::toggleRun() {
    this->field_90 = (this->field_90 == 0);
}
