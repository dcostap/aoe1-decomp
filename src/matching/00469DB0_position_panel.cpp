// matched source hypothesis: proportional wrapper to child panel set_rect virtual slot

void TEasy_Panel::position_panel(TPanel* panel, long x, long y, long w, long h) {
    panel->set_rect(
        (x * this->base_width) / this->ideal_width,
        (y * this->base_height) / this->ideal_height,
        (w * this->base_width) / this->ideal_width,
        (h * this->base_height) / this->ideal_height);
}
