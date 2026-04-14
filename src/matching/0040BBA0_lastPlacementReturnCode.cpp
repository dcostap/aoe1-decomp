class ConstructionAIModule {
public:
    virtual ~ConstructionAIModule();
    char gap_0[0x30C];
    int field_310;
    int lastPlacementReturnCode();
};

int ConstructionAIModule::lastPlacementReturnCode() { return this->field_310; }
