class AIModule {
public:
    virtual ~AIModule();
    char gap_04[224];
    int intelligenceLevel_;

    int setIntelligenceLevel(int param_1);
};

int AIModule::setIntelligenceLevel(int param_1) {
    this->intelligenceLevel_ = param_1;
    if (param_1 < 1) {
        this->intelligenceLevel_ = 1;
        return 0;
    }
    if (param_1 > 10) {
        this->intelligenceLevel_ = 10;
        return 0;
    }
    return 1;
}
