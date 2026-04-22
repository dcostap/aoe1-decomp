class TPanel {
public:
    char gap_00[0x40];
    TPanel* parent_panel;
    char gap_44[0x98];
    int z_order;

    void set_child_z_order(TPanel* child, unsigned char mode, short z_order);
    void set_z_order(unsigned char mode, short z_order);
};

void TPanel::set_z_order(unsigned char mode, short order) {
    if (this->parent_panel != 0) {
        this->parent_panel->set_child_z_order(this, mode, order);
        return;
    }

    switch ((int)mode) {
    case 0:
        this->z_order = order;
        break;
    case 1:
        this->z_order = 0;
        return;
    case 2:
        this->z_order = 0;
        return;
    }
}
