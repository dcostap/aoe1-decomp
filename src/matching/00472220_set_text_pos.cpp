#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    long text_x;
    long text_y;
    void set_redraw(int);
    void set_text_pos(long, long);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::set_text_pos(long a, long b) {
    this->text_x = a;
    this->text_y = b;
    this->set_redraw(1);
}
