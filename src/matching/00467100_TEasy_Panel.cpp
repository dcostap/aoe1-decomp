// probe 3: natural virtual class ctor surface like the matched TDialogPanel path

class TPanel {
public:
    virtual ~TPanel();
    TPanel();
};

class TEasy_Panel : public TPanel {
public:
    char gap_04[0x474];

    virtual ~TEasy_Panel();
    TEasy_Panel();
    void init_vars();
};

TEasy_Panel::TEasy_Panel()
    : TPanel()
{
    init_vars();
}
