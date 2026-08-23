#ifndef AICONMOD_CANONICAL_TU
class ConstructionAIModule {
public:
    enum PlacementResult { PlacementOk = 0 };
    virtual ~ConstructionAIModule();
    char gap_0[0x30C];
    PlacementResult lastPlacementReturnCodeValue;
    PlacementResult lastPlacementReturnCode();
};
#endif

ConstructionAIModule::PlacementResult ConstructionAIModule::lastPlacementReturnCode() {
    return this->lastPlacementReturnCodeValue;
}
