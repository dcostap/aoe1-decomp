// attempt 1: set_text as direct call; body too short (je 0x41 vs 0x46)
// attempt 2: set_text as virtual; body still too short (je 0x40 vs 0x46)
// Left in scratch after 2 attempts
// Remaining: original saves val_panel->vftable in edi before get_text call, reuses for set_text call
// VC5 loads vftable fresh just before set_text call (different pattern, ~6 bytes shorter)

class TTextPanel {
public:
    void set_line_by_id(int id);
    long get_line();
    char* get_text(int id);
    virtual void set_text(char* text) = 0;
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
            char* text = list_panel->get_text((short)line);
            val_panel->set_text(text);
        }
    }
}
