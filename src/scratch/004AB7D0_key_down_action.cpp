// 004AB7D0 TRIBE_Screen_Sed::key_down_action
// scr_sed.cpp
// Attempt log:
// try 1: broad reconstruction from packet: modal guard, key-with-modifier shortcuts, numeric panel shortcuts, scenario-editor command shortcuts.
// try 2: modeled initial global input/modal guard through 0x62E870 and early return when busy.
// try 3: modeled flags/nonzero branch using key range 'A'..'W', including view mode toggle for 'A'.
// try 4: modeled Ctrl/modified B..K cases as repeated button(+0x4D8..+0x4FC)->setMode(1) followed by set_panel(1..10) and return 0.
// try 5: modeled scenario cycle key using global 0x87D7B4, main-view test, wrap to 0/1/4, and messageButton->setMode(2).
// try 6: modeled no-flags numeric key dispatch range '0'..'9' for panelMode 8/3/4/6/5 and generic commandNum path.
// try 7: modeled panelMode 8 path: refreshList, list select, virtual doAction(...,3,0,0), commandNum, selectedNum, updateAfter.
// try 8: modeled panelMode 3/6 lockPanel +0x3C guards and panelMode 4 direct selection.
// try 9: modeled function-key/editor command cases 0x70..0x73, including openThing(openA/openB), otherAction, current player close/cancel flow and message button update.
// try 10: fixed local layout typo (p8/p5 offsets) so source compiles.
// try 11: default compile matches original size exactly at 1121B, but mismatch is broad: 930 positional bytes / 82.96%, first mismatch at early branch distance/parameter slot and large switch table/control topology. /GX not needed.
// left in scratch: broad behavior and size are present, but exact switch-table grouping, parameter ordering, repeated early-return layout, and virtual call surfaces differ too widely. No accepted_drift: broad control-flow/register mismatch.

class Widget { public: virtual void vf0(); virtual void vf4(); virtual void vf8(); virtual void vfC(); virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C(); virtual void setMode(int); virtual void vf24(); virtual void vf28(); virtual void vf2C(); virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C(); virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C(); virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C(); virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C(); virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C(); virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C(); virtual void vf90(); virtual void vf94(); virtual void vf98(); virtual void vf9C(); virtual void vfA0(); virtual void vfA4(); virtual void vfA8(); virtual void vfAC(); virtual void vfB0(); virtual void doAction(void*,int,int,int); };
class GlobalInput { public: int busy(); };
class MainView { public: char gap[0x50]; unsigned char mode; void* currentPlayer(); };
extern GlobalInput gInput;
extern MainView* gMainView;
extern int gScenarioCycle;
extern void openThing(void*);

class TRIBE_Screen_Sed {
public:
    void* vtbl; char gap04[0x4a4-4]; int panelMode; char gap4a8[0x4b8-0x4a8]; short selectedNum;
    char gap4ba[0x4c8-0x4ba]; Widget* messageButton; char gap4cc[0x4d4-0x4cc]; Widget* lockPanel;
    Widget* buttons[12]; char gap504[0x5b4-0x504]; Widget* p3; char gap5b8[0x5d8-0x5b8]; void* openA;
    char gap5dc[0x618-0x5dc]; Widget* p4; char gap61c[0x73c-0x61c]; Widget* p6; char gap740[0x76c-0x740]; void* openB;
    char gap770[0x7cc-0x770]; Widget* p8; char gap7d0[0x894-0x7d0]; Widget* p5;
    int key_down_action(long key, float f, int flags, int p4, int p5);
    void set_panel(int); void refreshList(); void setupSelection(int,int,int); void commandNum(int,int,int); void updateAfter(); void otherAction();
};
extern int sub_422490(MainView*);
extern unsigned char sub_41ACC0(void*);
extern unsigned char sub_4C0C50(void*);

int TRIBE_Screen_Sed::key_down_action(long key, float, int flags, int, int) {
    int n;
    if (gInput.busy()) return 0;
    if (flags) {
        switch (key) {
        case 'A': if (gMainView->mode != 3) { gMainView->mode = 3; return 1; } gMainView->mode = 0; return 1;
        case 'B': buttons[0]->setMode(1); set_panel(1); return 0;
        case 'C': buttons[1]->setMode(1); set_panel(2); return 0;
        case 'D': buttons[2]->setMode(1); set_panel(3); return 0;
        case 'E': buttons[3]->setMode(1); set_panel(4); return 0;
        case 'F': buttons[4]->setMode(1); set_panel(5); return 0;
        case 'G': buttons[5]->setMode(1); set_panel(6); return 0;
        case 'H': buttons[6]->setMode(1); set_panel(7); return 0;
        case 'I': buttons[7]->setMode(1); set_panel(8); return 0;
        case 'J': buttons[8]->setMode(1); set_panel(9); return 0;
        case 'K': buttons[9]->setMode(1); set_panel(10); return 0;
        case 'L':
            ++gScenarioCycle;
            if (sub_422490(gMainView)) { if (gScenarioCycle > 4) gScenarioCycle = 0; }
            else { if (gScenarioCycle > 1) gScenarioCycle = 0; }
            messageButton->setMode(2); return 0;
        default: return 0;
        }
    }
    if (key >= '0' && key <= '9') {
        n = key - '0';
        if (panelMode == 8 && n > 0) { refreshList(); p8->setMode(n-1); ((Widget*)this)->doAction(p8,3,0,0); commandNum(n,0,0); selectedNum=(short)n; updateAfter(); return 0; }
        if (panelMode == 3 && n > 0) { if (*(int*)((char*)lockPanel+0x3c)) return 0; p3->setMode(n-1); ((Widget*)this)->doAction(p3,0,0,0); return 0; }
        if (panelMode == 4) { p4->setMode(n); ((Widget*)this)->doAction(p4,0,0,0); return 0; }
        if (panelMode == 6 && n > 0) { if (*(int*)((char*)lockPanel+0x3c)) return 0; p6->setMode(n-1); ((Widget*)this)->doAction(p6,1,0,0); return 0; }
        if (panelMode == 5 && n > 0) { p5->setMode(n-1); ((Widget*)this)->doAction(p5,1,0,0); return 0; }
        if (n > 0) { commandNum(n,0,0); selectedNum=(short)n; return 0; }
    }
    switch (key) {
    case 0x70: if (panelMode==3 && !*(int*)((char*)lockPanel+0x3c)) openThing(openA); return 0;
    case 0x71: if (panelMode==6 && !*(int*)((char*)lockPanel+0x3c) && *(int*)((char*)openB+0x6c)) openThing(openB); return 0;
    case 0x72: otherAction(); return 0;
    case 0x73:
        if (panelMode == 4) {
            void* p = gMainView->currentPlayer();
            unsigned char v = 0x14;
            if (p) {
                if (*(void**)((char*)p+0x18)) v = sub_41ACC0(*(void**)((char*)p+0x18));
                else if (*(void**)((char*)p+0x10)) v = sub_4C0C50(*(void**)((char*)p+0x10));
            }
            ((Widget*)p)->vf0();
            if (!v) messageButton->setMode(2);
            return 1;
        }
        break;
    }
    return 0;
}
