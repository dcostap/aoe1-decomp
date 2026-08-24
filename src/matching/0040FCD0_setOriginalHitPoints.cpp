#ifndef AIPBOOK_CANONICAL_TU
class AIPlayStatus {
public:
    char gap_0[0x1A4];
    int arr_[5];
    void setOriginalHitPoints(int index, int val);
};
#endif

void AIPlayStatus::setOriginalHitPoints(int index, int val) {
    if (index < 0 || index >= 5) return;
    this->arr_[index] = val;
}
