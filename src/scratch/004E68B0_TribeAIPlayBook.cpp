#ifdef TAIPBOOK_CANONICAL_TU
#include "../../include/taipbook_context.h"
#else
class BaseClass {
public:
    virtual ~BaseClass();
    BaseClass();
};

class TribeAIPlayBook : public BaseClass {
public:
    virtual ~TribeAIPlayBook();
    TribeAIPlayBook();
};
#endif

#ifdef TAIPBOOK_CANONICAL_TU
TribeAIPlayBook::~TribeAIPlayBook() {
}

TribeAIPlayBook::TribeAIPlayBook() : AIPlayBook() {
}
#else
TribeAIPlayBook::TribeAIPlayBook() : BaseClass() {
}
#endif
