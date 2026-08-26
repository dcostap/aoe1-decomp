#ifdef TAIPBOOK_CANONICAL_TU
int TribeAIPlayBook::convertTargetCharacteristicNameToIntType(char* p) const {
    return AIPlayBook::convertTargetCharacteristicNameToIntType(p);
}
#else
class TribeAIPlayBook {
public:
    void target_func(int p0);
    void convertTargetCharacteristicNameToIntType(int p);
};

void TribeAIPlayBook::convertTargetCharacteristicNameToIntType(int p) { this->target_func(p); }
#endif
