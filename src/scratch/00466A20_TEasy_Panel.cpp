// first pass: run the TPanel base ctor, install the TEasy_Panel vftable, then initialize the panel variables under the EH frame
// tried the natural ctor body with /GX, then added virtual destructors to force cleanup; the remaining mismatch stayed at the EH/prolog basin (no fs:[0] frame in the rebuilt shape)

class TPanel {
public:
    void* vftable;
    TPanel(char* name);
    virtual ~TPanel();
};

class TEasy_Panel : public TPanel {
public:
    TEasy_Panel(char* name);
    virtual ~TEasy_Panel();
    void init_vars();
};

TEasy_Panel::TEasy_Panel(char* name) : TPanel(name) {
    this->vftable = (void*)0x00570D18;
    init_vars();
}
