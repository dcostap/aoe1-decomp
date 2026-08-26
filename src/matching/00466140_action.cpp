#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    virtual long action(TPanel* panel, long a2, unsigned long a3, unsigned long a4);

    char gap_04[0x3C];
    TPanel* parent_panel;
};

#endif
long TPanel::action(TPanel* panel, long a2, unsigned long a3, unsigned long a4) {
    if (parent_panel != 0) {
        return parent_panel->action(panel, a2, a3, a4);
    }
    return 0;
}
