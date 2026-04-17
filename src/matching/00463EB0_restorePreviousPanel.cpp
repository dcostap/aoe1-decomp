extern "C" __declspec(dllimport) int __stdcall UpdateWindow(void* hwnd);
extern void* AppWnd;

class TPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int mode);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
    virtual void vfB0(void);
    virtual void vfB4(void);
    virtual void vfB8(void);
    virtual void vfBC(void);
    virtual void vfC0(int mode);

    TPanel* previousPanel(void);
    void setPreviousPanel(TPanel* panel);
    char* panelName(void);
};

class TPanelSystem {
public:
    char gap_00[0x0C];
    TPanel* currentPanelValue;

    int destroyPanel(char* name);
    int restorePreviousPanel(int destroy_current);
};

int TPanelSystem::restorePreviousPanel(int destroy_current) {
    TPanel* previous;
    TPanel* current;

    if (currentPanelValue == 0) {
        return 0;
    }
    previous = currentPanelValue->previousPanel();
    if (previous == 0) {
        return 0;
    }
    current = currentPanelValue;
    if (destroy_current == 0) {
        previous->setPreviousPanel(current);
    } else {
        if (previous->previousPanel() == current) {
            previous->setPreviousPanel(0);
        }
        destroyPanel(current->panelName());
    }
    currentPanelValue = previous;
    previous->vfC0(1);
    currentPanelValue->vf20(2);
    UpdateWindow(AppWnd);
    return 1;
}
