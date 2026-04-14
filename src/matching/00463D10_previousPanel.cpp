struct Inner_00463D10 {
    int previousPanel();
};

class TPanelSystem {
public:
    char gap_0[0x0C];
    Inner_00463D10 *currentPanel;
    int previousPanel();
};

int TPanelSystem::previousPanel() {
    if (this->currentPanel)
        return this->currentPanel->previousPanel();
    return 0;
}
