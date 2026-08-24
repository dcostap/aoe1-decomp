// probe 3: natural virtual class ctor surface like the matched TDialogPanel path

#ifndef AOE1_PANEL_EZ_CONTEXT_H
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
#endif

TEasy_Panel::TEasy_Panel()
    : TPanel()
{
    init_vars();
}
