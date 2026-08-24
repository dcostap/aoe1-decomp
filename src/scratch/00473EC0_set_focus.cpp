// 00473EC0 TDialogPanel::set_focus
// Source: pnl_dlg.cpp lines 150-152
// Size: 13 bytes
#ifndef PNL_DLG_TU_CONTEXT
class TPanel {
public:
    virtual void set_focus(int);
};

class TEasy_Panel : public TPanel {
};

class TDialogPanel : public TEasy_Panel {
public:
    virtual void set_focus(int);
};
#endif

void TDialogPanel::set_focus(int focus)
{
    ((TEasy_Panel*)this)->TEasy_Panel::set_focus(focus);
}
