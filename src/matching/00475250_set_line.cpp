// tried the direct dropdown forwarding shape; compile succeeded, but the extractor hit a 75-byte .text ceiling
// tried widening the local panel surface; that only made the object bigger, so I’m shrinking to the exact touched fields/methods
// leaving in scratch unless this smaller surface lands under the extractor limit
// direct TTextPanel set_line/get_text are nonvirtual; set_text dispatch is vtable slot 0xE8.
#ifndef PNL_DROP_CONTEXT
class TTextPanel {
public:
    virtual void set_text(char* text);

    void set_line(long line);
    char* get_text(long line);
};
class TListPanel : public TTextPanel {
};

class TDropDownPanel {
public:
    char gap_00[0xF4];
    TTextPanel* val_panel;
    TTextPanel* btn_panel;
    TListPanel* list_panel;
    TTextPanel* scbar_panel;
    int mode;
    short val_num;

    void set_line(long line);
};
#endif

void TDropDownPanel::set_line(long line) {
    this->val_num = (short)line;
    if (this->list_panel != 0) {
        this->list_panel->set_line(line);
        if (this->val_panel != 0) {
            this->val_panel->set_text(this->list_panel->get_text(line));
        }
    }
}
