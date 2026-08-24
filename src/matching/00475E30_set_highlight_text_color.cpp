#ifndef PNL_EDIT_TU_CONTEXT
class TEditPanel {
public:
    virtual ~TEditPanel();
    void set_highlight_text_color(int p0, int p1);
};
#endif

#ifndef PNL_EDIT_TU_CONTEXT
void TEditPanel::set_highlight_text_color(int p0, int p1) {}
#else
void TEditPanel::set_highlight_text_color(unsigned long p0, unsigned long p1) {}
#endif
