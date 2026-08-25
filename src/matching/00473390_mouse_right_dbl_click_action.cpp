#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    virtual ~TButtonPanel();
    virtual long mouse_right_dbl_click_action(long p0, long p1, int p2, int p3);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

long TButtonPanel::mouse_right_dbl_click_action(long p0, long p1, int p2, int p3) { return 0; }
