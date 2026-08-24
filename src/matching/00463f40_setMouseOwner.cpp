#ifndef AOE1_PANEL_CONTEXT_H
class TPanelSystem {
public:
    int mouseOwner_;
    int keyboardOwner_;
    int modalPanel_;
    int currentPanel_;
    char gap_10[4];
    int numberActivePanels_;
    char gap_18[0xAA8];
    int ImeEnabled_;
    int ImeOn_;
    int InputEnabled_;

    void setMouseOwner(TPanel* v);
};

#endif
void TPanelSystem::setMouseOwner(TPanel* v) {
    this->mouseOwnerValue = v;
}
