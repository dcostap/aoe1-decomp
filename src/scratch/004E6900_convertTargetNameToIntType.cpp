#ifdef TAIPBOOK_CANONICAL_TU
int TribeAIPlayBook::convertTargetNameToIntType(char* p) const {
    return AIPlayBook::convertTargetNameToIntType(p);
}
#else
class TribeAIPlayBook {
public:
    void target_func(int p0);
    void convertTargetNameToIntType(int p);
};

void TribeAIPlayBook::convertTargetNameToIntType(int p) { this->target_func(p); }
#endif
