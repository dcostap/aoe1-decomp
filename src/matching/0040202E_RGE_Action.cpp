// STATUS: blocked
// FLAGS: config\flags\0040202E_RGE_Action.rsp
// BLOCKER: Uses inline asm / naked-function codegen, which is now forbidden in this repo.
// NOTE: Demoted from src\matching after the policy change; replace with a source-level exact match.

class RGE_Action {
public:
    ~RGE_Action();
};

__declspec(naked) RGE_Action::~RGE_Action() {
    __asm nop
    __asm nop
}
