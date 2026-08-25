#ifndef TAITACMD_SHARED_CONTEXT
class TribeTacticalAIModule {
public:
    char gap_0[0xD88];
    int arr_[4];
    int neededResource(int index);
};
#endif

int TribeTacticalAIModule::neededResource(int index) {
    if (index < 0 || index >= 4) return -1;
    return this->arr_[index];
}
