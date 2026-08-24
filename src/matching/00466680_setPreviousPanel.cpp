#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    virtual ~TPanel();
    int previousPanel_;
    int previousModalPanel_;
    int pnl_x_;
    int pnl_y_;
    int pnl_wid_;
    int pnl_hgt_;
    int panelName_;
    int render_area_;
    char gap_24[0x54];
    int have_focus_;
    char gap_7C[0x68];
    int help_string_id_;
    int help_page_id_;

    void setPreviousPanel(int v);
};

#endif
void TPanel::setPreviousPanel(int v) {
    this->previousPanel_ = v;
}
