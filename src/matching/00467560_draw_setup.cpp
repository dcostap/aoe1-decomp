#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TPanel {
public:
    void draw_setup(int);
};
class TEasy_Panel : public TPanel {
public:
    void target_func(int p0);
    void draw_setup(int p);
};
#endif

void TEasy_Panel::draw_setup(int p) { this->TPanel::draw_setup(p); }
