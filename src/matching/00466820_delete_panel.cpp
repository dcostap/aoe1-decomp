#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    virtual void scalar_deleting_destructor(unsigned int flags);
    void delete_panel(TPanel** panel);
};

#endif
void TPanel::delete_panel(TPanel** panel) {
    if (*panel != 0) {
    delete *panel;
        *panel = 0;
    }
}
