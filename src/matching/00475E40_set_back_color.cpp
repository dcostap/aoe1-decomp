#ifndef PNL_EDIT_TU_CONTEXT
class TEditPanel {
public:
    virtual ~TEditPanel();
    void set_back_color(int p0, int p1, int p2);
};
#endif

#ifndef PNL_EDIT_TU_CONTEXT
void TEditPanel::set_back_color(int p0, int p1, int p2) {}
#else
void TEditPanel::set_back_color(void* p0, unsigned long p1, unsigned char p2) {}
#endif
