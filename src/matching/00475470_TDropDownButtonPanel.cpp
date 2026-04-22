class TButtonPanel {
public:
    virtual ~TButtonPanel();
    TButtonPanel();
};

class TDropDownPanel;

class TDropDownButtonPanel : public TButtonPanel {
public:
    char gap_04[0x2B4];
    TDropDownPanel* drop_down_panel;

    TDropDownButtonPanel(TDropDownPanel* panel);
};

TDropDownButtonPanel::TDropDownButtonPanel(TDropDownPanel* panel) : TButtonPanel() {
    this->drop_down_panel = panel;
}
