#ifndef AIPBOOK_CANONICAL_TU
class AIPlayStatus {
public:
    char gap_0[0x1A4];
    int arr_[5];
    int originalHitPoints(int index) const;
};
#endif

int AIPlayStatus::originalHitPoints(int index) const {
    if (index < 0 || index >= 5) return -1;
    return this->arr_[index];
}
