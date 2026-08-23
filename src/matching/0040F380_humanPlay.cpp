#ifndef AIPBOOK_CANONICAL_TU
class AIPlay {
public:
    char nameValue[2];
    int humanPlay() const;
};
#endif

int AIPlay::humanPlay() const {
    if (this->nameValue[0] == 0x48 && this->nameValue[1] == 0x50) return 1;
    return 0;
}
