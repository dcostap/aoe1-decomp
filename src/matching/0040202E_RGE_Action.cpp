class RGE_Action {
public:
    ~RGE_Action();
};

__declspec(naked) RGE_Action::~RGE_Action() {
    __asm nop
    __asm nop
}
