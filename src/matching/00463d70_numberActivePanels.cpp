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

    int numberActivePanels();
};

int TPanelSystem::numberActivePanels() {
    return this->numberActivePanels_;
}
