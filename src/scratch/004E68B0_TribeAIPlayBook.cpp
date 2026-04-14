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

TribeAIPlayBook::TribeAIPlayBook() : BaseClass() {
}
