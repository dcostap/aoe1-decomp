class TDialogPanel {
public:
    void target_func(int p0);
    void set_focus(int p);
};

void TDialogPanel::set_focus(int p) { this->target_func(p); }
