// matched source hypothesis: proportional wrapper to child panel fixed-position
// virtual slot.  The period call site uses the four-long slot at +0x1C.

void TEasy_Panel::position_panel(TPanel* panel, long x, long y, long w, long h) {
    panel->set_fixed_position(
        (x * this->base_width) / this->ideal_width,
        (y * this->base_height) / this->ideal_height,
        (w * this->base_width) / this->ideal_width,
        (h * this->base_height) / this->ideal_height);
}
