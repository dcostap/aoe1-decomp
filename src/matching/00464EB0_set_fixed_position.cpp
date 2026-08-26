#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    virtual void set_position(long a1, long a2, long a3, long a4, long a5, long a6, long a7, long a8, long a9, long a10, long a11, long a12, long a13);

    virtual void set_fixed_position(long left, long top, long right, long bottom);
};

#endif
void TPanel::set_fixed_position(long left, long top, long right, long bottom) {
    set_positioning(TPanel::PositionFixed, left, top, 0, 0, right, right, bottom, bottom, 0, 0, 0, 0);
}
