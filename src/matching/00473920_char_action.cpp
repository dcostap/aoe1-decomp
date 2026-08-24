#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    virtual ~TButtonPanel();
    int char_action(int p0, int p1);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

int TButtonPanel::char_action(int p0, int p1) { return 0; }
