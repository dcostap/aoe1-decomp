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

    int IsIMEEnabled();
};

#endif
int TPanelSystem::IsIMEEnabled() {
    return this->ImeEnabled_;
}
