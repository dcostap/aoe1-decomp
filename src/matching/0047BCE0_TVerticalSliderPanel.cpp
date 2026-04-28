// 0047BCE0 TVerticalSliderPanel::TVerticalSliderPanel
// Source: pnl_sld.cpp lines 24-25
// Size: 38 bytes, 0.0000% MATCH
//
// Attempt log:
// Probe 1-2: vtable before fields (body assignments) — mismatch
// Probe 3: member initializer list (drawBox(1), spineWidth(0)) + empty body
//   → VC5 puts vtable AFTER member initialization → EXACT MATCH

class TScrollBarPanel {
public:
    virtual void vf00(void);
    TScrollBarPanel();
};

class TVerticalSliderPanel : public TScrollBarPanel {
public:
    char gap_04[0x1C0];
    int drawBox;
    int spineWidth;

    TVerticalSliderPanel();
};

TVerticalSliderPanel::TVerticalSliderPanel()
    : TScrollBarPanel(), drawBox(1), spineWidth(0)
{
}
