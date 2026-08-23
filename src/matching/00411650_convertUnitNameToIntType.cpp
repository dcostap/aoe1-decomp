#ifndef AIPBOOK_CANONICAL_TU
class AIPlayBook {
public:
    virtual ~AIPlayBook();
    virtual int convertUnitNameToIntType(char* name) const;
};
#endif

int AIPlayBook::convertUnitNameToIntType(char* name) const { return -1; }
