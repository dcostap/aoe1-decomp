// tried the straight ctor with base-init + init_vars; build size blew past the target function budget
// tried the minimal constructor surface with a direct vftable store; still not in the right EH/prolog basin
// leaving in scratch because the remaining gap is constructor codegen shape, not behavior
class TPanel {
public:
    void* vftable;
    TPanel();
};

class TEasy_Panel : public TPanel {
public:
    TEasy_Panel();
    void init_vars();
};

TEasy_Panel::TEasy_Panel() : TPanel() {
    this->vftable = (void*)0x570D18;
    this->init_vars();
}
