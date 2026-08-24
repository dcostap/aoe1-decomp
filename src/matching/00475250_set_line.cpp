// tried the direct dropdown forwarding shape; compile succeeded, but the extractor hit a 75-byte .text ceiling
// tried widening the local panel surface; that only made the object bigger, so I’m shrinking to the exact touched fields/methods
// leaving in scratch unless this smaller surface lands under the extractor limit
// direct TTextPanel set_line/get_text are nonvirtual; set_text dispatch is vtable slot 0xE8.
#ifndef PNL_DROP_CONTEXT
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
