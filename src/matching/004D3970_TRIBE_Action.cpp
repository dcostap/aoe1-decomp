class RGE_Action {
public:
    virtual ~RGE_Action();
};

// BINARY NOTE: The shipped body is a direct thunk to RGE_Action::~RGE_Action.
class __declspec(novtable) TRIBE_Action : public RGE_Action {
public:
    virtual ~TRIBE_Action();
};

TRIBE_Action::~TRIBE_Action() {}
