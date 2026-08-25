#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    virtual ~TButtonPanel();
    virtual long char_action(long p0, short p1);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

long TButtonPanel::char_action(long p0, short p1) { return 0; }
