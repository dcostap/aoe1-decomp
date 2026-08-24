#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TPanel {
public:
    virtual ~TPanel();
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    void prepare_for_close();
};
#endif

TEasy_Panel::~TEasy_Panel() {
    TPanel* self = this;

    prepare_for_close();
}
