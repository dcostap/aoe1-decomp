class RGE_Action {
public:
    virtual ~RGE_Action();
};

class __declspec(novtable) RGE_Action_Explore : public RGE_Action {
public:
    virtual ~RGE_Action_Explore();
};

RGE_Action_Explore::~RGE_Action_Explore() {
}
