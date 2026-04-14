class BaseClass {
public:
    virtual ~BaseClass();
    BaseClass(int param);
};

class TRIBE_Effects : public BaseClass {
public:
    virtual ~TRIBE_Effects();
    TRIBE_Effects(int param);
};

TRIBE_Effects::TRIBE_Effects(int param) : BaseClass(param) {
}
