struct InnerObj {
    int some_method();
};
class TribeTacticalAIModule {
public:
    int numberItemsToDefend();
    char pad[0xF0];
    char* field_F0;
};
int TribeTacticalAIModule::numberItemsToDefend() {
    return ((InnerObj*)(this->field_F0 + 0xCEC))->some_method();
}
