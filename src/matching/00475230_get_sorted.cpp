class InnerType {
public:
    char gap_0[0x15C];
    int field_15C;
};

class TDropDownPanel {
public:
    char gap_0[0xFC];
    InnerType* member_FC;

    int get_sorted();
};

int TDropDownPanel::get_sorted() {
    if (this->member_FC) {
        return this->member_FC->field_15C;
    }
    return 0;
}
