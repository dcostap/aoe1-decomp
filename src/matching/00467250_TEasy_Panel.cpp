class TPanel {
public:
    virtual ~TPanel();
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    void prepare_for_close();
};

TEasy_Panel::~TEasy_Panel() {
    TPanel* self = this;

    prepare_for_close();
}
