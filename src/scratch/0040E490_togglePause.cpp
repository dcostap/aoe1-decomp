class AIModule {
public:
    char gap_0[0x94];
    int field_94;

    void togglePause();
};

void AIModule::togglePause() {
    this->field_94 = (this->field_94 == 0);
}
