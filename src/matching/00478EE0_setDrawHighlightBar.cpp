class TListPanel {
public:
    virtual ~TListPanel();
    char gap_0[0x198];
    int field_19C;
    void setDrawHighlightBar(int v);
};

void TListPanel::setDrawHighlightBar(int v) { this->field_19C = v; }
