// VA: 0047D120 TTextPanel::key_down_action
// PDB source: Pnl_txt.cpp lines 884-921
// Attempt log:
// - Replaced the structural stub with the period-plausible switch and panel
//   forwarding path supported by the original CFG and proven TPanel layout.
// - Baseline source-order switch was exact-sized but VC5 merged all four
//   break-case scroll calls; matching the binary's case layout with 28/26,
//   22/21, then 24/23 improved the structural diff but still leaves one
//   merged scroll call.
// - The PDB-proven unsigned-char scroll ABI did not change emitted bytes.
// - Duplicated/goto forwarding tails and a narrow volatile reread did not
//   split the merged call; an early-return duplicate tail restored the call
//   count but grew the function by 53 bytes, so it was rolled back.

class TPanel {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual long key_down_action(long, short, int, int, int);

    char gap_04[0x3C];
    TPanel* parent_panel; // +0x40
    char gap_44[0x30];
    int tab_stop;         // +0x74
    char gap_78[0x7C];
};

class TTextPanel : public TPanel {
public:
    void scroll(unsigned char scroll_type, short amount, int param_3);
    virtual long key_down_action(long param_1, short param_2, int param_3,
                                 int param_4, int param_5);
};

long TTextPanel::key_down_action(long param_1, short param_2, int param_3,
                                 int param_4, int param_5)
{
    switch (param_1) {
    case 0x28:
        this->scroll(2, 0, 1);
        break;
    case 0x26:
        this->scroll(3, 0, 1);
        break;
    case 0x22:
        this->scroll(4, 0, 1);
        break;
    case 0x21:
        this->scroll(5, 0, 1);
        break;
    case 0x24:
        this->scroll(6, 0, 1);
        return 1;
    case 0x23:
        this->scroll(7, 0, 1);
        return 1;
    default:
        return 0;
    }

    if (this->parent_panel != 0 && this->tab_stop != 0) {
        this->parent_panel->key_down_action(param_1, param_2, param_3,
                                             param_4, param_5);
    }
    return 1;
}
