// EH-framed ctor: base TPanel(name), compiler-installed TEasy_Panel vfptr, then init_vars()
// FLAGS: config/flags/00466A20_TEasy_Panel.rsp

class TPanel {
public:
    TPanel(char* name);
    virtual ~TPanel();
};

class TEasy_Panel : public TPanel {
public:
    TEasy_Panel(char* name);
    virtual ~TEasy_Panel();

protected:
    void init_vars();
};

TEasy_Panel::TEasy_Panel(char* name)
    : TPanel(name)
{
    init_vars();
}
