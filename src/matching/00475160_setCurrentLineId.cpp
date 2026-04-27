// attempt 1: set_text as direct call; body too short (je 0x41 vs 0x46)
// attempt 2: set_text as virtual; body still too short (je 0x40 vs 0x46)
// Left in scratch after 2 attempts
// Remaining: original saves val_panel->vftable in edi before get_text call, reuses for set_text call
// VC5 loads vftable fresh just before set_text call (different pattern, ~6 bytes shorter)
// set_text belongs at vtable slot 0xE8; adding the real slot position made VC5 save that slot table in edi across get_text.

class TTextPanel {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
    virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C();
    virtual void vf90(); virtual void vf94(); virtual void vf98(); virtual void vf9C();
    virtual void vfA0(); virtual void vfA4(); virtual void vfA8(); virtual void vfAC();
    virtual void vfB0(); virtual void vfB4(); virtual void vfB8(); virtual void vfBC();
    virtual void vfC0(); virtual void vfC4(); virtual void vfC8(); virtual void vfCC();
    virtual void vfD0(); virtual void vfD4(); virtual void vfD8(); virtual void vfDC();
    virtual void vfE0(); virtual void vfE4();
    virtual void set_text(char* text);

    void set_line_by_id(int id);
    long get_line();
    char* get_text(int id);
};

class TValPanel : public TTextPanel {};

class TDropDownPanel {
public:
    char gap_00[0xF4];
    TTextPanel* val_panel;
    char gap_F8[0x4];
    TTextPanel* list_panel;
    char gap_100[0x8];
    short val_num;

    void setCurrentLineId(int id);
};

void TDropDownPanel::setCurrentLineId(int id) {
    if (list_panel) {
        list_panel->set_line_by_id(id);
        long line = list_panel->get_line();
        val_num = (short)line;
        if (val_panel) {
            val_panel->set_text(list_panel->get_text((short)line));
        }
    }
}
