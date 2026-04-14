class TListDialog {
public:
    virtual ~TListDialog();
    char gap_0[0x4A4];
    int field_4A8;
    int get_list_name();
};

int TListDialog::get_list_name() { return this->field_4A8; }
