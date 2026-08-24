#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    virtual ~TButtonPanel();
    int mouse_right_dbl_click_action(int p0, int p1, int p2, int p3);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

int TButtonPanel::mouse_right_dbl_click_action(int p0, int p1, int p2, int p3) { return 0; }
