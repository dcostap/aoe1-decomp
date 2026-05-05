// VA: 004B4810 TribeSelectScenarioScreen::activatePanels()
// PDB source: Scr_sels.cpp lines 417-433
// Default flags
//
// 104/112 edit-match bytes, 92 bytes exact. Only the set_curr_child call differs:
// __thiscall (original: mov ecx,this; push child; call addr) vs
// __stdcall (rebuild: push child; push this; mov eax,addr; call eax).
// VC5 doesn't allow __thiscall on function pointers.
//
// Fields: scenarioList@+0x494, missionTitle@+0x4AC, missionText@+0x4C0,
// okButton@+0x4C8, cancelButton@+0x4CC, field_3C@+0x3C.
// Virtual: vfunc05 at vtable+0x14, vfunc50 at vtable+0xC8.

struct TPanelVTable {
    virtual void vf0() {}
    virtual void vf1() {}
    virtual void vf2() {}
    virtual void vf3() {}
    virtual void vf4() {}
    virtual void vfunc05(int) {}  // slot 5 (0x14)
};

struct ScreenVTable {
    virtual void vf0() {}
    virtual void vf1() {}
    virtual void vf2() {}
    virtual void vf3() {}
    virtual void vf4() {}
    virtual void vf05(int) {}
    virtual void vf6() {} virtual void vf7() {} virtual void vf8() {} virtual void vf9() {}
    virtual void vf10() {} virtual void vf11() {} virtual void vf12() {} virtual void vf13() {} virtual void vf14() {}
    virtual void vf15() {} virtual void vf16() {} virtual void vf17() {} virtual void vf18() {} virtual void vf19() {}
    virtual void vf20() {} virtual void vf21() {} virtual void vf22() {} virtual void vf23() {} virtual void vf24() {}
    virtual void vf25() {} virtual void vf26() {} virtual void vf27() {} virtual void vf28() {} virtual void vf29() {}
    virtual void vf30() {} virtual void vf31() {} virtual void vf32() {} virtual void vf33() {} virtual void vf34() {}
    virtual void vf35() {} virtual void vf36() {} virtual void vf37() {} virtual void vf38() {} virtual void vf39() {}
    virtual void vf40() {} virtual void vf41() {} virtual void vf42() {} virtual void vf43() {} virtual void vf44() {}
    virtual void vf45() {} virtual void vf46() {} virtual void vf47() {} virtual void vf48() {} virtual void vf49() {}
    virtual void vfunc50(void**, int) {}  // slot 50 (0xC8)
};

class TribeSelectScenarioScreen {
public:
    char pad_00[0x3C];
    void* field_3C;
    char pad_40[0x454];
    TPanelVTable* scenarioList;
    char pad_498[0x14];
    TPanelVTable* missionTitle;
    char pad_4B0[0x10];
    TPanelVTable* missionText;
    char pad_4C4[0x04];
    TPanelVTable* okButton;
    TPanelVTable* cancelButton;

    void activatePanels();
};

struct ObjWithChild {
    char pad[0x6C];
    void* child;
};

void TribeSelectScenarioScreen::activatePanels() {
    ((TPanelVTable*)this->missionTitle)->vfunc05(1);
    ((TPanelVTable*)this->missionText)->vfunc05(1);

    TPanelVTable* tabList[4];
    tabList[0] = this->scenarioList;
    tabList[1] = this->okButton;
    tabList[2] = this->cancelButton;

    ((ScreenVTable*)this)->vfunc50((void**)tabList, 3);

    ObjWithChild* obj = (ObjWithChild*)this->field_3C;
    if (obj == 0 || obj->child == 0) {
        // __stdcall set_curr_child — differs from original __thiscall
        typedef void (__stdcall *SCC)(void*, void*);
        ((SCC)0x004663A0)(this, this->okButton);
    }
}
