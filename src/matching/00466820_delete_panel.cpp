class TPanel {
public:
    virtual void scalar_deleting_destructor(unsigned int flags);
    void delete_panel(TPanel** panel);
};

void TPanel::delete_panel(TPanel** panel) {
    if (*panel != 0) {
        (*panel)->scalar_deleting_destructor(1);
        *panel = 0;
    }
}
