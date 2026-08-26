// attempt 1: set_text as direct call; body too short (je 0x41 vs 0x46)
// attempt 2: set_text as virtual; body still too short (je 0x40 vs 0x46)
// Left in scratch after 2 attempts
// Remaining: original saves val_panel->vftable in edi before get_text call, reuses for set_text call
// VC5 loads vftable fresh just before set_text call (different pattern, ~6 bytes shorter)
// set_text belongs at vtable slot 0xE8; adding the real slot position made VC5 save that slot table in edi across get_text.

#ifndef PNL_DROP_CONTEXT
class TTextPanel {
public:
    virtual void set_text(char* text);

    void set_line_by_id(int id);
    long get_line();
    char* get_text(long id);
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
#endif

void TDropDownPanel::setCurrentLineId(int id) {
    if (list_panel) {
        list_panel->set_line_by_id(id);
        long line = list_panel->get_line();
        val_num = (short)line;
        if (val_panel) {
            val_panel->set_text(list_panel->get_text((long)(short)line));
        }
    }
}
